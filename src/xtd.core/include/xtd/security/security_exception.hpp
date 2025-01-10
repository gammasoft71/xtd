/// @file
/// @brief Contains xtd::security::security_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../literals.hpp"
#include "../system_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the underlying structure of the security system, including base classes for permissions.
  namespace security {
    /// @brief The exception that is thrown when an I/O error occurs.
    /// @par Header
    /// ```cpp
    /// #include <xtd/security/security_exception>
    /// ```
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
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class security_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit security_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit security_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class security_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      template<class exception_t>
      security_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::system_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_SECURITY));}
      /// @}
      
      /// @cond
      security_exception(const security_exception&) = default;
      security_exception& operator =(const security_exception&) = default;
      /// @endcond
    };
  }
}
