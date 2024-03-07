/// @file
/// @brief Contains xtd::system_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/stack_frame.h"
#include "diagnostics/stack_trace.h"
#include "optional.h"
#include "core_export.h"
#include "finally.h"
#include "literals.h"
#include "object.h"
#include "ustring.h"
#include <cstdint>
#include <stdexcept>
#include <system_error>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the base class for predefined exceptions in the xtd namespace.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class core_export_ system_exception : public object, public std::exception {
  public:
    /// @name Aliases
    
    /// @{
    /// @brief Optional reference wrapper on std::exception
    using exception_ref = std::optional<std::reference_wrapper<const std::exception>>;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Create a new instance of class system_exception
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), nullptr, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit system_exception(const xtd::ustring& message, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::error_code& error, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, error, "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, std::error_code(), help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, error, help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), &inner_exception, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, error, "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::exception& inner_exception, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, std::error_code(), help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Contains current information about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const xtd::ustring& message, const std::exception& inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, error, help_link, information) {}
    /// @}
    
    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator =(const system_exception&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets file path where exception occurred
    /// @return A string represent file path where exception occurred
    virtual const xtd::ustring& file_path() const noexcept;
    
    /// @brief Gets a link to the help file associated with this exception.
    /// @return A string represent a link to Help file associated with exception
    virtual const xtd::ustring& help_link() const noexcept;
    
    /// @brief Gets error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    virtual std::error_code error_code() const noexcept;
    
    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    virtual exception_ref inner_exception() const noexcept;
    
    /// @brief Gets Line number where the exception occurred
    /// @return the line number where exception occurred
    virtual uint32 line_number() const noexcept;
    
    /// @brief Gets file member where exception occurred
    /// @return A string represent member name where exception occurred
    virtual const xtd::ustring& member_name() const noexcept;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    virtual const xtd::ustring& message() const noexcept;
    
    /// @brief Gets full class name the exception
    /// @return A string represent a full class name of the exception
    virtual const xtd::ustring& name() const noexcept;
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    virtual xtd::ustring stack_trace() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    xtd::ustring to_string() const noexcept override;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    const char* what() const noexcept override;
    /// @}
    
    /// @name Static methods
    
    /// @{
    /// @brief Gets if the generation of the stack trace is enabled.
    /// @return triue if stack trace enabled; otherwhise false.
    static bool enable_stack_trace() noexcept;
    /// @brief Sets if the generation of the stack trace is enabled.
    /// @paran enable triue if stack trace enabled; otherwhise false.
    static void enable_stack_trace(bool enable) noexcept;
    /// @}

  private:
    system_exception(const xtd::ustring& message, const std::exception* inner_exception, const std::error_code& error, const xtd::ustring& help_link, const xtd::diagnostics::stack_frame& information);
    xtd::ustring stack_trace_to_string() const noexcept;
    const char* default_message() const noexcept;
    
    static bool enable_stack_trace_;
    mutable xtd::ustring name_;
    xtd::ustring message_;
    exception_ref inner_exception_;
    std::error_code error_;
    xtd::ustring help_link_;
    xtd::diagnostics::stack_frame information_;
    std::shared_ptr<xtd::diagnostics::stack_trace> stack_trace_;
  };
}

/// @brief Helper on xtd::system_exception to call it with current stack frame information.
/// @par Library
/// xtd.core
/// @ingroup xtd_core exceptions
/// @remarks Is equivalent to xtd::system_exception {{any argument}, csf_}
/// @code
/// void my_func() {
///   if (invalid_info) throw system_exception_(); // same as : throw system_exception {csf_};
///   if (invalid_value) throw system_exception_("Bad value"); // same as : throw system_exception {"Bad value", csf_};
///   ...
/// }
/// @endcode
#define system_exception_(...) system_exception(add_csf_(__VA_ARGS__))
