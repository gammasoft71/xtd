/// @file
/// @brief Contains xtd::threading::lock_guard class.
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
    /// class core_export_ lock_guard final : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::lock_guard
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/lock_guard>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @par Examples
    /// The following example uses the xtd::threading::lock_guard class to synchronize access to a single instance of a random number generator represented by the xtd::random class. The example creates ten threads, each of which executes asynchronously on a thread pool thread. Each thread generates 10,000 random numbers, calculates their average, and updates two procedure-level variables that maintain a running total of the number of random numbers generated and their sum. After all threads have executed, these two values are then used to calculate the overall mean.
    /// @include lock_guard.cpp
    /// @remarks See xtd::threading::mutex for more information.
    class core_export_ lock_guard final : public object {
    public:
      struct data;
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a xtd::threading::lock_guard object and acquires an exclusive lock_guard on the specified obj.
      /// @param obj The object on which to acquire the mutex lock_guard.
      /// @remarks When the xtd::threading::lock_guard destroyed it releases the exclusive lock_guard specified in the constructor.
      template<class object_t>
      explicit lock_guard(const object_t& obj) : lock_guard {reinterpret_cast<xtd::intptr>(&obj)} {}
      
      /// @brief Create a xtd::threading::lock_guard object and acquires an exclusive lock_guard on the specified string.
      /// @param str The string on which to acquire the mutex lock_guard.
      /// @remarks When the xtd::threading::lock_guard destroyed it releases the exclusive lock_guard specified in the constructor.
      explicit lock_guard(const xtd::string& str);
      /// @}
      
      /// @cond
      explicit lock_guard(xtd::intptr ptr);
      explicit lock_guard(const std::string& str);
      explicit lock_guard(const char* str);
      explicit lock_guard(const xtd::char16* str);
      explicit lock_guard(const xtd::char32* str);
      explicit lock_guard(const xtd::char8* str);
      explicit lock_guard(const xtd::wchar* str);
      ~lock_guard();
      /// @endcond
      
      /// @name Public Methods
      
      /// @{
      /// @brief Enters the lock_guard, waiting if necessary until the lock_guard can be entered.
      /// @remarks When the method returns, the current thread is the only thread that holds the lock_guard. If the lock_guard can't be entered immediately, the method waits until the lock_guard can be entered. If the lock_guard is already held by the current thread, the lock_guard is entered again. To fully exit the lock_guard and allow other threads to enter the lock_guard, the current thread should exit the lock_guard as many times as it has entered the lock_guard.
      void enter();
      
      /// @brief Exits the lock_guard.
      /// @exception xtd::object_closed_exception the handle is invalid
      /// @remarks If the current thread holds the lock_guard multiple times, such as recursively, the lock_guard is exited only once. The current thread should ensure that each enter is matched with an exit.
      void exit();
      /// @}
      
    private:
      lock_guard() = delete;
      xtd::ptr<data> data_;
    };
  }
}

#include "../lock_guard.hpp"
