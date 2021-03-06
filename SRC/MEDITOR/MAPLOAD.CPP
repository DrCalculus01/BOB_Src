/*
	 Battle of Britain
	 Copyright (C) 2000, 2001 Empire Interactive (Europe) Ltd,
	 677 High Road, North Finchley, London N12 0DA

	 Please see the document licence.doc for the full licence agreement

2. LICENCE
 2.1 	
 	Subject to the provisions of this Agreement we now grant to you the 
 	following rights in respect of the Source Code:
  2.1.1 
  	the non-exclusive right to Exploit  the Source Code and Executable 
  	Code on any medium; and 
  2.1.2 
  	the non-exclusive right to create and distribute Derivative Works.
 2.2 	
 	Subject to the provisions of this Agreement we now grant you the
	following rights in respect of the Object Code:
  2.2.1 
	the non-exclusive right to Exploit the Object Code on the same
	terms and conditions set out in clause 3, provided that any
	distribution is done so on the terms of this Agreement and is
	accompanied by the Source Code and Executable Code (as
	applicable).

3. GENERAL OBLIGATIONS
 3.1 
 	In consideration of the licence granted in clause 2.1 you now agree:
  3.1.1 
	that when you distribute the Source Code or Executable Code or
	any Derivative Works to Recipients you will also include the
	terms of this Agreement;
  3.1.2 
	that when you make the Source Code, Executable Code or any
	Derivative Works ("Materials") available to download, you will
	ensure that Recipients must accept the terms of this Agreement
	before being allowed to download such Materials;
  3.1.3 
	that by Exploiting the Source Code or Executable Code you may
	not impose any further restrictions on a Recipient's subsequent
	Exploitation of the Source Code or Executable Code other than
	those contained in the terms and conditions of this Agreement;
  3.1.4 
	not (and not to allow any third party) to profit or make any
	charge for the Source Code, or Executable Code, any
	Exploitation of the Source Code or Executable Code, or for any
	Derivative Works;
  3.1.5 
	not to place any restrictions on the operability of the Source 
	Code;
  3.1.6 
	to attach prominent notices to any Derivative Works stating
	that you have changed the Source Code or Executable Code and to
	include the details anddate of such change; and
  3.1.7 
  	not to Exploit the Source Code or Executable Code otherwise than
	as expressly permitted by  this Agreement.

questions about this file may be asked at bob@rowansoftware.com a
better place to ask is http://www.simhq.com/ or even :-
http://www.simhq.com/cgi-bin/boards/cgi-bin/forumdisplay.cgi?action=topics&forum=Battle+of+Britain&number=40&DaysPrune=20&LastLogin=
*/

//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include	"memain.h"
#include "mapload.h"
#include	"monotxt2.h"
//---------------------------------------------------------------------------
//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall MapLoad::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------


__fastcall MapLoad::MapLoad(bool CreateSuspended)
	: TThread(CreateSuspended)
{
  	leveldrop=MissionEditor->leveldrop;
	cfreq=RegisterClipboardFormat("RowanTT2Req");
	cfsrc=RegisterClipboardFormat("RowanTT2Sup");
    Priority=tpLower;
}
//---------------------------------------------------------------------------

void __fastcall MapLoad::Execute()
{
	//---- Place thread code here ----
    static	MonoText mt(0xb0000+160*24+79*2);
forever
    if (MissionEditor->loadrequested && IsClipboardFormatAvailable(cfsrc))
    {   //start copying: first flag as scaled, then begin to copy.
    	mt.PrintF(0,0,"L");
		LevelDrop& ld=leveldrop[MissionEditor->levelreq];
		int blcm=(ld.minscale*2048);
		int dx=MissionEditor->xloadreq/blcm-ld.px;
		int dy=MissionEditor->yloadreq/blcm-ld.py;
        if (dx>=0 && dy>=0 && dx<2 && dy<2)
            while (ld.maps[dx+dy*2].c==NULL)
                Sleep(2);
        while (!OpenClipboard(NULL))
        	Sleep(0);
        HANDLE clip=GetClipboardData(cfsrc);
    	mt.PrintF(0,0,"l");
        char* src=(char*)GlobalLock(clip);
        if (src)
		if (dx>=0 && dy>=0 && dx<2 && dy<2)
		{
          	ld.maps[dx+dy*2].scaled=-1;
			ld.dirty[dx+dy*2]=true;
			char* trg=ld.maps[dx+dy*2].c;
            memcpy(trg,src,2048*2048);
			ld.dirty[dx+dy*2]=false;
        }
		GlobalUnlock(clip);
		EmptyClipboard();
    	CloseClipboard();
        MissionEditor->loadrequested=false;
    	mt.PrintF(0,0,"F");
    }
    else
    {
    	mt.PrintF(0,0,"S");
    	Sleep(500);
    	mt.PrintF(0,0,"s");
    	Sleep(500);
     }

}
//---------------------------------------------------------------------------
