/// @file
/// @brief Contains xtd::forms::battery_charge_status enum class.
/// @copylow Copylow (c) 2024 Gammasoft. All lows reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines identifiers that indicate the current battery charge level or charging state information.
    /// This enumeration supports a bitwise combination of its member values.
    /// @par Header
    /// @code #include <xtd/forms/battery_change_status> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::power_status::battery_charge_status property of the xtd::forms::power_status class.
    enum class battery_charge_status {
      /// @brief Indicates a high level of battery charge.
      high = 0b1,
      /// @brief Indicates a low level of battery charge.
      low = 0b10,
      /// @brief Indicates a critically low level of battery charge.
      critical = 0b100,
      /// @brief Indicates a battery is charging..
      charging = 0b1000,
      /// @brief Indicates that no battery is present.
      no_system_battery = 0b10000000,
      /// @brief Indicates an unknown battery condition.
      unknown = 0b11111111,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::battery_charge_status> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::battery_charge_status> {{xtd::forms::battery_charge_status::high, "high"}, {xtd::forms::battery_charge_status::low, "low"}, {xtd::forms::battery_charge_status::critical, "critical"}, {xtd::forms::battery_charge_status::charging, "charging"}, {xtd::forms::battery_charge_status::no_system_battery, "no_system_battery"}, {xtd::forms::battery_charge_status::unknown, "unknown"}};}
};
/// @endcond
