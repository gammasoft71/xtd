#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <wx/spinbutt.h>
#undef interface
#include "control_handler.hpp"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/up_down_styles>
#include <xtd/argument_exception>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class up_down_button;
      class wx_up_down_button : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::up_down_button;
      private:
        explicit wx_up_down_button(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument, "control must have a parent");
          control_handler::create<wxSpinButton>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x, create_params.location.y), wxSize(create_params.size.width, create_params.size.height), style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & UDS_HORZ) == UDS_HORZ) wx_style |= wxSP_HORIZONTAL;
          if ((style & UDS_WRAP) == UDS_WRAP) wx_style |= wxSP_WRAP;
          
          return wx_style;
        }
      };
    }
  }
}
