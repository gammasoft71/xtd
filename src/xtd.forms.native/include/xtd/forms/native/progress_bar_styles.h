/// @file
/// @brief Contains progress bar styles constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstddef>

#ifndef PBS_SMOOTH
/// @brief The progress bar displays progress status in a smooth scrolling bar instead of the default segmented bar.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native pbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PBS_SMOOTH = 0x00000001;
/// @brief The progress bar displays progress status vertically, from bottom to top.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native pbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PBS_VERTICAL = 0x00000004;
/// @brief The progress indicator does not grow in size but instead moves repeatedly along the length of the bar, indicating activity without specifying what proportion of the progress is complete.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native pbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PBS_MARQUEE = 0x00000008;
/// @brief Determines the animation behavior that the progress bar should use when moving backward (from a higher value to a lower value). If this is set, then a "smooth" transition will occur, otherwise the control will "jump" to the lower value.
/// @par Library
/// xtd.forms.native
/// @ingroup xtd_forms_native pbs
/// @remarks For more info see https://docs.microsoft.com .
/// @warning Internal use only
constexpr size_t PBS_SMOOTHREVERSE = 0x00000010;
#endif
