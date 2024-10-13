/// @file
/// @brief Contains xtd::exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/stack_frame.h"
#include "core_export.h"
#include "h_result.h"
#include "object.h"
#include "optional.h"
#include "ptr.h"
#include "string.h"
#include <cstdint>
#include <stdexcept>
#include <system_error>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class system_exception;
  /// @endcond
  
  /// @brief Defines the base class for predefined exceptions in the xtd namespace.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  class core_export_ exception : public object, public std::exception {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Optional reference wrapper on std::exception
    using exception_ref = xtd::optional<std::reference_wrapper<const xtd::exception>>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit exception(const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    explicit exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = null);
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
    template<typename exception_t>
    exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : exception(message, inner_exception.template memberwise_clone<exception_t>(), stack_frame, true) {}
    /// @}
    
    /// @cond
    exception(exception&&) = default;
    exception(const exception&) = default;
    exception& operator =(exception&&) = default;
    exception& operator =(const exception&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a link to the help file associated with this exception.
    /// @return A string represent a link to Help file associated with exception
    virtual const xtd::string& help_link() const noexcept;
    /// @brief Sets a link to the help file associated with this exception.
    /// @param value A string represent a link to Help file associated with exception
    virtual void help_link(const xtd::string& value) noexcept;
    
    /// @brief Gets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @return The HRESULT value.
    virtual int32 h_result() const noexcept;
    /// @brief Sets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @param value The HRESULT value.
    virtual void h_result(int32 value) noexcept;
    
    /// @brief Gets error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    virtual const std::error_code& error_code() const noexcept;
    /// @brief Sets error associate to the exception
    /// @param value An error_code represent a Error associate to the exception
    virtual void error_code(const std::error_code& value) noexcept;

    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    virtual exception_ref inner_exception() const noexcept;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    virtual const xtd::string& message() const noexcept;
    
    /// @brief Gets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    virtual const xtd::string& source() const noexcept;
    /// @brief Sets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    virtual void source(const xtd::string& value) noexcept;
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    virtual xtd::string stack_trace() const noexcept;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Gets the last stack frame where the exception occurred
    /// @return The last stack frame where exception occurred
    virtual const xtd::diagnostics::stack_frame& get_last_stack_frame() const noexcept;
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    xtd::string to_string() const noexcept override;

    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    const char* what() const noexcept override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Gets if the generation of the stack trace is enabled.
    /// @return triue if stack trace enabled; otherwhise false.
    static bool enable_stack_trace() noexcept;
    /// @brief Sets if the generation of the stack trace is enabled.
    /// @paran enable triue if stack trace enabled; otherwhise false.
    static void enable_stack_trace(bool enable) noexcept;
    /// @}

  private:
    exception(const xtd::optional<xtd::string>& message, uptr<xtd::exception>&& inner_exception, const xtd::diagnostics::stack_frame& stack_frame, bool);
    xtd::string stack_trace_to_string() const noexcept;
    
    const xtd::string& get_name() const noexcept;

    struct data;
    ptr<data> data_;    
    static bool enable_stack_trace_;
  };
}
