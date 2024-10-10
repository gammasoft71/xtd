/// @file
/// @brief Contains xtd::argument_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is not valid.
  /// @par Header
  /// ```cpp
  /// #include <xtd/argument_exception>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an argument_exception.
  /// @include argument_exception.cpp
  /// @todo add param_name property and constructors param (param_name is the parameter that cause the exception).
  class argument_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class argument_exception
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_exception(const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, help_link, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class argument_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : system_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    argument_exception(const argument_exception&) = default;
    argument_exception& operator =(const argument_exception&) = default;
    /// @endcond
    
    /// @name Public static Methods
    
    /// @{
    /// @brief Throws an exception if `argument` is empty.
    /// @param argument The string argument to validate as non-empty.
    /// @param param_name (optional) The name of the parameter with which argument corresponds.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_exception `argument` is empty.
    static void throw_if_empty(const xtd::string& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (xtd::string::is_empty(argument)) throw argument_exception {string::format("The value cannot be an empty string. (Parameter '{}')", param_name, info)};}
    /// @brief Throws an exception if argument is empty, or consists only of white-space characters.
    /// @param argument The string argument to validate.
    /// @param param_name (optional) The name of the parameter with which argument corresponds.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_exception `argument` is empty or consists only of white-space characters.
    static void throw_if_empty_or_white_space(const xtd::string& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (xtd::string::is_empty(argument.replace(" ", ""))) throw argument_exception {string::format("The value cannot be an empty string or composed entirely of whitespace. (Parameter '{}')", param_name, info)};}
    /// @}

  private:
    const char* default_message() const noexcept {return "Value does not fall within the expected range."_t;}
  };
}
