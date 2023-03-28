/// @file
/// @brief Contains xtd::system_report class
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/version.h>
#include <xtd/drawing/color.h>
#include <xtd/drawing/font.h>
#include <xtd/forms/screen.h>
#include <xtd/forms/system_information.h>
#include "export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides system report about the current system environment.
  /// @par Library
  /// xtd
  /// @ingroup xtd system_information
  /// @remarks The system_report class provides static properties that can be used to get information and creates a string and xml format string reports about the current system environment.
  class export_ system_report final static_ {
  public:
    /// @brief Represents a xtd library that contains name, version and paths.
    class xtd_library final : public xtd::object {
    public:
      /// @cond
      xtd_library() = default;
      xtd_library(const xtd_library&) = default;
      xtd_library& operator =(const xtd_library&) = default;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets The inlcude path of the library.
      /// @return A string that represents the include path of the library.
      const xtd::ustring& include_path() const noexcept;
      
      /// @brief Gets The library path of the library.
      /// @return A string that represents the library path of the library.
      const xtd::ustring& library_path() const noexcept;
      
      /// @brief Gets The name of the library.
      /// @return A string that represents the name of the library.
      const xtd::ustring& name() const noexcept;
      
      /// @brief Gets The resource path of the library.
      /// @return A string that represents the resource path of the library.
      const xtd::ustring& resources_path() const noexcept;

      /// @brief Gets The version of the library.
      /// @return An xtd::version object that represents the version of the library.
      const xtd::version& version() const noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      xtd::ustring to_string() const noexcept override;
      /// @}
      
    private:
      friend class system_report;
      xtd_library(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& include_path, const xtd::ustring& library_path, const xtd::ustring& resources_path);
      xtd::ustring name_;
      xtd::version version_;
      xtd::ustring include_path_;
      xtd::ustring library_path_;
      xtd::ustring resources_path_;
    };
    
    /// @name Alias
    
    /// @{
    /// @brief Represents a xtd libraries collection.
    using xtd_library_collection = std::vector<xtd_library>;
    /// @brief Represents an environment variables collection.
    using environment_variable_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @brief Represents a folders collection.
    using special_folder_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @brief Represents a colors collection.
    using system_color_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::color>>;
    /// @brief Represents a font families collection.
    using system_font_family_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::font_family>>;
    /// @brief Represents a fonts collection.
    using system_font_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::font>>;
    /// @brief Represents a system informations collection.
    using system_information_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @}
    
    /// @name Properties
    
    /// @{
    /// @brief Gets an xtd::compiler object that contains the current compiler identifier and version number.
    /// @return An object that contains the compiler identifier and version number.
    static xtd::compiler compiler() noexcept;
    
    /// @brief Retrieves all environment variable names and their values from the current process.
    /// @return std::map A dictionary that contains all environment variable names and their values; otherwise, an empty dictionary if no environment variables are found.
    static environment_variable_collection environment_variables() noexcept;
    
    /// @brief Gets a generic font_families.
    /// @return Generic font families collection.
    static const system_font_family_collection& generic_font_families() noexcept;

    /// @brief Gets an xtd::cpp_language object that contains the current c++ standard identifier and version number.
    /// @return An object that contains the c++ standard identifier and version number.
    static xtd::cpp_language language() noexcept;
    
    /// @brief Gets a copy of the global C++ locale, which is the locale most recently used as the argument to See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::global</a> or a copy of See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::classic()</a> if no call to See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale::global</a> has been made.
    /// @return A copy of the global C++ locale.
    /// @remarks See <a href=https://en.cppreference.com/w/cpp/locale/locale/locale>std::locale</a> for more information.
    static std::locale locale() noexcept;
    
    static xtd::operating_system operating_system() noexcept;
    
    static xtd::processor processor() noexcept;
    
    static std::vector<xtd::forms::screen> screens() noexcept;

    static const special_folder_collection& special_folders() noexcept;
    
    /// @brief Gets current stack trace information.
    /// @return A string containing stack trace information. This value can be empty "".
    static xtd::diagnostics::stack_trace stack_trace() noexcept;
    
    /// @brief Gets current stack trace information with specified number of frames to skip.
    /// @param skip_frames The number of frames to skip.
    /// @return A string containing stack trace information. This value can be empty "".
    static xtd::diagnostics::stack_trace stack_trace(size_t skip_frames) noexcept;
    
    static const system_color_collection& system_colors() noexcept;
    
    static const system_font_collection& system_fonts() noexcept;
    
    static system_information_collection system_informations() noexcept;

    static xtd::toolkit toolkit() noexcept;

    static const xtd_library_collection& xtd_libraries() noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Generates string report.
    /// @return A string report.
    static xtd::ustring to_string() noexcept;
    /// @brief Generates xml format string report.
    /// @return An xml format string report.
    /// @todo Implement xml report
    static xtd::ustring to_xml() noexcept;
    /// @}
  };
}
