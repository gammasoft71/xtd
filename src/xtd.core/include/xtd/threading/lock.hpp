/// @file
/// @brief Contains xtd::threading::lock class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../block_scope.hpp"
#include "../object.hpp"
#include "../ptr.hpp"
#include "../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides a mechanism that synchronizes access to objects with xtd::threading::mutex.
    /// ```cpp
    /// class core_export_ lock final : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::lock
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/lock>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example uses the xtd::threading::lock class to synchronize access to a single instance of a random number generator represented by the xtd::random class. The example creates ten threads, each of which executes asynchronously on a thread pool thread. Each thread generates 10,000 random numbers, calculates their average, and updates two procedure-level variables that maintain a running total of the number of random numbers generated and their sum. After all threads have executed, these two values are then used to calculate the overall mean.
    /// @include lock.cpp
    /// @remarks See xtd::threading::mutex for more information.
    class core_export_ lock final : public object {
    public:
      struct data;

      /// @name Public Constructors
      
      /// @{
      /// @brief Create a xtd::threading::lock object and acquires an exclusive lock on the specified obj.
      /// @param obj The object on which to acquire the mutex lock.
      /// @remarks When the xtd::threading::lock destroyed it releases the exclusive lock specified in the constructor.
      template<class object_t>
      explicit lock(const object_t& obj) : lock {reinterpret_cast<xtd::intptr>(&obj)} {}

      /// @brief Create a xtd::threading::lock object and acquires an exclusive lock on the specified string.
      /// @param str The string on which to acquire the mutex lock.
      /// @remarks When the xtd::threading::lock destroyed it releases the exclusive lock specified in the constructor.
      explicit lock(const xtd::string& str);
      /// @}
      
      /// @cond
      explicit lock(xtd::intptr ptr);
      explicit lock(const std::string& str);
      explicit lock(const char* str);
      explicit lock(const xtd::char16* str);
      explicit lock(const xtd::char32* str);
      explicit lock(const xtd::char8* str);
      explicit lock(const xtd::wchar* str);
      ~lock();
      /// @endcond
      
      /// @name Public Methods
      
      /// @{
      /// @brief Enters the lock, waiting if necessary until the lock can be entered.
      /// @exception xtd::threading::lock_recursion_exception The lock has reached the limit of repeated entries by the current thread. The limit is implementation-defined and is intended to be high enough that it would not be reached in normal situations.
      /// @remarks When the method returns, the current thread is the only thread that holds the lock. If the lock can't be entered immediately, the method waits until the lock can be entered. If the lock is already held by the current thread, the lock is entered again. To fully exit the lock and allow other threads to enter the lock, the current thread should exit the lock as many times as it has entered the lock.
      void enter();

      /// @brief Exits the lock.
      /// @exception xtd::object_closed_exception the handle is invalid
      /// @remarks If the current thread holds the lock multiple times, such as recursively, the lock is exited only once. The current thread should ensure that each enter is matched with an exit.
      void exit();
      /// @}
      
    private:
      lock() = delete;
      xtd::ptr<data> data_;
    };
  }
}

#include "../lock.hpp"
