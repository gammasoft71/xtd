/// @file
/// @brief Contains xtd::semaphore exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "semaphore_full_exception.h"
#include "wait_handle.h"
#include "../int32_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::semaphore, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Limits the number of threads that can access a resource or pool of resources concurrently.
    /// @par Header
    /// @code #include <xtd/threading/semaphore> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    /// @remarks Use the xtd::threading::semaphore class to control access to a pool of resources. Threads enter the semaphore by calling the xtd::threading::wait_handle::wait_one method, which is inherited from the xtd::threading::wait_handle class, and release the semaphore by calling the xtd::threading::semaphore=::release method.
    /// @remarks The count on a semaphore is decremented each time a thread enters the semaphore, and incremented when a thread releases the semaphore. When the count is zero, subsequent requests block until other threads release the semaphore. When all threads have released the semaphore, the count is at the maximum value specified when the semaphore was created.
    /// @remarks There is no guaranteed order, such as FIFO or LIFO, in which blocked threads enter the semaphore.
    /// @remarks A thread can enter the semaphore multiple times, by calling the xtd::threading::wait_handle::wait_one method repeatedly. To release some or all of these entries, the thread can call the parameterless xtd::threading::semaphore::release() method overload multiple times, or it can call the xtd::threading::semaphore::release(int32) method overload that specifies the number of entries to be released.
    /// @remarks The xtd::threading::semaphore class does not enforce thread identity on calls to xtd::threading::wait_handle::wait_one or xtd::threading::semaphore::release. It is the programmer's responsibility to ensure that threads do not release the semaphore too many times. For example, suppose a semaphore has a maximum count of two, and that thread A and thread B both enter the semaphore. If a programming error in thread B causes it to call xtd::threading::semaphore::release twice, both calls succeed. The count on the semaphore is full, and when thread A eventually calls xtd::threading::semaphore::release, a xtd::threading::semaphore_full_exception is thrown.
    /// @remarks Semaphores are of two types: local semaphores and named system semaphores. If you create a xtd::threading::semaphore object using a constructor that accepts a name, it is associated with an operating-system semaphore of that name. Named system semaphores are visible throughout the operating system, and can be used to synchronize the activities of processes. You can create multiple xtd::threading::semaphore objects that represent the same named system semaphore, and you can use the xtd::threading::semaphore::open_existing method to open an existing named system semaphore.
    /// @remarks A local semaphore exists only within your process. It can be used by any thread in your process that has a reference to the local xtd::threading::semaphore object. Each xtd::threading::semaphore object is a separate local semaphore.
    class semaphore : public wait_handle {
      class semaphore_base;
      class named_semaphore;
      class unnamed_semaphore;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the Semaphore class.
      /// @remarks initial count is set to 0 and maximum count is set to xtd::int32_object::max_value.
      semaphore();
      /// @brief Initializes a new instance of the Semaphore class, specifying the initial number of entries and the maximum number of concurrent entries.
      semaphore(int32 initial_count, int32 maximum_count);

      semaphore(int32 initial_count, int32 maximum_count, const ustring& name);

      semaphore(int32 initial_count, int32 maximum_count, const ustring& name, bool created_new);
      /// @}

      /// @cond
      ~semaphore();
      /// @endcond

      /// @name Properties
      
      /// @{
      intptr handle() const noexcept override;
      void handle(intptr value) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      void close() override;
      
      static semaphore open_existing(const ustring& name);

      int32 release();
      int32 release(int32 release_count);

      static bool try_open_existing(const ustring& name, semaphore& result) noexcept;
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      bool signal() override;

      bool wait(int32 milliseconds_timeout) override;
      /// @}

    private:
      void create(int32 initial_count, int32 maximum_count, bool& created_new);
      std::shared_ptr<semaphore_base> semaphore_;
      int32 count_ = 0;
      int32 maximum_count_ = int32_object::max_value;
      ustring name_;
    };
  }
}
