//---------------------------------------------------------------------------

#pragma hdrstop

#include "ckrypt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	int krypt::ROT13 = 13;                                                              //ROT13 Verschiebung
	String krypt::PW = "Passwort";                                                              //PW Passwort f�r Verschl�sselung
	int krypt::PrStart = 15;                                                             //Primzahlen Startwert
	int krypt::PrEnd = 26;
	String krypt::Primzahlen;

//---------------------------------------------------------------------------
//---ROT13---

//Verschl�sselung
String krypt::vROT13(String Text,int iVer)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]+iVer;                                 //Verschiebt jedes Zeichen um den Verschiebungswert nach vorne
   }

	return sVer;
}

//Entschl�sselung
String krypt::eROT13(String Text,int iVer)
{
   String sVer = Text;
                                                              //Verschiebt jedes Zeichen um den Verschiebungswert nach hinten
   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]-iVer;
   }

	return sVer;
}
 //---------------------------------------------------------------------------
 //---Passwortverschl�sselung---

 //Verschl�sselung
String krypt::vPw(String Text,String Pw)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {                 //addiert die Werte der 2 Zeichen miteinander und erzeugt somit ein anderes
	  sVer[i] = Text[i]+Pw[i%Pw.Length()+1];
   }

   // BUG Manche Zeichen k�nnen nicht dagestellt werden, aber kann trotzdem entschl�sset (A mit A verschl�sseln)
	return sVer;
}

//Entschl�sselung
String krypt::ePw(String Text, String Pw)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]-Pw[i%Pw.Length()+1];
   }

	return sVer;
}
//---------------------------------------------------------------------------
//---XOR-Verschl�sselung---

String krypt::vXOR(String Text)
{                                                             //invertiert jedes Zeichen
   for (int i = 1; i <=  Text.Length(); i++)
   Text[i] = Text[i]^ 1;
   return Text;
}
//---------------------------------------------------------------------------
//---Primzahlenverschl�sselung---

bool krypt::gPr(int Pr)
{
  for (int i = 2; i <= sqrt((float)Pr); (i==2)? i++ :i+=2) {
  if (Pr%i == 0) return 0;                                    //�berpr�ft ob es sich bei "Pr" um eine Primzahl handelt
  }
	return 1;
}

String krypt::gStrPr(int start,int ende)
{
 for (int i = start; i <= ende; i++) {

                                                              //Erstellt eine Zeichenkette aus den Priemzahlen im Bereich
  if(gPr(i)){
  Primzahlen = Primzahlen + i;
  }

}
return Primzahlen;

}
//---------------------------------------------------------------------------
//---Reverse

String krypt::vREV(String Text)
{
   String sVer = Text;
   int icool =1;                                              //Dreht die Zeichenkette um

   for (int i = Text.Length(); i >= 1; i--) {
	  sVer[icool] = Text[i];
	  icool++;
   }

    return sVer;
}
//---------------------------------------------------------------------------


