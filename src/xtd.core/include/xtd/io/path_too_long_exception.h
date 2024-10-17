/// @file
/// @brief Contains xtd::io::path_too_long_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "io_exception.h"
#include "../literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when a path or file name is longer than the system-defined maximum length.
    /// ```cpp
    /// class path_too_long_exception : public xtd::io::io_exception
    /// ```
    /// @par Inheritance
    /// xtd::io::io_exception → xtd::io::path_too_long_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/path_too_long_exception>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an path_too_long_exception.
    /// @include path_too_long_exception.cpp
    class path_too_long_exception : public xtd::io::io_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class path_too_long_exception
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit path_too_long_exception(const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(default_message(), stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, error, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, help_link, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit path_too_long_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, error, help_link, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      /// @remarks Message is set with the default message associate to the exception.
      explicit path_too_long_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(default_message(), inner_exception, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, error, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, help_link, stack_frame) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically  xtd::diagnostics::stack_frame::current().
      explicit path_too_long_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame = xtd::diagnostics::stack_frame::current()) : io_exception(message, inner_exception, error, help_link, stack_frame) {}
      /// @}
      /// @cond
      path_too_long_exception(const path_too_long_exception&) = default;
      path_too_long_exception& operator =(const path_too_long_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const noexcept {return "The specified path, file name, or both are too long. The fully qualified file name must be less than 260 characters, and the directory name must be less than 248 characters."_t;}
    };
  }
}
