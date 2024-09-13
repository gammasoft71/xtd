/// @file
/// @brief Contains xtd::tunit::abort_error exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Exception thow when abort.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit exceptions
    class abort_error : public xtd::exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class abort_error
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      abort_error(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(default_message(), info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, error, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, help_link, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit abort_error(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit abort_error(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class abort_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit abort_error(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : exception(message, inner_exception, error, help_link, info) {}
      /// @}
      
      /// @cond
      abort_error(const abort_error&) = default;
      abort_error& operator =(const abort_error&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "Abort error."_t;}
    };
  }
}
