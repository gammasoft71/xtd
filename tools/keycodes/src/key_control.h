/// @file
/// @brief Contains key_control class.
#pragma once
#include <xtd/forms/label>
#include <xtd/forms/panel>
#include <xtd/forms/user_control>

/// @brief Represents the namespace that contains application objects.
namespace keycodes {
  /// @brief Represents the main form.
  class key_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the form1 class.
    key_control();
    
    key_control& key_event(const xtd::ustring& value);
    key_control& key_code(const xtd::ustring& value);
    key_control& key_data(const xtd::ustring& value);
    key_control& key_value(const xtd::ustring& value);
    key_control& key_modfiers(const xtd::ustring& value);
    key_control& line_visible(bool value);
    
  private:
    xtd::forms::label key_event_;
    xtd::forms::label key_code_label_;
    xtd::forms::label key_code_;
    xtd::forms::label key_data_label_;
    xtd::forms::label key_data_;
    xtd::forms::label key_value_label_;
    xtd::forms::label key_value_;
    xtd::forms::label key_modfiers_label_;
    xtd::forms::label key_modfiers_;
    xtd::forms::panel line_;
  };
}
