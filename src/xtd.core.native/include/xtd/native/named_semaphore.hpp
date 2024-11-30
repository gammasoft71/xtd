/// @file
/// @brief Contains named_semaphore API.
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
    class semaphore;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains named_semaphore native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ named_semaphore final {
      named_semaphore() = delete;
      friend xtd::threading::semaphore;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Create named semaphore with specified name, initial count and maxixum count.
      /// @param name The name, if the synchronization object is to be shared with other processes.
      /// @return The handle of the created semaphore.
      /// @warning Internal use only
      static intmax_t create(int32_t initial_count, int32_t max_count, const std::string& name);
      
      /// @brief Destroy named semaphore with specified semaphore handle.
      /// @param name The name of the semaphore.
      /// @param handle The semaphore handle to destroy.
      /// @warning Internal use only
      static void destroy(intmax_t handle, const std::string& name);
      
      /// @brief Gets the maximum name size supported.
      /// @return The maximum name size supported.
      /// @warning Internal use only
      static size_t max_name_size();
      
      /// @brief Open named semaphore with specified name.
      /// @param name The name, if the synchronization object is to be shared with other processes.
      /// @return The handle of the opened semaphore.
      /// @warning Internal use only
      static intmax_t open(const std::string& name);
      
      /// @brief Signal named semaphore with specified semaphore handle.
      /// @param handle The semaphore handle to signal.
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool signal(intmax_t handle, int32_t release_count, int32_t& previous_count, bool& io_error);
      
      /// @brief Wait named semaphore with specified semaphore handle and timeout.
      /// @param handle The semaphore handle to wait.
      /// @param milliseconds_timeout The timeout in milliseconds (-1 is infinite timeout).
      /// @return error code :
      ///  * 0x00000000 : Sucess
      ///  * 0x00000080 : Abandoned
      ///  * 0x00000102 : Timeout
      ///  * 0xFFFFFFFF : Failed
      /// @warning Internal use only
      static uint32_t wait(intmax_t handle, int32_t milliseconds_timeout);
      /// @}
    };
  }
}
