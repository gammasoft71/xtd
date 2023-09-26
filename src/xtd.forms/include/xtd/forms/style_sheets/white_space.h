/// @file
/// @brief Contains xtd::forms::style_sheets::white_space enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The white_space enum class specifies how white-space inside an element is handled.
      /// @par Header
      /// @code #include <xtd/forms/style_sheets/white_space> @endcode
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      enum class white_space {
        /// @brief Sequences of whitespace will collapse into a single whitespace. Text will wrap when necessary. This is default
        normal,
        /// @brief Sequences of whitespace will collapse into a single whitespace. Text will never wrap to the next line. The text continues on the same line until a <br> tag is encountered
        no_wrap,
        /// @brief Whitespace is preserved by the browser. Text will only wrap on line breaks. Acts like the <pre> tag in HTML
        pre,
        /// @brief Sequences of whitespace will collapse into a single whitespace. Text will wrap when necessary, and on line breaks
        pre_line,
        /// @brief Whitespace is preserved by the browser. Text will wrap when necessary, and on line breaks
        pre_wrap,
      };
    }
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::style_sheets::white_space> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::style_sheets::white_space> {{xtd::forms::style_sheets::white_space::normal, "normal"}, {xtd::forms::style_sheets::white_space::no_wrap, "no_wrap"}, {xtd::forms::style_sheets::white_space::pre, "pre"}, {xtd::forms::style_sheets::white_space::pre_line, "pre_line"}, {xtd::forms::style_sheets::white_space::pre_wrap, "pre_wrap"}};}
};
/// @endcond
