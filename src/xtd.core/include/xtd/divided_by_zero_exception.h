/// @file
/// @brief Contains xtd::divided_by_zero_exception exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "arithmetic_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when there is an attempt to divide an integral or decimal value by zero.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an divided_by_zero_exception.
  /// @include divided_by_zero_exception.cpp
  class divided_by_zero_exception : public arithmetic_exception {
  public:
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    divided_by_zero_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(default_message(), info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, error, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, help_link, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit divided_by_zero_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    divided_by_zero_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit divided_by_zero_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : arithmetic_exception(message, inner_exception, error, help_link, info) {}

    /// @cond
    divided_by_zero_exception(const divided_by_zero_exception&) = default;
    divided_by_zero_exception& operator=(const divided_by_zero_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const {return "Attempt to divide by zero."_t;}
  };
}
