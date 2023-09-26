#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    enum class notifier_style {
      standard = 0,
      system = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::notifier_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::notifier_style> {{xtd::forms::notifier_style::standard, "standard"}, {xtd::forms::notifier_style::system, "system"}};}
};
/// @endcond
