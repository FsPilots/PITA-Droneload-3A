#ifndef REGLAGESWINDOWS_H
#define REGLAGESWINDOWS_H

//(*Headers(ReglagesWindows)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
//*)

class ReglagesWindows: public wxDialog
{
	public:

		ReglagesWindows(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~ReglagesWindows();

		//(*Declarations(ReglagesWindows)
		wxSlider* Slider1;
		wxSlider* Slider2;
		wxSlider* Slider4;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		//*)

	protected:

		//(*Identifiers(ReglagesWindows)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_SLIDER1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_SLIDER4;
		//*)

	private:

		//(*Handlers(ReglagesWindows)
		void OnSlider1CmdScroll(wxScrollEvent& event);
		void OnSlider2CmdScroll(wxScrollEvent& event);
		void OnSlider4CmdScroll(wxScrollEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
