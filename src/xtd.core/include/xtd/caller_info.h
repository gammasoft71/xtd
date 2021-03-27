/// @file
/// @brief Contains xtd::caller_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include <string>
#include "va_args_comma.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief caller_info information class is used to store current file, current line and current function information.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
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
    caller_info(const std::string& file_path, unsigned int line_number, const std::string& member_name) noexcept : file_path_(file_path), line_number_(line_number), member_name_(member_name) {}
    
    /// @brief Return an empty caller info.
    /// @return Empty caller info.
    static xtd::caller_info empty() noexcept {return {};}
    
    /// @cond
    caller_info(const caller_info& caller_info) = default;
    caller_info& operator=(const caller_info&) = default;
    bool operator==(const caller_info& li) const {return member_name_ == li.member_name_ && file_path_ == li.file_path_ && line_number_ == li.line_number_;}
    bool operator!=(const caller_info& li) const {return !operator==(li);}
    /// @endcond
    
    /// @brief Gets the member name
    /// @return string member name
    const std::string& member_name() const noexcept {return member_name_;}
    
    /// @brief Gets the file path
    /// @return string file path
    const std::string& file_path() const noexcept {return file_path_;}
    
    /// @brief Gets the line number
    /// @return int32 line number
    unsigned int line_number() const noexcept {return line_number_;}
    
    std::string to_string() const noexcept {
      if (file_path_ == "" && line_number_ == 0 && member_name_ == "") return "{Empty}";
      if (member_name_ == "") return "{file_path=\"" + file_path_ + "\", line_number=" + std::to_string(line_number_) + "}";
      return "{member_name=\"" + member_name_ + "\", file_path=\"" + file_path_ + "\", line_number=" + std::to_string(line_number_) + "}";
    }
    
    std::string to_trace() const noexcept {
      if (file_path_ == "" && line_number_ == 0 && member_name_ == "") return "";
      if (member_name_ == "") return "  at {unknown} in " + file_path_ + ": " + std::to_string(line_number_);
      return "  at " + member_name_ + " in " + file_path_ + ": " + std::to_string(line_number_);
    }
    
    /// @cond
    friend std::ostream& operator<<(std::ostream& os, const xtd::caller_info caller_info) noexcept {return os << caller_info.to_string();}
    /// @endcond

  private:
    std::string file_path_;
    unsigned int line_number_ = 0;
    std::string member_name_;
  };
}

/// @brief Get xtd::tunit::caller_info informations
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @return xtd::tunit::caller_info caller informations.
/// @par Examples
/// The following example shows how to use the #caller_info_.
/// @include caller_info.cpp
#define caller_info_ \
  xtd::caller_info {__FILE__, __LINE__, __func__}

#define add_caller_info_(...) \
  __VA_ARGS__ __VA_ARGS_COMMA__(__VA_ARGS__) caller_info_
