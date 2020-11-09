#pragma once
#include "arithmetic_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown when an arithmetic, casting, or conversion operation in a checked context results in an overflow.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// The following example demonstrates how to throw and catch an overflow_exception.
  /// @include overflow_exception.cpp
  class overflow_exception :public arithmetic_exception {
  public:
    /// @brief Create a new instance of class overflow_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    overflow_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(default_message_, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, error, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, help_link, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit overflow_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    overflow_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(default_message_, inner_exception, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class overflow_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit overflow_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : arithmetic_exception(message, inner_exception, error, help_link, info) {}

    /// @cond
    overflow_exception(const overflow_exception&) = default;
    overflow_exception& operator=(const overflow_exception&) = default;
    /// @endcond
    
  private:
    static constexpr const char* default_message_ = "Arithmetic operation resulted in an overflow.";
  };
}

/// @brief Helper on overflow_exception to call it with caller information
/// @remarks Is equivalent to overflow_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw overflow_exception_(); // same as : throw overflow_exception(caller_info_)
///   if (invalid_value) throw overflow_exception_("Bad value"); // same as : throw overflow_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define overflow_exception_(...) overflow_exception(add_caller_info_(__VA_ARGS__))
