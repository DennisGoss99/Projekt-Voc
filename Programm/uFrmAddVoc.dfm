object frmAddVoc: TfrmAddVoc
  Left = 0
  Top = 0
  Caption = 'Vokabeln / Units hinzuf'#252'gen'
  ClientHeight = 360
  ClientWidth = 486
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnResize = FormResize
  OnShow = FormShow
  DesignSize = (
    486
    360)
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 466
    Height = 121
    Anchors = [akLeft, akTop, akRight]
    Caption = 'Unit- Eigenschaften'
    TabOrder = 0
    DesignSize = (
      466
      121)
    object imUnit: TImage
      Left = 369
      Top = 32
      Width = 80
      Height = 48
      Anchors = [akTop, akRight]
      ExplicitLeft = 232
    end
    object Label1: TLabel
      Left = 20
      Top = 62
      Width = 43
      Height = 13
      Caption = 'Sprache:'
    end
    object Label2: TLabel
      Left = 20
      Top = 89
      Width = 49
      Height = 13
      Caption = 'Unitname:'
    end
    object edUnitName: TEdit
      Left = 80
      Top = 86
      Width = 129
      Height = 21
      TabOrder = 0
      OnChange = edUnitNameChange
    end
    object cmbUnit: TComboBox
      Left = 16
      Top = 32
      Width = 193
      Height = 21
      TabOrder = 1
      OnChange = cmbUnitChange
      Items.Strings = (
        '-- hinzuf'#252'gen --')
    end
    object cmbUnitLang: TComboBox
      Left = 80
      Top = 59
      Width = 129
      Height = 21
      TabOrder = 2
      OnChange = cmbUnitLangChange
    end
    object btnUnitDel: TButton
      Left = 443
      Top = 9
      Width = 20
      Height = 20
      Anchors = [akTop, akRight]
      Caption = 'X'
      TabOrder = 3
      OnClick = btnUnitDelClick
    end
  end
  object btnClose: TButton
    Left = 316
    Top = 325
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Abbruch'
    TabOrder = 1
    OnClick = btnCloseClick
  end
  object grbVocmain: TGroupBox
    Left = 8
    Top = 135
    Width = 466
    Height = 186
    Anchors = [akLeft, akTop, akRight, akBottom]
    TabOrder = 2
    object grbVocT: TGroupBox
      Left = 164
      Top = 15
      Width = 150
      Height = 147
      Align = alLeft
      Caption = 'Vokabel ['#252'bersetzt]'
      TabOrder = 1
      DesignSize = (
        150
        147)
      object lbVocT: TListBox
        Left = 13
        Top = 41
        Width = 127
        Height = 97
        TabStop = False
        Anchors = [akLeft, akTop, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 0
        OnClick = lbVocTClick
      end
      object edVocT: TEdit
        Left = 13
        Top = 21
        Width = 127
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 1
        OnKeyUp = edVocTKeyUp
      end
    end
    object grbVocNT: TGroupBox
      Left = 2
      Top = 15
      Width = 162
      Height = 147
      Align = alLeft
      Caption = 'Vokabel [un'#252'bersetzt]'
      TabOrder = 0
      DesignSize = (
        162
        147)
      object lbVocNT: TListBox
        Left = 13
        Top = 41
        Width = 142
        Height = 97
        TabStop = False
        Anchors = [akLeft, akTop, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 0
        OnClick = lbVocNTClick
      end
      object edVocNT: TEdit
        Left = 13
        Top = 21
        Width = 142
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 1
        OnKeyUp = edVocNTKeyUp
      end
    end
    object Panel1: TPanel
      Left = 2
      Top = 162
      Width = 462
      Height = 22
      Align = alBottom
      Caption = 'Panel1'
      TabOrder = 3
      object btnVocAdd: TButton
        Left = 1
        Top = 1
        Width = 385
        Height = 20
        Align = alClient
        Caption = 'hinzuf'#252'gen'
        TabOrder = 0
        OnClick = btnVocAddClick
      end
      object btnVocDel: TButton
        Left = 386
        Top = 1
        Width = 75
        Height = 20
        Align = alRight
        Caption = 'L'#246'schen'
        TabOrder = 1
        OnClick = btnVocDelClick
      end
    end
    object grbGlos: TGroupBox
      Left = 320
      Top = 15
      Width = 144
      Height = 147
      Align = alRight
      Caption = 'Glossar'
      TabOrder = 2
      DesignSize = (
        144
        147)
      object lbGlos: TListBox
        Left = 13
        Top = 41
        Width = 121
        Height = 97
        TabStop = False
        Anchors = [akLeft, akTop, akRight, akBottom]
        ItemHeight = 13
        TabOrder = 0
        OnClick = lbGlosClick
      end
      object edGlos: TEdit
        Left = 13
        Top = 21
        Width = 121
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 1
        OnKeyUp = edGlosKeyUp
      end
    end
  end
  object btnSave: TButton
    Left = 397
    Top = 325
    Width = 75
    Height = 25
    Anchors = [akRight, akBottom]
    Caption = 'Speichern'
    TabOrder = 3
    OnClick = btnSaveClick
  end
end
