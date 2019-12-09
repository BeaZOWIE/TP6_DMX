﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
	typedef int socklen_t;
//#include "include/DasHard2006.dll"
#include "EnAttente.h"
#include "main.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Web.Win.Sockets"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;
	if(!erreur)
	{
		Textco->Visible = false;
		g_dasusbdll=LoadLibrary(L"DasHard2006.dll");
		if(g_dasusbdll)
		{
			DasUsbCommand=(DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
		}
		interface_open=DasUsbCommand(DHC_INIT,0,NULL);
		DasUsbCommand(DHC_OPEN,0,0);

		if (interface_open == 136)
		{
		   Connect->Color = clLime; //136 c'est le message de réussite
		}
		else
		{
			Connect->Color = clRed;  //sinon c'est pas co
			Textco->Visible = true;
		}

		for (int i = 0; i < 512; i++)  //on allume la lumière une fois connecté
		{
			dmxBlock[i]=0;
		}
		dmxBlock[0]=0xFF;
		dmxBlock[1]=0xFF;
		dmxBlock[2]=0xFF;
		dmxBlock[3]=0xFF;
		dmxBlock[4]=0xFF;
		dmxBlock[5]=0xFF;

	}
}

//---------------------------------------------------------------------------
 void __fastcall TForm1::SendTrame()
 {
	if(interface_open>0)
	{
		try
		{
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
		}
		catch(int x)
		{
		}
	}

 }

 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
 //FermetureduDMX�l'arretduprogramme
	if(interface_open>0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	SendTrame();
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=red->Position;
	dmxBlock[2]=green->Position;
	dmxBlock[3]=blue->Position;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BleuClick(TObject *Sender)
{
		for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=255;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BlancClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::RougeClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=255;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VertClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=255;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ONClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
	dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
	Connect->Color = clLime;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::OFFClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=0;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
     Connect->Color = clRed;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::StroboscopeClick(TObject *Sender)
{
	for (int i = 0; i < 512; i++) {
	dmxBlock[i]=0;
	}
	dmxBlock[0]=215;
	dmxBlock[1]=255;
	dmxBlock[2]=255;
	dmxBlock[3]=255;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
//---------------------------------------------------------------------------
