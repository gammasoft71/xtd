#include "../../../include/xtd/forms/control_layout_style.hpp"

using namespace xtd;
using namespace xtd::forms;

struct control_layout_style::data {
  xtd::forms::size_type size_type = xtd::forms::size_type::absolute;
  bool expanded = false;
  xtd::forms::content_alignment align = xtd::forms::content_alignment::top_left;
};

control_layout_style::control_layout_style() : data_(xtd::new_sptr<data>()) {
}

control_layout_style::control_layout_style(xtd::forms::size_type size_type) : data_(xtd::new_sptr<data>()) {
  data_->size_type = size_type;
}

control_layout_style::control_layout_style(bool expanded) : data_(xtd::new_sptr<data>())  {
  data_->expanded = expanded;
}

control_layout_style::control_layout_style(xtd::forms::content_alignment align) : data_(xtd::new_sptr<data>()) {
  data_->align = align;
}

control_layout_style::control_layout_style(xtd::forms::size_type size_type, bool expanded) : data_(xtd::new_sptr<data>()) {
  data_->size_type = size_type;
  data_->expanded = expanded;
}

control_layout_style::control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : data_(xtd::new_sptr<data>()) {
  data_->size_type = size_type;
  data_->align = align;
}

control_layout_style::control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : data_(xtd::new_sptr<data>()) {
  data_->size_type = size_type;
  data_->expanded = expanded;
  data_->align = align;
}

control_layout_style::control_layout_style(bool expanded, xtd::forms::content_alignment align) : data_(xtd::new_sptr<data>()) {
  data_->expanded = expanded;
  data_->align = align;
}

control_layout_style::control_layout_style(const control_layout_style& other) : data_(xtd::new_sptr<data>()) {
  *data_ = *other.data_;
}

control_layout_style& control_layout_style::operator =(const control_layout_style& other) {
  *data_ = *other.data_;
  return *this;
}

xtd::forms::size_type control_layout_style::size_type() const noexcept {
  return data_->size_type;
}

control_layout_style& control_layout_style::size_type(xtd::forms::size_type size_type) {
  data_->size_type = size_type;
  return *this;
}

bool control_layout_style::expanded() const noexcept {
  return data_->expanded;
}

control_layout_style& control_layout_style::expanded(bool expanded) {
  data_->expanded = expanded;
  return *this;
}

xtd::forms::content_alignment control_layout_style::align() const noexcept {
  return data_->align;
}

control_layout_style& control_layout_style::align(xtd::forms::content_alignment align) {
  data_->align = align;
  return *this;
}

bool control_layout_style::equals(const object& obj) const noexcept {
  return is<control_layout_style>(obj) && equals(static_cast<const control_layout_style&>(obj));
}

bool control_layout_style::equals(const control_layout_style& other) const noexcept {
  return data_->size_type == other.data_->size_type && data_->expanded == other.data_->expanded && data_->align == other.data_->align;
}

xtd::size control_layout_style::get_hash_code() const noexcept {
  return hash_code::combine(data_->size_type, data_->expanded, data_->align);
}

xtd::string control_layout_style::to_string() const noexcept {
  return string::format("control_layout_style=[expanded={}, align={}, size_type={}]", data_->expanded, data_->align, data_->size_type);
}
