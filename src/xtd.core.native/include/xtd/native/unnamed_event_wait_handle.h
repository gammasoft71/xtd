/// @file
/// @brief Contains unnamed_event_wait_handle API.
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
    class event_wait_handle;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains unnamed_event_wait_handle native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @remarks xtd::threading::semaphore does not use xtd::native::unnamed_event_wait_handle API as it uses std::counting_semaphore class.
    /// @warning Internal use only
    class core_native_export_ unnamed_event_wait_handle final {
      unnamed_event_wait_handle() = delete;
      friend xtd::threading::event_wait_handle;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Create named event wait handle with specified initial state and manual reset.
      /// @param initial_state true to set the initial state to signaled if the named event is created as a result of this call; false to set it to nonsignaled.
      /// @param manual_reset true the event resets manually; false the event resets automatically.
      /// @param name The name, if the synchronization object is to be shared with other processes.
      /// @return The handle of the created event wait handle.
      /// @warning Internal use only
      static intmax_t create(bool initial_state, bool manual_reset);
      
      /// @brief Destroy named event wait handle with specified event wait handle handle.
      /// @param handle The event wait handle handle to destroy.
      /// @warning Internal use only
      static void destroy(intmax_t handle);
      
      /// @brief Sets the state of the event to signaled, allowing one or more waiting threads to proceed.
      /// @param handle The event wait handle handle to set.
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool set(intmax_t handle, bool& io_error);

      /// @brief Sets the state of the event to nonsignaled, causing threads to block.
      /// @param handle The event wait handle handle to reset.
      /// @return true if succeed; otherwhise false.
      /// @warning Internal use only
      static bool reset(intmax_t handle, bool& io_error);

      /// @brief Wait named event wait handle with specified event wait handle handle, timeout and manual reset.
      /// @param handle The event wait handle handle to wait.
      /// @param milliseconds_timeout The timeout in milliseconds (-1 is infinite timeout).
      /// @param manual_reset true the event resets manually; false the event resets automatically.
      /// @return error code :
      ///  * 0x00000000 : Sucess
      ///  * 0x00000080 : Abandoned
      ///  * 0x00000102 : Timeout
      ///  * 0xFFFFFFFF : Failed
      /// @warning Internal use only
      static uint_least32_t wait(intmax_t handle, int_least32_t milliseconds_timeout, bool manual_reset);
      /// @}
    };
  }
}
