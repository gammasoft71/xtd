/// @file
/// @brief Contains xtd::argument_null_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.hpp"

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
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(default_message(), stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, error, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, help_link, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_null_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, error, help_link, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_null_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(default_message(), inner_exception, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, error, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, help_link, stack_frame) {}
    /// @brief Create a new instance of class argument_null_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_null_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, error, help_link, stack_frame) {}
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
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @exception xtd::argument_null_exception `argument` is null.
    template<class object_t>
    inline static void throw_if_null(const object_t* argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (!argument) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null, string::format("The value cannot benull. (Parameter '{}')", param_name, stack_frame).chars().c_str());}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::uptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @exception xtd::argument_null_exception `argument` is null.
    template<class object_t>
    inline static void throw_if_null(const std::optional<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (!argument) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null, string::format("The value cannot be null. (Parameter '{}')", param_name, stack_frame).chars().c_str());}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::sptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @exception xtd::argument_null_exception `argument` is null.
    template<class object_t>
    inline static void throw_if_null(const xtd::sptr<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (!argument) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null, string::format("The value cannot be null. (Parameter '{}')", param_name, stack_frame).chars().c_str());}
    /// @brief Throws an xtd::argument_null_exception if argument is null.
    /// @param argument The xtd::uptr type argument to validate as non-null.
    /// @param param_name (optional) The name of the parameter with which `argument` corresponds. If you omit this parameter, the name of `argument` is used.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @exception xtd::argument_null_exception `argument` is null.
    template<class object_t>
    inline static void throw_if_null(const xtd::uptr<object_t>& argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (!argument) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null, string::format("The value cannot be null. (Parameter '{}')", param_name, stack_frame).chars().c_str());}
    /// @cond
    static void throw_if_null(std::nullptr_t argument, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_null, string::format("The value cannot be null. (Parameter '{}')", param_name, stack_frame).chars().c_str());}
    /// @endcond
    /// @}
    
  private:
    const char* default_message() const noexcept {return "Value cannot be null.";}
  };
}
