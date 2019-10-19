#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Check_Button.H>

class Fl_Check_Box : public Fl_Check_Button {
public:
  Fl_Check_Box(int x, int y, int w, int h, const char* l = 0) : Fl_Check_Button(x, y, w, h, l) {}
  
  void indeterminate(bool i) {this->i = i;}
  bool indeterminate() const {return this->i;}
  
  void draw() override {
    this->Fl_Check_Button::draw();
    if (this->i) draw_box(FL_FLAT_BOX, this->x() + 5, this->y() + (this->h() - 14) / 2 + 3, 8, 8, FL_FOREGROUND_COLOR);
  }
  
private:
  bool i = false;
};

namespace xtd {
  namespace forms {
    namespace native {
      class fl_check_box : public control_handler {
      public:
        fl_check_box(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Check_Box>(create_params.x(), create_params.y(), create_params.width(), create_params.height(), create_params.caption().c_str());
        }
      };
    }
  }
}
