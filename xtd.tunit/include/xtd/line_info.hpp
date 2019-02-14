/// @file
/// @brief Contains xtd::tunit::caller class.
#pragma once
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @brief caller information class is used to store current file, current line and current function information.
    /// @par Examples
    /// The following example shows how to use the caller
    /// @include caller.cpp
    class line_info final {
    public:
      line_info() noexcept = default;
      line_info(const std::string& file_path, unsigned int line_number) noexcept : file_path_(file_path), line_number_(line_number) {}
      line_info(const std::string& member_name, const std::string& file_path, unsigned int line_number) noexcept : member_name_(member_name), file_path_(file_path), line_number_(line_number) {}
      
      /// @cond
      line_info(const line_info& caller) = default;
      line_info& operator=(const line_info&) = default;
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
      
      friend std::ostream& operator<<(std::ostream& os, const xtd::tunit::line_info caller) {
        if (caller.file_path_ == "" && caller.line_number_ == 0 && caller.member_name_ == "")
          return os << "{Empty}";
        if (caller.member_name_ == "")
          return os << "{file_path=\"" << caller.file_path_ << "\", line_number=" << caller.line_number_<< "}";
        return os << "{member_name=\"" << caller.member_name_ << "\", file_path=\"" << caller.file_path_ << "\", line_number=" << caller.line_number_<< "}";
      }

    private:
      std::string member_name_;
      std::string file_path_;
      unsigned int line_number_ = 0;
    };
  }
}
