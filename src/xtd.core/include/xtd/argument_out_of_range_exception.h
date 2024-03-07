/// @file
/// @brief Contains xtd::argument_out_of_range_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "argument_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when one of the arguments provided to a method is out of range.
  /// @par Header
  /// @code #include <xtd/argument_out_of_range_exception> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an argument_out_of_range_exception.
  /// @include argument_out_of_range_exception.cpp
  class argument_out_of_range_exception : public argument_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, help_link, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit argument_out_of_range_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class argument_out_of_range_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit argument_out_of_range_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : argument_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    argument_out_of_range_exception(const argument_out_of_range_exception&) = default;
    argument_out_of_range_exception& operator =(const argument_out_of_range_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Specified argument is out of range of valid values."_t;}
  };
}

/// @brief Helper on xtd::argument_out_of_range_exception to call it with current stack frame information.
/// @par Header
/// @code #include <xtd/argument_out_of_range_exception> @endcode
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::argument_out_of_range_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw argument_out_of_range_exception_(); // same as : throw argument_out_of_range_exception {csf_};
///   if (invalid_value) throw argument_out_of_range_exception_("Bad value"); // same as : throw argument_out_of_range_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define argument_out_of_range_exception_(...) argument_out_of_range_exception(add_csf_(__VA_ARGS__))
