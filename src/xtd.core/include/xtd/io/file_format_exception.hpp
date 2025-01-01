/// @file
/// @brief Contains xtd::io::file_format_exception exception.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../format_exception.hpp"
#include "../literals.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
    /// ```cpp
    /// class file_format_exception : public xtd::format_exception
    /// ```
    /// @par Inheritance
    /// xtd::format_exception → xtd::io::file_format_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/file_format_exception>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an file_format_exception.
    /// @include file_format_exception.cpp
    class file_format_exception : public xtd::format_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class file_format_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit file_format_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit file_format_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      template<typename exception_t>
      file_format_exception(const std::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : xtd::format_exception(std::optional<xtd::string> {message.value_or(default_message())}, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_FORMAT));}
      
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      file_format_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::file_format_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      file_format_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
      
      /// @cond
      file_format_exception(const file_format_exception&) = default;
      file_format_exception& operator =(const file_format_exception&) = default;
      /// @endcond
    private:
      static xtd::string default_message() noexcept;
    };
  }
}
