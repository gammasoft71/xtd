/// @file
/// @brief Contains xtd::wait_handle exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../abstract.h"
#include "../time_span.h"
#include "../types.h"
#include "timeout.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming.
  /// In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class thread;
    /// @endcond
    
    /// @brief Encapsulates operating system specific objects that wait for exclusive access to shared resources.
    /// @par Header
    /// @code #include <xtd/threading/wait_handle> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    class wait_handle abstract_ {
      friend class thread;
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents an invalid native operating system handle. This field is constant.
      static constexpr intptr_t invalid_handle = 0;
      
      /// @brief Indicates that a xtd::tThreading::wait_handle::wait_any(const xtd::threading::wait_handle[], int32_t, bool) operation timed out before any of the wait handles were signaled. This field is constant.
      static constexpr int32_t wait_timeout = -1;
      

      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::wait_handle class.
      wait_handle() = default;
      /// @}
      

      /// @cond
      ~wait_handle();
      /// @endcond

      /// @name Methods
      
      /// @{
      /// @brief When overridden in a derived class, releases all resources held by the current xtd::threading::wait_handle.
      virtual void close();
      
      /// @brief signals one wait_handle and waits on another.
      /// @param to_signal The wait_handle to signal.
      /// @param to_wait The wait_handle to wait on.
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception ArgumentNullException to_signal is null or to_wait is null.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait);
      
      /// @brief signals one wait_handle and waits on another, specifying a time-out interval as a 32-bit signed integer.
      /// @param to_signal The wait_handle to signal.
      /// @param to_wait The wait_handle to wait on.
      /// @param milliseconds_timeout An integer that represents the interval to wait. If the value is Timeout::Infinite, that is, -1, the wait is infinite
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception ArgumentNullException to_signal is null or to_wait is null.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, int32_t milliseconds_timeout);
      
      /// @brief signals one wait_handle and waits on another, specifying a time-out interval as a time_span.
      /// @param to_signal The wait_handle to signal.
      /// @param to_wait The wait_handle to wait on.
      /// @param timeout A time_span that represents the interval to wait. If the value is -1, the wait is infinite
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception ArgumentNullException to_signal is null or to_wait is null.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, const time_span& timeout);
      
      /// @brief Blocks the current thread until the current xtd::threading::wait_handle receives a signal.
      /// @return true if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(int32_t, bool) never returns.
      /// @exception ObjectDisposedException the handle is invalid
      virtual bool wait_one();
      
      /// @brief Blocks the current thread until the current xtd::threading::wait_handle receives
      /// a signal, using 32-bit signed integer to measure the time interval.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::Timeout.Infinite (-1) to wait indefinitely.
      /// @return if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(int32_t, bool) never returns.
      /// @exception ObjectDisposedException the handle is invalid
      /// @exception ArgumentException millisecondsTimeout is a negative number other than -1, which represents an infinite time-out.
      virtual bool wait_one(int32_t milliseconds_timeout);
      
      /// @brief Blocks the current thread until the current instance receives a signal, using
      /// a System.time_span to measure the time interval.
      /// @param timeout A System.time_span that represents the number of milliseconds to wait, or
      /// a System.time_span that represents -1 milliseconds to wait indefinitely.
      /// @return true if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(System.Int32, System.Boolean) never returns.
      /// @exception ObjectDisposedException the handle is invalid
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.  -or- timeout is greater than System.Int32.MaxValue.
      virtual bool wait_one(const time_span& timeout);
      
      /// @brief waits for all the elements in the specified array to receive a signal.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @return true when every element in wait_handles has received a signal; otherwise the method never returns.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static bool wait_all(std::vector<std::shared_ptr<wait_handle>> wait_handles);
      
      /// @brief waits for all the elements in the specified array to receive a signal, using
      /// an System.Int32 value to measure the time interval.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::Timeout.Infinite
      /// (-1) to wait indefinitely.
      /// @return true when every element in wait_handles has received a signal; otherwise the
      /// method never returns.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
      /// an infinite time-out.
      /// -or-  The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static bool wait_all(std::vector<std::shared_ptr<wait_handle>> wait_handles, int32_t milliseconds_timeout);
      
      /// @brief waits for all the elements in the specified array to receive a signal, using
      /// a System.time_span value to measure the time interval.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds, to wait indefinitely.
      /// @return true when every element in wait_handles has received a signal; otherwise the
      /// method never returns.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
      /// an infinite time-out.
      /// -or- timeout is greater than System.Int32.MaxValue.
      /// -or- The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static bool wait_all(std::vector<std::shared_ptr<wait_handle>> wait_handles, const time_span& timeout);
      
      /// @brief waits for any of the elements in the specified array to receive a signal.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @return The array index of the object that satisfied the wait.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
      /// an infinite time-out.
      /// -or-  The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static size_t wait_any(std::vector<std::shared_ptr<wait_handle>> wait_handles);
      
      /// @brief waits for any of the elements in the specified array to receive a signal,
      /// using a 32-bit signed integer to measure the time interval.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::Timeout.Infinite
      /// (-1) to wait indefinitely.
      /// @return The array index of the object that satisfied the wait, or xtd::threading::wait_handle.waitTimeout
      /// if no object satisfied the wait and a time interval equivalent to millisecondsTimeout
      /// has passed.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
      /// an infinite time-out.
      /// -or-  The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static size_t wait_any(std::vector<std::shared_ptr<wait_handle>> wait_handles, int32_t milliseconds_timeout);
      
      /// @brief waits for any of the elements in the specified array to receive a signal,
      /// using a System.time_span to measure the time interval.
      /// @param wait_handles A wait_handle array containing the objects for which the current instance
      /// will wait. This array cannot contain multiple references to the same object.
      /// @param timeout A System.time_span that represents the number of milliseconds to wait, or
      /// a System.time_span that represents -1 milliseconds to wait indefinitely.
      /// @return The array index of the object that satisfied the wait, or xtd::threading::wait_handle.waitTimeout
      /// if no object satisfied the wait and a time interval equivalent to timeout
      /// has passed.
      /// @exception ArgumentNullException The wait_handles parameter is null
      /// @exception ArgumentException timeout is a negative number other than -1 milliseconds, which represents
      /// an infinite time-out. -or-  The number of objects in wait_handles is greater than the system permits.
      /// @exception AbandonedMutexException The wait completed because a thread exited without releasing a mutex.
      static size_t wait_any(std::vector<std::shared_ptr<wait_handle>> wait_handles, const time_span& timeout);
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Releases ownership of the specified wait_handle object.
      /// @return true If the function succeeds, false otherwise.
      /// @remarks Override this function for all derived object
      virtual bool signal() = 0;
      
      /// @brief wait ownership of the specified mutex object.
      /// @param handle A valid handle to an open object.
      /// @param milliseconds_timeout The number of milliseconds to wait, or -1 to wait indefinitely.
      /// @return true if the current instance receives a signal; otherwise, false.
      /// @remarks If millisecondsTimeout is zero, the method does not block. It tests the state of the wait handle and returns immediately.
      /// @remarks Override this function for all derived object
      virtual bool wait(int32_t milliseconds_timeout) = 0;
      
      /// @cond
      bool do_wait(int32_t milliseconds_timeout);
      /// @endcond
      /// @}
    };
  }
}
