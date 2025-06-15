#pragma once
#include "../properties/settings.hpp"
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
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the settings.
    /// @return The settings.
    /// @remarks This property is same as ball::properties::settings::default_settings.
    const ball::properties::settings& settings() const noexcept;
    /// @brief Sets the settings.
    /// @param value The settings to set.
    /// @return This current instance.
    /// @remarks This property is same as ball::properties::settings::default_settings.
    settings_form& settings(const ball::properties::settings& value) noexcept;
    /// @)
    
    /// @name Public Events
    
    /// @{
    /// @brief Occurs when the ball::settings_form::settings property has been changed in some way.
    xtd::event<settings_form, xtd::event_handler> settings_changed;
    /// @}

  protected:
    /// @name Protected Methods
    
    /// @{
    /// @brief Raises the xtd::forms::form_closed event.
    /// @param e A xtd::forms::form_closed_event_args that contains the event data.
    void on_form_closed(const xtd::forms::form_closed_event_args& e) override;

    /// @brief Raises the ball::settings_form::settings_changed event.
    /// @param e An xtd::event_args that contains the event data.
    void on_settings_changed(const xtd::event_args& e);
    /// @}

  private:
    label color_label_;
    label light_point_color_label_;
    label opcacity_label_;
    label size_label_;
    label default_settings_label_;

    xtd::forms::color_picker color_color_picker_;
    xtd::forms::color_picker light_point_color_color_picker_;
    numeric_up_down opacity_numeric_up_down_;
    numeric_up_down size_numeric_up_down_;
    xtd::forms::button reset_button_;
  };
}
