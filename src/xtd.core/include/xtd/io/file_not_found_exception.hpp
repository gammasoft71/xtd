/// @file
/// @brief Contains xtd::io::file_not_found_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "io_exception.hpp"
#include "../literals.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when an attempt to access a file that does not exist on disk fails.
    /// ```cppƒ
    /// class file_not_found_exception : public xtd::io::io_exception
    /// ```
    /// @par Inheritance
    /// xtd::io::io_exception → xtd::io::file_not_found_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/file_not_found_exception>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an file_not_found_exception.
    /// @include file_not_found_exception.cpp
    class file_not_found_exception : public xtd::io::io_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit file_not_found_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit file_not_found_exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      template<typename exception_t>
      file_not_found_exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, stack_frame), defined_message_ {message.has_value()} {error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));}
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param file_name The full name of the file that cannot be found.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      file_not_found_exception(const xtd::optional<xtd::string>& message, const xtd::optional<xtd::string>& file_name, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param file_name The full name of the file that cannot be found.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      template<typename exception_t>
      file_not_found_exception(const xtd::optional<xtd::string>& message, const xtd::optional<xtd::string>& file_name, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, stack_frame), file_name_ {file_name}, defined_message_ {message.has_value()} {error_code(h_result::make_error_code(h_result::COR_E_FILENOTFOUND));}

      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @brief Create a new instance of class xtd::io::file_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @deprecated Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::directory_not_found_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit file_not_found_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current());
      /// @}
      /// @cond
      file_not_found_exception(const file_not_found_exception&) = default;
      file_not_found_exception& operator =(const file_not_found_exception&) = default;
      template<typename char_t>
      file_not_found_exception(const xtd::optional<xtd::string>& message, const char_t* file_name, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : file_not_found_exception {message, xtd::optional<xtd::string> {file_name}, stack_frame}  {}
      file_not_found_exception(const xtd::optional<xtd::string>& message, xtd::null_opt file_name, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : file_not_found_exception {message, xtd::optional<xtd::string> {file_name}, stack_frame}  {}
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the name of the file that cannot be found.
      /// @return The name of the file, or `empty` if no file name was passed to the constructor for this instance.
      /// @remrks This property is read-only.
      virtual const xtd::optional<xtd::string>& file_name() const noexcept;
      /// @brief Gets message associate to the exception
      /// @return A string represent a massage associate to the exception
      const xtd::string& message() const noexcept override;
      /// @}
      
    private:
      xtd::optional<xtd::string> file_name_;
      bool defined_message_ = false;
    };
  }
}
