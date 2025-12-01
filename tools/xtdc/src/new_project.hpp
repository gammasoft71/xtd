#include "project_base.hpp"
#include "project_language.hpp"
#include "project_management.hpp"
#include "project_sdk.hpp"
#include "project_type.hpp"
#include <xtd/collections/generic/dictionary>
#include <xtd/char_object>
#include <xtd/console>
#include <vector>

namespace xtdc_command {
  class new_project final : public project_base {
  public:
    static int execute(const xtd::array<xtd::string>& args) {
      auto show_help = false;
      xtd::string invalid_option;
      xtd::string type;
      xtd::string sdk;
      xtd::string name;
      xtd::string path;
      if (!process_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!xtd::string::is_empty(invalid_option))
          write_line_error(xtd::string::format("Unknown option: {0}", invalid_option));
        else
          write_line_error("Invalid parameters");
        xtd::console::write_line(xtd::string::join("\n", get_help()));
        return EXIT_FAILURE;
      }
      if (show_help) {
        xtd::console::write_line(xtd::string::join("\n", get_help()));
        return EXIT_SUCCESS;
      }
      
      if (xtd::string::is_empty(type)) type = "gui";
      if (xtd::string::is_empty(sdk)) sdk = "xtd";
      if (xtd::string::is_empty(name)) name = get_project_name_from_path(path);
      
      if (xtd::string::is_empty(name)) {
        xtd::console::write_line("The name is empty.");
        return EXIT_FAILURE;
      }
      if (name.first_or_default([](auto c) {return !(xtd::char_object::is_letter_or_digit(c) || c == '_');}) != 0) {
        write_line_error(xtd::string::format("The name : \"{}\" contains invalid charaters.", name));
        return EXIT_FAILURE;
      }
      if (name.length() > 128) {
        write_line_error("The size of the name is invalid, the size must be less than or equal to 128.");
        return EXIT_FAILURE;
      }
      
      auto project_type = xtd::collections::generic::dictionary<xtd::string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
      auto project_sdk = xtd::collections::generic::dictionary<xtd::string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"win32_c", xtdc_command::project_sdk::win32_c}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
      auto project_language = xtd::collections::generic::dictionary<xtd::string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"win32_c", xtdc_command::project_language::c}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
      auto status = project_management(get_project_full_path_from_path(path)).create(name, project_type, project_sdk, project_language);
      switch (status) {
        case operation_status::success: console::write_line("\n** CREATE SUCCEEDED **\n\n"); break;
        case operation_status::already_exist: write_line_error(xtd::string::format("Path {} already exists and not empty! Create project aborted.", path)); break;
        case operation_status::cmake_prefix_path_not_set: write_line_error("Set your CMAKE_PREFIX_PATH environment variable to the Qt installation prefix! Create project aborted."); break;
        case operation_status::invalid_language: write_line_error("The language param not valid with sdk param! Create project aborted."); break;
        case operation_status::invalid_sdk: write_line_error("The sdk param not valid with type param! Create project aborted."); break;
        case operation_status::invalid_sdk_with_current_project: write_line_error("The sdk param not valid with current project sdk! Create project aborted."); break;
        case operation_status::unknown_project: write_line_error(xtd::string::format("Parent directory \"{}\", is not a known project! Create project aborted.", xtd::io::directory::get_parent(path).full_name())); break;
        default: write_line_error("\n** CREATE FAILED **\n\n"); break;
      }
      return status == operation_status::success ? EXIT_SUCCESS : EXIT_FAILURE;
    }
    
  private:
    static xtd::array<xtd::string> get_help() noexcept {
      return {
        "Initialize project.",
        "Usage: new [template-short-name] [path] [<options>]",
        "",
        "template-short-name:",
        "  A template short name of the following table. If no short name specified, gui is used.",
        "  Templates               Short Name     SDK/Language                         ",
        "  ----------------------------------------------------------------------------",
        "  Console Application     console        [xtd], xtd_c, c++, c, c#, objective-c",
        "  GUI Application         gui            [xtd], xtd_c, cocoa, fltk, gtk+2,",
        "                                         gtk+3, gtk+4, gtkmm, wxwidgets, qt5,",
        "                                         qt6, win32, win32_c, winforms, wpf",
        "  Shared library          sharedlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Static library          staticlib      [xtd], xtd_c, c++, c, c#, objective-c",
        "  Unit Test Project       test           [xtd], xtd_c, gtest, catch2",
        "  Solution File           sln            [xtd], xtd_c",
        "",
        "path:",
        "  Location to place the generated output. If no path is specified, the current path is used.",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -n, --name          The name for the project. If no name is specified, the name of the specified path or of the current directory is used.",
        "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".",
        "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.",
        "",
        "",
        "Exemples:",
        "    xtdc new console",
        "    xtdc new gui my_app",
        "    xtdc new --help",
      };
    }
    
    static bool process_arguments(const xtd::array<xtd::string>& args, bool& show_help, xtd::string& type, xtd::string& name, xtd::string& path, xtd::string& sdk, xtd::string& invalid_option) {
      for (size_t i = 1; i < args.length(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.length()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.length()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        } else if (xtd::string::is_empty(type))
          type = args[i];
        else if (xtd::string::is_empty(path))
          path = args[i];
        else
          return false;
      }
      return true;
    }
  };
}
