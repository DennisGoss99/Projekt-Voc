//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmMain.h"
#include "Unit1.h"
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


void __fastcall TfrmMain::fbtLoginClick(TObject *Sender)
{
		Form1->Show();
}
//---------------------------------------------------------------------------

