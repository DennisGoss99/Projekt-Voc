//---------------------------------------------------------------------------

#pragma hdrstop

#include "cDBService.h"
#include "uFrmMain.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


wchar_t * cDBService::AnsiTowchar_t(AnsiString Str)
{
  wchar_t *str = new wchar_t[Str.WideCharBufSize()];
  return Str.WideChar(str, Str.WideCharBufSize());
  delete str;
}


bool cDBService::SqlLoginCheck(String SQL,String AttributeUser ,String AttributePassword ,String User,String Password)
{


	 frmMain->mainADOQuery->Close();
	 frmMain->mainADOQuery->SQL->Clear();
	 frmMain->mainADOQuery->SQL->Add(SQL + " Where " + AttributeUser + " like " + User + " && " + AttributePassword + " = " + Password);
	 frmMain->mainADOQuery->Open();

	 AnsiString X;

	 frmMain->mainADOQuery->First();
	 for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		 X = frmMain->mainADOQuery->FieldByName("Surname")->AsAnsiString;

		 Application->MessageBox(AnsiTowchar_t(X),L"Hallo",MB_OK);
		 frmMain->mainADOQuery->Next();
	 }

	return 1;
}


