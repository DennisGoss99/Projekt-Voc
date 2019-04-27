//---------------------------------------------------------------------------

#ifndef cLogSystemH
#define cLogSystemH
#include <vcl.h>
#include "cDBService.h"
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
	static void OutputError(AnsiString Text ,AnsiString Caption , int Flag , bool DoLog = false);


	void set_enableLog(bool enableLog) { this->enableLog = enableLog;}
	bool get_enableLog(void) { return enableLog;}

}myLog;



#endif
