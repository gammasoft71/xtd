#pragma once

#include <xtd/event_args.hpp>
#include <xtd/drawing/graphics.hpp>
#include <xtd/drawing/rectangle.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class paint_event_args : public event_args {
    public:
      paint_event_args() = default;
      paint_event_args(const drawing::rectangle& clip_rectangle, drawing::graphics& graphics) : clip_rectangle_(clip_rectangle), graphics_(&graphics) {};

      /// @cond
      paint_event_args(const paint_event_args& paint_event_args) = default;
      paint_event_args& operator=(const paint_event_args& paint_event_args) = default;
      /// @endcond

      const drawing::rectangle& clip_rectangle() const {return this->clip_rectangle_;}
      
      drawing::graphics& graphics() const {return *this->graphics_;}
      
    private:
      drawing::rectangle clip_rectangle_;
      drawing::graphics* graphics_ = nullptr;
    };
  }
}
