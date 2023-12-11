/// @file
/// @brief Contains xtd::platform_id enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "enum.h"
#undef unix
#undef linux

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Identifies the operating system, or platform, supported by an assembly.
  /// @par Namespace
  /// xtd
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
    /// @brief The operating system is iOS Apple.
    ios,
    /// @brief The operating system is Android.
    android,
    /// @brief The operating system is Linux.
    linux,
    /// @brief The operating system is tvOS Apple.
    tvos,
    /// @brief The operating system is watchOS Apple.
    watchos,
    /// @brief The operating system is FreeBSD.
    free_bsd,
    /// @brief The operating system is MINGW.
    mingw,
    /// @brief The operating system is MSYS.
    msys,
    /// @brief The operating system is other.
    other = 0x0FFFFFFF,
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::platform_id> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::platform_id> {{xtd::platform_id::unknown, "unknown"}, {xtd::platform_id::win32s, "win32s"}, {xtd::platform_id::win32_windows, "win32_windows"}, {xtd::platform_id::win32_nt, "win32_nt"}, {xtd::platform_id::win_ce, "win_ce"}, {xtd::platform_id::unix, "unix"}, {xtd::platform_id::xbox, "xbox"}, {xtd::platform_id::macos, "macos"}, {xtd::platform_id::ios, "ios"}, {xtd::platform_id::android, "android"}, {xtd::platform_id::linux, "linux"}, {xtd::platform_id::tvos, "tvos"}, {xtd::platform_id::watchos, "watchos"}, {xtd::platform_id::free_bsd, "free_bsd"}, {xtd::platform_id::mingw, "mingw"}, {xtd::platform_id::msys, "msys"}, {xtd::platform_id::other, "other"}};}
};
/// @endcond
