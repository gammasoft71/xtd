#include <xtd/drawing/native/pen.hpp>
#include <FL/fl_draw.H>

using namespace xtd::drawing::native;

namespace {
  class Fl_Pen {
  public:
    Fl_Pen() = default;
    
    Fl_Color color() const {return this->color_;}
    void color(Fl_Color color) {this->color_ = color;}
    
    int32_t width() const {return this->width_;}
    void width(int32_t width) {this->width_ = width;}
    
  private:
    Fl_Color color_ = FL_BLACK;
    int32_t width_ = 1;
  };
}

intptr_t pen::create() {
  return reinterpret_cast<intptr_t>(new Fl_Pen());
}

void pen::color(intptr_t pen, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<Fl_Pen*>(pen)->color(fl_rgb_color(uchar((r & 0x00FF0000)>>16), uchar((g& 0x0000FF00)>>8), uchar(b & 0x000000FF)));
}

void pen::width(intptr_t pen, float width) {
  reinterpret_cast<Fl_Pen*>(pen)->width(static_cast<int>(width));
}

void pen::destroy(intptr_t pen) {
  delete reinterpret_cast<Fl_Pen*>(pen);
}
