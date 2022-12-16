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
    using __slong__ = signed long long int; // Workaround: On linux 64 bits unfortunately 'int_least64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
    /// @brief Represents a 32-bit or 64-bit unsigned integer.
    /// @warning Internal use only
    using __ulong__ = unsigned long long int; // Workaround: On linux 64 bits unfortunately 'uint_least64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
#else
    /// @brief Represents a 32-bit or 64-bit signed integer.
    /// @warning Internal use only
    using __slong__ = signed long; // Workaround: On linux 64 bits unfortunately 'int_least64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
    /// @brief Represents a 32-bit or 64-bit unsigned integer.
    /// @warning Internal use only
    using __ulong__ = unsigned long; // Workaround: On linux 64 bits unfortunately 'uint_least64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
#endif
    /// @endcond
  }
}
