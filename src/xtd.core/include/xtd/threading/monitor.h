/// @file
/// @brief Contains xtd::threading::monitor class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../diagnostics/stack_frame.h"
#include "../core_export.h"
#include "../invalid_operation_exception.h"
#include "../static.h"
#include "../time_span.h"
#include "../types.h"
#include "../as.h"
#include "../is.h"
#include "mutex.h"
#include "timeout.h"
#include <unordered_map>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class lock_guard;
    /// @endcond
    
    /// @brief Provides a mechanism that synchronizes access to objects.
    /// @code
    /// class core_export_ monitor static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::threading::monitor
    /// @par Header
    /// @code #include <xtd/threading/monitor> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example uses the xtd::threading::monitor class to synchronize access to a single instance of a random number generator represented by the xtd::random class. The example creates ten threads, each of which executes asynchronously on a thread pool thread. Each thread generates 10,000 random numbers, calculates their average, and updates two procedure-level variables that maintain a running total of the number of random numbers generated and their sum. After all threads have executed, these two values are then used to calculate the overall mean.
    /// @include monitor.cpp
    /// Because they can be accessed from any task running on a thread pool thread, access to the variables total and n must also be synchronized. The xtd::threading::interlocked::add method is used for this purpose.
    /// <br><br>The following example demonstrates the combined use of the xtd::threading::monitor class (implemented with the #lock_ keyword), the xtd::threading::interlocked class, and the xtd::threading::auto_reset_event class. It defines two classes, sync_resource and un_sync_resource, that respectively provide synchronized and unsynchronized access to a resource. To ensure that the example illustrates the difference between the synchronized and unsynchronized access (which could be the case if each method call completes rapidly), the method includes a random delay: for threads whose xtd::threading::thread::managed_thread_id property is even, the method calls xtd::threading::thread::sleep to introduce a delay of 2,000 milliseconds.
    /// @include monitor_lock.cpp
    /// The example defines a variable, num_ops, that defines the number of threads that will attempt to access the resource. The application thread calls the xtd::threading::thread_pool::queue_user_work_item method for synchronized and unsynchronized access five times each. The xtd::threading::thread_pool::queue_user_work_item method has a single parameter, a delegate that accepts no parameters and returns no value. For synchronized access, it invokes the sync_update_resource method; for unsynchronized access, it invokes the un_sync_update_resource method. After each set of method calls, the application thread calls the xtd::thrrading::auto_reset_event::wait_one method so that it blocks until the xtd::threading::auto_reset_event instance is signaled.
    /// <br><br>Each call to the sync_update_resource method calls the sync_resource::access method and then calls the xtd::threading::interlocked::decrement method to decrement the num_ops counter. The xtd::threading::interlocked::decrement method Is used to decrement the counter, because otherwise you cannot be certain that a second thread will access the value before a first thread's decremented value has been stored in the variable. When the last synchronized worker thread decrements the counter to zero, indicating that all synchronized threads have completed accessing the resource, the syncUpdate_resource method calls the xtd::threading::event_wait_handle::set method, which signals the main thread to continue execution.
    /// <br><br>Each call to the un_sync_update_resource method calls the un_syncResource::access method and then calls the xtd::threading::interlocked::decrement method to decrement the num_ops counter. Once again, the xtd::threading::interlocked::decrement method Is used to decrement the counter to ensure that a second thread does not access the value before a first thread's decremented value has been assigned to the variable. When the last unsynchronized worker thread decrements the counter to zero, indicating that no more unsynchronized threads need to access the resource, the un_sync_update_resource method calls the xtd::threading::event_wait_handle::set method, which signals the main thread to continue execution.
    /// <br><br>As the output from the example shows, synchronized access ensures that the calling thread exits the protected resource before another thread can access it; each thread waits on its predecessor. On the other hand, without the lock, the un_sync_resource::access method is called in the order in which threads reach it.
    /// @remarks The xtd::threading::monitor class allows you to synchronize access to a region of code by taking and releasing a lock on a particular object by calling the xtd::threading::monitor::enter, xtd::threading::monitor::try_enter, and xtd::threading::monitor::exit methods. Object locks provide the ability to restrict access to a block of code, commonly called a critical section. While a thread owns the lock for an object, no other thread can acquire that lock. You can also use the xtd::threading::monitor class to ensure that no other thread is allowed to access a section of application code being executed by the lock owner, unless the other thread is executing the code using a different locked object. Because the xtd::threading::monotor class has thread affinity, the thread that acquired a lock must release the lock by calling the xtd::threading::monotor::exit method.
    /// @par The xtd::threading::monitor class: An overview
    /// xtd::threading::monotor has the following features:
    /// * It is associated with an object on demand.
    /// * It is unbound, which means it can be called directly from any context.
    /// * An instance of the xtd::threading::monitor class cannot be created; the methods of the xtd::threading::monitor class are all static. Each method is passed the synchronized object that controls access to the critical section.
    /// The following table describes the actions that can be taken by threads that access synchronized objects:
    /// | Action                                                             | Description                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// | ------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
    /// | xtd::threading::monitor::enter, xtd::threading::monitor::try_enter | Acquires a lock for an object. This action also marks the beginning of a critical section. No other thread can enter the critical section unless it is executing the instructions in the critical section using a different locked object.                                                                                                                                                                                               |
    /// | xtd::threading::monitor::wait                                      | Releases the lock on an object in order to permit other threads to lock and access the object. The calling thread waits while another thread accesses the object. xtd::threading::monitor::pulse signals are used to notify waiting threads about changes to an object's state.                                                                                                                                                                                   |
    /// | xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all | Sends a signal to one or more waiting threads. The signal notifies a waiting thread that the state of the locked object has changed, and the owner of the lock is ready to release the lock. The waiting thread is placed in the object's ready queue so that it might eventually receive the lock for the object. Once the thread has the lock, it can check the new state of the object to see if the required state has been reached. |
    /// | xtd::threading::monitor::exit                                      | Releases the lock on an object. This action also marks the end of a critical section protected by the locked object.                                                                                                                                                                                                                                                                                                                     |
    /// There are two sets of overloads for the xtd::threading::monitor::enter and xtd::threading::monitor::try_enter methods. One set of overloads has a boolean parameter that is atomically set to true if the lock is acquired, even if an exception is thrown when acquiring the lock. Use these overloads if it is critical to release the lock in all cases, even when the resources the lock is protecting might not be in a consistent state.
    /// @par The lock object
    /// The xtd::threading::monitor class consists of static methods that operate on an object that controls access to the critical section. The following information is maintained for each synchronized object:
    /// * A reference to the thread that currently holds the lock.
    /// * A reference to a ready queue, which contains the threads that are ready to obtain the lock.
    /// * A reference to a waiting queue, which contains the threads that are waiting for notification of a change in the state of the locked object.
    /// @par The critical section
    /// Use the xtd::threading::monitor::enter and xtd::threading::monitor::exit methods to mark the beginning and end of a critical section.
    /// @note The functionality provided by the xtd::threading::monitor::enter and xtd::threading::monitor::exit methods is identical to that provided by the xtd::threading::lock_guard object and the #lock_ keyword, except that with the xtd class: :threading::lock_guard class and the #lock_ keyword, the xtd::threading::monitor::enter method and the xtd::threading::monitor::exit method are always called, even if an exception has occurred.
    /// @note It is therefore advisable to use the xtd::threading::lock_guard class or the #lock_ keyword instead of calling the xtd::threading::monitor::enter and xtd::threading::monitor::exit methods, to ensure that no critical sections remain in the xtd::threading::monitor class.
    /// @par
    /// The folowing code shows the use use of xtd:threading::monitor::enter and xtd:threading::monitor::exit when an exception occured :
    /// @code
    /// // Define the lock object.
    /// auto obj = object {};
    ///
    /// try {
    ///   // Define the critical section.
    ///   monitor::enter(obj);
    ///
    ///   // Code to execute one thread at a time.
    ///
    ///   // Define the end of the critical section.
    ///   monitor::exit(obj);
    /// } catch(...) {
    ///   // You also need to define the end of the critical section.
    ///   monitor::exit(obj);
    /// }
    /// @endcode
    /// <br>The same code with the xtd::threading::lock_guard class :
    /// @code
    /// // Define the lock object.
    /// auto obj = object {};
    ///
    /// try {
    ///   // Define the critical section.
    ///   lock_guard lock {obj};
    ///
    ///   // Code to execute one thread at a time.
    ///
    /// } catch(...) {
    ///
    /// }
    /// @endcode
    /// <br>The same code with the #lock_ keyword :
    /// @code
    /// // Define the lock object.
    /// auto obj = object {};
    ///
    /// try {
    ///   // Define the critical section.
    ///   lock_(obj) {
    ///     // Code to execute one thread at a time.
    ///   }
    /// } catch(...) {
    ///
    /// }
    /// @endcode
    /// @par pulse, pulse_all, and wait
    /// Once a thread owns the lock and has entered the critical section that the lock protects, it can call the xtd::threading::monitor::wait, xtd::threading::monitor::pulse, and xtd::threading::monitor::pulse_all methods.
    /// <br><br>When the thread that holds the lock calls xtd::threading::monitor::wait, the lock is released and the thread is added to the waiting queue of the synchronized object. The first thread in the ready queue, if any, acquires the lock and enters the critical section. The thread that called Wait is moved from the waiting queue to the ready queue when either the xtd::threading::monitor::pulse or the xtd::threading::monitor::pulse_all method is called by the thread that holds the lock (to be moved, the thread must be at the head of the waiting queue). The xtd::threading::monitor::wait method returns when the calling thread reacquires the lock.
    /// <br><br>When the thread that holds the lock calls xtd::threading::monitor::pulse, the thread at the head of the waiting queue is moved to the ready queue. The call to the xtd::threading::monitor::pulse_all method moves all the threads from the waiting queue to the ready queue.
    /// @par Monitors and wait handles
    /// It is important to note the distinction between the use of the xtd::threading::monitor class and xtd::threading::wait_handle objects.
    /// * The xtd::threading::monitor class is purely managed, fully portable, and might be more efficient in terms of operating-system resource requirements.
    /// * xtd::threading::wait_handle objects represent operating-system waitable objects, are useful for synchronizing between managed and unmanaged code, and expose some advanced operating-system features like the ability to wait on many objects at once.
    class core_export_ monitor static_ {
      class critical_section;
      struct item;
      using item_collection = std::unordered_map<intptr, item>;
      using ptr_item = std::pair<intptr, bool>;
      struct static_data;
      
    public:
      /// @name Methods
      
      /// @{
      /// @brief Acquires an exclusive lock on the specified obj.
      /// @param obj The object on which to acquire the monitor lock.
      /// @remarks Use xtd::threading::monotor::enter to acquire the xtd::threading::monotor on the object passed as the parameter. If another thread has executed an xtd::threading::monotor::enter on the object, but has not yet executed the corresponding xtd::threading::monitor::exit, the current thread will block until the other thread releases the object. It is legal for the same thread to invoke xtd::threading::monotor::enter more than once without it blocking; however, an equal number of xtd::threading::monitor::exit calls must be invoked before other threads waiting on the object will unblock.
      template<typename object_t>
      static void enter(const object_t& obj) {
        auto lock_taken = false;
        enter_ptr(get_ptr(obj), lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static void enter(const type_t* str) {enter(ustring(str));}
      /// @endcond

      /// @brief Acquires an exclusive lock on the specified obj.
      /// @param obj The object on which to acquire the monitor lock.
      /// @param lock_taken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
      /// @note If no exception occurs, the output of this method is always true.
      /// @remarks Use xtd::threading::monotor::enter to acquire the xtd::threading::monotor on the object passed as the parameter. If another thread has executed an xtd::threading::monotor::enter on the object, but has not yet executed the corresponding xtd::threading::monitor::exit, the current thread will block until the other thread releases the object. It is legal for the same thread to invoke xtd::threading::monotor::enter more than once without it blocking; however, an equal number of xtd::threading::monitor::exit calls must be invoked before other threads waiting on the object will unblock.
      template<typename object_t>
      static void enter(const object_t& obj, bool& lock_taken) {
        enter_ptr(get_ptr(obj), lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static void enter(const type_t* str, bool& lock_taken) {enter(ustring(str), lock_taken);}
      /// @endcond

      /// @brief Releases an exclusive lock on the specified obj.
      /// @param obj The object on which to release the lock.
      /// @remarks The calling thread must own the lock on the obj parameter. If the calling thread owns the lock on the specified object, and has made an equal number of xtd::threading::monitor::exit and xtd::threading::monotor::enter calls for the object, then the lock is released. If the calling thread has not invoked xtd::threading::monitor::exit as many times as xtd::threading::monotor::enter, the lock is not released.
      /// @remarks If the lock is released and other threads are in the ready queue for the object, one of the threads acquires the lock. If other threads are in the waiting queue waiting to acquire the lock, they are not automatically moved to the ready queue when the owner of the lock calls xtd::threading::monitor::exit. To move one or more waiting threads into the ready queue, call xtd::threading::monitor::pulse or xtd::threading::monitor::xtd::threading::monitor::pulse_all before invoking xtd::threading::monitor::exit.
      template<typename object_t>
      static void exit(const object_t& obj) {
        exit_ptr(get_ptr(obj));
      }
      
      /// @cond
      template<typename type_t>
      static void exit(const type_t* str) {exit(ustring(str));}
      /// @endcond

      /// @brief Determines whether the current thread holds the lock on the specified object.
      /// @param obj The object to test.
      /// @@return true if the current thread holds the lock on obj; otherwise, false.
      /// @remarks This method works only for locks that are acquired by using the methods of the xtd::threading::monitor class, or the xtd::threading::lock_guard class, or by using the #lock_ keyword, which are implemented with xtd::threading::monitor.
      /// @remarks Use this method with diagnostic tools, such as the xtd::diagnostics::debug::assert method, to debug locking issues that involve the xtd::threading::monitor class.
      template<typename object_t>
      static bool is_entered(const object_t& obj) {
        return is_entered_ptr(get_ptr(obj));
      }

      /// @cond
      template<typename type_t>
      static bool is_entered(const type_t* str) {return is_entered(ustring(str));}
      /// @endcond

      /// @brief Notifies a thread in the waiting queue of a change in the locked object's state.
      /// @param obj The object a thread is waiting for.
      /// @exception xtd::threading::synchronization_lock_exception The calling thread does not own the lock for the specified object.
      /// @remarks Only the current owner of the lock can signal a waiting object using xtd::threading::monitor::pulse.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal the next thread in line for the lock. Upon receiving the pulse, the waiting thread is moved to the ready queue. When the thread that invoked xtd::threading::monitor::pulse releases the lock, the next thread in the ready queue (which is not necessarily the thread that was pulsed) acquires the lock.
      /// @warning The xtd::threading::monitor class does not maintain state indicating that the xtd::threading::monitor::pulse method has been called. Thus, if you call xtd::threading::monitor::pulse when no threads are waiting, the next thread that calls xtd::threading::monitor::wait blocks as if xtd::threading::monitor::pulse had never been called. If two threads are using xtd::threading::monitor::pulse and xtd::threading::monitor::wait to interact, this could result in a deadlock. Contrast this with the behavior of the xtd::threading::auto_reset_event class: If you signal an xtd::threading::auto_reset_svent by calling its xtd::threading::event_wait_handle::set method, and there are no threads waiting, the xtd::threading::auto_reset_event remains in a signaled state until a thread calls xtd::threading::wait_handle::wait_one, xtd::threading::wait_handle::wait_any, or xtd::threading::wait_handle::wait_all. The xtd::threading::auto_reset_event releases that thread and returns to the unsignaled state.
      /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all, and xtd::threading::monitor::wait methods must be invoked from within a synchronized block of code.
      /// @remarks To signal multiple threads, use the xtd::threading::monitor::pulse_all method.
      template<typename object_t>
      static void pulse(const object_t& obj) {
        pulse_ptr(get_ptr(obj));
      }
      
      /// @cond
      template<typename type_t>
      static void pulse(const type_t* str) {pulse(ustring(str));}
      /// @endcond

      /// @brief Notifies all waiting threads of a change in the object's state.
      /// @param obj The object a thread is waiting for.
      /// @exception xtd::threading::synchronization_lock_exception The calling thread does not own the lock for the specified object.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal all threads waiting to acquire the lock on the object. After the signal is sent, the waiting threads are moved to the ready queue. When the thread that invoked xtd::threading::monitor::xtd::threading::monitor::pulse_all releases the lock, the next thread in the ready queue acquires the lock.
      /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::xtd::threading::monitor::pulse_all, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the xtd::threading::monitor::pulse method explain what happens if xtd::threading::monitor::pulse is called when no threads are waiting.
      /// @remarks To signal a single thread, use the xtd::threading::monitor::pulse method.
      template<typename object_t>
      static void pulse_all(const object_t& obj) {
        pulse_all_ptr(get_ptr(obj));
      }
      
      /// @cond
      template<typename type_t>
      static void pulse_all(const type_t* str) {pulse_all(ustring(str));}
      /// @endcond

      /// @brief Attempts to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If successful, this method acquires an exclusive lock on the obj parameter. This method returns immediately, whether or not the lock is available.
      /// @remarks This method is similar to xtd::threading::monotor::enter, but it will never block. If the thread cannot enter without blocking, the method returns false, and the thread does not enter the critical section.
      template<typename object_t>
      static bool try_enter(const object_t& obj) noexcept {
        auto lock_taken = false;
        return try_enter_ptr(get_ptr(obj), timeout::infinite, lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str) {return try_enter(ustring(str));}
      /// @endcond

      /// @brief Attempts to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param lock_taken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
      /// @note If no exception occurs, the output of this method is always true.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If successful, this method acquires an exclusive lock on the obj parameter. This method returns immediately, whether or not the lock is available.
      /// @remarks This method is similar to xtd::threading::monotor::enter, but it will never block. If the thread cannot enter without blocking, the method returns false, and the thread does not enter the critical section.
      template<typename object_t>
      static bool try_enter(const object_t& obj, bool& lock_taken) noexcept {
        return try_enter_ptr(get_ptr(obj), timeout::infinite, lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, bool& lock_taken) {return try_enter(ustring(str), lock_taken);}
      /// @endcond

      /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param milliseconds_timeout The number of milliseconds to wait for the lock.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the milliseconds_timeout parameter equals Timeout::Infinite, this method is equivalent to xtd::threading::monotor::enter. If milliseconds_timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, int32 milliseconds_timeout) noexcept {
        auto lock_taken = false;
        return try_enter_ptr(get_ptr(obj), milliseconds_timeout, lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, int32 milliseconds_timeout) {return try_enter(ustring(str), milliseconds_timeout);}
      /// @endcond

      /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param milliseconds_timeout The number of milliseconds to wait for the lock.
      /// @param lock_taken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
      /// @note If no exception occurs, the output of this method is always true.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the milliseconds_timeout parameter equals Timeout::Infinite, this method is equivalent to xtd::threading::monotor::enter. If milliseconds_timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, int32 milliseconds_timeout, bool& lock_taken) noexcept {
        return try_enter_ptr(get_ptr(obj), milliseconds_timeout, lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, int32 milliseconds_timeout, bool& lock_taken) {return try_enter(ustring(str), milliseconds_timeout, lock_taken);}
      /// @endcond

      /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param milliseconds_timeout The number of milliseconds to wait for the lock.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the milliseconds_timeout parameter equals Timeout::Infinite, this method is equivalent to xtd::threading::monotor::enter. If milliseconds_timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, int64 milliseconds_timeout) noexcept {
        auto lock_taken = false;
        return try_enter_ptr(get_ptr(obj), static_cast<int32>(milliseconds_timeout), lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, int64 milliseconds_timeout) {return try_enter(ustring(str), milliseconds_timeout);}
      /// @endcond

      /// @brief Attempts, for the specified number of milliseconds, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param milliseconds_timeout The number of milliseconds to wait for the lock.
      /// @param lock_taken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
      /// @note If no exception occurs, the output of this method is always true.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the milliseconds_timeout parameter equals Timeout::Infinite, this method is equivalent to xtd::threading::monotor::enter. If milliseconds_timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, int64 milliseconds_timeout, bool& lock_taken) noexcept {
        return try_enter_ptr(get_ptr(obj), static_cast<int32>(milliseconds_timeout), lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, int64 milliseconds_timeout, bool& lock_taken) {return try_enter(ustring(str), milliseconds_timeout, lock_taken);}
      /// @endcond

      /// @brief Attempts, for the specified amount of time, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param timeout A time_span representing the amount of time to wait for the lock. A value of -1 millisecond specifies an infinite wait.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the value of the timeout parameter converted to milliseconds equals -1, this method is equivalent to xtd::threading::monotor::enter. If the value of timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, const time_span& timeout) noexcept {
        auto lock_taken = false;
        return try_enter_ptr(get_ptr(obj), timeout.total_milliseconds_duration().count(), lock_taken);
      }
      
      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, const time_span& timeout) {return try_enter(ustring(str), timeout);}
      /// @endcond

      /// @brief Attempts, for the specified amount of time, to acquire an exclusive lock on the specified object.
      /// @param obj The object on which to acquire the lock.
      /// @param timeout A time_span representing the amount of time to wait for the lock. A value of -1 millisecond specifies an infinite wait.
      /// @param lock_taken The result of the attempt to acquire the lock, passed by reference. The input must be false. The output is true if the lock is acquired; otherwise, the output is false. The output is set even if an exception occurs during the attempt to acquire the lock.
      /// @note If no exception occurs, the output of this method is always true.
      /// @return bool true if the current thread acquires the lock; otherwise, false
      /// @remarks If the value of the timeout parameter converted to milliseconds equals -1, this method is equivalent to xtd::threading::monotor::enter. If the value of timeout equals 0, this method is equivalent to try_enter.
      template<typename object_t>
      static bool try_enter(const object_t& obj, const time_span& timeout, bool& lock_taken) noexcept {
        return try_enter_ptr(get_ptr(obj), timeout.total_milliseconds_duration().count(), lock_taken);
      }

      /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock. If the specified time-out interval elapses, the thread enters the ready queue. This method also specifies whether the synchronization domain for the context (if in a synchronized context) is exited before the wait and reacquired afterward.
      /// @param obj The object on which to wait.
      /// @param milliseconds_timeout The number of milliseconds to wait before the thread enters the ready queue.
      /// @param exit_context true to exit and reacquire the synchronization domain for the context (if in a synchronized context) before the wait; otherwise, false.
      /// @return true if the lock was reacquired before the specified time elapsed; false if the lock was reacquired after the specified time elapsed. The method does not return until the lock is reacquired.
      ///
      template<typename object_t>
      static bool wait(const object_t& obj, int32 milliseconds_timeout, bool exit_context) {
        return wait_ptr(get_ptr(obj), milliseconds_timeout, exit_context);
      }
      
      template<typename object_t>
      static bool wait(const object_t& obj, const time_span& timeout, bool exit_context) {
        return wait_ptr(get_ptr(obj), as<int32>(timeout.total_milliseconds()), exit_context);
      }

      template<typename object_t>
      static bool wait(const object_t& obj, int32 milliseconds_timeout) {
        return wait_ptr(get_ptr(obj), milliseconds_timeout, false);
      }
      
      template<typename object_t>
      static bool wait(const object_t& obj, const time_span& timeout) {
        return wait_ptr(get_ptr(obj), as<int32>(timeout.total_milliseconds()), false);
      }

      template<typename object_t>
      static bool wait(const object_t& obj) {
        return wait_ptr(get_ptr(obj), timeout::infinite, false);
      }
      /// @}

      /// @cond
      template<typename type_t>
      static bool try_enter(const type_t* str, const time_span& timeout, bool& lock_taken) {return try_enter(ustring(str), timeout, lock_taken);}
      /// @endcond
      
    private:
      friend class xtd::threading::lock_guard;

      static static_data& get_static_data();

      template<typename object_t>
      static ptr_item get_ptr(const object_t& obj) noexcept {
        bool is_string = is<ustring>(obj);
        // The newly created string will be deleted when the exit method is called, or if the lock has already been entered.
        return std::make_pair(is_string ? get_ustring_ptr(*(new ustring(as<ustring>(obj)))) : reinterpret_cast<intptr>(&obj), is_string);
      }
      
      template<typename type_t>
      static ptr_item get_ptr(const type_t* str) {return get_ptr(ustring(str));}

      static void enter_ptr(ptr_item ptr);
      static void enter_ptr(ptr_item ptr, bool& lock_taken);
      static void exit_ptr(ptr_item ptr);
      static intptr get_ustring_ptr(const ustring& str);
      static bool is_entered_ptr(ptr_item ptr) noexcept;
      static void pulse_ptr(ptr_item obj);
      static void pulse_all_ptr(ptr_item obj);
      static bool try_enter_ptr(ptr_item ptr, int32 milliseconds_timeout, bool& lock_taken) noexcept;
      static bool wait_ptr(ptr_item ptr, int32 milliseconds_timeout, bool exit_context);
    };
  }
}
