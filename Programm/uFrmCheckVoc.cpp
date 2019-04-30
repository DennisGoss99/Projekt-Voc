//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmCheckVoc.h"
#include "cDBService.h"
#include "uFrmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCheckVoc *frmCheckVoc;
//---------------------------------------------------------------------------

void TfrmCheckVoc::NewVoc(void)
{		
							// if the parameter is empty, a message box is displayed und beendet das Form
	if (UnitWord.empty()) {
		myLog.OutputError("Unit ["+ SelectedUnit +"] abgearbeitet!", "Herzlichen Glückwunsch",MB_OK);
		this->Close();
		return;
	}
		
			// generate random numbers
    srand (time(NULL));
	randomIndex = rand() % UnitWord.size();
		
			// outputs the vocabulary wich has to be checked
	mVocNT->Text = UnitWord[randomIndex];
    mVocT->Text = "";
	mGlos->Text = UnitGlossary[randomIndex];
	mVocT->Font->Color = clBlack;
}

void TfrmCheckVoc::CheckVoc(void)
{	
			// Checks the entered vocabulary and if it is correct the font color is changed to green and a corresponding image is displayed
	if (mVocT->Text==UnitWordTranslated[randomIndex]) {
		mVocT->Font->Color = clLime;
		imCheck->Picture->Bitmap->Assign( ImageCollectionCheckbox->GetBitmap("Green Hook",40,40));
			// sets the vocabulary for IsFinished to 1
		cDBService.SqlExeq("Update Vocabulary Set IsFinished = 1 Where WordTranslated = '"+ UnitWordTranslated[randomIndex] +"' && Word = '"+ UnitWord[randomIndex] +"' && Glossary = '"+ UnitGlossary[randomIndex] +"' && Unit_idUnit ='"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"'" );
	}else{
			// If the entered vocabulary is wrong, the font color is changed to red and a corresponding image is displayed
		mVocT->Font->Color = clRed;
		mVocT->Text += "\r\n" + UnitWordTranslated[randomIndex];
		imCheck->Picture->Bitmap->Assign( ImageCollectionCheckbox->GetBitmap("Red Cross",40,40));
			// sets the vocabulary for IsFinished to 0
		cDBService.SqlExeq("Update Vocabulary Set IsFinished = 0 Where WordTranslated = '"+ UnitWordTranslated[randomIndex] +"' && Word = '"+ UnitWord[randomIndex] +"' && Glossary = '"+ UnitGlossary[randomIndex] +"' && Unit_idUnit ='"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"'" );
	}

			// Deletes the entered vocabulary
	UnitWordTranslated.erase(UnitWordTranslated.begin()+randomIndex );
	UnitWord.erase(UnitWord.begin()+randomIndex);
	UnitGlossary.erase(UnitGlossary.begin()+randomIndex );

}


void TfrmCheckVoc::ToggleGlos(void) // the current state is mirrored
{	
	if (showGloss) {
		pnGlos->Width = 0;
		btnShowGlos->Caption = "<";
		showGloss = false;
	}else{
		pnGlos->Width = 235;
		btnShowGlos->Caption = ">";
		showGloss = true;
	}
}

void TfrmCheckVoc::SetGlos(bool showGloss){ // Displays or closes the glossary.
	if (showGloss) {
		pnGlos->Width = 235;
		btnShowGlos->Caption = ">";
		this->showGloss = true;
	}else{
		pnGlos->Width = 0;
		btnShowGlos->Caption = "<";
		this->showGloss = false;
	}
}

void TfrmCheckVoc::UpdateUI(void)
{	
	// Updates the display (label) of the vocabulary wich still needs to be edited.
	lbUnit->Caption = "Unit: " + SelectedUnit;
	lbUnitDescription->Caption = "Noch zu bearbeitung offen: [ "+ (AnsiString)UnitWord.size() + " ]";
}

__fastcall TfrmCheckVoc::TfrmCheckVoc(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmCheckVoc::pnVocResize(TObject *Sender)
{
	grbVocNT->Width =pnVocIntern->Width/2-5; // changes the size of the groupboxes 
	grbVocT->Width =pnVocIntern->Width/2-5;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCheckVoc::btnShowGlosClick(TObject *Sender)
{
	// executes the function, if you click on the button of the glossary
	ToggleGlos();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::FormShow(TObject *Sender)
{
    SelectedUnit = frmMain->vcmbUnit->Items->Strings[frmMain->vcmbUnit->ItemIndex];
	
	// gets the records for the vocabulary to be queried 
	UnitWord = cDBService.SqlGetArray("Vocabulary", "Word", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && (IsFinished = '0' || Isfinished = -1)");
	UnitWordTranslated = cDBService.SqlGetArray("Vocabulary", "WordTranslated", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && (IsFinished = '0' || Isfinished = -1)");
	UnitGlossary = cDBService.SqlGetArray("Vocabulary", "Glossary", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && (IsFinished = '0' || Isfinished = -1)");

    NewVoc();

	UpdateUI();
	SetGlos(false);   // Closes the glossary
}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::btnCancelClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::btnCheckClick(TObject *Sender)
{
	imCheck->Picture->Bitmap->Assign(NULL);
	// When the "Kontrollieren" button is displayed, change it to "Weiter"
	if (btnCheck->Caption == "Kontrollieren") { 
		CheckVoc();
		SetGlos(true);
		btnCheck->Caption = "Weiter";
	}else{
		// changes button to "Kontrollieren" and displays a new vocabulary
		btnCheck->Caption = "Kontrollieren"; 
		SetGlos(false);
		NewVoc();
	}

	UpdateUI();

}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::FormClose(TObject *Sender, TCloseAction &Action)
{
		// updates the date in the database of the used unit
	cDBService.SqlExeq("Update Unit Set LastEdit = now() Where UnitName = '"+ SelectedUnit +"' && User_idUser = '"+ frmMain->mainUser->get_idUser() +"'");
	frmMain->UpdateUI(frmMain->vcmbUnit->ItemIndex);
}
//---------------------------------------------------------------------------

