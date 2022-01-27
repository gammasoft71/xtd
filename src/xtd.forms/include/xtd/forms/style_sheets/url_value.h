/// @file
/// @brief Contains xtd::forms::style_sheets::url_value class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/iequatable.h>
#include <xtd/ustring.h>
#include "../../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The url data allows you to specify the text url.
      /// @code
      /// class forms_export_ url_value : public xtd::object
      /// @par Implements
      /// xtd::iequatable <>
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::url_value
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ url_value : public xtd::iequatable<url_value>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::url_value class.
        url_value() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::url_value class with specified url.
        /// @param url The url value.
        url_value(const xtd::ustring& url);
        /// @}

        /// @cond
        url_value(const url_value&) = default;
        url_value(url_value&&) = default;
        url_value& operator=(const url_value&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<url_value>(other) ? equals(static_cast<const url_value&>(other)) : false;}
        bool equals(const url_value& other) const noexcept override {return url_ == other.url_;}

        /// @brief Gets the url text.
        /// @return The the url text.
        const xtd::ustring& url() const noexcept;
        /// @brief Sets the url text.
        /// @param value The url text.
        void url(const xtd::ustring& value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Creates a xtd::forms::style_sheets::url_value object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::url_value object.
        /// @param result The xtd::forms::style_sheets::url_value class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, url_value& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::url_value object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::url_value object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::url_value class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::color_data, the default_value is returned.
        static url_value from_css(const xtd::ustring& css_text, const url_value& default_value) noexcept;

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::url_value object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::url_value object.
        xtd::ustring to_css() const noexcept;

        xtd::ustring to_string() const noexcept override;        
        /// @}

      private:
        xtd::ustring url_;
      };
    }
  }
}
