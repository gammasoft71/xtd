#pragma once
#include <xtd/argument_exception.h>
#include <xtd/environment.h>
#include <xtd/drawing/system_images.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/button_styles.h>
#include <wx/commandlinkbutton.h>
#include <wx/platform.h>
#include "control_handler.h"
#include "wx_user_window.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_command_link_button : public control_handler {
      public:
        wx_command_link_button(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          owner_draw_ = (create_params.style() & BS_OWNERDRAW) == BS_OWNERDRAW;
          if (owner_draw_) {
            control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
            reinterpret_cast<wx_user_window*>(control())->set_accepts_focus(wxPlatformInfo::Get().GetOperatingSystemFamilyName() != "Macintosh");
          } else {
            control_handler::create<wxCommandLinkButton>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxEmptyString, wxEmptyString, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
            static_cast<wxCommandLinkButton*>(control())->SetLabel(wxString(create_params.caption().c_str(), wxMBConvUTF8()));
            if (!xtd::environment::os_version().is_windows_platform() || (xtd::environment::os_version().is_windows_platform() && application::dark_mode_enabled()))
              static_cast<wxCommandLinkButton*>(control())->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(xtd::drawing::system_images::from_name("go-next", xtd::drawing::size(16, 16)).handle())));
          }
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
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
        
        wxSize GetClientSize() const override {
          return control()->GetSize();
        }
        
        void SetClientSize(int32_t width, int32_t height) override {
          SetSize(width, height);
        }

        void SetSize(int32_t width, int32_t height) override {
          control_handler::SetSize(width, height);
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
