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
        explicit socket_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception with the specified error code.
        /// @param error_code The error code that indicates the error that occurred.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(int32 error_code, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception with the specified error code and message.
        /// @param error_code The error code that indicates the error that occurred.
        /// @param message The error code that indicates the error that occurred.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(int32 error_code, const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception with the specified socket error.
        /// @param socket_error The sockect error that indicates the error that occurred.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(xtd::net::sockets::socket_error socket_error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception with the specified socket error and message.
        /// @param socket_error The socket error that indicates the error that occurred.
        /// @param message The error code that indicates the error that occurred.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        explicit socket_exception(xtd::net::sockets::socket_error socket_error, const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());

        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @remarks Message is set with the default message associate to the exception.
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
        socket_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @brief Create a new instance of class socket_exception
        /// @param message Message string associate to the exception.
        /// @param inner_exception The exception that is the cause of the current exception.
        /// @param error Error code associate to the exception.
        /// @param help_link Help link string associate to the exception.
        /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
        /// @deprecated Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
        [[deprecated("Use xtd::socket_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
        socket_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
        /// @}
        
        /// @cond
        socket_exception(const socket_exception&) = default;
        socket_exception& operator =(const socket_exception&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the error code that is associated with this exception.
        /// @return An integer error code that is associated with this exception.
        /// @remarks The xtd::net::sockets::socket_exception::error property contains the error code that is associated with the error that caused the exception.
        /// @remarks The parameterless constructor for xtd::net::sockets::socket_exception sets the xtd::net::sockets::socket_exception::socket_error_code property to the last operating system error that occurred. For more information about socket error codes, see the [Windows Sockets version 2 API error code](https://learn.microsoft.com/en-us/windows/desktop/winsock/windows-sockets-error-codes-2) documentation.
        int32 socket_error_code() const noexcept;
        /// @brief Gets the socket error that is associated with this exception.
        /// @return A socket error that is associated with this exception.
        /// @remarks The xtd::net::sockets::socket_exception::socket_error_code property contains the error code that is associated with the error that caused the exception.
        /// @remarks The parameterless constructor for xtd::net::sockets::socket_exception sets the xtd::net::sockets::socket_exception::socket_error_code property to the last operating system error that occurred. For more information about socket error codes, see the [Windows Sockets version 2 API error code](https://learn.microsoft.com/en-us/windows/desktop/winsock/windows-sockets-error-codes-2) documentation.
        virtual xtd::net::sockets::socket_error socket_error() const noexcept;
        /// @}
        
      private:
        xtd::net::sockets::socket_error socket_error_ = xtd::net::sockets::socket_error::success;
      };
    }
  }
}
