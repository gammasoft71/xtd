#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include "wx_user_window.h"
#include <xtd/drawing/system_colors>
#include <xtd/drawing/system_images>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/application>
#include <xtd/forms/native/button_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <xtd/environment>
#include <wx/commandlinkbutton.h>
#include <wx/platform.h>

namespace xtd {
  namespace forms {
    namespace native {
      class command_link_button;
      class control;
      class wx_command_link_button : public control_handler {
        friend xtd::forms::native::command_link_button;
        friend xtd::forms::native::control;
      private:
        explicit wx_command_link_button(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          owner_draw_ = (create_params.style & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_user_window_style(create_params.style, create_params.ex_style));
            #if defined(__WXOSX__)
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(false);
            #else
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(true);
            #endif
            
          } else {
            control_handler::create<wxCommandLinkButton>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxEmptyString, wxEmptyString, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
            static_cast<wxCommandLinkButton*>(control())->SetLabel(wxString(xtd::convert_string::to_wstring(create_params.caption)));
            if (!xtd::environment::os_version().is_windows_platform() || (xtd::environment::os_version().is_windows_platform() && application::dark_mode_enabled()))
              static_cast<wxCommandLinkButton*>(control())->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(xtd::drawing::system_images::from_name("go-next", xtd::drawing::size(16, 16)).handle())));
            static_cast<wxCommandLinkButton*>(control())->SetPosition(wxPoint(create_params.location.x(), create_params.location.y()));
          }
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & BS_VCENTER) != BS_VCENTER) {
            if ((style & BS_TOP) == BS_TOP) wx_style |= wxBU_TOP;
            else if ((style & BS_BOTTOM) == BS_BOTTOM) wx_style |= wxBU_BOTTOM;
          }
          if ((style & BS_CENTER) != BS_CENTER) {
            if ((style & BS_LEFT) == BS_LEFT) wx_style |= wxBU_LEFT;
            else if ((style & BS_RIGHT) == BS_RIGHT) wx_style |= wxBU_RIGHT;
          }
          
          return wx_style;
        }
        
        static long style_to_wx_user_window_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }

        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32 width, int32 height) override {
          SetSize(width, height);
        }
        
        void SetSize(int32 width, int32 height) override {
          control_handler::SetSize(width, height);
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
