#ifndef REGLAGES_H
#define REGLAGES_H

//(*Headers(Reglages)
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
//*)

class Reglages: public wxDialog
{
	public:

		Reglages(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~Reglages();

		//(*Declarations(Reglages)
		wxButton* Button1;
		wxPanel* Panel1;
		wxSlider* Slider10;
		wxSlider* Slider11;
		wxSlider* Slider12;
		wxSlider* Slider13;
		wxSlider* Slider14;
		wxSlider* Slider15;
		wxSlider* Slider1;
		wxSlider* Slider2;
		wxSlider* Slider3;
		wxSlider* Slider4;
		wxSlider* Slider5;
		wxSlider* Slider6;
		wxSlider* Slider7;
		wxSlider* Slider8;
		wxSlider* Slider9;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText14;
		wxStaticText* StaticText15;
		wxStaticText* StaticText16;
		wxStaticText* StaticText17;
		wxStaticText* StaticText18;
		wxStaticText* StaticText19;
		wxStaticText* StaticText1;
		wxStaticText* StaticText20;
		wxStaticText* StaticText21;
		wxStaticText* StaticText22;
		wxStaticText* StaticText23;
		wxStaticText* StaticText24;
		wxStaticText* StaticText25;
		wxStaticText* StaticText26;
		wxStaticText* StaticText27;
		wxStaticText* StaticText28;
		wxStaticText* StaticText29;
		wxStaticText* StaticText2;
		wxStaticText* StaticText30;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		//*)

	protected:

		//(*Identifiers(Reglages)
		static const long ID_STATICTEXT1;
		static const long ID_STATICTEXT2;
		static const long ID_SLIDER1;
		static const long ID_STATICTEXT3;
		static const long ID_STATICTEXT4;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT6;
		static const long ID_SLIDER3;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT8;
		static const long ID_SLIDER4;
		static const long ID_STATICTEXT9;
		static const long ID_STATICTEXT10;
		static const long ID_SLIDER5;
		static const long ID_STATICTEXT11;
		static const long ID_STATICTEXT12;
		static const long ID_SLIDER6;
		static const long ID_STATICTEXT13;
		static const long ID_STATICTEXT14;
		static const long ID_SLIDER7;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT16;
		static const long ID_SLIDER8;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT18;
		static const long ID_SLIDER9;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT20;
		static const long ID_SLIDER10;
		static const long ID_STATICTEXT21;
		static const long ID_STATICTEXT22;
		static const long ID_SLIDER11;
		static const long ID_STATICTEXT23;
		static const long ID_STATICTEXT24;
		static const long ID_SLIDER12;
		static const long ID_STATICTEXT25;
		static const long ID_STATICTEXT26;
		static const long ID_SLIDER13;
		static const long ID_STATICTEXT28;
		static const long ID_STATICTEXT27;
		static const long ID_SLIDER14;
		static const long ID_STATICTEXT29;
		static const long ID_STATICTEXT30;
		static const long ID_SLIDER15;
		static const long ID_BUTTON1;
		static const long ID_PANEL1;
		//*)

	private:

		//(*Handlers(Reglages)
		void OnSlider1CmdScroll(wxScrollEvent& event);
		void OnSlider2CmdScroll(wxScrollEvent& event);
		void OnSlider3CmdScroll(wxScrollEvent& event);
		void OnSlider4CmdScroll(wxScrollEvent& event);
		void OnSlider5CmdScroll(wxScrollEvent& event);
		void OnSlider6CmdScroll(wxScrollEvent& event);
		void OnSlider7CmdScroll(wxScrollEvent& event);
		void OnSlider8CmdScroll(wxScrollEvent& event);
		void OnSlider9CmdScroll(wxScrollEvent& event);
		void OnSlider10CmdScroll(wxScrollEvent& event);
		void OnSlider11CmdScroll(wxScrollEvent& event);
		void OnSlider12CmdScroll(wxScrollEvent& event);
		void OnSlider13CmdScroll(wxScrollEvent& event);
		void OnSlider5CmdScroll1(wxScrollEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnButton1Click(wxCommandEvent& event);
		void OnSlider13CmdScroll1(wxScrollEvent& event);
		void OnSlider14CmdScroll(wxScrollEvent& event);
		void OnSlider14CmdScroll1(wxScrollEvent& event);
		void OnSlider15CmdScroll(wxScrollEvent& event);
		void OnSlider13CmdScroll2(wxScrollEvent& event);
		void OnSlider13CmdScroll3(wxScrollEvent& event);
		void OnSlider12CmdScroll1(wxScrollEvent& event);
		void OnSlider2CmdScroll1(wxScrollEvent& event);
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
