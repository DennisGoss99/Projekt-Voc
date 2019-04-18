//---------------------------------------------------------------------------

#ifndef cDBServiceH
#define cDBServiceH
#include <vcl.h>
//---------------------------------------------------------------------------

static class cDBService
{
	 private:

	 public:

     static wchar_t * AnsiTowchar_t(AnsiString Str);
	 static AnsiString SqlGetOneParameter(String Table,String Attribute,String AttributeId,AnsiString Id);
	 static int SqlLoginCheck(String SQL,String AttributeUser , String AttributeEmail ,String AttributePassword ,String User,String Password);

}cDBService;
#endif


