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


class MainFrame: public wxFrame
{
	public:

		MainFrame(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~MainFrame();

		//(*Declarations(MainFrame)
		wxButton* Button10;
		wxButton* Button11;
		wxButton* Button12;
		wxButton* Button13;
		wxButton* Button14;
		wxButton* Button15;
		wxButton* Button16;
		wxButton* Button17;
		wxButton* Button18;
		wxButton* Button19;
		wxButton* Button1;
		wxButton* Button20;
		wxButton* Button21;
		wxButton* Button22;
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
		static const long ID_BUTTON3;
		static const long ID_BUTTON2;
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
		static const long ID_BUTTON14;
		static const long ID_BUTTON16;
		static const long ID_BUTTON18;
		static const long ID_BUTTON17;
		static const long ID_BUTTON15;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON13;
		static const long ID_STATICTEXT5;
		static const long ID_STATICTEXT19;
		static const long ID_STATICTEXT14;
		static const long ID_STATICTEXT15;
		static const long ID_STATICTEXT16;
		static const long ID_STATICTEXT17;
		static const long ID_STATICTEXT18;
		static const long ID_BUTTON20;
		static const long ID_STATICTEXT20;
		static const long ID_BUTTON21;
		static const long ID_BUTTON22;
		static const long ID_STATICTEXT22;
		static const long ID_BUTTON12;
		static const long ID_BUTTON19;
		static const long ID_STATICTEXT21;
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
		void OnTextCtrl1Text2(wxCommandEvent& event);
		void OnTextCtrl1Text3(wxCommandEvent& event);
		void OnTextCtrl1Text4(wxCommandEvent& event);
		void OnTextCtrl1Text5(wxCommandEvent& event);
		void OnTextCtrl2Text(wxCommandEvent& event);
		void OnButton13Click(wxCommandEvent& event);
		void OnButton13Click1(wxCommandEvent& event);
		void OnButton12Click(wxCommandEvent& event);
		void OnButton14Click(wxCommandEvent& event);
		void OnButton16Click(wxCommandEvent& event);
		void OnButton17Click(wxCommandEvent& event);
		void OnButton15Click(wxCommandEvent& event);
		void OnButton18Click(wxCommandEvent& event);
		void OnButton20Click(wxCommandEvent& event);
		void OnButton19Click(wxCommandEvent& event);
		void OnButton21Click(wxCommandEvent& event);
		void OnButton22Click(wxCommandEvent& event);
		//*)

		DECLARE_EVENT_TABLE()


public:
        void UpdateIHM() ;
        void SpecialUpdateIHM() ;

};

#endif
