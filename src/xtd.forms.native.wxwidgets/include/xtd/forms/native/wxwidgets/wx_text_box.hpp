#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.hpp"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/edit_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/textctrl.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class text_box;
      class wx_text_box : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::text_box;
      private:
        enum class character_casing {normal, upper, lower};
        explicit wx_text_box(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t);
          int32 height = create_params.size.height();
          #if defined(__WXGTK__)
          if (height < 32) height = 32;
          #endif
          control_handler::create<wxTextCtrl>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x, create_params.location.y), wxSize(create_params.size.width(), height), style_to_wx_style(create_params.style, create_params.ex_style, character_casing_));
          if (character_casing_ != character_casing::normal) {
            control()->Bind(wxEVT_CHAR, [&](wxKeyEvent & event) {
              switch (character_casing_) {
                case character_casing::normal: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", event.GetUnicodeKey())); break;
                case character_casing::upper: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", std::toupper(event.GetUnicodeKey()))); break;
                case character_casing::lower: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", std::tolower(event.GetUnicodeKey()))); break;
              }
            });
            
            switch (character_casing_) {
              case character_casing::upper: static_cast<wxTextCtrl*>(control())->SetValue(wxString(xtd::convert_string::to_wstring(create_params.caption.to_upper()))); break;
              case character_casing::lower: static_cast<wxTextCtrl*>(control())->SetValue(wxString(xtd::convert_string::to_wstring(create_params.caption.to_lower()))); break;
              default: break;
            }
          }
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::text_box().r(), xtd::drawing::system_colors::text_box().g(), xtd::drawing::system_colors::text_box().b(), xtd::drawing::system_colors::text_box().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::text_box_text().r(), xtd::drawing::system_colors::text_box_text().g(), xtd::drawing::system_colors::text_box_text().b(), xtd::drawing::system_colors::text_box_text().a()));
          }
          #endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style, character_casing& casing) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          if ((style & ES_MULTILINE) == ES_MULTILINE) wx_style |= wxTE_MULTILINE;
          if ((style & ES_PASSWORD) == ES_PASSWORD) wx_style |= wxTE_PASSWORD;
          if ((style & ES_READONLY) == ES_READONLY) wx_style |= wxTE_READONLY;
          if ((style & ES_MULTILINE) == ES_MULTILINE && (style & ES_AUTOHSCROLL) == ES_AUTOHSCROLL) wx_style |= wxTE_DONTWRAP;
          if ((style & ES_WANTRETURN) == ES_WANTRETURN) wx_style |= wxTE_PROCESS_ENTER;
          if ((style & ES_WANTTAB) == ES_WANTTAB) wx_style |= wxTE_PROCESS_TAB;
          if ((style & ES_UPPERCASE) == ES_UPPERCASE) casing = character_casing::upper;
          if ((style & ES_LOWERCASE) == ES_LOWERCASE) casing = character_casing::lower;
          
          return wx_style;
        }
        
        character_casing character_casing_ = character_casing::normal;
      };
    }
  }
}
