/// @file
/// @brief Contains xtd::threading::spin_lock exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../object.h"
#include "../time_span.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides a mutual exclusion lock primitive where a thread trying to acquire the lock waits in a loop repeatedly checking until the lock becomes available.
    /// @code
    /// class spin_lock : public xtd::object
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/spin_lock> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example shows how to use a xtd::threading::spin_lock:
    /// @include spin_lock.cpp
    /// @remarks Spin locks can be used for leaf-level locks where the object allocation implied by using a xtd::threading::monitor, in size, is overly expensive. A spin lock can be useful to avoid blocking; however, if you expect a significant amount of blocking, you should probably not use spin locks due to excessive spinning. Spinning can be beneficial when locks are fine-grained and large in number (for example, a lock per node in a linked list) and also when lock hold-times are always extremely short. In general, while holding a spin lock, one should avoid any of these actions:
    /// * blocking,
    /// * calling anything that itself may block,
    /// * holding more than one spin lock at once,
    /// * making dynamically dispatched calls (interface and virtuals),
    /// * making statically dispatched calls into any code one doesn't own, or
    /// * allocating memory.
    /// @remarks xtd::threading::spin_lock should only be used after you have been determined that doing so will improve an application's performance. It is also important to note that xtd::threading::spin_lock is a value type, for performance reasons. For this reason, you must be very careful not to accidentally copy a xtd::threading::spin_lock instance, as the two instances (the original and the copy) would then be completely independent of one another, which would likely lead to erroneous behavior of the application. If a xtd::threading::spin_lock instance must be passed around, it should be passed by reference rather than by value.
    class spin_lock : public object {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::spin_lock structure
      spin_lock();
      /// @brief Initializes a new instance of the xtd::threading::spin_lock structure with the option to track thread IDs to improve debugging.
      /// @param enable_thread_owner_tracking Whether to capture and use thread IDs for debugging purposes.
      /// @remarks The parameterless constructor for xtd::threading::spin_lock tracks thread ownership.
      spin_lock(bool enable_thread_owner_tracking);
      /// @}

      ///@cond
      spin_lock(spin_lock&&) = default;
      spin_lock(const spin_lock&) = default;
      spin_lock& operator =(const spin_lock& other) = default;
      ///@endcond

      /// @name Public Properties
      
      /// @{
      ///@brief Gets whether the lock is currently held by any thread.
      ///@return true if the lock is currently held by any thread; otherwise false.
      bool is_held() const noexcept;

      /// @brief Gets whether the lock is held by the current thread.
      /// @return true if the lock is held by the current thread; otherwise false.
      /// @remarks If the lock was initialized to track owner threads, this will return whether the lock is acquired by the current thread. It is invalid to use this property when the lock was initialized to not track thread ownership.
      bool is_held_by_current_thread() const noexcept;
      
      /// @brief Gets whether thread ownership tracking is enabled for this instance.
      /// @return true if thread ownership tracking is enabled for this instance; otherwise false.
      bool is_thread_owner_tracking_enabled() const noexcept;
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Acquires the lock in a reliable manner, such that even if an exception occurs within the method call, lock_taken can be examined reliably to determine whether the lock was acquired.
      /// @param lock_taken True if the lock is acquired; otherwise, false.
      /// @exception xtd::threading::lock_recursion_exception Thread ownership tracking is enabled, and the current thread has already acquired this lock.
      /// @remarks xtd::threading::spin_lock is a non-reentrant lock, meaning that if a thread holds the lock, it is not allowed to enter the lock again. If thread ownership tracking is enabled (whether it's enabled is available through xtd::threading::spin_lock::is_thread_owner_tracking_enabled), an exception will be thrown when a thread tries to re-enter a lock it already holds. However, if thread ownership tracking is disabled, attempting to enter a lock already held will result in deadlock.
      void enter(bool& lock_taken);
      
      /// @brief Releases the lock.
      /// @exception xtd::threading::synchronization_lock_exception Thread ownership tracking is enabled, and the current thread is not the owner of this lock.
      /// @remarks The default overload of Exit provides the same behavior as if calling Exit using true as the argument.
      /// @remarks If you call xtd::threading::spin_lock::exit without having first called xtd::threading::spin_lock::enter the internal state of the xtd::threading::spin_lock can become corrupted.
      void exit();
      /// @brief Releases the lock.
      /// @param use_memory_barrier A bool value that indicates whether a memory fence should be issued in order to immediately publish the exit operation to other threads.
      /// @exception xtd::threading::synchronization_lock_exception Thread ownership tracking is enabled, and the current thread is not the owner of this lock.
      /// @remarks Calling Exit with the use_memory_barrier argument set to true will improve the fairness of the lock at the expense of some performance. The default xtd::threading::spin_lock::exit overload behaves as if specifying true for use_memory_barrier.
      /// @remarks If you call xtd::threading::spin_lock::exit without having first called xtd::threading::spin_lock::enter the internal state of the xtd::threading::spin_lock can become corrupted.
      void exit(bool use_memory_barrier);

      /// @brief Attempts to acquire the lock in a reliable manner, such that even if an exception occurs within the method call, lock_taken can be examined reliably to determine whether the lock was acquired.
      /// @param lock_taken True if the lock is acquired; otherwise, false.
      /// @exception xtd::threading::lock_recursion_exception Thread ownership tracking is enabled, and the current thread has already acquired this lock.
      /// @remarks Unlike xtd::threading::spin_lock::enter, xtd::threading::spin_lock::try_enter will not block waiting for the lock to be available. If the lock is not available when xtd::threading::spin_lock::try_enter is called, it will return immediately without any further spinning.
      void try_enter(bool& lock_taken);
      /// @brief Attempts to acquire the lock in a reliable manner, such that even if an exception occurs within the method call, lock_taken can be examined reliably to determine whether the lock was acquired.
      /// @param milliseconds_timeout The number of milliseconds to wait, or xtd::threading::timeout::infinite (-1) to wait indefinitely.
      /// @param lock_taken True if the lock is acquired; otherwise, false.
      /// @exception xtd::threading::lock_recursion_exception Thread ownership tracking is enabled, and the current thread has already acquired this lock.
      /// @remarks Unlike xtd::threading::spin_lock::enter, xtd::threading::spin_lock::try_enter will not block indefinitely waiting for the lock to be available. It will block until either the lock is available or until the milliseconds_timeout has expired.
      void try_enter(int32 milliseconds_timeout, bool& lock_taken);
      /// @brief Attempts to acquire the lock in a reliable manner, such that even if an exception occurs within the method call, lock_taken can be examined reliably to determine whether the lock was acquired
      /// @param timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @param lock_taken True if the lock is acquired; otherwise, false.
      /// @exception xtd::threading::lock_recursion_exception Thread ownership tracking is enabled, and the current thread has already acquired this lock.
      /// @remarks Unlike xtd::threading::spin_lock::enter, xtd::threading::spin_lock::try_enter will not block indefinitely waiting for the lock to be available. It will block until either the lock is available or until the timeout has expired.
      void try_enter(const time_span& timeout, bool& lock_taken);
      /// @}

    private:
      mutable std::shared_ptr<data> data_;
    };
  }
}
