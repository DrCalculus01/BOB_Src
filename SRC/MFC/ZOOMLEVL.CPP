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

// RowanDialog: // ZoomLevl.cpp : implementation file
//

#include "stdafx.h"
#include "bob.h"
#include "ZoomLevl.h"

float ZoomLevel::zoomLevel[16]={	0.25,	0.5,	1,		2,
									4,		6,		8,		10,
									15,		20,		30,		40,
									50,		60,		80,		100};


#ifdef _DEBUG
//#define new DEBUG_NEW
#ifndef THIS_FILE_DEFINED
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// ZoomLevel dialog


RDialog*	ZoomLevel::Make()
{
	return
		MakeTopDialog(::Place(POSN_CENTRE,POSN_CENTRE),
			DialBox(FIL_D_BLANK,new ZoomLevel())
			);
}


ZoomLevel::ZoomLevel(CWnd* pParent /*=NULL*/)
	: RowanDialog(ZoomLevel::IDD, pParent)
{
	//{{AFX_DATA_INIT(ZoomLevel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void ZoomLevel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ZoomLevel)
	DDX_Control(pDX, IDC_RSPINBUT_DEFAULTZOOM, m_IDC_RSPINBUT_DEFAULTZOOM);
	DDX_Control(pDX, IDC_RSPINBUT_SECONDZOOM, m_IDC_RSPINBUT_SECONDZOOM);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ZoomLevel, CDialog)
	//{{AFX_MSG_MAP(ZoomLevel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ZoomLevel message handlers

BEGIN_EVENTSINK_MAP(ZoomLevel, CDialog)
    //{{AFX_EVENTSINK_MAP(ZoomLevel)
	ON_EVENT(ZoomLevel, IDC_RSPINBUT_SECONDZOOM, 1 /* TextChanged */, OnTextChangedRspinbutSecondzoom, VTS_BSTR VTS_I2)
	ON_EVENT(ZoomLevel, IDC_RSPINBUT_DEFAULTZOOM, 1 /* TextChanged */, OnTextChangedRspinbutDefaultzoom, VTS_BSTR VTS_I2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

BOOL ZoomLevel::OnInitDialog() 
{
	CDialog::OnInitDialog();
	

	CRSpinBut* spinbut;
	int index;

	spinbut=GETDLGITEM(IDC_RSPINBUT_DEFAULTZOOM);
	FillSpin(spinbut);
	index = FindIndex(Save_Data.defaultzoom);
	spinbut->SetIndex(index);

	spinbut=GETDLGITEM(IDC_RSPINBUT_SECONDZOOM);
	FillSpin(spinbut);
	index = FindIndex(Save_Data.secondzoom);
	spinbut->SetIndex(index);

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

int	 ZoomLevel::FindIndex(float zoom)
{
	int retval = 0;
	int i = 0;
	float diff = 100;
	float tdiff;
	while (i <16)
	{
		tdiff = zoomLevel[i] - zoom;
		if (tdiff <0 )
			tdiff = -tdiff;
		if (tdiff < diff)
		{
			diff = tdiff;
			retval = i;
		}
		i++;
	}
//	retval = 0;
	return (retval);
}

void ZoomLevel::FillSpin(CRSpinBut* spinbut)
{
	spinbut->Clear();
	CString string;
	for (int i=0;i<16;i++)
	{
		string = CSprintf("%5.2f",zoomLevel[i]);
		spinbut->AddString(string);
//		spinbut->AddString(CSprintf("%i",i));
	}

}

void ZoomLevel::OnTextChangedRspinbutSecondzoom(LPCTSTR text, short index) 
{
	m_pView->m_zoom =
		Save_Data.secondzoom = 
			zoomLevel[index];	
	RDialog::m_pView->OnZoom();

	
}

void ZoomLevel::OnTextChangedRspinbutDefaultzoom(LPCTSTR text, short index) 
{
	m_pView->m_zoom =
		Save_Data.defaultzoom = 
			zoomLevel[index];	
	RDialog::m_pView->OnZoom();
}
