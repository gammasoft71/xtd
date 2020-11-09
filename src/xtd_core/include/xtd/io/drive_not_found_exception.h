#pragma once
#include "ioexception.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace io {
    /// @brief The exception that is thrown when trying to access a drive or share that is not available.
    /// @par Library
    /// xtd.core
    /// @par Examples
    /// The following example demonstrates how to throw and catch an drive_not_found_exception.
    /// @include drive_not_found_exception.cpp
    class drive_not_found_exception :public ioexception {
    public:
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      drive_not_found_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message_, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      explicit drive_not_found_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, error, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      /// @remarks Message is set with the default message associate to the exception.
      drive_not_found_exception(const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(default_message_, inner_exception, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, help_link, info) {}
      /// @brief Create a new instance of class drive_not_found_exception
      /// @param message Message string associate to the exception.
      /// @param inner_exception The exception that is the cause of the current exception.
      /// @param error Error code associate to the exception.
      /// @param help_link Help link string associate to the exception.
      /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
      explicit drive_not_found_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : ioexception(message, inner_exception, error, help_link, info) {}
      
      /// @cond
      drive_not_found_exception(const drive_not_found_exception&) = default;
      drive_not_found_exception& operator=(const drive_not_found_exception&) = default;
      /// @endcond
      
    private:
      static constexpr const char* default_message_ = "Attempted to access a drive that is not avaible.";
    };
  }
}

/// @brief Helper on drive_not_found_exception to call it with caller information
/// @remarks Is equivalent to drive_not_found_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw drive_not_found_exception_(); // same as : throw drive_not_found_exception(caller_info_)
///   if (invalid_value) throw drive_not_found_exception_("Bad value"); // same as : throw drive_not_found_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
/// @ingroup keywords
#define drive_not_found_exception_(...) drive_not_found_exception(add_caller_info_(__VA_ARGS__))
