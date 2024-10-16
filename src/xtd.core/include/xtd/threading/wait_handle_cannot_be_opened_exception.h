/// @file
/// @brief Contains xtd::threading::wait_handle_cannot_be_opened_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../literals.h"
#include "../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The exception that is thrown when a Thread is in an invalid ThreadState for the method call.
    /// ```cpp
    /// class wait_handle_cannot_be_opened_exception : public xtd::system_exception
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/threading/wait_handle_cannot_be_opened_exception>
    /// ```
    /// @par Namespace
    /// xtd::threading
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an wait_handle_cannot_be_opened_exception.
    /// @include wait_handle_cannot_be_opened_exception.cpp
    class wait_handle_cannot_be_opened_exception : public system_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit wait_handle_cannot_be_opened_exception(const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(default_message(), stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, error, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, help_link, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, error, help_link, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit wait_handle_cannot_be_opened_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(default_message(), inner_exception, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, error, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, help_link, stack_frame) {}
      /// @brief Create a new instance of class wait_handle_cannot_be_opened_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit wait_handle_cannot_be_opened_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, error, help_link, stack_frame) {}
      /// @}
      
      /// @cond
      wait_handle_cannot_be_opened_exception(const wait_handle_cannot_be_opened_exception&) = default;
      wait_handle_cannot_be_opened_exception& operator =(const wait_handle_cannot_be_opened_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "No handle of the given name exists."_t;}
    };
  }
}
