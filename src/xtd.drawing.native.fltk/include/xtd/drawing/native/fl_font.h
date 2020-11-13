#pragma once
#include <FL/fl_draw.H>

namespace xtd::drawing::native {
  class fl_font {
  public:
    fl_font() = default;
    fl_font(Fl_Font font, Fl_Fontsize size) : font_(font), size_(size) {}
    
    Fl_Font font() const {return this->font_;}
    Fl_Fontsize size() const {return this->size_;}

  private:
    Fl_Font font_ = FL_HELVETICA;
    Fl_Fontsize size_ = FL_NORMAL_SIZE;
  };
}
