#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Box.H>
#include <FL/Fl_Window.H>

class Fl_Form : public Fl_Window {
public:
  Fl_Form(int x, int y, int w, int h , const char* l = 0) : Fl_Window(x, y, w, h, l) {
    resizable_control_.hide();
    resizable(resizable_control_);
  }
  
  Fl_Box resizable_control_ {10000, 10000, 1, 1, ""};
  int dialog_result_ = 0;
};

namespace xtd {
  namespace forms {
    namespace native {
      class fl_form : public control_handler {
      public:
        fl_form(const xtd::forms::create_params& create_params) {
          this->control_handler::create<Fl_Form>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          this->control()->copy_label(create_params.caption().c_str());
          static_cast<Fl_Group*>(this->control())->end();
        }
      };
    }
  }
}
