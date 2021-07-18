/// @file
/// @brief Contains xtd::system_exception exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <system_error>
#include "core_export.h"
#include "literals.h"
#include "object.h"
#include "strings.h"
#include "diagnostics/stack_frame.h"
#include "diagnostics/stack_trace.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the base class for predefined exceptions in the xtd namespace.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class core_export_ system_exception : public object, public std::exception {
  public:
    /// @brief Optional reference wrapper on std::eception
    using exception_ref = std::optional<std::reference_wrapper<const std::exception>>;
    
    /// @brief Create a new instance of class system_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), nullptr, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit system_exception(const std::string& message, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, error, "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::string& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, std::error_code(), help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, nullptr, error, help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(default_message(), &inner_exception, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, std::error_code(), "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, error, "", information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, std::error_code(), help_link, information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& information = xtd::diagnostics::stack_frame::empty()) : system_exception(message, &inner_exception, error, help_link, information) {}
    
    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator=(const system_exception&) = default;
    /// @endcond
    
    /// @brief Get file path where exception occurred
    /// @return A string represent file path where exception occurred
    virtual const std::string& file_path() const noexcept {return information_.get_file_name();}
    
    /// @brief Gets a link to the help file associated with this exception.
    /// @return A string represent a link to Help file associated with sxception
    virtual const std::string& help_link() const noexcept {return help_link_;}
    
    /// @brief Gets or sets if the generation of the stack trace is enabled.
    static bool enable_stack_trace() {return enable_stack_trace_;}
    static void enable_stack_trace(bool enable) {enable_stack_trace_ = enable;}

    /// @brief Get error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    virtual std::error_code error() const noexcept {return error_;}
    
    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    virtual exception_ref inner_exception() const noexcept {return inner_exception_;}
    
    /// @brief Get Line number where the exception occurred
    /// @return the line number where exception occurred
    virtual uint32_t line_numer() const noexcept {return information_.get_file_line_number();}
    
    /// @brief Get file member where exception occurred
    /// @return A string represent member name where exception occurred
    virtual const std::string& member_name() const noexcept {return information_.get_method();}
    
    /// @brief Get message associate to the exception
    /// @return A string represent a massage associate to the exception
    virtual const std::string& message() const noexcept {return message_;}
    
    /// @brief Get full class name the exception
    /// @return A string represent a full class name of the exception
    virtual const std::string& name() const noexcept {return (name_ = xtd::strings::full_class_name(*this));}
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    virtual std::string stack_trace() const noexcept {return stack_trace_to_string();}
    
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    std::string to_string() const noexcept override;

    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const xtd::system_exception& e) noexcept {
      return os << e.to_string();
    }
    /// @endcond

    /// @brief Get message associate to the exception
    /// @return A string represent a massage associate to the exception
    const char* what() const noexcept override {return message().empty() ? name().c_str() : message().c_str();}

  private:
    system_exception(const std::string& message, const std::exception* inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& information);
    std::string stack_trace_to_string() const noexcept;
    const char* default_message() const;
    
    static bool enable_stack_trace_;
    mutable std::string name_;
    std::string message_;
    exception_ref inner_exception_;
    std::error_code error_;
    std::string help_link_;
    xtd::diagnostics::stack_frame information_;
    std::shared_ptr<xtd::diagnostics::stack_trace> stack_trace_;
  };
}

/// @brief Helper on system_exception to call it with caller information
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks Is equivalent to system_exception({any argument}, current_stack_frame_)
/// @code
/// void my_func() {
///   if (invalid_info) throw stystem_exception_(); // same as : throw system_exception(current_stack_frame_)
///   if (invalid_value) throw stystem_exception_("Bad value"); // same as : throw system_exception("Bad value", current_stack_frame_)
///   ...
/// }
/// @endcode
#define system_exception_(...) system_exception(add_current_stack_frame_(__VA_ARGS__))
