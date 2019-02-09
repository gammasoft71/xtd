#if defined(__linux__) || defined(__APPLE__)

#include "../include/console/__opaque_console.hpp"

#include <csignal>
#include <iostream>
#include <map>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

#if __APPLE__
#ifndef KIOCSOUND
const int KIOCSOUND = 0x4B2F;
#endif
#else
#include <linux/kd.h>
#endif

namespace {
  class terminal final {
  public:
    terminal() noexcept {
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      this->backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ECHO;
      tcsetattr(0, TCSANOW, &termioAttributes);
    }
    
    ~terminal() noexcept {
      tcsetattr(0, TCSANOW, &this->backupedTermioAttributes);
      if (is_ansi_supported())
        std::cout << "\x1b]0;\x7" << std::flush;
    }
    
    int getch() noexcept {
      if (this->peekCharacter != -1) {
        int8_t character = this->peekCharacter;
        this->peekCharacter = -1;
        return character;
      }
      
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      termios backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ICANON;
      termioAttributes.c_cc[VTIME] = 0;
      termioAttributes.c_cc[VMIN] = 1;
      tcsetattr(0, TCSANOW, &termioAttributes);
      
      int8_t character = 0;
      while (read(0, &character, 1) != 1);
      
      tcsetattr(0, TCSANOW, &backupedTermioAttributes);
      
      return character;
    }
    
    bool key_available() noexcept {
      if (this->peekCharacter != -1)
        return true;
      
      termios termioAttributes;
      tcgetattr(0, &termioAttributes);
      termios backupedTermioAttributes = termioAttributes;
      termioAttributes.c_lflag &= ~ICANON;
      termioAttributes.c_cc[VTIME] = 0;
      termioAttributes.c_cc[VMIN] = 0;
      tcsetattr(0, TCSANOW, &termioAttributes);
      
      read(0, &this->peekCharacter, 1);
      
      tcsetattr(0, TCSANOW, &backupedTermioAttributes);
      
      return this->peekCharacter != -1;
    }
    
    static bool is_ansi_supported() noexcept {
      static std::string terminal = getenv("TERM") == nullptr ? "" : getenv("TERM");
      return isatty(fileno(stdout)) && (terminal == "xterm" || terminal == "xterm-color" || terminal == "xterm-256color" || terminal == "screen" || terminal == "screen-256color" || terminal == "linux" || terminal == "cygwin");
    }
    
  private:
    int8_t peekCharacter {-1};
    termios backupedTermioAttributes;
  } term;
  
  xtd::console_color backColor = xtd::console_color::black;
  xtd::console_color foreColor = xtd::console_color::white;
  bool cursorVisible = true;
}

xtd::console_color __opaque_console::background_color() noexcept {
  return backColor;
}

bool __opaque_console::background_color(xtd::console_color color) noexcept {
  static std::map<xtd::console_color, const char*> colors {{xtd::console_color::black, "\033[40m"}, {xtd::console_color::dark_blue, "\033[44m"}, {xtd::console_color::dark_green, "\033[42m"}, {xtd::console_color::dark_cyan, "\033[46m"}, {xtd::console_color::dark_red, "\033[41m"}, {xtd::console_color::dark_magenta, "\033[45m"}, {xtd::console_color::dark_yellow, "\033[43m"}, {xtd::console_color::gray, "\033[47m"}, {xtd::console_color::dark_gray, "\033[100m"}, {xtd::console_color::blue, "\033[104m"}, {xtd::console_color::green, "\033[102m"}, {xtd::console_color::cyan, "\033[106m"}, {xtd::console_color::red, "\033[101m"}, {xtd::console_color::magenta, "\033[105m"}, {xtd::console_color::yellow, "\033[103m"}, {xtd::console_color::white, "\033[107m"}};
  if (!terminal::is_ansi_supported() && colors.find(color) != colors.end()) return false;
  std::cout << colors[color] << std::flush;
  backColor = color;
  return true;
}

bool __opaque_console::beep(unsigned int frequency, unsigned int duration) noexcept {
  if (frequency < 37 || frequency > 32767)
    return false;

  int fd = open("/dev/console", O_WRONLY);
  if (fd == -1)
    std::cout << "\a" << std::flush;
  else {
    if (ioctl(fd, KIOCSOUND, (int)(1193180 / frequency)) < 0)
      std::cout << "\a" << std::flush;
    else {
      usleep(1000 * duration);
      ioctl(fd, KIOCSOUND, 0);
    }
    close(fd);
  }
  return true;
}

int __opaque_console::buffer_height() noexcept {
  /// @todo console buffer Height on linux and macOS
  return __opaque_console::window_height();
}

bool __opaque_console::buffer_height(int height) noexcept {
  /// @todo set console buffer height on linux and macOS
  return true;
}

int __opaque_console::buffer_width() noexcept {
  /// @todo console buffer Width on linux and macOS
  return __opaque_console::window_width();
}

bool __opaque_console::buffer_width(int width) noexcept {
  /// @todo set console buffer width on linux and macOS
  return true;
}

bool __opaque_console::caps_lock() noexcept {
  /// @todo caps lock status on linux and macOS
  return false;
}

bool __opaque_console::clear() noexcept {
  if (!terminal::is_ansi_supported()) return false;
  std::cout << "\x1b[H\x1b[2J" << std::flush;
  return true;
}

int __opaque_console::cursor_left() noexcept {
  if (!terminal::is_ansi_supported()) return 0;
  std::cout << "\x1b[6n" << std::flush;
  term.getch();
  term.getch();
  for (char c = term.getch(); c != ';'; c = term.getch());
  std::string left;
  for (char c = term.getch(); c != 'R'; c = term.getch())
    left.push_back(c);
  return atoi(left.c_str()) - 1;
}

int __opaque_console::cursor_size() noexcept {
  return 100;
}

void __opaque_console::cursor_size(int size) noexcept {
  if (terminal::is_ansi_supported()) {
    if (size < 50)
      std::cout << "\x1b[4 q" << std::flush;
    else
      std::cout << "\x1b[2 q" << std::flush;
  }
}

int __opaque_console::cursor_top() noexcept {
  if (!terminal::is_ansi_supported()) return 0;
  std::cout << "\x1b[6n" << std::flush;
  term.getch();
  term.getch();
  std::string top;
  for (char c = term.getch(); c != ';'; c = term.getch())
    top.push_back(c);
  for (char c = term.getch(); c != 'R'; c = term.getch());
  return atoi(top.c_str()) - 1;
}

bool __opaque_console::cursor_visible() noexcept {
  return cursorVisible;
}

void __opaque_console::cursor_visible(bool visible) noexcept {
  if (terminal::is_ansi_supported()) {
    cursorVisible = visible;
    std::cout << (cursorVisible ? "\x1b[?25h" : "\x1b[?25l") << std::flush;
  }
}

xtd::console_color __opaque_console::foreground_color() noexcept {
  return foreColor;
}

bool __opaque_console::foreground_color(xtd::console_color color) noexcept {
  static std::map<xtd::console_color, const char*> colors {{xtd::console_color::black, "\033[30m"}, {xtd::console_color::dark_blue, "\033[34m"}, {xtd::console_color::dark_green, "\033[32m"}, {xtd::console_color::dark_cyan, "\033[36m"}, {xtd::console_color::dark_red, "\033[31m"}, {xtd::console_color::dark_magenta, "\033[35m"}, {xtd::console_color::dark_yellow, "\033[33m"}, {xtd::console_color::gray, "\033[37m"}, {xtd::console_color::dark_gray, "\033[90m"}, {xtd::console_color::blue, "\033[94m"}, {xtd::console_color::green, "\033[92m"}, {xtd::console_color::cyan, "\033[96m"}, {xtd::console_color::red, "\033[91m"}, {xtd::console_color::magenta, "\033[95m"}, {xtd::console_color::yellow, "\033[93m"}, {xtd::console_color::white, "\033[97m"}};
  if (!terminal::is_ansi_supported() && colors.find(color) != colors.end()) return false;
  std::cout << colors[color] << std::flush;
  foreColor = color;
  return true;
}

int __opaque_console::input_code_page() noexcept {
  /// @todo console input code page status on linux and macOS
  return 65001;
}

bool __opaque_console::input_code_page(int codePage) noexcept {
  /// @todo set console input code page on linux and macOS
  return true;
}

int __opaque_console::output_code_page() noexcept {
  /// @todo console output code page status on linux and macOS
  return 65001;
}

bool __opaque_console::output_code_page(int codePage) noexcept {
  /// @todo set console output code page on linux and macOS
  return true;
}

bool __opaque_console::reset_color() noexcept {
  if (!terminal::is_ansi_supported()) return false;
  std::cout << "\033[49m\033[39m" << std::flush;
  return true;
}

bool __opaque_console::set_cursor_position(int left, int top) noexcept {
  if (!terminal::is_ansi_supported()) return false;
  std::cout << "\x1b[" << top + 1 << ";" << left + 1 << "f" << std::flush;
  return true;
}

std::map<int, xtd::console_special_key> __opaque_console::signal_keys() noexcept {
  return {{SIGQUIT, xtd::console_special_key::control_backslash}, {SIGTSTP, xtd::console_special_key::control_z}, {SIGINT, xtd::console_special_key::control_c}};
}

int __opaque_console::window_left() noexcept {
  /// @todo get console window left on linux and macOS
  return 0;
}

int __opaque_console::window_height() noexcept {
  if (!terminal::is_ansi_supported()) return 24;
  int top = __opaque_console::cursor_top();
  __opaque_console::set_cursor_position(__opaque_console::cursor_left(), 999);
  int height = __opaque_console::cursor_top() + 1;
  __opaque_console::set_cursor_position(__opaque_console::cursor_left(), top);
  return height;
}

int __opaque_console::window_top() noexcept {
  /// @todo get console window top on linux and macOS
  return 0;
}

int __opaque_console::window_width() noexcept {
  if (!terminal::is_ansi_supported()) return 80;
  int left = __opaque_console::cursor_left();
  __opaque_console::set_cursor_position(999, __opaque_console::cursor_top());
  int width = __opaque_console::cursor_left() + 1;
  __opaque_console::set_cursor_position(left, __opaque_console::cursor_top());
  return width;
}

#endif
