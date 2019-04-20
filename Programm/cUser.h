//---------------------------------------------------------------------------

#ifndef cUserH
#define cUserH
#include <vcl.h>
//---------------------------------------------------------------------------
class User{

	 private:

		int idUser;
		AnsiString surname;
		AnsiString name;
		AnsiString email;
		AnsiString password;
		AnsiString creationDate;
		AnsiString username;

		void GetSQLValues(AnsiString idUser);
		void GetSQLValuesS(AnsiString surname);

	 public:


	 User();
	 User(AnsiString username);
	 User(int idUser);

	 int get_idUser() { return idUser;}
	 AnsiString get_username() { return username;}

	 //AnsiString get_ALL() {return idUser +"|"+ surname +"|"+ name +"|"+ email +"|"+ password +"|"+ creationDate +"|"+ username;}

};
#endif
