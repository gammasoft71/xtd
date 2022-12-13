/// @file
/// @brief Contains types.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
#if defined(__linux__) && defined(_LP64)
    /// @brief Represents a 32-bit or 64-bit signed integer.
    /// @warning Internal use only
    using __llong__ = long long int;
    /// @brief Represents a 32-bit or 64-bit unsigned integer.
    /// @warning Internal use only
    using __ullong__ = unsigned long long int;
#else
    /// @brief Represents a 32-bit or 64-bit signed integer.
    /// @warning Internal use only
    using __llong__ = long;
    /// @brief Represents a 32-bit or 64-bit unsigned integer.
    /// @warning Internal use only
    using __ullong__ = unsigned long;
#endif
    /// @endcond
  }
}
