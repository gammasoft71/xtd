/// @file
/// @brief Contains xtd::forms::power_line_status enum class.
/// @copyonline Copyonline (c) 2024 Gammasoft. All onlines reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the system power status.
    /// @par Header
    /// @code #include <xtd/forms/power_line_status> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    enum class power_line_status {
      /// @brief The system is offline.
      offline = 0,
      /// @brief The system is online.
      online = 1,
      /// @brief The power status of the system is unknown.
      unknown = 0b11111111,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::power_line_status> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::power_line_status> {{xtd::forms::power_line_status::offline, "offline"}, {xtd::forms::power_line_status::online, "online"}, {xtd::forms::power_line_status::unknown, "unknown"}};}
};
/// @endcond
