#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/checkbox.h>
#include <wx/tglbtn.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_check_box : public control_handler {
      public:
        wx_check_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          if ((create_params.style() & BS_PUSHLIKE) == BS_PUSHLIKE)
            this->control_handler::create<wxToggleButton>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0);
          else
            this->control_handler::create<wxCheckBox>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::check_box_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
