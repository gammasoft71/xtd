/// @file
/// @brief Contains xtd::forms::style_sheets::border_color_property class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/iequatable.h>
#include <xtd/ustring.h>
#include "color_property.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::border_color_property is used to set the color of the borders.
      /// @code
      /// class forms_export_ border_color_property : public xtd::iequatable<border_color_property>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::border_color_property
      /// @par Implements
      /// xtd::iequatable <>
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ border_color_property : public xtd::iequatable<border_color_property>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::border_color_property object.
        static const border_color_property empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class.
        border_color_property() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class using the supplied border_color_property for all edges.
        /// @param all The xtd::forms::style_sheets::color_data to be used for border_color_property for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        border_color_property(color_property all);
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::border_color_property class using a separate border_color_property for each edge.
        /// @param left The border_color_property for the left edge.
        /// @param top The border_color_property for the top edge.
        /// @param right The border_color_property for the right edge.
        /// @param bottom The border_color_property for the bottom edge.
        /// @remarks If all of the parameter values are equal, then the all property will reflect this common value.
        border_color_property(color_property left, color_property top, color_property right, color_property bottom);
        /// @}
        
        /// @cond
        border_color_property(const border_color_property&) = default;
        border_color_property& operator=(const border_color_property&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for all the edges.
        /// @return The xtd::forms::style_sheets::border_color_property for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color_property value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color_property values are not equal.
        color_property all() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for all the edges.
        /// @param all The xtd::forms::style_sheets::border_color_property for all edges if the same; otherwise, xtd::forms::style_sheets::color_data::empty.
        /// @remarks When retrieving this property, if all the edges use the same border_color_property value, then this common value is returned. Otherwise, xtd::forms::style_sheets::color_data::empty is returned to indicate that all the xtd::forms::style_sheets::border_color_property values are not equal.
        void all(color_property all) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the bottom edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        color_property bottom() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the bottom edge.
        /// @param bottom The xtd::forms::style_sheets::border_color_property for the bottom edge.
        /// @remarks Setting this value can also alter the all property.
        void bottom(color_property bottom) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the left edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        color_property left() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the left edge.
        /// @param left The xtd::forms::style_sheets::border_color_property for the left edge.
        /// @remarks Setting this value can also alter the all property.
        void left(color_property left) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the right edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        color_property right() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the right edge.
        /// @param right The xtd::forms::style_sheets::border_color_property for the right edge.
        /// @remarks Setting this value can also alter the all property.
        void right(color_property right) noexcept;
        
        /// @brief Gets the xtd::forms::style_sheets::border_color_property value for the top edge.
        /// @return The xtd::forms::style_sheets::border_color_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        color_property top() const noexcept;
        /// @brief Sets the xtd::forms::style_sheets::border_color_property value for the top edge.
        /// @param top The xtd::forms::style_sheets::border_color_property for the top edge.
        /// @remarks Setting this value can also alter the all property.
        void top(color_property top) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{        
        bool equals(const object& other) const noexcept override;
        bool equals(const border_color_property& other) const noexcept override;
        
        /// @brief Creates a xtd::forms::style_sheets::border_color_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::border_color_property object.
        /// @param result The xtd::forms::style_sheets::border_color_property class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, border_color_property& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::border_color_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::border_color_property object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::border_color_property class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::color_property, the default_value is returned.
        static border_color_property from_css(const xtd::ustring& css_text, const border_color_property& default_value) noexcept;
        
        /// @brief Splits a specified text into an array of string tht contains a representation for each xtd::forms::style_sheets::color_property.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::color_property object.
        /// @return The xtd::ustrings that contains a representation of each xtd::forms::style_sheets::color_property.
        static std::vector<xtd::ustring> split_colors(const xtd::ustring& text);

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::color_property object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::color_property object.
        xtd::ustring to_css() const noexcept;
        /// @}
        
      private:
        bool all_ = true;
        color_property left_ {xtd::drawing::color::black};
        color_property top_ {xtd::drawing::color::black};
        color_property right_ {xtd::drawing::color::black};
        color_property bottom_ {xtd::drawing::color::black};
      };
    }
  }
}
