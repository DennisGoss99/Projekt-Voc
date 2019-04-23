//---------------------------------------------------------------------------

#pragma hdrstop

#include "cUser.h"
#include "cDBService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void User::GetSQLValues(AnsiString idUser)
{
	surname = cDBService.SqlGetOneParameter("User","Surname","idUser = " + idUser);
	name = cDBService.SqlGetOneParameter("User","Name","idUser = " + idUser);
	email = cDBService.SqlGetOneParameter("User","Email","idUser = " + idUser);
	password = cDBService.SqlGetOneParameter("User","Password","idUser = " + idUser);
	creationDate = cDBService.SqlGetOneParameter("User","CreationDate","idUser = " + idUser);
	username = cDBService.SqlGetOneParameter("User","Username","idUser = " + idUser);
	totalWords = cDBService.SqlGetArrayInt("statistic","TotalWords","User_idUser",idUser);
	precessedWords = cDBService.SqlGetArrayInt("statistic","precessedWords","User_idUser",idUser);
	failedWords	= cDBService.SqlGetArrayInt("statistic","FailedWords","User_idUser",idUser);

}

void User::GetSQLValuesS(AnsiString surname)
{
	idUser = cDBService.SqlGetOneParameter("User","idUser","Surname = '" + surname+ "'").ToInt();
	name = cDBService.SqlGetOneParameter("User","Name","Surname = '" + surname+ "'");
	email = cDBService.SqlGetOneParameter("User","Email","Surname = '" + surname+ "'");
	password = cDBService.SqlGetOneParameter("User","Password","Surname = '" + surname+ "'");
	creationDate = cDBService.SqlGetOneParameter("User","CreationDate","Surname = '" + surname+ "'");
	username = cDBService.SqlGetOneParameter("User","Username","Surname = '" + surname + "'");
}

User::User(){}

User::User(AnsiString username)
{
User();
this->username = username;
GetSQLValues(this->username);
}

User::User(int idUser)
{
User();
this->idUser = idUser;
GetSQLValues(this->idUser);
}
