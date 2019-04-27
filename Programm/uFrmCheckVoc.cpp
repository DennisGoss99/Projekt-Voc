//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uFrmCheckVoc.h"
#include "cDBService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmCheckVoc *frmCheckVoc;
//---------------------------------------------------------------------------

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
	SetGlos(false);
}
//---------------------------------------------------------------------------

void __fastcall TfrmCheckVoc::btnCancelClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

