#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Group.H>
#include <FL/Fl_Slider.H>

namespace xtd {
  namespace forms {
    namespace native {
      class fl_track_bar : public control_handler {
      public:
        fl_track_bar(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Slider>(create_params.x(), create_params.y(), create_params.width(), create_params.height(), create_params.caption().c_str());
          reinterpret_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
      };
    }
  }
}
