#include "../../../include/xtd/forms/create_params.h"

using namespace xtd;
using namespace xtd::forms;

struct create_params::data {
  xtd::ustring caption;
  xtd::ustring class_name;
  size_t class_style = 0;
  size_t ex_style = 0;
  drawing::point location;
  intptr param = 0;
  intptr parent = 0;
  size_t style = 0;
  drawing::size size;
};

create_params::create_params() : data_(std::make_shared<data>()) {
}

create_params::create_params(const create_params& other) : data_(std::make_shared<data>()) {
  *data_ = *other.data_;
}

create_params& create_params::operator =(const create_params& other) {
  *data_ = *other.data_;
  return *this;
}

const xtd::ustring& create_params::caption() const noexcept {
  return data_->caption;
}

create_params& create_params::caption(const xtd::ustring& caption) {
  data_->caption = caption;
  return *this;
}

const xtd::ustring& create_params::class_name() const noexcept {
  return data_->class_name;
}

create_params& create_params::class_name(const xtd::ustring& class_name) {
  data_->class_name = class_name;
  return *this;
}

size_t create_params::class_style() const noexcept {
  return data_->class_style;
}

create_params& create_params::class_style(size_t class_style) {
  data_->class_style = class_style;
  return *this;
}

size_t create_params::ex_style() const noexcept {
  return data_->ex_style;
}

create_params& create_params::ex_style(size_t ex_style) {
  data_->ex_style = ex_style;
  return *this;
}

int32 create_params::height() const noexcept {
  return data_->size.height();
}

create_params& create_params::height(int32 height) {
  data_->size.height(height);
  return *this;
}

drawing::point create_params::location() const noexcept {
  return data_->location;
}

create_params& create_params::location(const drawing::point location) {
  data_->location = location;
  return *this;
}

intptr create_params::param() const noexcept {
  return data_->param;
}

create_params& create_params::param(intptr param) {
  data_->param = param;
  return *this;
}

intptr create_params::parent() const noexcept {
  return data_->parent;
}

create_params& create_params::parent(intptr parent) {
  data_->parent = parent;
  return *this;
}

size_t create_params::style() const noexcept {
  return data_->style;
}

create_params& create_params::style(size_t style) {
  data_->style = style;
  return *this;
}

drawing::size create_params::size() const noexcept {
  return data_->size;
}

create_params& create_params::size(const drawing::size size) {
  data_->size = size;
  return *this;
}


int32 create_params::width() const noexcept {
  return data_->size.width();
}

create_params& create_params::width(int32 width) {
  data_->size.width(width);
  return *this;
}

int32 create_params::x() const noexcept {
  return data_->location.x();
}

create_params& create_params::x(int32 x) {
  data_->location.x(x);
  return *this;
}

int32 create_params::y() const noexcept {
  return data_->location.y();
}

create_params& create_params::y(int32 y) {
  data_->location.y(y);
  return *this;
}

xtd::ustring create_params::to_string() const noexcept {
  return ustring::format("create_params {{'{}' , '{}', 0x{:X}, 0x{:X}, {{{}, {}, {}, {}}}}}", data_->class_name, data_->caption, data_->style, data_->ex_style, data_->location.x(), data_->location.y(), data_->size.width(), data_->size.height());
}
