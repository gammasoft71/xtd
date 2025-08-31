/// @file
/// @brief Contains xtd::forms::mouse_event_args event args.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "message.hpp"
#include "mouse_buttons.hpp"
#include <xtd/drawing/point>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class button;
    class control;
    class check_box;
    class light_button;
    class radio_button;
    class toggle_button;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::control::mouse_up, xtd::forms::control::mouse_down, and xtd::forms::control::mouse_move events.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/mouse_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class forms_export_ mouse_event_args : public event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the MouseEventArgs class.
      mouse_event_args() = default;
      /// @brief Initializes a new instance of the MouseEventArgs class.
      /// @param button One of the xtd::forms::mouse_buttons values that indicate which mouse button was pressed.
      /// @param clicks The number of times a mouse button was pressed.
      /// @param x The x-coordinate of a mouse click, in pixels.
      /// @param y The y-coordinate of a mouse click, in pixels.
      /// @param delta A signed count of the number of detents the wheel has rotated.
      mouse_event_args(mouse_buttons button, int32 clicks, int32 x, int32 y, int32 delta) : button_(button), location_(x, y), clicks_(clicks), delta_(delta) {}
      /// @brief Initializes a new instance of the MouseEventArgs class.
      /// @param button One of the xtd::forms::mouse_buttons values that indicate which mouse button was pressed.
      /// @param clicks The number of times a mouse button was pressed.
      /// @param location The location of a mouse click, in pixels.
      /// @param delta A signed count of the number of detents the wheel has rotated.
      mouse_event_args(mouse_buttons button, int32 clicks, const drawing::point& location, int32 delta) : button_(button), location_(location), clicks_(clicks), delta_(delta) {}
      /// @}
      
      /// @cond
      mouse_event_args(const mouse_event_args& mouse_event_args) = default;
      mouse_event_args& operator =(const mouse_event_args& mouse_event_args) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets which mouse button was pressed.
      /// @return One of the xtd::forms::mouse_buttons values.
      mouse_buttons button() const noexcept {return button_;}
      
      /// @brief Gets the number of times the mouse button was pressed and released.
      /// @return An std::int32_t that contains the number of times the mouse button was pressed and released.
      int32 clicks() const noexcept {return clicks_;}
      
      /// @brief Gets a signed count of the number of detents the mouse wheel has rotated, multiplied by the WHEEL_DELTA constant. A detent is one notch of the mouse wheel.
      /// @return A signed count of the number of detents the mouse wheel has rotated, multiplied by the WHEEL_DELTA constant.
      int32 delta() const noexcept {return delta_;}
      
      /// @brief Gets the location of the mouse during the generating mouse event.
      /// @return A xtd::drawing::point that contains the x- and y- mouse coordinates, in pixels, relative to the upper-left corner of the form.
      const drawing::point& location() const noexcept {return location_;}
      
      /// @brief Gets the x-coordinate of the mouse during the generating mouse event.
      /// @return The x-coordinate of the mouse, in pixels.
      int32 x() const noexcept {return location().x;}
      
      /// @brief Gets the y-coordinate of the mouse during the generating mouse event.
      /// @return The y-coordinate of the mouse, in pixels.
      int32 y() const noexcept {return location().y;}
      /// @}
      
    private:
      friend class button;
      friend class control;
      friend class check_box;
      friend class light_button;
      friend class radio_button;
      friend class toggle_button;
      static mouse_event_args create(const message& message, bool double_click_fired = false, int32 delta = 0);
      mouse_buttons button_ = mouse_buttons::none;
      drawing::point location_;
      int32 clicks_ = 0;
      int32 delta_ = 0;
    };
  }
}
