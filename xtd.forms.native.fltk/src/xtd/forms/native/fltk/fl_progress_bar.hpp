#pragma once
#include <stdexcept>
#include <xtd/forms/create_params.hpp>
#include <xtd/forms/native/button_styles.hpp>
#include "control_handler.hpp"
#include <FL/Fl_Progress.H>

class Fl_Progress_Bar : public Fl_Progress {
public:
  Fl_Progress_Bar(int x, int y, int w, int h) : Fl_Progress(x, y, w, h) {}
  
  void marquee(bool m) {
    this->m = m;
    if (this->m) Fl::add_timeout(0.2, OnMarqueeTimerTick, this);
  }
  bool marquee() const {return this->m;}
  
  void draw() override {
    this->Fl_Progress::draw();
    if (this->marquee()) {
      draw_box(FL_FLAT_BOX, this->x()+2, this->y() + 2, this->w() - 4, this->h() - 4, this->color());
      draw_box(FL_FLAT_BOX, this->x()+2 + marquee_pos, this->y() + 2, (this->w() - 4) / 10, this->h() - 4, this->selection_color());
    }
  }
  
private:
  static void OnMarqueeTimerTick(void* progress) {
    ((Fl_Progress_Bar*)progress)->marquee_pos = ((Fl_Progress_Bar*)progress)->marquee_pos < (((Fl_Progress_Bar*)progress)->w() - ((((Fl_Progress_Bar*)progress)->w() - 4) / 10)) ? ((Fl_Progress_Bar*)progress)->marquee_pos + ((((Fl_Progress_Bar*)progress)->w() - 4) / 10) : 0;
    ((Fl_Progress_Bar*)progress)->redraw();
    if (((Fl_Progress_Bar*)progress)->marquee()) Fl::repeat_timeout(0.2, OnMarqueeTimerTick, progress);
  }
  
  bool m= false;
  int marquee_pos = 0;
};

namespace xtd {
  namespace forms {
    namespace native {
      class fl_progress_bar : public control_handler {
      public:
        fl_progress_bar(const xtd::forms::create_params& create_params) {
          if (!create_params.parent()) throw std::invalid_argument("control must have a parent");
          this->control_handler::create<Fl_Progress_Bar>(create_params.x(), create_params.y(), create_params.width(), create_params.height());
        }
      };
    }
  }
}
