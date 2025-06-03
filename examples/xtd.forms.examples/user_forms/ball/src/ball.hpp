#pragma once
#include "ball_form.hpp"
#include "settings_form.hpp"
#include <xtd/drawing/texts>

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
    void on_mouse_down(const xtd::forms::mouse_event_args& e) override;

    /// @brief Raises the xtd::forms::control::mouse_move event.
    /// @param e An xtd::event_args that contains the event data.
    void on_mouse_move(const xtd::forms::mouse_event_args& e) override;

    /// @brief Raises the xtd::forms::control::mouse_up event.
    /// @param e An xtd::event_args that contains the event data.
    void on_mouse_up(const xtd::forms::mouse_event_args& e) override;
    /// @}

  private:
    void on_animation_timer_tick(xtd::object& sender, const xtd::event_args& e);
    void on_exit_menu_item_click(xtd::object& sender, const xtd::event_args& e);
    void on_settings_menu_item_click(xtd::object& sender, const xtd::event_args& e);

    settings_form settings_form_;
    xtd::forms::timer animation_timer_;
    xtd::forms::menu_item context_settings_menu_item_ {xtd::drawing::texts::settings(), {*this, &main_form::on_settings_menu_item_click}};
    xtd::forms::menu_item context_separator_menu_item_ {xtd::drawing::texts::separator()};
    xtd::forms::menu_item context_exit_menu_item_ {xtd::drawing::texts::exit(), {*this, &main_form::on_exit_menu_item_click}};
    xtd::forms::context_menu context_menu_ {context_settings_menu_item_, context_separator_menu_item_, context_exit_menu_item_};
    bool is_dragging_ = false;
    xtd::forms::panel main_panel_;
    xtd::drawing::point mouse_location_ = point::empty;
    xtd::drawing::point last_mouse_move_location_ = point::empty;
    xtd::drawing::point_f velocity = {0, 0};
  };
}
