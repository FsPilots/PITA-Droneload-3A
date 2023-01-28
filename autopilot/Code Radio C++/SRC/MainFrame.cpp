#include "MainFrame.h"
#include <stdio.h>

//(*InternalHeaders(MainFrame)
#include <wx/intl.h>
#include <wx/settings.h>
#include <wx/string.h>
//*)

//(*IdInit(MainFrame)
const long MainFrame::ID_BUTTON1 = wxNewId();
const long MainFrame::ID_BUTTON2 = wxNewId();
const long MainFrame::ID_BUTTON3 = wxNewId();
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
const long MainFrame::ID_TEXTCTRL1 = wxNewId();
const long MainFrame::ID_STATICTEXT5 = wxNewId();
//*)

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
	wxBoxSizer* BoxSizer24;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Projet ESTACA"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
	SetForegroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(this, ID_BUTTON1, _("Quit"), wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer2->Add(Button1, 0, wxALL|wxEXPAND, 5);
	Button2 = new wxButton(this, ID_BUTTON2, _("Reset"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	BoxSizer2->Add(Button2, 0, wxALL|wxEXPAND, 5);
	Button3 = new wxButton(this, ID_BUTTON3, _("NORM"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
	BoxSizer2->Add(Button3, 0, wxALL|wxEXPAND, 5);
	BoxSizer1->Add(BoxSizer2, 0, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	BoxSizer5 = new wxBoxSizer(wxVERTICAL);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Roll"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	StaticText1->SetForegroundColour(wxColour(0,0,255));
	BoxSizer9->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer5->Add(BoxSizer9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer10 = new wxBoxSizer(wxVERTICAL);
	Slider1 = new wxSlider(this, ID_SLIDER1, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER1"));
	Slider1->SetThumbLength(45);
	Slider1->SetBackgroundColour(wxColour(255,128,0));
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
	BoxSizer3->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6 = new wxBoxSizer(wxVERTICAL);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Pitch"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText2->SetForegroundColour(wxColour(0,0,255));
	BoxSizer11->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer6->Add(BoxSizer11, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer12 = new wxBoxSizer(wxVERTICAL);
	Slider2 = new wxSlider(this, ID_SLIDER2, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER2"));
	Slider2->SetThumbLength(45);
	Slider2->SetBackgroundColour(wxColour(255,128,64));
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
	BoxSizer3->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7 = new wxBoxSizer(wxVERTICAL);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Yaw"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	StaticText3->SetForegroundColour(wxColour(0,0,255));
	BoxSizer13->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer7->Add(BoxSizer13, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer14 = new wxBoxSizer(wxVERTICAL);
	Slider3 = new wxSlider(this, ID_SLIDER3, 50, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER3"));
	Slider3->SetThumbLength(45);
	Slider3->SetBackgroundColour(wxColour(255,128,64));
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
	BoxSizer3->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8 = new wxBoxSizer(wxVERTICAL);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Throttle"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	StaticText4->SetForegroundColour(wxColour(0,0,255));
	BoxSizer15->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer8->Add(BoxSizer15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer16 = new wxBoxSizer(wxVERTICAL);
	Slider4 = new wxSlider(this, ID_SLIDER4, 0, 0, 100, wxDefaultPosition, wxSize(50,400), wxSL_VERTICAL|wxSL_INVERSE|wxBORDER_RAISED, wxDefaultValidator, _T("ID_SLIDER4"));
	Slider4->SetThumbLength(45);
	Slider4->SetBackgroundColour(wxColour(255,128,64));
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
	BoxSizer8->Add(BoxSizer16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	TextCtrl1 = new wxTextCtrl(this, ID_TEXTCTRL1, _("COM2"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer4->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Unconnected"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT5"));
	StaticText5->SetForegroundColour(wxColour(255,0,0));
	BoxSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 0, wxALL|wxEXPAND, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton1Click);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton2Click);
	Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton3Click);
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
	Connect(ID_SLIDER4,wxEVT_COMMAND_SLIDER_UPDATED,(wxObjectEventFunction)&MainFrame::OnSlider4CmdScroll);
	Connect(ID_BUTTON10,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton10Click);
	Connect(ID_BUTTON11,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&MainFrame::OnButton11Click1);
	Connect(ID_TEXTCTRL1,wxEVT_COMMAND_TEXT_ENTER,(wxObjectEventFunction)&MainFrame::OnTextCtrl1Text);
	//*)

    Update() ;
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

    if ( MyRadio.IsOpen() )
    {
        StaticText5->SetForegroundColour(wxColour(0,255,0));
        StaticText5->SetLabel("Connected") ;
        //Led1->SwitchOn();
    }
    else
    {
        StaticText5->SetForegroundColour(wxColour(255,0,0));
        StaticText5->SetLabel("Unconnected") ;
        //Led1->SwitchOff();
    }
    StaticText5->SetWindowStyle(wxALL|wxALIGN_CENTRE);

    if ( MyRadio.GetMode() == 1 )
    {
        Button3->SetLabel("STAB");
    }
    else
    {
        Button3->SetLabel("NORM");
    }

    char tmp_str[10] ;

    Slider1->SetValue( MyRadio.GetLevelA() ) ;
    sprintf(tmp_str,"%03d",MyRadio.GetLevelA());
    StaticText10->SetLabel( tmp_str ) ;

    Slider2->SetValue( MyRadio.GetLevelE() ) ;
    sprintf(tmp_str,"%03d",MyRadio.GetLevelE());
    StaticText11->SetLabel( tmp_str ) ;

    Slider3->SetValue( MyRadio.GetLevelR() ) ;
    sprintf(tmp_str,"%03d",MyRadio.GetLevelR());
    StaticText12->SetLabel( tmp_str ) ;

    Slider4->SetValue( MyRadio.GetLevelT() ) ;
    sprintf(tmp_str,"%03d",MyRadio.GetLevelT());
    StaticText13->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetTrimA());
    StaticText6->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetTrimE());
    StaticText7->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetTrimR());
    StaticText8->SetLabel( tmp_str ) ;

    sprintf(tmp_str,"%d",MyRadio.GetTrimT());
    StaticText9->SetLabel( tmp_str ) ;

    this->Refresh();
}

void MainFrame::OnButton1Click(wxCommandEvent& event)
{
    Close() ;
}

void MainFrame::OnSlider1CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelA( Slider1->GetValue() );
    UpdateIHM() ;
}

void MainFrame::OnSlider2CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelE( Slider2->GetValue() );
    UpdateIHM() ;
}

void MainFrame::OnSlider3CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelR( Slider3->GetValue() );
    UpdateIHM() ;
}

void MainFrame::OnSlider4CmdScroll(wxScrollEvent& event)
{
    MyRadio.SetLevelT( Slider4->GetValue() );
    UpdateIHM() ;
}

void MainFrame::OnTextCtrl1Text(wxCommandEvent& event)
{
    MyRadio.Open( TextCtrl1->GetValue().c_str().AsChar() ) ;
    UpdateIHM() ;
}

void MainFrame::OnButton2Click(wxCommandEvent& event)
{
    MyRadio.Reset();
    UpdateIHM() ;
}

void MainFrame::OnButton3Click(wxCommandEvent& event)
{
    if ( strcmp("NORM", Button3->GetLabel().c_str().AsChar())==0 )
    {
        Button3->SetLabel("STAB");
        MyRadio.SetMode(STAB);
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
    UpdateIHM() ;
}

void MainFrame::OnButton4Click(wxCommandEvent& event)
{
    MyRadio.SetTrimA( MyRadio.GetTrimA() - 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton5Click(wxCommandEvent& event)
{
    MyRadio.SetTrimA( MyRadio.GetTrimA() + 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton6Click(wxCommandEvent& event)
{
    MyRadio.SetTrimE( MyRadio.GetTrimE() - 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton7Click(wxCommandEvent& event)
{
    MyRadio.SetTrimE( MyRadio.GetTrimE() + 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton8Click(wxCommandEvent& event)
{
    MyRadio.SetTrimR( MyRadio.GetTrimR() - 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton9Click(wxCommandEvent& event)
{
    MyRadio.SetTrimR( MyRadio.GetTrimR() + 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton10Click(wxCommandEvent& event)
{
    MyRadio.SetTrimT( MyRadio.GetTrimT() - 1 );
    UpdateIHM() ;
}

void MainFrame::OnButton11Click1(wxCommandEvent& event)
{
    MyRadio.SetTrimT( MyRadio.GetTrimT() + 1 );
    UpdateIHM() ;
}


void MainFrame::OnSlider1CmdScroll1(wxScrollEvent& event)
{
}

void MainFrame::OnSlider1CmdScroll2(wxScrollEvent& event)
{
}

void MainFrame::OnSlider1CmdScroll3(wxScrollEvent& event)
{
}

void MainFrame::OnSlider4CmdScroll2(wxScrollEvent& event)
{
}
