object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 300
  ClientWidth = 635
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Textco: TLabel
    Left = 39
    Top = 12
    Width = 130
    Height = 13
    Caption = 'Impossible de se connecter'
  end
  object Labelred: TLabel
    Left = 8
    Top = 100
    Width = 58
    Height = 13
    Caption = 'Taux Rouge'
  end
  object Labelgreen: TLabel
    Left = 8
    Top = 157
    Width = 47
    Height = 13
    Caption = 'Taux Vert'
  end
  object Labelblue: TLabel
    Left = 8
    Top = 213
    Width = 47
    Height = 13
    Caption = 'Taux Bleu'
  end
  object Labelwhite: TLabel
    Left = 176
    Top = 100
    Width = 52
    Height = 13
    Caption = 'Taux Blanc'
  end
  object Connect: TPanel
    Left = 8
    Top = 8
    Width = 17
    Height = 17
    Color = clRed
    ParentBackground = False
    TabOrder = 0
  end
  object Close: TButton
    Left = 552
    Top = 8
    Width = 75
    Height = 25
    Caption = 'CLOSE'
    TabOrder = 1
    OnClick = CloseClick
  end
  object red: TScrollBar
    Left = 8
    Top = 119
    Width = 121
    Height = 17
    Cursor = crHandPoint
    Max = 255
    PageSize = 0
    TabOrder = 2
  end
  object green: TScrollBar
    Left = 8
    Top = 176
    Width = 121
    Height = 17
    Cursor = crHandPoint
    Max = 255
    PageSize = 0
    TabOrder = 3
  end
  object blue: TScrollBar
    Left = 8
    Top = 232
    Width = 121
    Height = 17
    Cursor = crHandPoint
    Max = 255
    PageSize = 0
    TabOrder = 4
  end
  object white: TScrollBar
    Left = 176
    Top = 119
    Width = 121
    Height = 17
    Cursor = crHandPoint
    Max = 255
    PageSize = 0
    Position = 255
    TabOrder = 5
  end
  object stroboscope: TScrollBar
    Left = 176
    Top = 176
    Width = 121
    Height = 17
    Max = 223
    Min = 190
    PageSize = 0
    Position = 190
    TabOrder = 6
  end
  object reset: TButton
    Left = 8
    Top = 69
    Width = 75
    Height = 25
    Caption = 'Reset'
    TabOrder = 7
    OnClick = resetClick
  end
  object lampe2: TButton
    Left = 472
    Top = 119
    Width = 155
    Height = 25
    Caption = 'Boutton Lampe 2 (simulation)'
    TabOrder = 8
    OnClick = lampe2Click
  end
  object lampe3: TButton
    Left = 472
    Top = 150
    Width = 155
    Height = 25
    Caption = 'Boutton Lampe 3 (simulation)'
    TabOrder = 9
    OnClick = lampe3Click
  end
  object fondu: TButton
    Left = 552
    Top = 181
    Width = 75
    Height = 25
    Caption = 'Fondu'
    TabOrder = 10
    OnClick = fonduClick
  end
  object Timer1: TTimer
    Interval = 5
    OnTimer = Timer1Timer
    Left = 584
    Top = 40
  end
  object Timer2: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer2Timer
    Left = 544
    Top = 40
  end
end
