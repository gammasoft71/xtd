#include <xtd/xtd.core>
#include <chrono>
#include <iostream>

using namespace std;
using namespace xtd;

namespace guidgen {
  class program static_ {
  public:
    static int main(const vector<string>& args) {
      string format = "";
      int count = 1;
      bool show_help = false;
      bool show_version = false;
      if (!process_arguments(args, format, count, show_version, show_help)) {
        cout << get_error() << endl;
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
      
      for (int index = 0; index < count; index++)
        cout << guid::new_guid().to_string(format) << endl;
      return 0;
    }
    
  private:
    static string get_error() {
      return "guidgen : invalid params\n"
      "Try 'guidgen --help' for more information.";
    }
    
    static string get_usage() {
      return "Usage\n"
      "  guidgen [--format Format] [--count Count]\n"
      "\n"
      "-f, --format : Indicates how to format the value of this Guid. The format parameter can be :\n"
      "                 N : 32 digits.\n"
      "                 D : 32 digits separated by hyphens.\n"
      "                 B : 32 digits separated by hyphens, enclosed in braces.\n"
      "                 P : 32 digits separated by hyphens, enclosed in parentheses.\n"
      "                 X : Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces.\n"
      "-c, --count  : indicate the number of generation (form 1 to 2147483647)\n"
      "-v, --version      : Shows version information.\n"
      "-h, --help   : Shows this help page.";
    }
    
    static string get_version() {
      return strings::format("guidgen version {}, © {:L} by Gammasoft", /*environment::version()*/ version(1, 0, 0), chrono::system_clock::now());
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

startup_(guidgen::program);
