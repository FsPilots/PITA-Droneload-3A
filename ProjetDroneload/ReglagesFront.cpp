#include "ReglagesFront.h"
#include "Camera.h"

extern C_Camera MyFrontCamera  ;

//(*InternalHeaders(ReglagesFront)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(ReglagesFront)
const long ReglagesFront::ID_STATICTEXT1 = wxNewId();
const long ReglagesFront::ID_STATICTEXT2 = wxNewId();
const long ReglagesFront::ID_SLIDER1 = wxNewId();
const long ReglagesFront::ID_STATICTEXT3 = wxNewId();
const long ReglagesFront::ID_STATICTEXT4 = wxNewId();
const long ReglagesFront::ID_SLIDER2 = wxNewId();
const long ReglagesFront::ID_STATICTEXT5 = wxNewId();
const long ReglagesFront::ID_STATICTEXT6 = wxNewId();
const long ReglagesFront::ID_SLIDER3 = wxNewId();
//*)

BEGIN_EVENT_TABLE(ReglagesFront,wxPanel)
	//(*EventTable(ReglagesFront)
	//*)
END_EVENT_TABLE()

ReglagesFront::ReglagesFront(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(ReglagesFront)
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer3;
	wxBoxSizer* BoxSizer4;

	Create(parent, wxID_ANY, wxDefaultPosition, wxSize(540,283), wxTAB_TRAVERSAL, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	BoxSizer2->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider1 = new wxSlider(this, ID_SLIDER1, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER1"));
	BoxSizer2->Add(Slider1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider2 = new wxSlider(this, ID_SLIDER2, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER2"));
	BoxSizer3->Add(Slider2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer4->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Slider3 = new wxSlider(this, ID_SLIDER3, 0, 0, 100, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_SLIDER3"));
	BoxSizer4->Add(Slider3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(BoxSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	SetSizer(BoxSizer1);
	Layout();

	Connect(ID_SLIDER1,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&ReglagesFront::OnSlider1CmdScroll);
	Connect(ID_SLIDER2,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&ReglagesFront::OnSlider2CmdScroll);
	Connect(ID_SLIDER3,wxEVT_SCROLL_TOP|wxEVT_SCROLL_BOTTOM|wxEVT_SCROLL_LINEUP|wxEVT_SCROLL_LINEDOWN|wxEVT_SCROLL_PAGEUP|wxEVT_SCROLL_PAGEDOWN|wxEVT_SCROLL_THUMBTRACK|wxEVT_SCROLL_THUMBRELEASE|wxEVT_SCROLL_CHANGED,(wxObjectEventFunction)&ReglagesFront::OnSlider3CmdScroll);
	Connect(wxEVT_PAINT,(wxObjectEventFunction)&ReglagesFront::OnPaint);
	//*)
}

ReglagesFront::~ReglagesFront()
{
	//(*Destroy(ReglagesFront)
	//*)
}

void ReglagesFront::OnSlider1CmdScroll(wxScrollEvent& event)
{
    //char tmpstr[128] ;
    //MyFrontCamera.accroche_error( (double) Slider1->GetValue()/100. ) ;
    //sprintf(tmpstr,"%.3f",MyFrontCamera.accroche_error) ;
	//StaticText2->SetLabel( tmpstr )
}

void ReglagesFront::OnSlider2CmdScroll(wxScrollEvent& event)
{

}

void ReglagesFront::OnSlider3CmdScroll(wxScrollEvent& event)
{

}


void ReglagesFront::OnPaint(wxPaintEvent& event)
{
/*
    char tmpstr[128] ;

    StaticText1->SetLabel( "Accroche_error" ) ;
	sprintf(tmpstr,"%.3f",MyFrontCamera.accroche_error) ;
	StaticText2->SetLabel( tmpstr ) ;
	Slider1->SetValue( int (MyFrontCamera.accroche_error * 100.) ) ;

    StaticText3->SetLabel( "Size Error" ) ;
	sprintf(tmpstr,"%.3f",MyFrontCamera.size_error)) ;
	StaticText4->SetLabel( tmpstr ) ;
	Slider2->SetValue( int (MyFrontCamera.size_error * 100.) ) ;

    StaticText5->SetLabel( "Size Accroche Error" ) ;
	sprintf(tmpstr,"%.3f",MyFrontCamera.size_accroche_error) ;
	StaticText6->SetLabel( tmpstr ) ;
	Slider3->SetValue( int (MyFrontCamera.size_accroche_error * 100.) ) ;
	*/
}




