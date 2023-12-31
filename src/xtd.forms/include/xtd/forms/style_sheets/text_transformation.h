/// @file
/// @brief Contains xtd::forms::style_sheets::text_transformation enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::text_transformation enum class  is used to specify uppercase and lowercase letters in a text.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/text_transformation> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks It can be used to turn everything into uppercase or lowercase letters, or capitalize the first letter of each word
      enum class text_transformation {
        /// @brief Defines none text transformation.
        none,
        /// @brief Defines a lowercase text transformation
        lowercase,
        /// @brief Defines a uppercase text transformation.
        uppercase,
        /// @brief Defines a capitalize text transformation.
        capitalize,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::style_sheets::text_transformation> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::text_transformation> {{xtd::forms::style_sheets::text_transformation::none, "none"}, {xtd::forms::style_sheets::text_transformation::lowercase, "lowercase"}, {xtd::forms::style_sheets::text_transformation::uppercase, "uppercase"}, {xtd::forms::style_sheets::text_transformation::capitalize, "capitalize"}};}
};
/// @endcond
