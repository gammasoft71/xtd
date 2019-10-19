#include <xtd/drawing/native/brush.hpp>
#include <FL/fl_draw.H>

using namespace xtd::drawing::native;

namespace {
  class Fl_Brush {
  public:
    Fl_Brush() = default;
    
    Fl_Color color() const {return this->color_;}
    void color(Fl_Color color) {this->color_ = color;}
    
  private:
    Fl_Color color_ = FL_BLACK;
  };
}

intptr_t brush::create() {
  return reinterpret_cast<intptr_t>(new Fl_Brush());
}

void brush::color(intptr_t brush, uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
  reinterpret_cast<Fl_Brush*>(brush)->color(fl_rgb_color(uchar((r & 0x00FF0000)>>16), uchar((g& 0x0000FF00)>>8), uchar(b & 0x000000FF)));
}

void brush::destroy(intptr_t brush) {
  delete reinterpret_cast<Fl_Brush*>(brush);
}
