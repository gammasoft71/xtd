#include "../../../include/xtd/forms/status_bar_panel.h"
#include "../../../include/xtd/forms/status_bar.h"
#include "status_bar_panel_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

status_bar_panel::status_bar_panel() : data_(std::make_shared<data>()) {
}

xtd::forms::horizontal_alignment status_bar_panel::alignment() const noexcept {
  return data_->alignment;
}

status_bar_panel& status_bar_panel::alignment(xtd::forms::horizontal_alignment value) {
  if (data_->alignment == value) return *this;
  data_->alignment = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

xtd::forms::status_bar_panel_auto_size status_bar_panel::auto_size() const noexcept {
  return data_->auto_size;
}

status_bar_panel& status_bar_panel::auto_size(xtd::forms::status_bar_panel_auto_size value) {
  if (data_->auto_size == value) return *this;
  data_->auto_size = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

xtd::forms::status_bar_panel_border_style status_bar_panel::border_style() const noexcept {
  return data_->border_style;
}

status_bar_panel& status_bar_panel::border_style(xtd::forms::status_bar_panel_border_style value) {
  if (data_->border_style == value) return *this;
  data_->border_style = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

optional<reference_wrapper<forms::control>> status_bar_panel::control() const noexcept {
  return data_->control ? optional<reference_wrapper<forms::control>>(*data_->control) : nullopt;
}

status_bar_panel& status_bar_panel::control(const xtd::forms::control& value) {
  if (data_->control && data_->control == &value) return *this;
  data_->control = const_cast<xtd::forms::control*>(&value);
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

status_bar_panel& status_bar_panel::control(std::nullptr_t value) {
  if (!data_->control) return *this;
  data_->control = nullptr;
  if (data_->parent) data_->parent->post_recreate_handle();
  return *this;
}

const drawing::image& status_bar_panel::image() const noexcept {
  return data_->image;
}

status_bar_panel& status_bar_panel::image(const xtd::drawing::image& value) {
  if (data_->image == value) return *this;
  data_->image = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

int32 status_bar_panel::min_width() const noexcept {
  return data_->min_width;
}

status_bar_panel& status_bar_panel::min_width(int32 value) {
  if (data_->min_width == value) return *this;
  data_->min_width = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

const ustring& status_bar_panel::name() const noexcept {
  return data_->name;
}

status_bar_panel& status_bar_panel::name(const xtd::ustring& value) {
  data_->name = value;
  return *this;
}

optional<reference_wrapper<status_bar>> status_bar_panel::parent() const noexcept {
  return data_->parent ? optional<reference_wrapper<status_bar>>(*data_->parent) : nullopt;
}

xtd::forms::status_bar_panel_style status_bar_panel::style() const noexcept {
  return data_->style;
}

status_bar_panel& status_bar_panel::style(xtd::forms::status_bar_panel_style value) {
  if (data_->style == value) return *this;
  data_->style = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

std::any status_bar_panel::tag() const noexcept {
  return data_->tag;
}

status_bar_panel& status_bar_panel::tag(std::any value) {
  data_->tag = value;
  return *this;
}

const ustring& status_bar_panel::text() const noexcept {
  return data_->text;
}

status_bar_panel& status_bar_panel::text(const xtd::ustring& value) {
  if (data_->text == value) return *this;
  data_->text = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

const ustring& status_bar_panel::tool_tip_text() const noexcept {
  return data_->tool_tip_text;
}

status_bar_panel& status_bar_panel::tool_tip_text(const xtd::ustring& value) {
  if (data_->tool_tip_text == value) return *this;
  data_->tool_tip_text = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

int32 status_bar_panel::width() const noexcept {
  return data_->width;
}

status_bar_panel& status_bar_panel::width(int32 value) {
  if (data_->width == value) return *this;
  data_->width = value;
  if (data_->parent && data_->init_mode == false) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
  return *this;
}

void status_bar_panel::begin_init() {
  data_->init_mode = true;
}

status_bar_panel status_bar_panel::create_control(const xtd::ustring& text, const xtd::forms::control& control) {
  auto result = status_bar_panel {};
  result.control(control);
  result.style(xtd::forms::status_bar_panel_style::control);
  result.text(text);
  return result;
}

status_bar_panel status_bar_panel::create_control(const xtd::forms::control& control) {
  auto result = status_bar_panel {};
  result.control(control);
  result.style(xtd::forms::status_bar_panel_style::control);
  return result;
}

status_bar_panel status_bar_panel::create_panel(const xtd::ustring& text) {
  auto result = status_bar_panel {};
  result.style(xtd::forms::status_bar_panel_style::text);
  result.text(text);
  return result;
}

status_bar_panel status_bar_panel::create_panel(const xtd::drawing::image& image) {
  auto result = status_bar_panel {};
  result.style(xtd::forms::status_bar_panel_style::text);
  result.image(image);
  return result;
}

status_bar_panel status_bar_panel::create_panel(const xtd::ustring& text, const xtd::drawing::image& image) {
  auto result = status_bar_panel {};
  result.image(image);
  result.style(xtd::forms::status_bar_panel_style::text);
  result.text(text);
  return result;
}

bool status_bar_panel::equals(const status_bar_panel& other) const noexcept {
  return data_ == other.data_;
}

void status_bar_panel::end_init() {
  data_->init_mode = false;
  if (data_->parent) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image, data_->alignment, data_->auto_size, data_->border_style, data_->style, data_->min_width, data_->width);
}

xtd::ustring status_bar_panel::to_string() const noexcept {
  if (!data_->text.empty()) return ustring::format("{}, style: {}, text: {}", get_type().full_name(), data_->style, data_->text);
  if (!data_->name.empty()) return ustring::format("{}, style: {}, name: {}", get_type().full_name(), data_->style, data_->name);
  return ustring::format("{}, style: {}", get_type().full_name(), data_->style);
}
