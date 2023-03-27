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
    class xtd_library final {
    public:
      /// @cond
      xtd_library() = default;
      xtd_library(const xtd_library&) = default;
      xtd_library& operator =(const xtd_library&) = default;
      /// @endcond
      
      const xtd::ustring& name() const {return name_;}
      
      const xtd::version& version() const {return version_;}
      
      const xtd::ustring& include_path() const {return include_path_;}
      
      const xtd::ustring& library_path() const {return library_path_;}
      
      const xtd::ustring& resources_path() const {return resources_path_;}
      
      xtd::ustring to_string() const {return xtd::ustring::format("{} (version {})", name_, version_);}
      
    private:
      friend class system_report;
      xtd_library(const xtd::ustring& name, const xtd::version& version, const xtd::ustring& include_path, const xtd::ustring& library_path, const xtd::ustring& resources_path) : name_(name), version_(version), include_path_(include_path), library_path_(library_path), resources_path_(resources_path) {}
      xtd::ustring name_;
      xtd::version version_;
      xtd::ustring include_path_;
      xtd::ustring library_path_;
      xtd::ustring resources_path_;
    };
    
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
    
    static xtd::diagnostics::stack_trace stack_trace() noexcept {return stack_trace(0);}
    
    static xtd::diagnostics::stack_trace stack_trace(size_t skip_frames) noexcept {return xtd::diagnostics::stack_trace(skip_frames, true);}
    
    static const xtd_library_collection& xtd_libraries() noexcept;
    
    static xtd::operating_system operating_system() noexcept {return xtd::environment::os_version();}
    
    static xtd::processor processor() noexcept {return xtd::environment::processor_information();}
    
    static xtd::compiler compiler() noexcept {return xtd::environment::compiler_version();}
    
    static xtd::cpp_language language() noexcept {return xtd::environment::cpp_version();}
    
    static std::locale locale() noexcept {return std::locale();}
    
    static xtd::toolkit toolkit() noexcept {return xtd::environment::toolkit_version();}
    
    static environment_variable_collection environment_variables() noexcept;
    
    static const special_folder_collection& special_folders() noexcept;
    
    static const system_color_collection& system_colors() noexcept;
    
    static const system_font_family_collection& generic_font_families() noexcept;
    
    static const system_font_collection& system_fonts() noexcept;
    
    static std::vector<xtd::forms::screen> screens() noexcept {return xtd::forms::screen::all_screens();}
    
    static system_information_collection system_informations() noexcept;
    
    /// @brief Generates string report.
    /// @return A string report.
    static xtd::ustring to_string() noexcept;
    /// @brief Generates xml format string report.
    /// @return An xml format string report.
    /// @todo Implement xml report
    static xtd::ustring to_xml() noexcept;
  };
}
