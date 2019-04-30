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
		// if no user is logged in, then do nothing. Otherwise he draws the statistics of the logged in user
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
	// set all labels etc. in the main window
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
    //writes a new data record to the statistics
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
		// checks the user login
	if(tempUser)
	{
		mPbStatistic->Refresh();
		delete mainUser;
		mainUser = new User(tempUser);
		UpdateAfterLogin();

		Application->MessageBox(L"Angemeldet",L"Anmeldung war erfolgreich",MB_OK);
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
	// set all labels etc. in the main window
	frmMain->uimUnit->Picture->Bitmap->Assign( mainImageCollection->GetBitmap(cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage"),80,48));
	frmMain->vgrbUnit->Caption = "Unit: " + frmMain->vcmbUnit->Text;
	frmMain->ulbVocLag->Caption ="Sprache: " + cDBService.SqlGetOneParameter("Unit" , "Language" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && User_idUser = '" + mainUser->get_idUser() + "'", "*" , "inner join Language on Language.idLanguage = Unit.Language_idLanguage");
	frmMain->ulbVocAn->Caption  ="Anzahl Vokabeln: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && User_idUser = '" + mainUser->get_idUser() + "'", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit");
	frmMain->ulbVocBea->Caption = "Vokabeln bearbeitet: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 1  && User_idUser = '" + mainUser->get_idUser() + "'", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocOp->Caption = "Vokabeln offen: " + cDBService.SqlGetOneParameter("Unit" , "count(IsFinished)" , "UnitName = '" + frmMain->vcmbUnit->Text + "' && Isfinished = 0  && User_idUser = '" + mainUser->get_idUser() + "'", "count(IsFinished)" , "inner join Vocabulary on Vocabulary.Unit_idUnit = Unit.idUnit","group by IsFinished");
	frmMain->ulbVocTim->Caption = "Letzte Bearbeitung: " + cDBService.SqlGetOneParameter("Unit","LastEdit","UnitName = '" + frmMain->vcmbUnit->Text+ "'");
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormClose(TObject *Sender, TCloseAction &Action) // If a user is still logged in when closing the program, he will be logged out automatically.
{
	
	if (mainUser != NULL)
		Ausloggen1Click(NULL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ibtAddVocClick(TObject *Sender) // checks if the user is logged in before he can open the form to insert/update/delete vocabulary
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
	// checks if a unit is selcted
	if (! (vcmbUnit->ItemIndex >= 0)){
	myLog.OutputError("Bitte wählen Sie eine Unit aus!", "Keine Eingabe" ,MB_OK);
	return;
	}
	
	// Check if there are still words to edit in the unit list, if not he resets the unit to query it again
	if(0 < cDBService.SqlGetOneParameter("vocabulary" , "count(idVocabulary)", "Unit_idUnit = '" +cDBService.SqlGetOneParameter("Unit","idUnit", "UnitName = '"+ vcmbUnit->Items->Strings[vcmbUnit->ItemIndex] +"'")+"' && Isfinished = 1", "count(idVocabulary)" ))
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
	// Starts the log
	myLog.set_enableLog(frmMain->Anschalten1->Checked);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Leeren1Click(TObject *Sender)
{
	// Clears the log
	myLog.Clear();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::ffnen1Click(TObject *Sender)
{
	ShellExecute(0, 0, L"..\\..\\..\\Resources\\Log\\Log.txt", 0, 0 , SW_SHOW );  // opens the Log.txt file with the standard software
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormConstrainedResize(TObject *Sender, int &MinWidth, int &MinHeight,
          int &MaxWidth, int &MaxHeight)
{	
	// If the program size is changed, the statistics size is also dynamically updated with
	PlotStatistics();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Statisticlschen1Click(TObject *Sender)
{
	//Deletes the statistics
	if (mainUser == NULL) return;
	cDBService.SqlExeq("Delete from Statistic Where User_idUser = '" + (AnsiString) mainUser->get_idUser() + "'");
	Application->MessageBox(L"Bitte starten Sie das Programm neu",L"Neustarten!",MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Ausloggen1Click(TObject *Sender)
{
	// Logs out the user and resets the labels etc.
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
	frmMain->flbLoginNot->Caption = "Nicht Eingeloggt!";
	frmMain->fPnMainLeft->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::VokabeltrainerHilfe1Click(TObject *Sender)
{	
	// Opens the vocabulary trainer project on github
	ShellExecute(0, 0, L"https://github.com/DennisGoss99/Projekt-Voc", 0, 0 , SW_SHOW );
}
//---------------------------------------------------------------------------



void __fastcall TfrmMain::Statisticzeichnen1Click(TObject *Sender)
{
	PlotStatistics();
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::Optionen1Click(TObject *Sender)
{
		// Uses the registry
	AnsiString DateiName;
	Registry = new TRegistry;
	try {
		Registry->RootKey = HKEY_LOCAL_MACHINE;
		Registry->OpenKey("SOFTWARE\\SSC\\Registry\\user", true);
		DateiName = Registry->ReadString(mainUser->get_idUser());
		Registry->CloseKey();
		RegistryData = DateiName;
	} catch (...) {
	Application->MessageBox(L"Reg.Schlüssel fehlt bzw.Datei existiert nicht",L"Fehler",MB_OK);
	}
}
//---------------------------------------------------------------------------

