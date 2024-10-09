/// @file
/// @brief Contains xtd::interrupt_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when a method call is invalid for the object's current state.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an interrupt_exception.
  /// @include interrupt_exception.cpp
  class interrupt_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class interrupt_exception
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit interrupt_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, help_link, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit interrupt_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit interrupt_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class interrupt_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit interrupt_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    interrupt_exception(const interrupt_exception&) = default;
    interrupt_exception& operator =(const interrupt_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "An interruption occured."_t;}
  };
}
