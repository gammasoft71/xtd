/// @file
/// @brief Contains xtd::argument_null_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.h"
#include "literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is null.
  /// @par Header
  /// ```cpp
  /// #include <xtd/argument_null_exception>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an argument_null_exception.
  /// @include argument_null_exception.cpp
  class argument_null_exception : public argument_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class argument_null_exception
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const xtd::diagnostics::stack_frame& info = null) : argument_exception(default_message(), info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, error, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_null_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : argument_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null) : argument_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    argument_null_exception(const argument_null_exception&) = default;
    argument_null_exception& operator =(const argument_null_exception&) = default;
    /// @endcond
    
    /// @name Public static Methods
    
    /// @{
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The pointer type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_null_exception `argument` is null.
    template<typename object_t>
    static void throw_if_null(const object_t* argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (!argument) throw argument_null_exception {string::format("The value cannot benull. (Parameter '{}')", param_name, info)};}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::uptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_null_exception `argument` is null.
    template<typename object_t>
    static void throw_if_null(const std::optional<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (!argument) throw argument_null_exception {string::format("The value cannot be null. (Parameter '{}')", param_name, info)};}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::sptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_null_exception `argument` is null.
    template<typename object_t>
    static void throw_if_null(const xtd::sptr<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (!argument) throw argument_null_exception {string::format("The value cannot be null. (Parameter '{}')", param_name, info)};}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::uptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @exception xtd::argument_null_exception `argument` is null.
    template<typename object_t>
    static void throw_if_null(const xtd::uptr<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {if (!argument) throw argument_null_exception {string::format("The value cannot be null. (Parameter '{}')", param_name, info)};}
    /// @cond
    static void throw_if_null(std::nullptr_t argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& info = null) {throw argument_null_exception {string::format("The value cannot be null. (Parameter '{}')", param_name, info)};}
    /// @endcond
    /// @}

  private:
    const char* default_message() const noexcept {return "Value cannot be null."_t;}
  };
}
