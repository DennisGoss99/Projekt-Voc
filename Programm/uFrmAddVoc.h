//---------------------------------------------------------------------------

#ifndef uFrmAddVocH
#define uFrmAddVocH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <vector>
//---------------------------------------------------------------------------
class TfrmAddVoc : public TForm
{
__published:	// Von der IDE verwaltete Komponenten
	TImage *imUnit;
	TComboBox *cmbUnit;
	TEdit *edUnitName;
	TGroupBox *GroupBox1;
	TLabel *Label1;
	TComboBox *cmbUnitLang;
	TLabel *Label2;
	TButton *btnSave;
	TButton *btnClose;
	TGroupBox *grbVocmain;
	TListBox *lbVocNT;
	TEdit *edVocNT;
	TGroupBox *grbVocNT;
	TGroupBox *grbVocT;
	TListBox *lbVocT;
	TEdit *edVocT;
	TButton *btnVocAdd;
	TPanel *Panel1;
	TButton *btnVocDel;
	TButton *btnUnitDel;
	TGroupBox *grbGlos;
	TListBox *lbGlos;
	TEdit *edGlos;
	void __fastcall FormResize(TObject *Sender);
	void __fastcall lbVocNTClick(TObject *Sender);
	void __fastcall lbVocTClick(TObject *Sender);
	void __fastcall btnVocDelClick(TObject *Sender);
	void __fastcall btnVocAddClick(TObject *Sender);
	void __fastcall lbGlosClick(TObject *Sender);
	void __fastcall edVocNTKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall edVocTKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall edGlosKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall btnCloseClick(TObject *Sender);
	void __fastcall btnSaveClick(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall cmbUnitChange(TObject *Sender);
	void __fastcall cmbUnitLangChange(TObject *Sender);
	void __fastcall edUnitNameChange(TObject *Sender);
	void __fastcall btnUnitDelClick(TObject *Sender);
private:	// Benutzer-Deklarationen
public:		// Benutzer-Deklarationen
	__fastcall TfrmAddVoc(TComponent* Owner);

	void ClearVoc(void);
	AnsiString ListToWhereString(TListBox *listBox);
	void FillListbox(TListBox *listBox, std::vector<AnsiString> tempList);
	void FillListbox(TComboBox *comboBox, std::vector<AnsiString> tempList);

};
//---------------------------------------------------------------------------
extern PACKAGE TfrmAddVoc *frmAddVoc;
//---------------------------------------------------------------------------
#endif
