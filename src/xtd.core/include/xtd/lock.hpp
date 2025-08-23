/// @file
/// @brief Contains #lock_ keyword.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "threading/lock.hpp"

/// @brief The lock_ keyword marks a statement block as a critical section by obtaining the mutual-exclusion lock for a given object, executing a statement, and then releasing the lock. The following example includes a lock statement.
/// ```cpp
/// class account : public object {
/// public:
///   void withdraw(decimal amount) {
///     lock_ (balance) {
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
/// @remarks The lock_ keyword ensures that one thread does not enter a critical section of code while another thread is in the critical section. If another thread tries to enter a locked code, it will wait, block, until the object is released.
/// @remarks The section Threading discusses threading.
/// @remarks The lock_ keyword calls Enter at the start of the block and Exit at the end of the block. A xtd::threading::thread_interrupted_exception is thrown if xtd::threading::thread::interrupt interrupts a thread that is waiting to enter a lock statement.
/// @remarks In general, avoid locking on a public type, or instances beyond your code's control. The common constructs lock_ (*this), lock_ (typeof_<my_type>()), and lock_ ("myLock") violate this guideline:
/// * lock_ (*this) is a problem if the instance can be accessed publicly.
/// * lock_ (typeof_<my_type>()) is a problem if my_type is publicly accessible.
/// * lock_ ("my_lock") is a problem because any other code in the process using the same string, will share the same lock.
/// @remarks Best practice is to define a private object to lock on, or a private static object variable to protect data common to all instances.
/// @remarks You can't use the await_ keyword in the body of a lock_ statement.
/// @par Examples
/// The following sample shows a simple use of threads without locking in C++.
/// ```cpp
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
/// ```
/// @par Examples
/// The following sample uses threads and lock_. As long as the lock statement is present, the statement block is a critical section and balance will never become a negative number.
/// @include lock_keyword.cpp
/// @ingroup Keywords
#define lock_(object)\
  block_scope_(xtd::threading::lock __xtd_lock__(object))
