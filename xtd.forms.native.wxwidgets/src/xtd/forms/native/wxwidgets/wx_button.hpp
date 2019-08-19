#pragma once
#include <xtd/forms/create_params.hpp>
#include <wx/button.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_button : public control_handler {
      public:
        wx_button(const xtd::forms::create_params& create_params) {
          this->control_handler::create<wxButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), button_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
