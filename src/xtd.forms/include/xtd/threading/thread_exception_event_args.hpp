/// @file
/// @brief Contains xtd::forms::thread_exception_event_args event args.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.hpp"
#include <xtd/exception>
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief Provides data for the xtd::forms::application::thread_exception event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/thread_exception_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks A xtd::forms::thread_exception_event_args is created by a thread when an unhandled exception occurs. xtd::forms::thread_exception_event_args contains the xtd::exception that occurred.
    class forms_export_ thread_exception_event_args : public event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::thread_exception_event_args class.
      /// @param exception The std::exception that occurred.
      thread_exception_event_args(const std::exception& exception);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the std::exception that occurred.
      /// @return The std::exception that occurred.
      const std::exception& exception() const noexcept;
      /// @}
      
    private:
      const std::exception* exception_ = nullptr;
    };
  }
}
