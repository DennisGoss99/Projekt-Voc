//---------------------------------------------------------------------------

#ifndef cDBServiceH
#define cDBServiceH
#include <vcl.h>
//---------------------------------------------------------------------------

static class cDBService{

	 private:

	 public:

	 static wchar_t * AnsiTowchar_t(AnsiString Str);
	 static bool SqlLoginCheck(String SQL,String AttributeUser ,String AttributePassword ,String User,String Password);
}cDBService;
#endif


