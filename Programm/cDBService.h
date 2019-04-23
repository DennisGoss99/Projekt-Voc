//---------------------------------------------------------------------------

#ifndef cDBServiceH
#define cDBServiceH
#include <vcl.h>
#include <vector>
//---------------------------------------------------------------------------

static class cDBService
{
	 private:

	 public:

	 static wchar_t * AnsiTowchar_t(AnsiString Str);
	 static AnsiString SqlGetOneParameter(String Table,String Attribute,String Where,String Star= "*", String InnerJoin = "",String GroupBy = "");
	 static int SqlLoginCheck(String SQL,String AttributeUser , String AttributeEmail ,String AttributePassword ,String User,String Password);
	 static std::vector<AnsiString> SqlGetArray(String Table,String Attribute,String AttributeId,AnsiString Id);
	 static std::vector<int> SqlGetArrayInt(String Table,String Attribute,String AttributeId,AnsiString Id);
}cDBService;
#endif


