#pragma once
#include <codecvt>
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/up_down_styles.h>
#include <wx/spinctrl.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_numeric_up_down : public control_handler {
      public:
        wx_numeric_up_down(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          int32_t height = create_params.height();
#if defined(__WXGTK__)
          if (height < 32) height = 32;
#endif
          this->control_handler::create<wxSpinCtrlDouble>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxString(create_params.caption().c_str(), wxMBConvUTF8()), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), height), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          if ((style & UDS_WRAP) == UDS_WRAP) wx_style |= wxSP_WRAP;

          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_DEFAULT;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          return wx_style;
        }
      };
    }
  }
}
