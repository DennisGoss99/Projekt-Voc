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

//---------------------------------------------------------------------------
class TfrmMain : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TEdit *fedLoginName;
	TEdit *fedLoginPw;
	TButton *fbtLogin;
	TGauge *sga0;
	TPanel *mPnStatistic;
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
	TGauge *sga1;
	TGauge *sga2;
	TGauge *sga3;
	TGauge *sga4;
	TGauge *sga5;
	TGauge *sga6;
	TGauge *sga7;
	TGauge *sga8;
	TGauge *sga9;
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
	TScrollBar *sgaSb;
	TPanel *mPnStatisticMain;
	TComboBox *vcmbUnit;
	TImageCollection *mainImageCollection;
	void __fastcall fbtLoginClick(TObject *Sender);
	void __fastcall sgaSbChange(TObject *Sender);
	void __fastcall FormResize(TObject *Sender);
	void __fastcall Beenden1Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall vcmbUnitChange(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TfrmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmMain *frmMain;
//---------------------------------------------------------------------------
#endif
