#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/list_box_styles.h>
#include <wx/listbox.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class list_box;
      class wx_list_box : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::list_box;
      private:
        wx_list_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, current_stack_frame_);
          control_handler::create<wxListBox>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0, nullptr, style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          if ((style & LBS_EXTENDEDSEL) == LBS_EXTENDEDSEL) wx_style |= wxLB_EXTENDED;
          else if ((style & LBS_MULTIPLESEL) == LBS_MULTIPLESEL) wx_style |= wxLB_MULTIPLE;
          else if ((style & LBS_HASSTRINGS) == LBS_HASSTRINGS) wx_style |= wxLB_SINGLE;
          
          // Do not use wxwidgets sort
          //if ((style & LBS_SORT) == LBS_SORT) wx_style |= wxLB_SORT;
          
          return wx_style;
        }
      };
    }
  }
}
