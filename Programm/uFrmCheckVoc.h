//---------------------------------------------------------------------------

#ifndef uFrmCheckVocH
#define uFrmCheckVocH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.BaseImageCollection.hpp>
#include <Vcl.ImageCollection.hpp>
#include "cLogSystem.h"
#include <vector>
#include <time.h>
//---------------------------------------------------------------------------
class TfrmCheckVoc : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TPanel *pnGlos;
	TPanel *Panel2;
	TPanel *pnVoc;
	TButton *btnShowGlos;
	TLabel *lbUnit;
	TLabel *lbUnitDescription;
	TImage *imCheck;
	TButton *btnCheck;
	TButton *btnCancel;
	TGroupBox *grbVocNT;
	TMemo *mVocT;
	TGroupBox *grbVocT;
	TMemo *mVocNT;
	TPanel *pnVocIntern;
	TGroupBox *grbGlos;
	TMemo *mGlos;
	TImageCollection *ImageCollectionCheckbox;
	void __fastcall pnVocResize(TObject *Sender);
	void __fastcall btnShowGlosClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall btnCancelClick(TObject *Sender);
	void __fastcall btnCheckClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen

	bool showGloss = false;


	AnsiString SelectedUnit;

    int randomIndex;
	std::vector<AnsiString> UnitWord;
	std::vector<AnsiString> UnitWordTranslated;
	std::vector<AnsiString> UnitGlossary;

	void NewVoc(void);
    void ToggleGlos(void);
	void SetGlos(bool showGloss);
	void UpdateUI(void);
    void CheckVoc(void);

	__fastcall TfrmCheckVoc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCheckVoc *frmCheckVoc;
//---------------------------------------------------------------------------
#endif
