/// @file
/// @brief Contains xtd::invalid_cast_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "literals.h"
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown for invalid casting or explicit conversion.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @par Examples
  /// The following example demonstrates how to throw and catch an invalid_cast_exception.
  /// @include invalid_cast_exception.cpp
  class invalid_cast_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit invalid_cast_exception(const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(default_message(), stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, error, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, help_link, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit invalid_cast_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, error, help_link, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit invalid_cast_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(default_message(), inner_exception, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, error, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, help_link, stack_frame) {}
    /// @brief Create a new instance of class invalid_cast_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit invalid_cast_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : system_exception(message, inner_exception, error, help_link, stack_frame) {}
    /// @}
    
    /// @cond
    invalid_cast_exception(const invalid_cast_exception&) = default;
    invalid_cast_exception& operator =(const invalid_cast_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "Specified cast is not valid."_t;}
  };
}
