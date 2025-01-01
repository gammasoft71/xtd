/// @file
/// @brief Contains #call_once_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::call_once struct can be used to execute a routine exactly once. This can be used to initialise data in a thread-safe way.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks See also #call_once_ keyword helper.
  /// @par Examples
  /// The following example shows how to use xtd::call_once struct.
  /// @include call_once2.cpp
  struct call_once {
  };
  
  /// @cond
  template<typename function_t>
  struct __xtd_call_once_object__ {
    __xtd_call_once_object__(function_t function) { function(); }
  };
  
  template<typename function_t>
  auto operator +(call_once, function_t&& function) {
    return __xtd_call_once_object__<function_t>{std::forward<function_t>(function)};
  }
  /// @endcond
}

/// @cond
#define __xtd_call_once_cat__(name, line) name##line
#define __xtd_call_once_id__(name, line) __xtd_call_once_cat__(name, line)
/// @endcond

/// @brief The xtd keyword #call_once_ can be used to execute a routine exactly once. This can be used to initialise data in a thread-safe way.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks See also xtd::call_once struct.
/// @par Examples
/// The following example shows how to use #call_once_ keyword.
/// @include call_once.cpp
#define call_once_ [[maybe_unused]] static auto __xtd_call_once_id__(__xtd__call_once__, __LINE__) = xtd::call_once {} + [&]
