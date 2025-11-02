/// @file
/// @brief Contains xtd::argument_out_of_range_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is out of range.
  /// @par Header
  /// ```cpp
  /// #include <xtd/argument_out_of_range_exception>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an xtd::argument_out_of_range_exception.
  /// @include argument_out_of_range_exception.cpp
  class argument_out_of_range_exception : public argument_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(default_message(), stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, error, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, help_link, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, error, help_link, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(default_message(), inner_exception, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, error, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, help_link, stack_frame) {}
    /// @brief Create a new instance of class xtd::argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit argument_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : argument_exception(message, inner_exception, error, help_link, stack_frame) {}
    /// @}
    
    /// @cond
    argument_out_of_range_exception(const argument_out_of_range_exception&) = default;
    argument_out_of_range_exception& operator =(const argument_out_of_range_exception&) = default;
    /// @endcond
    
    /// @name Public static Methods
    
    /// @{
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is equal to `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as not equal to `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_equal(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value == other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must not be equal to `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is less than `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as greater than or equal to `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_less_than(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value < other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be greater than or equal to `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is less than or equal to `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as greater than `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_less_than_or_equal(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value <= other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be greater than `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is greater than `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as less than or equal to `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_greater_than(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value > other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be less than or equal to `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is greater than or equal to `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as less than `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_greater_than_or_equal(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value >= other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be less than `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is negative.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-negative.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_negative(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value < static_cast<value_t>(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be a non-negative value. (Parameter '{1}')\nActual value was {0}.", value, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is negative or zero.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-zero or non-negative.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_negative_or_zero(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value <= static_cast<value_t>(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be a non-negative and non-zero value. (Parameter '{1}')\nActual value was {0}.", value, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is not equal to `other`.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as equal to `other`.
    /// @param other The value to compare with `value`.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_not_equal(const value_t& value, const value_t& other, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value != other) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be equal to `{1}`. (Parameter '{2}')\nActual value was {0}.", value, other, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is positive.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-positive.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_positive(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value > static_cast<value_t>(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be a non-positive value. (Parameter '{1}')\nActual value was {0}.", value, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is positive or zero.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-zero or non-positive.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_positive_or_zero(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value >= static_cast<value_t>(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be a non-positive and non-zero value. (Parameter '{1}')\nActual value was {0}.", value, param_name, stack_frame).c_str());}
    /// @brief Throws an xtd::argument_out_of_range_exception if `value` is zero.
    /// @tparam value_t The type of the object to validate.
    /// @param value The argument to validate as non-zero.
    /// @param param_name (optional) The name of the parameter with which `value` corresponds.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class value_t>
    inline static void throw_if_zero(const value_t& value, const xtd::string& param_name = xtd::string::empty_string, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) {if (value == static_cast<value_t>(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range, string::format("value ('{0}') must be a non-zero value. (Parameter '{1}')\nActual value was {0}.", value, param_name, stack_frame).c_str());}
    /// @}
    
  private:
    const char* default_message() const noexcept {return "Specified argument is out of range of valid values.";}
  };
}
