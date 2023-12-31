/// @file
/// @brief Contains critical_section API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export>
#include <cstddef>
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace threading {
    class monitor;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains critical_section native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @remarks xtd::threading::semaphore does not use xtd::native::critical_section API as it uses std::recursive_timed_mutex class.
    /// @warning Internal use only
    class core_native_export_ critical_section final {
      critical_section() = delete;
      friend xtd::threading::monitor;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Create critical section.
      /// @return The handle of the created critical section.
      /// @warning Internal use only
      static intmax_t create();
      
      /// @brief Destroy critical section with specified critical section handle.
      /// @param handle The critical section handle to destroy.
      /// @warning Internal use only
      static void destroy(intmax_t handle);
      
      /// @brief Wait critical section with specified critical section handle.
      /// @param handle The critical section handle to wait.
      /// @return true if succeed; otherwhise false.
      static void enter(intmax_t handle);

      /// @brief Attempts to enter critical section with specified critical section handle.
      /// @param handle The critical section handle to wait.
      /// @return true if succeed; otherwhise false.
      static bool try_enter(intmax_t handle);

      /// @brief Release`critical section with specified critical section handle.
      /// @param handle The critical section handle to release.
      /// @warning Internal use only
      static void leave(intmax_t handle);
      /// @}
    };
  }
}
