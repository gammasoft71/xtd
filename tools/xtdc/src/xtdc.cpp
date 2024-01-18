#include "new_project.h"
//#include "project_management.h"
#include <xtd/char_object>
#include <xtd/startup>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

namespace xtdc_command {
  class xtdc final :public project_base {
  public:
    static auto main(const vector<ustring>& args) {
      if (args.size() == 0) {
        console::write_line(ustring::join("\n", get_help()));
        return -1;
      }
      
      auto show_help = false;
      auto show_info = false;
      auto show_version = false;
      string invalid_option;
      vector<ustring> command_args;
      if (process_xtdc_arguments(args, show_help, show_info, show_version, command_args, invalid_option) == false) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line("\n", get_help());
        return -1;
      }
      
      return run_commands(show_help, show_info, show_version, invalid_option, command_args);
    }
    
  private:
    static vector<ustring> get_help() noexcept {
      return {
        "",
        "Usage: xtdc [<options> | command [<command-argument>] [<command-options>]]",
        "",
        "options:",
        "  -i, --info       Display information.",
        "  -v, --version    Display version in use.",
        "  -h, --help       Display help.",
        
        "",
        "command:",
        "  new              Initializes project.",
        "  generate         Generate project from existing source files.",
        "  add              Adds new project to project.",
        "  update           Regenerates a project.",
        "  run              Compiles and immediately executes a project.",
        "  build            Builds a project.",
        "  install          Install a project.",
        "  clean            Clean build output(s).",
        "  open             Open a project in default ide.",
        "  targets          List project targets.",
        "  test             Runs unit tests using the test runner specified in the project.",
        "  uninstall        Uninstall a project.",
        "  documentation    Open xtd documentation.",
        "  examples         Open xtd examples.",
        "  guide            Open xtd reference guide.",
        "  web              Open xtd website.",
        "  help             Show help.",
        "",
        "Run 'xtdc command --help' for more information on a command.",
        "",
      };
    }
    
    static vector<ustring> get_add_help() noexcept {
      return {
        "Add new project to project.",
        "Usage: add [template-short-name] [path] [<options>]",
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
        "    xtdc add console",
        "    xtdc add gui my_app",
        "    xtdc add --help",
      };
    }
    
    static vector<ustring> get_build_help() noexcept {
      return {
        "Builds a project.",
        "Usage: build [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         build debug config.",
        "  -r, --release       build release config.",
        "  -t, --target        build a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc build",
        "    xtdc build my_apps",
        "    xtdc build my_apps -t my_app1",
        "    xtdc build --help"
      };
    }
    
    static vector<ustring> get_clean_help() noexcept {
      return {
        "Clean build output(s).",
        "Usage: clean [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         clean debug config.",
        "  -r, --release       clean release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc clean",
        "    xtdc clean my_app",
        "    xtdc clean --help",
      };
    }
    
    static vector<ustring> get_generate_help() noexcept {
      return {
        "Generate project.",
        "Usage: generate [template-short-name] [path] [<options>]",
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
        "    xtdc generate console",
        "    xtdc generate gui my_app",
        "    xtdc generate --help",
      };
    }
    
    static vector<ustring> get_install_help() noexcept {
      return {
        "Install a project.",
        "Usage: install [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         install debug config.",
        "  -r, --release       install release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc install",
        "    xtdc install my_app",
        "    xtdc install --help",
      };
    }
    
    static vector<ustring> get_open_help() noexcept {
      return {
        "Open a project in default ide.",
        "Usage: open [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         open debug config.",
        "  -r, --release       open release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc open",
        "    xtdc open my_app",
        "    xtdc open --help",
      };
    }
    

    static vector<ustring> get_update_help() noexcept {
      return {
        "Regenrates a project.",
        "Usage: update [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -t, --target        update a specified target project.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc update",
        "    xtdc update my_apps",
        "    xtdc update my_apps -t my_app1",
        "    xtdc update --help",
      };
    }
    
    static vector<ustring> get_run_help() noexcept {
      return {
        "Compiles and immediately executes a project.",
        "Usage: run [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         run debug config.",
        "  -r, --release       run release config.",
        "  -t, --target        run a specified target project.",
        "  -w, --wait          wait until the execution is finished.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc run",
        "    xtdc run my_apps",
        "    xtdc run my_apps -t my_app1",
        "    xtdc run --help",
      };
    }
    
    static vector<ustring> get_targets_help() noexcept {
      return {
        "List project targets.",
        "Usage: targets [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc list",
        "    xtdc list my_app",
        "    xtdc list --help",
      };
    }
    
    static vector<ustring> get_test_help() noexcept {
      return {
        "Runs unit tests using the test runner specified in the project.",
        "Usage: test [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         test debug config.",
        "  -r, --release       test release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc test",
        "    xtdc test my_app",
        "    xtdc test --help",
      };
    }
    
    static vector<ustring> get_uninstall_help() noexcept {
      return {
        "Uninstall a project.",
        "Usage: uninstall [path] [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         uninstall debug config.",
        "  -r, --release       uninstall release config.",
        "",
        "path:",
        "  Project path location. If no path is specified, the current path is used.",
        "",
        "",
        "Exemples:",
        "    xtdc uninstall",
        "    xtdc uninstall my_app",
        "    xtdc uninstall --help",
      };
    }
    
    static vector<ustring> get_info() noexcept {
      return {
        "",
        get_xtd_version(),
        //"",
        "Operating System:",
        ustring::format("  Name: {}", environment::os_version().name()),
        ustring::format("  Version: {}", environment::os_version().version()),
        ustring::format("  Service pack: {}", environment::os_version().service_pack()),
        ustring::format("  Desktop environment: {}", environment::os_version().desktop_environment()),
        ustring::format("  64 bit: {}", environment::os_version().is_64_bit()),
        "",
        "Compiler:",
        ustring::format("  Name: {}", environment::compiler_version().name()),
        ustring::format("  Version: {}", environment::compiler_version().version()),
        ustring::format("  Mode: {}", environment::compiler_version().is_build_type_debug() ? "Debug" : "Release"),
        ustring::format("  64 bit: {}", environment::compiler_version().is_64_bit()),
        "",
        "Language:",
        ustring::format("  Name: {}", environment::cpp_version().name()),
        ustring::format("  Version: {}", environment::cpp_version().version()),
        ustring::format("  Experimental: {}", environment::cpp_version().is_experimental_language()),
        ustring::format("  Supported: {}", environment::cpp_version().is_supported()),
        "",
      };
    }
    
    static ustring get_xtd_version() noexcept {
      auto result = ustring::format("xtd Framework:{}", environment::new_line());
      for (auto library : environment::xtd_libraries()) {
        result += ustring::format("  {}", library.name(), environment::new_line());
        result += ustring::format("    Version: {}{}", library.version(), environment::new_line());
        result += ustring::format("    include path: {}{}", library.include_path(), environment::new_line());
        result += ustring::format("    library path: {}{}", library.library_path(), environment::new_line());
        result += ustring::format("    resources path: {}{}", library.resources_path(), environment::new_line());
      }
      return result;
    }
    
    static ustring get_version() noexcept {
      return ustring::format("xtdc version {}, (c) {:L} by Gammasoft", get_version_number(), xtd::date_time::now());
    }
    
    static ustring get_version_number() noexcept {
      return environment::version().to_string();
    }
    
    static int add(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      ustring type;
      ustring sdk;
      ustring name;
      ustring path;
      if (!process_add_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_add_help()));
        return -1;
      }
      
      if (show_help)
        console::write_line(ustring::join("\n", get_add_help()));
      else {
        if (type.empty()) type = "gui";
        if (sdk.empty()) sdk = "xtd";
        if (name.empty()) name = get_project_name_from_path(path);
        
        if (name.empty()) {
          console::write_line("The name is empty.");
          return -1;
        }
        if (std::find_if(name.begin(), name.end(), [](auto c) {return !(char_object::is_letter_or_digit(c) || c == '_');}) != name.end()) {
          console::write_line("The name : \"{}\" contains invalid charaters.", name);
          return -1;
        }
        if (name.size() > 128) {
          console::write_line("The size of the name is invalid, the size must be less than or equal to 128.");
          return -1;
        }
        
        xtdc_command::project_type project_type = map<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
        console::write_line(project_management(get_project_full_path_from_path(path)).add(name, project_type, project_sdk, project_language));
      }
      return 0;
    }
    
    static int build(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto clean_first = false;
      auto release = false;
      ustring target;
      ustring path;
      if (!process_build_arguments(args, show_help, clean_first, release, target, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_build_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_build_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).build(target, clean_first, release));
      return 0;
    }
    
    static int clean(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      ustring path;
      if (!process_clean_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_clean_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_clean_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).clean(release));
      return 0;
    }
    
    static int generate(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      ustring type;
      ustring sdk;
      ustring name;
      ustring path;
      if (!process_generate_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_generate_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_generate_help()));
      else {
        if (type.empty()) type = "gui";
        if (sdk.empty()) sdk = "xtd";
        if (name.empty()) name = get_project_name_from_path(path);
        
        if (name.empty()) {
          console::write_line("The name is empty.");
          return -1;
        }
        if (std::find_if(name.begin(), name.end(), [](auto c) {return !(char_object::is_letter_or_digit(c) || c == '_');}) != name.end()) {
          console::write_line("The name : \"{}\" contains invalid charaters.", name);
          return -1;
        }
        if (name.size() > 128) {
          console::write_line("The size of the name is invalid, the size must be less than or equal to 128.");
          return -1;
        }
        
        xtdc_command::project_type project_type = map<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}} [type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtk+4", xtdc_command::project_sdk::gtk4}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"qt6", xtdc_command::project_sdk::qt6}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}, {"xtd_c", xtdc_command::project_sdk::xtd_c}} [sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtk+4", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"qt6", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"xtd_c", xtdc_command::project_language::c}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}} [sdk];
        console::write_line(project_management(get_project_full_path_from_path(path)).generate(name, project_type, project_sdk, project_language));
      }
      return 0;
    }
    
    static int help(const vector<ustring>& args) {
      console::write_line(ustring::join("\n", get_help()));
      return 0;
    }
    
    static int install(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      ustring path;
      if (!process_install_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_install_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_install_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).install(release));
      return 0;
    }
    
    static int open(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      ustring path;
      if (!process_open_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_open_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_open_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).open(release));
      return 0;
    }
    
    static int update(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      ustring target;
      ustring path;
      if (!process_update_arguments(args, show_help, target, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_update_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_update_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).update(target));
      return 0;
    }
    
    static int run(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      auto wait = false;
      ustring target;
      ustring path;
      if (!process_run_arguments(args, show_help, release, wait, target, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_run_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_run_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).run(target, release, wait));
      return 0;
    }
    
    static int targets(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      ustring path;
      if (!process_targets_arguments(args, show_help, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_targets_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_targets_help()));
      else {
        auto targets = xtd::ustring::join(", ", project_management(get_project_full_path_from_path(path)).targets());
        if (targets.empty()) targets = get_project_name_from_path(path);
        console::write_line(targets);
      }
      return 0;
    }
    
    static int test(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      ustring path;
      if (!process_test_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_test_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_test_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).test(release));
      return 0;
    }
    
    static int uninstall(const vector<ustring>& args) {
      auto show_help = false;
      ustring invalid_option;
      auto release = false;
      ustring path;
      if (!process_uninstall_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          console::write_line("Unknown option: {0}", invalid_option);
        else
          console::write_line("Invalid parameters");
        console::write_line(ustring::join("\n", get_uninstall_help()));
        return -1;
      }
      if (show_help)
        console::write_line(ustring::join("\n", get_uninstall_help()));
      else
        console::write_line(project_management(get_project_full_path_from_path(path)).uninstall(release));
      return 0;
    }
    
    static int documentation(const vector<ustring>& args) {
      process::start("https://gammasoft71.github.io/xtd/docs/documentation").wait_for_exit();
      return 0;
    }
    
    static int examples(const vector<ustring>& args) {
      process::start("https://github.com/gammasoft71/xtd/blob/master/examples/README.md").wait_for_exit();
      return 0;
    }
    
    static int guide(const vector<ustring>& args) {
      process::start("https://gammasoft71.github.io/xtd/reference_guides/latest/index.html").wait_for_exit();
      return 0;
    }
    
    static int web(const vector<ustring>& args) {
      process::start("https://gammasoft71.github.io/xtd").wait_for_exit();
      return 0;
    }
    
    static bool process_xtdc_arguments(const vector<ustring>& args, bool& show_help, bool& show_info, bool& show_version, vector<ustring>& command_args, string& invalid_option) {
      for (size_t i = 0; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-i" || args[i] == "--info")
          show_info = true;
        else if (args[i] == "-v" || args[i] == "--version")
          show_version = true;
        else if (!args[i].starts_with('-')) {
          command_args = {args.begin() + i, args.end()};
          i = args.size();
        } else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_add_arguments(const vector<ustring>& args, bool& show_help, ustring& type, ustring& name, ustring& path, ustring& sdk, ustring& invalid_option) {
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
        else if (name.empty())
          path = args[i];
        else
          return false;
      }
      return true;
    }
    
    static bool process_build_arguments(const vector<ustring>& args, bool& show_help, bool& clean_first, bool& release, ustring& target, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-c" || args[i] == "--clean-first")
          clean_first = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_clean_arguments(const vector<ustring>& args, bool& show_help, bool& release, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_generate_arguments(const vector<ustring>& args, bool& show_help, ustring& type, ustring& name, ustring& path, ustring& sdk, ustring& invalid_option) {
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
    
    static bool process_install_arguments(const vector<ustring>& args, bool& show_help, bool& release, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_open_arguments(const vector<ustring>& args, bool& show_help, bool& release, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_update_arguments(const vector<ustring>& args, bool& show_help, ustring& target, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_run_arguments(const vector<ustring>& args, bool& show_help, bool& release, bool& wait, ustring& target, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (args[i] == "-w" || args[i] == "--wait")
          wait = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_targets_arguments(const vector<ustring>& args, bool& show_help, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_test_arguments(const vector<ustring>& args, bool& show_help, bool& release, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static bool process_uninstall_arguments(const vector<ustring>& args, bool& show_help, bool& release, ustring& path, ustring& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (path.empty())
          path = args[i];
        else if (args[i].starts_with('-')) {
          invalid_option = args[i];
          return false;
        }
      }
      return true;
    }
    
    static int invalid_command(const vector<ustring>& command_args) {
      console::write_line("Invalid command");
      console::write_line(ustring::join("\n", get_help()));
      return -1;
    }
    
    static int run_commands(bool show_help, bool show_info, bool show_version, string invalid_option, const vector<ustring>& command_args) {
      if (show_version || show_info || show_help) {
        console::write_line(get_version());
        if (show_info) console::write_line(ustring::join("\n", get_info()));
        if (show_help) console::write_line(ustring::join("\n", get_help()));
        return 0;
      }
      static map<ustring, function<int(const vector<ustring>&)>> commands {{"add", add}, {"build", build}, {"clean", clean}, {"documentation", documentation}, {"examples", examples}, {"generate", generate}, {"guide", guide}, {"help", help}, {"install", install}, {"new", new_project::execute}, {"open", open}, {"update", update}, {"run", run}, {"targets", targets}, {"test", test}, {"uninstall", uninstall}, {"web", web}};
      auto it = commands.find(command_args[0]);
      if (it == commands.end()) return invalid_command(command_args);
      return it->second(command_args);
    }
  };
}

startup_(xtdc_command::xtdc::main);
