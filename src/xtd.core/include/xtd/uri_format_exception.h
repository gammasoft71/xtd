/// @file
/// @brief Contains xtd::uri_format_exception exception.
#pragma once
#include "format_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when an invalid Uniform Resource Identifier (URI) is detected.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class uri_format_exception : public format_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class uri_format_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit uri_format_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(default_message(), info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, error, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, help_link, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit uri_format_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit uri_format_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(default_message(), inner_exception, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit uri_format_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, error, help_link, info) {}
    /// @}
    
    /// @cond
    uri_format_exception(const uri_format_exception&) = default;
    uri_format_exception& operator =(const uri_format_exception&) = default;
    /// @endcond
    
  private:
    const char* default_message() const noexcept {return "One of identified items was an invalid format."_t;}
  };
}

/// @brief Helper on xtd::uri_format_exception to call it with current stack frame information.
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::uri_format_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw uri_format_exception_(); // same as : throw uri_format_exception {csf_};
///   if (invalid_value) throw uri_format_exception_("Bad value"); // same as : throw uri_format_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define uri_format_exception_(...) uri_format_exception(add_csf_(__VA_ARGS__))
