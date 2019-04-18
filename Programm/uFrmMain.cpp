//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmMain.h"
#include "cDBService.h"
#include "cUser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmMain *frmMain;

User *mainUser;

//---------------------------------------------------------------------------
__fastcall TfrmMain::TfrmMain(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void UpdateAfterLogin(void)
{
	frmMain->flbLoginNot->Caption = "Willkommen " + mainUser->get_username();
	frmMain->fPnMainLeft->Enabled = true;
}

void __fastcall TfrmMain::fbtLoginClick(TObject *Sender)
{

int tempUser = cDBService.SqlLoginCheck("Select * from User" , "Username" , "Email" , "Password" , fedLoginName->Text , fedLoginPw->Text);

if(tempUser)
{
	mainUser = new User(tempUser);
	UpdateAfterLogin();

	Application->MessageBox(L"Angemeldet",L"Anmeldung war erfolgreich",MB_OK);


}else
{
	Application->MessageBox(L"Benutzername oder Password Wing Wong",L"Anmeldung war nicht erfolgreich",MB_OK);
}


}
//---------------------------------------------------------------------------


void __fastcall TfrmMain::sgaSbChange(TObject *Sender)
{
	frmMain->mPnStatistic->Left =- frmMain->sgaSb->Position;
}
//---------------------------------------------------------------------------

void __fastcall TfrmMain::FormResize(TObject *Sender)
{
	frmMain->sgaSb->Update();
}
//---------------------------------------------------------------------------

