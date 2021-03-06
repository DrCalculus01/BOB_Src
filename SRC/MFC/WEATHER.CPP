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

// RowanDialog: // Weather.cpp : implementation file
//

#include "stdafx.h"
#include "mig.h"
#include "Weather.h"

#ifdef _DEBUG
//#define new DEBUG_NEW
#ifndef THIS_FILE_DEFINED
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CWeather dialog


//
// This dialog needs to take notice of 
// bool	Node_Data.GotBadWeatherPeriod(bool& alldayreturn,bool& informreturn)
//
//
//
//
//
//

CWeather::CWeather(CWnd* pParent /*=NULL*/)
	: RowanDialog(CWeather::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWeather)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CWeather::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWeather)
	DDX_Control(pDX,IDC_RSTATICCTRL2,m_IDC_RSTATICCTRL2);
	DDX_Control(pDX,IDC_CONDITIONS,m_IDC_CONDITIONS);
	DDX_Control(pDX,IDC_RSTATICCTRL4,m_IDC_RSTATICCTRL4);
	DDX_Control(pDX,IDC_CONTRAIL_BASE,m_IDC_CONTRAIL_BASE);
	DDX_Control(pDX,IDC_VISIBILITY,m_IDC_VISIBILITY);
	DDX_Control(pDX,IDC_CONTRAIL_TOP,m_IDC_CONTRAIL_TOP);
	DDX_Control(pDX,IDC_WINDSPEED0,m_IDC_WINDSPEED0);
	DDX_Control(pDX,IDC_WINDDIRECTION0,m_IDC_WINDDIRECTION0);
	DDX_Control(pDX,IDC_RSTATICCTRL10,m_IDC_RSTATICCTRL10);
	DDX_Control(pDX,IDC_RSTATICCTRL11,m_IDC_RSTATICCTRL11);
	DDX_Control(pDX,IDC_RSTATICCTRL12,m_IDC_RSTATICCTRL12);
	DDX_Control(pDX,IDC_RSTATICCTRL25,m_IDC_RSTATICCTRL25);
	DDX_Control(pDX,IDC_RSTATICCTRL26,m_IDC_RSTATICCTRL26);
	DDX_Control(pDX,IDC_TEMP,m_IDC_TEMP);
	DDX_Control(pDX,IDC_TEMPERATURE,m_IDC_TEMPERATURE);
	DDX_Control(pDX,IDC_RSTATICCTRL24,m_IDC_RSTATICCTRL24);
	DDX_Control(pDX,IDC_PRESSURE,m_IDC_PRESSURE);
	DDX_Control(pDX,IDC_RSTATICCTRL47,m_IDC_RSTATICCTRL47);
	DDX_Control(pDX,IDC_CLOUDLAYER,m_IDC_CLOUDLAYER);
	DDX_Control(pDX,IDC_RSTATICCTRL48,m_IDC_RSTATICCTRL48);
	DDX_Control(pDX,IDC_WINDSPEED1,m_IDC_WINDSPEED1);
	DDX_Control(pDX,IDC_WINDDIRECTION1,m_IDC_WINDDIRECTION1);
	DDX_Control(pDX,IDC_RSTATICCTRL49,m_IDC_RSTATICCTRL49);
	DDX_Control(pDX,IDC_RSTATICCTRL50,m_IDC_RSTATICCTRL50);
	DDX_Control(pDX,IDC_RSTATICCTRL51,m_IDC_RSTATICCTRL51);
	DDX_Control(pDX,IDC_RSTATICCTRL3,m_IDC_RSTATICCTRL3);
	DDX_Control(pDX,IDC_GUSTS,m_IDC_GUSTS);
	DDX_Control(pDX,IDC_RSTATICCTRL7,m_IDC_RSTATICCTRL7);
	DDX_Control(pDX,IDC_SPECIALNOTES,m_IDC_SPECIALNOTES);
	DDX_Control(pDX, IDC_CLOUD_0, m_IDC_CLOUD_0);
	DDX_Control(pDX, IDC_CLOUD_1, m_IDC_CLOUD_1);
	DDX_Control(pDX, IDC_CLOUD_2, m_IDC_CLOUD_2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWeather, CDialog)
	//{{AFX_MSG_MAP(CWeather)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWeather message handlers

BOOL CWeather::OnInitDialog() 
{
	CDialog::OnInitDialog();
//DeadCode JIM 20Oct00 	RDialog* parent=(RDialog*)GetParent();
//	parent->SetMaxSize(CRect(0,0,350,430));
//	parent->SetMinSize(CRect(0,0,150,150));
	if (!Node_Data.GotBadWeatherPeriod())
	{
		CRStatic*   s;
		bool layerpresent = false;
		int index = 0;
		SLong lowalt = 0x7ffffff;
		for (int i =0; i < 3; i++)
		{
			if (MMC.Sky.Layer[i].Cover >= 32)
			{
				layerpresent = true;
				s=GETDLGITEM(IDC_CLOUD_0+index);
				index ++;
				if (MMC.Sky.Layer[i].AltBase < lowalt)
					lowalt = MMC.Sky.Layer[i].AltBase;
				int alt= (MMC.Sky.Layer[i].AltBase*10)/Save_Data.alt.mediummm;
				alt = 100*((alt + 50)/100);

				s->SetString(CSprintf("%i%s (%i/8)", 
						alt,LoadResString(Save_Data.alt.mediumabbr), MMC.Sky.Layer[i].Cover/32));
			}
		}
		if (!layerpresent)
		{
			s=GETDLGITEM(IDC_CLOUD_0);
			s->SetString(RESSTRING(NONE));
			index ++;
		}
		for (index; index < 3; index++)
		{
			s=GETDLGITEM(IDC_CLOUD_0+index);

			s->SetString("");
		}

		

 		s=GETDLGITEM(IDC_CONDITIONS);
		if (layerpresent)
		{
			if ( lowalt < FT_5000)
				s->SetString(RESSTRING(OVERCAST));
			else if ( lowalt < FT_10000)
				s->SetString(RESSTRING(LOWCLOUD));
			else
				s->SetString(RESSTRING(CLOUDY));

		}else
		{
			if (MMC.Sky.FluffyCloud.Cover > 32)
				s->SetString(RESSTRING(PATCHYCLOUD));
			else
				s->SetString(RESSTRING(L_CLEAR));
		}
	//DEADCODE RDH 25/02/00 
	//DEADCODE RDH 25/02/00 	s=GETDLGITEM(IDC_SPECIALNOTES);
	//DEADCODE RDH 25/02/00 	if (MMC.Sky.MistInValley)
	//DEADCODE RDH 25/02/00 		s->SetString(RESSTRING(MISTINVALLEYS));
	//DEADCODE RDH 25/02/00 	else
	//DEADCODE RDH 25/02/00   		s->SetString(RESSTRING(NONE_SPECIALS));



		s=GETDLGITEM(IDC_GUSTS);
		int mag = MMC.Sky.MaxMagnitude;
		if (mag > 2)
			mag = 2;
		s->SetString(RESLIST(LIGHT,mag));

	//DEADCODE RDH 25/02/00 	s=GETDLGITEM(IDC_VISIBILITY);
	//DEADCODE RDH 25/02/00 	int v = 0.5 + MMC.Sky.Visibility/(30.48*6080);
	//DEADCODE RDH 25/02/00 	s->SetString(CSprintf("%i", v));

		s=GETDLGITEM(IDC_TEMPERATURE);
		int t = MMC.Sky.Temp0 - 272.65;
		s->SetString(CSprintf("%i", t));

		s=GETDLGITEM(IDC_PRESSURE);
		int p = (MMC.Sky.Press0 + 0.5);
		s->SetString(CSprintf("%i", p));



	//DEADCODE RDH 25/02/00 	s=GETDLGITEM(IDC_CONTRAIL_BASE);
	//DEADCODE RDH 25/02/00 	t = MMC.Sky.ContrailBandCentre - MMC.Sky.ContrailBandWidth/2;
	//DEADCODE RDH 25/02/00 	t = t/30.48;
	//DEADCODE RDH 25/02/00 	s->SetString(CSprintf("%i", t));
	//DEADCODE RDH 25/02/00 
	//DEADCODE RDH 25/02/00 	s=GETDLGITEM(IDC_CONTRAIL_TOP);
	//DEADCODE RDH 25/02/00 	t = MMC.Sky.ContrailBandCentre + MMC.Sky.ContrailBandWidth/2;
	//DEADCODE RDH 25/02/00 	t = t/30.48;
	//DEADCODE RDH 25/02/00 	s->SetString(CSprintf("%i", t));

		s=GETDLGITEM(IDC_WINDSPEED0);
		t = MMC.Sky.wind0;
		s->SetString(CSprintf("%i", t));

		s=GETDLGITEM(IDC_WINDDIRECTION0);
		t = MMC.Sky.dir0;
		s->SetString(CSprintf("%i", t));

		s=GETDLGITEM(IDC_WINDSPEED1);
		t = MMC.Sky.windalt;
		s->SetString(CSprintf("%i", t));

		s=GETDLGITEM(IDC_WINDDIRECTION1);
		t = MMC.Sky.diralt;
		s->SetString(CSprintf("%i", t));

	}
	else
	{
 
		GETDLGITEM(IDC_CLOUD_0)->SetString(CSprintf("%i%s (%i/8)", 
						1000,LoadResString(Save_Data.alt.mediumabbr), 7));

		for (int index=1; index < 3; index++)
		{
			GETDLGITEM(IDC_CLOUD_0+index)->SetString("");
		}
 		GETDLGITEM(IDC_CONDITIONS)->SetString(RESSTRING(OVERCAST));
		GETDLGITEM(IDC_GUSTS)->SetString(RESLIST(LIGHT,2));
		GETDLGITEM(IDC_TEMPERATURE)->SetString(CSprintf("%i", 10));

		GETDLGITEM(IDC_PRESSURE)->SetString(CSprintf("%i", 970));
		GETDLGITEM(IDC_WINDSPEED0)->SetString(CSprintf("%i", 25));

		GETDLGITEM(IDC_WINDDIRECTION0)->SetString(CSprintf("%i", MMC.Sky.dir0));

		GETDLGITEM(IDC_WINDSPEED1)->SetString(CSprintf("%i", 45));

		GETDLGITEM(IDC_WINDDIRECTION1)->SetString(CSprintf("%i", MMC.Sky.diralt));

	}





//	CRect rect;
//	parent->GetParent()->GetWindowRect(rect);
//	GetClientRect(rect);

//	parent->SetMaxSize(CRect(0,0,rect.Width(),rect.Height()));
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
