/// @file
/// @brief Contains xtd::semaphore exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "wait_handle.h"
#include "../int32_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::semaphore, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief A synchronization primitive that can also be used for interprocess synchronization.
    /// @par Header
    /// @code #include <xtd/threading/semaphore> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    class semaphore : public wait_handle {
      class semaphore_base;
      class named_semaphore;
      class unnamed_semaphore;
    public:
      /// @name Constructors
      
      /// @{
      semaphore();

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

      void release();
      
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
      ustring name_;
    };
  }
}
