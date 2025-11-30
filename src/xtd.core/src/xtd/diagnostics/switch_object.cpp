#include "../../../include/xtd/diagnostics/switch_object.hpp"
#include "../../../include/xtd/diagnostics/trace_listener_collection.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/call_once.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::collections::specialized;
using namespace xtd::diagnostics;
using namespace xtd::helpers;

const std::tuple<const trace_listener_collection&, const string_dictionary&>& __xtd___read_diagnostics_config__();

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
  auto new_value = value;
  call_once_ {
    if (switches_.count()) return;
    const auto& [listeners, switches] = __xtd___read_diagnostics_config__();
    switches_ = switches;
  };
  
  if (value_ == new_value) {
    if (switches_.contains_key(display_name_)) new_value = switches_[display_name_];
    else return;
  }
  value_ = new_value;
  switches_[display_name_] = value_;
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
  auto int_value = 0;
  if (!string::try_parse(value(), int_value)) throw_helper::throws(exception_case::format, "Input xtd::string was not in a correct format.");
  switch_setting(int_value);
}
