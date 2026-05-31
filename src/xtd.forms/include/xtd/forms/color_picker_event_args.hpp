/// @file
/// @brief Contains xtd::forms::color_picker_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/color>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::color_picker::color_picker_changed event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/color_picker_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class color_picker_event_args : public xtd::event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the color_picker_event_args class for the specified control.
      /// @param color The xtd::drawing::color that represent the xtd::forms::color_picker::color.
      explicit color_picker_event_args(const xtd::drawing::color& color) : color_(color) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the xtd::drawing::color that represent the xtd::forms::color_picker::color.
      /// @return The xtd::drawing::color that represent the xtd::forms::color_picker::color.
      [[nodiscard]] auto color() const noexcept -> const xtd::drawing::color& {return color_;}
      /// @}
      
    private:
      xtd::drawing::color color_;
    };
  }
}
