#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/combo_box_styles>
#include <xtd/argument_exception>
#include <wx/combobox.h>

namespace xtd {
  namespace forms {
    namespace native {
      class combo_box;
      class control;
      class wx_combo_box : public control_handler {
        friend xtd::forms::native::combo_box;
        friend xtd::forms::native::control;
      private:
        explicit wx_combo_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          #if defined(__WXMSW__)
          int32 height = (create_params.style & CBS_SIMPLE) == CBS_SIMPLE ? 163 : 23;
          #elif defined(__WXGTK__)
          int32 height = 34;
          #else
          int32 height = 26;
          #endif
          control_handler::create<wxComboBox>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxEmptyString, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), height), 0, nullptr, style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::window().r(), xtd::drawing::system_colors::window().g(), xtd::drawing::system_colors::window().b(), xtd::drawing::system_colors::window().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::window_text().r(), xtd::drawing::system_colors::window_text().g(), xtd::drawing::system_colors::window_text().b(), xtd::drawing::system_colors::window_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          // Do not use wxwidgets sort
          //if ((style & CBS_SORT) == CBS_SORT) wx_style |= wxCB_SORT;
          
          if ((style & CBS_DROPDOWNLIST) == CBS_DROPDOWNLIST) wx_style |= wxCB_READONLY;
          else if ((style & CBS_DROPDOWN) == CBS_DROPDOWN) wx_style |= wxCB_DROPDOWN;
          else if ((style & CBS_SIMPLE) == CBS_SIMPLE) wx_style |= wxCB_SIMPLE;
          
          return wx_style;
        }
      };
    }
  }
}
