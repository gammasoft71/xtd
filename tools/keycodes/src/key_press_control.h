/// @file
/// @brief Contains key_press_control class.
#pragma once
#include <xtd/forms/label>
#include <xtd/forms/user_control>

/// @brief Represents the namespace that contains application objects.
namespace keycodes {
  /// @brief Represents the main form.
  class key_press_control : public xtd::forms::user_control {
  public:
    /// @brief Initializes a new instance of the form1 class.
    key_press_control();
    
    key_press_control& key_char(const xtd::ustring& value);
    key_press_control& key_data(const xtd::ustring& value);
    
  protected:
    std::unique_ptr<xtd::object> clone() const override {
      auto result = std::make_unique<key_press_control>(*this);
      if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::ustring::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
      return result;
    }

  private:
    xtd::forms::label key_event_label_;
    xtd::forms::label key_char_label_;
    xtd::forms::label key_char_;
  };
}
