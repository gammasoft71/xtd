#include "../../../include/xtd/drawing/pen.h"
#include "../../../include/xtd/drawing/bitmap.h"
#include "../../../include/xtd/drawing/solid_brush.h"
#include "../../../include/xtd/drawing/drawing_2d/hatch_brush.h"
#include "../../../include/xtd/drawing/drawing_2d/conical_gradient_brush.h"
#include "../../../include/xtd/drawing/drawing_2d/linear_gradient_brush.h"
#include "../../../include/xtd/drawing/drawing_2d/radial_gradient_brush.h"
#include "../../../include/xtd/drawing/texture_brush.h"
#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/pen>
#undef __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/as>
#include <xtd/is>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;

struct pen::data {
  intptr handle_ = 0;
  xtd::drawing::drawing_2d::pen_alignment alignment = xtd::drawing::drawing_2d::pen_alignment::center;
  std::unique_ptr<xtd::drawing::brush> brush;
  xtd::drawing::color color;
  float dash_offset = 0.0f;
  std::vector<float> dash_pattern;
  xtd::drawing::dash_style dash_style = xtd::drawing::dash_style::solid;
  xtd::drawing::drawing_2d::line_cap end_cap = xtd::drawing::drawing_2d::line_cap::flat;
  xtd::drawing::drawing_2d::line_join line_join = xtd::drawing::drawing_2d::line_join::miter;
  float miter_limit = 10.0f;
  xtd::drawing::drawing_2d::line_cap start_cap = xtd::drawing::drawing_2d::line_cap::flat;
  xtd::drawing::drawing_2d::pen_type type = xtd::drawing::drawing_2d::pen_type::solid_color;
  float width = 1.0f;
};

pen::pen(const drawing::color& color) : pen(color, 1) {
}

pen::pen(const drawing::color& color, float width) : pen(solid_brush(color), width) {
  data_->color = color;
}

pen::pen() : data_(std::make_shared<data>()) {
  recreate_handle();
}

pen::pen(const pen& value) : data_(std::make_shared<data>()) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
  data_ = value.data_;
}

pen& pen::operator =(const pen& value) {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
  data_ = value.data_;
  return *this;
}

pen::~pen() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
}

pen_alignment pen::alignment() const noexcept {
  return data_->alignment;
}

pen& pen::alignment(drawing_2d::pen_alignment value) {
  if (data_->alignment != value) {
    data_->alignment = value;
    recreate_handle();
  }
  return *this;
}

const std::unique_ptr<drawing::brush>& pen::brush() const noexcept {
  return data_->brush;
}

const xtd::drawing::color& pen::color() const noexcept {
  return data_->color;
}

pen& pen::color(const drawing::color& value) {
  if (data_->color != value) {
    data_->color = value;
    data_->brush = make_unique<solid_brush>(value);
    recreate_handle();
  }
  return *this;
}

std::vector<float> pen::dash_pattern() const noexcept {
  return data_->dash_pattern;
}

xtd::drawing::pen& pen::dash_pattern(const std::initializer_list<float>& value) {
  return dash_pattern(std::vector<float>(value));
}

pen& pen::dash_pattern(const vector<float>& value) {
  if (data_->dash_pattern != value) {
    data_->dash_pattern = value;
    if (!data_->dash_pattern.empty()) data_->dash_style = drawing::dash_style::custom;
    recreate_handle();
  }
  return *this;
}

drawing::dash_style pen::dash_style() const noexcept {
  return data_->dash_style;
}

pen& pen::dash_style(drawing::dash_style value) {
  if (data_->dash_style != value) {
    data_->dash_style = value;
    recreate_handle();
  }
  return *this;
}

xtd::drawing::drawing_2d::line_cap pen::end_cap() const noexcept {
  return data_->end_cap;
}

xtd::drawing::pen& pen::end_cap(xtd::drawing::drawing_2d::line_cap value) {
  if (data_->end_cap != value) {
    data_->end_cap = value;
    recreate_handle();
  }
  return *this;
}

intptr pen::handle() const noexcept {
  return data_->handle_;
}

xtd::drawing::drawing_2d::line_join pen::line_join() const noexcept {
  return data_->line_join;
}

xtd::drawing::pen& pen::line_join(xtd::drawing::drawing_2d::line_join value) {
  if (data_->line_join != value) {
    data_->line_join = value;
    recreate_handle();
  }
  return *this;
}

float pen::miter_limit() const noexcept {
  return data_->miter_limit;
}

xtd::drawing::pen& pen::miter_limit(float value) {
  if (data_->miter_limit != value) {
    data_->miter_limit = value;
    recreate_handle();
  }
  return *this;
}

xtd::drawing::drawing_2d::line_cap pen::start_cap() const noexcept {
  return data_->start_cap;
}

xtd::drawing::pen& pen::start_cap(xtd::drawing::drawing_2d::line_cap value) {
  if (data_->start_cap != value) {
    data_->start_cap = value;
    recreate_handle();
  }
  return *this;
}

xtd::drawing::drawing_2d::pen_type pen::type() const noexcept {
  return data_->type;
}

float pen::width() const noexcept {
  return data_->width;
}

pen& pen::width(float value) {
  if (data_->width != value) {
    data_->width = value;
    recreate_handle();
  }
  return *this;
}

bool pen::equals(const xtd::drawing::pen& value) const noexcept {
  return data_ == value.data_;
}

xtd::ustring pen::to_string() const noexcept {
  return get_type().full_name();
}

void pen::brush_(std::unique_ptr<xtd::drawing::brush>&& brush) {
  data_->brush = std::move(brush);
}

void pen::color_(const xtd::drawing::color& color) {
  data_->color = color;
}

void pen::create_data() {
  data_ = std::make_shared<data>();
}

void pen::recreate_handle() {
  if (data_.use_count() == 1 && data_->handle_ != 0) native::pen::destroy(data_->handle_);
  data_->handle_ = native::pen::create();
  native::pen::end_cap(data_->handle_, static_cast<int32>(data_->end_cap));
  native::pen::line_join(data_->handle_, static_cast<int32>(data_->line_join));
  native::pen::start_cap(data_->handle_, static_cast<int32>(data_->start_cap));
  native::pen::miter_limit(data_->handle_, data_->miter_limit);
  
  vector<float> dashes;
  switch (data_->dash_style) {
    case drawing::dash_style::solid: break;
    case drawing::dash_style::dash: dashes = {3, 2};  break;
    case drawing::dash_style::dot: dashes = {1, 1};  break;
    case drawing::dash_style::dash_dot: dashes = {3, 1, 1, 1};  break;
    case drawing::dash_style::dash_dot_dot: dashes = {3, 1, 1, 1, 1, 1};  break;
    case drawing::dash_style::custom: dashes = data_->dash_pattern; break;
    default: break;
  }
  
  if (data_->brush == nullptr) {
    data_->type = pen_type::solid_color;
    native::pen::solid_color(data_->handle_, data_->color.a(), data_->color.r(), data_->color.g(), data_->color.b(), data_->width, data_->dash_offset, dashes);
  } else if (is<hatch_brush>(data_->brush.get())) {
    data_->type = pen_type::hatch_fill;
    native::pen::hatch_fill(data_->handle_, as<hatch_brush>(data_->brush.get())->handle(), data_->width);
  } else if (is<conical_gradient_brush>(data_->brush.get())) {
    data_->type = pen_type::conical_gradient;
    native::pen::conical_gradient(data_->handle_, as<conical_gradient_brush>(data_->brush.get())->handle(), data_->width);
  } else if (is<linear_gradient_brush>(data_->brush.get())) {
    data_->type = pen_type::linear_gradient;
    native::pen::linear_gradient(data_->handle_, as<linear_gradient_brush>(data_->brush.get())->handle(), data_->width);
  } else if (is<radial_gradient_brush>(data_->brush.get())) {
    data_->type = pen_type::radial_gradient;
    native::pen::radial_gradient(data_->handle_, as<radial_gradient_brush>(data_->brush.get())->handle(), data_->width);
  } else if (is<solid_brush>(data_->brush.get())) {
    data_->type = pen_type::solid_color;
    native::pen::solid_color(data_->handle_, as<solid_brush>(data_->brush.get())->color().a(), as<solid_brush>(data_->brush.get())->color().r(), as<solid_brush>(data_->brush.get())->color().g(), as<solid_brush>(data_->brush.get())->color().b(), data_->width, data_->dash_offset, dashes);
  } else if (is<texture_brush>(data_->brush.get())) {
    data_->type = pen_type::texture_fill;
    native::pen::texture_fill(data_->handle_, as<texture_brush>(data_->brush.get())->handle(), data_->width);
  }
}
