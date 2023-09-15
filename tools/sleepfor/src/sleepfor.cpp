#include <xtd/console>
#include <xtd/environment>
#include <xtd/startup>
#include <xtd/ustring>
#include <xtd/chrono>
#include <xtd/threading/thread>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::threading;

namespace sleepfor {
  class program final static_ {
    enum class period_type {nanoseconds, microseconds, milliseconds, seconds, minutes};
    
  public:
    static auto main(const vector<ustring>& args) {
      int duration = 0;
      period_type type = period_type::milliseconds;
      bool indefinitely = false;
      bool show_version = false;
      bool show_help = false;
      if (!process_arguments(args, duration, type, indefinitely, show_version, show_help)) {
        console::write_line(get_error());
        return -1;
      }
      
      if (show_version) console::write_line(get_version());
      else if (show_help) console::write_line("{0}{1}{1}{2}", get_version(), environment::new_line(), get_usage());
      else if (indefinitely) while (true) threading::thread::sleep(hours(numeric_limits<int32>::max()));
      else if (type == period_type::nanoseconds) threading::thread::sleep(std::chrono::nanoseconds(duration));
      else if (type == period_type::seconds) threading::thread::sleep(seconds(duration));
      else if (type == period_type::minutes) threading::thread::sleep(minutes(duration));
      else threading::thread::sleep(milliseconds(duration));
      return 0;
    }
    
  private:
    static string get_error() {
      return "sleepfor : invalid params\n"
        "Try 'sleepfor --help' for more information.";
    }
    
    static string get_usage() {
      return "Usage\n"
        "  sleepfor [duration] [--nanoseconds| -milliseconds| -seconds| -minutes|]\n"
        "\n"
        "-ns, --nanoseconds  : The specified duration is in nanoseconds.\n"
        "-ms, --milliseconds : The specified duration is in milliseconds. Is the default.\n"
        "-s, --seconds       : The specified duration is in seconds.\n"
        "-m, --minutes       : The specified duration is in minutes.\n"
        "-i, --indefinitely  : sleep indefinitely.\n"
        "-v, --version       : Shows version information.\n"
        "-h, --help          : Shows this help page.";
    }
    
    static string get_version() {
      return ustring::format("sleepfor version {}, (c) {:L} by Gammasoft", environment::version(), date_time::now());
    }
    
    static bool process_arguments(const vector<ustring>& args, int32& duration, period_type& type, bool& indefinitely, bool& show_version, bool& show_help) {
      for (size_t index = 0; index < args.size(); index += 1) {
        if (args[index] == "-ns" || args[index] == "--nanoseconds") type = period_type::nanoseconds;
        else if (args[index] == "-ms" || args[index] == "--milliseconds") type = period_type::milliseconds;
        else if (args[index] == "-s" || args[index] == "--seconds") type = period_type::seconds;
        else if (args[index] == "-m" || args[index] == "--minutes") type = period_type::minutes;
        else if (args[index] == "-i" || args[index] == "--indefinitely") indefinitely = true;
        else if (args[index] == "-v" || args[index] == "--version") show_version = true;
        else if (args[index] == "-h" || args[index] == "--help") show_help = true;
        else if (!try_parse(args[index], duration)) return false;
      }
      return true;
    }
  };
}

startup_(sleepfor::program::main);
