/// @file
/// @brief Contains xtd::forms::style_sheets::border_color class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.hpp"
#include <xtd/drawing/color>
#include <xtd/iequatable>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::border_color is used to set the color of the borders.
      /// ```cpp
      /// class forms_export_ border_color : public xtd::iequatable<border_color>, public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_color
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/border_color>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_color : public xtd::iequatable<border_color>, public xtd::object {
      public:
        /// @name Public Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::border_color object.
        static const border_color empty;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color class.
        border_color() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color class using the supplied border_color for all edges.
        /// @param all The xtd::forms::style_sheets::color_data to be used for border_color for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        explicit border_color(const xtd::drawing::color& all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color class using a separate border_color for each edge.
        /// @param left The border_color for the left edge.
        /// @param top The border_color for the top edge.
        /// @param right The border_color for the right edge.
        /// @param bottom The border_color for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_color(const xtd::drawing::color& left, const xtd::drawing::color& top, const xtd::drawing::color& right, const xtd::drawing::color& bottom);
        /// @}
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_color value for all the edges.
        /// @return The xtd::forms::style_sheets::border_color for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color values are not equal.
        [[nodiscard]] auto all() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the xtd::forms::style_sheets::border_color value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_color for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color values are not equal.
        auto all(const xtd::drawing::color& all) noexcept -> void;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_color for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        [[nodiscard]] auto bottom() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the xtd::forms::style_sheets::border_color value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_color for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        auto bottom(const xtd::drawing::color& bottom) noexcept -> void;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color value for the left edge.
        /// @return The xtd::forms::style_sheets::border_color for the left edge.
        /// @remarks Setting this value can also alter the all property.
        [[nodiscard]] auto left() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the xtd::forms::style_sheets::border_color value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_color for the left edge.
        /// @remarks Setting this value can also alter the all property.
        auto left(const xtd::drawing::color& left) noexcept -> void;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color value for the right edge.
        /// @return The xtd::forms::style_sheets::border_color for the right edge.
        /// @remarks Setting this value can also alter the all property.
        [[nodiscard]] auto right() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the xtd::forms::style_sheets::border_color value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_color for the right edge.
        /// @remarks Setting this value can also alter the all property.
        auto right(const xtd::drawing::color& right) noexcept -> void;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color value for the top edge.
        /// @return The xtd::forms::style_sheets::border_color for the top edge.
        /// @remarks Setting this value can also alter the all property.
        [[nodiscard]] auto top() const noexcept -> const xtd::drawing::color&;
        /// @brief Sets the xtd::forms::style_sheets::border_color value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_color for the top edge.
        /// @remarks Setting this value can also alter the all property.
        auto top(const xtd::drawing::color& top) noexcept -> void;
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
        [[nodiscard]] auto equals(const border_color& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        /// @}
        
      private:
        bool all_ = true;
        xtd::drawing::color left_ = xtd::drawing::color::black;
        xtd::drawing::color top_ = xtd::drawing::color::black;
        xtd::drawing::color right_ = xtd::drawing::color::black;
        xtd::drawing::color bottom_ = xtd::drawing::color::black;
      };
    }
  }
}
