#include "project_management.h"

#include <xtd/xtd.core>
#include <chrono>
#include <filesystem>
#include <iostream>

#if !defined(WIN32)
#include <unistd.h>
#endif

using namespace std;
using namespace xtd;

namespace xtdc_command {
  class xtdc static_ {
  public:
    static int main(const vector<string>& args) {
      if (args.size() == 0) {
        cout << strings::join("\n", get_help()) << endl;
        return -1;
      }
      
      auto show_help = false;
      auto show_info = false;
      auto show_version = false;
      string invalid_option;
      vector<string> command_args;
      if (process_xtdc_arguments(args, show_help, show_info, show_version, command_args, invalid_option) == false) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_help()) << endl;
        return -1;
      }
      
      return run_commands(show_help, show_info, show_version, invalid_option, command_args);
    }
    
  private:
  #if defined(__XTD_FORMS_RESOURCES_PATH__)
    static string get_base_path() noexcept {return __XTD_FORMS_RESOURCES_PATH__;}
  #else
    static string get_base_path() noexcept {return "";}
  #endif

    static vector<string> get_help() noexcept {
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
        "  new              Initialize project.",
        //"  add              Add new project to project.",
        "  run              Compiles and immediately executes a project.",
        "  build            Builds a project.",
        "  install          Install a project.",
        "  clean            Clean build output(s).",
        "  open             Open a project in default ide.",
        "  targets          List project targets.",
        "  test             Runs unit tests using the test runner specified in the project.",
        "  uninstall        Uninstall a project.",
        //"  documentations   Open documentations.",
        //"  examples         Open xtd examples.",
        //"  guide            Open xtd reference guide.",
        //"  web              Open xtd website.",
        "  help             Show help.",
        "",
        "Run 'xtdc command --help' for more information on a command.",
        "",
      };
    }
    
    static vector<string> get_add_help() noexcept {
      return {
        "Add new project to project.",
        "Usage: add [options]",
      };
    }

    static vector<string> get_build_help() noexcept {
      return {
        "Builds a project.",
        "Usage: build [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         build debug config.",
        "  -r, --release       build release config.",
        "  -t, --target        build a specified target project.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc build",
        "    xtdc build -p my_apps",
        "    xtdc build -p my_apps -t my_app1",
        "    xtdc build --help"
      };
    }
    
    static vector<string> get_clean_help() noexcept {
      return {
        "Clean build output(s).",
        "Usage: clean [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         clean debug config.",
        "  -r, --release       clean release config.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc clean",
        "    xtdc clean -p my_app",
        "    xtdc clean --help",
      };
    }
    
    static vector<string> get_install_help() noexcept {
      return {
        "Install a project.",
        "Usage: install [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         install debug config.",
        "  -r, --release       install release config.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc install",
        "    xtdc install -p my_app",
        "    xtdc install --help",
      };
    }
    
    static vector<string> get_open_help() noexcept {
      return {
        "Open a project in default ide.",
        "Usage: open [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         open debug config.",
        "  -r, --release       open release config.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc open",
        "    xtdc open -p my_app",
        "    xtdc open --help",
      };
    }
    
    static vector<string> get_new_help() noexcept {
      return {
        "Initialize project.",
        "Usage: new [template-short-name] [name] [<options>]",
        "",
        "template-short-name:",
        "  A template short name of the following table. If no short name specified, gui is used.",
        "  Templates               Short Name     SDK/Language                      ",
        "  -------------------------------------------------------------------------",
        "  GUI Application         gui            [xtd], cocoa, fltk, gtk+2, gtk+3, ",
        "                                         gtkmm, wxwidgets, qt5, win32,     ",
        "                                         winforms, wpf                     ",
        "  Console Application     console        [xtd], c++, c, c#, objective-c    ",
        "  Shared library          sharedlib      [xtd], c++, c, c#, objective-c    ",
        "  Static library          staticlib      [xtd], c++, c, c#, objective-c    ",
        "  Unit Test Project       test           [xtd], gtest, catch2              ",
        "  Solution File           sln            [xtd]                             ",
        "",
        "name:",
        "  The name for the project. If no name is specified, the name of the specified path or of the current directory is used.",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -p, --path          Location to place the generated output.",
        "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".",
        "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.",
        "  --force             Forces content to be generated even if it would change existing files.",
        "",
        "",
        "Exemples:",
        "    xtdc new console",
        "    xtdc new gui -p my_app",
        "    xtdc new --help",
      };
    }

    static vector<string> get_run_help() noexcept {
      return {
        "Compiles and immediately executes a project.",
        "Usage: run [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         run debug config.",
        "  -r, --release       run release config.",
        "  -t, --target        run a specified target project.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc run",
        "    xtdc run -p my_apps",
        "    xtdc run -p my_apps -t my_app1",
        "    xtdc run --help",
      };
    }
    
    static vector<string> get_targets_help() noexcept {
      return {
        "List project targets.",
        "Usage: clean [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc list",
        "    xtdc list -p my_app",
        "    xtdc list --help",
      };
    }

    static vector<string> get_test_help() noexcept {
      return {
        "Runs unit tests using the test runner specified in the project.",
        "Usage: test [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         test debug config.",
        "  -r, --release       test release config.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc test",
        "    xtdc test -p my_app",
        "    xtdc test --help",
      };
    }
    
    static vector<string> get_uninstall_help() noexcept {
      return {
        "Uninstall a project.",
        "Usage: uninstall [<options>]",
        "",
        "options:",
        "  -h, --help          Displays help for this command.",
        "  -d, --debug         uninstall debug config.",
        "  -r, --release       uninstall release config.",
        "  -p, --path          Project path location.",
        "",
        "",
        "Exemples:",
        "    xtdc uninstall",
        "    xtdc uninstall -p my_app",
        "    xtdc uninstall --help",
      };
    }
    
    static vector<string> get_info() noexcept {
      return {
        "",
        "xtdc:",
        strings::format("  Version: {}", get_version_number()),
        "",
        "System Environment:",
        strings::format("  OS Name:    {}", get_os_name()),
        strings::format("  OS Version: {}", environment::os_version().version().to_string(2)),
        strings::format("  Base Path:  {}", get_base_path())
      };
    }

    static string get_os_name() noexcept {
      static map<platform_id, string> names = {{platform_id::unknown, "Unknown System"}, {platform_id::win32s, "Windows"}, {platform_id::win32_windows, "Windows"}, {platform_id::win32_nt, "Windows NT"}, {platform_id::win_ce, "Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::mac_os_x, "Mac OS X"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, };
      return names[environment::os_version().platform()];
    }

    static string get_version() noexcept {
      return strings::format("xtdc version {}, © {:L} by Gammasoft", get_version_number(), chrono::system_clock::now());
    }
    
    static string get_version_number() noexcept {
      return /*environment::version().to_string()*/ version(1, 0, 0).to_string();
    }
     
    static bool is_ansi_supported() noexcept {
#if defined(WIN32)
      return true;
#else
      static string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
#endif
    }

    static int new_project(const vector<string>& args) {
      auto show_help = false;
      string invalid_option;
      string type = "gui";
      string sdk = "xtd";
      string name;
      string path = environment::current_directory();
      if (!process_new_arguments(args, show_help, type, name, path, sdk, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_new_help()) << endl;
        return -1;
      }
      if (name.empty()) name = filesystem::path(path).stem().string();

      if (show_help)
        cout << strings::join("\n", get_new_help()) << endl;
      else {
        xtdc_command::project_type project_type = map<string, xtdc_command::project_type> {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}}[type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"catch2", xtdc_command::project_sdk::catch2}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"fltk", xtdc_command::project_sdk::fltk}, {"gtest", xtdc_command::project_sdk::gtest}, {"gtk+2", xtdc_command::project_sdk::gtk2}, {"gtk+3", xtdc_command::project_sdk::gtk3}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"qt5", xtdc_command::project_sdk::qt5}, {"win32", xtdc_command::project_sdk::win32}, {"winforms", xtdc_command::project_sdk::winforms}, {"wpf", xtdc_command::project_sdk::wpf}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"xtd", xtdc_command::project_sdk::xtd}}[sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cocoa", xtdc_command::project_language::objectivec}, {"fltk", xtdc_command::project_language::cpp}, {"gtk+2", xtdc_command::project_language::cpp}, {"gtk+3", xtdc_command::project_language::cpp}, {"gtkmm", xtdc_command::project_language::cpp}, {"qt5", xtdc_command::project_language::cpp}, {"win32", xtdc_command::project_language::cpp}, {"winforms", xtdc_command::project_language::csharp}, {"wpf", xtdc_command::project_language::csharp}, {"wxwidgets", xtdc_command::project_language::cpp}, {"xtd", xtdc_command::project_language::cpp}, {"c++", xtdc_command::project_language::cpp}, {"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"c#", xtdc_command::project_language::csharp}, {"csharp", xtdc_command::project_language::csharp}, {"objective-c", xtdc_command::project_language::objectivec}, {"objectivec", xtdc_command::project_language::objectivec}}[sdk];
        cout << project_management(filesystem::absolute(filesystem::path(path))).create(name, project_type, project_sdk, project_language) << endl;
      }
      return 0;
    }
    
    static int add(const vector<string>& args) {
      return 0;
    }
    
    static int build(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool clean_first = false;
      bool release = false;
      string target;
      string path;
      if (!process_build_arguments(args, show_help, clean_first, release, target, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_build_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_build_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.build(target, clean_first, release) << endl;
      }
      return 0;
    }
    
    static int clean(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_clean_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_clean_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_clean_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.clean(release) << endl;
      }
      return 0;
    }
    
    static int help(const vector<string>& args) {
      cout << strings::join("\n", get_help()) << endl;
      return 0;
    }
    
    static int install(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_install_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_install_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_install_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.install(release) << endl;
      }
      return 0;
    }

    static int open(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_open_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_open_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_open_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.open(release) << endl;
      }
      return 0;
    }
    
    static int run(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string target;
      string path;
      if (!process_run_arguments(args, show_help, release, target, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_run_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_run_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.run(target, release) << endl;
      }
      return 0;
    }
    
    static int targets(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      string path;
      if (!process_targets_arguments(args, show_help, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_targets_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_targets_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << xtd::strings::join(", ", project.targets()) << endl;
      }
      return 0;
    }

    static int test(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_test_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_test_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_test_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.test(release) << endl;
      }
      return 0;
    }
    
    static int uninstall(const vector<string>& args) {
      bool show_help = false;
      string invalid_option;
      bool release = false;
      string path;
      if (!process_uninstall_arguments(args, show_help, release, path, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << strings::join("\n", get_uninstall_help()) << endl;
        return -1;
      }
      if (show_help)
        cout << strings::join("\n", get_uninstall_help()) << endl;
      else {
        if (path.empty()) path = environment::current_directory();
        project_management project(filesystem::absolute(filesystem::path(path)));
        cout << project.uninstall(release) << endl;
      }
      return 0;
    }
    
    static int documentations(const vector<string>& args) {
      return 0;
    }
    
    static int examples(const vector<string>& args) {
      return 0;
    }
    
    static int guide(const vector<string>& args) {
      return 0;
    }
    
    static int web(const vector<string>& args) {
      return 0;
    }

    static bool process_xtdc_arguments(const vector<string>& args, bool& show_help, bool& show_info, bool& show_version, vector<string>& command_args, string& invalid_option) {
      for (size_t i = 0; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-i" || args[i] == "--info")
          show_info = true;
        else if (args[i] == "-v" || args[i] == "--version")
          show_version = true;
        else if (!strings::starts_with(args[i], '-')) {
          command_args = vector<string>(args.size() - i);
          command_args = {args.begin() + i, args.end()};
          i = args.size();
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_add_arguments(const vector<string>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help") {
          show_help = true;
        } else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i+1 >= args.size()) return false;
          sdk = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        } else if (type.empty()) {
          type = args[i];
        } else if (name.empty()) {
          name = args[i];
        } else
          return false;
      }
      return true;
    }

    static bool process_build_arguments(const vector<string>& args, bool& show_help, bool& clean_first, bool& release, string& target, string& path, string& invalid_option) {
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
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_clean_arguments(const vector<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_install_arguments(const vector<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }

    static bool process_open_arguments(const vector<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 0; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_new_arguments(const vector<string>& args, bool& show_help, string& type, string& name, string& path, string& sdk, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help") {
          show_help = true;
        } else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i+1 >= args.size()) return false;
          sdk = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        } else if (type.empty()) {
            type = args[i];
        } else if (name.empty()) {
          name = args[i];
        } else
          return false;
      }
      return true;
    }

    static bool process_run_arguments(const vector<string>& args, bool& show_help, bool& release, string& target, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-t" || args[i] == "--target")
          target = args[++i];
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_targets_arguments(const vector<string>& args, bool& show_help, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }

    static bool process_test_arguments(const vector<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_uninstall_arguments(const vector<string>& args, bool& show_help, bool& release, string& path, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-d" || args[i] == "--debug")
          release = false;
        else if (args[i] == "-r" || args[i] == "--release")
          release = true;
        else if (args[i] == "-p" || args[i] == "--path") {
          if (i+1 >= args.size()) return false;
          path = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }

    static int run_commands(bool show_help, bool show_info, bool show_version, string invalid_option, const vector<string>& command_args) {
      if (show_version || show_info || show_help) {
        cout << get_version() << endl;
        if (show_info)
          cout << strings::join("\n", get_info()) << endl;
        if (show_help)
          cout << strings::join("\n", get_help()) << endl;
      } else {
        if (command_args[0] == "new") return new_project(command_args);
        else if (command_args[0] == "add") return add(command_args);
        else if (command_args[0] == "build") return build(command_args);
        else if (command_args[0] == "clean") return clean(command_args);
        else if (command_args[0] == "help") return help(command_args);
        else if (command_args[0] == "install") return install(command_args);
        else if (command_args[0] == "open") return open(command_args);
        else if (command_args[0] == "run") return run(command_args);
        else if (command_args[0] == "targets") return targets(command_args);
        else if (command_args[0] == "test") return test(command_args);
        else if (command_args[0] == "uninstall") return uninstall(command_args);
        //else if (command_args[0] == "documentations" || command_args[0] == "documentation") return documentations(command_args);
        //else if (command_args[0] == "examples") return examples(command_args);
        //else if (command_args[0] == "guide") return guide(command_args);
        //else if (command_args[0] == "web") return web(command_args);
        else {
          cout << "Invalid command" << endl;
          cout << strings::join("\n", get_help()) << endl;
          return -1;
        }
      }
      return 0;
    }
  };
}

startup_(xtdc_command::xtdc);
