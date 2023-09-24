/// @file
/// @brief Contains xtd::threading::lock_guard class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../object"
#include "../using"
#include "monitor"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides a mechanism that synchronizes access to objects with xtd::threading::monitor.
    /// @code
    /// class core_export_ lock_guard final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::lock_guard
    /// @par Header
    /// @code #include <xtd/threading/lock_guard> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example uses the xtd::threading::lock_guard class to synchronize access to a single instance of a random number generator represented by the xtd::random class. The example creates ten threads, each of which executes asynchronously on a thread pool thread. Each thread generates 10,000 random numbers, calculates their average, and updates two procedure-level variables that maintain a running total of the number of random numbers generated and their sum. After all threads have executed, these two values are then used to calculate the overall mean.
    /// @include lock_guard.cpp
    /// @remarks See xtd::threading::monitor for more information.
    class core_export_ lock_guard final : public object {
    public:
      /// @name Constructors

      /// @{
      /// @brief Create a xtd::threaing::lock_guard object and acquires an exclusive lock on the specified obj.
      /// @param obj The object on which to acquire the monitor lock.
      /// @remarks When the xtd::threading::lock_guard destroyed it releases the exclusive lock specified in the constructor.
      template<typename object_t>
      explicit lock_guard(const object_t& obj) : obj_(monitor::get_ptr(obj)) {monitor::enter_ptr(obj_);}
      /// @}
      
      /// @cond
      ~lock_guard();
      /// @endcond

      /// @name Methods

      /// @{
      /// @brief Notifies a thread in the waiting queue of a change in the locked object's state.
      /// @remarks Only the current owner of the lock can signal a waiting object using xtd::threading::monitor::pulse.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal the next thread in line for the lock. Upon receiving the pulse, the waiting thread is moved to the ready queue. When the thread that invoked xtd::threading::monitor::pulse releases the lock, the next thread in the ready queue (which is not necessarily the thread that was pulsed) acquires the lock.
      /// @warning The xtd::threading::monitor class does not maintain state indicating that the xtd::threading::monitor::pulse method has been called. Thus, if you call xtd::threading::monitor::pulse when no threads are waiting, the next thread that calls xtd::threading::monitor::wait blocks as if xtd::threading::monitor::pulse had never been called. If two threads are using xtd::threading::monitor::pulse and xtd::threading::monitor::wait to interact, this could result in a deadlock. Contrast this with the behavior of the xtd::threading::auto_reset_event class: If you signal an xtd::threading::auto_reset_event by calling its xtd::threading::event_wait_handle::set method, and there are no threads waiting, the xtd::threading::auto_reset_event remains in a signaled state until a thread calls xtd::threading::wait_handle::wait_one, xtd::threading::wait_handle::wait_any, or xtd::threading::wait_handle::wait_all. The xtd::threading::auto_reset_event releases that thread and returns to the unsignaled state.
      /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all, and xtd::threading::monitor::wait methods must be invoked from within a synchronized block of code.
      /// @remarks To signal multiple threads, use the xtd::threading::monitor::pulse_all method.
      void pulse();

      /// @brief Notifies all waiting threads of a change in the object's state.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal all threads waiting to acquire the lock on the object. After the signal is sent, the waiting threads are moved to the ready queue. When the thread that invoked xtd::threading::monitor::xtd::threading::monitor::pulse_all releases the lock, the next thread in the ready queue acquires the lock.
      /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::xtd::threading::monitor::pulse_all, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the xtd::threading::monitor::pulse method explain what happens if xtd::threading::monitor::pulse is called when no threads are waiting.
      /// @remarks To signal a single thread, use the xtd::threading::monitor::pulse method.
      void pulse_all();

      /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock. If the specified time-out interval elapses, the thread enters the ready queue.
      /// @param obj The object on which to wait.
      /// @param milliseconds_timeout The number of milliseconds to wait before the thread enters the ready queue.
      /// @return true if the lock was reacquired before the specified time elapsed; false if the lock was reacquired after the specified time elapsed. The method does not return until the lock is reacquired.
      /// @exception xtd::threading::synchronization_lock_exception xtd::threading::monitor::wait is not invoked from within a synchronized block of code.
      /// @remarks This method does not return until it reacquires an exclusive lock on the obj parameter.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
      /// @remarks The time-out ensures that the current thread does not block indefinitely if another thread releases the lock without first calling the xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method. It also moves the thread to the ready queue, bypassing other threads ahead of it in the wait queue, so that it can reacquire the lock sooner. The thread can test the return value of the xtd::threading::monitor::wait method to determine whether it reacquired the lock prior to the time-out. The thread can evaluate the conditions that caused it to enter the wait, and if necessary call the xtd::threading::monitor::wait method again.
      /// @remarks When a thread calls xtd::threading::monitor::wait, it releases the lock and enters the waiting queue. At this point, the next thread in the ready queue (if there is one) is allowed to take control of the lock. The thread that invoked Wait remains in the waiting queue until either a thread that holds the lock invokes xtd::threading::monitor::pulse_all, or it is the next in the queue and a thread that holds the lock invokes xtd::threading::monitor::pulse. However, if milliseconds_timeout elapses before another thread invokes this object's xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method, the original thread is moved to the ready queue in order to regain the lock.
      /// @note If xtd::threading::timeout::infinite is specified for the milliseconds_timeout parameter, this method blocks indefinitely unless the holder of the lock calls xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all. If milliseconds_timeout equals 0, the thread that calls Wait releases the lock and then immediately enters the ready queue in order to regain the lock.
      /// @remarks The caller executes xtd::threading::monitor::wait once, regardless of the number of times xtd::threading::monitor::enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked xtd::threading::monitor::enter on the object and invokes xtd::threading::monitor::exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls xtd::threading::monitor::enter as many times as necessary to restore the saved xtd::threading::monitor::enter count for the caller. Calling xtd::threading::monitor::wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
      /// @note A synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the xtd::threading::monitor::pulse method explain what happens if xtd::threading::monitor::pulse is called when no threads are waiting.
      bool wait(int32 milliseconds_timeout);
      
      /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock. If the specified time-out interval elapses, the thread enters the ready queue.
      /// @param timeout A xtd::time_span representing the amount of time to wait before the thread enters the ready queue.
      /// @return true if the lock was reacquired before the specified time elapsed; false if the lock was reacquired after the specified time elapsed. The method does not return until the lock is reacquired.
      /// @exception xtd::threading::synchronization_lock_exception xtd::threading::monitor::wait is not invoked from within a synchronized block of code.
      /// @remarks This method does not return until it reacquires an exclusive lock on the obj parameter.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
      /// @remarks The time-out ensures that the current thread does not block indefinitely if another thread releases the lock without first calling the xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method. It also moves the thread to the ready queue, bypassing other threads ahead of it in the wait queue, so that it can reacquire the lock sooner. The thread can test the return value of the xtd::threading::monitor::wait method to determine whether it reacquired the lock prior to the time-out. The thread can evaluate the conditions that caused it to enter the wait, and if necessary call the xtd::threading::monitor::wait method again.
      /// @remarks When a thread calls xtd::threading::monitor::wait, it releases the lock and enters the waiting queue. At this point, the next thread in the ready queue (if there is one) is allowed to take control of the lock. The thread that invoked Wait remains in the waiting queue until either a thread that holds the lock invokes xtd::threading::monitor::pulse_all, or it is the next in the queue and a thread that holds the lock invokes xtd::threading::monitor::pulse. However, if milliseconds_timeout elapses before another thread invokes this object's xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method, the original thread is moved to the ready queue in order to regain the lock.
      /// @note If xtd::threading::timeout::infinite is specified for the milliseconds_timeout parameter, this method blocks indefinitely unless the holder of the lock calls xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all. If milliseconds_timeout equals 0, the thread that calls Wait releases the lock and then immediately enters the ready queue in order to regain the lock.
      /// @remarks The caller executes xtd::threading::monitor::wait once, regardless of the number of times xtd::threading::monitor::enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked xtd::threading::monitor::enter on the object and invokes xtd::threading::monitor::exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls xtd::threading::monitor::enter as many times as necessary to restore the saved xtd::threading::monitor::enter count for the caller. Calling xtd::threading::monitor::wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
      /// @note A synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the xtd::threading::monitor::pulse method explain what happens if xtd::threading::monitor::pulse is called when no threads are waiting.
      bool wait(const time_span& timeout);
      
      /// @brief Releases the lock on an object and blocks the current thread until it reacquires the lock.
      /// @return true if the call returned because the caller reacquired the lock for the specified object. This method does not return if the lock is not reacquired.
      /// @exception xtd::threading::synchronization_lock_exception xtd::threading::monitor::wait is not invoked from within a synchronized block of code.
      /// @remarks This method does not return until it reacquires an exclusive lock on the obj parameter.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method in order to release the object so that another thread can access it. The caller is blocked while waiting to reacquire the lock. This method is called when the caller needs to wait for a state change that will occur as a result of another thread's operations.
      /// @remarks The time-out ensures that the current thread does not block indefinitely if another thread releases the lock without first calling the xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method. It also moves the thread to the ready queue, bypassing other threads ahead of it in the wait queue, so that it can reacquire the lock sooner. The thread can test the return value of the xtd::threading::monitor::wait method to determine whether it reacquired the lock prior to the time-out. The thread can evaluate the conditions that caused it to enter the wait, and if necessary call the xtd::threading::monitor::wait method again.
      /// @remarks When a thread calls xtd::threading::monitor::wait, it releases the lock and enters the waiting queue. At this point, the next thread in the ready queue (if there is one) is allowed to take control of the lock. The thread that invoked Wait remains in the waiting queue until either a thread that holds the lock invokes xtd::threading::monitor::pulse_all, or it is the next in the queue and a thread that holds the lock invokes xtd::threading::monitor::pulse. However, if milliseconds_timeout elapses before another thread invokes this object's xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all method, the original thread is moved to the ready queue in order to regain the lock.
      /// @note If xtd::threading::timeout::infinite is specified for the milliseconds_timeout parameter, this method blocks indefinitely unless the holder of the lock calls xtd::threading::monitor::pulse or xtd::threading::monitor::pulse_all. If milliseconds_timeout equals 0, the thread that calls Wait releases the lock and then immediately enters the ready queue in order to regain the lock.
      /// @remarks The caller executes xtd::threading::monitor::wait once, regardless of the number of times xtd::threading::monitor::enter has been invoked for the specified object. Conceptually, the Wait method stores the number of times the caller invoked xtd::threading::monitor::enter on the object and invokes xtd::threading::monitor::exit as many times as necessary to fully release the locked object. The caller then blocks while waiting to reacquire the object. When the caller reacquires the lock, the system calls xtd::threading::monitor::enter as many times as necessary to restore the saved xtd::threading::monitor::enter count for the caller. Calling xtd::threading::monitor::wait releases the lock for the specified object only; if the caller is the owner of locks on other objects, these locks are not released.
      /// @note A synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The xtd::threading::monitor::pulse, xtd::threading::monitor::pulse_all, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the xtd::threading::monitor::pulse method explain what happens if xtd::threading::monitor::pulse is called when no threads are waiting.
      bool wait();
      /// @}
      
    private:
      lock_guard() = delete;
      monitor::object_ptr obj_;
    };
  }
}

/// @brief The lock_guard_ keyword marks a statement block as a critical section by obtaining the mutual-exclusion lock for a given object, executing a statement, and then releasing the lock. The following example includes a lock statement.
/// @code
/// class account : public object {
/// public:
///   void withdraw(decimal amount) {
///     lock_guard_ (balance) {
///       if (amount > balance)
///         throw system_exception("Insufficient funds");
///       balance -= amount;
///     }
///   }
///
/// private:
///   decimal balance;
/// };
/// @endcode
/// For more information, see Thread Synchronization.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks The lock_guard_ keyword ensures that one thread does not enter a critical section of code while another thread is in the critical section. If another thread tries to enter a locked code, it will wait, block, until the object is released.
/// @remarks The section Threading discusses threading.
/// @remarks The lock_guard_ keyword calls Enter at the start of the block and Exit at the end of the block. A xtd::threading::thread_interrupted_exception is thrown if xtd::threading::thread::interrupt interrupts a thread that is waiting to enter a lock statement.
/// @remarks In general, avoid locking on a public type, or instances beyond your code's control. The common constructs lock_guard_ (*this), lock_guard_ (typeof_<my_type>()), and lock_guard_ ("myLock") violate this guideline:
/// * lock_guard_ (*this) is a problem if the instance can be accessed publicly.
/// * lock_guard_ (typeof_<my_type>()) is a problem if my_type is publicly accessible.
/// * lock_guard_ ("my_lock") is a problem because any other code in the process using the same string, will share the same lock.
/// @remarks Best practice is to define a private object to lock on, or a private static object variable to protect data common to all instances.
/// @remarks You can't use the await_ keyword in the body of a lock_guard_ statement.
/// @par Examples
/// The following sample shows a simple use of threads without locking in C++.
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
/// using namespace xtd::rhreading;
///
/// class thread_test {
/// public:
///   void run_me() {
///     console::write_line("run_me called");
///   }
///
///   static void main() {
///     thread_test b;
///     auto t = thread {thread_start {b, &thread_test::run_me));
///     t.start();
///   }
/// };
///
/// startup_(thread_test::main)
///
/// // Output: run_me called
/// @endcode
/// @par Examples
/// The following sample uses threads and lock_guard_. As long as the lock statement is present, the statement block is a critical section and balance will never become a negative number.
/// @include lock_guard_keyword.cpp
/// @ingroup Keywords
#define lock_guard_(object)\
  using_ (xtd::threading::lock_guard __xtd_lock_guard__(object))
