//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Web.Win.Sockets"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TcpServer1Accept(TObject *Sender, TCustomIpClient *ClientSocket)

{
   int a = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TcpServer1CreateHandle(TObject *Sender)
{
             int a = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TcpServer1Listening(TObject *Sender)
{
       int a = 2;
}
//---------------------------------------------------------------------------
