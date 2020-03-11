#pragma once
#include <codecvt>
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/static_styles.h>
#include <wx/stattext.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_label : public control_handler {
      public:
        wx_label(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxStaticText>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
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
      };
    }
  }
}
