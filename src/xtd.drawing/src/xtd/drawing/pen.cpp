#include <stdexcept>
#include "../../../include/xtd/drawing/pen.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#include <xtd/argument_exception.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/pen.h>
#undef __XTD_DRAWING_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

pen::pen(const drawing::brush& brush) {
  data_->handle_ = native::pen::create();
  this->brush(brush);
}

pen::pen(const drawing::brush& brush, float width) {
  data_->handle_ = native::pen::create();
  this->brush(brush);
  this->width(width);
}

pen::pen(const drawing::color& color) {
  data_->handle_ = native::pen::create();
  this->color(color);
}

pen::pen(const drawing::color& color, float width) {
  data_->handle_ = native::pen::create();
  this->color(color);
  this->width(width);
}

pen::pen() {
  data_->handle_ = native::pen::create();
}

pen::pen(const pen& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
  data_ = value.data_;
}

pen& pen::operator=(const pen& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

pen::~pen() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
}

pen& pen::alignment(drawing2d::pen_alignment alignment) {
  if (data_->alignment_ != alignment) {
    data_->alignment_ = alignment;
  }
  return *this;
}

std::unique_ptr<drawing::brush> pen::brush() const {
  switch (data_->type_) {
    case drawing2d::pen_type::solid_color: return make_unique<solid_brush>(data_->color_); break;
    case drawing2d::pen_type::hatch_fill: //return make_unique<drawing2d::hatch_brush>(data_->color_); break;
    case drawing2d::pen_type::texture_fill: //return make_unique<texture_brush>(data_->color_); break;
    case drawing2d::pen_type::path_gradient: //return make_unique<drawing2d::path_gradient_brush>(data_->color_); break;
    case drawing2d::pen_type::linear_gradient: //return make_unique<drawing2d::linear_gradient_brush>(data_->color_); break;
    default: throw xtd::argument_exception("pen type invalid"_t, current_stack_frame_); break;
  }
}

pen& pen::brush(const drawing::brush& brush) {
  if (dynamic_cast<const drawing::solid_brush*>(&brush) != nullptr) {
    data_->type_ = drawing2d::pen_type::solid_color;
    color(static_cast<const drawing::solid_brush&>(brush).color());
  //} else if (dynamic_cast<const drawing2d::hatch_brush*>(&brush) != nullptr) {
  //  type_ = drawing2d::pen_type::hatch_fill;
  //} else if (dynamic_cast<const texture_brush*>(&brush) != nullptr) {
  //  type_ = drawing2d::pen_type::texture_fill;
  //} else if (dynamic_cast<const ddrawing2d::path_gradient_brush*>(&brush) != nullptr) {
  //  type_ = drawing2d::pen_type::path_gradient;
  //} else if (dynamic_cast<const drawing2d::linear_gradient_brush*>(&brush) != nullptr) {
  //  type_ = drawing2d::pen_type::linear_gradient;
  } else
    throw xtd::argument_exception("brush invalid"_t, current_stack_frame_);
  return *this;
}

pen& pen::color(const drawing::color& color) {
  if (data_->color_ != color) {
    data_->color_ = color;
    native::pen::color(data_->handle_, color.a(), color.r(), color.g(), color.b());
  }
  return *this;
}

pen& pen::dash_pattern(const vector<float>& dash_pattern) {
  if (data_->dash_pattern_ != dash_pattern) {
    data_->dash_pattern_ = dash_pattern;
    native::pen::dash_pattern(data_->handle_, dash_pattern);
  }
  return *this;
}

pen& pen::dash_style(drawing::dash_style dash_style) {
  if (data_->dash_style_ != dash_style) {
    data_->dash_style_ = dash_style;
    native::pen::dash_style(data_->handle_, static_cast<uint32_t>(dash_style));
  }
  return *this;
}

pen& pen::type(drawing2d::pen_type type) {
  if (data_->type_ != type) {
    data_->type_ = type;
  }
  return *this;
}

pen& pen::width(float width) {
  if (data_->width_ != width) {
    data_->width_ = width;
    native::pen::width(data_->handle_, width);
  }
  return *this;
}
