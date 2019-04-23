#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the operating system, or platform, supported by an assembly.
  /// @par Library
  /// Switch.Core
  /// @ingroup SwitchCore
  /// @see OperatingSystem
  enum class platform_id {
    /// @brief The operating system is unknown.
    unknown = -1,
    /// @brief The operating system is Win32s. Win32s is a layer that runs on 16-bit versions of Windows to provide access to 32-bit applications.
    win32s,
    /// @brief The operating system is Windows 95 or Windows 98.
    win32_windows,
    /// @brief The operating system is Windows NT or later.
    win32_nt,
    /// @brief The operating system is Windows CE.
    win_ce,
    /// @brief The operating system is Unix.
    unix,
    /// @brief The development platform is Xbox 360.
    xbox,
    /// @brief The operating system is Macintosh.
    mac_os_x,
    /// @brief The operating system is IOs Apple.
    ios,
    /// @brief The operating system is Android.
    android,
  };
}
