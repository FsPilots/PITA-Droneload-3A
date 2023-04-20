#ifndef C_WXIMAGEPANEL_H
#define C_WXIMAGEPANEL_H

#include <wx/wx.h>

// les includes pour opencv
#include <opencv2/core.hpp>

class wxImagePanel : public wxPanel
{
public:
    wxImagePanel(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)) ;
    bool SetBitmapFromMat(const cv::Mat& mat );
    void SetXPositionOnPanel( int i_x_position_on_panel ) { m_x_position_on_panel = i_x_position_on_panel ; } // pour donner la position en x � donner � l'image pour la centrer sur le panel
    void SetYPositionOnPanel( int i_y_position_on_panel ) { m_y_position_on_panel = i_y_position_on_panel ; } // pour donner la position en y � donner � l'image pour la centrer sur le panel


private :
    wxBitmap m_bitmap;
    int m_x_position_on_panel ; // la position en x a donner a du coin sup�rieur gauche de l'image pour qu'elle soit centr�e sur la panel
    int m_y_position_on_panel  ; // la position en y a donner a du coin sup�rieur gauche de l'image pour qu'elle soit centr�e sur la panel

    void OnPaint(wxPaintEvent&);
} ;
#endif // C_WXIMAGEPANEL_H
