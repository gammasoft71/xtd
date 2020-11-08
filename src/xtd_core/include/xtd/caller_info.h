/// @file
/// @brief Contains xtd::tunit::caller_info class.
#pragma once
#include <ostream>
#include <string>
#include "va_args_comma.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief caller_info information class is used to store current file, current line and current function information.
  /// @par Examples
  /// The following example shows how to use the caller_info
  /// @include caller_info.cpp
  class caller_info final {
  public:
    /// @brief Creates new instance of caller info.
    caller_info() noexcept = default;
    
    /// @brief Creates new instance of caller info with file path specified, and line number specified.
    /// @param file_path Contains the file path string.
    /// @param line_number Contains the line number.
    caller_info(const std::string& file_path, unsigned int line_number) noexcept : file_path_(file_path), line_number_(line_number) {}
    
    /// @brief Creates new instance of caller info with member name specified, file path specified, and line number specified.
    /// @param member_name Contains the member name string.
    /// @param file_path Contains the file path string.
    /// @param line_number Contains the line number.
    caller_info(const std::string& member_name, const std::string& file_path, unsigned int line_number) noexcept : member_name_(member_name), file_path_(file_path), line_number_(line_number) {}
    
    /// @brief Return an empty caller info.
    /// @return Empty caller info.
    static xtd::caller_info empty() {return {};}
    
    /// @cond
    caller_info(const caller_info& caller_info) = default;
    caller_info& operator=(const caller_info&) = default;
    bool operator==(const caller_info& li) const {return this->member_name_ == li.member_name_ && this->file_path_ == li.file_path_ && this->line_number_ == li.line_number_;}
    bool operator!=(const caller_info& li) const {return !this->operator==(li);}
    /// @endcond
    
    /// @brief Gets the member name
    /// @return string member name
    const std::string& member_name() const noexcept {return this->member_name_;}
    
    /// @brief Gets the file path
    /// @return string file path
    const std::string& file_path() const noexcept {return this->file_path_;}
    
    /// @brief Gets the line number
    /// @return int32 line number
    unsigned int line_number() const noexcept {return this->line_number_;}
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const xtd::caller_info caller_info) noexcept {
      if (caller_info.file_path_ == "" && caller_info.line_number_ == 0 && caller_info.member_name_ == "")
        return os << "{Empty}";
      if (caller_info.member_name_ == "")
        return os << "{file_path=\"" << caller_info.file_path_ << "\", line_number=" << caller_info.line_number_<< "}";
      return os << "{member_name=\"" << caller_info.member_name_ << "\", file_path=\"" << caller_info.file_path_ << "\", line_number=" << caller_info.line_number_<< "}";
    }
    /// @endcond
    
  private:
    std::string member_name_;
    std::string file_path_;
    unsigned int line_number_ = 0;
  };
}

/// @brief Get xtd::tunit::caller_info informations
/// @return xtd::tunit::caller_info caller informations.
/// @par Examples
/// The following example shows how to use the #caller_info_.
/// @include caller_info.cpp
/// @ingroup tunit
#define caller_info_ \
  xtd::caller_info {__func__, __FILE__, __LINE__}

#define add_caller_info_(...) \
  __VA_ARGS__ __VA_ARGS_COMMA__(__VA_ARGS__) caller_info_
