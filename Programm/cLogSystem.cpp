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
	tm *ltm = localtime(&now);	//gives you the current time

	fstream f;		
	f.open(OutputPath , ios::out);	//opens file "OutputPath" and overwrites everything
	f << ltm->tm_hour <<":";	
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";		//hours/minutes/seconds are written
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year<<" | ";

	f << "cleared" <<endl;		//adds "cleared" to the file
	f.close();			//Closes the file

	getch();
}

void Log::Add(AnsiString LogContent)
{
	if (!enableLog) return;		

	clrscr();
	time_t now = time(0);
	tm *ltm = localtime(&now);	//gives you the current time

	fstream f;
	f.open(OutputPath , ios::app);	//opens file OutputPath and adds it to the end
	f << ltm->tm_hour <<":";
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";		//hours/minutes/seconds are written
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year<<" | ";
	f << LogContent <<endl;		//adds "LogContent" to the file
	f.close();			//Closes the file

	getch();
}

void Log::Add(AnsiString LogContent,int Priority)
{
	if (!enableLog) return;

   	clrscr();
	time_t now = time(0);
	tm *ltm = localtime(&now);	//gives you the current time

	fstream f;
	f.open(OutputPath , ios::app);	//opens file OutputPath and adds it to the end
	f << ltm->tm_hour <<":";
	f << ltm->tm_min <<":";
	f << ltm->tm_sec <<" ";		//hours/minutes/seconds are written
	f<<ltm->tm_mday<<"/"<<1+ltm->tm_mon<<"/";
	f<<1900+ltm->tm_year;
	f << " [~" << Priority << "~] ";
	f << LogContent <<endl;		//adds "LogContent" to the file
	f.close();			//Closes the file

	getch();
}


void Log::OutputError(AnsiString Text ,AnsiString Caption , int Flag , bool DoLog){
	if (DoLog) Add("Messagebox: " + Text + " | Caption: " + Caption);				//Wenn Log an ist wird der Msg-Kontent in den Log geschrieben
	Application->MessageBox(cDBService.AnsiTowchar_t(Text),cDBService.AnsiTowchar_t(Caption),Flag);
}
