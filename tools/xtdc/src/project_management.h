#pragma once
#include <map>
#include <xtd/argument_exception>
#include <xtd/bit_converter>
#include <xtd/action>
#include <xtd/console>
#include <xtd/diagnostics/process>

#include "blank_solution_project.h"
#include "c_console_project.h"
#include "c_shared_library_project.h"
#include "c_static_library_project.h"
#include "catch2_unit_test_application_project.h"
#include "cocoa_gui_project.h"
#include "cpp_console_project.h"
#include "cpp_shared_library_project.h"
#include "cpp_static_library_project.h"
#include "csharp_console_project.h"
#include "csharp_shared_library_project.h"
#include "csharp_static_library_project.h"
#include "fltk_gui_project.h"
#include "gtest_unit_test_application_project.h"
#include "gtk2_gui_project.h"
#include "gtk3_gui_project.h"
#include "gtk4_gui_project.h"
#include "gtkmm_gui_project.h"
#include "qt5_gui_project.h"
#include "qt6_gui_project.h"
#include "objectivec_console_project.h"
#include "objectivec_shared_library_project.h"
#include "objectivec_static_library_project.h"
#include "project_language.h"
#include "project_sdk.h"
#include "project_type.h"
#include "win32_gui_project.h"
#include "winforms_gui_project.h"
#include "wpf_gui_project.h"
#include "wxwidgets_gui_project.h"
#include "xtd_blank_solution_project.h"
#include "xtd_c_blank_solution_project.h"
#include "xtd_c_console_project.h"
#include "xtd_c_gui_project.h"
#include "xtd_c_shared_library_project.h"
#include "xtd_c_static_library_project.h"
#include "xtd_c_unit_test_application_project.h"
#include "xtd_console_project.h"
#include "xtd_gui_project.h"
#include "xtd_shared_library_project.h"
#include "xtd_static_library_project.h"
#include "xtd_unit_test_application_project.h"

namespace xtdc_command {
  class project_management {
    class change_current_directory {
    public:
      change_current_directory(const xtd::ustring& current_directory) {
        if (!xtd::io::directory::exists(current_directory)) xtd::io::directory::create_directory(current_directory);
        xtd::environment::current_directory(current_directory);
      }
      ~change_current_directory() {xtd::environment::current_directory(previous_current_directoy_);}
    private:
      xtd::ustring previous_current_directoy_ = xtd::environment::current_directory();
    };
    
  public:
    explicit project_management(const xtd::ustring& output) : path_(output.c_str()) {}
    
    static std::vector<project_sdk> get_valid_sdks(project_type type) {
      switch (type) {
        case project_type::unknown: return {project_sdk::none};
        case project_type::blank_solution: return {project_sdk::xtd, project_sdk::xtd_c};
        case project_type::console: return {project_sdk::none, project_sdk::xtd, project_sdk::xtd_c};
        case project_type::gui: return {project_sdk::cocoa, project_sdk::fltk, project_sdk::gtk2, project_sdk::gtk3, project_sdk::gtk4, project_sdk::gtkmm, project_sdk::qt5, project_sdk::qt6, project_sdk::win32, project_sdk::winforms, project_sdk::wpf, project_sdk::wxwidgets, project_sdk::xtd, project_sdk::xtd_c};
        case project_type::shared_library: return {project_sdk::none, project_sdk::xtd, project_sdk::xtd_c};
        case project_type::static_library: return {project_sdk::none, project_sdk::xtd, project_sdk::xtd_c};
        case project_type::unit_test_application: return {project_sdk::catch2, project_sdk::gtest, project_sdk::xtd, project_sdk::xtd_c};
      }
      throw xtd::argument_exception("type is not project_type valid value", current_stack_frame_);
    }
    
    static std::vector<project_language> get_valid_languages(project_sdk sdk) {
      switch (sdk) {
        case project_sdk::none: return {project_language::cpp, project_language::c, project_language::objectivec, project_language::csharp};
        case project_sdk::catch2: return {project_language::c, project_language::cpp};
        case project_sdk::cocoa: return {project_language::objectivec};
        case project_sdk::fltk: return {project_language::cpp};
        case project_sdk::gtest: return {project_language::c, project_language::cpp};
        case project_sdk::gtk2: return {project_language::c, project_language::cpp};
        case project_sdk::gtk3: return {project_language::c, project_language::cpp};
        case project_sdk::gtk4: return {project_language::c, project_language::cpp};
        case project_sdk::gtkmm: return {project_language::cpp};
        case project_sdk::qt5: return {project_language::cpp};
        case project_sdk::qt6: return {project_language::cpp};
        case project_sdk::win32: return {project_language::c, project_language::cpp};
        case project_sdk::winforms: return {project_language::csharp};
        case project_sdk::wpf: return {project_language::csharp};
        case project_sdk::wxwidgets: return {project_language::cpp};
        case project_sdk::xtd: return {project_language::cpp};
        case project_sdk::xtd_c: return {project_language::c};
      }
      throw xtd::argument_exception("sdk is not project_sdk valid value", current_stack_frame_);
    }
    
    xtd::ustring add(const xtd::ustring& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! Add project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Add project aborted.";
      if (is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} already exists and not empty! Add project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Add project aborted.";
      if (!xtd::io::file::exists(xtd::io::path::combine(xtd::io::directory::get_parent(path_).full_name(), "CMakeLists.txt"))) return xtd::ustring::format("Parent directory \"{}\", is not a known project! Add project aborted.", xtd::io::directory::get_parent(path_).full_name());
      auto lines  = xtd::io::file::read_all_lines(xtd::io::path::combine(xtd::io::directory::get_parent(path_).full_name(), "CMakeLists.txt"));
      if (std::find_if(lines.begin(), lines.end(), [](const xtd::ustring & value) {return value.contains("find_package(xtd");}) != lines.end() && sdk != project_sdk::xtd) return "The sdk param not valid with current project sdk! Add project aborted.";
      if (std::find_if(lines.begin(), lines.end(), [](const xtd::ustring & value) {return value.contains("find_package(xtd");}) == lines.end() && sdk == project_sdk::xtd) return "The sdk param not valid with current project sdk! Add project aborted.";
      
      lines.push_back(xtd::ustring::format("{}({})", std::find_if(lines.begin(), lines.end(), [](const xtd::ustring & value) {return value.contains("find_package(xtd");}) != lines.end() ? "add_projects" : "add_subdirectory", xtd::io::path::get_file_name(path_)));
      std::map<project_type, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {
        {project_type::blank_solution, {*this, &project_management::create_blank_solution}},
        {project_type::console, {*this, &project_management::create_console}},
        {project_type::gui, {*this, &project_management::create_gui}},
        {project_type::shared_library, {*this, &project_management::create_shared_library}},
        {project_type::static_library, {*this, &project_management::create_static_library}},
        {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}
      } [type](name, sdk, language, false);
      path_ = xtd::io::directory::get_parent(path_).full_name();
      xtd::io::file::write_all_lines(xtd::io::path::combine(path_, "CMakeLists.txt"), lines);
      generate_project(name);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Add project aborted.";
      return xtd::ustring::format("{0}Project {1} added{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring build(const xtd::ustring& target, bool clean_first, bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Build project aborted.", path_);
      if (clean_first) clean(release);
      else generate_project();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Build project aborted.";
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      if (xtd::environment::os_version().is_windows_platform())
        launch_and_wait_process("cmake", xtd::ustring::format("--build {} --parallel {} --config {}{}{}", build_path(), xtd::environment::processor_count(), (release ? "Release" : "Debug"), target.empty() ? "" : xtd::ustring::format(" --target {}", target), clean_first ? xtd::ustring::format(" --clean-first {}", target) : ""), false);
      else if (xtd::environment::os_version().is_macos_platform())
        launch_and_wait_process("cmake", xtd::ustring::format("--build {} --parallel {} --config {}{}{}", build_path(), xtd::environment::processor_count(), (release ? "Release" : "Debug"), target.empty() ? "" : xtd::ustring::format(" --target {}", target), clean_first ? xtd::ustring::format(" --clean-first {}", target) : ""), true);
      else
        launch_and_wait_process("cmake", xtd::ustring::format("--build {}{}", xtd::io::path::combine(build_path(), release ? "Release" : "Debug"), target.empty() ? "" : xtd::ustring::format(" --target {}", target), clean_first ? " --clean-first {}" : ""));
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Build project aborted.";
      return xtd::ustring::format("{0}Project {1} builded{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring clean(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Clean project aborted.", path_);
      auto build_path = xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(this->build_path(), release ? "Release" : "Debug") : this->build_path();
      if (xtd::io::directory::exists(build_path)) xtd::io::directory::remove(build_path, true);
      generate_project();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Clean project aborted.";
      return xtd::ustring::format("{0}Project {1} cleaned{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring create(const xtd::ustring& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! Create project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Create project aborted.";
      if (is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} already exists and not empty! Create project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Create project aborted.";
      xtd::io::directory::create_directory(xtd::io::path::combine(path_, "build"));
      create_doxygen_txt(name);
      create_readme_md(name);
      std::map<project_type, xtd::action<const xtd::ustring&, project_sdk, project_language, bool>> {
        {project_type::blank_solution, {*this, &project_management::create_blank_solution}},
        {project_type::console, {*this, &project_management::create_console}},
        {project_type::gui, {*this, &project_management::create_gui}},
        {project_type::shared_library, {*this, &project_management::create_shared_library}},
        {project_type::static_library, {*this, &project_management::create_static_library}},
        {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}
      } [type](name, sdk, language, true);
      generate_project(name);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Create project aborted.";
      return xtd::ustring::format("{0}Project {1} created{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring generate(const xtd::ustring& name, project_type type, project_sdk sdk, project_language language) const {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) return "The sdk param not valid with type param! GenertaeGenertae project aborted.";
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) return "The language param not valid with sdk param! Genertae project aborted.";
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Genertae project aborted.", path_);
      if (sdk == project_sdk::qt5 && xtd::environment::get_environment_variable("CMAKE_PREFIX_PATH").empty()) return "Set your CMAKE_PREFIX_PATH environment variable to the Qt 5 installation prefix! Genertae project aborted.";
      xtd::io::directory::create_directory(xtd::io::path::combine(path_, "build"));
      create_doxygen_txt(name);
      create_readme_md(name);
      std::map<project_type, xtd::action<const xtd::ustring&, project_sdk, project_language>> {
        {project_type::blank_solution, {*this, &project_management::generate_blank_solution}},
        {project_type::console, {*this, &project_management::generate_console}},
        {project_type::gui, {*this, &project_management::generate_gui}},
        {project_type::shared_library, {*this, &project_management::generate_shared_library}},
        {project_type::static_library, {*this, &project_management::generate_static_library}},
        {project_type::unit_test_application, {*this, &project_management::generate_unit_test_application}}
      } [type](name, sdk, language);
      generate_project(name);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Create project aborted.";
      return xtd::ustring::format("{0}Project {1} created{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring install(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Install project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      build("install", false, release);
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Install project aborted.";
      return xtd::ustring::format("{0}Project {1} installed{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring open(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Open project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      generate_project();
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Open project aborted.";
      if (xtd::environment::os_version().is_windows_platform()) launch_and_wait_process(xtd::ustring::format("{}.sln", xtd::io::path::combine(build_path(), get_name())), true);
      else if (xtd::environment::os_version().is_macos_platform()) launch_and_wait_process(xtd::ustring::format("{}.xcodeproj", xtd::io::path::combine(build_path(), get_name())), true);
      else launch_and_wait_process(xtd::ustring::format("{}.cbp", xtd::io::path::combine(build_path(), release ? "Release" : "Debug", get_name())), true);
      return xtd::ustring::format("{0}Project {1} opened{0}", xtd::environment::new_line(), get_name());
    }
    
    xtd::ustring update(const xtd::ustring& target) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Update project aborted.", path_);
      change_current_directory current_directory {build_path()};
      generate_project(target);
      if (last_exit_code() != EXIT_SUCCESS) return "Generation error! Update project aborted.";
      return xtd::ustring::format("{0}Project {1} updated{0}", xtd::environment::new_line(), get_name());
    }
    
    xtd::ustring run(const xtd::ustring& target, bool release, bool wait_process) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Run project aborted.", path_);
      build(target, false, release);
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Run project aborted.";
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      auto target_path = target.empty() ? get_first_target_path(release) : get_target_path(target, release);
      if (target_path.empty()) return "The target does not exist! Run project aborted.";
      
      xtd::console::clear();
      xtd::diagnostics::process process;
      process.start_info(xtd::diagnostics::process_start_info(target_path));
      process.start_info().use_shell_execute(is_gui(target_path));
      process.start();
      if (wait_process) process.wait_for_exit();
      return "";
    }
    
    std::vector<xtd::ustring>& targets() const {
      static std::vector<xtd::ustring> targets;
      if (targets.size() == 0)
        for (const auto& line : get_system_information())
          if (line.index_of("_BINARY_DIR:STATIC=") != xtd::ustring::npos)
            targets.push_back(line.substring(0, line.index_of("_BINARY_DIR:STATIC=")));
      return targets;
    }
    
    xtd::ustring test(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Test project aborted.", path_);
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      build("", false, release);
      if (last_exit_code() != EXIT_SUCCESS) return "Build error! Test project aborted.";
      launch_and_wait_process("ctest", xtd::ustring::format("--output-on-failure --build-config {}", release ? "release" : "debug"));
      return xtd::ustring::format("{0}Project {1} tested{0}", xtd::environment::new_line(), path_);
    }
    
    xtd::ustring uninstall(bool release) const {
      if (!is_path_already_exist_and_not_empty(path_)) return xtd::ustring::format("Path {} does not exists or is empty! Uninstall project aborted.", path_);
      if (!xtd::io::file::exists(xtd::io::path::combine(xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path(), "install_manifest.txt"))) return xtd::ustring::format("File {} does not exists! Uninstall project aborted.", xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : xtd::io::path::combine(build_path(), "install_manifest.txt"));
      change_current_directory current_directory {xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()};
      
      for (auto system_file : xtd::io::file::read_all_lines(xtd::io::path::combine((xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path()), "install_manifest.txt"))) {
        if (xtd::io::directory::exists(system_file)) xtd::io::directory::remove(system_file, true);
        else if (xtd::io::file::exists(system_file)) {
          if (xtd::environment::os_version().is_macos_platform() && system_file.contains("Contents/MacOS")) xtd::io::directory::remove(system_file.remove(system_file.index_of("Contents/MacOS")), true);
          else xtd::io::file::remove(system_file);
        }
      }
      
      xtd::io::file::remove(xtd::io::path::combine(xtd::environment::os_version().is_unix_platform() ? xtd::io::path::combine(build_path(), release ? "Release" : "Debug") : build_path(), "install_manifest.txt"));
      return xtd::ustring::format("{0}Project {1} uninstalled{0}", xtd::environment::new_line(), path_);
    }
    
  private:
    xtd::ustring& get_name() const {
      static xtd::ustring name;
      if (name.empty()) {
        for (const auto& line : get_system_information()) {
          if (line.starts_with("CMAKE_PROJECT_NAME:STATIC=")) {
            name = line.replace("CMAKE_PROJECT_NAME:STATIC=", "");
            break;
          }
        }
      }
      if (name.empty()) name = xtd::io::path::get_file_name(path_);
      return name;
    }
    
    xtd::ustring get_target_path(const xtd::ustring& target, bool release) const {
      for (const auto& line : get_system_information())
        if (line.starts_with(xtd::ustring::format("{}_BINARY_DIR:STATIC=", target)))
          return make_platform_target_path(line.replace(xtd::ustring::format("{}_BINARY_DIR:STATIC=", target), ""), target, release);
      return xtd::io::path::combine(build_path(), release ? "Release" : "Debug", target, target);
    }
    
    xtd::ustring get_first_target_path(bool release) const {
      for (const auto& line : get_system_information())
        if (line.index_of("_BINARY_DIR:STATIC=") != xtd::ustring::npos)
          return make_platform_target_path(line.replace(xtd::ustring::format("{}_BINARY_DIR:STATIC=", line.substring(0, line.index_of("_BINARY_DIR:STATIC="))), ""), line.substring(0, line.index_of("_BINARY_DIR:STATIC=")), release);
      if (xtd::environment::os_version().is_windows_platform()) return xtd::io::path::combine(build_path(), xtd::io::path::get_file_name(path_), release ? "Release" : "Debug", xtd::io::path::get_file_name(path_));
      return xtd::io::path::combine(build_path(), release ? "Release" : "Debug", xtd::io::path::get_file_name(path_), xtd::io::path::get_file_name(path_));
    }
    
    xtd::ustring make_platform_target_path(const xtd::ustring& path, const xtd::ustring& target, bool release) const {
      if (xtd::environment::os_version().is_windows_platform() && xtd::io::file::exists(xtd::io::path::combine(path, release ? "Release" : "Debug", xtd::ustring::format("{}.exe", target))))
        return xtd::io::path::combine(path, release ? "Release" : "Debug", xtd::ustring::format("{}.exe", target));
      else if (xtd::environment::os_version().is_macos_platform() && xtd::io::directory::exists(xtd::io::path::combine(path, release ? "Release" : "Debug", xtd::ustring::format("{}.app", target))))
        return xtd::io::path::combine(path, release ? "Release" : "Debug", xtd::ustring::format("{}.app", target));
      else if (xtd::environment::os_version().is_macos_platform() && xtd::io::file::exists(xtd::io::path::combine(path, release ? "Release" : "Debug", target)))
        return xtd::io::path::combine(path, release ? "Release" : "Debug", target);
      else if (xtd::environment::os_version().is_unix_platform() && xtd::io::file::exists(xtd::io::path::combine(path, target)))
        return xtd::io::path::combine(path, target);
      return "";
    }
    
    bool is_windows_gui_app(const xtd::ustring& path) const {
      if (!xtd::io::file::exists(path)) return false;
      auto bytes = xtd::io::file::read_all_bytes(path);
      // read PE Format : https://docs.microsoft.com/en-us/windows/win32/debug/pe-format
      if (bytes[0] != 'M' || bytes[1] != 'Z') return false;
      return xtd::bit_converter::to_uint16(bytes, xtd::bit_converter::to_uint16(bytes, 0x3C) + 92) == 2;
    }
    
    bool is_linux_gui_app(const xtd::ustring& path) const {
      if (!xtd::io::file::exists(path)) return false;
      auto config_file = xtd::io::path::combine({xtd::environment::get_folder_path(xtd::environment::special_folder::home), ".local", "share", "applications", xtd::ustring::format("{}.desktop", xtd::io::path::get_file_name(path))});
      if (!xtd::io::file::exists(config_file)) return false;
      auto lines = xtd::io::file::read_all_lines(config_file);
      for (auto line : lines)
        if (line.to_lower() == "terminael=false") return true;
      return false;
    }
    
    bool is_macos_gui_app(const xtd::ustring& path) const {
      return xtd::io::path::has_extension(path) && xtd::io::path::get_extension(path) == ".app";
    }
    
    bool is_gui(const xtd::ustring& path) const {
      if (xtd::environment::os_version().is_windows_platform()) return is_windows_gui_app(path);
      if (xtd::environment::os_version().is_macos_platform()) return is_macos_gui_app(path);
      return is_linux_gui_app(path);
    }
    
    std::vector<xtd::ustring>& get_system_information() const {
      static std::vector<xtd::ustring> system_information;
      static bool exception_throwed = false;
      if (!exception_throwed && system_information.size() == 0) {
        if (!xtd::io::file::exists(xtd::io::path::combine(build_path(), "xtd_si.txt"))) {
          change_current_directory current_directory {build_path()};
          try {
            launch_and_wait_process("cmake", "--system-information xtd_si.txt", xtd::environment::os_version().is_macos_platform());
          } catch (...) {
            exception_throwed = true;
          }
        }
        if (xtd::io::file::exists(xtd::io::path::combine(build_path(), "xtd_si.txt")))
          system_information = xtd::io::file::read_all_lines(xtd::io::path::combine(build_path(), "xtd_si.txt"));
      }
      return system_information;
    }
    
    xtd::ustring build_path() const {return xtd::io::path::combine(path_, "build");}
    xtd::int32 last_exit_code() const {return last_exit_code_;}
    
    void create_blank_solution(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) {
      std::map<project_sdk, xtd::action<const xtd::ustring&, bool>> {
        {project_sdk::none, {blank_solution_project {path_}, &blank_solution_project::create}},
        {project_sdk::xtd, {xtd_blank_solution_project {path_}, &xtd_blank_solution_project::create}},
        {project_sdk::xtd_c, {xtd_c_blank_solution_project {path_}, &xtd_c_blank_solution_project::create}}
      } [sdk](name, create_solution);
    }
    
    void create_console(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_console_project(path_).create(name, create_solution); break;
        case project_sdk::xtd_c: xtd_c_console_project(path_).create(name, create_solution); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&, bool>> {
            {project_language::c, {c_console_project {path_}, &c_console_project::create}},
            {project_language::cpp, {cpp_console_project {path_}, &cpp_console_project::create}},
            {project_language::csharp, {csharp_console_project {path_}, &csharp_console_project::create}},
            {project_language::objectivec, {objectivec_console_project {path_}, &objectivec_console_project::create}}
          } [language](name, create_solution); break;
      }
    }
    
    void create_gui(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&, bool>> {
        {project_sdk::cocoa, {cocoa_gui_project {path_}, &cocoa_gui_project::create}},
        {project_sdk::fltk, {fltk_gui_project {path_}, &fltk_gui_project::create}},
        {project_sdk::gtk2, {gtk2_gui_project {path_}, &gtk2_gui_project::create}},
        {project_sdk::gtk3, {gtk3_gui_project {path_}, &gtk3_gui_project::create}},
        {project_sdk::gtk4, {gtk4_gui_project {path_}, &gtk4_gui_project::create}},
        {project_sdk::gtkmm, {gtkmm_gui_project {path_}, &gtkmm_gui_project::create}},
        {project_sdk::qt5, {qt5_gui_project {path_}, &qt5_gui_project::create}},
        {project_sdk::qt6, {qt6_gui_project {path_}, &qt6_gui_project::create}},
        {project_sdk::win32, {win32_gui_project {path_}, &win32_gui_project::create}},
        {project_sdk::winforms, {winforms_gui_project {path_}, &winforms_gui_project::create}},
        {project_sdk::wpf, {wpf_gui_project {path_}, &wpf_gui_project::create}},
        {project_sdk::wxwidgets, {wxwidgets_gui_project {path_}, &wxwidgets_gui_project::create}},
        {project_sdk::xtd, {xtd_gui_project {path_}, &xtd_gui_project::create}},
        {project_sdk::xtd_c, {xtd_c_gui_project {path_}, &xtd_c_gui_project::create}}
      } [sdk](name, create_solution);
    }
    
    void create_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_shared_library_project(path_).create(name, create_solution); break;
        case project_sdk::xtd_c: xtd_c_shared_library_project(path_).create(name, create_solution); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&, bool>> {
            {project_language::c, {c_shared_library_project {path_}, &c_shared_library_project::create}},
            {project_language::cpp, {cpp_shared_library_project {path_}, &cpp_shared_library_project::create}},
            {project_language::csharp, {csharp_shared_library_project {path_}, &csharp_shared_library_project::create}},
            {project_language::objectivec, {objectivec_shared_library_project {path_}, &objectivec_shared_library_project::create}}
          } [language](name, create_solution); break;
      }
    }
    
    void create_static_library(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_static_library_project(path_).create(name, create_solution); break;
        case project_sdk::xtd_c: xtd_c_static_library_project(path_).create(name, create_solution); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&, bool>> {
            {project_language::c, {c_static_library_project {path_}, &c_static_library_project::create}},
            {project_language::cpp, {cpp_static_library_project {path_}, &cpp_static_library_project::create}},
            {project_language::csharp, {csharp_static_library_project {path_}, &csharp_static_library_project::create}},
            {project_language::objectivec, {objectivec_static_library_project {path_}, &objectivec_static_library_project::create}}
          } [language](name, create_solution); break;
      }
    }
    
    void create_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language, bool create_solution) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&, bool>> {
        {project_sdk::catch2, {catch2_unit_test_application_project {path_}, &catch2_unit_test_application_project::create}},
        {project_sdk::gtest, {gtest_unit_test_application_project {path_}, &gtest_unit_test_application_project::create}},
        {project_sdk::xtd, {xtd_unit_test_application_project {path_}, &xtd_unit_test_application_project::create}},
        {project_sdk::xtd_c, {xtd_c_unit_test_application_project {path_}, &xtd_c_unit_test_application_project::create}}
      } [sdk](name, create_solution);
    }
    
    void create_doxygen_txt(const xtd::ustring& name) const {
      xtd::io::file::write_all_text(xtd::io::path::combine(path_, ".doxygen.txt"), xtd::io::path::combine(xtd::environment::get_folder_path(xtd::environment::special_folder::xtd_resources), "texts", "doxygen.txt"));
    }
    
    void create_readme_md(const xtd::ustring& name) const {
      std::vector<xtd::ustring> lines {
        xtd::ustring::format("# {}", name),
      };
      xtd::io::file::write_all_lines(xtd::io::path::combine(path_, "README.md"), lines);
    }
    
    void generate_blank_solution(const xtd::ustring& name, project_sdk sdk, project_language language) {
      std::map<project_sdk, xtd::action<const xtd::ustring&>> {
        {project_sdk::none, {blank_solution_project {path_}, &blank_solution_project::generate}},
        {project_sdk::xtd, {xtd_blank_solution_project {path_}, &xtd_blank_solution_project::generate}},
        {project_sdk::xtd_c, {xtd_c_blank_solution_project {path_}, &xtd_c_blank_solution_project::generate}}
      } [sdk](name);
    }
    
    void generate_console(const xtd::ustring& name, project_sdk sdk, project_language language) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_console_project(path_).generate(name); break;
        case project_sdk::xtd_c: xtd_c_console_project(path_).generate(name); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&>> {
            {project_language::c, {c_console_project {path_}, &c_console_project::generate}},
            {project_language::cpp, {cpp_console_project {path_}, &cpp_console_project::generate}},
            {project_language::csharp, {csharp_console_project {path_}, &csharp_console_project::generate}},
            {project_language::objectivec, {objectivec_console_project {path_}, &objectivec_console_project::generate}}
          } [language](name); break;
      }
    }
    
    void generate_gui(const xtd::ustring& name, project_sdk sdk, project_language language) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&>> {
        {project_sdk::cocoa, {cocoa_gui_project {path_}, &cocoa_gui_project::generate}},
        {project_sdk::fltk, {fltk_gui_project {path_}, &fltk_gui_project::generate}},
        {project_sdk::gtk2, {gtk2_gui_project {path_}, &gtk2_gui_project::generate}},
        {project_sdk::gtk3, {gtk3_gui_project {path_}, &gtk3_gui_project::generate}},
        {project_sdk::gtk4, {gtk4_gui_project {path_}, &gtk4_gui_project::generate}},
        {project_sdk::gtkmm, {gtkmm_gui_project {path_}, &gtkmm_gui_project::generate}},
        {project_sdk::qt5, {qt5_gui_project {path_}, &qt5_gui_project::generate}},
        {project_sdk::qt6, {qt6_gui_project {path_}, &qt6_gui_project::generate}},
        {project_sdk::win32, {win32_gui_project {path_}, &win32_gui_project::generate}},
        {project_sdk::winforms, {winforms_gui_project {path_}, &winforms_gui_project::generate}},
        {project_sdk::wpf, {wpf_gui_project {path_}, &wpf_gui_project::generate}},
        {project_sdk::wxwidgets, {wxwidgets_gui_project {path_}, &wxwidgets_gui_project::generate}},
        {project_sdk::xtd, {xtd_gui_project {path_}, &xtd_gui_project::generate}},
        {project_sdk::xtd_c, {xtd_c_gui_project {path_}, &xtd_c_gui_project::generate}}
      } [sdk](name);
    }
    
    void generate_shared_library(const xtd::ustring& name, project_sdk sdk, project_language language) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_shared_library_project(path_).generate(name); break;
        case project_sdk::xtd_c: xtd_c_shared_library_project(path_).generate(name); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&>> {
            {project_language::c, {c_shared_library_project {path_}, &c_shared_library_project::generate}},
            {project_language::cpp, {cpp_shared_library_project {path_}, &cpp_shared_library_project::generate}},
            {project_language::csharp, {csharp_shared_library_project {path_}, &csharp_shared_library_project::generate}},
            {project_language::objectivec, {objectivec_shared_library_project {path_}, &objectivec_shared_library_project::generate}}
          } [language](name); break;
      }
    }
    
    void generate_static_library(const xtd::ustring& name, project_sdk sdk, project_language language) const {
      switch (sdk) {
        case project_sdk::xtd: xtd_static_library_project(path_).generate(name); break;
        case project_sdk::xtd_c: xtd_c_static_library_project(path_).generate(name); break;
        default: std::map<project_language, xtd::action<const xtd::ustring&>> {
            {project_language::c, {c_static_library_project {path_}, &c_static_library_project::generate}},
            {project_language::cpp, {cpp_static_library_project {path_}, &cpp_static_library_project::generate}},
            {project_language::csharp, {csharp_static_library_project {path_}, &csharp_static_library_project::generate}},
            {project_language::objectivec, {objectivec_static_library_project {path_}, &objectivec_static_library_project::generate}}
          } [language](name); break;
      }
    }
    
    void generate_unit_test_application(const xtd::ustring& name, project_sdk sdk, project_language language) const {
      std::map<project_sdk, xtd::action<const xtd::ustring&>> {
        {project_sdk::catch2, {catch2_unit_test_application_project {path_}, &catch2_unit_test_application_project::generate}},
        {project_sdk::gtest, {gtest_unit_test_application_project {path_}, &gtest_unit_test_application_project::generate}},
        {project_sdk::xtd, {xtd_unit_test_application_project {path_}, &xtd_unit_test_application_project::generate}},
        {project_sdk::xtd_c, {xtd_c_unit_test_application_project {path_}, &xtd_c_unit_test_application_project::generate}}
      } [sdk](name);
    }
    
    void generate_project() const {generate_project(xtd::io::path::get_file_name(path_));}
    
    void generate_project(xtd::ustring name) const {
      bool first_generation = !xtd::io::directory::exists(build_path());
      xtd::io::directory::create_directory(build_path());
      change_current_directory current_directory {build_path()};
      if (!first_generation && name.empty()) name = get_name();
      if (xtd::environment::os_version().is_windows_platform() && (first_generation || !xtd::io::file::exists(xtd::io::path::combine(build_path(), xtd::ustring::format("{}.sln", name)))))
        launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {}", path_, build_path()));
      else if (xtd::environment::os_version().is_macos_platform() && (first_generation || !xtd::io::directory::exists(xtd::io::path::combine(build_path(), xtd::ustring::format("{}.xcodeproj", name)))))
        launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"Xcode\"", path_, build_path()), true);
      else if (xtd::environment::os_version().is_unix_platform()) {
        if (first_generation || !xtd::io::file::exists(xtd::io::path::combine(build_path(), "Debug", xtd::ustring::format("{}.cbp", name)))) {
          change_current_directory current_directory_debug {xtd::io::path::combine(build_path(), "Debug")};
          xtd::io::directory::create_directory(xtd::io::path::combine(build_path(), "Debug"));
          launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, xtd::io::path::combine(build_path(), "Debug")));
          patch_cbp_file(name, "Debug");
        }
        if (first_generation || !xtd::io::file::exists(xtd::io::path::combine(build_path(), "Release", xtd::ustring::format("{}.cbp", name)))) {
          change_current_directory current_directory_release {xtd::io::path::combine(build_path(), "Release")};
          xtd::io::directory::create_directory(xtd::io::path::combine(build_path(), "Release"));
          launch_and_wait_process("cmake", xtd::ustring::format("-S {} -B {} -G \"CodeBlocks - Unix Makefiles\"", path_, xtd::io::path::combine(build_path(), "Release")));
          patch_cbp_file(name, "Release");
        }
      }
    }
    
    bool is_path_already_exist_and_not_empty(const xtd::ustring& path) const {
      if (!xtd::io::directory::exists(path_)) return false;
      if (xtd::io::directory::get_file_system_entries(path_).size() == 0) return false;
      if (xtd::environment::os_version().is_macos_platform() && xtd::io::directory::get_file_system_entries(path_).size() == 1 && xtd::io::directory::get_file_system_entries(path_, ".DS_Store").size() == 1) return false;
      return true;
    }
    
    void launch_and_wait_process(const xtd::ustring& file_name) const {launch_and_wait_process(file_name, false);}
    void launch_and_wait_process(const xtd::ustring& file_name, bool shell_execute) const {launch_and_wait_process(file_name, "", shell_execute);}
    void launch_and_wait_process(const xtd::ustring& file_name, const xtd::ustring& arguments) const {launch_and_wait_process(file_name, arguments, false);}
    void launch_and_wait_process(const xtd::ustring& file_name, const xtd::ustring& arguments, bool shell_execute) const {
      xtd::diagnostics::process process;
      process.start_info({file_name, arguments});
      process.start_info().use_shell_execute(shell_execute);
      process.start();
      process.wait_for_exit();
      last_exit_code_ = process.exit_code();
    }
    
    void patch_cbp_file(const xtd::ustring& name, const xtd::ustring& build_config) const {
      if (xtd::io::file::read_all_text(xtd::io::file::exists(xtd::io::path::combine(path_, name, "CMakeLists.txt")) ? xtd::io::path::combine(path_, name, "CMakeLists.txt") : xtd::io::path::combine(path_, "CMakeLists.txt")).contains("GUI_APPLICATION")) {
        auto cbp_file_lines = xtd::io::file::read_all_lines(xtd::io::path::combine(build_path(), build_config, xtd::ustring::format("{}.cbp", name)));
        for (auto iterator = std::find(cbp_file_lines.begin(), cbp_file_lines.end(), xtd::ustring::format("\t\t\t<Target title=\"{}\">", name)); iterator != cbp_file_lines.end(); ++iterator) {
          if (*iterator == "\t\t\t\t<Option type=\"1\"/>") {
            *iterator = "\t\t\t\t<Option type=\"0\"/>";
            break;
          }
        }
        xtd::io::file::write_all_lines(xtd::io::path::combine(build_path(), build_config, xtd::ustring::format("{}.cbp", name)), cbp_file_lines);
      }
    }
    
    mutable xtd::ustring path_ = xtd::environment::current_directory();
    mutable xtd::int32 last_exit_code_ = EXIT_SUCCESS;
  };
}
