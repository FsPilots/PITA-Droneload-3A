#ifndef REGLAGESFRONT_H
#define REGLAGESFRONT_H

//(*Headers(ReglagesFront)
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
//*)

class ReglagesFront: public wxPanel
{
	public:

		ReglagesFront(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ReglagesFront();

		//(*Declarations(ReglagesFront)
		wxSlider* Slider1;
		wxSlider* Slider2;
		wxSlider* Slider3;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		//*)

	protected:

		//(*Identifiers(ReglagesFront)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_SLIDER1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_SLIDER3;
		//*)

	private:

		//(*Handlers(ReglagesFront)
		void OnPaint(wxPaintEvent& event);
		void OnSlider1CmdScroll(wxScrollEvent& event);
		void OnSlider2CmdScroll(wxScrollEvent& event);
		void OnSlider3CmdScroll(wxScrollEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
