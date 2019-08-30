#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <wx/stattext.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_label : public control_handler {
      public:
        wx_label(const forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<wxStaticText>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::label_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
