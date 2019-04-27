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
	if (UnitWord.empty()) {
		myLog.OutputError("Unit ["+ SelectedUnit +"] abgearbeitet!", "Herzlichen Glückwunsch",MB_OK);
		this->Close();
		return;
	}

    srand (time(NULL));
	randomIndex = rand() % UnitWord.size();

	mVocNT->Text = UnitWord[randomIndex];
    mVocT->Text = "";
	mGlos->Text = UnitGlossary[randomIndex];


}

void TfrmCheckVoc::CheckVoc(void)
{
	if (mVocT->Text==UnitWordTranslated[randomIndex]) {
		mVocT->Font->Color = clLime;
		imCheck->Picture->Bitmap->Assign( ImageCollectionCheckbox->GetBitmap("Green Hook",40,40));

		cDBService.SqlExeq("Update Vocabulary Set IsFinished = 1 Where WordTranslated = '"+ UnitWordTranslated[randomIndex] +"' && Word = '"+ UnitWord[randomIndex] +"' && Glossary = '"+ UnitGlossary[randomIndex] +"' && Unit_idUnit ='"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"'" );
	}else{
		mVocT->Font->Color = clRed;
		mVocT->Text += "\r\n" + UnitWordTranslated[randomIndex];
		imCheck->Picture->Bitmap->Assign( ImageCollectionCheckbox->GetBitmap("Red Cross",40,40));

		cDBService.SqlExeq("Update Vocabulary Set IsFinished = 0 Were WordTranslated = '"+ UnitWordTranslated[randomIndex] +"' && Word = '"+ UnitWord[randomIndex] +"' && Glossary = '"+ UnitGlossary[randomIndex] +"' && Unit_idUnit ='"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"'" );
	}

	UnitWordTranslated.erase(UnitWordTranslated.begin()+randomIndex );
	UnitWord.erase(UnitWord.begin()+randomIndex);
	UnitGlossary.erase(UnitGlossary.begin()+randomIndex );

}


void TfrmCheckVoc::ToggleGlos(void)
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

void TfrmCheckVoc::SetGlos(bool showGloss){
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
	grbVocNT->Width =pnVocIntern->Width/2-5;
	grbVocT->Width =pnVocIntern->Width/2-5;
}
//---------------------------------------------------------------------------
void __fastcall TfrmCheckVoc::btnShowGlosClick(TObject *Sender)
{
	ToggleGlos();
}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::FormShow(TObject *Sender)
{
    SelectedUnit = frmMain->vcmbUnit->Items->Strings[frmMain->vcmbUnit->ItemIndex];

	UnitWord = cDBService.SqlGetArray("Vocabulary", "Word", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && IsFinished = '0' ");
	UnitWordTranslated = cDBService.SqlGetArray("Vocabulary", "WordTranslated", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && IsFinished = '0' ");
	UnitGlossary = cDBService.SqlGetArray("Vocabulary", "Glossary", "Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ SelectedUnit +"'") +"' && IsFinished = '0' ");

    NewVoc();

	UpdateUI();
	SetGlos(false);
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

	if (btnCheck->Caption == "Überprüfen") {
		CheckVoc();
		SetGlos(true);
		btnCheck->Caption = "Weiter";
	}else{
		btnCheck->Caption = "Überprüfen";
		SetGlos(false);
		NewVoc();
	}

	UpdateUI();

}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::FormClose(TObject *Sender, TCloseAction &Action)
{
	cDBService.SqlExeq("Update Unit Set LastEdit = now() Where UnitName = '"+ SelectedUnit +"' && User_idUser = '"+ frmMain->mainUser->get_idUser() +"'");
	frmMain->UpdateUI(frmMain->vcmbUnit->ItemIndex);
}
//---------------------------------------------------------------------------

