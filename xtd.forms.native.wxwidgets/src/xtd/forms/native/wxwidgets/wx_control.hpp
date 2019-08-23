#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/xtd.diagnostics>
#include <wx/control.h>
#include "control_handler.hpp"

namespace xtd {
  namespace forms {
    namespace native {
      class wx_control : public control_handler {
      public:
        wx_control(const forms::create_params& create_params) {
          cdebug << "Native check create_parm" << std::endl;
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          cdebug << "Native create control" << std::endl;
          this->create<wxControl>(((control_handler*)create_params.parent())->control(), wxID_ANY, wxPoint(create_params.x(), create_params.y()), wxSize(create_params.width(), create_params.height()), control_handler::control_to_wx_style(create_params.style(), create_params.ex_style()));
        }
      };
    }
  }
}
