//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include<System.Classes.hpp>
#include<Vcl.Controls.hpp>
#include<Vcl.StdCtrls.hpp>
#include<Vcl.Forms.hpp>
#include<Vcl.ComCtrls.hpp>
#include<Vcl.ExtCtrls.hpp>
#include"include/DasHard.h.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "Web.Win.Sockets.hpp"
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include "trames.h"
#define DMX_MAXCHANNEL 512
//---------------------------------------------------------------------------
class TForm1 : public TForm
{

__published:	// Composants gérés par l'EDI
	TTimer *Timer1;
	TPanel *Connect;
	TLabel *Textco;
	TButton *Close;
	TScrollBar *red;
	TLabel *Labelred;
	TScrollBar *green;
	TLabel *Labelgreen;
	TScrollBar *blue;
	TLabel *Labelblue;
	TScrollBar *white;
	TLabel *Labelwhite;
	TScrollBar *stroboscope;
	TButton *reset;
	TButton *lampe2;
	TButton *lampe3;
	TButton *fondu;
	TTimer *Timer2;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject*Sender,TCloseAction&Action);
	void __fastcall CloseClick(TObject *Sender);
	void __fastcall resetClick(TObject *Sender);
	void __fastcall lampe2Click(TObject *Sender);
	void __fastcall lampe3Click(TObject *Sender);
	void __fastcall fonduClick(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);



private:	// Déclarations utilisateur

	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];
    unsigned char close[512];
	//void__fastcall SendTrame();
	int CouleurR;
	int CouleurG;
	int CouleurB;
	int CouleurW;
	int cas;
	int r,v,b;

public:		// Déclarations utilisateur
      SOCKET sock;
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SendTrame();


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
