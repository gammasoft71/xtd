
/// @file
/// @brief Contains console color constants.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief Console color black.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native console_color
/// @remarks Added specificALLy for xtd.
/// @warning Internal use only
constexpr std::int32_t FILE_PERMISSIONS_NONE = 0;

constexpr std::int32_t FILE_PERMISSIONS_OWNER_READ = 0400;
constexpr std::int32_t FILE_PERMISSIONS_OWNER_WRITE = 0200;
constexpr std::int32_t FILE_PERMISSIONS_OWNER_EXECUTE = 0100;
constexpr std::int32_t FILE_PERMISSIONS_OWNER_ALL = FILE_PERMISSIONS_OWNER_READ | FILE_PERMISSIONS_OWNER_WRITE | FILE_PERMISSIONS_OWNER_EXECUTE;

constexpr std::int32_t FILE_PERMISSIONS_GROUP_READ = 040;
constexpr std::int32_t FILE_PERMISSIONS_GROUP_WRITE = 020;
constexpr std::int32_t FILE_PERMISSIONS_GROUP_EXECUTE = 010;
constexpr std::int32_t FILE_PERMISSIONS_GROUP_ALL = FILE_PERMISSIONS_GROUP_READ | FILE_PERMISSIONS_GROUP_WRITE | FILE_PERMISSIONS_GROUP_EXECUTE;

constexpr std::int32_t FILE_PERMISSIONS_OTHERS_READ = 04;
constexpr std::int32_t FILE_PERMISSIONS_OTHERS_WRITE = 02;
constexpr std::int32_t FILE_PERMISSIONS_OTHERS_EXECUTE = 01;
constexpr std::int32_t FILE_PERMISSIONS_OTHERS_ALL = FILE_PERMISSIONS_OTHERS_READ | FILE_PERMISSIONS_OTHERS_WRITE | FILE_PERMISSIONS_OTHERS_EXECUTE;

constexpr std::int32_t FILE_PERMISSIONS_ALL = FILE_PERMISSIONS_OWNER_ALL | FILE_PERMISSIONS_GROUP_ALL | FILE_PERMISSIONS_OTHERS_ALL;

constexpr std::int32_t FILE_PERMISSIONS_SET_UID = 04000;
constexpr std::int32_t FILE_PERMISSIONS_SET_GID = 02000;
constexpr std::int32_t FILE_PERMISSIONS_STICKY_BIT = 01000;

constexpr std::int32_t FILE_PERMISSIONS_MASK = 07777;


constexpr std::int32_t FILE_PERMISSIONS_UNKNOWN = 0xFFFF;
