#pragma once
#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/edit_styles.h>
#include <xtd/strings.h>
#include <wx/textctrl.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_text_box : public control_handler {
      public:
        enum class character_casing {normal, upper, lower};
        wx_text_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          int32_t height = create_params.height();
#if defined(__WXGTK__)
          if (height < 32) height = 32;
#endif
          control_handler::create<wxTextCtrl>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), height), style_to_wx_style(create_params.style(), create_params.ex_style(), character_casing_));
          if (character_casing_ != character_casing::normal) {
            control()->Bind(wxEVT_CHAR, [&](wxKeyEvent& event) {
              switch (character_casing_) {
                case character_casing::normal: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", event.GetUnicodeKey())); break;
                case character_casing::upper: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", std::toupper(event.GetUnicodeKey()))); break;
                case character_casing::lower: static_cast<wxTextCtrl*>(control())->WriteText(wxString::Format("%c", std::tolower(event.GetUnicodeKey()))); break;
              }
            });

            switch (character_casing_) {
              case character_casing::upper: static_cast<wxTextCtrl*>(control())->SetValue(wxString(xtd::strings::to_upper(create_params.caption()).c_str(), wxMBConvUTF8())); break;
              case character_casing::lower: static_cast<wxTextCtrl*>(control())->SetValue(wxString(xtd::strings::to_lower(create_params.caption()).c_str(), wxMBConvUTF8())); break;
              default: break;
            }
          }
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::text_box().r(), xtd::drawing::system_colors::text_box().g(), xtd::drawing::system_colors::text_box().b(), xtd::drawing::system_colors::text_box().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::text_box_text().r(), xtd::drawing::system_colors::text_box_text().g(), xtd::drawing::system_colors::text_box_text().b(), xtd::drawing::system_colors::text_box_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style, character_casing& casing) {
          long wx_style = 0;
          
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
