/// @file
/// @brief Contains xtd::mutex exception.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "wait_handle.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief A synchronization primitive that can also be used for interprocess synchronization.
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
      /// @exception xtd::io::io_xception An Io error occurred.
      mutex();
      /// @brief Initializes a new instance of the xtd::threading::mutex with a bool value that indicates whether the calling thread should have initial ownership of the mutex.
      /// @param initially_owned true to give the calling thread initial ownership of the named system mutex if the named system mutex is created as a result of this call; otherwise, false.
      /// @exception xtd::io::io_xception An Io error occurred.
      mutex(bool initially_owned);

      mutex(bool initially_owned, const ustring& name);

      mutex(bool initially_owned, const ustring& name, bool created_new);
      /// @}

      /// @cond
      ~mutex();
      /// @endcond

      /// @name Properties
      
      /// @{
      intptr_t handle() const noexcept override;
      void handle(intptr_t value) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      void close() override;
      
      /// @brief Opens an existing named mutex.
      /// @param name The name of a system-wide named mutex object.
      /// @return A xtd::threading::mutex object that represents a named system mutex.
      /// @exception xtd::argument_exception is a zero-length string <br>-or-<br> name is longer than 128 characters
      /// @exception xtd::io::io_Exception An Io error occurred.
      static mutex open_existing(const ustring& name);

      void release_mutex();
      
      static bool try_open_existing(const ustring& name, mutex& result);
      /// @}

    protected:
      /// @name Protected methods
      
      /// @{
      bool signal() override;

      bool wait(int32_t milliseconds_timeout) override;
      /// @}

    private:
      void create(bool initially_owned, bool& created_new);
      std::shared_ptr<mutex_base> mutex_;
      ustring name_;
    };
  }
}
