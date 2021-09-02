/// @file
/// @brief Contains xtd::tunit::line_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief line_info information class is used to store current file, current line and current function information.
    /// @par Namespace
    /// xtd::tunit
    /// @par Examples
    /// The following example shows how to use the line_info
    /// @include line_info.cpp
    class line_info final {
    public:
      /// @brief Creates new instance of line info.
      line_info() noexcept = default;

      /// @brief Creates new instance of line info with file path specified, and line number specified.
      /// @param file_path Contains the file path string.
      /// @param line_number Contains the line number.
      line_info(const std::string& file_path, unsigned int line_number) noexcept : file_path_(file_path), line_number_(line_number) {}

      /// @brief Creates new instance of line info with member name specified, file path specified, and line number specified.
      /// @param member_name Contains the member name string.
      /// @param file_path Contains the file path string.
      /// @param line_number Contains the line number.
      line_info(const std::string& member_name, const std::string& file_path, unsigned int line_number) noexcept : member_name_(member_name), file_path_(file_path), line_number_(line_number) {}
      
      /// @brief Return an empty line info.
      /// @return Empty line info.
      static xtd::tunit::line_info empty() {return {};}
      
      /// @cond
      line_info(const line_info& line_info) = default;
      line_info& operator=(const line_info&) = default;
      bool operator==(const line_info& li) const {return member_name_ == li.member_name_ && file_path_ == li.file_path_ && line_number_ == li.line_number_;}
      bool operator!=(const line_info& li) const {return !operator==(li);}
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
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::tunit::line_info line_info) noexcept {
        if (line_info.file_path_ == "" && line_info.line_number_ == 0 && line_info.member_name_ == "")
          return os << "{Empty}";
        if (line_info.member_name_ == "")
          return os << "{file_path=\"" << line_info.file_path_ << "\", line_number=" << line_info.line_number_<< "}";
        return os << "{member_name=\"" << line_info.member_name_ << "\", file_path=\"" << line_info.file_path_ << "\", line_number=" << line_info.line_number_<< "}";
      }
      /// @endcond

    private:
      std::string member_name_;
      std::string file_path_;
      unsigned int line_number_ = 0;
    };
  }
}

/// @brief Get xtd::tunit::line_info informations
/// @par Library
/// xtd.tunit
/// @ingroup xtd_tunit
/// @return xtd::tunit::line_info line informations.
/// @par Examples
/// The following example shows how to use the #line_info_.
/// @include line_info.cpp
#define line_info_ \
  xtd::tunit::line_info {__func__, __FILE__, __LINE__}
