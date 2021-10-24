/// @file
/// @brief Contains xtd::security::security_exception exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the underlying structure of the common language runtime security system, including base classes for permissions.
  namespace security {
    /// @brief The exception that is thrown when an I/O error occurs.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an security_exception.
    /// @include security_exception.cpp
    class security_exception : public system_exception {
    public:
      /// @brief Create a new instance of class security_exception
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      security_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, help_link, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit security_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      security_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit security_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : system_exception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      security_exception(const security_exception&) = default;
      security_exception& operator=(const security_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const {return "Security error detected."_t;}
    };
  }
}
