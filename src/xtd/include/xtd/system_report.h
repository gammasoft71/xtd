/// @file
/// @brief Contains xtd::system_report class
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/strings.h>
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
  /// @remarks The system_report class provides static properties that can be used to get information and creates a string and xml reports about the current system environment.
  class export_ system_report final static_ {
  public:
    class xtd_library final {
    public:
      /// @cond
      xtd_library() = default;
      xtd_library(const xtd_library&) = default;
      xtd_library& operator=(const xtd_library&) = default;
      /// @endcond
      
      const std::string& name() const {return name_;}
      
      const xtd::version& version() const {return version_;}
      
      const std::string& include_path() const {return include_path_;}
      
      const std::string& library_path() const {return library_path_;}
      
      const std::string& resources_path() const {return resources_path_;}
      
      std::string to_string() const {return xtd::strings::format("{} (version {})", name_, version_);}
      
    private:
      friend class system_report;
      xtd_library(const std::string& name, const xtd::version& version, const std::string& include_path, const std::string& library_path, const std::string& resources_path) : name_(name), version_(version), include_path_(include_path), library_path_(library_path), resources_path_(resources_path) {}
      std::string name_;
      xtd::version version_;
      std::string include_path_;
      std::string library_path_;
      std::string resources_path_;
    };
    
    using xtd_library_collection = std::vector<xtd_library>;
    
    using environment_variable_collection = std::vector<std::pair<std::string, std::string>>;
    
    using special_folder_collection = std::vector<std::pair<std::string, std::string>>;
    
    using system_color_collection = std::vector<std::pair<std::string, xtd::drawing::color>>;
    
    using system_font_family_collection = std::vector<std::pair<std::string, xtd::drawing::font_family>>;
    
    using system_font_collection = std::vector<std::pair<std::string, xtd::drawing::font>>;
    
    using system_information_collection = std::vector<std::pair<std::string, std::string>>;
    
    static xtd::diagnostics::stack_trace stack_trace() noexcept {return stack_trace(0);}
    
    static xtd::diagnostics::stack_trace stack_trace(size_t skip_frames) noexcept {return xtd::diagnostics::stack_trace(skip_frames, true);}
    
    static xtd_library_collection xtd_libraries() noexcept;
    
    static xtd::operating_system operating_system() noexcept {return xtd::environment::os_version();}
    
    static xtd::processor processor() noexcept {return xtd::environment::processor_information();}
    
    static xtd::compiler compiler() noexcept {return xtd::environment::compiler_version();}
    
    static xtd::cpp_language language() noexcept {return xtd::environment::cpp_version();}
    
    static std::locale locale() noexcept {return std::locale();}
    
    static environment_variable_collection environment_variables() noexcept;
    
    static special_folder_collection special_folders() noexcept;
    
    static system_color_collection system_colors() noexcept;
    
    static system_font_family_collection generic_font_families() noexcept;
    
    static system_font_collection system_fonts() noexcept;
    
    static std::vector<xtd::forms::screen> screens() noexcept {return xtd::forms::screen::all_screens();}
    
    static system_information_collection system_informations() noexcept;
    
    static std::string to_string() noexcept;

    static std::string to_xml() noexcept;
  };
}
