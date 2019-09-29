#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/button.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_button : public control_handler {
      public:
        wx_button(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), button_to_wx_style(create_params.style(), create_params.ex_style()));
        }
        
        static long button_to_wx_style(size_t style, size_t ex_style) {
          long wx_style = 0;
          
          if ((style & BS_TOP) == BS_TOP) wx_style |= wxBU_TOP;
          if ((style & BS_BOTTOM) == BS_BOTTOM) wx_style |= wxBU_BOTTOM;
          if ((style & BS_LEFT) == BS_LEFT) wx_style |= wxBU_LEFT;
          if ((style & BS_RIGHT) == BS_RIGHT) wx_style |= wxBU_RIGHT;

          return wx_style; // | common_window_style_to_wx_style(style, ex_style);
        }
      };
    }
  }
}
