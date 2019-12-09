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
  object TcpServer1: TTcpServer
    Active = True
    LocalPort = '23565'
    OnAccept = TcpServer1Accept
    OnListening = TcpServer1Listening
    OnCreateHandle = TcpServer1CreateHandle
    Left = 256
    Top = 128
  end
end
