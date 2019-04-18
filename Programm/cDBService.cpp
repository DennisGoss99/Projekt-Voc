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

AnsiString cDBService::SqlGetOneParameter(String Table,String Attribute,String AttributeId,AnsiString Id)
{
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from " + Table + " Where " + AttributeId + " = " + Id);
	frmMain->mainADOQuery->Open();

	frmMain->mainADOQuery->First();


	return frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString;
}

int cDBService::SqlLoginCheck(String SQL,String AttributeUser , String AttributeEmail ,String AttributePassword ,String User,String Password)
{
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add(SQL + " Where (" + AttributeUser + " like '" + User + "' || " + AttributeEmail + " like '" + User + "' )&& " + AttributePassword + " = '" + Password + "' LIMIT 1" );
	frmMain->mainADOQuery->Open();

	frmMain->mainADOQuery->First();


	return frmMain->mainADOQuery->FieldByName("idUser")->AsInteger;
}

/*
   	 frmMain->mainADOQuery->Close();
	 frmMain->mainADOQuery->SQL->Clear();
	 frmMain->mainADOQuery->SQL->Add(SQL + " Where " + AttributeUser + " like '" + User + "' && " + AttributePassword + " = '" + Password + "'");
	 frmMain->mainADOQuery->Open();

	 AnsiString X;

	 frmMain->mainADOQuery->First();


	 for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		 X = frmMain->mainADOQuery->FieldByName("Surname")->AsAnsiString;

		 Application->MessageBox(AnsiTowchar_t(X),L"Hallo",MB_OK);
		 frmMain->mainADOQuery->Next();
	 }
*/
