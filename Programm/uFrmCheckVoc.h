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
//---------------------------------------------------------------------------
class TfrmCheckVoc : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TPanel *pnGlos;
	TPanel *Panel2;
	TPanel *pnVoc;
	TButton *btnShowGlos;
	TLabel *Label1;
	TLabel *Label2;
	TImage *Image1;
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
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen

	bool showGloss = false;
    void ToggleGlos(void);
	void SetGlos(bool showGloss);

	__fastcall TfrmCheckVoc(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmCheckVoc *frmCheckVoc;
//---------------------------------------------------------------------------
#endif
