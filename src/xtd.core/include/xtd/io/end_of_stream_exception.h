/// @file
/// @brief Contains xtd::io::end_of_stream_exception exception.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "io_exception.h"
#include "../literals.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when reading is attempted past the end of a stream.
    /// ```cpp
    /// class end_of_stream_exception : public xtd::io::io_exception
    /// ```
    /// @par Inheritance
    /// xtd::io::io_exception → xtd::io::end_of_stream_exception
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/end_of_stream_exception>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core exceptions
    /// @par Examples
    /// The following example demonstrates how to throw and catch an end_of_stream_exception.
    /// @include end_of_stream_exception.cpp
    class end_of_stream_exception : public xtd::io::io_exception {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      explicit end_of_stream_exception(const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      explicit end_of_stream_exception(const xtd::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class xtd::io::end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param stack_frame (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      template<typename exception_t>
      end_of_stream_exception(const xtd::optional<xtd::string>& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame = null) : io_exception(message, inner_exception, stack_frame) {error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));}

      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @remarks Message is set with the default message associate to the exception.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::error_code - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the property xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null);
      /// @brief Create a new instance of class end_of_stream_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Contains current stack frame about member name, file path and  line number in the file where the exception is occurred. Typically #current_stack_frame_.
      /// @deprecated Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.
      [[deprecated("Use xtd::io::end_of_stream_exception (const xtd::string& message, const exception_t& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) and manually set the properties xtd::exception::error_code and xtd::exception::help_link - Will be removed in version 0.4.0.")]]
      explicit end_of_stream_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& info = null);
      /// @}
      
      /// @cond
      end_of_stream_exception(const end_of_stream_exception&) = default;
      end_of_stream_exception& operator =(const end_of_stream_exception&) = default;
      /// @endcond
    };
  }
}
