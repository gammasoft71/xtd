#pragma once
#include <wx/panel.h>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_user_window : public wxPanel {
      public:
        wx_user_window() = default;
        wx_user_window(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)) : wxPanel(parent, winid, pos, size, style, name) {}
        
        void set_accepts_focus(bool acceps_focus) {accepts_focus_ = acceps_focus;}
        
        bool AcceptsFocus() const override {return accepts_focus_;}
        
        bool AcceptsFocusFromKeyboard() const override {return accepts_focus_;}
        
      private:
        bool accepts_focus_ = false;
      };
    }
  }
}
