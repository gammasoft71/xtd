#include "project_management.hpp"

#include <xtd/xtd.core>
#include <chrono>
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
        cout << get_usage() << endl;
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
        cout << get_help() << endl;
        return -1;
      }
      
      if (show_version)
        cout << get_version() << endl;
      else if (show_help)
        cout << get_help() << endl;
      else if (show_info)
        cout << get_info() << endl;
      else {
        if (command_args[0] == "new")
          return new_project(command_args);
        else if (command_args[0] == "build")
          return build(command_args);
        else if (command_args[0] == "clean")
          return clean(command_args);
        else if (command_args[0] == "help")
          return help(command_args);
        else if (command_args[0] == "install")
          return install(command_args);
        else if (command_args[0] == "open")
          return open(command_args);
        else if (command_args[0] == "run")
          return run(command_args);
        else if (command_args[0] == "test")
          return test(command_args);
        else if (command_args[0] == "uninstall")
          return uninstall(command_args);
        else if (command_args[0] == "documentations" || command_args[0] == "documentation")
          return documentations(command_args);
        else if (command_args[0] == "examples")
          return examples(command_args);
        else if (command_args[0] == "guide")
          return guide(command_args);
        else if (command_args[0] == "web")
          return web(command_args);
        else {
          if (io::file::exists(command_args[0])) {
            //diagnostics::process::start(command_args[0]);
          } else {
            set_foreground_color_red();
            cout << format("No executable found matching command \"xtdc-{0}\"", command_args[0]) << endl;
            reset_color();
            return -1;
          }
        }
      }
      return 0;
    }
    
  private:
  #if defined(__XTD_FORMS_RESOURCES_PATH__)
    static string get_base_path() noexcept {return __XTD_FORMS_RESOURCES_PATH__;}
  #else
    static string get_base_path() noexcept {return "";}
  #endif

    static string get_help() noexcept {
      return strings::format("xtdc Command Line Tools ({0})\n"
                             "Usage: xtdc [runtime-options] [path-to-application]\n"
                             "Usage: xtdc [sdk-options] [command] [arguments] [command-options]\n"
                             "\n"
                             "path-to-application:\n"
                             "  The path to an application file to execute.\n"
                             "\n"
                             "SDK commands:\n"
                             "  new              Initialize projects.\n"
                             "  run              Compiles and immediately executes a project.\n"
                             "  build            Builds a project.\n"
                             "  install          Install a project.\n"
                             "  clean            Clean build output(s).\n"
                             "  open             Open a project in default ide.\n"
                             "  test             Runs unit tests using the test runner specified in the project.\n"
                             "  uninstall        Uninstall a project.\n"
                             "  documentations   Open documentations.\n"
                             "  examples         Open xtd examples.\n"
                             "  guide            Open xtd reference guide.\n"
                             "  web              Open xtd website.\n"
                             "  help             Show help.\n"
                             "\n"
                             "Common options:\n"
                             "  -v|--verbosity        Set the verbosity level of the command. Allowed values are q[uiet], m[inimal], n[ormal], d[etailed], and diag[nostic].\n"
                             "  -h|--help             Show help.\n"
                             "\n"
                             "Run 'xtdc COMMAND --help' for more information on a command.\n"
                             "\n"
                             "sdk-options:\n"
                             "  --version        Display Swicth version in use.\n"
                             "  --info           Display Switch information.\n", get_version_number());
    }
    
    static string get_build_help() noexcept {
      return "Usage: build [options]\n";
    }
    
    static string get_clean_help() noexcept {
      return "Usage: clean [options]\n";
    }
    
    static string get_install_help() noexcept {
      return "Usage: install [options]\n";
    }
    
    static string get_open_help() noexcept {
      return "Usage: open [options]\n";
    }
    
    static string get_new_help() noexcept {
      return "Usage: new template_short_name [options]\n"
      "\n"
      "Options:\n"
      "  -h, --help          Displays help for this command.\n"
      "  -l, --list          Lists templates containing the specified name. If no name is specified, lists all templates.\n"
      "  -n, --name          The name for the output being created. If no name is specified, the name of the current directory is used.\n"
      "  -o, --output        Location to place the generated output.\n"
      "  --type              Filters templates based on available types. Predefined values are \"project\", \"item\" or \"other\".\n"
      "  -s , --sdk          Filters templates based on SDK/language and specifies the SDK/language of the template to create.\n"
      "  --force             Forces content to be generated even if it would change existing files.\n"
      "\n"
      "\n"
      "Templates                                     Short Name    SDK/Language\n"
      "-----------------------------------------------------------------------------------------\n"
      "Console Application                           console       [xtd], c++, c, objective-c\n"
      "Graphic User Interface Application            gui           [xtd], win32, gtk, cocoa, gtkmm, wxwidgets, qt5\n"
      "Static library                                staticlib     [xtd], c++, c, objective-c\n"
      "Shared library                                sharedlib     [xtd], c++, c, objective-c\n"
      "Unit Test Project                             test          [xtd], gtest, catch2\n"
      "Solution File                                 sln\n"
      "\n"
      "\n"
      "Exemples:\n"
      "    switch new console\n"
      "    switch new gui -o my_app\n"
      "    switch new --help\n";
    }
    
    static string get_run_help() noexcept {
      return "Usage: run [options]\n";
    }
    
    static string get_test_help() noexcept {
      return "Usage: test [options]\n";
    }
    
    static string get_uninstall_help() noexcept {
      return "Usage: uninstall [options]\n";
    }
    

    static string get_info() noexcept {
      return strings::format("xtdc:\n"
                            "  Version: {0}\n"
                            "\n"
                            "System Environment:\n"
                            "  OS Name:    {1}\n"
                            "  OS Version: {2}\n"
                            "  Base Path:  {3}\n", get_version_number(), get_os_name(), environment::os_version().version().to_string(2), get_base_path());
    }

    static string get_os_name() noexcept {
      static map<platform_id, string> names = {{platform_id::unknown, "Unknown System"}, {platform_id::win32s, "Windows"}, {platform_id::win32_windows, "Windows"}, {platform_id::win32_nt, "Windows NT"}, {platform_id::win_ce, "Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::mac_os_x, "Mac OS X"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, };
      return names[environment::os_version().platform()];
    }

    static string get_usage() noexcept {
      return "Usage: xtdc [options]\n"
      "Usage: xtdc [path-to-application]\n"
      "\n"
      "Options:\n"
      "  -h|--help        Display help.\n"
      "  --info           Display xtdc information.\n"
      "  --version        Display xtdc version in use.\n"
      "\n"
      "path-to-application:\n"
      "  The path to an application file to execute.\n";
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
      static std::string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
#endif
    }

    static int new_project(const vector<string>& args) {
      auto show_help = false;
      auto show_list = false;
      string invalid_option;
      string type;
      string sdk;
      string output;
      if (!process_new_arguments(args, show_help, show_list, type, output, sdk, invalid_option)) {
        if (!invalid_option.empty())
          cout << format("Unknown option: {0}", invalid_option) << endl;
        else
          cout << "Invalid parameters" << endl;
        cout << get_new_help() << endl;
        return -1;
      }
      
      if (show_help)
        cout << get_new_help() << endl;
      else {
        static map<string, project_type> types = {{"sln", project_type::blank_solution}, {"gui", project_type::gui}, {"console", project_type::console}, {"sharedlib", project_type::shared_library}, {"staticlib", project_type::static_library}, {"test", project_type::unit_test_application}};
        static map<project_type, vector<string>> sdk_languages = {{project_type::console, {"xtd", "c++", "c", "objective-c"}}, {project_type::gui, {"xtd", "win32", "gtk", "cocoa", "gtkmm", "wxwidgets", "qt5"}}, {project_type::static_library, {"xtd", "c++", "c", "objective-c"}}, {project_type::shared_library, {"xtd", "c++", "c", "objective-c"}}, {project_type::unit_test_application, {"xtd", "gtest", "catch2"}}, {project_type::blank_solution, {"xtd"}}};
        
        if (type.empty()) type = "gui";
        if (sdk.empty()) sdk = "xtd";
        if (output.empty()) output = environment::current_directory();
        if (types.find(type) == types.end()) {
          set_foreground_color_red();
          cout << format("No templates matched the input template type: {0}.", type) << endl;
          reset_color();
          return -1;
        }
        if (find(sdk_languages[types[type]].begin(), sdk_languages[types[type]].end(), sdk) == sdk_languages[types[type]].end()) {
          set_foreground_color_red();
          cout << format("Error: Invalid parameter(s):\n"
                         "--sdk {0}\n"
                         "'{0}' is not a valid value for --sdk (SDK/Language).\n"
                         "Run switch new --help for usage information.", sdk) << endl;
          reset_color();
          return -1;
        }
        
        xtdc_command::project_type project_type = types[type];
        xtdc_command::project_sdk project_sdk = map<string, xtdc_command::project_sdk> {{"none", xtdc_command::project_sdk::none}, {"xtd", xtdc_command::project_sdk::xtd}, {"win32", xtdc_command::project_sdk::win32}, {"gtk", xtdc_command::project_sdk::gtk}, {"cocoa", xtdc_command::project_sdk::cocoa}, {"gtkmm", xtdc_command::project_sdk::gtkmm}, {"wxwidgets", xtdc_command::project_sdk::wxwidgets}, {"qt5", xtdc_command::project_sdk::qt5}, {"gtest", xtdc_command::project_sdk::gtest}, {"catch2", xtdc_command::project_sdk::catch2}}[sdk];
        xtdc_command::project_language project_language = map<string, xtdc_command::project_language> {{"cpp", xtdc_command::project_language::cpp}, {"c", xtdc_command::project_language::c}, {"objectivec", xtdc_command::project_language::objectivec}}[sdk];
        string project_name = io::path::get_file_name_without_extension(output);

        if (sdk == "xtd") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "win32") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "cocoa") project_language = xtdc_command::project_language::objectivec;
        else if (sdk == "gtk") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "gtkmm") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "wxwidgets") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "qt5") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "c++") project_language = xtdc_command::project_language::cpp;
        else if (sdk == "c") project_language = xtdc_command::project_language::c;
        else if (sdk == "objectivec") project_language = xtdc_command::project_language::objectivec;

        project_management project(project_name, project_type, project_sdk, project_language, io::path::get_full_path(output));
        cout << project.create() << endl;
        cout << project.generate() << endl;
      }
      return 0;
    }
    
    static int build(const vector<string>& args) {
      return 0;
    }
    
    static int clean(const vector<string>& args) {
      return 0;
    }
    
    static int help(const vector<string>& args) {
      return 0;
    }
    
    static int install(const vector<string>& args) {
      return 0;
    }
    
    static int open(const vector<string>& args) {
      return 0;
    }
    
    static int run(const vector<string>& args) {
      return 0;
    }
    
    static int test(const vector<string>& args) {
      return 0;
    }
    
    static int uninstall(const vector<string>& args) {
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
        else if (args[i] == "--info")
          show_info = true;
        else if (args[i] == "--version")
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
    
    static bool process_build_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_clean_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_install_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_launch_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 0; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_new_arguments(const vector<string>& args, bool& show_help, bool& show_list, string& type, string& output, string& sdk, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (!strings::starts_with(args[i], '-')) {
          type = args[i];
        } else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (args[i] == "-s" || args[i] == "--sdk") {
          if (i+1 >= args.size()) return false;
          sdk = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }

    static bool process_run_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_test_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }
    
    static bool process_uninstall_arguments(const vector<string>& args, bool& show_help, string& output, string& invalid_option) {
      for (size_t i = 1; i < args.size(); i += 1) {
        if (args[i] == "-h" || args[i] == "--help")
          show_help = true;
        else if (args[i] == "-o" || args[i] == "--output") {
          if (i+1 >= args.size()) return false;
          output = args[++i];
        } else if (strings::starts_with(args[i], '-')) {
          invalid_option = args[i];;
          return false;
        }
      }
      return true;
    }

    static void reset_color() noexcept {
      if (is_ansi_supported())
        std::cout << "\033[49m\033[39m";
    }

    static void set_foreground_color_red() noexcept {
      if (is_ansi_supported())
        std::cout << "\033[31m";
    }
  };
}

startup_(xtdc_command::xtdc);
