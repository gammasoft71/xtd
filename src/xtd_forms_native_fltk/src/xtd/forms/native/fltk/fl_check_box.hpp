#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Group.H>

static constexpr int FL_CHECK_BOX_UNCHECKED = 0;
static constexpr int FL_CHECK_BOX_CHECKED = 1;
static constexpr int FL_CHECK_BOX_INDETERMINATE = 2;

class Fl_Check_Box : public Fl_Check_Button {
public:
  Fl_Check_Box(int x, int y, int w, int h, const char* l = 0) : Fl_Check_Button(x, y, w, h, l) {toggle_button(false);}
  
  bool autocheck() const {return autocheck_;}
  void autocheck(bool autocheck) {autocheck_ = autocheck;}
  
  bool three_state() const {return three_state_;}
  void three_state(bool three_state) {three_state_ = three_state;}
  
  bool toggle_button() const {return toggle_button_;}
  void toggle_button(bool toggle_button) {
    toggle_button_ = toggle_button;
    if (toggle_button_) {
      box(FL_UP_BOX);
      down_box(FL_NO_BOX);
      color(FL_BACKGROUND_COLOR);
      selection_color(FL_BACKGROUND_COLOR);
      align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE);
    } else {
      color(FL_BACKGROUND_COLOR);
      selection_color(FL_FOREGROUND_COLOR);
      align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    }
  }

  int state() const {return state_;}
  void state(int state) {
    if (this->state_ != state) {
      state_ = state > 2 ? 2 : state;
      value(state != 0);
      set_changed();
      if (when() & FL_WHEN_CHANGED) this->do_callback();
    }
  }

  int handle (int event) override {
    if (event == FL_PUSH || event == FL_DRAG) return true;
    if (event == FL_RELEASE || (event == FL_KEYBOARD && Fl::focus() == this && Fl::event_key() == ' ' && !(Fl::event_state() & (FL_SHIFT | FL_CTRL | FL_ALT | FL_META)))) {
      if (autocheck_) {
        state(state() < (three_state() ? FL_CHECK_BOX_INDETERMINATE : FL_CHECK_BOX_CHECKED) ? state() + 1 : 0);
        redraw();
      }
      if (when() & FL_WHEN_RELEASE) this->do_callback();
      return true;
    }
    return this->Fl_Check_Button::handle(event);
  }
  
  void draw() override {
    if (toggle_button() == true)
      this->Fl_Button::draw();
    else {
      this->Fl_Check_Button::draw();
      if (this->state() == FL_CHECK_BOX_INDETERMINATE && toggle_button() == false)
        draw_box(FL_FLAT_BOX, this->x() + 5, this->y() + (this->h() - 14) / 2 + 3, 8, 8, selection_color());
    }
  }
  
private:
  using Fl_Check_Button::value;
  bool autocheck_ = true;
  bool toggle_button_ = false;
  int state_ = FL_CHECK_BOX_UNCHECKED;
  bool three_state_ = false;
};

namespace xtd {
  namespace forms {
    namespace native {
      class fl_check_box : public control_handler {
      public:
        fl_check_box(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Check_Box>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          this->control()->copy_label(create_params.caption().c_str());
          static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
      };
    }
  }
}
