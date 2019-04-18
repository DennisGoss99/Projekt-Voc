object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'VokabelTrainer'
  ClientHeight = 416
  ClientWidth = 738
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = fMainMenu
  OldCreateOrder = False
  Position = poDesigned
  DesignSize = (
    738
    416)
  PixelsPerInch = 96
  TextHeight = 13
  object flbLoginPw: TLabel
    Left = 480
    Top = 8
    Width = 50
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Password:'
  end
  object flbLoginName: TLabel
    Left = 229
    Top = 8
    Width = 107
    Height = 13
    Anchors = [akTop, akRight]
    Caption = 'Benutzername / Email:'
  end
  object flbLoginNot: TLabel
    Left = 8
    Top = 8
    Width = 81
    Height = 13
    Caption = 'Nicht Eingeloggt!'
  end
  object fPnMain: TPanel
    Left = 0
    Top = 30
    Width = 739
    Height = 392
    Anchors = [akLeft, akTop, akRight, akBottom]
    Enabled = False
    TabOrder = 0
    DesignSize = (
      739
      392)
    object mlbStatisticR: TLabel
      Left = 433
      Top = 359
      Width = 45
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = 'Richtig: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6273177
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object mlbStatisticF: TLabel
      Left = 581
      Top = 359
      Width = 51
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = 'Fehlend: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4670451
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object mlbStatisticG: TLabel
      Left = 285
      Top = 359
      Width = 45
      Height = 13
      Anchors = [akRight, akBottom]
      Caption = 'Anzahl: 0'
    end
    object mPnStatistic: TPanel
      Left = 273
      Top = 10
      Width = 462
      Height = 335
      Anchors = [akTop, akRight, akBottom]
      TabOrder = 0
      DesignSize = (
        462
        335)
      object sga0: TGauge
        Left = 12
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga1: TGauge
        Left = 57
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga2: TGauge
        Left = 102
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga3: TGauge
        Left = 147
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga4: TGauge
        Left = 192
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga5: TGauge
        Left = 237
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga6: TGauge
        Left = 282
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga7: TGauge
        Left = 327
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga8: TGauge
        Left = 372
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
      object sga9: TGauge
        Left = 417
        Top = 16
        Width = 39
        Height = 310
        Anchors = [akLeft, akTop, akBottom]
        BackColor = 4670451
        BorderStyle = bsNone
        ForeColor = 6273177
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = []
        Kind = gkVerticalBar
        ParentFont = False
        Progress = 60
      end
    end
    object mgrbVoc: TGroupBox
      Left = 8
      Top = 145
      Width = 259
      Height = 200
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = 'Unit Informationen'
      TabOrder = 1
      DesignSize = (
        259
        200)
      object vcbUnit: TComboBox
        Left = 8
        Top = 24
        Width = 241
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 0
        Text = 'ComboBox1'
      end
      object vgrbUnit: TGroupBox
        Left = 8
        Top = 51
        Width = 241
        Height = 134
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = 'Unit 1'
        TabOrder = 1
        object ulbVocAn: TLabel
          Left = 11
          Top = 44
          Width = 82
          Height = 13
          Caption = 'Anzahl Vokabeln:'
        end
        object ulbVocBea: TLabel
          Left = 11
          Top = 63
          Width = 100
          Height = 13
          Caption = 'Vokabeln bearbeitet:'
        end
        object ulbVocLag: TLabel
          Left = 11
          Top = 25
          Width = 43
          Height = 13
          Caption = 'Sprache:'
        end
        object uimUnit: TImage
          Left = 184
          Top = 12
          Width = 50
          Height = 37
        end
        object ulbVocOp: TLabel
          Left = 11
          Top = 82
          Width = 76
          Height = 13
          Caption = 'Vokabeln offen:'
        end
        object ulbVocTim: TLabel
          Left = 11
          Top = 101
          Width = 95
          Height = 13
          Caption = 'Letzte Bearbeitung:'
        end
      end
    end
    object mbtnStartVoc: TButton
      Left = 8
      Top = 351
      Width = 259
      Height = 25
      Anchors = [akLeft, akRight, akBottom]
      Caption = 'Start Vokabeln'
      TabOrder = 2
    end
    object mgrbInfo: TGroupBox
      Left = 8
      Top = 10
      Width = 259
      Height = 135
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 3
      object ilb0: TLabel
        Left = 8
        Top = 16
        Width = 201
        Height = 13
        Caption = 'F'#252'llen Sie das Programm mit Inhalt!'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
      end
      object ilb1: TLabel
        Left = 12
        Top = 35
        Width = 188
        Height = 13
        Caption = 'Sie k'#246'nnen selber K'#228'rtchen zum Lernen'
      end
      object ilb2: TLabel
        Left = 12
        Top = 50
        Width = 189
        Height = 13
        Caption = 'anlegen oder Lernstoff aus Lehrwerken'
      end
      object ilb3: TLabel
        Left = 12
        Top = 67
        Width = 177
        Height = 13
        Caption = 'verschiedener Verlage erwerben und'
      end
      object ilb4: TLabel
        Left = 12
        Top = 83
        Width = 58
        Height = 13
        Caption = 'importieren.'
      end
      object ibtAddVoc: TButton
        Left = 12
        Top = 102
        Width = 232
        Height = 20
        Caption = 'K'#228'rtchen manuell eingeben >'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -11
        Font.Name = 'Tahoma'
        Font.Pitch = fpFixed
        Font.Style = []
        Font.Quality = fqProof
        ParentFont = False
        TabOrder = 0
      end
    end
  end
  object fedLoginPw: TEdit
    Left = 536
    Top = 3
    Width = 134
    Height = 21
    Anchors = [akTop, akRight]
    PasswordChar = '*'
    TabOrder = 2
  end
  object fbtLogin: TButton
    Left = 674
    Top = 4
    Width = 59
    Height = 20
    Anchors = [akTop, akRight]
    Caption = 'Login'
    TabOrder = 3
    OnClick = fbtLoginClick
  end
  object fedLoginName: TEdit
    Left = 340
    Top = 3
    Width = 134
    Height = 21
    Anchors = [akTop, akRight]
    TabOrder = 1
  end
  object fMainMenu: TMainMenu
    Left = 384
    Top = 65528
    object Datei1: TMenuItem
      Caption = '&Datei'
      object Optionen1: TMenuItem
        Caption = 'Optionen'
      end
      object N2: TMenuItem
        Caption = '-'
      end
      object Beenden1: TMenuItem
        Caption = 'Beenden'
      end
    end
    object Bearbeiten1: TMenuItem
      Caption = '&Bearbeiten'
      object Hilfe1: TMenuItem
        Caption = 'Vokabeln Einf'#252'gen'
      end
    end
    object N1: TMenuItem
      Caption = '-'
    end
    object Hilfe2: TMenuItem
      Caption = '&Hilfe'
    end
  end
  object mainADOConnection: TADOConnection
    ConnectionString = 
      'Provider=MSDASQL.1;Persist Security Info=False;Data Source=DataV' +
      'oc;'
    LoginPrompt = False
    Provider = 'MSDASQL.1'
    Left = 105
  end
  object mainDataSource: TDataSource
    DataSet = mainADOQuery
    Left = 192
  end
  object mainADOQuery: TADOQuery
    Connection = mainADOConnection
    Parameters = <>
    Left = 152
  end
end
