#pragma once
#include "system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The exception that is thrown for errors in domain. That is, situations where the inputs are outside of the domain on which an operation is defined..
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// The following example demonstrates how to throw and catch an domain_exception.
  /// @include domain_exception.cpp
  class domain_exception :public system_exception {
  public:
    /// @brief Create a new instance of class domain_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    domain_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message_, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, help_link, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    explicit domain_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, help_link, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    domain_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message_, inner_exception, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, help_link, info) {}
    /// @brief Create a new instance of class domain_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit domain_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, help_link, info) {}

    /// @cond
    domain_exception(const domain_exception&) = default;
    domain_exception& operator=(const domain_exception&) = default;
    /// @endcond
    
  private:
    static constexpr const char* default_message_ = "Report domain error.";
  };
}

/// @brief Helper on domain_exception to call it with caller information
/// @remarks Is equivalent to domain_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw domain_exception_(); // same as : throw domain_exception(caller_info_)
///   if (invalid_value) throw domain_exception_("Bad value"); // same as : throw domain_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define domain_exception_(...) domain_exception(add_caller_info_(__VA_ARGS__))
