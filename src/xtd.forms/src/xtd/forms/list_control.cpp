#include "../../../include/xtd/forms/list_control"

using namespace xtd;
using namespace xtd::forms;

struct list_control::data {
  size_t selected_index = npos;
};

list_control::item::item(const xtd::ustring& value) : value_(value) {
}

list_control::item::item(const xtd::ustring& value, const std::any& tag) : value_(value), tag_(tag) {
}

list_control::item::item(const char* value) : value_(value) {
}

const xtd::ustring& list_control::item::value() const noexcept {
  return value_;
}

std::any list_control::item::tag() const noexcept {
  return tag_;
}

bool list_control::item::equals(const item& value) const noexcept {
  return value_ == value.value_;
}

int32 list_control::item::compare_to(const item& value) const noexcept {
  return value_ < value.value_ ? -1 : value_ > value.value_ ? 1 : 0;
}

xtd::ustring list_control::item::to_string() const noexcept {
  return value_;
}

list_control::list_control() : data_(std::make_shared<data>()) {
  //back_color_ = default_back_color();
  //fore_color_ = default_fore_color();
}

size_t list_control::selected_index() const noexcept {
  return data_->selected_index;
}

drawing::color list_control::default_back_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window();
}

drawing::color list_control::default_fore_color() const noexcept {
  return xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().window_text();
}

bool list_control::allow_selection() const noexcept {
  return true;
}

void list_control::on_selected_index_changed(const event_args& e) {
  selected_index_changed(*this, e);
}

void list_control::on_selected_value_changed(const event_args& e) {
  selected_value_changed(*this, e);
}

void list_control::set_selected_index(size_t value) {
  data_->selected_index = value;
}
