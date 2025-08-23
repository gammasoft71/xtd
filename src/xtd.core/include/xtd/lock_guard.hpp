/// @file
/// @brief Contains #lock_guard_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "threading/lock_guard.hpp"

/// @brief The lock_guard_ keyword marks a statement block_guard as a critical section by obtaining the mutual-exclusion lock_guard for a given object, executing a statement, and then releasing the lock_guard. The following example includes a lock_guard statement.
/// ```cpp
/// class account : public object {
/// public:
///   void withdraw(decimal amount) {
///     lock_guard_ (balance) {
///       if (amount > balance)
///         throw exception("Insufficient funds");
///       balance -= amount;
///     }
///   }
///
/// private:
///   decimal balance;
/// };
/// ```
/// For more information, see Thread Synchronization.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks The lock_guard_ keyword ensures that one thread does not enter a critical section of code while another thread is in the critical section. If another thread tries to enter a lock_guarded code, it will wait, block_guard, until the object is released.
/// @remarks The section Threading discusses threading.
/// @remarks The lock_guard_ keyword calls Enter at the start of the block_guard and Exit at the end of the block_guard. A xtd::threading::thread_interrupted_exception is thrown if xtd::threading::thread::interrupt interrupts a thread that is waiting to enter a lock_guard statement.
/// @remarks In general, avoid lock_guarding on a public type, or instances beyond your code's control. The common constructs lock_guard_ (*this), lock_guard_ (typeof_<my_type>()), and lock_guard_ ("myLock") violate this guideline:
/// * lock_guard_ (*this) is a problem if the instance can be accessed publicly.
/// * lock_guard_ (typeof_<my_type>()) is a problem if my_type is publicly accessible.
/// * lock_guard_ ("my_lock_guard") is a problem because any other code in the process using the same string, will share the same lock_guard.
/// @remarks Best practice is to define a private object to lock_guard on, or a private static object variable to protect data common to all instances.
/// @remarks You can't use the await_ keyword in the body of a lock_guard_ statement.
/// @par Examples
/// The following sample shows a simple use of threads without lock_guarding in C++.
/// ```cpp
/// #include <xtd/xtd>
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
/// ```
/// @par Examples
/// The following sample uses threads and lock_guard_. As long as the lock_guard statement is present, the statement block_guard is a critical section and balance will never become a negative number.
/// @include lock_guard_keyword.cpp
/// @ingroup Keywords
#define lock_guard_(object)\
  block_scope_(xtd::threading::lock_guard __xtd_lock_guard__(object))
