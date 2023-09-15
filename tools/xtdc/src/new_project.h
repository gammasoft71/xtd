#include "project_base.h"
#include "project_language.h"
#include "project_management.h"
#include "project_sdk.h"
#include "project_type.h"
#include <xtd/console>
#include <vector>

namespace xtdc_command {
  class new_project final :public project_base {
  public:
    static int execute(const std::vector<xtd::ustring>& args) {
      auto show_help = false;
      xtd::ustring invalid_option;
      xtd::ustring type;
      xtd::ustring sdk;
      xtd::ustring name;
      xtd::ustring path;
      if (!process_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          xtd::console::write_line("Unknown option: {0}", invalid_option);
        else
          xtd::console::write_line("Invalid parameters");
        xtd::console::write_line(xtd::ustring::join("\n", get_help()));
        return -1;
      }
      if (show_help)
        xtd::console::write_line(xtd::ustring::join("\n", get_help()));
      else {
        if (type.empty()) type = "gui";
        if (sdk.empty()) sdk = "xtd";
        if (name.empty()) name = get_project_name_from_path(path);
        
        if (name.empty()) {
          xtd::console::write_line("The name is empty.");
          return -1;
        }
        if (std::find_if(name.begin(), name.end(), [](auto c) {return !(isalnum(c) || c == '_');}) != name.end()) {
          xtd::console::write_line("The name : \"{}\" contains invalid charaters.", name);
          return -1;
        }
        if (name.size() > 128) {
          xtd::console::write_line("The size of the name is invalid, the size must be less than or equal to 128.");
          return -1;
        }
        
        xtdc_command::project_type project_type = std::map<xtd::ustring, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
        xtdc_command::project_sdk project_sdk = std::map<xtd::ustring, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
        xtdc_command::project_language project_language = std::map<xtd::ustring, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
        xtd::console::write_line(project_management(get_project_full_path_from_path(path)).create(name, project_type, project_sdk, project_language));
      }
      return 0;
    }
    
  private:
    static std::vector<xtd::ustring> get_help() noexcept {
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
        "                                         qt6, win32, winforms, wpf",
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
    
    static bool process_arguments(const std::vector<xtd::ustring>& args, bool& show_help, xtd::ustring& type, xtd::ustring& name, xtd::ustring& path, xtd::ustring& sdk, xtd::ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-n" || args[i] == "--name") {
          if (i + 1 >= args.size()) return false;
          name = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i + 1 >= args.size()) return false;
          sdk = args[++i];
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        } else if (type.empty())
          type = args[i];
        else if (path.empty())
          path = args[i];
        else
          return false;
      }
      return true;
    }
  };
}
