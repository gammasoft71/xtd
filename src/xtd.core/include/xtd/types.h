/// @file
/// @brief Contains xtd fundamental types.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "core_export.h"
#include "self.h"
/// @cond
#define __XTD_VALUE_TYPE_NATIVE__
#include <xtd/native/value_types>
#undef __XTD_VALUE_TYPE_NATIVE__
/// @endcond
#include <cstdint>
#include <string>
#include <typeinfo>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Native types

  /// @{
  /// @brief Represents a boolean.
  /// @par Header
  /// @code #include <xtd/bool> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using bool_ = bool;
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Header
  /// @code #include <xtd/byte> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using byte = uint_least8_t;
  /// @brief Represents a character.
  /// @par Header
  /// @code #include <xtd/char> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Represents a 32-bit unicode character on Linux and many other non-Windows systems, but a 16-bit unicode character on Windows.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using char_ = char;

#if defined(__cpp_lib_char8_t)
  /// @brief Represents a 8-bit unicode character.
  /// @par Header
  /// @code #include <xtd/char8> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using char8 = char8_t;
#endif
  
  /// @brief Represents a 16-bit unicode character.
  /// @par Header
  /// @code #include <xtd/char16> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using char16 = char16_t;
  
  /// @brief Represents a 32-bit unicode character.
  /// @par Header
  /// @code #include <xtd/char32> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using char32 = char32_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Header
  /// @code #include <xtd/decimal> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using decimal = long double;

  /// @brief Represents a double-precision floating-point number.
  /// @par Header
  /// @code #include <xtd/double> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using double_ = double;

  /// @brief Represents a 16-bit signed integer.
  /// @par Header
  /// @code #include <xtd/int16> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using int16 = int_least16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @par Header
  /// @code #include <xtd/int32> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using int32 = int_least32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @par Header
  /// @code #include <xtd/int64> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using int64 = int_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Header
  /// @code #include <xtd/intptr> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using intptr = intmax_t;
  
  /// @brief Represent the signed integer type of the result of subtracting two pointers.
  /// @par Header
  /// @code #include <xtd/ptrdiff> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using ptrdiff = std::ptrdiff_t;
  
  /// @brief Represents a 8-bit signed integer.
  /// @par Header
  /// @code #include <xtd/sbyte> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using sbyte = int_least8_t;

  /// @brief Represents a single-precision floating-point number.
  /// @par Header
  /// @code #include <xtd/single> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using single = float;

  /// @brief Represents a size of any object in bytes
  /// @par Header
  /// @code #include <xtd/size> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using size = size_t;
  
  /// @brief Represents a 32-bit or 64-bit signed integer.
  /// @par Header
  /// @code #include <xtd/slong> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using slong = __slong__; // Workaround: On linux 64 bits unfortunately 'int_least64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
  
  /// @brief Stores information about a type.
  /// @par Header
  /// @code #include <xtd/type> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using type = std::type_info;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Header
  /// @code #include <xtd/uint16> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using uint16 = uint_least16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Header
  /// @code #include <xtd/uint32> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using uint32 = uint_least32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Header
  /// @code #include <xtd/uint64> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using uint64 = uint_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Header
  /// @code #include <xtd/uintptr> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using uintptr = uintmax_t;
  
  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @par Header
  /// @code #include <xtd/ulong> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using ulong = __ulong__; // Workaround: On linux 64 bits unfortunately 'uint_least64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
  
  /// @brief Represents a wide character.
  /// @par Header
  /// @code #include <xtd/wchar> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Represents a 32-bit unicode character on Linux and many other non-Windows systems, but a 16-bit unicode character on Windows.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  using wchar = wchar_t;
  /// @}
  
  /// @brief Represents a null pointer value.
  /// @par Header
  /// @code #include <xtd/null> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// std::unique_ptr<foo_class> foo = std::make_unique<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// @endcode
  /// @ingroup xtd_core types
  extern core_export_ std::nullptr_t null;
}
