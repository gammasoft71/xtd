/// @file
/// @brief Contains xtd::time_zone_not_found_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when the time allotted for a process or operation has expired.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an time_zone_not_found_exception.
  /// @include time_zone_not_found_exception.cpp
  class time_zone_not_found_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit time_zone_not_found_exception(const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, help_link, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit time_zone_not_found_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class time_zone_not_found_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit time_zone_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    time_zone_not_found_exception(const time_zone_not_found_exception&) = default;
    time_zone_not_found_exception& operator =(const time_zone_not_found_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "The time zone cannot be found."_t;}
  };
}
