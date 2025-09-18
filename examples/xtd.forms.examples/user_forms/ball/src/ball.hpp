#pragma once
#include "ball_form.hpp"
#include "settings_form.hpp"

/// @brief Represents the ball widget application namespace.
namespace ball {
  /// @brief Represents the main forms of the ball widget application.
  class main_form : public ball_form {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialises a new instance of ball::main_form class.
    main_form();
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief The main entry point for the ball widget.
    static void main();
    /// @}

  protected:
    /// @name Protected Methods
    
    /// @{
    /// @brief Raises the xtd::forms::control::mouse_down event.
    /// @param e An xtd::event_args that contains the event data.
    void on_mouse_down(const mouse_event_args& e) override;

    /// @brief Raises the xtd::forms::control::mouse_move event.
    /// @param e An xtd::event_args that contains the event data.
    void on_mouse_move(const mouse_event_args& e) override;

    /// @brief Raises the xtd::forms::control::mouse_up event.
    /// @param e An xtd::event_args that contains the event data.
    void on_mouse_up(const mouse_event_args& e) override;
    /// @}

  private:
    void on_animation_timer_tick(object& sender, const event_args& e);
    void on_exit_menu_item_click(object& sender, const event_args& e);
    void on_settings_changed(object& sender, const event_args& e);
    void on_settings_menu_item_click(object& sender, const event_args& e);

    settings_form settings_form_;
    forms::timer animation_timer_;
    menu_item context_settings_menu_item_ {drawing::texts::settings(), event_handler {*this, &main_form::on_settings_menu_item_click}};
    menu_item context_separator_menu_item_ {drawing::texts::separator()};
    menu_item context_exit_menu_item_ {drawing::texts::exit(), event_handler {*this, &main_form::on_exit_menu_item_click}};
    forms::context_menu context_menu_ {context_settings_menu_item_, context_separator_menu_item_, context_exit_menu_item_};
    bool is_dragging_ = false;
    panel main_panel_;
    drawing::point mouse_location_ = point::empty;
    drawing::point last_mouse_move_location_ = point::empty;
    point_f velocity = {0, 0};
  };
}
