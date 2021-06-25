#if defined(__linux__) || defined(__APPLE__)

#include <unistd.h>
#include <map>
#include "../../../include/xtd/tunit/__console_color.h"

namespace {
  bool is_ansi_supported() noexcept {
    static std::string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
    return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
  }
}

void __opaque_foreground_color(__console_color color) {
  if (is_ansi_supported()) {
    static std::map<__console_color, const char*> colors {{__console_color::black, "\033[30m"}, {__console_color::dark_blue, "\033[34m"}, {__console_color::dark_green, "\033[32m"}, {__console_color::dark_cyan, "\033[36m"}, {__console_color::dark_red, "\033[31m"}, {__console_color::dark_magenta, "\033[35m"}, {__console_color::dark_yellow, "\033[33m"}, {__console_color::gray, "\033[37m"}, {__console_color::dark_gray, "\033[90m"}, {__console_color::blue, "\033[94m"}, {__console_color::green, "\033[92m"}, {__console_color::cyan, "\033[96m"}, {__console_color::red, "\033[91m"}, {__console_color::magenta, "\033[95m"}, {__console_color::yellow, "\033[93m"}, {__console_color::white, "\033[97m"}};
    std::cout << colors[color] << std::flush;
  }
}

void __opaque_reset_color() {
  if (is_ansi_supported()) std::cout << "\033[49m\033[39m" << std::flush;
}
#endif
