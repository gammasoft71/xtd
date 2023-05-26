/// @file
/// @brief Contains __std_abort definition.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @cond
// Workaround : the std::abort function on Visual Studio shows a message box.
#if defined(_MSC_VER)
#define __std_abort __debugbreak
#else
#define __std_abort std::abort
#endif
/// @endcond
