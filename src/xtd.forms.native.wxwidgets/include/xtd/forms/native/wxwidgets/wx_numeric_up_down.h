#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/up_down_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/spinctrl.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class numeric_up_down;
      class wx_numeric_up_down : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::numeric_up_down;
      private:
        explicit wx_numeric_up_down(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          int32 height = create_params.size.height();
          #if defined(__WXGTK__)
          if (height < 32) height = 32;
          #endif
          control_handler::create<wxSpinCtrlDouble>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), height), style_to_wx_style(create_params.style, create_params.ex_style));
          // Workaround : with wxWidgets version <= 3.1.4 when wxSpinCtrlDouble lost focus the value is changed by error.
          value_ = static_cast<wxSpinCtrlDouble*>(control())->GetValue();
          control()->Bind(wxEVT_SPINCTRLDOUBLE, [&](wxCommandEvent & event) {
            if (!control()) return;
            value_ = static_cast<wxSpinCtrlDouble*>(control())->GetValue();
            refresh_ = true;
          });
          
          control()->Bind(wxEVT_TEXT, [&](wxCommandEvent & event) {
            if (!control()) return;
            value_ = static_cast<wxSpinCtrlDouble*>(control())->GetValue();
            refresh_ = false;
          });
          
          control()->Bind(wxEVT_KILL_FOCUS, [&](wxFocusEvent & event) {
            if (!control()) return;
            if (refresh_) static_cast<wxSpinCtrlDouble*>(control())->SetValue(value_);
          });
          // <-- Workaround
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->GetChildren()[0]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::text_box().r(), xtd::drawing::system_colors::text_box().g(), xtd::drawing::system_colors::text_box().b(), xtd::drawing::system_colors::text_box().a()));
            control()->GetChildren()[0]->SetForegroundColour(wxColour(xtd::drawing::system_colors::text_box_text().r(), xtd::drawing::system_colors::text_box_text().g(), xtd::drawing::system_colors::text_box_text().b(), xtd::drawing::system_colors::text_box_text().a()));
            control()->GetChildren()[1]->SetBackgroundColour(wxColour(xtd::drawing::system_colors::button_face().r(), xtd::drawing::system_colors::button_face().g(), xtd::drawing::system_colors::button_face().b(), xtd::drawing::system_colors::button_face().a()));
            control()->GetChildren()[1]->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & WS_TABSTOP) != WS_TABSTOP) wx_style |= wxTAB_TRAVERSAL;
          if ((style & UDS_WRAP) == UDS_WRAP) wx_style |= wxSP_WRAP;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          return wx_style;
        }
        
        bool refresh_ = true;
        // Workaround : with wxWidgets version <= 3.1.4 when wxSpinCtrlDouble lost focus the value is changed by error.
        double value_ = 0;
      };
    }
  }
}
