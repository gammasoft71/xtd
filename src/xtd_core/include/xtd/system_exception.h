#pragma once
#include <cstdint>
#include <stdexcept>
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
    explicit system_exception(const std::string& str, const xtd::caller_info& info = xtd::caller_info::empty()) : what_(str), info_(info) {}
    explicit system_exception(const std::string& str, int32_t hresult, std::string& help_link, const xtd::caller_info& info = xtd::caller_info::empty()) : what_(str), hresult_(hresult), help_link_(help_link), info_(info) {}

    /// @cond
    system_exception(const system_exception&) = default;
    system_exception& operator=(const system_exception&) = default;
    /// @endcond
    
    xtd::caller_info caller_info() const {return info_;}
    
    const char* what() const noexcept override {return what_.c_str();}
    
    const std::string& help_link() const noexcept {return help_link_;}
    
    int32_t hresult() const noexcept {return hresult_;}

    std::string to_string() const {return info_ == caller_info::empty() ? xtd::strings::format("{} : {}", strings::class_name(*this), what()) : xtd::strings::format("{} : {}\n{}", strings::class_name(*this), what(), caller_info());}

  private:
    std::string what_ = "Sytem error.";
    int32_t hresult_ = 0;
    std::string help_link_;
    xtd::caller_info info_;
  };
}

#define system_exception_(...) system_exception(add_caller_info_(__VA_ARGS__))
