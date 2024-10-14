/// @file
/// @brief Contains xtd::threading::task_canceled_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../literals.h"
#include "../../operation_canceled_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::threading namespace provides classes and interfaces that enable multithreaded programming. In addition to classes for synchronizing thread activities and access to data ( xtd::threading::mutex, xtd::threading::monitor, xtd::threading::interlocked, xtd::threading::auto_reset_event, and so on), this namespace includes a xtd::threading::thread_pool class that allows you to use a pool of system-supplied threads, and a xtd::threading::timer class that executes callback methods on thread pool threads.
  namespace threading {
    /// @brief The xtd::threading::tasks namespace provides types that simplify the work of writing concurrent and asynchronous code. The main types are xtd::threading::tasks::task which represents an asynchronous operation that can be waited on and cancelled, and xtd::threading::tasks::task <result_t>, which is a task that can return a value. The xtd::threading::tasks::task_factory class provides static methods for creating and starting tasks, and the xtd::threading::tasks::task_scheduler class provides the default thread scheduling infrastructure.
    namespace tasks {
      /// @brief Represents an exception used to communicate task cancellation.
      /// ```cpp
      /// class task_canceled_exception : public xtd::operation_canceled_exception
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/threading/task_canceled_exception>
      /// ```
      /// @par Namespace
      /// xtd::threading
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core tasks exceptions
      class task_canceled_exception : public operation_canceled_exception {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of class task_canceled_exception
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        /// @remarks Message is set with the default message associate to the exception.
        explicit task_canceled_exception(const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(default_message(), stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, error, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, help_link, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        explicit task_canceled_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, error, help_link, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        /// @remarks Message is set with the default message associate to the exception.
        explicit task_canceled_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(default_message(), inner_exception, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, inner_exception, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, inner_exception, error, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, inner_exception, help_link, stack_frame) {}
        /// @brief Create a new instance of class task_canceled_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
        explicit task_canceled_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null) : operation_canceled_exception(message, inner_exception, error, help_link, stack_frame) {}
        /// @}
        
        /// @cond
        task_canceled_exception(const task_canceled_exception&) = default;
        task_canceled_exception& operator =(const task_canceled_exception&) = default;
        /// @endcond
        
      private:
        const char* default_message() const noexcept {return "A task was canceled."_t;}
      };
    }
  }
}
