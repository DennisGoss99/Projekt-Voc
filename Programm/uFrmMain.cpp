//---------------------------------------------------------------------------

#include <vcl.h>
#include <vector>
#pragma hdrstop

#include "uFrmMain.h"
#include <fstream>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TfrmMain::PlotStatistics(void)
{
	if (mainUser == NULL || (! plotStatistic)) return;
	try {
		mainPaintBox->drawStatistic(mainUser->get_totalWords(),mainUser->get_precessedWords(),mainUser->get_failedWords());
	} catch (...) {
	}

}

void TfrmMain::UpdateUI(int SelectUnit)
{
	if (mainUser == NULL) return;

	//Set Combobox Items
	frmMain->vcmbUnit->Items->Clear();
	frmMain->vcmbUnit->Text = "";

	std::vector<AnsiString> tempList = cDBService.SqlGetArray("Unit","UnitName","User_idUser",mainUser->get_idUser());

	for (int i = 0; i < tempList.size(); i++) {
		frmMain->vcmbUnit->Items->Add(tempList[i]);
	}

	frmMain->vcmbUnit->ItemIndex = SelectUnit;

	// Shows overall Vocabulary Statistics
	frmMain->mlbStatisticF->Caption = "Fehlend: " + cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "' && Isfinished = 0","count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
	frmMain->mlbStatisticR->Caption = "Richtig: " + cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "' && Isfinished = 1","count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
	frmMain->mlbStatisticG->Caption = "Anzahl: " + cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "'", "count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit", "group by User_idUser");

	frmMain->uimUnit->Picture->Bitmap->Assign( mainImageCollection->GetBitmap(cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage"),80,48));
	frmMain->vgrbUnit->Caption = "Unit: " + frmMain->vcmbUnit->Text;
	frmMain->ulbVocLag->Caption ="Sprache: " + cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage");
	frmMain->ulbVocAn->Caption  ="Anzahl Vokabeln: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
	frmMain->ulbVocBea->Caption = "Vokabeln bearbeitet: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 1", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocOp->Caption = "Vokabeln offen: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 0", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocTim->Caption = "Letzte Bearbeitung: " + cDBService.SqlGetOneParameter("Unit","LastEdit","UnitName = '" + frmMain->vcmbUnit->Text+ "'");

	PlotStatistics();

}

void TfrmMain::UpdateAfterLogin(void)
{
    //Set wellcome message
	frmMain->flbLoginNot->Caption = "Willkommen " + mainUser->get_username();
	frmMain->fPnMainLeft->Enabled = true;

	plotStatistic = true;

	UpdateUI();
}

void TfrmMain::UpdateStatistic(void)
{
	if (mainUser == NULL) return;

	try {
		AnsiString FailedWords = cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "' && Isfinished = 0","count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
		AnsiString PrecessedWords = cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "' && Isfinished = 1","count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
		AnsiString TotalWords = cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "'", "count(User_idUser)", "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit", "group by User_idUser");
		AnsiString TotalUnits = cDBService.SqlGetOneParameter("Unit" , "count(User_idUser)" , "User_idUser = '" + (AnsiString)mainUser->get_idUser() + "'", "count(User_idUser)");

		cDBService.SqlExeq("Insert Into Statistic (LastVisite , TotalWords , TotalUnits , precessedWords , FailedWords , User_idUser) values (now(),'"+ TotalWords +"','"+ TotalUnits +"','"+ PrecessedWords +"','"+ FailedWords +"','"+ mainUser->get_idUser() +"')");
	} catch (...) {
	}
}

//---------------------------------------------------------------------------
//Unit Functions
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormShow(TObject *Sender)
{
	frmMain->Anschalten1->Checked = myLog.get_enableLog();
	myLog.Add("---- Programm gestartet ----");

	mainPaintBox = new PaintBox(frmMain->mPbStatistic);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::fbtLoginClick(TObject *Sender)
{

	int tempUser = cDBService.SqlLoginCheck("Select * from User" , "Username" , "Email" , "Password" , fedLoginName->Text , fedLoginPw->Text);

	if(tempUser)
	{
		mPbStatistic->Refresh();
		delete mainUser;
		mainUser = new User(tempUser);
		UpdateAfterLogin();

		//Application->MessageBox(L"Angemeldet",L"Anmeldung war erfolgreich",MB_OK);
		myLog.Add("Anmeldung User:" + fedLoginName->Text,1);

	}else
	{
		Application->MessageBox(L"Benutzername oder Password Wing Wong",L"Anmeldung war nicht erfolgreich",MB_OK);
		myLog.Add("Felgeschlagende Anmeldung User:" + fedLoginName->Text,1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::vcmbUnitChange(TObject *Sender)
{
	if (mainUser == NULL) return;
	frmMain->uimUnit->Picture->Bitmap->Assign( mainImageCollection->GetBitmap(cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage"),80,48));
	frmMain->vgrbUnit->Caption = "Unit: " + frmMain->vcmbUnit->Text;
	frmMain->ulbVocLag->Caption ="Sprache: " + cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage");
	frmMain->ulbVocAn->Caption  ="Anzahl Vokabeln: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
	frmMain->ulbVocBea->Caption = "Vokabeln bearbeitet: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 1", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocOp->Caption = "Vokabeln offen: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 0", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocTim->Caption = "Letzte Bearbeitung: " + cDBService.SqlGetOneParameter("Unit","LastEdit","UnitName = '" + frmMain->vcmbUnit->Text+ "'");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action)
{
	if (mainUser != NULL)
		Ausloggen1Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ibtAddVocClick(TObject *Sender)
{
	if (mainUser == NULL) {
		myLog.OutputError("Bitte loggen Sie sich ein.", "Nicht eingeloggt!" ,MB_OK);
		return;
	}

	frmAddVoc->Show();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::mbtnStartVocClick(TObject *Sender)
{
	if (! (vcmbUnit->ItemIndex >= 0)){
	myLog.OutputError("Bitte wählen Sie eine Unit aus!", "Keine Eingabe" ,MB_OK);
	return;
	}

	if(0 == cDBService.SqlGetOneParameter("vocabulary" , "count(idVocabulary)", "Unit_idUnit = '" +cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ vcmbUnit->Items->Strings[vcmbUnit->ItemIndex] +"'")+"' && Isfinished = 0 || Isfinished = -1", "count(idVocabulary)" ))
		cDBService.SqlExeq("Update Vocabulary Set Isfinished = 0 Where Unit_idUnit = '" +cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ vcmbUnit->Items->Strings[vcmbUnit->ItemIndex] +"'")+"'");


	frmCheckVoc->Show();
	frmMain->UpdateUI(vcmbUnit->ItemIndex);
}
//---------------------------------------------------------------------------

// Menu Functions
//---------------------------------------------------------------------------

 void __fastcall TfrmMain::Beenden1Click(TObject *Sender)
{
	frmMain->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Anschalten1Click(TObject *Sender)
{
	myLog.set_enableLog(frmMain->Anschalten1->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Leeren1Click(TObject *Sender)
{
	myLog.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ffnen1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"..\\..\\..\\Resources\\Log\\Log.txt", 0, 0 , SW_SHOW );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight)
{
	PlotStatistics();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Statisticlschen1Click(TObject *Sender)
{
	if (mainUser == NULL) return;
	cDBService.SqlExeq("Delete from Statistic Where User_idUser = '" + (AnsiString) mainUser->get_idUser() + "'");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Ausloggen1Click(TObject *Sender)
{
	plotStatistic = false;

	if (mainUser == NULL) return;

	UpdateStatistic();
	delete mainUser;
	delete mainPaintBox;
    mainUser = NULL;

	fedLoginName->Text = "";
    fedLoginPw->Text = "";

	mPbStatistic->Refresh();

	frmMain->vcmbUnit->Text = "";
	frmMain->vcmbUnit->Items->Clear();
	frmMain->uimUnit->Picture->Bitmap->Assign(NULL);
	frmMain->vgrbUnit->Caption ="Unit: ";
	frmMain->ulbVocLag->Caption ="Sprache: ";
	frmMain->ulbVocAn->Caption  ="Anzahl Vokabeln: ";
	frmMain->ulbVocBea->Caption ="Vokabeln bearbeitet: ";
	frmMain->ulbVocOp->Caption ="Vokabeln offen: ";
	frmMain->ulbVocTim->Caption ="Letzte Bearbeitung: ";
	frmMain->mlbStatisticG->Caption = "Anzahl: ";
	frmMain->mlbStatisticR->Caption = "Richtig: ";
	frmMain->mlbStatisticF->Caption = "Fehlend: ";
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::VokabeltrainerHilfe1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"https://github.com/DennisGoss99/Projekt-Voc", 0, 0 , SW_SHOW );
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Optionen1Click(TObject *Sender)
{
    //Todo: Options
}
//---------------------------------------------------------------------------

