#pragma once
#include "ioexception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief The exception that is thrown when a path or file name is longer than the system-defined maximum length.
    /// @par Library
    /// xtd.core
    /// @par Examples
    /// The following example demonstrates how to throw and catch an path_too_long_exception.
    /// @include path_too_long_exception.cpp
    class path_too_long_exception :public ioexception {
    public:
      /// @brief Create a new instance of class path_too_long_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      path_too_long_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message_, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, help_link, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit path_too_long_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, help_link, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      path_too_long_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message_, inner_exception, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class path_too_long_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit path_too_long_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      path_too_long_exception(const path_too_long_exception&) = default;
      path_too_long_exception& operator=(const path_too_long_exception&) = default;
      /// @endcond
      
    private:
      static constexpr const char* default_message_ = "The specified path, file name, or both are too long. The fully ualified file name must be less than 260 caracters, and the directory name must be less than 248 caracters.";
    };
  }
}

/// @brief Helper on path_too_long_exception to call it with caller information
/// @remarks Is equivalent to path_too_long_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw path_too_long_exception_(); // same as : throw path_too_long_exception(caller_info_)
///   if (invalid_value) throw path_too_long_exception_("Bad value"); // same as : throw path_too_long_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define path_too_long_exception_(...) path_too_long_exception(add_caller_info_(__VA_ARGS__))
