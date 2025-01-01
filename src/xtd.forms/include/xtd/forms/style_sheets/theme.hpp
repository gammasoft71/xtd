/// @file
/// @brief Contains xtd::forms::style_sheets::theme class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../forms_export.hpp"
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/uri>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The theme data allows you to specify the theme informations.
      /// ```cpp
      /// class forms_export_ theme : public xtd::object
      /// ```
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::theme
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/style_sheets/theme>
      /// ```
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ theme : public xtd::iequatable<theme>, public xtd::object {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme class.
        theme() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme class with specified name.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        explicit theme(const xtd::string& name);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme class with specified name and description.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        theme(const xtd::string& name, const xtd::string& description);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme class with specified name, description and authors.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        theme(const xtd::string& name, const xtd::string& description, const xtd::string& authors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme class with specified name, description, authors and website.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        /// @param name The theme website.
        theme(const xtd::string& name, const xtd::string& description, const xtd::string& authors, const xtd::uri& website);
        /// @}
        
        /// @cond
        theme(const theme&) = default;
        theme(theme&&) = default;
        theme& operator =(const theme&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the theme authors.
        /// @return The theme authors.
        const xtd::string& authors() const noexcept;
        /// @brief Sets the theme authors.
        /// @param value The theme authors.
        void authors(const xtd::string& value) noexcept;
        
        /// @brief Gets the theme name.
        /// @return The theme name.
        const xtd::string& description() const noexcept;
        /// @brief Sets the theme name.
        /// @param value The theme name.
        void description(const xtd::string& value) noexcept;
        
        /// @brief Gets the theme name.
        /// @return The theme name.
        const xtd::string& name() const noexcept;
        /// @brief Sets the theme name.
        /// @param value The theme name.
        void name(const xtd::string& value) noexcept;
        
        /// @brief Gets the theme website.
        /// @return The theme website.
        const xtd::uri& website() const noexcept;
        /// @brief Sets the theme website.
        /// @param value The theme website.
        void website(const xtd::uri& value) noexcept;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        using object::equals;
        bool equals(const theme& other) const noexcept override {return name_ == other.name_ && description_ == other.description_ && authors_ == other.authors_ && website_ == other.website_;}
        
        xtd::string to_string() const noexcept override;
        
        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::theme object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::theme object.
        xtd::string to_css() const noexcept;
        /// @}
        
        /// @name Public Static Methods
        
        /// @{
        /// @brief Creates a xtd::forms::style_sheets::theme object from the specified css text.
        /// @param css_text A css xtd::string that represents a xtd::forms::style_sheets::theme object.
        /// @param result The xtd::forms::style_sheets::theme class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::string& css_text, theme& result);
        
        /// @brief Creates a xtd::forms::style_sheets::theme object from the specified text.
        /// @param text A xtd::string that represents a xtd::forms::style_sheets::theme object.
        /// @return The xtd::forms::style_sheets::theme class that this method creates.
        /// @exception xtd::argument_exception The text is not a xtd::forms::style_sheets::theme object.
        static theme parse(const xtd::string& text);
        
        /// @brief Creates a xtd::forms::style_sheets::theme object from the specified text.
        /// @param text A xtd::string that represents a xtd::forms::style_sheets::theme object.
        /// @param result The xtd::forms::style_sheets::theme class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool try_parse(const xtd::string& text, theme& result) noexcept;
        /// @}

      private:
        xtd::string name_;
        xtd::string description_;
        xtd::string authors_;
        xtd::uri website_;
      };
    }
  }
}
