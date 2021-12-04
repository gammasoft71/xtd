
/// @file
/// @brief Contains drive type constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

#if !defined(DRIVE_UNKNOWN)
/// @internal
/// @brief The drive type cannot be determined.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_UNKNOWN = 0;

/// @internal
/// @brief The root path is invalid; for example, there is no volume mounted at the specified path.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_NO_ROOT_DIR = 1;

/// @internal
/// @brief The drive has removable media; for example, a floppy drive, thumb drive, or flash card reader.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_REMOVABLE = 2;

/// @internal
/// @brief The drive has fixed media; for example, a hard disk drive or flash drive.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_FIXED = 3;

/// @internal
/// @brief The drive is a remote (network) drive.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_REMOTE = 4;

/// @internal
/// @brief The drive is a CD-ROM drive.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_CDROM = 5;

/// @internal
/// @brief The drive is a RAM disk.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native drive_type
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr int32_t DRIVE_RAMDISK = 6;
#endif
