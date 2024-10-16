/// @file
/// @brief Contains xtd::net::cookie_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../format_exception.h"
#include "../literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The exception that is thrown when an error is made adding a xtd::net::cookie to a xtd::net::cookie_container.
    /// @par Header
    /// ```cpp
    /// #include <xtd/net/cookie_exception>
    /// ```
    /// @par Namespace
    /// xtd::net
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an cookie_exception.
    /// @include cookie_exception.cpp
    class cookie_exception : public format_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class cookie_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit cookie_exception(const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(default_message(), stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, error, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, help_link, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit cookie_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, error, help_link, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit cookie_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(default_message(), inner_exception, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, inner_exception, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, inner_exception, error, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, inner_exception, help_link, stack_frame) {}
      /// @brief Create a new instance of class cookie_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit cookie_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = csf_) : format_exception(message, inner_exception, error, help_link, stack_frame) {}
      /// @}
      
      /// @cond
      cookie_exception(const cookie_exception&) = default;
      cookie_exception& operator =(const cookie_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "One of identified items is an invalid format."_t;}
    };
  }
}
