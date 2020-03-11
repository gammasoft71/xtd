#pragma once
#include <codecvt>
#include <stdexcept>
#include <xtd/forms/create_params.h>
#include <xtd/forms/native/up_down_styles.h>
#include <wx/spinbutt.h>
#include "control_handler.h"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_up_down_button : public control_handler {
      public:
        wx_up_down_button(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxSpinButton>(reinterpret_cast<control_handler*>(create_params.parent())->container(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;

          if ((style & UDS_HORZ) == UDS_HORZ) wx_style |= wxSP_HORIZONTAL;
          if ((style & UDS_WRAP) == UDS_WRAP) wx_style |= wxSP_WRAP;

          return wx_style;
        }
      };
    }
  }
}
