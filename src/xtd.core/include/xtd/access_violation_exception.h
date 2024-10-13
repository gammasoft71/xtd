/// @file
/// @brief Contains xtd::access_violation_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "h_result.h"
#include "literals.h"
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
  /// The following example demonstrates how to throw and catch an access_violation_exception.
  /// @include access_violation_exception.cpp
  class access_violation_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class access_violation_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit access_violation_exception(const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit access_violation_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template<typename exception_t>
    access_violation_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : xtd::system_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::E_POINTER));}

    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
     access_violation_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class access_violation_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @deprecated Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
    [[deprecated("Use xtd::access_violation_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
    access_violation_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @}
    
    /// @cond
    access_violation_exception(const access_violation_exception&) = default;
    access_violation_exception& operator =(const access_violation_exception&) = default;
    /// @endcond
  };
}
