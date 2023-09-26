#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler"
#include "wx_user_window"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/button_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/platform.h>
#include <wx/radiobut.h>
#include <wx/tglbtn.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class switch_button;
      class wx_switch_button : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::switch_button;
      private:
        explicit wx_switch_button(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          owner_draw_ = (create_params.style & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()));
            #if defined(__WXOSX__)
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(false);
            #else
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(true);
            #endif
          } else
            control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
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
