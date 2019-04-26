//---------------------------------------------------------------------------

#ifndef uFrmMainH
#define uFrmMainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Samples.Gauges.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>

#include "cDBService.h"
#include "cUser.h"
#include "cLogSystem.h"
#include "cPaintbox.h"
#include "uFrmAddVoc.h"

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TEdit *fedLoginName;
	TEdit *fedLoginPw;
	TButton *fbtLogin;
	TLabel *mlbStatisticG;
	TLabel *mlbStatisticR;
	TLabel *mlbStatisticF;
	TGroupBox *mgrbVoc;
	TButton *mbtnStartVoc;
	TImage *uimUnit;
	TLabel *ulbVocLag;
	TLabel *ulbVocAn;
	TLabel *ulbVocBea;
	TGroupBox *vgrbUnit;
	TLabel *ulbVocOp;
	TGroupBox *mgrbInfo;
	TLabel *ilb0;
	TLabel *ilb1;
	TLabel *ilb2;
	TLabel *ilb3;
	TLabel *ilb4;
	TButton *ibtAddVoc;
	TLabel *ulbVocTim;
	TMainMenu *fMainMenu;
	TMenuItem *Datei1;
	TMenuItem *Bearbeiten1;
	TMenuItem *Hilfe1;
	TMenuItem *Hilfe2;
	TMenuItem *N1;
	TMenuItem *Optionen1;
	TMenuItem *Beenden1;
	TMenuItem *N2;
	TLabel *flbLoginPw;
	TLabel *flbLoginName;
	TLabel *flbLoginNot;
	TADOConnection *mainADOConnection;
	TDataSource *mainDataSource;
	TADOQuery *mainADOQuery;
	TPanel *fPnMainRight;
	TPanel *fPnMainLeft;
	TPanel *fPnMainTop;
	TSplitter *Splitter1;
	TPanel *mPnStatisticMain;
	TComboBox *vcmbUnit;
	TImageCollection *mainImageCollection;
	TMenuItem *Log1;
	TMenuItem *Leeren1;
	TMenuItem *Anschalten1;
	TPaintBox *mPbStatistic;
	TMenuItem *ffnen1;
	TMenuItem *N3;
	void __fastcall fbtLoginClick(TObject *Sender);
	void __fastcall Beenden1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall vcmbUnitChange(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall Anschalten1Click(TObject *Sender);
	void __fastcall Leeren1Click(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall ibtAddVocClick(TObject *Sender);
	void __fastcall ffnen1Click(TObject *Sender);





private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen

	User *mainUser;

	__fastcall TfrmMain(TComponent* Owner);
	void PlotStatistics(void);
	void UpdateUI(void);
	void UpdateAfterLogin(void);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
