#pragma once
#include <cstdint>
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
    /// @brief Create a new instance of class system_exception
    /// @remarks Message is set with the default message associate to the error.
    system_exception(const xtd::caller_info& info = xtd::caller_info::empty()) : info_(info) {}
    explicit system_exception(const std::string& message, const xtd::caller_info& info = xtd::caller_info::empty()) : message_(message), info_(info) {}
    explicit system_exception(const std::string& message, const std::error_code& error, std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : message_(message), error_(error), help_link_(help_link), info_(info) {}

    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator=(const system_exception&) = default;
    /// @endcond
    
    xtd::caller_info caller_info() const {return info_;}
    
    const std::string& help_link() const noexcept {return help_link_;}
    
    std::error_code error() const noexcept {return error_;}

    std::string name() const {return xtd::strings::class_name(*this);}
    
    const std::string& message() const {return message_;}
    
    std::string to_string() const {return info_ == caller_info::empty() ? xtd::strings::format("{} : {}", name(), what()) : xtd::strings::format("{} : {}\n{}", name(), message(), caller_info());}
    
    const char* what() const noexcept override {return message_.c_str();}

  private:
    std::string message_ = "Sytem error.";
    std::error_code error_;
    std::string help_link_;
    xtd::caller_info info_;
  };
}

#define system_exception_(...) system_exception(add_caller_info_(__VA_ARGS__))
