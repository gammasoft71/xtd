/// @file
/// @brief Contains xtd::forms::paint_event_args event args.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_args.h>
#include <xtd/drawing/graphics.h>
#include <xtd/drawing/rectangle.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond;
    
    /// @brief Provides data for the paint event.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The paint event occurs when a control is redrawn. A paint_event_args specifies the graphics to use to paint the control and the clip_rectangle in which to paint.
    class forms_export_ paint_event_args : public event_args {
    public:
      /// @brief Initializes a new instance of the paint_event_args class.
      paint_event_args() = default;
      /// @brief Initializes a new instance of the paint_event_args class with the specified control, clipping rectangle.
      /// @param control The control used to paint the item.
      /// @param clip_rectangle The xtd::drawing::rectangle that represents the rectangle in which to paint.
      paint_event_args(control& control, const drawing::rectangle& clip_rectangle) : control_(&control), clip_rectangle_(clip_rectangle) {};

      /// @cond
      paint_event_args(const paint_event_args& paint_event_args) = default;
      paint_event_args& operator=(const paint_event_args& paint_event_args) = default;
      /// @endcond

      /// @brief Gets the rectangle in which to paint.
      /// @return The xtd::drawing::rectangle in which to paint.urn
      const drawing::rectangle& clip_rectangle() const {return clip_rectangle_;}
      
      /// @brief Gets the graphics used to paint.
      /// @return The xtd::drawing::graphics object used to paint. The xtd::drawing::graphics object provides methods for drawing objects on the display device.
      drawing::graphics graphics() const;
      
    private:
      control* control_;
      drawing::rectangle clip_rectangle_;
    };
  }
}
