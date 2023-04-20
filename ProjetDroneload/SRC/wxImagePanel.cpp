#include "wxImagePanel.h"

#include <wx/wx.h>
#include <wx/panel.h>
#include <wx/dcbuffer.h>
#include "convertmattowxbmp.h"


wxImagePanel::wxImagePanel(wxWindow *parent, wxWindowID winid , const wxPoint& pos , const wxSize& size , long style , const wxString& name ) : wxPanel ( parent, winid, pos, size, style,name )
{

    SetBackgroundColour(*wxBLACK);
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    m_x_position_on_panel = 0 ;
    m_y_position_on_panel = 0 ;

    Bind(wxEVT_PAINT, &wxImagePanel::OnPaint, this);
}


bool wxImagePanel::SetBitmapFromMat(const cv::Mat& mat )
{

    wxBitmap tmp_bitmap( mat.cols, mat.rows, 24 );

    ConvertMatBitmapTowxBitmap( mat, tmp_bitmap );

    if ( tmp_bitmap.IsOk() )
    {
        if (tmp_bitmap.GetSize() != GetVirtualSize() )
        {
            InvalidateBestSize();
            SetVirtualSize(tmp_bitmap.GetSize());
        }
    }
    else
    {
        InvalidateBestSize();
        SetVirtualSize(1, 1);
    }

    m_bitmap = tmp_bitmap ;

    Refresh();
    Update();
    return true;
};


// Méthode appellée à chaque éventement de type wxEVT_PAINT
void wxImagePanel::OnPaint(wxPaintEvent&)
{
    wxAutoBufferedPaintDC dc(this);

    dc.Clear();

    if ( ! m_bitmap.IsOk() )
        return;

    dc.DrawBitmap(m_bitmap, m_x_position_on_panel, m_y_position_on_panel, false);

}

