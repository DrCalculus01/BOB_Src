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

// RowanDialog: // SFlight.cpp : implementation file
//

#include "stdafx.h"
#include "mig.h"
#include "SFlight.h"
#include "rcombo.h"
#include	"winmove.h"
#include	"comms.h"

#ifdef _DEBUG
//#define new DEBUG_NEW
#ifndef	THIS_FILE_DEFINED
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CSFlight dialog


CSFlight::CSFlight(CWnd* pParent /*=NULL*/)
	: RowanDialog(CSFlight::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSFlight)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSFlight::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSFlight)
	DDX_Control(pDX,IDC_CBO_ALL,m_IDC_CBO_ALL);
	DDX_Control(pDX,IDC_RSTATICCTRL1,m_IDC_RSTATICCTRL1);
	DDX_Control(pDX,IDC_CBO_POWERBOOST,m_IDC_CBO_POWERBOOST);
	DDX_Control(pDX,IDC_RSTATICCTRL3,m_IDC_RSTATICCTRL3);
	DDX_Control(pDX,IDC_CBO_WINDGUSTS,m_IDC_CBO_WINDGUSTS);
	DDX_Control(pDX,IDC_RSTATICCTRL5,m_IDC_RSTATICCTRL5);
	DDX_Control(pDX,IDC_CBO_SPINS,m_IDC_CBO_SPINS);
	DDX_Control(pDX,IDC_RSTATICCTRL6,m_IDC_RSTATICCTRL6);
	DDX_Control(pDX,IDC_CBO_AIRFRAME,m_IDC_CBO_AIRFRAME);
	DDX_Control(pDX,IDC_RSTATICCTRL7,m_IDC_RSTATICCTRL7);
	DDX_Control(pDX,IDC_CBO_TORQUE,m_IDC_CBO_TORQUE);
	DDX_Control(pDX,IDC_RSTATICCTRL9,m_IDC_RSTATICCTRL9);
	DDX_Control(pDX,IDC_CBO_109FUEL,m_IDC_CBO_109FUEL);
	DDX_Control(pDX,IDC_RSTATICCTRL10,m_IDC_RSTATICCTRL10);
	DDX_Control(pDX,IDC_CBO_WIND0,m_IDC_CBO_WIND0);
	DDX_Control(pDX,IDC_RSTATICCTRL52,m_IDC_RSTATICCTRL52);
	DDX_Control(pDX, IDC_CBO_ENGINEMANAGEMENT, m_IDC_CBO_ENGINEMANAGEMENT);
	DDX_Control(pDX, IDC_CBO_PROPPITCH, m_IDC_CBO_PROPPITCH);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSFlight, CDialog)
	//{{AFX_MSG_MAP(CSFlight)
	ON_WM_DESTROY()
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSFlight message handlers
//	SETFIELD(BIT(flightdifficulty,FD_COORDINATEDRUDDER),IDC_CBO_RUDDER,RESCOMBO(YESNO_NO,2),		LEVELS(0,0,1,1,1))	

#define OPTIONS	\
	SETFIELD(MASTER1,							IDC_CBO_ALL,RESCOMBO(BLMHT_BOT,6),			PRESETLEVEL(5))	\
	SETFIELD(BIT(flightdifficulty,FD_SPINS),			IDC_CBO_SPINS,RESCOMBO(EASY,2),			LEVELS(0,1,1,1,1))	\
	SETFIELD(BIT(flightdifficulty,FD_POWERBOOST),		IDC_CBO_POWERBOOST,RESCOMBO(OFF,2),		LEVELS(1,1,0,0,0))	\
	SETFIELD(BIT(flightdifficulty,FD_WINDEFFECTS),		IDC_CBO_WIND0,RESCOMBO(OFF,2),			LEVELS(0,0,1,1,1))	\
	SETFIELD(BIT(flightdifficulty,FD_WINDGUSTS),		IDC_CBO_WINDGUSTS,RESCOMBO(OFF,2),		LEVELS(0,0,0,1,1))	\
	SETFIELD(BIT(flightdifficulty,FD_SLIPSTREAMEFFECTS),IDC_CBO_TORQUE,RESCOMBO(OFF,2),			LEVELS(0,0,0,1,1))	\
	SETFIELD(BIT(flightdifficulty,FD_PROPPITCH),IDC_CBO_PROPPITCH,RESCOMBO(AUTO,2),				LEVELS(0,0,0,1,1))	\
	SETFIELD(BIT(flightdifficulty,FD_EXCESSIVEACCELDAMAGE),IDC_CBO_AIRFRAME,RESCOMBO(OFF,2),	LEVELS(0,0,0,0,1))	\
	SETFIELD(BIT(flightdifficulty,FD_ENGINEMANAGMENT),IDC_CBO_ENGINEMANAGEMENT,RESCOMBO(AUTO,2),LEVELS(0,0,0,0,1))	\
	SETFIELD(BIT(flightdifficulty,FD_109FUEL),IDC_CBO_109FUEL,RESCOMBO(109FUELCAPLOW,2),			LEVELS(0,0,0,0,0))	\
	SETFIELD(MASTER2,							IDC_CBO_ALL,GetIndex(),						POSTSETLEVEL(5))	\
	


BOOL CSFlight::OnInitDialog() 
{
	CDialog::OnInitDialog();

	if (_DPlay.PlayerCreated)
	{
//DeadCode AMM 16Nov99 		_DPlay.UISendInPrefsMessage();
//DeadCode AMM 16Nov99 		DPlay::H2H_Player[_DPlay.mySlot].status=CPS_PREFS;
		_DPlay.SendStatusChange(DPlay::CPS_PREFS);
	}

	FlightPref_Timer=SetTimer(DPlay::TIMER_PREFSFLIGHT,0,NULL);

#define	SG2C_DISPLAY setlevel
#include "sg2combo.h"
	OPTIONS	
//DEADCODE RDH 24/11/99 	m_IDC_CBO_ALL.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_POWERBOOST.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_WINDGUSTS.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_SPINS.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_AIRFRAME.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_TORQUE.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_109FUEL.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 	m_IDC_CBO_WIND0.SetCircularStyle(TRUE);
//DEADCODE RDH 24/11/99 

	CRCombo* combo;
 	if(Save_Data.flightdifficulty[FD_SPINS] && !_DPlay.PlayerCreated)
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(true);

		if(Save_Data.flightdifficulty[FD_ENGINEMANAGMENT])
		{
			combo=GETDLGITEM(IDC_CBO_PROPPITCH);
			combo->SetEnabled(false);
		}
	}
	else
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(false);

		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
		combo->SetEnabled(false);
	}






	if	(		(RFullPanelDial::incomms)
			&&	(_DPlay.UIPlayerType==DPlay::PLAYER_GUEST)
		)
	{
		combo=GETDLGITEM(IDC_CBO_ALL);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_POWERBOOST);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_WINDGUSTS);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_SPINS);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_AIRFRAME);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_TORQUE);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_109FUEL);
		combo->SetEnabled(false);
		combo=GETDLGITEM(IDC_CBO_WIND0);
		combo->SetEnabled(false);
	}else
	{
		combo=GETDLGITEM(IDC_CBO_ALL);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_POWERBOOST);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_WINDGUSTS);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_SPINS);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_AIRFRAME);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_TORQUE);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_109FUEL);
		combo->SetEnabled(true);
		combo=GETDLGITEM(IDC_CBO_WIND0);
		combo->SetEnabled(true);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CSFlight::OnDestroy() 
{
	KillTimer(FlightPref_Timer);

//#define	SG2C_WRITEBACK
//#include "sg2combo.h"
//	OPTIONS
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
}

void CSFlight::PreDestroyPanel()
{
#define	SG2C_WRITEBACK
#include "sg2combo.h"
	OPTIONS
}


BEGIN_EVENTSINK_MAP(CSFlight, CDialog)
    //{{AFX_EVENTSINK_MAP(CSFlight)
	ON_EVENT(CSFlight, IDC_CBO_ALL, 1 /* TextChanged */, OnTextChangedCboAll, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_AIRFRAME, 1 /* TextChanged */, OnTextChangedCboAirframe, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_109FUEL, 1 /* TextChanged */, OnTextChangedCbo109Fuel, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_POWERBOOST, 1 /* TextChanged */, OnTextChangedCboPowerboost, VTS_BSTR VTS_I2)
//DEADCODE JIM 30/11/99 	ON_EVENT(CSFlight, IDC_CBO_RUDDER, 1 /* TextChanged */, OnTextChangedCboRudder, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_SPINS, 1 /* TextChanged */, OnTextChangedCboSpins, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_TORQUE, 1 /* TextChanged */, OnTextChangedCboTorque, VTS_BSTR VTS_I2)
//DEADCODE JIM 30/11/99 	ON_EVENT(CSFlight, IDC_CBO_WIND, 1 /* TextChanged */, OnTextChangedCboWind, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_WIND0, 1 /* TextChanged */, OnTextChangedCboWind0, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_PROPPITCH, 1 /* TextChanged */, OnTextChangedCboProppitch, VTS_BSTR VTS_I2)
	ON_EVENT(CSFlight, IDC_CBO_ENGINEMANAGEMENT, 1 /* TextChanged */, OnTextChangedCboEnginemanagement, VTS_BSTR VTS_I2)
	//}}AFX_EVENTSINK_MAP
END_EVENTSINK_MAP()

void CSFlight::OnTextChangedCboAll(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
#define	SG2C_CHANGELEVEL   tmp
#include "sg2combo.h"
	OPTIONS

		CRCombo* combo;

	if (GETDLGITEM(IDC_CBO_SPINS)->GetIndex() == 1)
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(true);

		if (GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT)->GetIndex() == 0)
		{
			combo=GETDLGITEM(IDC_CBO_PROPPITCH);
			combo->SetEnabled(true);
		}else
		{
			combo=GETDLGITEM(IDC_CBO_PROPPITCH);
			combo->SetEnabled(false);
			Save_Data.flightdifficulty %= FD_PROPPITCH;
		}
	}else
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(false);
		Save_Data.flightdifficulty %= FD_ENGINEMANAGMENT;

		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
		combo->SetEnabled(false);
		Save_Data.flightdifficulty %= FD_PROPPITCH;
	}
}


#define	SG2C_CHANGEFIELD
#include "sg2combo.h"

void CSFlight::OnTextChangedCboAirframe(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
//DEADCODE RDH 24/11/99 #define	SG2C_CHANGEFIELD
//DEADCODE RDH 24/11/99 #include "sg2combo.h"
	OPTIONS
	
}

void CSFlight::OnTextChangedCbo109Fuel(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	
}


void CSFlight::OnTextChangedCboPowerboost(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	
}

void CSFlight::OnTextChangedCboRudder(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	
}

void CSFlight::OnTextChangedCboSpins(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	CRCombo* combo;

	if (index == 1)
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(true);

		if (GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT)->GetIndex() == 0)
		{
			combo=GETDLGITEM(IDC_CBO_PROPPITCH);
			combo->SetEnabled(true);
		}else
		{
			combo=GETDLGITEM(IDC_CBO_PROPPITCH);
			combo->SetEnabled(false);
			Save_Data.flightdifficulty |= FD_PROPPITCH;
		}
//DEADCODE CSB 13/01/00 		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
//DEADCODE CSB 13/01/00 		combo->SetEnabled(true);
	}else
	{
		combo=GETDLGITEM(IDC_CBO_ENGINEMANAGEMENT);
		combo->SetEnabled(false);
		Save_Data.flightdifficulty |= FD_ENGINEMANAGMENT;

		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
		combo->SetEnabled(false);
		Save_Data.flightdifficulty %= FD_PROPPITCH;
	}
	
}


void CSFlight::OnTextChangedCboTorque(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	
}

void CSFlight::OnTextChangedCboWind(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS
	
}
void CSFlight::OnTextChangedCboWind0(LPCTSTR text, short index) 
{
	// TODO: Add your control notification handler code here
	OPTIONS

}


void CSFlight::OnTimer(UINT nIDEvent) 
{
	if (nIDEvent==FlightPref_Timer && _DPlay.PlayerCreated)
	{
		_DPlay.UIUpdateMainSheet();
	}

	CDialog::OnTimer(nIDEvent);
}



void CSFlight::OnTextChangedCboProppitch(LPCTSTR text, short index) 
{
	OPTIONS
	
}

void CSFlight::OnTextChangedCboEnginemanagement(LPCTSTR text, short index) 
{
	OPTIONS
	CRCombo* combo;

	if (index == 0)
	{
		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
		combo->SetEnabled(true);
	}else
	{
		combo=GETDLGITEM(IDC_CBO_PROPPITCH);
		combo->SetEnabled(false);
		Save_Data.flightdifficulty |= FD_PROPPITCH;
	}
}
#define SG2C_CLEANUP
#include "sg2combo.h"
