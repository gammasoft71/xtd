/// @file
/// @brief Contains xtd::forms::power_state enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/enum>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Defines identifiers that indicate a suspended system power activity mode.
    /// @par Header
    /// @code #include <xtd/forms/power_state> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration is used by the xtd::forms::application::set_suspend_state method of the xtd::forms::application class.
    enum class power_state {
      /// @brief Indicates a system suspended power mode. When a system is suspended, the computer switches to a low-power state called standby. When a computer is in standby mode, some devices are turned off and the computer uses less power. The system can restore itself more quickly than returning from hibernation. Because standby does not save the memory state to disk, a power failure while in standby can cause loss of information.
      suspend = 0,
      /// @brief Indicates a system hibernation power mode. When a system enters hibernation, the contents of its memory are saved to disk before the computer is turned off. When the system is restarted, the desktop and previously active programs are restored.
      hibernate = 1,
    };
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::forms::power_state> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::forms::power_state> {{xtd::forms::power_state::suspend, "suspend"}, {xtd::forms::power_state::hibernate, "hibernate"}};}
};
/// @endcond
