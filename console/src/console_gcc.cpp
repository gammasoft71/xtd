#if defined(__linux__) || defined(__APPLE__)

#include "../include/console.hpp"

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

using namespace gammasoft;
using namespace std;

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
  };
  
  static terminal term;
  static console_color backColor = console_color::black;
  static console_color foreColor = console_color::white;
  static bool cursorVisible = true;
}

console_color console::background_color() noexcept {
  return backColor;
}

bool console::background_color(console_color color) noexcept {
  static map<console_color, const char*> colors {{console_color::black, "\033[40m"}, {console_color::dark_blue, "\033[44m"}, {console_color::dark_green, "\033[42m"}, {console_color::dark_cyan, "\033[46m"}, {console_color::dark_red, "\033[41m"}, {console_color::dark_magenta, "\033[45m"}, {console_color::dark_yellow, "\033[43m"}, {console_color::gray, "\033[47m"}, {console_color::dark_gray, "\033[100m"}, {console_color::blue, "\033[104m"}, {console_color::green, "\033[102m"}, {console_color::cyan, "\033[106m"}, {console_color::red, "\033[101m"}, {console_color::magenta, "\033[105m"}, {console_color::yellow, "\033[103m"}, {console_color::white, "\033[107m"}};
  if (!terminal::is_ansi_supported() && colors.find(color) != colors.end()) return false;
  cout << colors[color] << flush;
  backColor = color;
  return true;
}

bool console::beep(unsigned int frequency, unsigned int duration) noexcept {
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

int console::buffer_height() noexcept {
  /// @todo console buffer Height on linux and macOS
  return window_height();
}

int console::buffer_width() noexcept {
  /// @todo console buffer Width on linux and macOS
  return window_width();
}

bool console::caps_lock() noexcept {
  /// @todo caps lock status on linux and macOS
  return false;
}

bool console::clrscr() noexcept {
  if (!terminal::is_ansi_supported()) return false;
  std::cout << "\x1b[H\x1b[2J" << std::flush;
  return true;
}

int console::cursor_left() noexcept {
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

int console::cursor_size() noexcept {
  return 100;
}

void console::cursor_size(int size) noexcept {
  if (terminal::is_ansi_supported()) {
    if (size < 50)
      std::cout << "\x1b[4 q" << std::flush;
    else
      std::cout << "\x1b[2 q" << std::flush;
  }
}

int console::cursor_top() noexcept {
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

bool console::cursor_visible() noexcept {
  return cursorVisible;
}

void console::cursor_visible(bool visible) noexcept {
  if (terminal::is_ansi_supported()) {
    cursorVisible = visible;
    std::cout << (cursorVisible ? "\x1b[?25h" : "\x1b[?25l") << std::flush;
  }
}

console_color console::foreground_color() noexcept {
  return foreColor;
}

bool console::foreground_color(console_color color) noexcept {
  static map<console_color, const char*> colors {{console_color::black, "\033[30m"}, {console_color::dark_blue, "\033[34m"}, {console_color::dark_green, "\033[32m"}, {console_color::dark_cyan, "\033[36m"}, {console_color::dark_red, "\033[31m"}, {console_color::dark_magenta, "\033[35m"}, {console_color::dark_yellow, "\033[33m"}, {console_color::gray, "\033[37m"}, {console_color::dark_gray, "\033[90m"}, {console_color::blue, "\033[94m"}, {console_color::green, "\033[92m"}, {console_color::cyan, "\033[96m"}, {console_color::red, "\033[91m"}, {console_color::magenta, "\033[95m"}, {console_color::yellow, "\033[93m"}, {console_color::white, "\033[97m"}};
  if (!terminal::is_ansi_supported() && colors.find(color) != colors.end()) return false;
  cout << colors[color] << flush;
  foreColor = color;
  return true;
}

int console::input_code_page() noexcept {
  /// @todo console input code page status on linux and macOS
  return 65001;
}

bool console::input_code_page(int codePage) noexcept {
  /// @todo set console input code page on linux and macOS
  return true;
}

int console::output_code_page() noexcept {
  /// @todo console output code page status on linux and macOS
  return 65001;
}

bool console::output_code_page(int codePage) noexcept {
  /// @todo set console output code page on linux and macOS
  return true;
}

bool console::reset_color() noexcept {
  if (!terminal::is_ansi_supported()) return false;
  cout << "\033[49m\033[39m" << flush;
  return true;
}

bool console::set_cursor_position(int left, int top) noexcept {
  if (!terminal::is_ansi_supported()) return false;
  std::cout << "\x1b[" << top + 1 << ";" << left + 1 << "f" << std::flush;
  return true;
}

int console::window_left() noexcept {
  /// @todo get console window left on linux and macOS
  return 0;
}

int console::window_height() noexcept {
  if (!terminal::is_ansi_supported()) return 24;
  int top = cursor_top();
  set_cursor_position(cursor_left(), 999);
  int height = cursor_top() + 1;
  set_cursor_position(cursor_left(), top);
  return height;
}

int console::window_top() noexcept {
  /// @todo get console window top on linux and macOS
  return 0;
}

int console::window_width() noexcept {
  if (!terminal::is_ansi_supported()) return 80;
  int left = cursor_left();
  set_cursor_position(999, cursor_top());
  int width = cursor_left() + 1;
  set_cursor_position(left, cursor_top());
  return width;
}

#endif
