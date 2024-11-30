/// @file
/// @brief Contains value types.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_VALUE_TYPE_NATIVE__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

#if defined(_LP64) && !defined(__APPLE__) && (defined(_POSIX_VERSION) || defined(__ANDROID__) || defined(__CYGWIN__) || defined(__linux__) || defined(__MSYS__) || defined(__unix__))
/// @brief Represents a 32-bit or 64-bit signed integer.
/// @warning Internal use only
using __slong__ = signed long long int; // Workaround : On Linux and Unix 64 bits unfortunately 'int64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
/// @brief Represents a 32-bit or 64-bit unsigned integer.
/// @warning Internal use only
using __ulong__ = unsigned long long int; // Workaround : On Linux and Unix 64 bits unfortunately 'uint64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
#else
/// @brief Represents a 32-bit or 64-bit signed integer.
/// @warning Internal use only
using __slong__ = signed long; // Workaround : On linux 64 bits unfortunately 'int64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
/// @brief Represents a 32-bit or 64-bit unsigned integer.
/// @warning Internal use only
using __ulong__ = unsigned long; // Workaround : On linux 64 bits unfortunately 'uint64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
#endif
