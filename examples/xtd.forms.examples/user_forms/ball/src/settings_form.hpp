#pragma once
#include <xtd/forms/button>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/numeric_up_down>

/// @brief Represents the ball widget application namespace.
namespace ball {
  /// @brief
  class settings_form : public xtd::forms::form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialises a new instance of ball::settings_form class.
    settings_form();
    /// @)
    
    /// @name Public Events
    
    /// @{
    xtd::event<settings_form, xtd::event_handler> settings_changed;
    /// @}

    /// @name Public Properties
    
    /// @{
    /// @}

  protected:
    /// @name Protected Methods
    
    /// @{
    void on_form_closed(const xtd::forms::form_closed_event_args& e) override;
    void on_settings_changed(const xtd::event_args& e);
    /// @}

  private:
    label color_label_;
    label light_point_color_label_;
    label size_label_;
    label default_settings_label_;

    xtd::forms::color_picker color_color_picker_;
    xtd::forms::color_picker light_point_color_color_picker_;
    numeric_up_down size_numeric_up_down_;
    xtd::forms::button reset_button_;
  };
}
