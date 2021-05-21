#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/choice.h>
#include <wx/choice.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_choice : public control_handler {
      public:
        wx_choice(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
#if defined(__WXMSW__)
          int32_t height = 23;
#elif defined(__WXGTK__)
          int32_t height = 32;
#else
          int32_t height = 23;
#endif
          control_handler::create<wxChoice>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), height), 0, nullptr, style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          // Do not use wxwidgets sort
          //if ((style & CBS_SORT) == CBS_SORT) wx_style |= wxCB_SORT;
          
          return wx_style;
        }
      };
    }
  }
}
