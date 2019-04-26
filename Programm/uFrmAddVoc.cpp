//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmAddVoc.h"
#include "cDBService.h"
#include "uFrmMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmAddVoc *frmAddVoc;
//---------------------------------------------------------------------------
	std::vector<AnsiString> UnitList;
//---------------------------------------------------------------------------

__fastcall TfrmAddVoc::TfrmAddVoc(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------
AnsiString TfrmAddVoc::ListToWhereString(TListBox *listBox)
{
AnsiString returnString = "(";

	if (listBox->Items->Count <= 1) {
		returnString+="''";
	}

	for (int i = 0; i < listBox->Items->Count-1; i++) {

		if (i == listBox->Items->Count-2) {
			returnString+= "'"+listBox->Items->Strings[i]+ "'";
		}else{
			returnString+= "'"+listBox->Items->Strings[i] + "',";
		}
	}
	returnString+= ")";
	return returnString;
}

void TfrmAddVoc::ClearVoc(void)
{
	lbVocNT->Items->Clear();
	lbVocT->Items->Clear();
	lbGlos->Items->Clear();
	lbVocNT->ItemIndex = -1;
	lbVocT->ItemIndex = -1;
	lbGlos->ItemIndex = -1;
	edVocNT->Text = "";
	edVocT->Text = "";
	edGlos->Text = "";
}

void TfrmAddVoc::FillListbox(TListBox *listBox, std::vector<AnsiString> tempList)
{
	listBox->Items->Clear();

	for (int i = 0; i < tempList.size(); i++) {
		listBox->Items->Add(tempList[i]);
	}
}

void TfrmAddVoc::FillListbox(TComboBox *comboBox, std::vector<AnsiString> tempList)
{
	comboBox->Items->Clear();
	comboBox->Text = "";

	for (int i = 0; i < tempList.size(); i++) {
		comboBox->Items->Add(tempList[i]);
	}
}

//---------------------------------------------------------------------------
//Form Functions
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::FormResize(TObject *Sender)
{
	grbVocNT->Width =grbVocmain->Width/4;
	grbVocT->Width =grbVocmain->Width/4;
	grbGlos->Width = grbVocmain->Width/2;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::FormShow(TObject *Sender)
{
    imUnit->Picture->Bitmap = NULL;

	UnitList = cDBService.SqlGetArray("Unit","UnitName","User_idUser",frmMain->mainUser->get_idUser());

	FillListbox(cmbUnit, UnitList);
	cmbUnit->Items->Add("-- hinzufügen -- ");

	edUnitName->Text = cmbUnit->Text;



	FillListbox(cmbUnitLang ,cDBService.SqlGetArray("Language","Language","idLanguage","%"));

	ClearVoc();

	lbVocNT->Items->Add("-- hinzufügen --");
	lbVocT->Items->Add("-- hinzufügen --");
	lbGlos->Items->Add("-- hinzufügen --");

}
//---------------------------------------------------------------------------
//Unit Functions
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::cmbUnitChange(TObject *Sender)
{
	edUnitName->Text = cmbUnit->Text;

	cmbUnitLang->Text = cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + cmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage");
	cmbUnitLangChange(NULL);

    ClearVoc();

	FillListbox(lbVocNT,cDBService.SqlGetArray("Vocabulary", "Word" , "Where Unit_idUnit ='" + cDBService.SqlGetOneParameter("Unit", "idUnit"," UnitName = '"+ cmbUnit->Text +"' && User_idUser = '"+ frmMain->mainUser->get_idUser() +"'") + "'"));
	FillListbox(lbVocT,cDBService.SqlGetArray("Vocabulary", "WordTranslated" , "Where Unit_idUnit ='" + cDBService.SqlGetOneParameter("Unit", "idUnit"," UnitName = '"+ cmbUnit->Text +"' && User_idUser = '"+ frmMain->mainUser->get_idUser() +"'") + "'"));
	FillListbox(lbGlos,cDBService.SqlGetArray("Vocabulary", "Glossary" , "Where Unit_idUnit ='" + cDBService.SqlGetOneParameter("Unit", "idUnit"," UnitName = '"+ cmbUnit->Text +"' && User_idUser = '"+ frmMain->mainUser->get_idUser() +"'") + "'"));

	lbVocNT->Items->Add("-- hinzufügen --");
	lbVocT->Items->Add("-- hinzufügen --");
	lbGlos->Items->Add("-- hinzufügen --");



}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::cmbUnitLangChange(TObject *Sender)
{
	imUnit->Picture->Bitmap->Assign( frmMain->mainImageCollection->GetBitmap(cmbUnitLang->Text,80,48));
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::edUnitNameChange(TObject *Sender)
{
	cmbUnit->Text = edUnitName->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::btnUnitDelClick(TObject *Sender)
{

	if(Application->MessageBox(L"Wollen Sie diese Unit wirklich löschen?",L"Sind Sie sich sicher?",MB_OKCANCEL) == 2)return;

	cDBService.SqlExeq("Delete Vocabulary from Unit inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit Where User_idUser = '" + (AnsiString)frmMain->mainUser->get_idUser() + "' && Unitname = '"+ cmbUnit->Text +"'");

	cDBService.SqlExeq("Delete from Unit Where UnitName = '"+ cmbUnit->Text +"' && User_idUser = '" + frmMain->mainUser->get_idUser() + "'"  );

	cmbUnit->Items->Delete(cmbUnit->ItemIndex);

	edUnitName->Text = "";
	cmbUnit->Text = "";
	cmbUnitLang->Text = "";
	imUnit->Picture->Bitmap = NULL;

	edVocNT->Text = "";
	edVocT->Text = "";
	edGlos->Text = "";

	lbVocNT->Items->Clear();
	lbVocT->Items->Clear();
	lbGlos->Items->Clear();
}

//---------------------------------------------------------------------------
//Voc Functions
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::lbVocNTClick(TObject *Sender)
{
	try
	{
		if (lbVocNT->Items->Count-1==lbVocNT->ItemIndex){
			//resets edit and selects hinzufügen
			lbVocNT->ItemIndex = -1;
			lbVocT->ItemIndex = -1;
			lbGlos->ItemIndex = -1;
			edVocNT->Text = "";
			edVocT->Text = "";
			edGlos->Text = "";
			}else{

			lbVocT->ItemIndex = lbVocNT->ItemIndex;
			lbGlos->ItemIndex = lbVocNT->ItemIndex;

			edVocNT->Text = lbVocNT->Items->Strings[lbVocNT->ItemIndex];
			edVocT->Text = lbVocT->Items->Strings[lbVocT->ItemIndex];
			edGlos->Text = lbGlos->Items->Strings[lbGlos->ItemIndex];
		}

	} catch (...) {
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::lbVocTClick(TObject *Sender)
{
	try
	{
		if (lbVocT->Items->Count-1==lbVocT->ItemIndex){
			lbVocNT->ItemIndex = -1;
			lbVocT->ItemIndex = -1;
			lbGlos->ItemIndex = -1;
			edVocNT->Text = "";
			edVocT->Text = "";
			edGlos->Text = "";
		}else{

			lbVocNT->ItemIndex = lbVocT->ItemIndex;
			lbGlos->ItemIndex = lbVocT->ItemIndex;

			edVocNT->Text = lbVocNT->Items->Strings[lbVocNT->ItemIndex];
			edVocT->Text = lbVocT->Items->Strings[lbVocT->ItemIndex];
			edGlos->Text = lbGlos->Items->Strings[lbGlos->ItemIndex];
		}
	} catch (...) {
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::lbGlosClick(TObject *Sender)
{
	try
	{
		if (lbGlos->Items->Count-1==lbGlos->ItemIndex){
			lbVocNT->ItemIndex = -1;
			lbVocT->ItemIndex = -1;
			lbGlos->ItemIndex = -1;
			edVocNT->Text = "";
			edVocT->Text = "";
			edGlos->Text = "";
		}else{

			lbVocNT->ItemIndex = lbGlos->ItemIndex;
			lbVocT->ItemIndex = lbGlos->ItemIndex;

			edVocNT->Text = lbVocNT->Items->Strings[lbVocNT->ItemIndex];
			edVocT->Text = lbVocT->Items->Strings[lbVocT->ItemIndex];
			edGlos->Text = lbGlos->Items->Strings[lbGlos->ItemIndex];
		}
	} catch (...) {
	}
}

//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::btnVocDelClick(TObject *Sender)
{
	if (! (lbVocT->ItemIndex >= 0 && lbVocNT->ItemIndex >= 0 && lbGlos->ItemIndex >= 0))return;

	lbVocT->Items->Delete(lbVocT->ItemIndex);
	lbVocNT->Items->Delete(lbVocNT->ItemIndex);
	lbGlos->Items->Delete(lbGlos->ItemIndex);

	edVocNT->Text = "";
	edVocT->Text = "";
	edGlos->Text = "";

    //Todo: Delete

}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::btnVocAddClick(TObject *Sender)
{
	if ((lbVocT->ItemIndex >= 0 && lbVocNT->ItemIndex >= 0 && lbGlos->ItemIndex >= 0))return;
	if (edVocNT->Text == "" || edVocT->Text == "" ) return;
	if (edVocNT->Text==edVocT->Text || edVocNT->Text==edGlos->Text || edVocT->Text==edGlos->Text) {
		Application->MessageBox(L"Bitte geben Sie immer unterschiedliche Daten an!",L"Eingabe Falsch!",MB_OK);
		return;
	}

	std::vector<AnsiString> VocNTList;
	std::vector<AnsiString> VocTList;
	std::vector<AnsiString> GlosList;

	for (int i = 0; i < lbVocNT->Items->Count-1; i++) {
		VocNTList.push_back(lbVocNT->Items->Strings[i]);
		VocTList.push_back(lbVocT->Items->Strings[i]);
		GlosList.push_back(lbGlos->Items->Strings[i]);
	}

	lbVocNT->Items->Clear();
	lbVocT->Items->Clear();
	lbGlos->Items->Clear();
	lbVocNT->ItemIndex = -1;
	lbVocT->ItemIndex = -1;
	lbGlos->ItemIndex = -1;

	FillListbox(lbVocNT,VocNTList);
	FillListbox(lbVocT,VocTList);
	FillListbox(lbGlos,GlosList);

	lbVocNT->Items->Add(edVocNT->Text);
	lbVocT->Items->Add(edVocT->Text);
	lbGlos->Items->Add(edGlos->Text);

	lbVocNT->Items->Add("-- hinzufügen --");
	lbVocT->Items->Add("-- hinzufügen --");
	lbGlos->Items->Add("-- hinzufügen --");

	edVocNT->Text = "";
	edVocT->Text = "";
	edGlos->Text = "";
}

//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::edVocNTKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (!(lbVocT->ItemIndex >= 0 && lbVocNT->ItemIndex >= 0 && lbGlos->ItemIndex >= 0))return;

	lbVocNT->Items->Strings[lbVocNT->ItemIndex] = edVocNT->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::edVocTKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (!(lbVocT->ItemIndex >= 0 && lbVocNT->ItemIndex >= 0 && lbGlos->ItemIndex >= 0))return;

	lbVocT->Items->Strings[lbVocNT->ItemIndex] = edVocT->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::edGlosKeyUp(TObject *Sender, WORD &Key, TShiftState Shift)

{
	if (!(lbVocT->ItemIndex >= 0 && lbVocNT->ItemIndex >= 0 && lbGlos->ItemIndex >= 0))return;

	lbGlos->Items->Strings[lbVocNT->ItemIndex] = edGlos->Text;
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::btnCloseClick(TObject *Sender)
{
	this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmAddVoc::btnSaveClick(TObject *Sender)
{
	if (cmbUnit->Text == "-- hinzufügen -- ") {
		Application->MessageBox(L"Bitte ändern Sie den Unitnamen!",L"Falsche Eingabe",MB_OK);
		myLog.Add("Nicht erlaubter Unitname!",2);
		return;
	}

	bool unitExists = false;

	for (int i = 0; i < cmbUnit->Items->Count -1 ; i++) {


		if (cmbUnit->Items->Strings[cmbUnit->ItemIndex] == cmbUnit->Items->Strings[i]) {
			unitExists = true;
			continue;
		}
	}

	if (unitExists) {
		cDBService.SqlExeq("Update Unit Set UnitName = '" + edUnitName->Text + "', Language_IdLanguage = '" + cDBService.SqlGetOneParameter("Language", "IdLanguage", "language = '"+ cmbUnitLang->Text +"'") + "' Where UnitName = '"+ cmbUnit->Items->Strings[cmbUnit->ItemIndex] +"' && User_idUser = '" + frmMain->mainUser->get_idUser() + "'");
	}else{
		if (cmbUnitLang->ItemIndex == -1) {
		Application->MessageBox(L"Bitte Geben Sie eine Sprache an!",L"Falsche Eingabe",MB_OK);
		myLog.Add("Keine Sprache ausgewählt!",2);
		return;
		}

		cDBService.SqlExeq("INSERT INTO Unit (IdUnit, UnitName, User_IdUser,Language_IdLanguage) VALUES (default, '"+ edUnitName->Text +"','" + frmMain->mainUser->get_idUser() +"' , '"+ cDBService.SqlGetOneParameter("Language", "IdLanguage", "language = '"+ cmbUnitLang->Text +"'") +"' )");

    }


	cDBService.SqlExeq("Delete from Vocabulary Where Unit_idUnit = '"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ edUnitName->Text +"'") +"' &&( Word not in "+ ListToWhereString(lbVocNT) + "|| WordTranslated not in "+ ListToWhereString(lbVocT)+ "|| Glossary not in "+ ListToWhereString(lbGlos) + ")");

	for (int i = 0; i < lbVocNT->Items->Count -1; i++) {
			cDBService.SqlExeq("Insert into vocabulary (Word,WordTranslated,Glossary,Unit_idUnit) Select * from (Select '"+ lbVocNT->Items->Strings[i] +"','"+ lbVocT->Items->Strings[i] +"','"+ lbGlos->Items->Strings[i] +"','"+ cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ edUnitName->Text +"'") +"' ) AS tmp Where NOT EXISTS(Select Word from vocabulary Where word = '"+ lbVocNT->Items->Strings[i] +"') || NOT EXISTS(Select WordTranslated from vocabulary Where WordTranslated = '"+ lbVocT->Items->Strings[i] +"') || NOT EXISTS(Select Glossary from vocabulary Where Glossary = '"+ lbGlos->Items->Strings[i] +"')");
	}

	frmMain->UpdateUI();

	if(Application->MessageBox(L"Wollen Sie das Fenster nun schließen?",L"Erfolgreich gespeichert!",MB_OKCANCEL) == 1)this->Close();

}

//---------------------------------------------------------------------------


