/// @file
/// @brief Contains unnamed_mutex API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
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
    class mutex;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains unnamed_mutex native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @remarks xtd::threading::semaphore does not use xtd::native::unnamed_mutex API as it uses std::recursive_timed_mutex class.
    /// @warning Internal use only
    class core_native_export_ unnamed_mutex final {
      unnamed_mutex() = delete;
      friend xtd::threading::mutex;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Create named mutex with specified name and a bool value that.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      /// @param name The name, if the synchronization object is to be shared with other processes.
      /// @return The handle of the created mutex.
      /// @warning Internal use only
      static intmax_t create(bool initially_owned);
      
      /// @brief Destroy named mutex with specified mutex handle.
      /// @param name The name of the mutex.
      /// @param handle The mutex handle to destroy.
      /// @warning Internal use only
      static void destroy(intmax_t handle);
            
      /// @brief Signal named mutex with specified mutex handle.
      /// @param handle The mutex handle to signal.
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool signal(intmax_t handle, bool& io_error);
      
      /// @brief Wait named mutex with specified mutex handle and timeout.
      /// @param handle The mutex handle to wait.
      /// @param milliseconds_timeout The timeout in milliseconds (-1 is infinite timeout).
      /// @return error code :
      ///  * 0x00000000 : Sucess
      ///  * 0x00000080 : Abandoned
      ///  * 0x00000102 : Timeout
      ///  * 0xFFFFFFFF : Failed
      /// @warning Internal use only
      static uint_least32_t wait(intmax_t handle, int_least32_t milliseconds_timeout);
      /// @}
    };
  }
}
