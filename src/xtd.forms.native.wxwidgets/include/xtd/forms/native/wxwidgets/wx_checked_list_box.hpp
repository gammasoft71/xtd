#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.hpp"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/list_box_styles>
#include <xtd/argument_exception>
#include <wx/checklst.h>

namespace xtd {
  namespace forms {
    namespace native {
      class checked_list_box;
      class control;
      class wx_checked_list_box : public control_handler {
        friend xtd::forms::native::checked_list_box;
        friend xtd::forms::native::control;
      private:
        explicit wx_checked_list_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t);
          control_handler::create<wxCheckListBox>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x, create_params.location.y), wxSize(0, 0), 0, nullptr, style_to_wx_style(create_params.style, create_params.ex_style));
          // Workaround : with wxWidgets version <= 3.1.4 checked item alignment error on macos...
          static_cast<wxCheckListBox*>(control())->SetPosition({create_params.location.x, create_params.location.y});
          static_cast<wxCheckListBox*>(control())->SetSize(create_params.size.width(), create_params.size.height());
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          if ((style & LBS_EXTENDEDSEL) == LBS_EXTENDEDSEL) wx_style |= wxLB_EXTENDED;
          else if ((style & LBS_MULTIPLESEL) == LBS_MULTIPLESEL) wx_style |= wxLB_MULTIPLE;
          else if ((style & LBS_HASSTRINGS) == LBS_HASSTRINGS) wx_style |= wxLB_SINGLE;
          
          // Do not use wxwidgets sort
          //if ((style & LBS_SORT) == LBS_SORT) wx_style |= wxLB_SORT;
          
          return wx_style | common_window_style_to_wx_style(style, ex_style);
        }
      };
    }
  }
}
