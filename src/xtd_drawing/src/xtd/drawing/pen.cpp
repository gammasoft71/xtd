#include <stdexcept>
#include "../../../include/xtd/drawing/pen.hpp"
#include "../../../include/xtd/drawing/solid_brush.hpp"
#include <xtd/drawing/native/pen.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

pen::pen(const drawing::brush& brush) {
  this->data_->handle_ = native::pen::create();
  this->brush(brush);
}

pen::pen(const drawing::brush& brush, float width) {
  this->data_->handle_ = native::pen::create();
  this->brush(brush);
  this->width(width);
}

pen::pen(const drawing::color& color) {
  this->data_->handle_ = native::pen::create();
  this->color(color);
}

pen::pen(const drawing::color& color, float width) {
  this->data_->handle_ = native::pen::create();
  this->color(color);
  this->width(width);
}

pen::pen() {
  this->data_->handle_ = native::pen::create();
}

pen::pen(const pen& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::pen::destroy(this->data_->handle_);
  this->data_ = value.data_;
}

pen& pen::operator=(const pen& value) {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::pen::destroy(this->data_->handle_);
  this->data_ = value.data_;
  return *this;
}

pen::~pen() {
  if (this->data_.use_count() == 1 && this->data_->handle_ != 0) native::pen::destroy(this->data_->handle_);
}

pen& pen::alignment(drawing2d::pen_alignment alignment) {
  if (this->data_->alignment_ != alignment) {
    this->data_->alignment_ = alignment;
  }
  return *this;
}

std::unique_ptr<drawing::brush> pen::brush() const {
  switch (this->data_->type_) {
    case drawing2d::pen_type::solid_color: return make_unique<solid_brush>(this->data_->color_); break;
    case drawing2d::pen_type::hatch_fill: //return make_unique<drawing2d::hatch_brush>(this->data_->color_); break;
    case drawing2d::pen_type::texture_fill: //return make_unique<texture_brush>(this->data_->color_); break;
    case drawing2d::pen_type::path_gradient: //return make_unique<drawing2d::path_gradient_brush>(this->data_->color_); break;
    case drawing2d::pen_type::linear_gradient: //return make_unique<drawing2d::linear_gradient_brush>(this->data_->color_); break;
    default: throw std::out_of_range("pen type invalid"); break;
  }
}

pen& pen::brush(const drawing::brush& brush) {
  if (dynamic_cast<const drawing::solid_brush*>(&brush) != nullptr) {
    this->data_->type_ = drawing2d::pen_type::solid_color;
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
  if (this->data_->color_ != color) {
    this->data_->color_ = color;
    native::pen::color(this->data_->handle_, color.a(), color.r(), color.g(), color.b());
  }
  return *this;
}

pen& pen::type(drawing2d::pen_type type) {
  if (this->data_->type_ != type) {
    this->data_->type_ = type;
  }
  return *this;
}

pen& pen::width(float width) {
  if (this->data_->width_ != width) {
    this->data_->width_ = width;
    native::pen::width(this->data_->handle_, width);
  }
  return *this;
}
