/// @file
/// @brief Contains xtd::system_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when a method call is invalid for the object's current state.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an system_exception.
  /// @include system_exception.cpp
  class system_exception : public exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class system_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit system_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template<typename exception_t>
    system_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_SYSTEM));}
    
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
    explicit system_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::system_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
    explicit system_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @}
    
    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator =(const system_exception&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets file path where exception occurred
    /// @return A string represent file path where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_file_name - Will be removed in version 0.4.0.
    [[deprecated("Replaced by xtd::exception::get_last_stack_frame().get_file_name - Will be removed in version 0.4.0.")]]
    virtual const xtd::string& file_path() const noexcept;
    
    /// @brief Gets Line number where the exception occurred
    /// @return the line number where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_file_line_number - Will be removed in version 0.4.0.
    [[deprecated("Replaced by xtd::exception::get_last_stack_frame().get_file_line_number - Will be removed in version 0.4.0.")]]
    virtual xtd::size line_number() const noexcept;
    
    /// @brief Gets file member where exception occurred
    /// @return A string represent member name where exception occurred
    /// @deprecated Replaced by xtd::exception::get_last_stack_frame().get_method - Will be removed in version 0.4.0.
    [[deprecated("Replaced by xtd::exception::get_last_stack_frame().get_method - Will be removed in version 0.4.0.")]]
    virtual const xtd::string& member_name() const noexcept;
    
    /// @brief Gets full class name the exception
    /// @return A string represent a full class name of the exception
    /// @deprecated Replaced by xtd::exception::get_type().full_name() - Will be removed in version 0.4.0.
    [[deprecated("Replaced by xtd::exception::get_type().full_name() - Will be removed in version 0.4.0.")]]
    virtual const xtd::string& name() const noexcept;
  /// @}
  };
}
