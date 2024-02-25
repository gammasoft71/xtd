/// @file
/// @brief Contains settings_form class.
#pragma once
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>

namespace xtdc_gui {
  /// @brief Represents the main form
  class settings_form : public xtd::forms::form {
  public:
    /// @brief Initializes a new instance of the settings_form class.
    settings_form();
    
    /// @brief The main entry point for the application.
    static void main();
    
  protected:
    void on_form_closed(const xtd::forms::form_closed_event_args& e) override;

  private:
    xtd::forms::label auto_close_label_;
    xtd::forms::check_box auto_close_check_box_;
    xtd::forms::label use_default_ide_label_;
    xtd::forms::check_box use_default_ide_check_box_;
    xtd::forms::label ide_path_label_;
    xtd::forms::text_box ide_path_text_box_;
    xtd::forms::button ide_path_button_;
  };
}
