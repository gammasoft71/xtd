/// @file
/// @brief Contains xtd::mutex exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "wait_handle.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming.
  /// In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Encapsulates operating system specific objects that wait for exclusive access to shared resources.
    /// @par Header
    /// @code #include <xtd/threading/mutex> @endcode
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core threading
    class mutex : public wait_handle {
      class mutex_base;
      class named_mutex;
      class unnamed_mutex;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::threading::mutex class.
      mutex();
      /// @}
      
      /// @name Properties
      
      /// @{
      intptr_t handle() const noexcept override;
      void handle(intptr_t value) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      void close() override;
      
      mutex open_existing(const ustring& name);
      
    protected:
      bool signal() override;

      bool wait(int32_t milliseconds_timeout) override;
      /// @}

    private:
      std::shared_ptr<mutex_base> mutex_;
    };
  }
}
