#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <wx/panel.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      template<typename control_t>
      class control_wrapper;
      class user_window;
      class wx_button;
      class wx_check_box;
      class wx_command_link_button;
      class wx_radio_button;
      class wx_switch_button;
      class wx_toggle_button;
      class wx_user_window : public wxPanel {
      public:
        wx_user_window() = default;
      private:
        friend xtd::forms::native::control;
        template<typename control_t>
        friend class control_wrapper;
        friend xtd::forms::native::user_window;
        friend xtd::forms::native::wx_button;
        friend xtd::forms::native::wx_check_box;
        friend xtd::forms::native::wx_command_link_button;
        friend xtd::forms::native::wx_radio_button;
        friend xtd::forms::native::wx_switch_button;
        friend xtd::forms::native::wx_toggle_button;

        wx_user_window(wxWindow *parent, wxWindowID winid = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxTAB_TRAVERSAL | wxNO_BORDER, const wxString& name = wxASCII_STR(wxPanelNameStr)) : wxPanel(parent, winid, pos, size, style, name) {}
        
        void set_accepts_focus(bool accepts_focus) {accepts_focus_ = accepts_focus;}
        
        bool AcceptsFocus() const override {return accepts_focus_;}
        
        bool AcceptsFocusFromKeyboard() const override {return accepts_focus_;}
        
      private:
        bool accepts_focus_ = false;
      };
    }
  }
}
