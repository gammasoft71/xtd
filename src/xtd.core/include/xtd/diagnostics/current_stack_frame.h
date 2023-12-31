/// @file
/// @brief Contains #current_stack_frame_ and #csf_ keywords.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "stack_frame.h"

/// @brief Provides information about the current stack frame.
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @return Informations about the current stack frame.
/// @par Examples
/// The following example shows how to use the #current_stack_frame_.
/// @include current_stack_frame.cpp
/// @remarks same as #csf_
#define current_stack_frame_ \
  xtd::diagnostics::stack_frame {__FILE__, __LINE__, __func__}

/// @brief Provides information about the current stack frame.
/// @par Header
/// @code #include <xtd/diagnostics/stack_frame> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @return Informations about the current stack frame.
/// @par Examples
/// The following example shows how to use the #csf_.
/// @include csf.cpp
/// @remarks same as #current_stack_frame_
#define csf_ current_stack_frame_

/// @brief Add current stack frame to the __VA_ARGS__ with a comma separator.
/// @par Header
/// @code #include <xtd/diagnostics/stack_frame> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @return __VA_ARGS__ with comma and current stack frame.
/// @par Examples
/// @remarks same as #add_csf_
#define add_current_stack_frame_(...) \
  __VA_ARGS__ __VA_ARGS_COMMA__(__VA_ARGS__) current_stack_frame_

/// @brief Add current stack frame to the __VA_ARGS__ with a comma separator.
/// @par Header
/// @code #include <xtd/diagnostics/stack_frame> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @return __VA_ARGS__ with comma and current stack frame.
/// @par Examples
/// @remarks same as #add_current_stack_frame_
#define add_csf_ add_current_stack_frame_
