/// @file
/// @brief Contains sound constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief The sound specified as the Windows Default Beep sound.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_OK = 0x00000000;

/// @brief The sound specified as the Windows Critical Stop sound.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_typesound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONERROR = 0x00000010;

/// @brief See ST_ICONERROR.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONHAND = 0x00000010;

/// @brief See ST_ICONERROR.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONSTOP = 0x00000010;

/// @brief The sound specified as the Windows Question sound.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONQUESTION = 0x00000020;

/// @brief The sound specified as the Windows Exclamation sound.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONWARNING = 0x00000030;

/// @brief See ST_ICONWARNING.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONEXCLAMATION = 0x00000030;

/// @brief The sound specified as the Windows Asterisk sound.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONINFORMATION = 0x00000040;

/// @brief See ST_ICONINFORMATION.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_ICONASTERISK = 0x00000040;

/// @brief A simple beep. If the sound card is not available, the sound is generated using the speaker.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native sound_type
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr uint32_t ST_BEEP = 0xFFFFFFFF;
