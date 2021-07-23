#include "../../../include/xtd/diagnostics/switch_base.h"

using namespace xtd;
using namespace xtd::diagnostics;

bool switch_base::operator==(const switch_base& value) const {
  return display_name_ == value.display_name_ && description_ == value.description_ && attributes_ == value.attributes_ && switch_setting_ == value.switch_setting_ && value_ == value.value_;
}

bool switch_base::operator!=(const switch_base& value) const {
  return !operator==(value);
}

const std::map<std::string, std::string>& switch_base::attributes() const {
  return attributes_;
}

std::map<std::string, std::string>& switch_base::attributes() {
  return attributes_;
}

void switch_base::attributes(const std::map<std::string, std::string>& attributes) {
  attributes_ = attributes;
}

const std::string& switch_base::description() const {
  return description_;
}

const std::string& switch_base::display_name() const {
  return display_name_;
}

switch_base::switch_base(const std::string& display_name, const std::string& description) : display_name_(display_name), description_(description) {
}

switch_base::switch_base(const std::string& display_name, const std::string& description, const std::string& default_switch_value) : display_name_(display_name), description_(description), value_(default_switch_value) {
}

int32_t switch_base::switch_setting() const {
  return switch_setting_;
}

void switch_base::switch_setting(int32_t switch_setting) {
  if (switch_setting_ != switch_setting) {
    switch_setting_ = switch_setting;
    on_switch_setting_changed();
  }
}

const std::string& switch_base::value() const {
  return value_;
}

void switch_base::value(const std::string& value) {
  if (value_ != value) {
    value_ = value;
    on_value_changed();
  }
}

std::vector<std::string> switch_base::get_supported_attributes() const {
  return {};
}

void switch_base::on_switch_setting_changed() {
}

void switch_base::on_value_changed() {
}
