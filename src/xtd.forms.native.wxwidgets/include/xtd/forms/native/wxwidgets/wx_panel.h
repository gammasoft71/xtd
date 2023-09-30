#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/argument_exception>
#include <wx/panel.h>
#include <wx/scrolwin.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class panel;
      class wx_panel : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::panel;
      private:
        explicit wx_panel(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          if ((create_params.ex_style & WS_EX_AUTOSCROLL) == WS_EX_AUTOSCROLL)
            control_handler::create<wxScrolled<wxPanel>>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          else
            control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
          control()->SetSize(create_params.size.width(), create_params.size.height());
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & WS_HSCROLL) == WS_HSCROLL) wx_style |= wxHSCROLL;
          if ((style & WS_VSCROLL) == WS_VSCROLL) wx_style |= wxVSCROLL;
          if (((style & WS_HSCROLL) == WS_HSCROLL || (style & WS_VSCROLL) == WS_VSCROLL) && (ex_style & WS_EX_AUTOSCROLL) != WS_EX_AUTOSCROLL) wx_style |= wxALWAYS_SHOW_SB;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
      };
    }
  }
}
