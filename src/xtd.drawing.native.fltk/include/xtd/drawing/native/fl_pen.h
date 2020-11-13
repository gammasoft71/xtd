#pragma once
#include <FL/fl_draw.H>

namespace xtd::drawing::native {
  class fl_pen {
  public:
    fl_pen() = default;
    fl_pen(Fl_Color color) : color_(color) {}
    fl_pen(Fl_Color color, int32_t width) : color_(color), width_(width) {}
    fl_pen(Fl_Color color, int32_t width, int32_t style) : color_(color), width_(width), style_(style) {}

    Fl_Color color() const {return this->color_;}
    void color(Fl_Color color) {this->color_ = color;}
    
    int32_t style() const {return this->width_;}
    void style(int32_t style) {this->style_ = style;}
    
    int32_t width() const {return this->width_;}
    void width(int32_t width) {this->width_ = width;}

  private:
    Fl_Color color_ = FL_BLACK;
    int32_t width_ = 1;
    int style_ = FL_SOLID;
  };
}
