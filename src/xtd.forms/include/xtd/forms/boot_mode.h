/// @file
/// @brief Contains xtd::forms::boot_mode enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Specifies the mode to start the computer in.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd::forms
    /// @ingroup xtd_forms
    /// @remarks This enumeration defines identifiers that represent the standard operating system startup modes.
    /// @remarks This enumeration is used by the boot_mode property of the system_information class.
    /// @remarks The normal boot mode is the standard system startup mode. The fail_safe boot mode is also called safe mode. The fail_safe_with_network boot mode is also called safe mode with networking.
    enum class boot_mode {
      /// @brief Starts the computer in standard mode.
      normal = 0,
      /// @brief Starts the computer by using only the basic files and drivers.
      fail_safe = 1,
      /// @brief Starts the computer by using the basic files, drivers and the services and drivers necessary to start networking.
      fail_safe_with_network = 2,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, boot_mode value) {return os << to_string(value, {{boot_mode::normal, "normal"}, {boot_mode::fail_safe, "fail_safe"}, {boot_mode::fail_safe_with_network, "fail_safe_with_network"}});}
    inline std::wostream& operator<<(std::wostream& os, boot_mode value) {return os << to_string(value, {{boot_mode::normal, L"normal"}, {boot_mode::fail_safe, L"fail_safe"}, {boot_mode::fail_safe_with_network, L"fail_safe_with_network"}});}
    /// @endcond
  }
}
