/// @file
/// @brief Contains xtd::forms::style_sheets::shadow class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export"
#include <xtd/drawing/color>
#include <xtd/drawing/point>
#include <xtd/iequatable>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The style specifies the shadow of text and elements.
      /// @code
      /// class forms_export_ shadow : public xtd::iequatable<shadow>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::shadow
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/shadow> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ shadow : public xtd::iequatable<shadow>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::shadow object with no xtd::forms::style_sheets::shadow.
        static const shadow empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::shadow class.
        shadow() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::shadow class with the offset point, radius, and color.
        /// @param offset The shadow offset point in pixels.
        /// @param radius The shadow blurring radius.
        /// @param color The shadow color.
        shadow(const xtd::drawing::point& offset, int32 radius, const xtd::drawing::color& color);
        /// @}
        
        /// @cond
        shadow(const shadow&) = default;
        shadow& operator =(const shadow&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the shadow color.
        /// @return The shadow color.
        const xtd::drawing::color& color() const noexcept;
        /// @brief Sets the shadow color.
        /// @param value The shadow color.
        void color(const xtd::drawing::color& value) noexcept;
        /// @brief Gets the shadow offset in pixels.
        /// @return The shadow offset.
        const xtd::drawing::point& offset() const noexcept;
        /// @brief Sets the shadow offset point in pixels.
        /// @param value The shadow offset point.
        void offset(const xtd::drawing::point& value) noexcept;
        /// @brief Gets the shadow blurring radius in pixels.
        /// @return The shadow blurring radius.
        int32 radius() const noexcept;
        /// @brief Sets the shadow blurring radius in pixels.
        /// @param value The shadow blurring radius.
        void radius(int32 value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const shadow& other) const noexcept override;
        /// @}
        
      private:
        xtd::drawing::color color_;
        xtd::drawing::point offset_;
        int32 radius_ = 0;
      };
    }
  }
}
