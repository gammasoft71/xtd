#include "../../../../include/xtd/drawing/imaging/bitmap_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::imaging;

int32 bitmap_data::height() const noexcept {
  return height_;
}

bitmap_data& bitmap_data::height(int32 value) noexcept {
  height_ = value;
  return *this;
}

xtd::drawing::imaging::pixel_format bitmap_data::pixel_format() const noexcept {
  return pixel_format_;
}

bitmap_data& bitmap_data::pixel_format(xtd::drawing::imaging::pixel_format value) noexcept {
  pixel_format_ = value;
  return *this;
}

int32 bitmap_data::reserved() const noexcept {
  return reserved_;
}

bitmap_data& bitmap_data::reserved(int32 value) noexcept {
  reserved_ = value;
  return *this;
}

intptr bitmap_data::scan0() const noexcept {
  return scan0_;
}

bitmap_data& bitmap_data::scan0(intptr value) noexcept {
  scan0_ = value;
  return *this;
}

int32 bitmap_data::stride() const noexcept {
  return stride_;
}

bitmap_data& bitmap_data::stride(int32 value) noexcept {
  stride_ = value;
  return *this;
}

int32 bitmap_data::width() const noexcept {
  return width_;
}

bitmap_data& bitmap_data::width(int32 value) noexcept {
  width_ = value;
  return *this;
}
