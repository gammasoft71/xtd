#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Scroll.H>

namespace xtd {
  namespace forms {
    namespace native {
      class fl_user_control : public control_handler {
      public:
        fl_user_control(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Scroll>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          this->control()->copy_label(create_params.caption().c_str());
          static_cast<Fl_Group*>(this->control())->end();
          static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
      };
    }
  }
}
