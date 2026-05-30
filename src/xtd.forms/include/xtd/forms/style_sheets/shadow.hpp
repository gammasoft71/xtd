/// @file
/// @brief Contains xtd::forms::style_sheets::shadow class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.hpp"
#include <xtd/drawing/color>
#include <xtd/drawing/point>
#include <xtd/iequatable>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The style specifies the shadow of text and elements.
      /// ```cpp
      /// class forms_export_ shadow : public xtd::iequatable<shadow>, public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::shadow
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/shadow>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ shadow : public xtd::iequatable<shadow>, public xtd::object {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief Provides a xtd::forms::style_sheets::shadow object with no xtd::forms::style_sheets::shadow.
        static const shadow empty;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::shadow class.
        shadow() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::shadow class with the offset point, radius, and color.
        /// @param offset The shadow offset point in pixels.
        /// @param radius The shadow blurring radius.
        /// @param color The shadow color.
        shadow(const xtd::drawing::point& offset, int32 radius, const xtd::drawing::color& color);
        /// @}
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the shadow color.
        /// @return The shadow color.
        [[nodiscard]] auto color() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the shadow color.
        /// @param value The shadow color.
        auto color(const xtd::drawing::color& value) noexcept -> void;
        /// @brief Gets the shadow offset in pixels.
        /// @return The shadow offset.
        [[nodiscard]] auto offset() const noexcept -> const xtd::drawing::point&;
        /// @brief Sets the shadow offset point in pixels.
        /// @param value The shadow offset point.
        auto offset(const xtd::drawing::point& value) noexcept -> void;
        /// @brief Gets the shadow blurring radius in pixels.
        /// @return The shadow blurring radius.
        [[nodiscard]] auto radius() const noexcept -> xtd::int32;
        /// @brief Sets the shadow blurring radius in pixels.
        /// @param value The shadow blurring radius.
        auto radius(xtd::int32 value) noexcept -> void;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const shadow& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        /// @}
        
      private:
        xtd::drawing::color color_;
        xtd::drawing::point offset_;
        int32 radius_ = 0;
      };
    }
  }
}
