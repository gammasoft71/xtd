#pragma once
#include <cstdint>
#include <optional>
#include <stdexcept>
#include <system_error>
#include <xtd/strings.h>
#include "caller_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Defines the base class for predefined exceptions in the xtd namespace.
  /// @par Library
  /// xtd.core
  class system_exception : public std::exception {
  public:
    /// @brief Optional reference wrapper on std::eception
    using exception_ref = std::optional<std::reference_wrapper<const std::exception>>;
    
    /// @brief Create a new instance of class system_exception
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const xtd::caller_info& information = xtd::caller_info::empty()) : message_(default_message_), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    explicit system_exception(const std::string& message, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::error_code& error, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), error_(error), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::string& help_link, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), help_link_(help_link), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::error_code& error, const std::string& help_link, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), error_(error), help_link_(help_link), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    /// @remarks Message is set with the default message associate to the exception.
    explicit system_exception(const std::exception& inner_exception, const xtd::caller_info& information = xtd::caller_info::empty()) : inner_exception_(inner_exception), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::exception& inner_exception, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), inner_exception_(inner_exception), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), inner_exception_(inner_exception), error_(error), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::string& help_link, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), inner_exception_(inner_exception), help_link_(help_link), information_(information) {}
    /// @brief Create a new instance of class system_exception
    /// @param message Message string associate to the exception.
    /// @param inner_exception The exception that is the cause of the current exception.
    /// @param error Error code associate to the exception.
    /// @param help_link Help link string associate to the exception.
    /// @param information (optional) Conatains current information about memeber name, file path and  line number in the file where the exception is occurred. Typically #caller_information_.
    system_exception(const std::string& message, const std::exception& inner_exception, const std::error_code& error, const std::string& help_link, const xtd::caller_info& information = xtd::caller_info::empty()) : message_(message), inner_exception_(inner_exception), error_(error), help_link_(help_link), information_(information) {}
    
    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator=(const system_exception&) = default;
    /// @endcond
    
    /// @brief Get file path where exception occurred
    /// @return A string represent file path where exception occurred
    virtual const std::string& file_path() const noexcept {return information_.file_path();}
    
    /// @brief Gets a link to the help file associated with this exception.
    /// @return A string represent a link to Help file associated with sxception
    virtual const std::string& help_link() const noexcept {return help_link_;}
    
    /// @brief Get error associate to the exception
    /// @return An error_code represent a Error associate to the exception
    virtual std::error_code error() const noexcept {return error_;}
    
    /// @brief Gets the exception instance that caused the current exception.
    /// @return An instance of exception that describes the error that caused the current exception. The inner_exception property returns the same value as was passed into the constructor, or a null reference if the inner exception value was not supplied to the constructor.
    virtual exception_ref inner_exception() const noexcept {return inner_exception_;}
    
    /// @brief Get Line number where the exception occurred
    /// @return the line number where exception occurred
    virtual uint32_t line_numer() const noexcept {return information_.line_number();}
    
    /// @brief Get file member where exception occurred
    /// @return A string represent member name where exception occurred
    virtual const std::string& member_name() const noexcept {return information_.member_name();}
    
    /// @brief Get message associate to the exception
    /// @return A string represent a massage associate to the exception
    virtual const std::string& message() const noexcept {return message_;}
    
    /// @brief Get full class name the exception
    /// @return A string represent a full class name of the exception
    virtual std::string name() const noexcept {return xtd::strings::full_class_name(*this);}
    
    /// @brief Gets a string representation of the immediate frames on the call stack.
    /// @return A string that describes the immediate frames of the call stack.
    virtual std::string stack_trace() const noexcept {
      return information_.to_trace();
    }
    
    /// @brief Returns a string that represents the current exception.
    /// @return A string that represents the current exception.
    virtual std::string to_string() const noexcept {
      if (stack_trace().empty()) return xtd::strings::format("{} : {}", name(), message());
      return xtd::strings::format("{} : {}\n{}", name(), message(), stack_trace());
    }

    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const xtd::system_exception& e) noexcept {
      return os << e.to_string();
    }
    /// @endcond

    /// @brief Get message associate to the exception
    /// @return A string represent a massage associate to the exception
    const char* what() const noexcept override {return message().c_str();}

  private:
    static constexpr const char* default_message_ = "Sytem error.";
    std::string message_;
    exception_ref inner_exception_;
    std::error_code error_;
    std::string help_link_;
    xtd::caller_info information_;
  };
}

/// @brief Helper on system_exception to call it with caller information
/// @remarks Is equivalent to system_exception({any argument}, caller_info_)
/// @code
/// void my_func() {
///   if (invalid_info) throw stystem_exception_(); // same as : throw system_exception(caller_info_)
///   if (invalid_value) throw stystem_exception_("Bad value"); // same as : throw system_exception("Bad value", caller_info_)
///   ...
/// }
/// @endcode
#define system_exception_(...) system_exception(add_caller_information_(__VA_ARGS__))
