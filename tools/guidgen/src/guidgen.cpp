#include <xtd/console>
#include <xtd/environment>
#include <xtd/guid>
#include <xtd/startup>

using namespace xtd;

namespace guidgen {
  class program final static_ {
  public:
    static auto main(const std::vector<ustring>& args) {
      auto format = ustring::empty_string;
      auto count = 1;
      auto show_help = false;
      auto show_version = false;
      if (!process_arguments(args, format, count, show_version, show_help)) {
        console::write_line(get_error());
        return as<int>(exit_status::failure);
      }
      
      if (show_version) {
        console::write_line(get_version());
        return as<int>(exit_status::success);
      }
      
      if (show_help) {
        console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
        return as<int>(exit_status::success);
      }
      
      for (auto index = 0; index < count; index++)
        console::write_line(guid::new_guid().to_string(format));
      return as<int>(exit_status::success);
    }
    
  private:
    static auto get_error() noexcept -> ustring {
      return "guidgen : invalid params\n"
        "Try 'guidgen --help' for more information.";
    }
    
    static auto get_usage() noexcept -> ustring {
      return "Usage\n"
        "  guidgen [--format Format] [--count Count]\n"
        "\n"
        "-f, --format  : Indicates how to format the value of this Guid. The format parameter can be :\n"
        "                  N : 32 digits.\n"
        "                  D : 32 digits separated by hyphens.\n"
        "                  B : 32 digits separated by hyphens, enclosed in braces.\n"
        "                  P : 32 digits separated by hyphens, enclosed in parentheses.\n"
        "                  X : Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces.\n"
        "-c, --count   : indicate the number of generation (form 1 to 2147483647)\n"
        "-v, --version : Shows version information.\n"
        "-h, --help    : Shows this help page.";
    }
    
    static auto get_version() noexcept -> ustring {
      return ustring::format("guidgen version {}, (c) {:L} by Gammasoft", environment::version(), date_time::now());
    }
    
    static auto process_arguments(const std::vector<ustring>& args, ustring& format, int& count, bool& show_version, bool& show_help) noexcept -> bool {
      try {
        for (auto index = 0_sz; index < args.size(); index += 1) {
          static constexpr auto format_types = {"N", "D", "B", "P", "X"};
          if ((args[index] == "-f" || args[index] == "--format") && index + 1 < args.size() && std::count(format_types.begin(), format_types.end(), args[index + 1])) format = args[index++ + 1];
          else if ((args[index] == "-c" || args[index] == "--count") && index + 1 < args.size() && ustring::try_parse(args[index++ + 1], count) && count >= 1) ; // nothing to do all is done
          else if (args[index] == "-v" || args[index] == "--version") show_version = true;
          else if (args[index] == "-h" || args[index] == "--help") show_help = true;
          else return false;
        }
        return true;
      } catch(...) {
        return false;
      }
    }
  };
}

startup_(guidgen::program::main);
