﻿//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
	typedef int socklen_t;
//#include "include/DasHard2006.dll"
#include "trames.h"
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
		else
		{
			Connect->Color = clRed;  //sinon c'est pas co
			Textco->Visible = true;
		}
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
	dmxBlock[0]=stroboscope->Position;
	dmxBlock[1]=red->Position;
	dmxBlock[2]=green->Position;
	dmxBlock[3]=blue->Position;
	dmxBlock[4]=white->Position;
	dmxBlock[5]=255;
}

//---------------------------------------------------------------------------

void __fastcall TForm1::CloseClick(TObject *Sender)
{
	Timer1->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::resetClick(TObject *Sender)
{
   red->Position=0;
   stroboscope->Position=190;
   blue->Position=0;
   green->Position=0;
   white->Position=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lampe2Click(TObject *Sender)
{
    Timer1->Enabled= false;
	for (int i = 0; i < 512; i++)  //on allume la lumière du channel 2
		{                          // en blanc
			dmxBlock[i]=0;
		}
		dmxBlock[6]=255;
		dmxBlock[7]=255;
		dmxBlock[8]=255;
		dmxBlock[9]=255;
		dmxBlock[10]=255;
		dmxBlock[11]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::lampe3Click(TObject *Sender)
{
	Timer1->Enabled= false;
	for (int i = 0; i < 512; i++)  //on allume la lumière du channel 3
		{                          //en blanc
			dmxBlock[i]=0;
		}
		dmxBlock[12]=255;
		dmxBlock[13]=255;
		dmxBlock[14]=255;
		dmxBlock[15]=255;
		dmxBlock[16]=255;
		dmxBlock[17]=255;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::fonduClick(TObject *Sender)
{
	Timer1->Enabled = false;
	Timer2->Enabled= true;
	cas = 0;
	r = 0;
	v = 0;
	b = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{

		for (int i = 0; i < 512; i++)
		{
			dmxBlock[i]=0;
		}
		dmxBlock[0]=32;
		dmxBlock[4]=0;
		dmxBlock[5]=0xFF;
		//on demarre le fondu

		SendTrame();
		switch(cas)
		{
			case 0:
				v+=2;  //on augmente le vert

				if(v >= 255)
				{
					v = 255;
					cas = 1;
				}
				break;

			case 1:
				 r+= 2; //puis le rouge
				 if(r >= 255)
				 {
					 r = 255;
					 cas = 2;
				 }
				break;

			case 2:
				v-=2;  //puis on enleve le vert
				if(v <= 0)
				{
					v = 0;
					cas = 3;
                }
				break;
			case 3:
				b+=2; //augmente le bleu
				if (b >=255)
				{
					b =255;
					cas = 4;
				}
				break;
			case 4:
				r-=2; //diminue le rouge
				if (r <= 0)
				{
					r = 0;
					cas = 5;
				}
				break;
			case 5:
				v+=2; //reaugmente le vert
				if (v >= 255)
				{
					v = 255;
					cas = 6;
				}
				break;
			case 6:
				r+=2;//reaugmente le rouge
				if (r >= 255)
				{
					r = 255;
					cas = 7;
				}
		}   //on termine avec les 3 couleurs a fond ce qui nous donne du blanc

			dmxBlock[1] = r;
			dmxBlock[2] = v;
			dmxBlock[3] = b;
			SendTrame();
}
//---------------------------------------------------------------------------

