/// @file
/// @brief Contains xtd::forms::style_sheets::height_property class.
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
      /// @brief The xtd::forms::style_sheets::height_property is used to set the height of the control.
      /// @code
      /// class forms_export_ height_property :  public xtd::iequatable<height_property>, public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::height_property
      /// @par Implements
      /// xtd::iequatable <>
      /// @par
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ height_property : public xtd::iequatable<height_property>, public xtd::object {
      public:
        /// @name Fields
        
        /// @{
        /// @brief Provides an empty xtd::forms::style_sheets::height_property object.
        static const height_property empty;
        /// @}
        
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::height_property class.
        height_property() = default;
        
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::height_property class using the supplied height_property for all edges.
        /// @param all The xtd::forms::style_sheets::color_data to be used for height_property for all edges.
        /// @remarks This constructor sets the right, left, bottom, top and all properties to the value of the all parameter.
        height_property(int32_t height) : height_(height) {}
        /// @}
        
        /// @cond
        height_property(const height_property&) = default;
        height_property& operator=(const height_property&) = default;
        /// @endcond
        
        /// @name Peorperties
        
        /// @{
        /// @brief Gets the height value.
        /// @return The height value.
        int32_t height() const noexcept;
        /// @brief Sets the height value.
        /// @param value The height value.
        void height(int32_t value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override;
        bool equals(const height_property& other) const noexcept override;
        
        /// @brief Creates a xtd::forms::style_sheets::height_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::height_property object.
        /// @param result The xtd::forms::style_sheets::height_property class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, height_property& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::height_property object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::height_property object.
        /// @param default_value The default_value is used if the specified css text is invalid.
        /// @return The xtd::forms::style_sheets::height_property class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::height_property, the default_value is returned.
        static height_property from_css(const xtd::ustring& css_text, const height_property& default_value) noexcept;
        
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::height_property object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::height_property object.
        xtd::ustring to_css() const noexcept;
        /// @}
        
      private:
        int32_t height_ = -1;
      };
    }
  }
}
