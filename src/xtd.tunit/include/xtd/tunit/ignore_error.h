/// @file
/// @brief Contains xtd::tunit::ignore_error exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/exception>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Exception to be thrown when something is ignored.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit exceptions
    class ignore_error : public xtd::exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class ignore_error
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      ignore_error(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(default_message(), stack_frame) {}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {error_code(error);}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {this->help_link(help_link);}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {
        error_code(error);
        this->help_link(help_link);
      }
      /// @brief Create a new instance of class ignore_error
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit ignore_error(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(default_message(), stack_frame) {}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {error_code(error);}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {this->help_link(help_link);}
      /// @brief Create a new instance of class ignore_error
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit ignore_error(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::empty()) : exception(message, stack_frame) {
        error_code(error);
        this->help_link(help_link);
      }
      /// @}
      
      /// @cond
      ignore_error(const ignore_error&) = default;
      ignore_error& operator =(const ignore_error&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "Abort error."_t;}
    };
  }
}
