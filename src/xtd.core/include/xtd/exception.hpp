/// @file
/// @brief Contains xtd::exception exception.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/stack_frame.hpp"
#include "core_export.hpp"
#include "h_result.hpp"
#include "object.hpp"
#include "nullopt.hpp"
#include "optional.hpp"
#include "ptr.hpp"
#include "uptr.hpp"
#include "string.hpp"
#include <exception>
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
    using exception_ref = xtd::optional<xtd::ref<const xtd::exception>>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Create a new instance of class exception
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    /// @remarks Message is set with the default message associate to the exception.
    explicit exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    explicit exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
    /// @brief Create a new instance of class exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
    template<typename exception_t>
    exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : exception(message, inner_exception.template memberwise_clone<exception_t>(), stack_frame, true) {}
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
    [[nodiscard]] virtual auto help_link() const noexcept -> const xtd::string&;
    /// @brief Sets a link to the help file associated with this exception.
    /// @param value A string represent a link to Help file associated with exception
    virtual auto help_link(const xtd::string& value) noexcept -> void;
    
    /// @brief Gets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @return The HRESULT value.
    [[nodiscard]] virtual auto h_result() const noexcept -> xtd::int32;
    /// @brief Sets HRESULT, a coded numerical value that is assigned to a specific exception.
    /// @param value The HRESULT value.
    virtual auto h_result(xtd::int32 value) noexcept -> void;
    
    /// @brief Gets error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    [[nodiscard]] virtual auto error_code() const noexcept -> const std::error_code&;
    /// @brief Sets error associate to the exception
    /// @param value An error_code represent a Error associate to the exception
    virtual auto error_code(const std::error_code& value) noexcept -> void;
    
    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    [[nodiscard]] virtual auto inner_exception() const noexcept -> exception_ref;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    [[nodiscard]] virtual auto message() const noexcept -> const xtd::string&;
    
    /// @brief Gets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    [[nodiscard]] virtual auto source() const noexcept -> const xtd::string&;
    /// @brief Sets the name of the application or the object that causes the error.
    /// @return The name of the application or the object that causes the error.
    /// @remarks If the xtd::exception::source property is not set explicitly, the runtime automatically sets it to the name of the assembly in which the exception originated.
    virtual auto source(const xtd::string& value) noexcept -> void;
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    [[nodiscard]] virtual auto stack_trace() const noexcept -> xtd::string;
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Gets the last stack frame where the exception occurred
    /// @return The last stack frame where exception occurred
    [[nodiscard]] virtual auto get_last_stack_frame() const noexcept -> const xtd::diagnostics::stack_frame&;
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
    
    /// @brief Gets message associate to the exception
    /// @return A string represent a massage associate to the exception
    [[nodiscard]] auto what() const noexcept -> const char* override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Gets if the generation of the stack trace is enabled.
    /// @return triue if stack trace enabled; otherwise `false`.
    [[nodiscard]] static auto enable_stack_trace() noexcept -> bool;
    /// @brief Sets if the generation of the stack trace is enabled.
    /// @paran enable triue if stack trace enabled; otherwise `false`.
    static auto enable_stack_trace(bool enable) noexcept -> void;
    /// @}
    
  private:
    exception(const xtd::optional<xtd::string>& message, xtd::uptr<xtd::exception>&& inner_exception, const xtd::diagnostics::stack_frame& stack_frame, bool);
    [[nodiscard]] auto stack_trace_to_string() const noexcept -> xtd::string;
    
    [[nodiscard]] auto get_name() const noexcept -> const xtd::string&;
    
    struct data;
    xtd::ptr<data> data_;
    static bool enable_stack_trace_;
  };
}
