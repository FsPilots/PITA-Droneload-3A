#include "MainFrame.h"
#include <stdio.h>

#include "Radio.h"
#include "Camera.h"
#include "Pilote.h"

extern C_Radio MyRadio ;
extern C_Camera MyFrontCamera  ;
extern C_Camera MyBottomCamera  ;
extern C_Pilote MyPilot ;

void * PilotTakeOFF(void *threadid)
{
   MyPilot.Takeoff();
   pthread_exit(NULL);
   return NULL ;
} ;


//(*InternalHeaders(MainFrame)
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(MainFrame)
const long MainFrame::ID_BUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON3 = wxNewId();
const long MainFrame::ID_BUTTON2 = wxNewId();
const long MainFrame::ID_STATICTEXT1 = wxNewId();
const long MainFrame::ID_SLIDER1 = wxNewId();
const long MainFrame::ID_STATICTEXT10 = wxNewId();
const long MainFrame::ID_BUTTON4 = wxNewId();
const long MainFrame::ID_BUTTON5 = wxNewId();
const long MainFrame::ID_STATICTEXT6 = wxNewId();
const long MainFrame::ID_STATICTEXT2 = wxNewId();
const long MainFrame::ID_SLIDER2 = wxNewId();
const long MainFrame::ID_STATICTEXT11 = wxNewId();
const long MainFrame::ID_BUTTON6 = wxNewId();
const long MainFrame::ID_BUTTON7 = wxNewId();
const long MainFrame::ID_STATICTEXT7 = wxNewId();
const long MainFrame::ID_STATICTEXT3 = wxNewId();
const long MainFrame::ID_SLIDER3 = wxNewId();
const long MainFrame::ID_STATICTEXT12 = wxNewId();
const long MainFrame::ID_BUTTON8 = wxNewId();
const long MainFrame::ID_BUTTON9 = wxNewId();
const long MainFrame::ID_STATICTEXT8 = wxNewId();
const long MainFrame::ID_STATICTEXT4 = wxNewId();
const long MainFrame::ID_SLIDER4 = wxNewId();
const long MainFrame::ID_STATICTEXT13 = wxNewId();
const long MainFrame::ID_BUTTON10 = wxNewId();
const long MainFrame::ID_BUTTON11 = wxNewId();
const long MainFrame::ID_STATICTEXT9 = wxNewId();
const long MainFrame::ID_BUTTON14 = wxNewId();
const long MainFrame::ID_BUTTON16 = wxNewId();
const long MainFrame::ID_BUTTON18 = wxNewId();
const long MainFrame::ID_BUTTON17 = wxNewId();
const long MainFrame::ID_BUTTON15 = wxNewId();
const long MainFrame::ID_TEXTCTRL1 = wxNewId();
const long MainFrame::ID_BUTTON13 = wxNewId();
const long MainFrame::ID_STATICTEXT5 = wxNewId();
const long MainFrame::ID_STATICTEXT19 = wxNewId();
const long MainFrame::ID_STATICTEXT14 = wxNewId();
const long MainFrame::ID_STATICTEXT15 = wxNewId();
const long MainFrame::ID_STATICTEXT16 = wxNewId();
const long MainFrame::ID_STATICTEXT17 = wxNewId();
const long MainFrame::ID_STATICTEXT18 = wxNewId();
const long MainFrame::ID_BUTTON20 = wxNewId();
const long MainFrame::ID_STATICTEXT20 = wxNewId();
const long MainFrame::ID_STATICTEXT23 = wxNewId();
const long MainFrame::ID_STATICTEXT24 = wxNewId();
const long MainFrame::ID_STATICTEXT25 = wxNewId();
const long MainFrame::ID_STATICTEXT26 = wxNewId();
const long MainFrame::ID_SLIDER5 = wxNewId();
const long MainFrame::ID_BITMAPBUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON21 = wxNewId();
const long MainFrame::ID_BUTTON22 = wxNewId();
const long MainFrame::ID_STATICTEXT22 = wxNewId();
const long MainFrame::ID_BUTTON12 = wxNewId();
const long MainFrame::ID_BUTTON19 = wxNewId();
const long MainFrame::ID_STATICTEXT21 = wxNewId();
const long MainFrame::ID_PANEL1 = wxNewId();
const long MainFrame::ID_PANEL2 = wxNewId();
//*)

const long MainFrame::ID_IMAGEPANEL1 = wxNewId();
const long MainFrame::ID_IMAGEPANEL2 = wxNewId();



BEGIN_EVENT_TABLE(MainFrame,wxFrame)
	//(*EventTable(MainFrame)
	//*)
END_EVENT_TABLE()

MainFrame::MainFrame(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(MainFrame)
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer13;
	wxBoxSizer* BoxSizer14;
	wxBoxSizer* BoxSizer15;
	wxBoxSizer* BoxSizer16;
	wxBoxSizer* BoxSizer17;
	wxBoxSizer* BoxSizer18;
	wxBoxSizer* BoxSizer19;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer20;
	wxBoxSizer* BoxSizer21;
	wxBoxSizer* BoxSizer22;
	wxBoxSizer* BoxSizer23;
	wxBoxSizer* BoxSizer24;
	wxBoxSizer* BoxSizer25;
	wxBoxSizer* BoxSizer26;
	wxBoxSizer* BoxSizer27;
	wxBoxSizer* BoxSizer28;
	wxBoxSizer* BoxSizer29;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer30;
	wxBoxSizer* BoxSizer31;
	wxBoxSizer* BoxSizer32;
	wxBoxSizer* BoxSizer33;
	wxBoxSizer* BoxSizer34;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;
	wxFlexGridSizer* FlexGridSizer1;
	wxStaticBoxSizer* StaticBoxSizer1;
	wxStaticBoxSizer* StaticBoxSizer2;
	wxStaticBoxSizer* StaticBoxSizer3;
	wxStaticBoxSizer* StaticBoxSizer4;
	wxStaticBoxSizer* StaticBoxSizer5;
	wxStaticBoxSizer* StaticBoxSizer6;

	Create(parent, wxID_ANY, _("Projet ESTACA"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	Move(wxPoint(-1,-1));
	SetForegroundColour(wxColour(0,0,255));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Quit"), wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer23 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Controle PC"));
	BoxSizer31 = new wxBoxSizer(wxVERTICAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	Button3 = new wxButton(this, ID_BUTTON3, _("NORM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer9->Add(Button3, 0, wxALL|wxEXPAND, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer9->Add(Button2, 0, wxALL|wxEXPAND, 5);
	BoxSizer31->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Controles élémentaires"));
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Throttle"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(0,0,255));
	BoxSizer5->Add(StaticText1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER1"));
	Slider1->SetThumbLength(45);
	Slider1->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	BoxSizer10->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT10"));
	StaticText10->SetForegroundColour(wxColour(0,255,0));
	StaticText10->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer10->Add(StaticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer18 = new wxBoxSizer(wxVERTICAL);
	BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	Button4 = new wxButton(this, ID_BUTTON4, _("-"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON4"));
	BoxSizer17->Add(Button4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button5 = new wxButton(this, ID_BUTTON5, _("+"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON5"));
	BoxSizer17->Add(Button5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer18->Add(BoxSizer17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Trim"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT6"));
	StaticText6->SetForegroundColour(wxColour(0,255,0));
	StaticText6->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer18->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer10->Add(BoxSizer18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Yaw"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxColour(0,0,255));
	BoxSizer6->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12 = new wxBoxSizer(wxVERTICAL);
	Slider2 = new wxSlider(this, ID_SLIDER2, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER2"));
	Slider2->SetThumbLength(45);
	Slider2->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	BoxSizer12->Add(Slider2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT11"));
	StaticText11->SetForegroundColour(wxColour(0,255,0));
	StaticText11->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer12->Add(StaticText11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer19 = new wxBoxSizer(wxVERTICAL);
	BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	Button6 = new wxButton(this, ID_BUTTON6, _("-"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON6"));
	BoxSizer20->Add(Button6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button7 = new wxButton(this, ID_BUTTON7, _("+"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON7"));
	BoxSizer20->Add(Button7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer19->Add(BoxSizer20, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Trim"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT7"));
	StaticText7->SetForegroundColour(wxColour(0,255,0));
	StaticText7->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer19->Add(StaticText7, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer12->Add(BoxSizer19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Pitch"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->SetForegroundColour(wxColour(0,0,255));
	BoxSizer7->Add(StaticText3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14 = new wxBoxSizer(wxVERTICAL);
	Slider3 = new wxSlider(this, ID_SLIDER3, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER3"));
	Slider3->SetThumbLength(45);
	Slider3->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	BoxSizer14->Add(Slider3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Label"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT12"));
	StaticText12->SetForegroundColour(wxColour(0,255,0));
	StaticText12->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer14->Add(StaticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21 = new wxBoxSizer(wxVERTICAL);
	BoxSizer24 = new wxBoxSizer(wxHORIZONTAL);
	Button8 = new wxButton(this, ID_BUTTON8, _("-"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON8"));
	BoxSizer24->Add(Button8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button9 = new wxButton(this, ID_BUTTON9, _("+"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON9"));
	BoxSizer24->Add(Button9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21->Add(BoxSizer24, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("Trim"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT8"));
	StaticText8->SetForegroundColour(wxColour(0,255,0));
	StaticText8->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer21->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer14->Add(BoxSizer21, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer7, 0, wxALL, 5);
	BoxSizer29 = new wxBoxSizer(wxVERTICAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Roll"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->SetForegroundColour(wxColour(0,0,255));
	BoxSizer29->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16 = new wxBoxSizer(wxVERTICAL);
	Slider4 = new wxSlider(this, ID_SLIDER4, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER4"));
	Slider4->SetThumbLength(45);
	Slider4->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_ACTIVECAPTION));
	BoxSizer16->Add(Slider4, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Label"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT13"));
	StaticText13->SetForegroundColour(wxColour(0,255,0));
	StaticText13->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer16->Add(StaticText13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer22 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	Button10 = new wxButton(this, ID_BUTTON10, _("-"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON10"));
	FlexGridSizer1->Add(Button10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button11 = new wxButton(this, ID_BUTTON11, _("+"), wxDefaultPosition, wxSize(20,25), 0, wxDefaultValidator, _T("ID_BUTTON11"));
	FlexGridSizer1->Add(Button11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer22->Add(FlexGridSizer1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Trim"), wxDefaultPosition, wxSize(30,-1), wxALIGN_CENTRE|wxBORDER_SUNKEN, _T("ID_STATICTEXT9"));
	StaticText9->SetForegroundColour(wxColour(0,255,0));
	StaticText9->SetBackgroundColour(wxColour(0,0,0));
	BoxSizer22->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 1);
	BoxSizer16->Add(BoxSizer22, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer29->Add(BoxSizer16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer29, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer3->Add(BoxSizer8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 20);
	BoxSizer31->Add(StaticBoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer26 = new wxBoxSizer(wxHORIZONTAL);
	Button14 = new wxButton(this, ID_BUTTON14, _("Take Off"), wxDefaultPosition, wxSize(70,70), 0, wxDefaultValidator, _T("ID_BUTTON14"));
	BoxSizer26->Add(Button14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button16 = new wxButton(this, ID_BUTTON16, _("Auto\nThrottle"), wxDefaultPosition, wxSize(70,70), 0, wxDefaultValidator, _T("ID_BUTTON16"));
	BoxSizer26->Add(Button16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button18 = new wxButton(this, ID_BUTTON18, _("Gate"), wxDefaultPosition, wxSize(70,70), 0, wxDefaultValidator, _T("ID_BUTTON18"));
	BoxSizer26->Add(Button18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button17 = new wxButton(this, ID_BUTTON17, _("Read QR"), wxDefaultPosition, wxSize(70,70), 0, wxDefaultValidator, _T("ID_BUTTON17"));
	BoxSizer26->Add(Button17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button15 = new wxButton(this, ID_BUTTON15, _("Landing"), wxDefaultPosition, wxSize(70,70), 0, wxDefaultValidator, _T("ID_BUTTON15"));
	BoxSizer26->Add(Button15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer31->Add(BoxSizer26, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer25 = new wxBoxSizer(wxVERTICAL);
	BoxSizer25->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer25->Add(-1,-1,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer4->Add(BoxSizer25, 0, wxALL|wxEXPAND, 5);
	BoxSizer23->Add(StaticBoxSizer4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer30 = new wxBoxSizer(wxVERTICAL);
	StaticBoxSizer1 = new wxStaticBoxSizer(wxVERTICAL, this, _("Radio"));
	BoxSizer27 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("COM11"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer27->Add(TextCtrl1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button13 = new wxButton(this, ID_BUTTON13, _("Connect"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON13"));
	BoxSizer27->Add(Button13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Unconnected"), wxDefaultPosition, wxSize(100,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT5"));
	StaticText5->SetForegroundColour(wxColour(255,0,0));
	BoxSizer27->Add(StaticText5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText19 = new wxStaticText(this, ID_STATICTEXT19, _("Controle par PC"), wxDefaultPosition, wxSize(250,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT19"));
	StaticBoxSizer1->Add(StaticText19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer28 = new wxBoxSizer(wxHORIZONTAL);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("0"), wxDefaultPosition, wxSize(50,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT14"));
	BoxSizer28->Add(StaticText14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("0"), wxDefaultPosition, wxSize(50,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT15"));
	BoxSizer28->Add(StaticText15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("0"), wxDefaultPosition, wxSize(50,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT16"));
	BoxSizer28->Add(StaticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("0"), wxDefaultPosition, wxSize(50,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT17"));
	BoxSizer28->Add(StaticText17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(this, ID_STATICTEXT18, _("0"), wxDefaultPosition, wxSize(50,-1), wxALIGN_CENTRE|wxBORDER_SIMPLE, _T("ID_STATICTEXT18"));
	BoxSizer28->Add(StaticText18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer28, 1, wxALL|wxEXPAND, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	Button20 = new wxButton(this, ID_BUTTON20, _("Start log"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON20"));
	BoxSizer11->Add(Button20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(this, ID_STATICTEXT20, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT20"));
	BoxSizer11->Add(StaticText20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer1->Add(BoxSizer11, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer30->Add(StaticBoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6 = new wxStaticBoxSizer(wxVERTICAL, this, _("Drone Data"));
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	StaticText23 = new wxStaticText(this, ID_STATICTEXT23, _("Atitude estimée :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT23"));
	BoxSizer15->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(this, ID_STATICTEXT24, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT24"));
	BoxSizer15->Add(StaticText24, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticBoxSizer6->Add(BoxSizer15, 0, wxALL|wxEXPAND, 5);
	BoxSizer32 = new wxBoxSizer(wxVERTICAL);
	BoxSizer33 = new wxBoxSizer(wxHORIZONTAL);
	StaticText25 = new wxStaticText(this, ID_STATICTEXT25, _("Altitude de consigne :"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT25"));
	BoxSizer33->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(this, ID_STATICTEXT26, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT26"));
	BoxSizer33->Add(StaticText26, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer32->Add(BoxSizer33, 1, wxALL|wxEXPAND, 0);
	Slider5 = new wxSlider(this, ID_SLIDER5, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER5"));
	BoxSizer32->Add(Slider5, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer6->Add(BoxSizer32, 0, wxALL|wxEXPAND, 5);
	BoxSizer30->Add(StaticBoxSizer6, 0, wxALL|wxEXPAND, 5);
	BoxSizer34 = new wxBoxSizer(wxHORIZONTAL);
	BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("Capture.PNG"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|wxBORDER_NONE, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BoxSizer34->Add(BitmapButton1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer30->Add(BoxSizer34, 1, wxALL|wxEXPAND, 5);
	StaticBoxSizer5 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Bottom image "));
	Button21 = new wxButton(this, ID_BUTTON21, _("Hide image"), wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_BUTTON21"));
	StaticBoxSizer5->Add(Button21, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button22 = new wxButton(this, ID_BUTTON22, _("Record"), wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_BUTTON22"));
	StaticBoxSizer5->Add(Button22, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(this, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT22"));
	StaticBoxSizer5->Add(StaticText22, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer30->Add(StaticBoxSizer5, 0, wxALL|wxEXPAND, 5);
	StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Front Image"));
	Button12 = new wxButton(this, ID_BUTTON12, _("Hide image"), wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_BUTTON12"));
	StaticBoxSizer2->Add(Button12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Button19 = new wxButton(this, ID_BUTTON19, _("Record"), wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_BUTTON19"));
	StaticBoxSizer2->Add(Button19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText21 = new wxStaticText(this, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT21"));
	StaticBoxSizer2->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer30->Add(StaticBoxSizer2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3->Add(BoxSizer30, 0, wxALL|wxEXPAND, 0);
	BoxSizer13 = new wxBoxSizer(wxVERTICAL);
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer13->Add(Panel1, 1, wxALL|wxEXPAND, 5);
	Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
	BoxSizer13->Add(Panel2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3->Add(BoxSizer13, 1, wxALL|wxEXPAND, 0);
	BoxSizer1->Add(BoxSizer3, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton1Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton3Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton2Click);
	Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&MainFrame::OnSliderCmdScrollChanged);
	Connect(ID_SLIDER1,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MainFrame::OnSlider1CmdScroll);
	Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton4Click);
	Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton5Click);
	Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&MainFrame::OnSliderCmdScrollChanged);
	Connect(ID_SLIDER2,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MainFrame::OnSlider2CmdScroll);
	Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton6Click);
	Connect(ID_BUTTON7,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton7Click);
	Connect(ID_SLIDER3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&MainFrame::OnSliderCmdScrollChanged);
	Connect(ID_SLIDER3,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MainFrame::OnSlider3CmdScroll);
	Connect(ID_BUTTON8,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton8Click);
	Connect(ID_BUTTON9,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton9Click);
	Connect(ID_SLIDER4,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&MainFrame::OnSliderCmdScrollChanged);
	Connect(ID_SLIDER4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MainFrame::OnSlider4CmdScroll);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton10Click);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton11Click);
	Connect(ID_BUTTON14,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton14Click);
	Connect(ID_BUTTON16,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton16Click);
	Connect(ID_BUTTON18,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton18Click);
	Connect(ID_BUTTON17,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton17Click);
	Connect(ID_BUTTON15,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton15Click);
	Connect(ID_BUTTON13,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton13Click);
	Connect(ID_BUTTON20,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton20Click);
	Connect(ID_BUTTON21,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton21Click);
	Connect(ID_BUTTON22,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton22Click);
	Connect(ID_BUTTON12,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton12Click);
	Connect(ID_BUTTON19,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton19Click);
	//*)

	 m_imagepanelfront = new wxImagePanel ( Panel1, ID_IMAGEPANEL1, wxDefaultPosition, Panel1->GetClientSize(), wxBORDER_SUNKEN | wxTAB_TRAVERSAL, _T ( "ID_IMAGEPANEL1" ) );
     m_imagepanelbottom = new wxImagePanel ( Panel2, ID_IMAGEPANEL2, wxDefaultPosition, Panel2->GetClientSize(), wxBORDER_SUNKEN | wxTAB_TRAVERSAL, _T ( "ID_IMAGEPANEL2" ) );

    MyFrontCamera.SetRenderPanel ( m_imagepanelfront ) ;
    MyBottomCamera.SetRenderPanel ( m_imagepanelbottom ) ;
    Update() ;

    // Slider1->SetBackgroundColour(wxColour(146,216,158));
}

MainFrame::~MainFrame()
{
	//(*Destroy(MainFrame)
	//*)
	MyRadio.Close();
}

void MainFrame::UpdateIHM()
{
    TextCtrl1->SetValue( MyRadio.GetNomPort() );
}

void MainFrame::SpecialUpdateIHM()
{
    char tmp_str[10] ;
//    TextCtrl1->SetValue( MyRadio.GetNomPort() );

    if ( MyRadio.IsOpen() )
    {
        StaticText5->SetForegroundColour(wxColour(0,255,0));
        StaticText5->SetLabel("Connected") ;
    }
    else
    {
        StaticText5->SetForegroundColour(wxColour(255,0,0));
        StaticText5->SetLabel("Unconnected") ;
    }
    StaticText5->SetWindowStyle(wxALL|wxALIGN_CENTRE);

    if ( MyRadio.GetReceivedMode() == 0 )
    {
        StaticText19->SetLabel( "Control par PC") ;
        Slider1->Enable();
        Slider2->Enable();
        Slider3->Enable();
        Slider4->Enable();
    }
    else
    {
        StaticText19->SetLabel( "Control par Télécommande") ;
        Slider1->Disable(); MyRadio.SetLevelT( MyRadio.GetReceivedLevelT() ) ;
        Slider2->Disable(); MyRadio.SetLevelR( MyRadio.GetReceivedLevelR() ) ;
        Slider3->Disable(); MyRadio.SetLevelE( MyRadio.GetReceivedLevelE() ) ;
        Slider4->Disable(); MyRadio.SetLevelA( MyRadio.GetReceivedLevelA() ) ;
    }
    Slider1->SetValue( MyRadio.GetLevelT() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelT()) ; StaticText10->SetLabel( tmp_str ) ;
    Slider2->SetValue( MyRadio.GetLevelR() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelR()) ; StaticText11->SetLabel( tmp_str ) ;
    Slider3->SetValue( MyRadio.GetLevelE() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelE()) ; StaticText12->SetLabel( tmp_str ) ;
    Slider4->SetValue( MyRadio.GetLevelA() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelA()) ; StaticText13->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetTrimT()); StaticText6->SetLabel( tmp_str ) ;
    sprintf(tmp_str,"%d",MyRadio.GetTrimR()); StaticText7->SetLabel( tmp_str ) ;
    sprintf(tmp_str,"%d",MyRadio.GetTrimE()); StaticText8->SetLabel( tmp_str ) ;
    sprintf(tmp_str,"%d",MyRadio.GetTrimA()); StaticText9->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetReceivedMode());  StaticText14->SetLabel( tmp_str );
    sprintf(tmp_str,"%d",MyRadio.GetReceivedLevelT());  StaticText15->SetLabel( tmp_str );
    sprintf(tmp_str,"%d",MyRadio.GetReceivedLevelR());  StaticText16->SetLabel( tmp_str );
    sprintf(tmp_str,"%d",MyRadio.GetReceivedLevelE());  StaticText17->SetLabel( tmp_str );
    sprintf(tmp_str,"%d",MyRadio.GetReceivedLevelA());  StaticText18->SetLabel( tmp_str );

    if ( MyFrontCamera.IsRecording() )
    {
        Button19->SetLabel("Stop Record");
        StaticText21->SetLabel("Rec is pending ...");
    }
    else
    {
        Button19->SetLabel("Start Record");
        StaticText21->SetLabel("");
    }

    if ( MyFrontCamera.IsShowing() )
    {
        Button12->SetLabel("Hide image");
    }
    else
    {
        Button12->SetLabel("Show image");
    }

    if ( MyBottomCamera.IsRecording() )
    {
        Button22->SetLabel("Stop Record");
        StaticText22->SetLabel("Rec is pending ...");
    }
    else
    {
        Button22->SetLabel("Start Record");
        StaticText22->SetLabel("");
    }

    if ( MyBottomCamera.IsShowing() )
    {
        Button21->SetLabel("Hide image");
    }
    else
    {
       Button21->SetLabel("Show image");
    }


    if ( MyPilot.GetState() == TAKINGOFF )
    {
        Button14->SetBackgroundColour( wxColour(146,216,158) ) ;
    }

    else
    {
        Button14->SetBackgroundColour( wxSystemSettings::GetColour(wxSYS_COLOUR_MENU) ) ;
    }





    if ( MyPilot.GetState() == STABILIZED )
    {
        Button16->SetBackgroundColour( wxColour(146,216,158) ) ;
    }
    else
    {
        Button16->SetBackgroundColour( wxSystemSettings::GetColour(wxSYS_COLOUR_MENU) ) ;
    }




    if ( MyPilot.GetState() == LANDING )
    {
        Button15->SetBackgroundColour( wxColour(146,216,158) ) ;



    }
    else
    {
        Button15->SetBackgroundColour( wxSystemSettings::GetColour(wxSYS_COLOUR_MENU) ) ;
    }




    if (MyBottomCamera.GetCameraActivity()== READINGQR)
    {
        Button17->SetBackgroundColour( wxColour(146,216,158) ) ;
    }
     else
    {
        Button17->SetBackgroundColour( wxSystemSettings::GetColour(wxSYS_COLOUR_MENU) ) ;
    }


    if (MyPilot.GetActivity()== PASSGATE)
    {
        Button18->SetBackgroundColour( wxColour(146,216,158) ) ;
        MyPilot.PassGate();
    }
     else
    {
        Button18->SetBackgroundColour( wxSystemSettings::GetColour(wxSYS_COLOUR_MENU) ) ;
    }

    //mise a jour du slider pour l'altitude de consigne
    int Slider5_value = Slider5->GetValue();
    MyPilot.SetAltitudeConsigne(Slider5_value);
    sprintf(tmp_str,"%d",MyPilot.GetAltutudeConsigne()); StaticText26->SetLabel( tmp_str ) ;
    sprintf(tmp_str,"%d",MyBottomCamera.GetAltitude()); StaticText24->SetLabel( tmp_str ) ;

}

void MainFrame::OnButton1Click(wxCommandEvent& event)
{
    Close() ;
}

void MainFrame::OnSlider1CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelT( Slider1->GetValue() );
}

void MainFrame::OnSlider2CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelR( Slider2->GetValue() );
}

void MainFrame::OnSlider3CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelE( Slider3->GetValue() );
}

void MainFrame::OnSlider4CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelA( Slider4->GetValue() );
}

void MainFrame::OnButton2Click(wxCommandEvent& event)
{
    MyRadio.Reset();
}

void MainFrame::OnButton3Click(wxCommandEvent& event)
{
    if ( strcmp("NORM", Button3->GetLabel().c_str().AsChar())==0 )
    {
        Button3->SetLabel("STAB");
        MyRadio.SetMode(STAB);
        MyRadio.ReCenter();
        char tmp_str[10] ;
        Slider1->SetValue( MyRadio.GetLevelT() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelT()) ; StaticText10->SetLabel( tmp_str ) ;
        Slider2->SetValue( MyRadio.GetLevelR() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelR()) ; StaticText11->SetLabel( tmp_str ) ;
        Slider3->SetValue( MyRadio.GetLevelE() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelE()) ; StaticText12->SetLabel( tmp_str ) ;
        Slider4->SetValue( MyRadio.GetLevelA() ) ; sprintf(tmp_str,"%03d",MyRadio.GetLevelA()) ; StaticText13->SetLabel( tmp_str ) ;

    }
    else
    {
        Button3->SetLabel("NORM");
        MyRadio.SetMode(NORM);
    }
}

void MainFrame::OnSliderCmdScrollChanged(wxScrollEvent& event)
{
    if (MyRadio.GetMode()==STAB)
    {
        MyRadio.ReCenter();
    }
}

void MainFrame::OnButton4Click(wxCommandEvent& event)
{
    MyRadio.SetTrimT( MyRadio.GetTrimT() - 1 );
}

void MainFrame::OnButton5Click(wxCommandEvent& event)
{
    MyRadio.SetTrimT( MyRadio.GetTrimT() + 1 );
}

void MainFrame::OnButton6Click(wxCommandEvent& event)
{
    MyRadio.SetTrimR( MyRadio.GetTrimR() - 1 );
}


void MainFrame::OnButton7Click(wxCommandEvent& event)
{
    MyRadio.SetTrimR( MyRadio.GetTrimR() + 1 );
}

void MainFrame::OnButton8Click(wxCommandEvent& event)
{
    MyRadio.SetTrimE( MyRadio.GetTrimE() - 1 );
}

void MainFrame::OnButton9Click(wxCommandEvent& event)
{
    MyRadio.SetTrimE( MyRadio.GetTrimE() + 1 );
}

void MainFrame::OnButton10Click(wxCommandEvent& event)
{
    MyRadio.SetTrimA( MyRadio.GetTrimA() - 1 );
}

void MainFrame::OnButton11Click(wxCommandEvent& event)
{
    MyRadio.SetTrimA( MyRadio.GetTrimA() + 1 );
}

void MainFrame::OnButton13Click(wxCommandEvent& event)
{
    MyRadio.Open( TextCtrl1->GetValue().c_str().AsChar() ) ;
}


void MainFrame::OnButton12Click(wxCommandEvent& event)
{
    MyFrontCamera.ToggleShowing() ;
}

// Decollage
void MainFrame::OnButton14Click(wxCommandEvent& event)
{
    pthread_t MyPiloteThread;
    if ( pthread_create ( &MyPiloteThread, NULL, PilotTakeOFF, NULL ) )
    {
        std::cerr << "Impossible de créer le thread take off\n" ;
    }
    SetCursorPos(0,0);
}

// auto THrottle
void MainFrame::OnButton16Click(wxCommandEvent& event)
{
    MyPilot.ToggleAltitudeStabilisation() ;
    SetCursorPos(0,0);
}

// QR code
void MainFrame::OnButton17Click(wxCommandEvent& event)
{

    if (MyPilot.GetActivity()==READINGQR)
    {
        MyPilot.SetActivity(0);
    }
    else
    {
        MyPilot.SetActivity(READINGQR);
    }
    SetCursorPos(0,0);
}

//Land
void MainFrame::OnButton15Click(wxCommandEvent& event)
{
    MyPilot.Landing() ;
           MyPilot.SetActivity(0);
        MyPilot.SetState(0);
        MyBottomCamera.SetCameraActivity(0);
    SetCursorPos(0,0);

}

//Gate
void MainFrame::OnButton18Click(wxCommandEvent& event)
{

if (MyPilot.GetActivity()==PASSGATE)
    {
        MyPilot.SetActivity(0);
    }
    else
    {
       MyPilot.SetActivity(PASSGATE);
    }
    SetCursorPos(0,0);

}




void MainFrame::OnButton19Click(wxCommandEvent& event)
{
    MyFrontCamera.ToggleRecording() ;
}

void MainFrame::OnButton20Click(wxCommandEvent& event)
{
    MyRadio.ToggleLog() ;
    if ( MyRadio.GetLog() )
    {
        Button20->SetLabel("Stop log");
        StaticText20->SetLabel("Log is pending ...");
    }
    else
    {
        Button20->SetLabel("Start log");
        StaticText20->SetLabel("");
    }
}

void MainFrame::OnButton21Click(wxCommandEvent& event)
{
    MyBottomCamera.ToggleShowing() ;
}

void MainFrame::OnButton22Click(wxCommandEvent& event)
{
    MyBottomCamera.ToggleRecording() ;
}

void MainFrame::OnButton23Click(wxCommandEvent& event)
{
}

void MainFrame::OnButton23Click1(wxCommandEvent& event)
{
   //MyFrontCamera.Run().ImageProcessing_QRCodeDetection();
}

void MainFrame::OnSlider4CmdScroll2(wxScrollEvent& event)
{
}
