/// @file
/// @brief Contains xtd::net::sockets::socket_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "socket_error.h"
#include "../../literals.h"
#include "../../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::net namespace provides a simple programming interface for many of the protocols used on networks today. The xtd::net::web_request and xtd::net::web_response classes form the basis of what are called pluggable protocols, an implementation of network services that enables you to develop applications that use Internet resources without worrying about the specific details of the individual protocols.
  namespace net {
    /// @brief The xtd::net::sockets namespace provides a managed implementation of the Berkeley Sockets interface for developers who need to tightly control access to the network.
    namespace sockets {
      /// @brief The exception that is thrown when a socket error occurs.
      /// ```cpp
      /// class socket_exception : public xtd::system_exception
      /// ```
      /// @par Inheritance
      /// xtd::system_exception → xtd::net::sockets::socket_exception
      /// @par Header
      /// ```cpp
      /// #include <xtd/net/sockets/socket_exception>
      /// ```
      /// @par Namespace
      /// xtd::net::sockets
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core exceptions
      /// @par Examples
      /// The following example demonstrates how to throw and catch an socket_exception.
      /// @include socket_exception.cpp
      class socket_exception : public xtd::system_exception {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Create a new instance of class socket_exception
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @remarks Message is set with the default message associate to the exception.
        explicit socket_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(default_message(), stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, error, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, help_link, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        explicit socket_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, error, help_link, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @remarks Message is set with the default message associate to the exception.
        explicit socket_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(default_message(), inner_exception, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, error, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, help_link, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(message, inner_exception, error, help_link, stack_frame) {}
        /// @brief Create a new instance of class socket_exception
        /// @param error One of xtd::net::sockets::socket_error values .
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(const xtd::net::sockets::socket_error& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : system_exception(default_message(), std::error_code(static_cast<int32>(error), std::system_category()), stack_frame) {}
        /// @}
        
        /// @cond
        socket_exception(const socket_exception&) = default;
        socket_exception& operator =(const socket_exception&) = default;
        /// @endcond
        
      private:
        const char* default_message() const noexcept {return "The Socket operation failed."_t;}
      };
    }
  }
}
