#pragma once

#include <xtd/event_args.hpp>
#include <xtd/point.hpp>
#include "mouse_buttons.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class mouse_event_args : public xtd::event_args {
    public:
      mouse_event_args() = default;
      
      mouse_event_args(xtd::forms::mouse_buttons button, const xtd::drawing::point& location, int clicks, int delta) : button_(button), location_(location), clicks_(clicks), delta_(delta) {}
      mouse_event_args(xtd::forms::mouse_buttons button, int x, int y, int clicks, int delta) : button_(button), location_({x, y}), clicks_(clicks), delta_(delta) {}
      
      /// @cond
      mouse_event_args(const xtd::forms::mouse_event_args& mouse_event_args) = default;
      mouse_event_args& operator=(const xtd::forms::mouse_event_args& mouse_event_args) = default;
      /// @endcond
      
      xtd::forms::mouse_buttons button() {return this->button_;}
      
      const xtd::drawing::point& location() {return this->location_;}
      
      int clicks() {return this->clicks_;}
      
      int delta() {return this->delta_;}
      
      int x() {return this->location().x();}
      
      int y() {return this->location().y();}
      
    private:
      mouse_buttons button_ = mouse_buttons::none;
      xtd::drawing::point location_;
      int clicks_ = 0;
      int delta_ = 0;
    };
  }
}
