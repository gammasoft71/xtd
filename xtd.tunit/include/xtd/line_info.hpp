/// @file
/// @brief Contains xtd::tunit::caller class.
#pragma once
#include <ostream>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
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
      
      static xtd::tunit::line_info empty() {return {};}
      
      /// @cond
      line_info(const line_info& caller) = default;
      line_info& operator=(const line_info&) = default;
      bool operator==(const line_info& li) const {return this->member_name_ == li.member_name_ && this->file_path_ == li.file_path_ && this->line_number_ == li.line_number_;}
      bool operator!=(const line_info& li) const {return !this->operator==(li);}
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
      
      friend std::ostream& operator<<(std::ostream& os, const xtd::tunit::line_info caller) noexcept {
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

/// @brief Get xtd::tunit::line_info informations
/// @return xtd::tunit::line_info line informations.
/// @par Examples
/// The following example shows how to use the #line_info_.
/// @include line_info.cpp
/// @ingroup Helpers
#define line_info_ \
  xtd::tunit::line_info {__func__, __FILE__, __LINE__}
