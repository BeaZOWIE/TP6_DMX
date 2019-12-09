//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "Web.Win.Sockets.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// Composants gérés par l'EDI
	TTcpServer *TcpServer1;
	void __fastcall TcpServer1Accept(TObject *Sender, TCustomIpClient *ClientSocket);
	void __fastcall TcpServer1CreateHandle(TObject *Sender);
	void __fastcall TcpServer1Listening(TObject *Sender);

private:	// Déclarations utilisateur
public:		// Déclarations utilisateur
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
