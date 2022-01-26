/// @file
/// @brief Contains xtd::forms::style_sheets::url_data class.
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
      /// class forms_export_ url_data : public xtd::object
      /// @par Implements
      /// xtd::iequatable <>
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::url_data
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ url_data : public xtd::iequatable<url_data>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::url_data class.
        url_data() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::url_data class with specified url.
        /// @param text The url value.
        url_data(const xtd::ustring& uurl);
        /// @}

        /// @cond
        url_data(const url_data&) = default;
        url_data(url_data&&) = default;
        url_data& operator=(const url_data&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<url_data>(other) ? equals(static_cast<const url_data&>(other)) : false;}
        bool equals(const url_data& other) const noexcept override {return url_ == other.url_;}

        /// @brief Gets the url text.
        /// @return The the url text.
        const xtd::ustring& url() const noexcept;
        /// @brief Sets the url text.
        /// @param value The url text.
        void url(const xtd::ustring& value) noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        /// @brief Creates a xtd::forms::style_sheets::url_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::url_data object.
        /// @param result The xtd::forms::style_sheets::url_data class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, url_data& result) noexcept;
        /// @brief Creates a xtd::forms::style_sheets::url_data object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::url_data object.
        /// @param default_value The default_value is used if the specified text is invalid.
        /// @return The xtd::forms::style_sheets::url_data class that this method creates.
        /// @remarks If css_text is not a xtd::forms::sttyle_sheets::color_data, the default_value is returned.
        static url_data from_css(const xtd::ustring& css_text, const url_data& default_value) noexcept;

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::url_data object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::url_data object.
        xtd::ustring to_css() const noexcept;

        xtd::ustring to_string() const noexcept override;        
        /// @}

      private:
        xtd::ustring url_;
      };
    }
  }
}
