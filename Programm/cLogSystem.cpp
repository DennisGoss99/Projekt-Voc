//---------------------------------------------------------------------------

#pragma hdrstop

#include "cLogSystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

const char *Log::OutputPath= "..\\..\\..\\Resources\\Log\\Log.txt";
bool Log::enableLog = 0;

void Log::Clear(void)
{
	clrscr();
	time_t now = time(0);
	tm *ltm = localtime(&now);

	fstream f;
	f.open(OutputPath , ios::out);
	f << ltm->tm_hour <<":";
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year<<" | ";

	f << "cleared" <<endl;
	f.close();

	getch();
}

void Log::Add(AnsiString LogContent)
{
	if (!enableLog) return;

	clrscr();
	time_t now = time(0);
	tm *ltm = localtime(&now);

	fstream f;
	f.open(OutputPath , ios::app);
	f << ltm->tm_hour <<":";
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year<<" | ";
	f << LogContent <<endl;
	f.close();

	getch();
}

void Log::Add(AnsiString LogContent,int Priority)
{
	if (!enableLog) return;

   	clrscr();
	time_t now = time(0);
	tm *ltm = localtime(&now);

	fstream f;
	f.open(OutputPath , ios::app);
	f << ltm->tm_hour <<":";
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year;
	f << " [~" << Priority << "~] ";
	f << LogContent <<endl;
	f.close();

	getch();
}


void Log::OutputError(AnsiString Text ,AnsiString Caption , int Flag , bool DoLog){
	if (DoLog) Add("Messagebox: " + Text + " | Caption: " + Caption);
	Application->MessageBox(cDBService.AnsiTowchar_t(Text),cDBService.AnsiTowchar_t(Caption),Flag);
}
