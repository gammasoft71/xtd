/// @file
/// @brief Contains main_form class.
#pragma once
#include <xtd/overload>
#include <xtd/forms/button>
#include <xtd/forms/check_box>
#include <xtd/forms/control>
#include <xtd/forms/form>
#include <xtd/forms/main_menu>
#include <xtd/forms/menu_images>
#include <xtd/forms/menu_item>
#include <xtd/forms/panel>
#include <xtd/drawing/texts>

/// @brief Represents the namespace that contains application objects.
namespace keycodes {
  /// @brief Represents the main form.
  class main_form : public xtd::forms::form {
  public:
    /// @brief The main entry point for the application.
    static auto main() -> void;
    
    /// @brief Initializes a new instance of the form1 class.
    main_form();
    
  private:
    bool pre_process_message(const xtd::forms::message& message) override;
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
    xtd::forms::menu_item file_clear_menu_item_ {xtd::drawing::texts::clear(), {*this, &main_form::on_clear_button_click}, xtd::forms::menu_images::from_name("edit-delete"), xtd::forms::shortcut::cmd_del};
    xtd::forms::menu_item file_separator1_menu_item_ {"-"};
    xtd::forms::menu_item file_exit_menu_item_ {xtd::drawing::texts::exit(), overload_<>(&xtd::forms::application::exit), xtd::forms::menu_images::file_exit(), xtd::forms::shortcut::alt_f4};
    xtd::forms::menu_item file_menu_item_ {xtd::drawing::texts::file(), {file_clear_menu_item_, file_separator1_menu_item_, file_exit_menu_item_}};
    xtd::forms::menu_item help_about_menu_item_ {xtd::drawing::texts::about(), {*this, &main_form::show_about_dialog}, xtd::forms::menu_images::help_about()};
    xtd::forms::menu_item help_menu_item_ {xtd::drawing::texts::help(), {help_about_menu_item_}};
    xtd::forms::main_menu main_menu_ {file_menu_item_, help_menu_item_};
    std::vector<std::shared_ptr<xtd::forms::control>> key_controls_;
    bool handled_key_press_ = false;  // used to prevent receive more than one WM_CHAR event.
  };
}
