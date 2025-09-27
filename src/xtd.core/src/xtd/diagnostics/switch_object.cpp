#include "../../../include/xtd/diagnostics/switch_object.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;
using namespace xtd::helpers;

const switch_object::attribute_collection& switch_object::attributes() const noexcept {
  return attributes_;
}

switch_object::attribute_collection& switch_object::attributes() noexcept {
  return attributes_;
}

void switch_object::attributes(const attribute_collection& attributes) noexcept {
  attributes_ = attributes;
}

const string& switch_object::description() const noexcept {
  return description_;
}

const string& switch_object::display_name() const noexcept {
  return display_name_;
}

const string& switch_object::value() const noexcept {
  return value_;
}

void switch_object::value(const string& value) {
  if (value_ == value) return;
  value_ = value;
  on_value_changed();
}

bool switch_object::equals(const object& obj) const noexcept {
  return is<switch_object>(obj) && equals(static_cast<const switch_object&>(obj));
}

bool switch_object::equals(const switch_object& other) const noexcept {
  return display_name_ == other.display_name_ && description_ == other.description_ && attributes_ == other.attributes_ && switch_setting_ == other.switch_setting_ && value_ == other.value_;
}

switch_object::switch_object(const string& display_name, const string& description) : display_name_(display_name), description_(description) {
}

switch_object::switch_object(const string& display_name, const string& description, const string& default_switch_value) : display_name_(display_name), description_(description), value_(default_switch_value) {
  set_switch_setting();
}

int32 switch_object::switch_setting() const noexcept {
  return switch_setting_;
}

void switch_object::switch_setting(int32 switch_setting) {
  if (switch_setting_ == switch_setting) return;
  switch_setting_ = switch_setting;
  on_switch_setting_changed();
}

array<string> switch_object::get_supported_attributes() const noexcept {
  return {};
}

void switch_object::on_switch_setting_changed() {
}

void switch_object::on_value_changed() {
  set_switch_setting();
}

void switch_object::set_switch_setting() {
  auto bool_value = false;
  auto int_value = 0;
  if (string::try_parse(value(), bool_value) == true) switch_setting_ = as<int32>(bool_value);
  else if (string::try_parse(value(), int_value) == true) switch_setting_ = int_value;
  else throw_helper::throws(exception_case::format, "Input xtd::string was not in a correct format."_t);
}
