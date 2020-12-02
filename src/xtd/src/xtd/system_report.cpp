#include "../../include/xtd/system_report.h"
#include <xtd/environment.h>
#include <xtd/io/path.h>

using namespace std;
using namespace xtd;

namespace {
  static constexpr int32_t default_size_indent = 2;
  
  string indent_string(int32_t indent, int32_t size_indent) {
    return std::string(indent * size_indent, ' ');
  }
  
  string indent_string(int32_t indent) {
    return indent_string(indent, default_size_indent);
  }
    
  string generate_stack_trace_string_report(int32_t indent) {
    std::string report = strings::format("{}Stack trace{}", indent_string(indent), environment::new_line());
    auto stack_trace = system_report::stack_trace();
    for (auto frame : stack_trace.frames())
      report += strings::format("{}{}{}", indent_string(indent +1), frame, environment::new_line());
    return report + environment::new_line();
  }

  string generate_libraries_string_report(int32_t indent) {
    std::string report = strings::format("{}xtd libraries{}", indent_string(indent), environment::new_line());
    for (auto library : system_report::xtd_libraries()) {
      report += strings::format("{}{}{}", indent_string(indent + 1), library.name(), environment::new_line());
      report += strings::format("{}Version: {}{}", indent_string(indent + 2), library.version(), environment::new_line());
      report += strings::format("{}include path: {}{}", indent_string(indent + 2), library.include_path(), environment::new_line());
      report += strings::format("{}library path: {}{}", indent_string(indent + 2), library.library_path(), environment::new_line());
      report += strings::format("{}resources path: {}{}", indent_string(indent + 2), library.resources_path(), environment::new_line());
    }
    return report + environment::new_line();
  }
  
  string generate_processor_string_report(int32_t indent) {
    std::string report = strings::format("{}Processor{}", indent_string(indent), environment::new_line());
    auto processor = system_report::processor();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), processor.name(), environment::new_line());
    report += strings::format("{}Architecture: {}{}", indent_string(indent + 1), processor.architecture_string(), environment::new_line());
    report += strings::format("{}Core count: {}{}", indent_string(indent + 1), processor.core_count(), environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), processor.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_operating_system_string_report(int32_t indent) {
    std::string report = strings::format("{}Operating System{}", indent_string(indent), environment::new_line());
    auto operating_system = system_report::operating_system();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), operating_system.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), operating_system.version(), environment::new_line());
    report += strings::format("{}Service pack: {}{}", indent_string(indent + 1), operating_system.service_pack(), environment::new_line());
    report += strings::format("{}Desktop environment: {}{}", indent_string(indent + 1), operating_system.desktop_environment(), environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), operating_system.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_compiler_string_report(int32_t indent) {
    std::string report = strings::format("{}Compiler{}", indent_string(indent), environment::new_line());
    auto compiler = system_report::compiler();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), compiler.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), compiler.version(), environment::new_line());
    report += strings::format("{}Mode: {}{}", indent_string(indent + 1), compiler.is_build_type_debug() ? "Debug" : "Release", environment::new_line());
    report += strings::format("{}64 bit: {}{}", indent_string(indent + 1), compiler.is_64_bit(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_language_string_report(int32_t indent) {
    std::string report = strings::format("{}Language{}", indent_string(indent), environment::new_line());
    auto language = system_report::language();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), language.name(), environment::new_line());
    report += strings::format("{}Version: {}{}", indent_string(indent + 1), language.version(), environment::new_line());
    report += strings::format("{}Experimental: {}{}", indent_string(indent + 1), language.is_experimental_language(), environment::new_line());
    report += strings::format("{}Supported: {}{}", indent_string(indent + 1), language.is_supported(), environment::new_line());
    return report + environment::new_line();
  }
  
  string generate_locale_string_report(int32_t indent) {
    std::string report = strings::format("{}Locale{}", indent_string(indent), environment::new_line());
    auto locale = system_report::locale();
    report += strings::format("{}Name: {}{}", indent_string(indent + 1), locale.name(), environment::new_line());
    return report + environment::new_line();
  }

  string generate_environment_variables_string_report(int32_t indent) {
    std::string report = strings::format("{}Environment variables{}", indent_string(indent), environment::new_line());
    for (auto environment_variable : system_report::environment_variables())
      report += strings::format("{}{}={}{}", indent_string(indent + 1), environment_variable.first, environment_variable.second, environment::new_line());
    return report + environment::new_line();
  }

  string generate_special_folders_string_report(int32_t indent) {
    std::string report = strings::format("{}Special folders{}", indent_string(indent), environment::new_line());
    for (auto special_folder : system_report::special_folders())
      report += strings::format("{}{}={}{}", indent_string(indent + 1), special_folder.first, special_folder.second, environment::new_line());
    return report + environment::new_line();
  }
}

xtd::system_report::xtd_library_collection system_report::xtd_libraries() noexcept {
  return {
    {"xtd.core", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")},
    {"xtd.drawing", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")},
    {"xtd.forms", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")},
    {"xtd.tunit", environment::version(), xtd::io::path::combine(__XTD_INSTALL_PATH__, "include"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "lib"), xtd::io::path::combine(__XTD_INSTALL_PATH__, "share", "xtd", "resources")},
  };
}

system_report::environment_variable_collection system_report::environment_variables() noexcept {
  environment_variable_collection environment_variables;
  for (auto environment_variable : xtd::environment::get_environment_variables())
    environment_variables.push_back(environment_variable);
  return environment_variables;
}

system_report::special_folder_collection system_report::special_folders() noexcept {
  static map<environment::special_folder, std::string> folders {{environment::special_folder::desktop, "desktop"}, {environment::special_folder::programs, "programs"}, {environment::special_folder::my_documents, "my_documents"}, {environment::special_folder::personal, "personal"}, {environment::special_folder::favorites, "favorites"}, {environment::special_folder::startup, "startup"}, {environment::special_folder::recent, "recent"}, {environment::special_folder::send_to, "send_to"}, {environment::special_folder::start_menu, "start_menu"}, {environment::special_folder::my_music, "my_music"}, {environment::special_folder::my_videos, "my_videos"}, {environment::special_folder::desktop_directory, "desktop_directory"}, {environment::special_folder::my_computer, "my_computer"}, {environment::special_folder::network_shortcuts, "network_shortcuts"}, {environment::special_folder::fonts, "fonts"}, {environment::special_folder::templates, "templates"}, {environment::special_folder::common_start_menu, "common_start_menu"}, {environment::special_folder::common_programs, "common_programs"}, {environment::special_folder::common_startup, "common_startup"}, {environment::special_folder::common_desktop_directory, "common_desktop_directory"}, {environment::special_folder::application_data, "application_data"}, {environment::special_folder::printer_shortcuts, "printer_shortcuts"}, {environment::special_folder::local_application_data, "local_application_data"}, {environment::special_folder::internet_cache, "internet_cache"}, {environment::special_folder::cookies, "cookies"}, {environment::special_folder::history, "history"}, {environment::special_folder::common_application_data, "common_application_data"}, {environment::special_folder::windows, "windows"}, {environment::special_folder::system, "system"}, {environment::special_folder::program_files, "program_files"}, {environment::special_folder::my_pictures, "my_pictures"}, {environment::special_folder::user_profile, "user_profile"}, {environment::special_folder::system_x86, "system_x86"}, {environment::special_folder::program_files_x86, "program_files_x86"}, {environment::special_folder::common_program_files, "common_program_files"}, {environment::special_folder::common_program_files_x86, "common_program_files_x86"}, {environment::special_folder::common_templates, "common_templates"}, {environment::special_folder::common_documents, "common_documents"}, {environment::special_folder::common_admin_tools, "common_admin_tools"}, {environment::special_folder::admin_tools, "admin_tools"}, {environment::special_folder::common_music, "common_music"}, {environment::special_folder::common_pictures, "common_pictures"}, {environment::special_folder::common_videos, "common_videos"}, {environment::special_folder::resources, "resources"}, {environment::special_folder::localized_resources, "localized_resources"}, {environment::special_folder::common_oem_links, "common_oem_links"}, {environment::special_folder::cd_burning, "cd_burning"}, {environment::special_folder::home, "home"},};
  special_folder_collection special_folders;
  for (auto folder : folders)
    special_folders.push_back({folder.second, environment::get_folder_path(folder.first)});
  return special_folders;
}

string system_report::to_string() noexcept {
  int32_t indent = 0;
  string report;
  report += generate_stack_trace_string_report(indent);
  report += generate_libraries_string_report(indent);
  report += generate_processor_string_report(indent);
  report += generate_operating_system_string_report(indent);
  report += generate_compiler_string_report(indent);
  report += generate_language_string_report(indent);
  report += generate_locale_string_report(indent);
  report += generate_environment_variables_string_report(indent);
  report += generate_special_folders_string_report(indent);
  return report;
}

string system_report::to_xml() noexcept {
  return "";
}
