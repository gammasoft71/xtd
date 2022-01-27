/// @file
/// @brief Contains xtd::forms::style_sheets::string_value class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <xtd/object.h>
#include <xtd/iequatable.h>
#include <xtd/ustring.h>
#include <xtd/drawing/font.h>
#include <xtd/drawing/string_format.h>
#include <xtd/drawing/system_fonts.h>
#include <xtd/forms/content_alignment.h>
#include "color_property.h"
#include "text_decoration.h"
#include "text_transformation.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The text data allows you to specify the text.
      /// @code
      /// class forms_export_ string_value : public xtd::object
      /// @par Implements
      /// xtd::iequatable <>
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::string_value
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class string_value : public xtd::iequatable<string_value>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::string_value class.
        string_value() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::string_value class with specified text.
        /// @param text The text value.
        string_value(const xtd::ustring& text);

        /// @cond
        string_value(const string_value&) = default;
        string_value(string_value&&) = default;
        string_value& operator=(const string_value&) = default;
        /// @endcond
        
        /// @brief Gets the text value.
        /// @return The the text value.
        const xtd::ustring& text() const noexcept;
        /// @brief Sets the text value.
        /// @param value The text value.
        void text(const xtd::ustring& value) noexcept;
        
        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<string_value>(other) ? equals(static_cast<const string_value&>(other)) : false;}
        bool equals(const string_value& other) const noexcept override {return text_ == other.text_;}
          
        /// @brief Creates a xtd::forms::style_sheets::url_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::string_value object.
        /// @param result The xtd::forms::style_sheets::string_value class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, string_value& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::string_value object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::string_value object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::string_value class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::string_value, the default_value is returned.
        static string_value from_css(const xtd::ustring& css_text, const string_value& default_value) noexcept;
        
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::url_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::url_data object.
        xtd::ustring to_css() const noexcept;
        /// @}

      private:
        xtd::ustring text_;
      };
    }
  }
}
