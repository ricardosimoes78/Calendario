object frm_Calendario: Tfrm_Calendario
  Left = 1104
  Top = 333
  Width = 792
  Height = 614
  HorzScrollBar.Visible = False
  VertScrollBar.Visible = False
  Caption = 'Calendario'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object bvl_Separador2: TBevel
    Left = 8
    Top = 320
    Width = 537
    Height = 17
    Shape = bsTopLine
  end
  object H0600: TLabel
    Left = 8
    Top = 352
    Width = 27
    Height = 13
    Caption = '06:00'
  end
  object H0800: TLabel
    Left = 8
    Top = 376
    Width = 27
    Height = 13
    Caption = '08:00'
  end
  object H1400: TLabel
    Left = 8
    Top = 448
    Width = 27
    Height = 13
    Caption = '14:00'
  end
  object H1200: TLabel
    Left = 8
    Top = 424
    Width = 27
    Height = 13
    Caption = '12:00'
  end
  object H1000: TLabel
    Left = 8
    Top = 400
    Width = 27
    Height = 13
    Caption = '10:00'
  end
  object H2200: TLabel
    Left = 8
    Top = 544
    Width = 27
    Height = 13
    Caption = '22:00'
  end
  object H2000: TLabel
    Left = 8
    Top = 520
    Width = 27
    Height = 13
    Caption = '20:00'
  end
  object H1800: TLabel
    Left = 8
    Top = 496
    Width = 27
    Height = 13
    Caption = '18:00'
  end
  object H1600: TLabel
    Left = 8
    Top = 472
    Width = 27
    Height = 13
    Caption = '16:00'
  end
  object lbl_Sem_Domingo: TLabel
    Left = 40
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Domingo'
    Color = clBtnFace
    ParentColor = False
  end
  object lbl_Sem_Segunda: TLabel
    Left = 112
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Segunda'
  end
  object lbl_Sem_Quarta: TLabel
    Left = 256
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Quarta'
  end
  object lbl_Sem_Terca: TLabel
    Left = 184
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Ter'#231'a'
  end
  object lbl_Sem_Sabado: TLabel
    Left = 472
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'S'#225'bado'
  end
  object lbl_Sem_Sexta: TLabel
    Left = 400
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Sexta'
  end
  object lbl_Sem_Quinta: TLabel
    Left = 328
    Top = 328
    Width = 72
    Height = 13
    Alignment = taCenter
    AutoSize = False
    Caption = 'Quinita'
  end
  object Calendario: TMonthCalendar
    Left = 452
    Top = 56
    Width = 309
    Height = 253
    Date = 42307.9379384259
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Verdana'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object pnl_Horario_Fundo: TPanel
    Left = 0
    Top = 0
    Width = 776
    Height = 50
    Align = alTop
    TabOrder = 1
    object lbl_Horario_Fundo: TLabel
      Left = 1
      Top = 1
      Width = 760
      Height = 24
      Alignment = taCenter
      AutoSize = False
      Caption = 'lbl_Horario_Fundo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Courier New'
      Font.Style = []
      ParentFont = False
    end
    object pnl_Horario_Cores: TPanel
      Left = 8
      Top = 0
      Width = 185
      Height = 41
      TabOrder = 0
      object lbl_Horario_Cores: TLabel
        Left = 32
        Top = 1
        Width = 272
        Height = 30
        Alignment = taCenter
        Caption = 'lbl_Horario_Cores'
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clWindowText
        Font.Height = -27
        Font.Name = 'Courier New'
        Font.Style = []
        ParentFont = False
      end
    end
  end
  object Projeto: TPanel
    Left = 10
    Top = 96
    Width = 433
    Height = 217
    TabOrder = 2
  end
  object bto_IncProjeto: TButton
    Left = 290
    Top = 64
    Width = 75
    Height = 25
    Caption = '+ Projeto'
    TabOrder = 3
    OnClick = bto_IncProjetoClick
  end
  object edt_IncProjeto: TEdit
    Left = 10
    Top = 64
    Width = 153
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 4
  end
  object edt_DataProjeto: TEdit
    Left = 170
    Top = 64
    Width = 113
    Height = 28
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 5
  end
  object bto_Salvar: TButton
    Left = 370
    Top = 64
    Width = 65
    Height = 25
    Caption = 'v Salvar'
    TabOrder = 6
    OnClick = bto_SalvarClick
  end
  object Memo1: TMemo
    Left = 552
    Top = 320
    Width = 209
    Height = 241
    Lines.Strings = (
      'Memo1')
    TabOrder = 7
  end
  object Relogio: TTimer
    OnTimer = RelogioTimer
    Left = 12
    Top = 8
  end
end
