#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/combobox.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_combo_box : public control_handler {
      public:
        wx_combo_box(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxComboBox>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, wxEmptyString, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), 0, nullptr, control_handler::combo_box_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
