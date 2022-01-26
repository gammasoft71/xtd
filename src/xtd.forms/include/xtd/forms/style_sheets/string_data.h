/// @file
/// @brief Contains xtd::forms::style_sheets::string_data class.
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
#include "color_data.h"
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
      /// class forms_export_ string_data : public xtd::object
      /// @par Implements
      /// xtd::iequatable <>
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::string_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class string_data : public xtd::iequatable<string_data>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::string_data class.
        string_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::string_data class with specified text.
        /// @param text The text value.
        string_data(const xtd::ustring& text);

        /// @cond
        string_data(const string_data&) = default;
        string_data(string_data&&) = default;
        string_data& operator=(const string_data&) = default;
        /// @endcond
        
        /// @brief Gets the text value.
        /// @return The the text value.
        const xtd::ustring& text() const noexcept;
        /// @brief Sets the text value.
        /// @param value The text value.
        void text(const xtd::ustring& value) noexcept;
        
        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<string_data>(other) ? equals(static_cast<const string_data&>(other)) : false;}
          bool equals(const string_data& other) const noexcept override {return text_ == other.text_;}
          
        /// @brief Creates a xtd::forms::style_sheets::url_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::string_data object.
        /// @param result The xtd::forms::style_sheets::string_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, string_data& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::string_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::string_data object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::string_data class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::string_data, the default_value is returned.
        static string_data from_css(const xtd::ustring& css_text, const string_data& default_value) noexcept;
        
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
