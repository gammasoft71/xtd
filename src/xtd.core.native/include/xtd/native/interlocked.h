/// @file
/// @brief Contains interlocked API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>
#include <ctime>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace threading {
    class interlocked;
  }
  /// @endcond
  
  /// @internal
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @internal
    /// @brief Contains interlocked native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ interlocked final {
    public:
    private:
      interlocked() = delete;
#if defined(__linux__) && defined(_LP64)
      using llong_t = long long int;
#else
      using llong_t = long;
#endif

    protected:
      friend xtd::threading::interlocked;
      /// @name Protected methods
      
      /// @{
      /// @internal
      static int32_t add(int32_t& location, int32_t value);
      static int64_t add(int64_t& location, int64_t value);

      static int32_t compare_exchange(int32_t& location, int32_t value, int32_t comparand);
      static int64_t compare_exchange(int64_t& location, int64_t value, int64_t comparand);
      static llong_t compare_exchange(llong_t& location, llong_t value, llong_t comparand);
      static void* compare_exchange(void*& location, void* value, void* comparand);

      static int32_t decrement(int32_t& location);
      static int64_t decrement(int64_t& location);

      static int32_t exchange(int32_t& location, int32_t value);
      static int64_t exchange(int64_t& location, int64_t value);
      static llong_t exchange(llong_t& location, llong_t value);
      static void* exchange(void*& location, void* value);

      static int32_t increment(int32_t& location);
      static int64_t increment(int64_t& location);
      /// @}
    };
  }
}
