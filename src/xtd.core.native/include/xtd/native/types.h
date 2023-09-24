/// @file
/// @brief Contains types.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_TYPE_NATIVE__) && !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

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

#if defined(__XTD_CORE_NATIVE_LIBRARY__)
#include <xtd/core_native_export>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class ustring;
  namespace threading {
    class thread;
    class wait_handle;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains type native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ types final {
      types() = delete;
      friend xtd::ustring;
      friend xtd::threading::thread;
      friend xtd::threading::wait_handle;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Gets demangled string of name,.
      /// @param name The name to demangle.
      /// @return The demangled string of name.
      /// @warning Internal use only
      static std::string demangle(const std::string& name);
      
      /// @brief Gets an invalid native operating system handle.
      /// @return An invalid native operating system handle.
      static intmax_t invalid_handle() noexcept;
      /// @}
    };
  }
}
#endif
