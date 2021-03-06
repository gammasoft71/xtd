/// @file
/// @brief Contains xtd::collections::key_not_found_exception exception.
#pragma once
#include "../system_exception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace collections {
    /// @brief The exception that is thrown when the key specified for accessing an element in a collection does not match any key in the collection.
    /// @par Library
    /// xtd.core
    /// @par Examples
    /// The following example demonstrates how to throw and catch an key_not_found_exception.
    /// @include key_not_found_exception.cpp
    /// @ingroup xtd_core
    class key_not_found_exception :public system_exception {
    public:
      /// @brief Create a new instance of class key_not_found_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      key_not_found_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message(), info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, help_link, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit key_not_found_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, error, help_link, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      key_not_found_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(default_message(), inner_exception, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class key_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit key_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : system_exception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      key_not_found_exception(const key_not_found_exception&) = default;
      key_not_found_exception& operator=(const key_not_found_exception&) = default;
      /// @endcond
      
    private:
      const char* default_message() const {return "The given key was not present in the dictionnary."_t;}
    };
  }
}
