/// @file
/// @brief Contains main_form class.
#pragma once
#include <xtd/xtd.forms>

/// @brief Represents the namespace that contains application objects.
namespace keycodes {
  /// @brief Represents the main form.
  class main_form : public xtd::forms::form {
  public:
    /// @brief The main entry point for the application.
    static void main();
    
    /// @brief Initializes a new instance of the form1 class.
    main_form();

  private:
    bool pre_process_message(xtd::forms::message& message) override;
    void on_clear_button_click(xtd::object& sender, const xtd::event_args& e);
    void on_form_location_changed(xtd::object& sender, const xtd::event_args& e);
    void on_form_resize(xtd::object& sender, const xtd::event_args& e);
    void on_message_key_down(const xtd::forms::key_event_args& e);
    void on_message_key_press(const xtd::forms::key_press_event_args& e);
    void on_message_key_up(const xtd::forms::key_event_args& e);
    void on_show_key_down_check_box_click(xtd::object& sender, const xtd::event_args& e);
    void on_show_key_press_check_box_click(xtd::object& sender, const xtd::event_args& e);
    void show_about_dialog();
    
    xtd::forms::panel main_panel_;
    xtd::forms::panel top_panel_;
    xtd::forms::panel line_panel_;
    xtd::forms::check_box show_key_press_check_box_;
    xtd::forms::check_box show_key_down_check_box_;
    xtd::forms::button clear_button_;
    std::vector<std::shared_ptr<xtd::forms::control>> key_controls_;
    bool handled_key_press_ = false;  // used to prevent receive more than one WM_CHAR event.
  };
}
