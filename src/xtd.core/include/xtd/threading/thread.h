/// @file
/// @brief Contains xtd::threading::thread class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "wait_handle.h"
#include "thread_priority.h"
#include "thread_state.h"
#include "../core_export.h"
#include "../object.h"
#include "../time_span.h"
#include "../types.h"
#include <mutex>
#include <thread>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Contains a constant used to specify an infinite amount of time. This class cannot be inherited.
    /// @code
    /// class core_export_ thread : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::threading::thread
    /// @par Header
    /// @code #include <xtd/threading/thread> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core threading
    /// @ingroup xtd_core threading
    class core_export_ thread : public object {
      struct data;
      using native_handle = std::thread::native_handle_type;
      using thread_id = std::thread::id;
      using thread_collection = std::vector<thread>;

      friend class wait_handle;
    public:
      /// @name Fields
      
      /// @{
      /// @brief Gets the currently running thread.
      /// @return A System::Threading::Thread that is the representation of the currently running
      /// @return thread.
      static thread& current_thread();
      /// @}

      /// @name Cosntructors
      
      /// @{
      thread();
      /// @}

      /// @cond

      /// @endcond
      
      /// @name Properties
      
      /// @{
      
      /// @}

      /// @name Methods
      
      /// @{
      /// @brief Interrupts a thread that is in the thread_state::wait_sleep_join thread state.
      /// @return One of the xt::threading::thread_state values indicating the state of the current thread. The initial value is thread_state::unstarted.
      /// @remarks If this thread is not currently blocked in a thread_state::wait, thread_state::sleep, or thread_state::join state, it will be interrupted when it next begins to block.
      /// @remarks xtd::threading::thread_interrupted_exception is thrown in the interrupted thread, but not until the thread blocks. If the thread never blocks, the exception is never thrown, and thus the thread might complete without ever being interrupted.
      void interrupt();

      /// @brief Suspends the current thread for a specified time.
      /// @param milliseconds_timeout The number of milliseconds for which the thread is blocked. Specify zero (0) to indicate that this thread should be suspended to allow other waiting threads to execute. Specify xtd::threading::Timeout.Infinite to block the thread indefinitely.
      /// @exception ArgumentException milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      static void sleep(int32 milliseconds_timeout);
      
      /// @brief Suspends the current thread for a specified time.
      /// @param timeout A xtd::time_span set to the amount of time for which the thread is blocked. Specify zero to indicate that this thread should be suspended to allow other waiting threads to execute. Specify xtd::threading::Timeout.Infinite to block the thread indefinitely.
      /// @exception ArgumentException The value of timeout is negative and is not equal to xtd::threading::Timeout.Infinite in milliseconds, or is greater than xtd::Int32.MaxValue milliseconds.
      static void sleep(const time_span& timeout);

      /// @brief Causes the calling thread to yield execution to another thread that is ready to run on the current processor. The operating system selects the thread to yield to.
      /// @return true if the operating system switched execution to another thread; otherwise, false.
      /// @remarks If this method succeeds, the rest of the thread's current time slice is yielded. The operating system schedules the calling thread for another time slice, according to its priority and the status of other threads that are available to run.
      /// @remarks yielding is limited to the processor that is executing the calling thread. The operating system will not switch execution to another processor, even if that processor is idle or is running a thread of lower priority. If there are no other threads that are ready to execute on the current processor, the operating system does not yield execution, and this method returns false.
      /// @remarks This method is equivalent to using platform invoke to call the native Win32 switch_to_thread function. You should call the yield method instead of using platform invoke, because platform invoke bypasses any custom threading behavior the host has requested.
      static bool yield();
      /// @}

    protected:
      
    private:
      bool cancel();
      static bool do_wait(wait_handle& wait_handle, int32 milliseconds_timeout);

      std::shared_ptr<data> data_;
      static thread_id main_thread_id_;
      static std::recursive_mutex mutex_;
      static thread_collection threads_;
      static constexpr int32 unmanaged_thread_id = 0;
      static constexpr int32 main_managed_thread_id = 1;
    };
  }
}
