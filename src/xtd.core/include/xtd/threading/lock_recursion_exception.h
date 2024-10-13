/// @file
/// @brief Contains xtd::threading::lock_recursion_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../literals.h"
#include "../system_exception.h"
#include "../typeof.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The exception that is thrown when a Thread is in an invalid ThreadState for the method call.
    /// ```cpp
    /// class lock_recursion_exception : public xtd::system_exception
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/lock_recursion_exception>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an lock_recursion_exception.
    /// @include lock_recursion_exception.cpp
    class lock_recursion_exception : public system_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit lock_recursion_exception(const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, help_link, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit lock_recursion_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit lock_recursion_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class lock_recursion_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit lock_recursion_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, help_link, info) {}
      /// @}
      
      /// @cond
      lock_recursion_exception(const lock_recursion_exception&) = default;
      lock_recursion_exception& operator =(const lock_recursion_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "Exception of type 'xtd::threading::lock_recursion_exception' was thrown.";}
    };
  }
}
