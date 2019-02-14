/// @file
/// @brief Contains xtd::tunit::caller class.
#pragma once
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @brief caller information class is used to store current file, current line and current function information.
    /// @par Examples
    /// The following example shows how to use the caller
    /// @include caller.cpp
    class caller final {
    public:
      caller() noexcept = default;
      caller(const std::string& file_path, unsigned int line_number) noexcept : file_path_(file_path), line_number_(line_number) {}
      caller(const std::string& member_name, const std::string& file_path, unsigned int line_number) noexcept : member_name_(member_name), file_path_(file_path), line_number_(line_number) {}
      
      /// @cond
      caller(const caller& caller) = default;
      caller& operator=(const caller&) = default;
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
      
    private:
      std::string member_name_;
      std::string file_path_;
      unsigned int line_number_ = 0;
    };
  }
  /// @brief Get xtd::tunit::caller informations
  /// @return xtd::tunit::caller caller informations.
  /// @par Examples
  /// The following example shows how to use the #caller_.
  /// @include caller.cpp
  /// @ingroup Helpers
  #define caller_ \
  xtd::tunit::caller(__func__, __FILE__, __LINE__)
}
