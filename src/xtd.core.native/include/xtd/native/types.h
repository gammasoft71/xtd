/// @file
/// @brief Contains types.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstdint>
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
      /// @name Protected static methods
      
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
