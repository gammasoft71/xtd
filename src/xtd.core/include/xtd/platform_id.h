/// @file
/// @brief Contains xtd::platform_id enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"
#undef unix

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the operating system, or platform, supported by an assembly.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @see operating_system
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
    macos,
    /// @brief The operating system is IOs Apple.
    ios,
    /// @brief The operating system is Android.
    android,
  };

  inline std::ostream& operator<<(std::ostream& os, platform_id value) {return os << to_string(value, {{platform_id::unknown, "unknown"}, {platform_id::win32s, "win32s"}, {platform_id::win32_windows, "win32_windows"}, {platform_id::win32_nt, "win32_nt"}, {platform_id::win_ce, "win_ce"}, {platform_id::unix, "unix"}, {platform_id::xbox, "xbox"}, {platform_id::macos, "macos"}, {platform_id::ios, "ios"}, {platform_id::android, "android"}});}
  inline std::wostream& operator<<(std::wostream& os, platform_id value) {return os << to_string(value, {{platform_id::unknown, L"unknown"}, {platform_id::win32s, L"win32s"}, {platform_id::win32_windows, L"win32_windows"}, {platform_id::win32_nt, L"win32_nt"}, {platform_id::win_ce, L"win_ce"}, {platform_id::unix, L"unix"}, {platform_id::xbox, L"xbox"}, {platform_id::macos, L"macos"}, {platform_id::ios, L"ios"}, {platform_id::android, L"android"}});}
}
