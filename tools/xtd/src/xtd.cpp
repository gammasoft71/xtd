#include <xtd/xtd.core>
#include <chrono>
#include <iostream>

using namespace std;
using namespace xtd;

namespace guid_command {
class program static_ {
public:
  static int main(const vector<string>& args) {
    string format = "";
    int count = 1;
    bool show_help = false;
    bool show_version = false;
    if (!process_arguments(args, format, count, show_version, show_help)) {
      cout << "Invalid parameters" << endl;
      cout << get_help() << endl;
      return -1;
    }
    
    if (show_version) {
      cout << get_version() << endl;
      return 0;
    }
    
    if (show_help) {
      cout << get_version() << endl << endl << get_usage() << endl;
      return 0;
    }

    cout << get_usage() << endl;
    return 0;
  }
  
private:
#if defined(__XTD_FORMS_RESOURCES_PATH__)
  static string get_base_path() {return __XTD_FORMS_RESOURCES_PATH__;}
#else
  static string get_base_path() {return "";}
#endif

  static string get_help() {
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
  
  static string get_info() {
    return strings::format("xtdc:\n"
                          "  Version: {0}\n"
                          "\n"
                          "System Environment:\n"
                          "  OS Name:    {1}\n"
                          "  OS Version: {2}\n"
                          "  Base Path:  {3}\n", get_version_number(), get_os_name(), environment::os_version().version().to_string(2), get_base_path());
  }

  static string get_os_name() {
    static map<platform_id, string> names = {{platform_id::unknown, "Unknown System"}, {platform_id::win32s, "Windows"}, {platform_id::win32_windows, "Windows"}, {platform_id::win32_nt, "Windows NT"}, {platform_id::win_ce, "Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::mac_os_x, "Mac OS X"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, };
    return names[environment::os_version().platform()];
  }

  static string get_usage() {
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
  
  static string get_version() {
    return strings::format("xtdc version {}, © {:L} by Gammasoft", get_version_number(), chrono::system_clock::now());
  }
  
  static string get_version_number() {
    return /*environment::version().to_string()*/ version(1, 0, 0).to_string();
  }
  
  static bool process_arguments(const vector<string>& args, string& format, int& count, bool& show_version, bool& show_help) {
    for (size_t index = 0; index < args.size(); index += 1) {
      vector<string> format_types {"N", "D", "B", "P", "X"};
      if ((args[index] == "-f" || args[index] == "--format") && index + 1 < args.size() && std::count(format_types.begin(), format_types.end(), args[index + 1]))
        format = args[index++ + 1];
      else if ((args[index] == "-c" || args[index] == "--count") && index + 1 < args.size() && strings::try_parse(args[index++ + 1], count) && count >= 1) {
        // nothing to do all is done
      } else if (args[index] == "-v" || args[index] == "--version")
        show_version = true;
      else if (args[index] == "-h" || args[index] == "--help")
        show_help = true;
      else
        return false;
    }
    return true;
  }
};
}

startup_(guid_command::program);
