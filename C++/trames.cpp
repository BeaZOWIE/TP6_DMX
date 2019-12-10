//---------------------------------------------------------------------------

#pragma hdrstop
#include "main.h"
#include "trames.h"
#include <iostream>
#include <conio.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)

trames::trames(){
}

trames::~trames(){
}

void trames::fondu(){
        do
	{
		v++;
		if(v == 255)
		{
			r++;
		}
		if(r == 255)
		{
			v--;
		}
		if((v == 0) && (r == 255))
		{
			b++;
		}
		if(b == 255)
		{
			r--;
		}
		if((b == 255) && (r == 0))
		{
			v++;
		}
		if((b == 255) && (v == 255))
		{
			r++;
		}
	}
	while((v != 255) && (r!= 255) && (b != 255));
}

