#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class about_dialog_style {
      standard = 0,
      system = 1,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, about_dialog_style value) {return os << to_string(value, {{about_dialog_style::standard, "standard"}, {about_dialog_style::system, "system"}});}
    inline std::wostream& operator<<(std::wostream& os, about_dialog_style value) {return os << to_string(value, {{about_dialog_style::standard, L"standard"}, {about_dialog_style::system, L"system"}});}
    /// @endcond
  }
}
