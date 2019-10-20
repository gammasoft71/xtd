#pragma once
#include <FL/fl_draw.H>

namespace xtd::drawing::native {
  class fl_brush {
  public:
    fl_brush() = default;
    
    Fl_Color color() const {return this->color_;}
    void color(Fl_Color color) {this->color_ = color;}
    
  private:
    Fl_Color color_ = FL_BLACK;
  };
}
