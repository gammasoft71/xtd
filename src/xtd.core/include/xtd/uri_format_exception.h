/// @file
/// @brief Contains xtd::uri_format_exception exception.
#pragma once
#include "format_exception.h"
#include "literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when an invalid Uniform Resource Identifier (URI) is detected.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class uri_format_exception : public xtd::format_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class uri_format_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit uri_format_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit uri_format_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class uri_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<typename exception_t>
    uri_format_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::format_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_FORMAT));}
    /// @}
    
    /// @cond
    uri_format_exception(const uri_format_exception&) = default;
    uri_format_exception& operator =(const uri_format_exception&) = default;
    /// @endcond
  };
}
