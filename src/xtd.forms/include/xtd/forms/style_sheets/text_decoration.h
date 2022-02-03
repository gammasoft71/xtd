/// @file
/// @brief Contains xtd::forms::style_sheets::text_decoration enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::style_sheets namespace contains various properties, states, and subcontrols that make it possible to customize the look of control.
    namespace style_sheets {
      /// @brief The xtd::forms::style_sheets::text_decoration enum class is used to set or remove decorations from text.
      /// @par Namespace
      /// xtd::forms::style_sheets
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms style_sheets
      /// @remarks The value xtd::forms::style_sheets::text_decoration::none; is often used to remove underlines from links.
      /// @note  It is not recommended to underline text that is not a link, as this often confuses the reader.
      enum class text_decoration {
        /// @brief Defines none text decoration.
        none,
        /// @brief Defines a overline text decoration.
        overline,
        /// @brief Defines a line through text decoration.
        line_through,
        /// @brief Defines a underline text decoration.
        underline,
      };
      
      /// @cond
      inline std::ostream& operator<<(std::ostream& os, const text_decoration value) {return os << to_string(value, {{text_decoration::none, "none"}, {text_decoration::overline, "overline"}, {text_decoration::line_through, "line_through"}, {text_decoration::underline, "underline"}});}
      inline std::wostream& operator<<(std::wostream& os, const text_decoration value) {return os << to_string(value, {{text_decoration::none, L"none"}, {text_decoration::overline, L"overline"}, {text_decoration::line_through, L"line_through"}, {text_decoration::underline, L"underline"}});}
      /// @endcond
    }
  }
}
