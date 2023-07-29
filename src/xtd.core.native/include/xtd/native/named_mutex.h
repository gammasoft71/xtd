/// @file
/// @brief Contains named_mutex API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
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
    /// @brief Contains named_mutex native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ named_mutex final {
      named_mutex() = delete;
      friend xtd::threading::mutex;
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Create named mutex with specified name and a bool value that, when the method returns, indicates whether the calling thread was granted initial ownership of the mutex.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      /// @param name The name, if the synchronization object is to be shared with other processes.
      /// @param creat_new When this method returns, contains a boolthat is true if the specified named system mutex was created; false if the specified named system mutex already existed.
      /// @return The handle of the created or open mutex.
      /// @warning Internal use only
      static intptr_t create(bool initially_owned, const std::string& name, bool& create_new);
      /// @brief Destroy named mutex with specified mutex handle.
      /// @param name The name of the mutex.
      /// @param handle The mutex handle to destroy.
      /// @warning Internal use only
      static void destroy(intptr_t handle, const std::string& name);
      /// @brief Signal named mutex with specified mutex handle.
      /// @param handle The mutex handle to signal.
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool signal(intptr_t handle, bool& io_error);
      /// @brief Wait named mutex with specified mutex handle and timeout.
      /// @param handle The mutex handle to wait.
      /// @param milliseconds_timeout The timeout in milliseconds (-1 is infinite timeout).
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool wait(intptr_t handle, int32_t milliseconds_timeout, bool& io_error);
      /// @}
    };
  }
}
