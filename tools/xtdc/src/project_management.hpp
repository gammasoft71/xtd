#pragma once
#include <iostream>
#include <filesystem>
#include <map>
#include <string>
#include <vector>
#include <xtd/environment.hpp>
#include <xtd/action.hpp>
#include <xtd/path.hpp>
#include <xtd/strings.hpp>

#include "project_language.hpp"
#include "project_sdk.hpp"
#include "project_type.hpp"

namespace xtdc_command {
  class project_management {
  public:
    project_management() {}
    explicit project_management(const std::string& name) : name_(name) {}
    project_management(const std::string& name, project_type type) : name_(name), type_(type) {}
    project_management(const std::string& name, project_type type, project_sdk sdk, project_language language, const std::string& output) : name_(name), type_(type), sdk_(sdk), language_(language), output_(output) {
      auto sdks = get_valid_sdks(type);
      if (std::find(sdks.begin(), sdks.end(), sdk) == sdks.end()) throw std::invalid_argument("sdk not valid with type");
      auto languages = get_valid_languages(sdk);
      if (std::find(languages.begin(), languages.end(), language) == languages.end()) throw std::invalid_argument("language not valid with sdk");
    }

    static std::vector<project_sdk> get_valid_sdks(project_type type) {
      switch (type) {
        case project_type::blank_solution: return {project_sdk::xtd};
        case project_type::console: return {project_sdk::none, project_sdk::xtd};
        case project_type::gui: return {project_sdk::xtd, project_sdk::win32, project_sdk::gtk, project_sdk::cocoa, project_sdk::gtkmm, project_sdk::wxwidgets, project_sdk::qt5};
        case project_type::shared_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::static_library: return {project_sdk::none, project_sdk::xtd};
        case project_type::unit_test_application: return {project_sdk::xtd, project_sdk::gtest, project_sdk::catch2};
      }
      throw std::invalid_argument("type is not project_type valid value");
    }
    
    static std::vector<project_language> get_valid_languages(project_sdk sdk) {
      switch (sdk) {
        case project_sdk::none: return {project_language::cpp, project_language::c, project_language::objectivec};
        case project_sdk::xtd: return {project_language::cpp};
        case project_sdk::win32: return {project_language::c, project_language::cpp};
        case project_sdk::gtk: return {project_language::c, project_language::cpp};
        case project_sdk::cocoa: return {project_language::objectivec};
        case project_sdk::gtkmm: return {project_language::cpp};
        case project_sdk::wxwidgets: return {project_language::cpp};
        case project_sdk::qt5: return {project_language::cpp};
        case project_sdk::gtest: return {project_language::c, project_language::cpp};
        case project_sdk::catch2: return {project_language::c, project_language::cpp};
      }
      throw std::invalid_argument("sdk is not project_sdk valid value");
    }
    
    std::string create() {
      if (is_path_already_exist_and_not_empty(output_)) return xtd::strings::format("Path \"{0}\" already exists and not empty! CreateNewProject aborted.", output_);
      std::map<project_type, xtd::action<>> {{project_type::blank_solution, {*this, &project_management::create_blank_solution}}, {project_type::console, {*this, &project_management::create_console}}, {project_type::gui, {*this, &project_management::create_gui}}, {project_type::shared_library, {*this, &project_management::create_shared_library}}, {project_type::static_library, {*this, &project_management::create_static_library}}, {project_type::unit_test_application, {*this, &project_management::create_unit_test_application}}}[type_]();
      return xtd::strings::format("The {} {} project is created in {}", name_, to_string(type_), output_);
    }
    
    std::string generate() {
      return xtd::strings::format("Project {}generated", name_);
    }

    std::string to_string() const {return xtd::strings::format("{{name=\"{}\", type={}, sdk={}, language={}, output=\"{}\"}}", name_, to_string(type_), to_string(sdk_), to_string(language_), output_);}

  private:
    void create_blank_solution() {
      std::cout << "() Generate " << to_string() << std::endl << std::endl;
      //create_doxygen_txt();
      //create_blank_solution_cmakelists_txt();
    }
    
    void create_console() {
      std::cout << "(create_console) Generate " << to_string() << std::endl << std::endl;
    }
    
    void create_gui() {
      std::cout << "(create_gui) Generate " << to_string() << std::endl << std::endl;
    }
    
    void create_shared_library() {
      std::cout << "(create_shared_library) Generate " << to_string() << std::endl << std::endl;
    }
    
    void create_static_library() {
      std::cout << "(create_static_library) Generate " << to_string() << std::endl << std::endl;
    }
    
    void create_unit_test_application() {
      std::cout << "(create_unit_test_application) Generate " << to_string() << std::endl << std::endl;
    }
    
    bool is_path_already_exist_and_not_empty(const std::string& path) {
      if (!std::filesystem::exists({output_})) return false;
      if (std::filesystem::is_empty({output_})) return false;
      if (xtd::environment::os_version().is_osx_platform() && std::count_if(std::filesystem::directory_iterator({output_}), std::filesystem::directory_iterator(), static_cast<bool(*)(const std::filesystem::path&)>(std::filesystem::is_regular_file)) == 1 && (*std::filesystem::directory_iterator({output_})).path().filename().string() == ".DS_Store") return false;
      return true;
    }
    
    static std::string to_string(project_type type) {return std::map<xtdc_command::project_type, std::string> {{xtdc_command::project_type::blank_solution, "blank_solution"}, {xtdc_command::project_type::gui, "gui"}, {xtdc_command::project_type::console, "console"}, {xtdc_command::project_type::shared_library, "shared_library"}, {xtdc_command::project_type::static_library, "static_library"}, {xtdc_command::project_type::unit_test_application, "unit_test_application"}}[type];}
    static std::string to_string(project_sdk sdk) {return std::map<xtdc_command::project_sdk, std::string> {{xtdc_command::project_sdk::none, "none"}, {xtdc_command::project_sdk::xtd, "xtd"}, {xtdc_command::project_sdk::win32, "win32"}, {xtdc_command::project_sdk::gtk, "gtk"}, {xtdc_command::project_sdk::cocoa, "cocoa"}, {xtdc_command::project_sdk::gtkmm, "gtkmm"}, {xtdc_command::project_sdk::wxwidgets, "wxwidgets"}, {xtdc_command::project_sdk::qt5, "qt5"}, {xtdc_command::project_sdk::gtest, "gtest"}, {xtdc_command::project_sdk::catch2, "catch2"}}[sdk];}
    static std::string to_string(project_language language) {return std::map<xtdc_command::project_language, std::string> {{xtdc_command::project_language::cpp, "cpp"}, {xtdc_command::project_language::c, "c"}, {xtdc_command::project_language::objectivec, "objectivec"}}[language];}
    std::string name_ = xtd::io::path::get_file_name_without_extension(xtd::environment::current_directory());
    project_type type_ = project_type::gui;
    project_sdk sdk_ = project_sdk::xtd;
    project_language language_ = project_language::cpp;
    std::string output_ = xtd::environment::current_directory();
  };
}
