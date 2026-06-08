/// @file
/// @brief Contains xtd::forms::paint_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include "message.hpp"
#include <xtd/drawing/graphics>
#include <xtd/drawing/rectangle>
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::control::paint event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/paint_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks The xtd::forms::control::paint event occurs when a control is redrawn. A paint_event_args specifies the graphics to use to paint the control and the clip_rectangle in which to paint.
    class forms_export_ paint_event_args : public xtd::event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the paint_event_args class with the specified control, clipping rectangle.
      /// @param control The xtd::forms::control used to paint the item.
      /// @param clip_rectangle The xtd::drawing::rectangle that represents the rectangle in which to paint.
      /// @param message The xtd::forms::message that represents the message associate to this paint_event_args.
      /// @remarks The message is needed for xtd::forms::control::on_paint_ xtd::forms::control::on_paint_background to call def_wnd_proc method.
      paint_event_args(xtd::forms::control& control, const xtd::drawing::rectangle& clip_rectangle, xtd::forms::message& message);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the rectangle in which to paint.
      /// @return The xtd::drawing::rectangle in which to paint.
      [[nodiscard]] auto clip_rectangle() const noexcept -> const xtd::drawing::rectangle&;
      
      /// @brief Gets the graphics used to paint.
      /// @return The xtd::drawing::graphics object used to paint. The xtd::drawing::graphics object provides methods for drawing objects on the display device.
      [[nodiscard]] auto graphics() -> xtd::drawing::graphics&;
      
      /// @brief Gets the message associate to paint.
      /// @return The xtd::forms::message object associate to paint.
      [[nodiscard]] xtd::forms::message& message() noexcept;
      /// @}
      
    private:
      xtd::forms::control* control_ = nullptr;
      mutable xtd::sptr<xtd::drawing::graphics> graphics_;
      xtd::drawing::rectangle clip_rectangle_;
      xtd::forms::message* message_ = nullptr;
    };
  }
}
