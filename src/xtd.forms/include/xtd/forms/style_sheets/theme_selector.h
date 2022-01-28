/// @file
/// @brief Contains xtd::forms::style_sheets::theme_selector class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <memory>
#include <vector>
#include <xtd/iequatable.h>
#include <xtd/object.h>
#include "../../forms_export.h"
#include "authors_property.h"
#include "description_property.h"
#include "name_property.h"
#include "website_property.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The theme data allows you to specify the theme informations.
      /// @code
      /// class forms_export_ theme_selector : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::forms::style_sheets::theme_selector
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      class forms_export_ theme_selector : public xtd::iequatable<theme_selector>, public xtd::object {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme_selector class.
        theme_selector() = default;
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme_selector class with specified name.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        explicit theme_selector(const xtd::forms::style_sheets::string_value& name);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme_selector class with specified name and description.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        theme_selector(const xtd::forms::style_sheets::string_value& name, const xtd::forms::style_sheets::string_value& description);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme_selector class with specified name, description and authors.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        theme_selector(const xtd::forms::style_sheets::string_value& name, const xtd::forms::style_sheets::string_value& description, const xtd::forms::style_sheets::string_value& authors);
        /// @brief Initializes a new instance of the xtd::forms::style_sheets::theme_selector class with specified name, description, authors and website.
        /// @param name The theme name.
        /// @param name The theme description.
        /// @param name The theme authors.
        /// @param name The theme website.
        theme_selector(const xtd::forms::style_sheets::string_value& name, const xtd::forms::style_sheets::string_value& description, const xtd::forms::style_sheets::string_value& authors, const xtd::forms::style_sheets::url_value& website);
        /// @}

        /// @cond
        theme_selector(const theme_selector&) = default;
        theme_selector(theme_selector&&) = default;
        theme_selector& operator=(const theme_selector&) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the theme authors.
        /// @return The theme authors.
        const xtd::forms::style_sheets::authors_property& authors() const noexcept;
        /// @brief Sets the theme authors.
        /// @param value The theme authors.
        void authors(const xtd::forms::style_sheets::authors_property& value) noexcept;
        
        /// @brief Gets the theme name.
        /// @return The theme name.
        const xtd::forms::style_sheets::description_property& description() const noexcept;
        /// @brief Sets the theme name.
        /// @param value The theme name.
        void description(const xtd::forms::style_sheets::description_property& value) noexcept;

        /// @brief Gets the theme name.
        /// @return The theme name.
        const xtd::forms::style_sheets::name_property& name() const noexcept;
        /// @brief Sets the theme name.
        /// @param value The theme name.
        void name(const xtd::forms::style_sheets::name_property& value) noexcept;

        /// @brief Gets the theme website.
        /// @return The theme website.
        const xtd::forms::style_sheets::website_property& website() const noexcept;
        /// @brief Sets the theme website.
        /// @param value The theme website.
        void website(const xtd::forms::style_sheets::website_property& value) noexcept;
        /// @}

        /// @name Methods
        
        /// @{
        bool equals(const object& other) const noexcept override {return is<theme_selector>(other) ? equals(static_cast<const theme_selector&>(other)) : false;}
        bool equals(const theme_selector& other) const noexcept override {return name_ == other.name_ && description_ == other.description_ && authors_ == other.authors_ && website_ == other.website_;}

        /// @brief Creates a xtd::forms::style_sheets::theme_selector object from the specified css text.
        /// @param css_text A css xtd::ustring that represents a xtd::forms::style_sheets::theme_selector object.
        /// @param result The xtd::forms::style_sheets::theme_selector class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool from_css(const xtd::ustring& css_text, theme_selector& result);

        /// @brief Creates a xtd::forms::style_sheets::theme_selector object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::theme_selector object.
        /// @return The xtd::forms::style_sheets::theme_selector class that this method creates.
        /// @exception xtd::argument_exception The text is not a xtd::forms::style_sheets::theme_selector object.
        static theme_selector parse(const xtd::ustring& text);

        xtd::ustring to_string() const noexcept override;

        /// @brief Return a xtd::string that represents the css format of the current xtd::forms::style_sheets::theme_selector object.
        /// @return A xtd::string that represents the css format of the current xtd::forms::style_sheets::theme_selector object.
        xtd::ustring to_css() const noexcept;
        
        /// @brief Creates a xtd::forms::style_sheets::theme_selector object from the specified text.
        /// @param text A xtd::ustring that represents a xtd::forms::style_sheets::theme_selector object.
        /// @param result The xtd::forms::style_sheets::theme_selector class that this method creates.
        /// @return true if succeed; otherwise false.
        static bool try_parse(const xtd::ustring& text, theme_selector& result);
        /// @}

      private:
        xtd::forms::style_sheets::name_property name_;
        xtd::forms::style_sheets::string_value description_;
        xtd::forms::style_sheets::string_value authors_;
        xtd::forms::style_sheets::website_property website_;
      };
    }
  }
}
