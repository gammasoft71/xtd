/// @file
/// @brief Contains xtd::io::file_format_exception exception.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../format_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an file_format_exception.
    /// @include file_format_exception.cpp
    class file_format_exception : public format_exception {
    public:
      /// @brief Create a new instance of class file_format_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      file_format_exception(const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(default_message(), info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, error, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, help_link, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit file_format_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      file_format_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class file_format_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::diagnostics::stack_frame& info = xtd::diagnostics::stack_frame::empty()) : format_exception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      file_format_exception(const file_format_exception&) = default;
      file_format_exception& operator=(const file_format_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const {return "Input file or data stream does not conform to the expected file format specification."_t;}
    };
  }
}
