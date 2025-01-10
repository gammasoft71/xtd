/// @file
/// @brief Contains xtd::uri_template_match_exception exception.
#pragma once
#include "literals.hpp"
#include "system_exception.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents an error when matching a Uri to a UriTemplateTable.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class uri_template_match_exception : public system_exception {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class uri_template_match_exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit uri_template_match_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class uri_template_match_exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit uri_template_match_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class uri_template_match_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<class exception_t>
    uri_template_match_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::system_exception(message, inner_exception, stack_frame) {}
    /// @}
    
    /// @cond
    uri_template_match_exception(const uri_template_match_exception&) = default;
    uri_template_match_exception& operator =(const uri_template_match_exception&) = default;
    /// @endcond
  };
}
