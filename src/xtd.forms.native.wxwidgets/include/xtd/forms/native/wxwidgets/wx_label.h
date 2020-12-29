#pragma once
#include <codecvt>
#include <xtd/argument_exception.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/static_styles.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include "control_handler.h"
#include "wx_user_window.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_label : public control_handler {
      public:
        wx_label(const forms::create_params& create_params) {
          if (!create_params.parent()) throw xtd::argument_exception("control must have a parent"_t, caller_info_);
          owner_draw_ = (create_params.style() & SS_OWNERDRAW) == SS_OWNERDRAW;
          if (owner_draw_) control_handler::create<wx_user_window>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          else control_handler::create<wxStaticText>(reinterpret_cast<control_handler*>(create_params.parent())->main_control(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
#if defined(__WIN32__)
          if (xtd::drawing::system_colors::window().get_lightness() < 0.5) {
            control()->SetBackgroundColour(wxColour(xtd::drawing::system_colors::control().r(), xtd::drawing::system_colors::control().g(), xtd::drawing::system_colors::control().b(), xtd::drawing::system_colors::control().a()));
            control()->SetForegroundColour(wxColour(xtd::drawing::system_colors::control_text().r(), xtd::drawing::system_colors::control_text().g(), xtd::drawing::system_colors::control_text().b(), xtd::drawing::system_colors::control_text().a()));
          }
#endif
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxST_NO_AUTORESIZE;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          if ((style & SS_CENTER) == SS_CENTER) wx_style |= wxALIGN_CENTRE_HORIZONTAL;
          else if ((style & SS_RIGHT) == SS_RIGHT) wx_style |= wxALIGN_RIGHT;
          else wx_style |= wxALIGN_LEFT;

          if ((style & SS_VCENTER) == SS_VCENTER) wx_style |= wxALIGN_CENTRE_VERTICAL;
          else if ((style & SS_RIGHT) == SS_BOTTOM) wx_style |= wxALIGN_BOTTOM;
          else wx_style |= wxALIGN_TOP;

          return wx_style;
        }
        
        bool owner_draw_ = false;
      };
    }
  }
}
