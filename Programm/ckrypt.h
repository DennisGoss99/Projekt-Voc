//---------------------------------------------------------------------------

#ifndef ckryptH
#define ckryptH
#include <vcl.h>
//---------------------------------------------------------------------------

static class krypt{

	private:

	static String Primzahlen;


	public:

	static int ROT13;                                                              //ROT13 Verschiebung
	static String PW;                                                              //PW Passwort für Verschlüsselung
	static int PrStart;                                                             //Primzahlen Startwert
	static int PrEnd;                                                               //Primzahlen Endwert


	static String gStrPr(int,int);
	static bool gPr(int);
	static String vXOR(String);
	static String ePw(String, String);
	static String vPw(String,String);
	static String vROT13(String,int);
	static String eROT13(String,int);
	static String vREV(String);
//------------------------------------------------------------------------------------




}ckrypt;

#endif
