#pragma once
#include <xtd/event_args.h>
#include <xtd/drawing/point.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond

    /// @brief Provides data for the control_added and control_removed events.
    class help_event_args : public event_args {
    public:
      /// @cond
      help_event_args(const help_event_args& control_event_args) = default;
      help_event_args& operator=(const help_event_args& help_event_args) = default;
      /// @endcond
      
      /// @brief Initializes a new instance of the help_event_args class.
      /// @param mouse_pos The coordinates of the mouse pointer.
      help_event_args(const drawing::point& mouse_pos) : mouse_pos_(mouse_pos) {}
      
      bool handled() const {return this->handled_;}
      void handled(bool handled) {this->handled_ = handled;}

      drawing::point mouse_pos() const {return this->mouse_pos_;}
      void mouse_pos(const drawing::point& mouse_pos) {this->mouse_pos_ = mouse_pos;}
      
    private:
      bool handled_ = false;
      drawing::point mouse_pos_;
    };
  }
}
