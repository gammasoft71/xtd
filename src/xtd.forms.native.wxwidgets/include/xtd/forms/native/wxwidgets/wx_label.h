#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "control_handler.h"
#include "wx_user_window.h"
#include <xtd/drawing/system_colors>
#include <xtd/forms/native/create_params>
#include <xtd/forms/native/static_styles>
#include <xtd/argument_exception>
#include <xtd/convert_string>
#include <wx/panel.h>
#include <wx/stattext.h>

namespace xtd {
  namespace forms {
    namespace native {
      class control;
      class label;
      class wx_label : public control_handler {
        friend xtd::forms::native::control;
        friend xtd::forms::native::label;
      private:
        explicit wx_label(const xtd::forms::native::create_params& create_params) {
          if (!create_params.parent) throw xtd::argument_exception("control must have a parent"_t, csf_);
          owner_draw_ = (create_params.style & SS_OWNERDRAW) == SS_OWNERDRAW;
          if (owner_draw_) control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), common_control_style_to_wx_style(create_params.style, create_params.ex_style));
          else control_handler::create<wxStaticText>(reinterpret_cast<control_handler*>(create_params.parent)->main_control(), wxID_ANY, wxString(xtd::convert_string::to_wstring(create_params.caption)), wxPoint(create_params.location.x(), create_params.location.y()), wxSize(create_params.size.width(), create_params.size.height()), style_to_wx_style(create_params.style, create_params.ex_style));
          #if defined(__WXMSW__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
          #endif
          text_ = wxString(xtd::convert_string::to_wstring(create_params.caption));
          
          if (!owner_draw_) {
            control()->Bind(wxEVT_SIZE, [&](wxSizeEvent & e) {
              if ((static_cast<wxStaticText*>(control())->GetWindowStyle() & wxST_ELLIPSIZE_END) != wxST_ELLIPSIZE_END) {
                static_cast<wxStaticText*>(control())->SetLabel(text_);
                static_cast<wxStaticText*>(control())->Wrap(e.GetSize().GetWidth());
              }
            });
          }
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = common_control_style_to_wx_style(style, ex_style);
          
          wx_style |= wxST_NO_AUTORESIZE;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;
          
          if ((style & SS_CENTER) == SS_CENTER) wx_style |= wxALIGN_CENTRE_HORIZONTAL;
          else if ((style & SS_RIGHT) == SS_RIGHT) wx_style |= wxALIGN_RIGHT;
          else wx_style |= wxALIGN_LEFT;
          
          if ((style & SS_VCENTER) == SS_VCENTER) wx_style |= wxALIGN_CENTRE_VERTICAL;
          else if ((style & SS_RIGHT) == SS_BOTTOM) wx_style |= wxALIGN_BOTTOM;
          else wx_style |= wxALIGN_TOP;
          
          if ((style & SS_ENDELLIPSIS) == SS_ENDELLIPSIS) wx_style |= wxST_ELLIPSIZE_END;
          
          return wx_style;
        }
        
        
        void SetLabel(const wxString& label) override  {
          text_ = label;
          control_handler::SetLabel(label);
        }
        
        
        bool owner_draw_ = false;
        wxString text_;
      };
    }
  }
}
