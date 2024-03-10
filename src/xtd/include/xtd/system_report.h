/// @file
/// @brief Contains xtd::system_report class
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include <xtd/environment>
#include <xtd/static>
#include <xtd/ustring>
#include <xtd/version>
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/forms/screen>
#include <xtd/forms/system_information>
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
    /// @brief Specifies enumerated constants used by xtd::system_report::to_json, xtd::system_report::to_string and xtd::system_report::to_xml methods to generate reports.
    enum class reports {
      /// @brief Stack trace information.
      stack_trace = 0b1,
      /// @brief xtd libraries informations collection.
      libraries = 0b10,
      /// @brief The procesor identifier.
      processor = 0b100,
      /// @brief The platform identifier and version number.
      operating_system = 0b1000,
      /// @brief The compiler identifier and version number.
      compiler = 0b10000,
      /// @brief The c++ standard identifier and version number.
      language = 0b100000,
      /// @brief The global C++ locale.
      locale = 0b1000000,
      /// @brief The toolkit identifier and version number.
      toolkit = 0b10000000,
      /// @brief Environment variable names and their values.
      environment_variables = 0b100000000,
      /// @brief Directory paths to system special folders.
      special_folders = 0b1000000000,
      /// @brief System colors collection.
      system_colors = 0b10000000000,
      /// @brief Generic font families collection.
      generic_font_families = 0b100000000000,
      /// @brief System fonsts collection.
      system_fonts = 0b1000000000000,
      /// @brief Displays on the system.
      screens = 0b10000000000000,
      /// @brief System informations collection.
      system_informations = 0b100000000000000,
      all = stack_trace|libraries|processor|operating_system|compiler|language|locale|toolkit|environment_variables|special_folders|system_colors|generic_font_families|system_fonts|screens|system_informations
    };

    /// @name Public Aliases
    
    /// @{
    /// @brief Represents an environment variables collection.
    using environment_variable_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @brief Represents a folders collection.
    using special_folder_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @brief Represents a colors collection.
    using system_color_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::color>>;
    /// @brief Represents a fonts collection.
    using system_font_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::font>>;
    /// @brief Represents a font families collection.
    using system_font_family_collection = std::vector<std::pair<xtd::ustring, xtd::drawing::font_family>>;
    /// @brief Represents a system informations collection.
    using system_information_collection = std::vector<std::pair<xtd::ustring, xtd::ustring>>;
    /// @}
    
    /// @name Public Static Properties
    
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
    
    /// @brief Gets a copy of the global C++ locale, which is the locale most recently used as the argument to See [std::locale::global](https://en.cppreference.com/w/cpp/locale/locale/locale) or a copy of See [std::locale::classic()](https://en.cppreference.com/w/cpp/locale/locale/locale) if no call to See [std::locale::global](https://en.cppreference.com/w/cpp/locale/locale/locale) has been made.
    /// @return A copy of the global C++ locale.
    /// @remarks See [std::locale](https://en.cppreference.com/w/cpp/locale/locale/locale) for more information.
    static std::locale locale() noexcept;
    
    /// @brief Gets an xtd::operating_system object that contains the current platform identifier and version number.
    /// @return An object that contains the platform identifier and version number.
    static xtd::operating_system operating_system() noexcept;
    
    /// @brief Gets an xtd::processor object that contains the processor identifier.
    /// @return An object that contains the procesor identifier.
    static xtd::processor processor() noexcept;
    
    /// @brief Gets an array of all displays on the system.
    /// @return An array of type screen, containing all displays on the system.
    static std::vector<xtd::forms::screen> screens() noexcept;
    
    /// @brief Gets directory paths to system special folders.
    /// @return A special_folder_collection collection containing directory paths to system special folders.
    static const special_folder_collection& special_folders() noexcept;
    
    /// @brief Gets current stack trace information.
    /// @return A string containing stack trace information. This value can be empty "".
    static xtd::diagnostics::stack_trace stack_trace() noexcept;
    
    /// @brief Gets current stack trace information with specified number of frames to skip.
    /// @param skip_frames The number of frames to skip.
    /// @return A string containing stack trace information. This value can be empty "".
    static xtd::diagnostics::stack_trace stack_trace(size_t skip_frames) noexcept;
    
    /// @brief Gets system colors.
    /// @return A system_color_collection collection containing system colors.
    static const system_color_collection& system_colors() noexcept;
    
    /// @brief Gets system fonts.
    /// @return A system_font_collection collection containing system fonst.
    static const system_font_collection& system_fonts() noexcept;
    
    /// @brief Gets system informations.
    /// @return A system_information_collection collection containing system informations.
    static system_information_collection system_informations() noexcept;
    
    /// @brief Gets an xtd::toolkit object that contains the current toolkit identifier and version number.
    /// @return An object that contains the toolkit identifier and version number.
    static xtd::toolkit toolkit() noexcept;
    
    /// @brief Gets xtd libraries informations.
    /// @return A environment::xtd_library_collection collection containing xtd libraries informations.
    static const environment::xtd_library_collection& xtd_libraries() noexcept;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Generates json format string report.
    /// @return An json format string report.
    /// @todo Implement json report
    static xtd::ustring to_json() noexcept;
    /// @brief Generates json format string report.
    /// @param reports A bitwise combination of the xtd::system_report::reports values.
    /// @return An json format string report.
    /// @todo Implement json report
    static xtd::ustring to_json(reports reports) noexcept;
    /// @brief Generates string report.
    /// @return A string report.
    static xtd::ustring to_string() noexcept;
    /// @brief Generates string report.
    /// @param reports A bitwise combination of the xtd::system_report::reports values.
    /// @return A string report.
    static xtd::ustring to_string(reports reports) noexcept;
    /// @brief Generates xml format string report.
    /// @return An xml format string report.
    /// @todo Implement xml report
    static xtd::ustring to_xml() noexcept;
    /// @brief Generates xml format string report.
    /// @param reports A bitwise combination of the xtd::system_report::reports values.
    /// @return An xml format string report.
    /// @todo Implement xml report
    static xtd::ustring to_xml(reports reports) noexcept;
    /// @}
  };
}

/// @cond
flags_attribute_(xtd, system_report::reports);

template<> struct xtd::enum_register<xtd::system_report::reports> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::system_report::reports> {{xtd::system_report::reports::stack_trace, "stack_trace"}, {xtd::system_report::reports::libraries, "libraries"}, {xtd::system_report::reports::processor, "processor"}, {xtd::system_report::reports::operating_system, "operating_system"}, {xtd::system_report::reports::compiler, "compiler"}, {xtd::system_report::reports::language, "language"}, {xtd::system_report::reports::locale, "locale"}, {xtd::system_report::reports::toolkit, "toolkit"}, {xtd::system_report::reports::environment_variables, "environment_variables"}, {xtd::system_report::reports::special_folders, "special_folders"}, {xtd::system_report::reports::system_colors, "system_colors"}, {xtd::system_report::reports::generic_font_families, "generic_font_families"}, {xtd::system_report::reports::system_fonts, "system_fonts"}, {xtd::system_report::reports::screens, "screens"}, {xtd::system_report::reports::system_informations, "system_informations"}};}
};
/// @endcond
