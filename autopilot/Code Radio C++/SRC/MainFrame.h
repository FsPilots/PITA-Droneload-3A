#ifndef MAINFRAME_H
#define MAINFRAME_H



//(*Headers(MainFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/sizer.h>
#include <wx/slider.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

#include "Radio.h"


class MainFrame: public wxFrame
{
	public:

		MainFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MainFrame();

		//(*Declarations(MainFrame)
		wxButton* Button10;
		wxButton* Button11;
		wxButton* Button1;
		wxButton* Button2;
		wxButton* Button3;
		wxButton* Button4;
		wxButton* Button5;
		wxButton* Button6;
		wxButton* Button7;
		wxButton* Button8;
		wxButton* Button9;
		wxSlider* Slider1;
		wxSlider* Slider2;
		wxSlider* Slider3;
		wxSlider* Slider4;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText12;
		wxStaticText* StaticText13;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* TextCtrl1;
		//*)

	protected:

		//(*Identifiers(MainFrame)
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_BUTTON3;
		static const long ID_STATICTEXT1;
		static const long ID_SLIDER1;
		static const long ID_STATICTEXT10;
		static const long ID_BUTTON4;
		static const long ID_BUTTON5;
		static const long ID_STATICTEXT6;
		static const long ID_STATICTEXT2;
		static const long ID_SLIDER2;
		static const long ID_STATICTEXT11;
		static const long ID_BUTTON6;
		static const long ID_BUTTON7;
		static const long ID_STATICTEXT7;
		static const long ID_STATICTEXT3;
		static const long ID_SLIDER3;
		static const long ID_STATICTEXT12;
		static const long ID_BUTTON8;
		static const long ID_BUTTON9;
		static const long ID_STATICTEXT8;
		static const long ID_STATICTEXT4;
		static const long ID_SLIDER4;
		static const long ID_STATICTEXT13;
		static const long ID_BUTTON10;
		static const long ID_BUTTON11;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT5;
		//*)

	private:

		//(*Handlers(MainFrame)
		void OnButton1Click(wxCommandEvent& event);
		void OnSlider1CmdScroll(wxScrollEvent& event);
		void OnSlider2CmdScroll(wxScrollEvent& event);
		void OnSlider3CmdScroll(wxScrollEvent& event);
		void OnSlider4CmdScroll(wxScrollEvent& event);
		void OnTextCtrl1Text(wxCommandEvent& event);
		void OnChar(wxKeyEvent& event);
		void OnSlider3CmdScroll1(wxScrollEvent& event);
		void OnButton2Click(wxCommandEvent& event);
		void OnButton3Click(wxCommandEvent& event);
		void OnSliderCmdScrollChanged(wxScrollEvent& event);
		void OnSlider4CmdScroll1(wxScrollEvent& event);
		void OnButton11Click(wxCommandEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnButton4Click(wxCommandEvent& event);
		void OnButton5Click(wxCommandEvent& event);
		void OnButton6Click(wxCommandEvent& event);
		void OnButton7Click(wxCommandEvent& event);
		void OnButton8Click(wxCommandEvent& event);
		void OnButton9Click(wxCommandEvent& event);
		void OnButton10Click(wxCommandEvent& event);
		void OnButton11Click1(wxCommandEvent& event);
		void OnTextCtrl1Text1(wxCommandEvent& event);
		void OnSlider1CmdScroll1(wxScrollEvent& event);
		void OnSlider1CmdScroll2(wxScrollEvent& event);
		void OnSlider1CmdScroll3(wxScrollEvent& event);
		void OnSlider4CmdScroll2(wxScrollEvent& event);
		//*)

		DECLARE_EVENT_TABLE()

		C_Radio MyRadio ;

public:
        void UpdateIHM() ;

};

#endif
