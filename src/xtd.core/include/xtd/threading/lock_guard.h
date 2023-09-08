/// @file
/// @brief Contains xtd::threading::lock_guard class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once

#include "../object.h"
#include "../using.h"
#include "monitor.h"

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
    /// The following example uses the xtd::threading::monitor class to synchronize access to a single instance of a random number generator represented by the xtd::random class. The example creates ten threads, each of which executes asynchronously on a thread pool thread. Each thread generates 10,000 random numbers, calculates their average, and updates two procedure-level variables that maintain a running total of the number of random numbers generated and their sum. After all threads have executed, these two values are then used to calculate the overall mean.
    /// @include lock_guard.cpp
    class core_export_ lock_guard final : public xtd::object {
    public:
      /// @name Constructors

      /// @{
      /// @brief Create a xtd::threaing::lock_guard object and acquires an exclusive lock on the specified obj.
      /// @param obj The object on which to acquire the monitor lock.
      /// @remarks When the xtd::threading::lock_guard destroyed it releases the exclusive lock specified in the constructor.
      template<typename object_t>
      explicit lock_guard(const object_t& lock) : lock_(xtd::threading::monitor::get_ptr(lock)) {xtd::threading::monitor::enter_ptr(lock_);}
      /// @}
      
      /// @cond
      ~lock_guard();
      /// @endcond

      /// @name Methods

      /// @{
      /// @brief Notifies a thread in the waiting queue of a change in the locked object's state.
      /// @remarks Only the current owner of the lock can signal a waiting object using Pulse.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal the next thread in line for the lock. Upon receiving the pulse, the waiting thread is moved to the ready queue. When the thread that invoked Pulse releases the lock, the next thread in the ready queue (which is not necessarily the thread that was pulsed) acquires the lock.
      void pulse();

      /// @brief Notifies all waiting threads of a change in the object's state.
      /// @remarks The thread that currently owns the lock on the specified object invokes this method to signal all threads waiting to acquire the lock on the object. After the signal is sent, the waiting threads are moved to the ready queue. When the thread that invoked PulseAll releases the lock, the next thread in the ready queue acquires the lock.
      /// @remarks Note that a synchronized object holds several references, including a reference to the thread that currently holds the lock, a reference to the ready queue, which contains the threads that are ready to obtain the lock, and a reference to the waiting queue, which contains the threads that are waiting for notification of a change in the object's state.
      /// @remarks The Pulse, PulseAll, and Wait methods must be invoked from within a synchronized block of code.
      /// @remarks The remarks for the Pulse method explain what happens if Pulse is called when no threads are waiting.
      /// @remarks To signal a single thread, use the Pulse method.
      void pulse_all();
      /// @}
      
    private:
      lock_guard() = delete;
      std::pair<xtd::intptr, bool> lock_;
    };
  }
}
