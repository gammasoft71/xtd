/// @file
/// @brief Contains xtd::format_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "literals.h"
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an format_exception.
  /// @include format_exception.cpp
  class format_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class format_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit format_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(default_message(), stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, error, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, help_link, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit format_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, error, help_link, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit format_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(default_message(), inner_exception, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, error, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, help_link, stack_frame) {}
    /// @brief Create a new instance of class format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, error, help_link, stack_frame) {}
    /// @}
    
    /// @cond
    format_exception(const format_exception&) = default;
    format_exception& operator =(const format_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "One of identified items is an invalid format."_t;}
  };
}
