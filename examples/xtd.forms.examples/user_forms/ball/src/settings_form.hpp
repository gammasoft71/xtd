#pragma once
#include <xtd/forms/form>

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
    /// @}

  protected:
    /// @name Protected Methods
    
    /// @{
    void on_form_closed(const xtd::forms::form_closed_event_args& e) override;
    /// @}

  private:
  };
}
