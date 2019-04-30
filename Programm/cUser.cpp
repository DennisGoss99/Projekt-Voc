//---------------------------------------------------------------------------

#pragma hdrstop

#include "cUser.h"
#include "cDBService.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void User::GetSQLValues(AnsiString idUser)
{
	surname = cDBService.SqlGetOneParameter("User","Surname","idUser = " + idUser); 					// gets surname enforced by cDBService.SqlGetOneParameter
	name = cDBService.SqlGetOneParameter("User","Name","idUser = " + idUser); 							// gets name enforced by cDBService.SqlGetOneParameter
	email = cDBService.SqlGetOneParameter("User","Email","idUser = " + idUser); 						// gets email enforced by cDBService.SqlGetOneParameter
	password = cDBService.SqlGetOneParameter("User","Password","idUser = " + idUser); 					// gets password enforced by cDBService.SqlGetOneParameter
	creationDate = cDBService.SqlGetOneParameter("User","CreationDate","idUser = " + idUser);			// gets creationDate enforced by cDBService.SqlGetOneParameter
	username = cDBService.SqlGetOneParameter("User","Username","idUser = " + idUser); 					// gets username enforced by cDBService.SqlGetOneParameter
	totalWords = cDBService.SqlGetArrayInt("statistic","TotalWords","User_idUser",idUser); 				// gets totalWords enforced by cDBService.SqlGetArrayInt
	precessedWords = cDBService.SqlGetArrayInt("statistic","precessedWords","User_idUser",idUser); 		// gets precessedWords enforced by cDBService.SqlGetArrayInt
	failedWords	= cDBService.SqlGetArrayInt("statistic","FailedWords","User_idUser",idUser);		 	// gets failedWords enforced by cDBService.SqlGetArrayInt

}

void User::GetSQLValuesS(AnsiString surname)
{
	idUser = cDBService.SqlGetOneParameter("User","idUser","Surname = '" + surname+ "'").ToInt();		// gets idUser enforced by cDBService.SqlGetArrayInt
	name = cDBService.SqlGetOneParameter("User","Name","Surname = '" + surname+ "'");					// gets name enforced by cDBService.SqlGetArrayInt
	email = cDBService.SqlGetOneParameter("User","Email","Surname = '" + surname+ "'"); 				// gets email enforced by cDBService.SqlGetArrayInt
	password = cDBService.SqlGetOneParameter("User","Password","Surname = '" + surname+ "'"); 			// gets password enforced by cDBService.SqlGetArrayInt
	creationDate = cDBService.SqlGetOneParameter("User","CreationDate","Surname = '" + surname+ "'"); 	// gets creationDate enforced by cDBService.SqlGetArrayInt
	username = cDBService.SqlGetOneParameter("User","Username","Surname = '" + surname + "'"); 			// gets username enforced by cDBService.SqlGetArrayInt
}

User::User(){}

User::User(AnsiString username)
{
User(); // constructor, executes GetSQLValuesS
this->username = username;
GetSQLValuesS(this->username);
}

User::User(int idUser)
{
User(); // constructor, executes GetSQLValues 
this->idUser = idUser;
GetSQLValues(this->idUser);
}
