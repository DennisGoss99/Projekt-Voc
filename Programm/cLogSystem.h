//---------------------------------------------------------------------------

#ifndef cLogSystemH
#define cLogSystemH
#include <vcl.h>
#include <fstream>
#include<time.h>
#include<conio.h>
//---------------------------------------------------------------------------
using namespace std;

static class Log
{
private:

	static bool enableLog;
	const static char *OutputPath;


public:

	static void Clear(void);
	static void Add(AnsiString LogContent);
	static void Add(AnsiString LogContent,int Priority);

	void set_enableLog(bool enableLog) { this->enableLog = enableLog;}
	bool get_enableLog(void) { return enableLog;}

}myLog;



#endif
