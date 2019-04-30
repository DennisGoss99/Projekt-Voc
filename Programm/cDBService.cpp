//---------------------------------------------------------------------------

#pragma hdrstop

#include "cDBService.h"
#include "uFrmMain.h"
#include "cLogSystem.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)


wchar_t * cDBService::AnsiTowchar_t(AnsiString Str)
{
		// AnsiString becomes wchar
	wchar_t *str = new wchar_t[Str.WideCharBufSize()];
	return Str.WideChar(str, Str.WideCharBufSize());
	delete[] str;
}

AnsiString cDBService::SqlGetOneParameter(String Table,String Attribute,String Where,String Star,String InnerJoin,String GroupBy)
{
	myLog.Add("Select "+ Star +" from " + Table +" "+ InnerJoin + " Where " + Where + " " + GroupBy);  // outputs command in log
	 
	 // gets a parameter
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
	SqlExeq("CREATE TEMPORARY TABLE tempPassword (Select Password('"+ Password +"') as 'Password')");	// creates a temporary table to get the password and deletes an already existing table 
	
	// outputs command in log
	myLog.Add(SQL + " Where (" + AttributeUser + " like '" + User + "' || " + AttributeEmail + " like '" + User + "' )&& " + AttributePassword + " = '" + SqlGetOneParameter("tempPassword","Password"," Password like '%'") + "' LIMIT 1" );   //SqlGetOneParameter("tempPassword","Password"," Password like '%'")

	AnsiString tmpPassword =  SqlGetOneParameter("tempPassword","Password"," Password like '%'");

	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add(SQL + " Where (" + AttributeUser + " like '" + User + "' || " + AttributeEmail + " like '" + User + "' )&& " + AttributePassword + " = '" + tmpPassword + "' LIMIT 1");  // checks the entered user
	frmMain->mainADOQuery->Open();

	frmMain->mainADOQuery->First();


	return frmMain->mainADOQuery->FieldByName("idUser")->AsInteger; // returns the user id
}

std::vector<AnsiString> cDBService::SqlGetArray(String Table,String Attribute,String AttributeId,AnsiString Id)  // is used to get single (string) list
{
	myLog.Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Open();

	std::vector<AnsiString> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString);  // inserts the data records at the end of the list
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

std::vector<AnsiString> cDBService::SqlGetArray(String Table,String Attribute,String Where) // is used to get single (string) list with extra conditions  
{
	myLog.Add("Select * from "+ Table + " " + Where);
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " " + Where );
	frmMain->mainADOQuery->Open();

	std::vector<AnsiString> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsAnsiString);  // inserts the data records at the end of the list
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

std::vector<int> cDBService::SqlGetArrayInt(String Table,String Attribute,String AttributeId,AnsiString Id) // is used to get single (Integer) list
{
	myLog.Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add("Select * from "+ Table + " Where " + AttributeId + " like '" + Id + "'");
	frmMain->mainADOQuery->Open();

	std::vector<int> returnList;

	frmMain->mainADOQuery->First();


	for (int i = 0; i < frmMain->mainADOQuery->RecordCount; i++) {
		returnList.push_back( frmMain->mainADOQuery->FieldByName(Attribute)->AsInteger);	// inserts the data records at the end of the list
		frmMain->mainADOQuery->Next();
	}

	return returnList;
}

int cDBService::SqlExeq(AnsiString SQL) // executes a sql command like update, insert und delete
{
    myLog.Add(SQL);
	frmMain->mainADOQuery->Close();
	frmMain->mainADOQuery->SQL->Clear();
	frmMain->mainADOQuery->SQL->Add(SQL);
	return frmMain->mainADOQuery->ExecSQL();
}
