/// @file
/// @brief Contains xtd::forms::font_picker_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond
    
    /// @brief Provides data for the xtd::forms::font_picker::font_picker_changed events.
    /// @par Header
    /// @code #include <xtd/forms/font_picker_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class font_picker_event_args : public event_args {
    public:
      /// @cond
      font_picker_event_args(const font_picker_event_args& font_picker_event_args) = default;
      font_picker_event_args& operator =(const font_picker_event_args& font_picker_event_args) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the font_picker_event_args class for the specified control.
      /// @param font The xtd::drawing::font that represent the xtd::forms::font_picker::font.
      /// @param color The xtd::drawing::color that represent the xtd::forms::font_picker::color.
      explicit font_picker_event_args(const xtd::drawing::font& font, const xtd::drawing::color& color) : color_(color), font_(font) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the xtd::drawing::color that represent the xtd::forms::font_picker::color.
      /// @return The xtd::drawing::color that represent the xtd::forms::font_picker::color.
      const xtd::drawing::color& color() const noexcept {return color_;}
      
      /// @brief Gets the xtd::drawing::font that represent the xtd::forms::font_picker::font.
      /// @return The xtd::drawing::font that represent the xtd::forms::font_picker::font.
      const xtd::drawing::font& font() const noexcept {return font_;}
      //// @}
      
    private:
      xtd::drawing::color color_;
      xtd::drawing::font font_;
    };
  }
}
