#include "Reglages.h"

#include "Camera.h"
#include "Pilote.h"

extern C_Camera MyBottomCamera  ;
extern C_Camera MyFrontCamera ;
extern C_Pilote MyPilot ;

//(*InternalHeaders(Reglages)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Reglages)
const long Reglages::ID_STATICTEXT1 = wxNewId();
const long Reglages::ID_STATICTEXT2 = wxNewId();
const long Reglages::ID_SLIDER1 = wxNewId();
const long Reglages::ID_STATICTEXT3 = wxNewId();
const long Reglages::ID_STATICTEXT4 = wxNewId();
const long Reglages::ID_SLIDER2 = wxNewId();
const long Reglages::ID_STATICTEXT5 = wxNewId();
const long Reglages::ID_STATICTEXT6 = wxNewId();
const long Reglages::ID_SLIDER3 = wxNewId();
const long Reglages::ID_STATICTEXT7 = wxNewId();
const long Reglages::ID_STATICTEXT8 = wxNewId();
const long Reglages::ID_SLIDER4 = wxNewId();
const long Reglages::ID_STATICTEXT9 = wxNewId();
const long Reglages::ID_STATICTEXT10 = wxNewId();
const long Reglages::ID_SLIDER5 = wxNewId();
const long Reglages::ID_STATICTEXT11 = wxNewId();
const long Reglages::ID_STATICTEXT12 = wxNewId();
const long Reglages::ID_SLIDER6 = wxNewId();
const long Reglages::ID_STATICTEXT13 = wxNewId();
const long Reglages::ID_STATICTEXT14 = wxNewId();
const long Reglages::ID_SLIDER7 = wxNewId();
const long Reglages::ID_STATICTEXT15 = wxNewId();
const long Reglages::ID_STATICTEXT16 = wxNewId();
const long Reglages::ID_SLIDER8 = wxNewId();
const long Reglages::ID_STATICTEXT17 = wxNewId();
const long Reglages::ID_STATICTEXT18 = wxNewId();
const long Reglages::ID_SLIDER9 = wxNewId();
const long Reglages::ID_STATICTEXT19 = wxNewId();
const long Reglages::ID_STATICTEXT20 = wxNewId();
const long Reglages::ID_SLIDER10 = wxNewId();
const long Reglages::ID_STATICTEXT21 = wxNewId();
const long Reglages::ID_STATICTEXT22 = wxNewId();
const long Reglages::ID_SLIDER11 = wxNewId();
const long Reglages::ID_STATICTEXT23 = wxNewId();
const long Reglages::ID_STATICTEXT24 = wxNewId();
const long Reglages::ID_SLIDER12 = wxNewId();
const long Reglages::ID_STATICTEXT25 = wxNewId();
const long Reglages::ID_STATICTEXT26 = wxNewId();
const long Reglages::ID_SLIDER13 = wxNewId();
const long Reglages::ID_STATICTEXT28 = wxNewId();
const long Reglages::ID_STATICTEXT27 = wxNewId();
const long Reglages::ID_SLIDER14 = wxNewId();
const long Reglages::ID_STATICTEXT29 = wxNewId();
const long Reglages::ID_STATICTEXT30 = wxNewId();
const long Reglages::ID_SLIDER15 = wxNewId();
const long Reglages::ID_STATICLINE2 = wxNewId();
const long Reglages::ID_STATICTEXT31 = wxNewId();
const long Reglages::ID_STATICLINE3 = wxNewId();
const long Reglages::ID_STATICTEXT32 = wxNewId();
const long Reglages::ID_STATICTEXT33 = wxNewId();
const long Reglages::ID_SLIDER16 = wxNewId();
const long Reglages::ID_STATICTEXT34 = wxNewId();
const long Reglages::ID_STATICTEXT35 = wxNewId();
const long Reglages::ID_SLIDER17 = wxNewId();
const long Reglages::ID_STATICTEXT36 = wxNewId();
const long Reglages::ID_STATICTEXT37 = wxNewId();
const long Reglages::ID_SLIDER18 = wxNewId();
const long Reglages::ID_BUTTON1 = wxNewId();
const long Reglages::ID_PANEL1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Reglages,wxDialog)
	//(*EventTable(Reglages)
	//*)
END_EVENT_TABLE()

Reglages::Reglages(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(Reglages)
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
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxBoxSizer* BoxSizer9;

	Create(parent, wxID_ANY, _("Réglage TI Bottom Camera"), wxDefaultPosition, wxDefaultSize, wxSTAY_ON_TOP|wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER, _T("wxID_ANY"));
	SetClientSize(wxSize(647,926));
	Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider1 = new wxSlider(Panel1, ID_SLIDER1, 0, 150, 255, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER1"));
	BoxSizer2->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider2 = new wxSlider(Panel1, ID_SLIDER2, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER2"));
	BoxSizer3->Add(Slider2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(Panel1, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT6"));
	BoxSizer4->Add(StaticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider3 = new wxSlider(Panel1, ID_SLIDER3, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER3"));
	BoxSizer4->Add(Slider3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT7"));
	BoxSizer5->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(Panel1, ID_STATICTEXT8, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT8"));
	BoxSizer5->Add(StaticText8, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider4 = new wxSlider(Panel1, ID_SLIDER4, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER4"));
	BoxSizer5->Add(Slider4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText9 = new wxStaticText(Panel1, ID_STATICTEXT9, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT9"));
	BoxSizer6->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(Panel1, ID_STATICTEXT10, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT10"));
	BoxSizer6->Add(StaticText10, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider5 = new wxSlider(Panel1, ID_SLIDER5, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER5"));
	BoxSizer6->Add(Slider5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(Panel1, ID_STATICTEXT11, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT11"));
	BoxSizer7->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText12 = new wxStaticText(Panel1, ID_STATICTEXT12, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT12"));
	BoxSizer7->Add(StaticText12, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider6 = new wxSlider(Panel1, ID_SLIDER6, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER6"));
	BoxSizer7->Add(Slider6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText13 = new wxStaticText(Panel1, ID_STATICTEXT13, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT13"));
	BoxSizer8->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText14 = new wxStaticText(Panel1, ID_STATICTEXT14, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT14"));
	BoxSizer8->Add(StaticText14, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider7 = new wxSlider(Panel1, ID_SLIDER7, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER7"));
	BoxSizer8->Add(Slider7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText15 = new wxStaticText(Panel1, ID_STATICTEXT15, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT15"));
	BoxSizer9->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText16 = new wxStaticText(Panel1, ID_STATICTEXT16, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT16"));
	BoxSizer9->Add(StaticText16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider8 = new wxSlider(Panel1, ID_SLIDER8, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER8"));
	BoxSizer9->Add(Slider8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText17 = new wxStaticText(Panel1, ID_STATICTEXT17, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT17"));
	BoxSizer10->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText18 = new wxStaticText(Panel1, ID_STATICTEXT18, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT18"));
	BoxSizer10->Add(StaticText18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider9 = new wxSlider(Panel1, ID_SLIDER9, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER9"));
	BoxSizer10->Add(Slider9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText19 = new wxStaticText(Panel1, ID_STATICTEXT19, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT19"));
	BoxSizer11->Add(StaticText19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText20 = new wxStaticText(Panel1, ID_STATICTEXT20, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT20"));
	BoxSizer11->Add(StaticText20, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider10 = new wxSlider(Panel1, ID_SLIDER10, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER10"));
	BoxSizer11->Add(Slider10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	StaticText21 = new wxStaticText(Panel1, ID_STATICTEXT21, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT21"));
	BoxSizer12->Add(StaticText21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText22 = new wxStaticText(Panel1, ID_STATICTEXT22, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT22"));
	BoxSizer12->Add(StaticText22, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider11 = new wxSlider(Panel1, ID_SLIDER11, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER11"));
	BoxSizer12->Add(Slider11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText23 = new wxStaticText(Panel1, ID_STATICTEXT23, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT23"));
	BoxSizer13->Add(StaticText23, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText24 = new wxStaticText(Panel1, ID_STATICTEXT24, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT24"));
	BoxSizer13->Add(StaticText24, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider12 = new wxSlider(Panel1, ID_SLIDER12, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER12"));
	BoxSizer13->Add(Slider12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	StaticText25 = new wxStaticText(Panel1, ID_STATICTEXT25, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT25"));
	BoxSizer14->Add(StaticText25, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText26 = new wxStaticText(Panel1, ID_STATICTEXT26, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT26"));
	BoxSizer14->Add(StaticText26, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider13 = new wxSlider(Panel1, ID_SLIDER13, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER13"));
	BoxSizer14->Add(Slider13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer16 = new wxBoxSizer(wxHORIZONTAL);
	StaticText27 = new wxStaticText(Panel1, ID_STATICTEXT28, _("Label"), wxDefaultPosition, wxSize(150,-1), 0, _T("ID_STATICTEXT28"));
	BoxSizer16->Add(StaticText27, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText28 = new wxStaticText(Panel1, ID_STATICTEXT27, _("Label"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT, _T("ID_STATICTEXT27"));
	BoxSizer16->Add(StaticText28, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider14 = new wxSlider(Panel1, ID_SLIDER14, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER14"));
	BoxSizer16->Add(Slider14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer17 = new wxBoxSizer(wxHORIZONTAL);
	StaticText29 = new wxStaticText(Panel1, ID_STATICTEXT29, _("Label"), wxDefaultPosition, wxSize(204,21), 0, _T("ID_STATICTEXT29"));
	BoxSizer17->Add(StaticText29, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText30 = new wxStaticText(Panel1, ID_STATICTEXT30, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT30"));
	BoxSizer17->Add(StaticText30, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider15 = new wxSlider(Panel1, ID_SLIDER15, 0, 0, 100, wxDefaultPosition, wxSize(200,-1), 0, wxDefaultValidator, _T("ID_SLIDER15"));
	BoxSizer17->Add(Slider15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	BoxSizer18 = new wxBoxSizer(wxHORIZONTAL);
	StaticLine2 = new wxStaticLine(Panel1, ID_STATICLINE2, wxDefaultPosition, wxSize(71,4), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	BoxSizer18->Add(StaticLine2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText31 = new wxStaticText(Panel1, ID_STATICTEXT31, _("Réglages Windows Detect"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT31"));
	BoxSizer18->Add(StaticText31, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticLine3 = new wxStaticLine(Panel1, ID_STATICLINE3, wxDefaultPosition, wxSize(71,4), wxLI_HORIZONTAL, _T("ID_STATICLINE3"));
	BoxSizer18->Add(StaticLine3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer18, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer19 = new wxBoxSizer(wxHORIZONTAL);
	StaticText32 = new wxStaticText(Panel1, ID_STATICTEXT32, _("Label"), wxDefaultPosition, wxSize(172,21), 0, _T("ID_STATICTEXT32"));
	BoxSizer19->Add(StaticText32, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText33 = new wxStaticText(Panel1, ID_STATICTEXT33, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT33"));
	BoxSizer19->Add(StaticText33, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider16 = new wxSlider(Panel1, ID_SLIDER16, 0, 0, 100, wxDefaultPosition, wxSize(227,28), 0, wxDefaultValidator, _T("ID_SLIDER16"));
	BoxSizer19->Add(Slider16, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer19, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer20 = new wxBoxSizer(wxHORIZONTAL);
	StaticText34 = new wxStaticText(Panel1, ID_STATICTEXT34, _("Label"), wxDefaultPosition, wxSize(159,21), 0, _T("ID_STATICTEXT34"));
	BoxSizer20->Add(StaticText34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText35 = new wxStaticText(Panel1, ID_STATICTEXT35, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT35"));
	BoxSizer20->Add(StaticText35, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider17 = new wxSlider(Panel1, ID_SLIDER17, 0, 0, 500, wxDefaultPosition, wxSize(235,28), 0, wxDefaultValidator, _T("ID_SLIDER17"));
	BoxSizer20->Add(Slider17, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer20, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer21 = new wxBoxSizer(wxHORIZONTAL);
	StaticText36 = new wxStaticText(Panel1, ID_STATICTEXT36, _("Label"), wxDefaultPosition, wxSize(156,21), 0, _T("ID_STATICTEXT36"));
	BoxSizer21->Add(StaticText36, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText37 = new wxStaticText(Panel1, ID_STATICTEXT37, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT37"));
	BoxSizer21->Add(StaticText37, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider18 = new wxSlider(Panel1, ID_SLIDER18, 0, 0, 500, wxDefaultPosition, wxSize(239,28), 0, wxDefaultValidator, _T("ID_SLIDER18"));
	BoxSizer21->Add(Slider18, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer21, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	Button1 = new wxButton(Panel1, ID_BUTTON1, _("Close"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	BoxSizer15->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer15, 1, wxALL, 0);
	Panel1->SetSizer(BoxSizer1);
	BoxSizer1->Fit(Panel1);
	BoxSizer1->SetSizeHints(Panel1);

	Connect(ID_SLIDER1,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider1CmdScroll);
	Connect(ID_SLIDER2,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider2CmdScroll);
	Connect(ID_SLIDER3,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider3CmdScroll);
	Connect(ID_SLIDER4,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider4CmdScroll);
	Connect(ID_SLIDER5,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider5CmdScroll);
	Connect(ID_SLIDER6,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider6CmdScroll);
	Connect(ID_SLIDER7,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider7CmdScroll);
	Connect(ID_SLIDER8,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider8CmdScroll);
	Connect(ID_SLIDER9,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider9CmdScroll);
	Connect(ID_SLIDER10,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider10CmdScroll);
	Connect(ID_SLIDER11,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider11CmdScroll);
	Connect(ID_SLIDER12,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider12CmdScroll);
	Connect(ID_SLIDER13,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider13CmdScroll);
	Connect(ID_SLIDER14,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider14CmdScroll);
	Connect(ID_SLIDER15,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider15CmdScroll);
	Connect(ID_SLIDER16,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider16CmdScroll);
	Connect(ID_SLIDER17,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider17CmdScroll);
	Connect(ID_SLIDER18,wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&Reglages::OnSlider18CmdScroll);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&Reglages::OnButton1Click);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&Reglages::OnPaint);
	//*)

}

Reglages::~Reglages()
{
	//(*Destroy(Reglages)
	//*)
}


void Reglages::OnSlider1CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_GreyLevelThreshold  = Slider1->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_GreyLevelThreshold) ;
	StaticText2->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider2CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_OpenKernelSize  = Slider2->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_OpenKernelSize) ;
	StaticText4->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider3CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_TopHatKernelSize  = Slider3->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_TopHatKernelSize) ;
	StaticText6->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider4CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_MaxRayon  = Slider4->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_MaxRayon) ;
	StaticText8->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider5CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_MinArea  = Slider5->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_MinArea) ;
	StaticText10->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider6CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_MoyenneMin  = Slider6->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_MoyenneMin) ;
	StaticText12->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider7CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_SigmaMax  = Slider7->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_SigmaMax) ;
	StaticText14->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider8CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_SymetryCondition  = Slider8->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_SymetryCondition) ;
	StaticText16->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider9CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_HorizCondition  = Slider9->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_HorizCondition) ;
	StaticText18->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider10CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyBottomCamera.m_ProxyCondition  = Slider10->GetValue() ;
    sprintf(tmpstr,"%d",MyBottomCamera.m_ProxyCondition) ;
	StaticText20->SetLabel( tmpstr ) ;
}

void Reglages::OnSlider11CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyPilot.SetAlphaFiltrage( (double) Slider11->GetValue()/100. ) ;
    sprintf(tmpstr,"%.3f",MyPilot.GetAlphaFiltrage()) ;
	StaticText22->SetLabel( tmpstr ) ;
}

void Reglages::OnSlider12CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyPilot.SetPID_P_Up( (double) Slider12->GetValue()/100. ) ;
    sprintf(tmpstr,"%.3f",MyPilot.GetPID_P_Up()) ;
	StaticText24->SetLabel( tmpstr ) ;
}

void Reglages::OnSlider13CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyPilot.SetPID_P_Dwn( (double) Slider13->GetValue()/100. ) ;
    sprintf(tmpstr,"%.3f",MyPilot.GetPID_P_Dwn()) ;
	StaticText26->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider14CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyPilot.Setm_PID_P_Center( (double) Slider14->GetValue()/100. ) ;
    sprintf(tmpstr,"%.3f",MyPilot.Getm_PID_P_Center()) ;
	StaticText28->SetLabel( tmpstr ) ;
}


void Reglages::OnSlider15CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyPilot.Setm_PID_P_Center_Roll( (double) Slider15->GetValue()/100.) ;
    sprintf(tmpstr,"%.3f",MyPilot.Getm_PID_P_Center_Roll()) ;
	StaticText30->SetLabel( tmpstr ) ;
}

void Reglages::OnSlider16CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyFrontCamera.set_accroche_error( (int) Slider16->GetValue() ) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_accroche_error()) ;
    StaticText33->SetLabel( tmpstr );
}

void Reglages::OnSlider17CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyFrontCamera.set_size_error( (int) Slider17->GetValue() ) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_size_error()) ;
    StaticText35->SetLabel( tmpstr );
}

void Reglages::OnSlider18CmdScroll(wxScrollEvent& event)
{
    char tmpstr[128] ;
    MyFrontCamera.set_size_accroche_error( (int) Slider18->GetValue()) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_size_accroche_error()) ;
    StaticText37->SetLabel( tmpstr );
}



void Reglages::OnPaint(wxPaintEvent& event)
{
    char tmpstr[128] ;

	StaticText1->SetLabel( "m_GreyLevelThreshold" ) ;
	sprintf(tmpstr,"%d", MyBottomCamera.m_GreyLevelThreshold ) ;
	StaticText2->SetLabel( tmpstr ) ;
	Slider1->SetValue( MyBottomCamera.m_GreyLevelThreshold ) ;

	StaticText3->SetLabel( "m_OpenKernelSize" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_OpenKernelSize) ;
	StaticText4->SetLabel( tmpstr ) ;
	Slider2->SetValue( MyBottomCamera.m_OpenKernelSize ) ;

	StaticText5->SetLabel( "m_TopHatKernelSize" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_TopHatKernelSize) ;
	StaticText6->SetLabel( tmpstr ) ;
	Slider3->SetValue( MyBottomCamera.m_TopHatKernelSize ) ;

	StaticText7->SetLabel( "m_MaxRayon" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_MaxRayon) ;
	StaticText8->SetLabel( tmpstr ) ;
	Slider4->SetValue( MyBottomCamera.m_MaxRayon ) ;

	StaticText9->SetLabel( "m_MinArea" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_MinArea) ;
	StaticText10->SetLabel( tmpstr ) ;
	Slider5->SetValue( MyBottomCamera.m_MinArea ) ;

	StaticText11->SetLabel( "m_MoyenneMin" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_MoyenneMin) ;
	StaticText12->SetLabel( tmpstr ) ;
	Slider6->SetValue( MyBottomCamera.m_MoyenneMin) ;

	StaticText13->SetLabel( "m_SigmaMax" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_SigmaMax) ;
	StaticText14->SetLabel( tmpstr ) ;
	Slider7->SetValue( MyBottomCamera.m_SigmaMax ) ;

	StaticText15->SetLabel( "m_SymetryCondition" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_SymetryCondition ) ;
	StaticText16->SetLabel( tmpstr ) ;
	Slider8->SetValue( MyBottomCamera.m_SymetryCondition ) ;

	StaticText17->SetLabel( "m_HorizCondition" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_HorizCondition) ;
	StaticText18->SetLabel( tmpstr ) ;
	Slider9->SetValue( MyBottomCamera.m_HorizCondition ) ;

	StaticText19->SetLabel( "m_ProxyCondition" ) ;
	sprintf(tmpstr,"%d",MyBottomCamera.m_ProxyCondition) ;
	StaticText20->SetLabel( tmpstr ) ;
	Slider10->SetValue( MyBottomCamera.m_ProxyCondition ) ;

	StaticText21->SetLabel( "m_AphaFiltrage" ) ;
	sprintf(tmpstr,"%.3f",MyPilot.GetAlphaFiltrage()) ;
	StaticText22->SetLabel( tmpstr ) ;
	Slider11->SetValue( int (MyPilot.GetAlphaFiltrage() * 100.) ) ;

	StaticText23->SetLabel( "m_PID_P_up" ) ;
	sprintf(tmpstr,"%.3f",MyPilot.GetPID_P_Up()) ;
	StaticText24->SetLabel( tmpstr ) ;
	Slider12->SetValue( int (MyPilot.GetPID_P_Up() * 100.) ) ;

	StaticText25->SetLabel( "m_PID_P_DWN" ) ;
	sprintf(tmpstr,"%.3f",MyPilot.GetPID_P_Dwn()) ;
	StaticText26->SetLabel( tmpstr ) ;
	Slider13->SetValue( int (MyPilot.GetPID_P_Dwn() * 100.) ) ;

	StaticText27->SetLabel( "m_PID_P_Center" ) ;
	sprintf(tmpstr,"%.3f",MyPilot.Getm_PID_P_Center()) ;
	StaticText28->SetLabel( tmpstr ) ;
	Slider14->SetValue( int (MyPilot.Getm_PID_P_Center() * 100.) ) ;

    StaticText29->SetLabel( "m_PID_P_Center_Roll" ) ;
	sprintf(tmpstr,"%.3f",MyPilot.Getm_PID_P_Center_Roll()) ;
	StaticText30->SetLabel( tmpstr ) ;
	Slider15->SetValue( int (MyPilot.Getm_PID_P_Center_Roll() * 100.) ) ;

    StaticText32->SetLabel( "Accroche_error" ) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_accroche_error()) ;
    StaticText33->SetLabel( tmpstr ) ;
    Slider16->SetValue( int (MyFrontCamera.get_accroche_error()) ) ;

    StaticText34->SetLabel( "Size Error" ) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_size_error()) ;
    StaticText35->SetLabel( tmpstr ) ;
    Slider17->SetValue( int (MyFrontCamera.get_size_error()) ) ;

    StaticText36->SetLabel( "Size Accroche Error" ) ;
    sprintf(tmpstr,"%d",MyFrontCamera.get_size_accroche_error()) ;
    StaticText37->SetLabel( tmpstr ) ;
    Slider18->SetValue( int (MyFrontCamera.get_size_accroche_error()) ) ;
}

void Reglages::OnButton1Click(wxCommandEvent& event)
{
    Close() ;
}


