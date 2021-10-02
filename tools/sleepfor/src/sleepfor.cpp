#include <xtd/xtd.core>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::chrono;
using namespace std::this_thread;
using namespace xtd;

namespace sleepfor {
  class program final static_ {
    enum class period_type {nanoseconds, microseconds, milliseconds, seconds, minutes};

  public:
    static int main(const vector<ustring>& args) {
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
      else if (indefinitely) while(true) sleep_for(hours(numeric_limits<int32_t>::max()));
      else if (type == period_type::nanoseconds) sleep_for(nanoseconds(duration));
      else if (type == period_type::seconds) sleep_for(seconds(duration));
      else if (type == period_type::minutes) sleep_for(minutes(duration));
      else sleep_for(milliseconds(duration));
      return 0;
    }
    
  private:
    static string get_error() {
      return "sleepfor : invalid params\n"
      "Try 'sleepfor --help' for more information.";
    }
    
    static string get_usage() {
      return "Usage\n"
      "  sleepfor [duration] [--nanoseconds|--milliseconds|--seconds|--minutes|]\n"
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
      return ustring::format("sleepfor version {}, © {:L} by Gammasoft", environment::version(), chrono::system_clock::now());
    }

    static bool process_arguments(const vector<ustring>& args, int32_t& duration, period_type& type, bool& indefinitely, bool& show_version, bool& show_help) {
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

startup_(sleepfor::program);
