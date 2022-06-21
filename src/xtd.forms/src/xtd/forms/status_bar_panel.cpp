#include "../../../include/xtd/forms/status_bar_panel.h"
#include "../../../include/xtd/forms/status_bar.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

optional<reference_wrapper<forms::control>> status_bar_panel::control() const noexcept {
  return data_->control ? optional<reference_wrapper<forms::control>>(*data_->control) : nullopt;
}

status_bar_panel& status_bar_panel::control(const xtd::forms::control& value) {
  if (!data_->control || data_->control != &value) {
    data_->control = const_cast<xtd::forms::control*>(&value);
    if (data_->parent) data_->parent->post_recreate_handle();
  }
  return *this;
}

status_bar_panel& status_bar_panel::control(std::nullptr_t value) {
  if (data_->control) {
    data_->control = nullptr;
    if (data_->parent) data_->parent->post_recreate_handle();
  }
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
  if (data_->style != value) {
    data_->style = value;
    if (data_->parent) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image);
  }
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
  if (data_->text != value) {
    data_->text = value;
    if (data_->parent) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image);
  }
  return *this;
}

const ustring& status_bar_panel::tool_tip_text() const noexcept {
  return data_->tool_tip_text;
}

status_bar_panel& status_bar_panel::tool_tip_text(const xtd::ustring& value) {
  if (data_->tool_tip_text != value) {
    data_->tool_tip_text = value;
    if (data_->parent) data_->parent->update_status_bar_panel_control(data_->handle, data_->text, data_->tool_tip_text, data_->image);
  }
  return *this;
}

status_bar_panel status_bar_panel::create_control(const xtd::ustring& text, const xtd::forms::control& control) {
  status_bar_panel result;
  result.control(control);
  result.style(xtd::forms::status_bar_panel_style::control);
  result.text(text);
  return result;
}

status_bar_panel status_bar_panel::create_control(const xtd::forms::control& control) {
  status_bar_panel result;
  result.control(control);
  result.style(xtd::forms::status_bar_panel_style::control);
  return result;
}

xtd::ustring status_bar_panel::to_string() const noexcept {
  if (!data_->text.empty()) return ustring::format("{}, style: {}, text: {}", ustring::full_class_name(*this), data_->style, data_->text);
  if (!data_->name.empty()) return ustring::format("{}, style: {}, name: {}", ustring::full_class_name(*this), data_->style, data_->name);
  return ustring::format("{}, style: {}", ustring::full_class_name(*this), data_->style);
}
