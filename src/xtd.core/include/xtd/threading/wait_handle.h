/// @file
/// @brief Contains xtd::threading::wait_handle exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "timeout.h"
#include "../abstract.h"
#include "../as.h"
#include "../time_span.h"
#include "../types.h"
#include <limits>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class registered_wait_handle;
    class thread;
    /// @endcond
    
    /// @brief Encapsulates operating system specific objects that wait for exclusive access to shared resources.
    /// @code
    /// class core_export_ wait_handle abstract_
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/wait_handle> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks The xtd::threading::wait_handle class encapsulates a native operating system synchronization handle and is used to represent all synchronization objects in the runtime that allow multiple wait operations.
    /// @remarks The xtd::threading::wait_handle class itself is abstract. Classes derived from xtd::threading::wait_handle define a signaling mechanism to indicate taking or releasing access to a shared resource, but they use the inherited xtd::threading::wait_handle methods to block while waiting for access to shared resources. The classes derived from xtd::threading::wait_handle include:
    /// * The xtd::threading::mutex class.
    /// * The xtd::threading::event_wait_handle class and its derived classes, xtd::threading::auto_reset_event and xtd::threading::manual_reset_event.
    /// * The xtd::threading::semaphore class.
    /// @remarks Threads can block on an individual wait handle by calling the instance method xtd::threading::wait_handle::wait_one, which is inherited by classes derived from xtd::threading::wait_handle.
    /// @remarks The derived classes of xtd::threading::wait_handle differ in their thread affinity. Event wait handles (xtd::threading::envent_wait_handle, xtd::threading::auto_reset_event, and xtd::threading::manual_reset_event) and semaphores do not have thread affinity; any thread can signal an event wait handle or semaphore. Mutexes, on the other hand, do have thread affinity; the thread that owns a mutex must release it, and an exception is thrown if a thread calls the xtd::threading::mutex::release_mutex method on a mutex that it does not own.
    /// @remarks In addition to its derived classes, the xtd::threading::wait_handle class has a number of static methods that block a thread until one or more synchronization objects receive a signal. These include:
    /// * xtd::threading::wait_handle::signal_and_wait, which allows a thread to signal one wait handle and immediately wait on another.
    /// * xtd::threading::wait_handle::wait_all, which allows a thread to wait until all the wait handles in an array receive a signal.
    /// * xtd::threading::wait_handle::wait_any, which allows a thread to wait until any one of a specified set of wait handles has been signaled.
    /// @remarks The overloads of these methods provide timeout intervals for abandoning the wait, and the opportunity to exit a synchronization context before entering the wait, allowing other threads to use the synchronization context.
    /// @par Examples
    /// The following code example shows how two threads can do background tasks while the Main thread waits for the tasks to complete using the static xtd::threading::wait_handle::wait_any and xtd::threading::wait_handle::wait_all methods of the xtd::threading::wait_handle class.
    /// @include wait_handle.cpp
    class core_export_ wait_handle abstract_ {
      friend class registered_wait_handle;
      friend class thread;
    public:
      /// @name Fields
      
      /// @{
      /// @brief Represents an invalid native operating system handle. This field is read-only.
      /// @remarks Used internally to initialize the xtd::threading::wait_handle::handle property.
      /// @par Notes to Inheritors
      /// You can use this value to determine whether the xtd::threading::wait_handle::handle property contains a valid native operating system handle.
      static const intptr invalid_handle;
      
      /// @brief Indicates that a xtd::threading::wait_handle::wait_any operation timed out before any of the wait handles were signaled. This field is constant.
      /// @remrarks This field is one of the possible return values of xtd::threading::wait_handle::wait_any.
      static constexpr size_t wait_timeout = std::numeric_limits<size_t>::max();
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::wait_handle class.
      wait_handle() = default;
      /// @}
      
      /// @cond
      ~wait_handle();
      /// @endcond

      /// @name Properties
      
      /// @{
      /// @brief Gets the native operating system handle.
      /// @return An intptr representing the native operating system handle.
      virtual intptr handle() const noexcept = 0;
      /// @brief Sets the native operating system handle.
      /// @param value An intptr representing the native operating system handle.
      virtual void handle(intptr value) = 0;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Releases all resources held by the current xtd::threading::wait_handle.
      /// @remarks You to call this method in the destructor of the inherited class.
      virtual void close();
      
      /// @brief Blocks the current thread until the current xtd::threading::wait_handle receives a signal.
      /// @return true if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(int32, bool) never returns.
      /// @exception xtd::object_closed_exception the handle is invalid
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      virtual bool wait_one();
      
      /// @brief Blocks the current thread until the current xtd::threading::wait_handle receives a signal, using 32-bit signed integer to measure the time interval.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
      /// @return if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(int32, bool) never returns.
      /// @exception xtd::object_closed_exception the handle is invalid
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      /// @exception xtd::argument_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      virtual bool wait_one(int32 milliseconds_timeout);
      
      /// @brief Blocks the current thread until the current instance receives a signal, using a xtd::time_span to measure the time interval.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @return true if the current instance receives a signal. If the current instance is never signaled, xtd::threading::wait_handle.wait_one(int32, bool) never returns.
      /// @exception xtd::object_closed_exception the handle is invalid
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      /// @exception xtd::argument_exception milliseconds_timeout is a negative number other than -1, which represents an infinite time-out.
      virtual bool wait_one(const time_span& timeout);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Signals one xtd::threading::wait_handle and waits on another.
      /// @param to_signal The xtd::threading::wait_handle to signal.
      /// @param to_wait The xtd::threading::wait_handle to wait on.
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::invalid_operation_exception to_signal is a semaphore, and it already has a full count.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait);
      
      /// @brief Signals one xtd::threading::wait_handle and waits on another, specifying a time-out interval as a 32-bit signed integer.
      /// @param to_signal The xtd::threading::wait_handle to signal.
      /// @param to_wait The xtd::threading::wait_handle to wait on.
      /// @param milliseconds_timeout An integer that represents the interval to wait. If the value is xtd::threading::timeout::infinite, that is, -1, the wait is infinite
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::invalid_operation_exception to_signal is a semaphore, and it already has a full count.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, int32 milliseconds_timeout);
      
      /// @brief Signals one xtd::threading::wait_handle and waits on another, specifying a time-out interval as a time_span.
      /// @param to_signal The wait_handle to signal.
      /// @param to_wait The wait_handle to wait on.
      /// @param timeout A time_span that represents the interval to wait. If the value is -1, the wait is infinite
      /// @return bool true if both the signal and the wait complete successfully; if the wait does not complete, the method does not return.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::invalid_operation_exception to_signal is a semaphore, and it already has a full count.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      static bool signal_and_wait(wait_handle& to_signal, wait_handle& to_wait, const time_span& timeout);
      
      /// @brief Waits for all the elements in the specified collection to receive a signal.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @return true when every element in wait_handles has received a signal; otherwise the method never returns.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static bool wait_all(const collection_t& wait_handles) {return wait_all(wait_handles, timeout::infinite);}
      
      /// @brief Waits for all the elements in the specified collection to receive a signal, using an int32 value to measure the time interval.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
      /// @return true when every element in wait_handles has received a signal; otherwise the method never returns.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.<br>-or-<br>The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static bool wait_all(const collection_t& wait_handles, int32 milliseconds_timeout) {
        std::vector<wait_handle*> wait_handle_pointers;
        for (auto& item : wait_handles)
          wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&item)));
        return wait_all(wait_handle_pointers, milliseconds_timeout);
      }
      
      /// @brief Waits for all the elements in the specified collection to receive a signal, using a xtd::time_span value to measure the time interval.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds, to wait indefinitely.
      /// @return true when every element in wait_handles has received a signal; otherwise the method never returns.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.<br>-or-<br>The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static bool wait_all(const collection_t& wait_handles, const time_span& timeout) {return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));}
      
      /// @brief Waits for any of the elements in the specified collection to receive a signal.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @return The array index of the object that satisfied the wait.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.<br>-or-<br>The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static size_t wait_any(const collection_t& wait_handles) {return wait_any(wait_handles, timeout::infinite);}
      
      /// @brief Waits for any of the elements in the specified collection to receive a signal, using a 32-bit signed integer to measure the time interval.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
      /// @return The array index of the object that satisfied the wait, or xtd::threading::wait_handle::wait_timeout if no object satisfied the wait and a time interval equivalent to milliseconds_timeout has passed.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.<br>-or-<br>The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static size_t wait_any(const collection_t& wait_handles, int32 milliseconds_timeout) {
        std::vector<wait_handle*> wait_handle_pointers;
        for (auto& item : wait_handles)
          wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&item)));
        return wait_any(wait_handle_pointers, milliseconds_timeout);
      }
      
      /// @brief Waits for any of the elements in the specified collection to receive a signal, using a xtd::time_span to measure the time interval.
      /// @param wait_handles A xtd::threading::wait_handle collection containing the objects for which the current instance will wait. This array cannot contain multiple references to the same object.
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @return The array index of the object that satisfied the wait, or xtd::threading::wait_handle::wait_timeout if no object satisfied the wait and a time interval equivalent to timeout has passed.
      /// @exception xtd::argument_exception timeout is a negative number other than -1 milliseconds, which represents an infinite time-out.<br>-or-<br>The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::object_closed_exception the to_signal and/or to_wait are invalid
      /// @exception xtd::argument_exception The number of objects in wait_handles is greater than the system permits.
      /// @exception xtd::threading::abandoned_mutex_exception The wait completed because a thread exited without releasing a mutex.
      template<typename collection_t>
      static size_t wait_any(const collection_t& wait_handles, const time_span& timeout) {return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));}
      /// @}

      /// @cond
      template <typename... items_t>
      static size_t wait_all(items_t... items) {return wait_all(timeout::infinite, items...);}
      template <typename... items_t>
      static size_t wait_all(const time_span& timeout, items_t... items) {return wait_all(as<int32>(timeout.total_milliseconds()), items...);}
      template <typename... items_t>
      static size_t wait_all(int32 milliseconds_timeout, items_t... items) {
        std::vector<wait_handle*> wait_handle_pointers;
        fill_wait_handle_pointers(wait_handle_pointers, items...);
        return wait_all(wait_handle_pointers, milliseconds_timeout);
      }
      template<typename item_t>
      static bool wait_all(const std::initializer_list<item_t>& wait_handles) {return wait_all(wait_handles, timeout::infinite);}
      template<typename item_t>
      static bool wait_all(const std::initializer_list<item_t>& wait_handles, int32 milliseconds_timeout) {
        std::vector<wait_handle*> wait_handle_pointers;
        for (auto& item : wait_handles)
          wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&item)));
        return wait_all(wait_handle_pointers, milliseconds_timeout);
      }
      template<typename item_t>
      static bool wait_all(const std::initializer_list<item_t>& wait_handles, const time_span& timeout) {return wait_all(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));}
      static bool wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles);
      static bool wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static bool wait_all(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static bool wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles);
      static bool wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static bool wait_all(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static bool wait_all(const std::vector<std::shared_ptr<wait_handle>>& wait_handles);
      static bool wait_all(const std::vector<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static bool wait_all(const std::vector<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static bool wait_all(const std::vector<std::unique_ptr<wait_handle>>& wait_handles);
      static bool wait_all(const std::vector<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static bool wait_all(const std::vector<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static bool wait_all(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout);

      template <typename... items_t>
      static size_t wait_any(items_t... items) {return wait_any(timeout::infinite, items...);}
      template <typename... items_t>
      static size_t wait_any(const time_span& timeout, items_t... items) {return wait_any(as<int32>(timeout.total_milliseconds()), items...);}
      template <typename... items_t>
      static size_t wait_any(int32 milliseconds_timeout, items_t... items) {
        std::vector<wait_handle*> wait_handle_pointers;
        fill_wait_handle_pointers(wait_handle_pointers, items...);
        return wait_any(wait_handle_pointers, milliseconds_timeout);
      }
      template<typename item_t>
      static size_t wait_any(const std::initializer_list<item_t>& wait_handles) {return wait_any(wait_handles, timeout::infinite);}
      template<typename item_t>
      static size_t wait_any(const std::initializer_list<item_t>& wait_handles, int32 milliseconds_timeout) {
        std::vector<wait_handle*> wait_handle_pointers;
        for (auto& item : wait_handles)
          wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&item)));
        return wait_any(wait_handle_pointers, milliseconds_timeout);
      }
      template<typename item_t>
      static size_t wait_any(const std::initializer_list<item_t>& wait_handles, const time_span& timeout) {return wait_any(wait_handles, as<int32>(timeout.total_milliseconds_duration().count()));}
      static size_t wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles);
      static size_t wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static size_t wait_any(const std::initializer_list<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static size_t wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles);
      static size_t wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static size_t wait_any(const std::initializer_list<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static size_t wait_any(const std::vector<std::shared_ptr<wait_handle>>& wait_handles);
      static size_t wait_any(const std::vector<std::shared_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static size_t wait_any(const std::vector<std::shared_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static size_t wait_any(const std::vector<std::unique_ptr<wait_handle>>& wait_handles);
      static size_t wait_any(const std::vector<std::unique_ptr<wait_handle>>& wait_handles, int32 milliseconds_timeout);
      static size_t wait_any(const std::vector<std::unique_ptr<wait_handle>>& wait_handles, const time_span& timeout);
      static size_t wait_any(const std::vector<wait_handle*>& wait_handles, int32 milliseconds_timeout);
      /// @endcond

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
      /// @remarks If milliseconds_timeout is zero, the method does not block. It tests the state of the wait handle and returns immediately.
      /// @remarks Override this function for all derived object
      virtual bool wait(int32 milliseconds_timeout) = 0;
      /// @}

    private:
      template <typename item_t, typename... items_t>
      static void fill_wait_handle_pointers(std::vector<wait_handle*>& wait_handle_pointers, item_t& first, items_t&... rest) {
        wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&first)));
        fill_wait_handle_pointers(wait_handle_pointers, rest...);
      }
      template <typename item_t>
      static void fill_wait_handle_pointers(std::vector<wait_handle*>& wait_handle_pointers, item_t& item) {
        wait_handle_pointers.push_back(const_cast<wait_handle*>(as<wait_handle>(&item)));
      }
    };
  }
}
