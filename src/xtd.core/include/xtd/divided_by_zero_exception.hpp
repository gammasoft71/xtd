/// @file
/// @brief Contains xtd::divided_by_zero_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "arithmetic_exception.hpp"
#include "literals.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when there is an attempt to divide an integral or decimal value by zero.
  /// @par Header
  /// ```cpp
  /// #include <xtd/divided_by_zero_exception>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an divided_by_zero_exception.
  /// @include divided_by_zero_exception.cpp
  class divided_by_zero_exception : public arithmetic_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit divided_by_zero_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(default_message(), stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, error, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, help_link, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit divided_by_zero_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, error, help_link, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit divided_by_zero_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(default_message(), inner_exception, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, inner_exception, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, inner_exception, error, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, inner_exception, help_link, stack_frame) {}
    /// @brief Create a new instance of class divided_by_zero_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit divided_by_zero_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : arithmetic_exception(message, inner_exception, error, help_link, stack_frame) {}
    /// @}
    
    /// @cond
    divided_by_zero_exception(const divided_by_zero_exception&) = default;
    divided_by_zero_exception& operator =(const divided_by_zero_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Attempt to divide by zero."_t;}
  };
}
