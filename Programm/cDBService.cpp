//---------------------------------------------------------------------------

#pragma hdrstop

#include "cDBService.h"
#include "uFrmMain.h"
#include "cLogSystem.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


wchar_t * cDBService::AnsiTowchar_t(AnsiString Str)
{
	wchar_t *str = new wchar_t[Str.WideCharBufSize()];
	return Str.WideChar(str, Str.WideCharBufSize());
	delete[] str;
}

AnsiString cDBService::SqlGetOneParameter(String Table,String Attribute,String Where,String Star,String InnerJoin,String GroupBy)
{
	myLog.Add("Select "+ Star +" from " + Table +" "+ InnerJoin + " Where " + Where + " " + GroupBy);

	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select "+ Star +" from " + Table +" "+ InnerJoin + " Where " + Where + " " + GroupBy );

	frmMain->mainADOQuery->Open();

	frmMain->mainADOQuery->First();


	return frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString;
}

int cDBService::SqlLoginCheck(String SQL,String AttributeUser , String AttributeEmail ,String AttributePassword ,String User,String Password)
{
    SqlExeq("DROP TABLE IF EXISTS tempPassword");
	SqlExeq("CREATE TEMPORARY TABLE tempPassword (Select Password('"+ Password +"') as 'Password')");

	myLog.Add(SQL + " Where (" + AttributeUser + " like '" + User + "' || " + AttributeEmail + " like '" + User + "' )&& " + AttributePassword + " = '" + SqlGetOneParameter("tempPassword","Password"," Password like '%'") + "' LIMIT 1" );   //SqlGetOneParameter("tempPassword","Password"," Password like '%'")

	AnsiString Test53 =  SqlGetOneParameter("tempPassword","Password"," Password like '%'");

	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add(SQL + " Where (" + AttributeUser + " like '" + User + "' || " + AttributeEmail + " like '" + User + "' )&& " + AttributePassword + " = '" + Test53 + "' LIMIT 1");
	frmMain->mainADOQuery->Open();

	frmMain->mainADOQuery->First();


	return frmMain->mainADOQuery->FieldByName("idUser")->AsInteger;
}

std::vector<AnsiString> cDBService::SqlGetArray(String Table,String Attribute,String AttributeId,AnsiString Id)
{
	myLog.Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Open();

	std::vector<AnsiString> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString);
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

std::vector<AnsiString> cDBService::SqlGetArray(String Table,String Attribute,String Where)
{
	myLog.Add("Select * from "+ Table + " " + Where);
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " " + Where );
	frmMain->mainADOQuery->Open();

	std::vector<AnsiString> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString);
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

std::vector<int> cDBService::SqlGetArrayInt(String Table,String Attribute,String AttributeId,AnsiString Id)
{
	myLog.Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Open();

	std::vector<int> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsInteger);
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

int cDBService::SqlExeq(AnsiString SQL)
{
    myLog.Add(SQL);
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add(SQL);
	return frmMain->mainADOQuery->ExecSQL();
}
