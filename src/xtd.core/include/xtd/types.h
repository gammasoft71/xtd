/// @file
/// @brief Contains xtd fundamental types.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "core_export.h"
#include "core_namespace_aliases.h"
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
  /// ```cpp
  /// #include <xtd/bool>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using bool_ = bool;
  /// @brief Represents a 8-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/byte>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using byte = uint_least8_t;
  /// @brief Represents a character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Represents a 32-bit unicode character on Linux and many other non-Windows systems, but a 16-bit unicode character on Windows.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char_ = char;

#if defined(__cpp_lib_char8_t)
  /// @brief Represents a 8-bit unicode character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char8>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char8 = char8_t;
#endif
  
  /// @brief Represents a 16-bit unicode character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char16>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char16 = char16_t;
  
  /// @brief Represents a 32-bit unicode character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/char32>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using char32 = char32_t;
  
  /// @brief Represents a decimal-precision floating-point number.
  /// @par Header
  /// ```cpp
  /// #include <xtd/decimal>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using decimal = long double;

  /// @brief Represents a double-precision floating-point number.
  /// @par Header
  /// ```cpp
  /// #include <xtd/double>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using double_ = double;

  /// @brief Represents a 16-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/int16>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using int16 = int_least16_t;
  
  /// @brief Represents a 32-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/int32>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using int32 = int_least32_t;
  
  /// @brief Represents a 64-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/int64>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using int64 = int_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Header
  /// ```cpp
  /// #include <xtd/intptr>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using intptr = intmax_t;
  
  /// @brief Represent the signed integer type of the result of subtracting two pointers.
  /// @par Header
  /// ```cpp
  /// #include <xtd/ptrdiff>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using ptrdiff = std::ptrdiff_t;
  
  /// @brief Represents a 8-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/sbyte>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using sbyte = int_least8_t;

  /// @brief Represents a single-precision floating-point number.
  /// @par Header
  /// ```cpp
  /// #include <xtd/single>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using single = float;

  /// @brief Represents a size of any object in bytes
  /// @par Header
  /// ```cpp
  /// #include <xtd/size>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using size = size_t;
  
  /// @brief Represents a 32-bit or 64-bit signed integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/slong>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using slong = __slong__; // Workaround : On linux 64 bits unfortunately 'int_least64_t' is an alias on 'long' and not on 'long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
  
  /// @brief Stores information about a type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/type>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using type = std::type_info;
  
  /// @brief Represents a 16-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/uint16>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using uint16 = uint_least16_t;
  
  /// @brief Represents a 32-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/uint32>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using uint32 = uint_least32_t;
  
  /// @brief Represents a 64-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/uint64>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using uint64 = uint_least64_t;
  
  /// @brief Represent a pointer or a handle.
  /// @par Header
  /// ```cpp
  /// #include <xtd/uintptr>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using uintptr = uintmax_t;
  
  /// @brief Represents a 32-bit or 64-bit unsigned integer.
  /// @par Header
  /// ```cpp
  /// #include <xtd/ulong>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using ulong = __ulong__; // Workaround : On linux 64 bits unfortunately 'uint_least64_t' is an alias on 'unigned long' and not on 'unsigned long long int' as other platforms. In order to avoid conflicts in operator or method overloads, it is necessary to give the type that is not taken into account.
  
  /// @brief Represents a wide character.
  /// @par Header
  /// ```cpp
  /// #include <xtd/wchar>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  /// @remarks Represents a 32-bit unicode character on Linux and many other non-Windows systems, but a 16-bit unicode character on Windows.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  using wchar = wchar_t;
  /// @}
  
  /// @brief Represents a null pointer value.
  /// @par Header
  /// ```cpp
  /// #include <xtd/null>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// ```cpp
  /// std::unique_ptr<foo_class> foo = std::make_unique<foo_class>();
  /// ...
  /// foo = null; // release the unique pointer.
  /// ```
  /// @ingroup xtd_core types
  extern core_export_ std::nullptr_t null;
}
