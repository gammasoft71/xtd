#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/progress_bar_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Progress.H>

class Fl_Progress_Bar : public Fl_Progress {
public:
  Fl_Progress_Bar(int x, int y, int w, int h) : Fl_Progress(x, y, w, h) {
    selection_color(FL_SELECTION_COLOR);
  }
  
  ~Fl_Progress_Bar() {
    if (this->marquee_)
      Fl::remove_timeout(on_marquee_timer_tick);
  }
  
  void animation_speed(int animation_speed) {this->animation_speed_ = animation_speed;}
  int animation_speed() const {return animation_speed_;}

  void marquee(bool marquee) {
    this->marquee_ = marquee;
    if (this->marquee_) Fl::add_timeout((double)this->animation_speed_ / 1000, on_marquee_timer_tick, this);
  }
  bool marquee() const {return this->marquee_;}
  
  int marquee_width() const {return this->marquee_width_;}
  void marquee_width(int marquee_width) {this->marquee_width_ = marquee_width;}

  void draw() override {
    this->Fl_Progress::draw();
    if (this->marquee_) {
      draw_box(FL_DOWN_BOX, this->x(), this->y(), this->w(), this->h(), this->color());
      draw_box(FL_FLAT_BOX, this->x() + Fl::box_dw(this->box()) / 2 + marquee_pos_ - 1, this->y() + Fl::box_dh(this->box()) / 2 - 1, this->marquee_width_ - Fl::box_dw(this->box()) + 2, this->h() - Fl::box_dh(this->box()) + 2, this->selection_color());
    }
  }
  
private:
  static void on_marquee_timer_tick(void* progress) {
    if (((Fl_Progress_Bar*)progress)->right_) {
      if (((Fl_Progress_Bar*)progress)->marquee_pos_ < (((Fl_Progress_Bar*)progress)->w() - (2 * Fl::box_dw(((Fl_Progress_Bar*)progress)->box()))) - ((Fl_Progress_Bar*)progress)->marquee_width_)
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ + ((Fl_Progress_Bar*)progress)->marquee_width_;
      else {
        ((Fl_Progress_Bar*)progress)->right_ = false;
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ - ((Fl_Progress_Bar*)progress)->marquee_width_;
      }
    } else {
      if (((Fl_Progress_Bar*)progress)->marquee_pos_ > 0)
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ - ((Fl_Progress_Bar*)progress)->marquee_width_;
      else {
        ((Fl_Progress_Bar*)progress)->right_ = true;
        ((Fl_Progress_Bar*)progress)->marquee_pos_ = ((Fl_Progress_Bar*)progress)->marquee_pos_ + ((Fl_Progress_Bar*)progress)->marquee_width_;
      }
    }

    ((Fl_Progress_Bar*)progress)->redraw();
    if (((Fl_Progress_Bar*)progress)->marquee()) Fl::repeat_timeout((double)((Fl_Progress_Bar*)progress)->animation_speed_ / 1000, on_marquee_timer_tick, progress);
  }
  
  int animation_speed_ = 200;
  bool marquee_ = false;
  int marquee_pos_ = 0;
  int marquee_width_ = 40;
  bool right_ = true;
};

namespace xtd {
  namespace forms {
    namespace native {
      class fl_progress_bar : public control_handler {
      public:
        fl_progress_bar(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Progress_Bar>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
          static_cast<Fl_Progress_Bar*>(this->control())->marquee((create_params.style() & PBS_MARQUEE) == PBS_MARQUEE);
          static_cast<Fl_Group*>(reinterpret_cast<control_handler*>(create_params.parent())->control())->add(this->control());
        }
      };
    }
  }
}
