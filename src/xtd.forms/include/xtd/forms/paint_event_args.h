/// @file
/// @brief Contains xtd::forms::paint_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include "message.h"
#include <xtd/drawing/graphics>
#include <xtd/drawing/rectangle>
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::control::paint event.
    /// @par Header
    /// @code #include <xtd/forms/paint_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The xtd::forms::control::paint event occurs when a control is redrawn. A paint_event_args specifies the graphics to use to paint the control and the clip_rectangle in which to paint.
    class forms_export_ paint_event_args : public event_args {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the paint_event_args class with the specified control, clipping rectangle.
      /// @param control The xtd::forms::control used to paint the item.
      /// @param clip_rectangle The xtd::drawing::rectangle that represents the rectangle in which to paint.
      paint_event_args(xtd::forms::control& control, const drawing::rectangle& clip_rectangle);
      /// @brief Initializes a new instance of the paint_event_args class with the specified control, clipping rectangle.
      /// @param graphics_ The xtd::drawing::graphics used to paint the item.
      /// @param clip_rectangle The xtd::drawing::rectangle that represents the rectangle in which to paint.
      paint_event_args(xtd::drawing::graphics& graphics, const drawing::rectangle& clip_rectangle);
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the rectangle in which to paint.
      /// @return The xtd::drawing::rectangle in which to paint.
      const drawing::rectangle& clip_rectangle() const noexcept;
      
      /// @brief Gets the graphics used to paint.
      /// @return The xtd::drawing::graphics object used to paint. The xtd::drawing::graphics object provides methods for drawing objects on the display device.
      drawing::graphics& graphics();
      /// @}
      
    private:
      friend class xtd::forms::control;
      xtd::forms::control* control_ = nullptr;
      mutable std::unique_ptr<xtd::drawing::graphics> graphics_;
      xtd::drawing::rectangle clip_rectangle_;
      xtd::forms::message message_; // need for xtd::forms::control::on_paint_ xtd::forms::control::on_paint_background to call def_wnd_proc method.
    };
  }
}
