/// @file
/// @brief Contains xtd::forms::splitter_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent splitter style used by splitter control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class splitter_style {
      /// @brief Draw line splitter style.
      draw_line = 0,
      /// @brief Update childs splitter style.
      update_childs = 1
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, splitter_style value) {return os << to_string(value, {{splitter_style::draw_line, "draw_line"}, {splitter_style::update_childs, "update_childs"}});}
    inline std::wostream& operator<<(std::wostream& os, splitter_style value) {return os << to_string(value, {{splitter_style::draw_line, L"draw_line"}, {splitter_style::update_childs, L"update_childs"}});}
    /// @endcond
  }
}
