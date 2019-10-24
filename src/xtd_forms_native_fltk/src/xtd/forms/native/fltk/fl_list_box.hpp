#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/list_box_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Browser.H>

namespace xtd {
  namespace forms {
    namespace native {
      class fl_list_box : public control_handler {
      public:
        fl_list_box(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Browser>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          if ((create_params.style() & LBS_NOSEL) == LBS_NOSEL) static_cast<Fl_Browser*>(this->control())->type(FL_NORMAL_BROWSER);
          else if ((create_params.style() & LBS_MULTIPLESEL) == LBS_MULTIPLESEL) static_cast<Fl_Browser*>(this->control())->type( FL_MULTI_BROWSER);
          else if ((create_params.style() & LBS_EXTENDEDSEL) == LBS_EXTENDEDSEL) static_cast<Fl_Browser*>(this->control())->type( FL_MULTI_BROWSER);
          else static_cast<Fl_Browser*>(this->control())->type( FL_HOLD_BROWSER);
          static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
            
          bool sorted() const {return this->sorted_;}
            
        private:
          bool sorted_ = false;
      };
    }
  }
}
