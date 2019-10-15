#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/panel.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_user_control : public control_handler {
      public:
        wx_user_control(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxPanel>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), style_to_wx_style(create_params.style(), create_params.ex_style()));
          this->control()->SetSize(create_params.width(), create_params.height());
        }
        
        static long style_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = wxST_NO_AUTORESIZE;
          
          if ((style & WS_BORDER) == WS_BORDER) wx_style |= wxBORDER_SIMPLE;
          else if ((ex_style & WS_EX_CLIENTEDGE) == WS_EX_CLIENTEDGE) wx_style |= wxBORDER_THEME;
          else wx_style |= wxBORDER_NONE;

          return wx_style;
        }
      };
    }
  }
}
