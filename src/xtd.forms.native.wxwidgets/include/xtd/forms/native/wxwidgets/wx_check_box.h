#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include "wx_user_window.h"
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/button_states>
#include <xtd/forms/native/button_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/checkbox.h>
#include <wx/platform.h>
#include <wx/tglbtn.h>

namespace xtd {
  namespace forms {
    namespace native {
      class check_box;
      class control;
      class wx_check_box : public control_handler {
        friend xtd::forms::native::check_box;
        friend xtd::forms::native::control;
      private:
        explicit wx_check_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          owner_draw_ = (create_params.style & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()));
            #if defined(__WXOSX__)
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(false);
            #else
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(true);
            #endif
          } else if ((create_params.style & BS_PUSHLIKE) == BS_PUSHLIKE) control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), 0);
          else control_handler::create<wxCheckBox>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxCHK_3STATE;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & BS_AUTO3STATE) == BS_AUTO3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;
          else if ((style & BS_3STATE) == BS_3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;
          
          if ((style & BS_RIGHTBUTTON) == BS_RIGHTBUTTON) wx_style |= wxALIGN_RIGHT;
          
          return wx_style;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32 width, int32 height) override {
          control()->SetSize(width, height);
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
