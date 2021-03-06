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

// RowanDialog: // CurrEmbl.cpp : implementation file
//

#include "stdafx.h"
#include "mig.h"
#include "CurrEmbl.h"
#include "winmove.h"
#include "comms.h"


#ifdef _DEBUG
//#define new DEBUG_NEW
#ifndef THIS_FILE_DEFINED
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif
/////////////////////////////////////////////////////////////////////////////
// CCurrEmblem dialog


CCurrEmblem::CCurrEmblem(CWnd* pParent /*=NULL*/)
	: RowanDialog(CCurrEmblem::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCurrEmblem)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CCurrEmblem::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCurrEmblem)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX,IDC_NOSEART0,m_IDC_NOSEART0);
	DDX_Control(pDX,IDC_RSTATICCTRL24,m_IDC_RSTATICCTRL24);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCurrEmblem, CDialog)
	//{{AFX_MSG_MAP(CCurrEmblem)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCurrEmblem message handlers

BOOL CCurrEmblem::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CRButton* rbutton;
	rbutton=GETDLGITEM(IDC_NOSEART0);
	CRStatic* s =   GETDLGITEM(IDC_RSTATICCTRL24);
	
	if (DPlay::H2H_Player[_DPlay.mySlot].squadron < PT_GER_FLYABLE)
	{
		rbutton->ShowWindow(SW_SHOW);
		s->ShowWindow(SW_SHOW);
//DEADCODE AMM 17/01/00 		int decal = DPlay::H2H_Player[_DPlay.mySlot].decal;
		int decal=0;
		assert (decal>=0 && decal<32)
		if (decal < 16)
			decal = decal + FIL_NOSE_STD_1;
		else
			decal = decal - 16 + FIL_NOSE_USER_1;
  
		rbutton->SetNormalFileNum(decal);
		rbutton->SetPressedFileNum(decal);
	}else
	{
		rbutton->ShowWindow(SW_HIDE);
		s->ShowWindow(SW_HIDE);
	}

	FullPanel()->ResetVariantOption();



	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
