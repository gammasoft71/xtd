#include <stdexcept>
#include "../../../include/xtd/drawing/pen.hpp"
#include "../../../include/xtd/drawing/solid_brush.hpp"
#include <xtd/drawing/native/pen.hpp>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

pen::pen(const drawing::brush& brush) {
  this->handle_ = native::pen::create();
  this->brush(brush);
}

pen::pen(const drawing::brush& brush, float width) {
  this->handle_ = native::pen::create();
  this->brush(brush);
  this->width(width);
}

pen::pen(const drawing::color& color) {
  this->handle_ = native::pen::create();
  this->color(color);
}

pen::pen(const drawing::color& color, float width) {
  this->handle_ = native::pen::create();
  this->color(color);
  this->width(width);
}

pen::pen(const pen& pen) {
  this->handle_ = native::pen::create();
  this->alignment(pen.alignment());
  this->color(pen.color());
  this->type(pen.type());
  this->width(pen.width());
}

pen& pen::operator=(const pen& pen) {
  this->handle_ = native::pen::create();
  this->alignment(pen.alignment());
  this->color(pen.color());
  this->type(pen.type());
  this->width(pen.width());
  return *this;
}

pen::pen() {
  this->handle_ = native::pen::create();
}

pen::~pen() {
  native::pen::destroy(this->handle_);
}

pen& pen::alignment(drawing2d::pen_alignment alignment) {
  if (this->alignment_ != alignment) {
    this->alignment_ = alignment;
  }
  return *this;
}

std::unique_ptr<drawing::brush> pen::brush() const {
  switch (this->type_) {
    case drawing2d::pen_type::solid_color: return make_unique<solid_brush>(this->color_); break;
    case drawing2d::pen_type::hatch_fill: //return make_unique<drawing2d::hatch_brush>(this->color_); break;
    case drawing2d::pen_type::texture_fill: //return make_unique<texture_brush>(this->color_); break;
    case drawing2d::pen_type::path_gradient: //return make_unique<drawing2d::path_gradient_brush>(this->color_); break;
    case drawing2d::pen_type::linear_gradient: //return make_unique<drawing2d::linear_gradient_brush>(this->color_); break;
    default: throw std::out_of_range("pen type invalid"); break;
  }
}

pen& pen::brush(const drawing::brush& brush) {
  if (dynamic_cast<const drawing::solid_brush*>(&brush) != nullptr) {
    this->type_ = drawing2d::pen_type::solid_color;
    this->color(static_cast<const drawing::solid_brush&>(brush).color());
  //} else if (dynamic_cast<const drawing2d::hatch_brush*>(&brush) != nullptr) {
  //  this->type_ = drawing2d::pen_type::hatch_fill;
  //} else if (dynamic_cast<const texture_brush*>(&brush) != nullptr) {
  //  this->type_ = drawing2d::pen_type::texture_fill;
  //} else if (dynamic_cast<const ddrawing2d::path_gradient_brush*>(&brush) != nullptr) {
  //  this->type_ = drawing2d::pen_type::path_gradient;
  //} else if (dynamic_cast<const drawing2d::linear_gradient_brush*>(&brush) != nullptr) {
  //  this->type_ = drawing2d::pen_type::linear_gradient;
  } else
    throw std::invalid_argument("brush invalid");
  return *this;
}

pen& pen::color(const drawing::color& color) {
  if (this->color_ != color) {
    this->color_ = color;
    native::pen::color(this->handle_, color.a(), color.r(), color.g(), color.b());
  }
  return *this;
}

pen& pen::type(drawing2d::pen_type type) {
  if (this->type_ != type) {
    this->type_ = type;
  }
  return *this;
}

pen& pen::width(float width) {
  if (this->width_ != width) {
    this->width_ = width;
    native::pen::width(this->handle_, width);
  }
  return *this;
}
