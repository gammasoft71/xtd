#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/loading_indicator_styles.h>
#include <wx/panel.h>
#include <wx/activityindicator.h>
#include "control_handler.h"
#include "wx_user_window.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class loading_indicator;
      class wx_loading_indicator : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::loading_indicator;
      private:
        wx_loading_indicator(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          owner_draw_ = (create_params.style() & LI_OWNERDRAW) == LI_OWNERDRAW;
          if (owner_draw_) control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()));
          else control_handler::create<wxActivityIndicator>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
