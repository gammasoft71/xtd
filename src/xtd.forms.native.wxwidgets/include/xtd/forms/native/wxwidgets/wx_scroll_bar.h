#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/scroll_bar_styles>
#include <xtd/argument_exception>
#include <wx/scrolbar.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class scroll_bar;
      class wx_scroll_bar : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::scroll_bar;
      private:
        explicit wx_scroll_bar(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          control_handler::create<wxScrollBar>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), (create_params.style & SBS_VERT) == SBS_VERT ? wxSB_VERTICAL : wxSB_HORIZONTAL);
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        int32 large_change_ = 1;
        int32 minimum_ = 0;
        int32 maximum_ = 100;
        int32 small_change_ = 1;
        int32 value_ = 0;
      };
    }
  }
}
