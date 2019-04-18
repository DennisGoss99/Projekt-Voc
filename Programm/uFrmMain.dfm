object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'VokabelTrainer'
  ClientHeight = 429
  ClientWidth = 885
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = fMainMenu
  OldCreateOrder = False
  Position = poDesigned
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Splitter1: TSplitter
    Left = 337
    Top = 35
    Height = 394
    Color = clBackground
    ParentColor = False
    ExplicitLeft = 344
    ExplicitTop = 120
    ExplicitHeight = 100
  end
  object fPnMainRight: TPanel
    Left = 340
    Top = 35
    Width = 545
    Height = 394
    Align = alClient
    TabOrder = 0
    ExplicitLeft = 390
    ExplicitWidth = 495
    DesignSize = (
      545
      394)
    object mlbStatisticG: TLabel
      Left = 27
      Top = 361
      Width = 45
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'Anzahl: 0'
      ExplicitTop = 359
    end
    object mlbStatisticR: TLabel
      Left = 175
      Top = 361
      Width = 45
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'Richtig: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 6273177
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitTop = 359
    end
    object mlbStatisticF: TLabel
      Left = 323
      Top = 361
      Width = 51
      Height = 13
      Anchors = [akLeft, akBottom]
      Caption = 'Fehlend: 0'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = 4670451
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ExplicitTop = 359
    end
    object mPnStatisticMain: TPanel
      Left = 7
      Top = 6
      Width = 516
      Height = 349
      Anchors = [akLeft, akTop, akRight, akBottom]
      TabOrder = 0
      ExplicitWidth = 466
      DesignSize = (
        516
        349)
      object sgaSb: TScrollBar
        Left = 1
        Top = 331
        Width = 514
        Height = 17
        Align = alBottom
        DoubleBuffered = False
        Max = 400
        PageSize = 50
        ParentDoubleBuffered = False
        TabOrder = 0
        OnChange = sgaSbChange
        ExplicitTop = 332
        ExplicitWidth = 465
      end
      object mPnStatistic: TPanel
        Left = 0
        Top = 0
        Width = 467
        Height = 333
        Anchors = [akTop, akBottom]
        BevelOuter = bvNone
        TabOrder = 1
        DesignSize = (
          467
          333)
        object sga0: TGauge
          Left = 12
          Top = 16
          Width = 39
          Height = 313
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
          Progress = 9
        end
        object sga1: TGauge
          Left = 57
          Top = 16
          Width = 39
          Height = 313
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
          Height = 313
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
          Height = 313
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
          Height = 313
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
          Height = 313
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
          Height = 313
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
          Height = 313
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
          Height = 313
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
          ExplicitHeight = 310
        end
        object sga9: TGauge
          Left = 417
          Top = 16
          Width = 39
          Height = 313
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
    end
  end
  object fPnMainLeft: TPanel
    Left = 0
    Top = 35
    Width = 337
    Height = 394
    Align = alLeft
    Enabled = False
    TabOrder = 1
    DesignSize = (
      337
      394)
    object mbtnStartVoc: TButton
      Left = 8
      Top = 356
      Width = 307
      Height = 25
      Anchors = [akLeft, akRight, akBottom]
      Caption = 'Start Vokabeln'
      TabOrder = 0
      ExplicitWidth = 313
    end
    object mgrbInfo: TGroupBox
      Left = 8
      Top = 10
      Width = 307
      Height = 135
      Anchors = [akLeft, akTop, akRight]
      TabOrder = 1
      ExplicitWidth = 313
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
        Width = 230
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
    object mgrbVoc: TGroupBox
      Left = 8
      Top = 148
      Width = 307
      Height = 205
      Anchors = [akLeft, akTop, akRight, akBottom]
      Caption = 'Unit Informationen'
      TabOrder = 2
      ExplicitWidth = 313
      DesignSize = (
        307
        205)
      object vgrbUnit: TGroupBox
        Left = 8
        Top = 51
        Width = 282
        Height = 139
        Anchors = [akLeft, akTop, akRight, akBottom]
        Caption = 'Unit 1'
        TabOrder = 0
        ExplicitWidth = 288
        DesignSize = (
          282
          139)
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
          Anchors = [akTop, akRight]
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
        object ulbVocAn: TLabel
          Left = 11
          Top = 44
          Width = 82
          Height = 13
          Caption = 'Anzahl Vokabeln:'
        end
      end
      object vcmbUnit: TComboBox
        Left = 9
        Top = 23
        Width = 233
        Height = 21
        Anchors = [akLeft, akTop, akRight]
        TabOrder = 1
      end
    end
  end
  object fPnMainTop: TPanel
    Left = 0
    Top = 0
    Width = 885
    Height = 35
    Align = alTop
    TabOrder = 2
    DesignSize = (
      885
      35)
    object flbLoginNot: TLabel
      Left = 8
      Top = 8
      Width = 81
      Height = 13
      Caption = 'Nicht Eingeloggt!'
    end
    object flbLoginPw: TLabel
      Left = 627
      Top = 8
      Width = 50
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'Password:'
      ExplicitLeft = 480
    end
    object flbLoginName: TLabel
      Left = 374
      Top = 8
      Width = 107
      Height = 13
      Anchors = [akTop, akRight]
      Caption = 'Benutzername / Email:'
    end
    object fedLoginPw: TEdit
      Left = 683
      Top = 3
      Width = 134
      Height = 21
      Anchors = [akTop, akRight]
      PasswordChar = '*'
      TabOrder = 0
    end
    object fedLoginName: TEdit
      Left = 487
      Top = 3
      Width = 134
      Height = 21
      Anchors = [akTop, akRight]
      TabOrder = 1
    end
    object fbtLogin: TButton
      Left = 821
      Top = 4
      Width = 59
      Height = 20
      Anchors = [akTop, akRight]
      Caption = 'Login'
      TabOrder = 2
      OnClick = fbtLoginClick
    end
  end
  object fMainMenu: TMainMenu
    Left = 296
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
    Left = 193
    Top = 65528
  end
  object mainDataSource: TDataSource
    DataSet = mainADOQuery
    Left = 248
    Top = 65528
  end
  object mainADOQuery: TADOQuery
    Connection = mainADOConnection
    Parameters = <>
    Left = 224
    Top = 65528
  end
end
