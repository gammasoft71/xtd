#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class splitter_style {
      draw_line = 0,
      update_childs = 1
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, splitter_style value) {return os << to_string(value, {{splitter_style::draw_line, "draw_line"}, {splitter_style::update_childs, "update_childs"}});}
    inline std::wostream& operator<<(std::wostream& os, splitter_style value) {return os << to_string(value, {{splitter_style::draw_line, L"draw_line"}, {splitter_style::update_childs, L"update_childs"}});}
    /// @endcond
  }
}
