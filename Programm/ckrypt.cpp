//---------------------------------------------------------------------------

#pragma hdrstop

#include "ckrypt.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

	int krypt::ROT13 = 13;                                                              //ROT13 shift
	String krypt::PW = "Passwort";                                                              //PW Password for encryption
	int krypt::PrStart = 15;                                                             //Primes Start value
	int krypt::PrEnd = 26;
	String krypt::Primzahlen;

//---------------------------------------------------------------------------
//---ROT13---

//encoding
String krypt::vROT13(String Text,int iVer)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]+iVer;                                 //Moves each character forward by the shift value
   }

	return sVer;
}

//decoding
String krypt::eROT13(String Text,int iVer)
{
   String sVer = Text;
                                                              //VMoves each character back by the shift value
   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]-iVer;
   }

	return sVer;
}
 //---------------------------------------------------------------------------
 //---Passwortverschlüsselung---

 //encoding
String krypt::vPw(String Text,String Pw)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {                 //adds the values of the 2 characters together and creates a different
	  sVer[i] = Text[i]+Pw[i%Pw.Length()+1];
   }

   // BUG Some characters cannot be displayed, but can still be decrypted (encrypt A with A)
	return sVer;
}

//decoding
String krypt::ePw(String Text, String Pw)
{
   String sVer = Text;

   for (int i = 1; i <= Text.Length(); i++) {
	  sVer[i] = Text[i]-Pw[i%Pw.Length()+1];
   }

	return sVer;
}
//---------------------------------------------------------------------------
//---XOR-encoding---

String krypt::vXOR(String Text)
{                                                             //inverts each character
   for (int i = 1; i <=  Text.Length(); i++)
   Text[i] = Text[i]^ 1;
   return Text;
}
//---------------------------------------------------------------------------
//---prime number encoding---

bool krypt::gPr(int Pr)
{
  for (int i = 2; i <= sqrt((float)Pr); (i==2)? i++ :i+=2) {
  if (Pr%i == 0) return 0;                                    //Checks whether "Pr" is a prime number
  }
	return 1;
}

String krypt::gStrPr(int start,int ende)
{
 for (int i = start; i <= ende; i++) {

                                                              //Creates a character string from the prime numbers in the range
  if(gPr(i)){e range
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
   int icool =1;                                              //Reverses the string

   for (int i = Text.Length(); i >= 1; i--) {
	  sVer[icool] = Text[i];
	  icool++;
   }

    return sVer;
}
//---------------------------------------------------------------------------


