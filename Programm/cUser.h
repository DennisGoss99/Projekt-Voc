//---------------------------------------------------------------------------

#ifndef cUserH
#define cUserH
#include <vcl.h>
#include <vector>
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
		std::vector<int> totalWords;
		std::vector<int> precessedWords;
		std::vector<int> failedWords;

		void GetSQLValues(AnsiString idUser);
		void GetSQLValuesS(AnsiString surname);

	 public:


	 User();
	 User(AnsiString username);
	 User(int idUser);

	 int get_idUser() { return idUser;}
	 AnsiString get_username() { return username;}
	 std::vector<int> get_totalWords() { return totalWords;}
	 std::vector<int> get_precessedWords() { return precessedWords;}
	 std::vector<int> get_failedWords() { return failedWords;}

	 //AnsiString get_ALL() {return idUser +"|"+ surname +"|"+ name +"|"+ email +"|"+ password +"|"+ creationDate +"|"+ username;}

};
#endif
