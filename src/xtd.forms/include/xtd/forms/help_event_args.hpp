/// @file
/// @brief Contains xtd::forms::help_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/point>
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::control::control_added and xtd::forms::control::control_removed events.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/help_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class help_event_args : public event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::help_event_args class.
      /// @param mouse_pos The coordinates of the mouse pointer.
      explicit help_event_args(const drawing::point& mouse_pos) : mouse_pos_(mouse_pos) {}
      /// @}
      
      /// @cond
      help_event_args(const help_event_args& control_event_args) = default;
      help_event_args& operator =(const help_event_args& help_event_args) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the help event was handled.
      /// @return true if the event is handled; otherwise, false. The default is false.
      /// @remarks If you do not set this property to true the event will be passed to Windows for additional processing.
      bool handled() const noexcept {return handled_;}
      /// @brief Sets a value indicating whether the help event was handled.
      /// @param handled true if the event is handled; otherwise, false. The default is false.
      /// @remarks If you do not set this property to true the event will be passed to Windows for additional processing.
      void handled(bool handled) {handled_ = handled;}
      
      /// @brief Gets the screen coordinates of the mouse pointer.
      /// @return A xtd::drawing::point representing the screen coordinates of the mouse pointer.
      /// @remarks You can use this information to provide help based on the position of the mouse pointer.
      xtd::drawing::point mouse_pos() const noexcept {return mouse_pos_;}
      /// @}
      
    private:
      bool handled_ = false;
      drawing::point mouse_pos_;
    };
  }
}
