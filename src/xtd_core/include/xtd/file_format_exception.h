#pragma once
#include "format_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when the format of an argument does not meet the parameter specifications of the invoked method.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// The following example demonstrates how to throw and catch an file_format_exception.
  /// @include file_format_exception.cpp
  class file_format_exception :public format_exception {
  public:
    /// @brief Create a new instance of class file_format_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    file_format_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(default_message_, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, error, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, help_link, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit file_format_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    file_format_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(default_message_, inner_exception, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class file_format_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit file_format_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : format_exception(message, inner_exception, error, help_link, info) {}

    /// @cond
    file_format_exception(const file_format_exception&) = default;
    file_format_exception& operator=(const file_format_exception&) = default;
    /// @endcond
    
  private:
    static constexpr const char* default_message_ = "Input file or data stream does not conform to the expected file format specification.";
  };
}

/// @brief Helper on file_format_exception to call it with caller information
/// @remarks Is equivalent to file_format_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw file_format_exception_(); // same as : throw file_format_exception(caller_info_)
///   if (invalid_value) throw file_format_exception_("Bad value"); // same as : throw file_format_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define file_format_exception_(...) file_format_exception(add_caller_info_(__VA_ARGS__))
