#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/button_states.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/checkbox.h>
#include <wx/platform.h>
#include <wx/tglbtn.h>
#include "control_handler.h"
#include "wx_user_window.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_check_box : public control_handler {
      public:
        wx_check_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          owner_draw_ = (create_params.style() & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh");
          } else if ((create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE) control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else control_handler::create<wxCheckBox>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxCHK_3STATE;
          
          if ((style & BS_AUTO3STATE) == BS_AUTO3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;
          else if ((style & BS_3STATE) == BS_3STATE) wx_style |= wxCHK_ALLOW_3RD_STATE_FOR_USER;

          if ((style & BS_RIGHTBUTTON) == BS_RIGHTBUTTON) wx_style |= wxALIGN_RIGHT;

          return wx_style;
        }
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          control()->SetSize(width, height);
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
