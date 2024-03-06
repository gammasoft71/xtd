/// @file
/// @brief Contains xtd::threading::mutex exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "wait_handle.h"
#include "../date_time.h"
#include "../icomparable.h"
#include "../iequatable.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @cond
    class thread;
    /// @endcond
    
    /// @brief A synchronization primitive that can also be used for interprocess synchronization.
    /// @code
    /// class mutex : public xtd::threading::wait_handle, public icomparable<mutex>, public xtd::iequatable<mutex>
    /// @endcode
    /// @par Header
    /// @code #include <xtd/threading/mutex> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks When two or more threads need to access a shared resource at the same time, the system needs a synchronization mechanism to ensure that only one thread at a time uses the resource. xtd::threading::mutex is a synchronization primitive that grants exclusive access to the shared resource to only one thread. If a thread acquires a mutex, the second thread that wants to acquire that mutex is suspended until the first thread releases the mutex.
    /// @remarks You can use the xtd::threading::wait_handle::wait_one method to request ownership of a mutex. The calling thread blocks until one of the following occurs:
    /// * The mutex is signaled to indicate that it is not owned. When this happens, the xtd::threading::wait_handle::wait_one method returns true, and the calling thread assumes ownership of the mutex and accesses the resource protected by the mutex. When it has finished accessing the resource, the thread must call the xtd::threading::mutex::release_mutex method to release ownership of the mutex. The first example in the Examples section illustrates this pattern.
    /// * The time-out interval specified in the call to a xtd::threading::wait_handle::wait_one method that has a @verbatim milliseconds_timeout @endverbatim or timeout parameter has elapsed. When this happens, the xtd::threading::wait_handle::wait_one method returns false, and the calling thread makes no further attempt to acquire ownership of the mutex. In this case, you should structure your code so that access to the resource that is protected by the mutex is denied to the calling thread. Because the thread never acquired ownership of the mutex, it must not call the xtd::threading::mutex::release_mutex method. The second example in the Examples section illustrates this pattern.
    /// @remarks The xtd::threading::mutex class enforces thread identity, so a mutex can be released only by the thread that acquired it. By contrast, the xtd::threading::semaphore class does not enforce thread identity. A mutex can also be passed across application domain boundaries.
    /// @remarks The thread that owns a mutex can request the same mutex in repeated calls to xtd::threading::wait_handle::wait_one without blocking its execution. However, the thread must call the xtd::threading::mutex::release_mutex method the same number of times to release ownership of the mutex.
    /// @remarks Because the xtd::threading::mutex class inherits from xtd::threading::wait_handle, you can also call the static xtd::threading::wait_handle::wait_all and xtd::threading::wait_handle::wait_any methods to synchronize access to a protected resource.
    /// @remarks If a thread terminates while owning a mutex, the mutex is said to be abandoned. The state of the mutex is set to signaled, and the next waiting thread gets ownership. An xtd::threading::abandoned_mutex_exception is thrown in the next thread that acquires the abandoned mutex.
    /// @warning An abandoned mutex often indicates a serious error in the code. When a thread exits without releasing the mutex, the data structures protected by the mutex might not be in a consistent state. The next thread to request ownership of the mutex can handle this exception and proceed, if the integrity of the data structures can be verified.
    /// @remarks In the case of a system-wide mutex, an abandoned mutex might indicate that an application has been terminated abruptly (for example, by using Windows Task Manager).
    /// @remarks Mutexes are of two types: local mutexes, which are unnamed, and named system mutexes. A local mutex exists only within your process. It can be used by any thread in your process that has a reference to the xtd::threading::mutex object that represents the mutex. Each unnamed xtd::threading::mutex object represents a separate local mutex.
    /// @remarks Named system mutexes are visible throughout the operating system, and can be used to synchronize the activities of processes. You can create a xtd::threading::mutex object that represents a named system mutex by using a constructor that accepts a name. The operating-system object can be created at the same time, or it can exist before the creation of the xtd::threading::mutex object. You can create multiple xtd::threading::mutex objects that represent the same named system mutex, and you can use the xtd::threading::mutex::open_existing method to open an existing named system mutex.
    /// @warning The backslash (\) and slash(/) are a reserved character in a mutex name. Don't use a backslash (\) and slash (/) in a mutex name except as specified in the note on using mutexes in terminal server sessions. Otherwise, a xtd::io::directory_not_found_exception may be thrown, even though the name of the mutex represents an existing file.
    /// @remarks The unnamed mutex is a <a href="https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex">std::recursive_timed_mutex</a> of C++17. You can therefore use xtd::threading::mutex or <a href="https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex">std::recursive_timed_mutex</a> indifferently in your projects.
    /// @remarks If you use other synchronization objects for your threads and you use xtd::threading::thread you are interested in using xtd::threading::mutex. You will also benefit from xtd::threading::wait_handle::wait_all and xtd::threading::wait_handle::wait_any among others to synchronize all your objects.
    /// @remarks  On the other hand, if you only use mutexes and you use <a href="https://en.cppreference.com/w/cpp/thread/thread">std::thread</a> then you are interested in using <a href="https://en.cppreference.com/w/cpp/thread/recursive_timed_mutex">std::recursive_timed_mutex</a>.
    /// @par Examples
    /// This example shows how a local xtd::threading::mutex object is used to synchronize access to a protected resource. Because each calling thread is blocked until it acquires ownership of the mutex, it must call the xtd::threading::mutex::release_mutex method to release ownership of the mutex.
    /// @include mutex.cpp
    class core_export_ mutex : public wait_handle, public icomparable<mutex>, public iequatable<mutex> {
      class mutex_base;
      class named_mutex;
      class unnamed_mutex;
    public:
      /// @name Alias
      
      /// @{
      /// @brief Rpresents the native handle type.
      using native_handle_type = intptr;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::mutex class with default properties.
      /// @remarks Calling this constructor overload is the same as calling the xtd::threading::mutex::mutex(bool) constructor overload and specifying false for initial ownership of the mutex. That is, the calling thread does not own the mutex.
      mutex();
      /// @brief Initializes a new instance of the xtd::threading::mutex with a bool value that indicates whether the calling thread should have initial ownership of the mutex.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      explicit mutex(bool initially_owned);
      /// @brief Initializes a new instance of the xtd::threading::mutex class with a string that is the name of the mutex.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, an empty string. The name is case-sensitive. The backslash character (\) and slsh (/) are reserved.
      /// @exception xtd::io::io_xception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks The initially owned is set to flase.
      explicit mutex(const ustring& name);
      /// @brief Initializes a new instance of the xtd::threading::mutex class with a string that is the name of the mutex, and a bool value that, when the method returns, indicates whether the calling thread was granted initial ownership of the mutex.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, an empty string. The name is case-sensitive. The backslash character (\) and slsh (/) are reserved.
      /// @param created_new When this method returns, contains a bool that is true if a local mutex was created (that is, if name is empty string) or if the specified named system mutex was created; false if the specified named system mutex already existed.
      /// @exception xtd::io::io_xception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      /// @remarks The initially owned is set to flase.
      mutex(const ustring& name, bool& created_new);
      /// @brief Initializes a new instance of the xtd::threading::mutex class with a bool value that indicates whether the calling thread should have initial ownership of the mutex, and a string that is the name of the mutex.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, an empty string. The name is case-sensitive. The backslash character (\) and slsh (/) are reserved.
      /// @exception xtd::io::io_xception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      mutex(bool initially_owned, const ustring& name);
      /// @brief Initializes a new instance of the xtd::threading::mutex class with a bool value that indicates whether the calling thread should have initial ownership of the mutex, a string that is the name of the mutex, and a bool value that, when the method returns, indicates whether the calling thread was granted initial ownership of the mutex.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      /// @param name The name, if the synchronization object is to be shared with other processes; otherwise, an empty string. The name is case-sensitive. The backslash character (\) and slsh (/) are reserved.
      /// @param created_new When this method returns, contains a bool that is true if a local mutex was created (that is, if name is empty string) or if the specified named system mutex was created; false if the specified named system mutex already existed.
      /// @exception xtd::io::io_xception name is invalid. This can be for various reasons, including some restrictions that may be placed by the operating system, such as an unknown prefix or invalid characters. Note that the name and common prefixes "Global\" and "Local\" are case-sensitive.<br>-or-<br>There was some other error. The HResult property may provide more information.
      mutex(bool initially_owned, const ustring& name, bool& created_new);
      /// @}

      /// @cond
      template <typename char_t>
      explicit mutex(const char_t* name) : mutex(ustring(name)) {}
      ~mutex();
      /// @endcond

      /// @name Properties
      
      /// @{
      intptr handle() const noexcept override;
      void handle(intptr value) override;

      /// @brief Returns the underlying implementation-defined native handle object.
      /// @return Implementation-defined native handle object.
      native_handle_type native_handle() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      void close() override;
      
      int32 compare_to(const mutex& value) const noexcept override;
      
      bool equals(const mutex& value) const noexcept override;
      
      /// @brief Locks the mutex. If another thread has already locked the mutex, a call to lock will block execution until the lock is acquired.
      /// @remarks If lock is called by a thread that already owns the mutex, the behavior is undefined: for example, the program may deadlock. An implementation that can detect the invalid usage is encouraged to throw a std::system_error with error condition resource_deadlock_would_occur instead of deadlocking.
      /// @remarks Prior unlock() operations on the same mutex synchronize-with (as defined in std::memory_order) this operation.
      /// @note xtd::threading::mutex::lock() is usually not called directly: std::unique_lock, std::scoped_lock, and std::lock_guard are used to manage exclusive locking.
      void lock();

      /// @brief Releases the Mutex once.
      /// @exception xtd::object_closed_exception the handle is invalid
      void release_mutex();
      
      /// @brief Tries to lock the mutex. Returns immediately. On successful lock acquisition returns true, otherwise returns false.
      /// @param timeout timeout A xtd::time_span that represents the number of milliseconds to wait, or a xtd::time_span that represents -1 milliseconds to wait indefinitely.
      /// @return true if the lock was acquired successfully, otherwise false.
      /// @remarks This function is allowed to fail spuriously and return false even if the mutex is not currently locked by any other thread.
      /// @remarks If try_lock is called by a thread that already owns the mutex, the behavior is undefined.
      /// @remarks Prior unlock() operation on the same mutex synchronizes-with (as defined in std::memory_order) this operation if it returns true. Note that prior lock() does not synchronize with this operation if it returns false.
      bool try_lock() noexcept;
      
      /// @brief Tries to lock the mutex. Blocks until specified timeout_duration has elapsed or the lock is acquired, whichever comes first. On successful lock acquisition returns true, otherwise returns false.
      /// @param timeout minimum duration to block for
      /// @return true if the lock was acquired successfully, otherwise false.
      /// @remarks If timeout_duration is less or equal timeout_duration.zero(), the function behaves like try_lock().
      /// @remarks This function may block for longer than timeout_duration due to scheduling or resource contention delays.
      /// @remarks The standard recommends that a steady_clock is used to measure the duration. If an implementation uses a system_clock instead, the wait time may also be sensitive to clock adjustments.
      /// @remarks As with try_lock(), this function is allowed to fail spuriously and return false even if the mutex was not locked by any other thread at some point during timeout_duration.
      /// @remarks Prior unlock() operation on the same mutex synchronizes-with (as defined in std::memory_order) this operation if it returns true.
      /// @remarks If try_lock_for is called by a thread that already owns the mutex, the behavior is undefined.
      bool try_lock_for(const time_span& timeout) noexcept;
      
      /// @brief Tries to lock the mutex. Blocks until specified timeout_time has been reached or the lock is acquired, whichever comes first. On successful lock acquisition returns true, otherwise returns false.
      /// @param timeout_time maximum time point to block until
      /// @return true if the lock was acquired successfully, otherwise false.
      /// @remarks If timeout_time has already passed, this function behaves like try_lock().
      /// @remarks Clock must meet the Clock requirements. The program is ill-formed if std::chrono::is_clock_v<Clock> is false (since C++20).
      /// @remarks The standard recommends that the clock tied to timeout_time be used, in which case adjustments of the clock may be taken into account. Thus, the duration of the block might be more or less than timeout_time - Clock::now() at the time of the call, depending on the direction of the adjustment and whether it is honored by the implementation. The function also may block until after timeout_time has been reached due to process scheduling or resource contention delays.
      /// @remarks As with try_lock(), this function is allowed to fail spuriously and return false even if the mutex was not locked by any other thread at some point before timeout_time.
      /// @remarks Prior unlock() operation on the same mutex synchronizes-with (as defined in std::memory_order) this operation if it returns true.
      /// @remarks If try_lock_until is called by a thread that already owns the mutex, the behavior is undefined.
      bool try_lock_until(const date_time& timeout_time) noexcept;

      /// @brief Unlocks the mutex.
      /// @remarks The mutex must be locked by the current thread of execution, otherwise, the behavior is undefined.
      /// @remarks This operation synchronizes-with (as defined in std::memory_order) any subsequent lock operation that obtains ownership of the same mutex.
      /// @remarks xtd::threading::mutex::unlock() is usually not called directly: std::unique_lock and std::lock_guard are used to manage exclusive locking.
      void unlock();
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief Opens an existing named mutex.
      /// @param name The name of a system-wide named mutex object.
      /// @return A xtd::threading::mutex object that represents a named system mutex.
      /// @exception xtd::argument_exception is a zero-length string <br>-or-<br> name is longer than 128 characters
      /// @exception xtd::io::io_exception An Io error occurred.
      static mutex open_existing(const ustring& name);
      
      /// @brief Opens the specified named mutex, if it already exists, and returns a value that indicates whether the operation succeeded.
      /// @param name The name of the synchronization object to be shared with other processes. The name is case-sensitive. The backslash character (\) and (/) are reserved.
      /// @param result When this method returns, contains a xtd::threading::mutex object that represents the named mutex if the call succeeded.
      /// @return true if the named mutex was opened successfully; otherwise, false. In some cases, false may be returned for invalid names.
      static bool try_open_existing(const ustring& name, mutex& result) noexcept;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      bool signal() override;

      bool wait(int32 milliseconds_timeout) override;
      /// @}

    private:
      friend class thread;
      void create(bool initially_owned, bool& created_new);
      std::shared_ptr<mutex_base> mutex_;
      ustring name_;
    };
  }
}
