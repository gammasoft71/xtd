#pragma once
#include "ball_form.hpp"
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

  private:
    xtd::forms::panel main_panel_;
    xtd::forms::menu_item context_preference_menu_item_ {xtd::drawing::texts::preferences(), [&]{}};
    xtd::forms::menu_item context_separator_menu_item_ {"-"};
    xtd::forms::menu_item context_exit_menu_item_ {xtd::drawing::texts::exit(), {*this, &main_form::close}};
    xtd::forms::context_menu context_menu_ {context_preference_menu_item_, context_separator_menu_item_, context_exit_menu_item_};
    xtd::forms::timer animation_timer_;

    xtd::drawing::point mouse_location_ = point::empty;
    xtd::drawing::point last_mouse_move_location_ = point::empty;
    xtd::drawing::point_f velocity = {0, 0};
    
    bool is_dragging = false;    
  };
}
