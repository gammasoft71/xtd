#pragma once
#include <xtd/forms/create_params.hpp>
#include <wx/statbox.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_group_box : public control_handler {
      public:
        wx_group_box(const forms::create_params& create_params) {
          this->control_handler::create<wxStaticBox>(reinterpret_cast<control_handler*>(create_params.parent())->control(), wxID_ANY, create_params.caption(), wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::group_box_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
