#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include <xtd/drawing/point.h>
#include "message.h"
#include "mouse_buttons.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class button;
    class control;
    /// @endcond
    
    class mouse_event_args : public event_args {
    public:
      mouse_event_args() = default;
      
      mouse_event_args(mouse_buttons button, const drawing::point& location, int32_t clicks, int32_t delta) : button_(button), location_(location), clicks_(clicks), delta_(delta) {}
      mouse_event_args(mouse_buttons button, int32_t x, int32_t y, int32_t clicks, int32_t delta) : button_(button), location_(x, y), clicks_(clicks), delta_(delta) {}
      
      /// @cond
      mouse_event_args(const mouse_event_args& mouse_event_args) = default;
      mouse_event_args& operator=(const mouse_event_args& mouse_event_args) = default;
      /// @endcond
      
      mouse_buttons button() const {return this->button_;}
      
      const drawing::point& location() const {return this->location_;}
      
      int32_t clicks() const {return this->clicks_;}
      
      int32_t delta() const {return this->delta_;}
      
      int32_t x() const {return this->location().x();}
      
      int32_t y() const {return this->location().y();}
      
    private:
      friend class button;
      friend class control;
      static mouse_event_args create(const message& message, bool double_click_fired = false, int32_t delta = 0);
      mouse_buttons button_ = mouse_buttons::none;
      drawing::point location_;
      int32_t clicks_ = 0;
      int32_t delta_ = 0;
    };
  }
}
