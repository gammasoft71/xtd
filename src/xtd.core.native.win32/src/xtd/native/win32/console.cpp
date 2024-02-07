#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/console>
#include <xtd/native/console_special_key>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <csignal>
#include <conio.h>
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

namespace {
  std::function<bool(int_least32_t)> user_cancel_callback;
  
  int_least32_t __default_background_color() {
    static auto color = CONSOLE_COLOR_DEFAULT;
    if (color != CONSOLE_COLOR_DEFAULT) return color;
    auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) != TRUE) color = 0x00;
    color = (csbi.wAttributes & 0x00F0) >> 4;
    return color;
  }
  
  int_least32_t __default_foreground_color() {
    static auto color = CONSOLE_COLOR_DEFAULT;
    if (color != CONSOLE_COLOR_DEFAULT) return color;
    auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) != TRUE) color = 0x07;
    color = csbi.wAttributes & 0x000F;
    return color;
  }
  
  BOOL WINAPI __handler_routine(DWORD ctrl_type) {
    if (user_cancel_callback && (ctrl_type == CTRL_C_EVENT || ctrl_type == CTRL_BREAK_EVENT))
      return user_cancel_callback(ctrl_type == CTRL_C_EVENT ? CONSOLE_SPECIAL_KEY_CTRL_C : CONSOLE_SPECIAL_KEY_CTRL_BREAK) == TRUE;
    return FALSE;
  }
  
  bool init_treat_control_c_as_input = []()-> bool {
    SetConsoleCtrlHandler(&__handler_routine, TRUE);
    return false;
  }();
  bool echo_off = []()-> bool {
    auto mode = DWORD {};
    GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
    return SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode & ~ENABLE_ECHO_INPUT) == TRUE;
  }();

  bool treat_control_c_as_input =  false;
  auto background_color = CONSOLE_COLOR_DEFAULT;
  auto foreground_color = CONSOLE_COLOR_DEFAULT;
  auto buffer_height = -1;
  auto buffer_width = -1;
  auto caps_lock = false;
  auto cursor_left = 0;
  auto cursor_size = 100;
  auto cursor_top = 0;
  auto cursor_visible = true;
  auto input_code_page = 65001;
  auto largest_window_height = 1000;
  auto largest_window_width = 1000;
  auto number_lock = true;
  auto output_code_page = 65001;
  std::string title;
  auto window_height = -1;
  auto window_left = 0;
  auto window_top = 0;
  auto window_width = -1;
  
  class terminal final {
  public:
    static terminal terminal_;
    
    void force_compiler_optimizer_to_create_object() {
    }
    
  private:
    terminal() = default;
    ~terminal() {
      auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
      
      csbi.wAttributes &= 0xFF0F;
      csbi.wAttributes |= ((int_least32_t)background_color_ << 4) | (int_least32_t)foreground_color_;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
    }
    
    int_least32_t background_color_ = __default_background_color();
    int_least32_t foreground_color_ = __default_foreground_color();
  };
  
  terminal terminal::terminal_;
}

int_least32_t console::background_color() {
  return ::background_color;
}

bool console::background_color(int_least32_t color) {
  ::background_color = color;
  terminal::terminal_.force_compiler_optimizer_to_create_object();
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFF0F;
  csbi.wAttributes |= (color == CONSOLE_COLOR_DEFAULT ? __default_background_color() : color) << 4;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool console::beep(uint_least32_t frequency, uint_least32_t duration) {
  if (frequency < 37 || frequency > 32767) return false;
  return Beep(frequency, duration) == TRUE;
}

int_least32_t console::buffer_height() {
  /*
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::buffer_height = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.dwSize.Y : console::window_height();
   */
  if (::buffer_height == -1) ::buffer_height = console::window_height();
  return ::buffer_height;
}

bool console::buffer_height(int_least32_t height) {
  ::buffer_height = height;
  /*
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.Y = static_cast<int_least16_t>(height);
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
   */
  return true;
}

int_least32_t console::buffer_width() {
  /*
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::buffer_width = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.dwSize.X : console::window_width();
   */
  if (::buffer_width == -1) ::buffer_width = console::window_width();
  return ::buffer_width;
}

bool console::buffer_width(int_least32_t width) {
  ::buffer_width = width;
  /*
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.X = static_cast<int_least16_t>(width);
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
   */
  return true;
}

bool console::caps_lock() {
  ::caps_lock = (GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
  return ::caps_lock;
}

bool console::clear() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  const auto coord = COORD {0, 0};
  auto nbCharsWritten = DWORD {};
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  return console::set_cursor_position(0, 0);
}

int_least32_t console::cursor_left() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE) ::cursor_left = csbi.dwCursorPosition.X;
  return ::cursor_left;
}

int_least32_t console::cursor_size() {
  auto cci = CONSOLE_CURSOR_INFO {};
  if (GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci) == TRUE) ::cursor_size = cci.dwSize;
  return ::cursor_size;
}

bool console::cursor_size(int_least32_t size) {
  ::cursor_size = size;
  auto cci = CONSOLE_CURSOR_INFO {};
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.dwSize = size;
  return SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci) == TRUE;
}

int_least32_t console::cursor_top() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE) ::cursor_top = csbi.dwCursorPosition.Y;
  return ::cursor_top;
}

bool console::cursor_visible() {
  auto cci = CONSOLE_CURSOR_INFO {};
  if (GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci) == TRUE) ::cursor_visible = cci.bVisible != FALSE;
  return ::cursor_visible;
}

bool console::cursor_visible(bool visible) {
  ::cursor_visible = visible;
  auto cci = CONSOLE_CURSOR_INFO {};
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  cci.bVisible = visible;
  return SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci) == TRUE;
}

bool console::echo(bool on) {
  auto mode = DWORD {};
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  if (on) mode |= ENABLE_ECHO_INPUT;
  else mode &= ~ENABLE_ECHO_INPUT;
  return SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode) == TRUE;
}

int_least32_t console::foreground_color() {
  return ::foreground_color;
}

bool console::foreground_color(int_least32_t color) {
  ::foreground_color = color;
  terminal::terminal_.force_compiler_optimizer_to_create_object();
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= (color == CONSOLE_COLOR_DEFAULT ? __default_foreground_color() : color);
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

int_least32_t console::input_code_page() {
  ::input_code_page = GetConsoleCP();
  return ::input_code_page;
}

bool console::input_code_page(int_least32_t code_page) {
  ::input_code_page = code_page;
  return SetConsoleCP(code_page) == TRUE;
}

bool console::key_available() {
  return _kbhit() != 0;
}

int_least32_t console::largest_window_height() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE) ::largest_window_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
  return ::largest_window_height;
}

int_least32_t console::largest_window_width() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE) ::largest_window_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
  return ::largest_window_width;
}

bool console::number_lock() {
  ::number_lock = (GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
  return ::number_lock;
}

int_least32_t console::output_code_page() {
  ::output_code_page = GetConsoleOutputCP();
  return ::output_code_page;
}

bool console::output_code_page(int_least32_t code_page) {
  ::output_code_page = code_page;
  return SetConsoleOutputCP(code_page) == TRUE;
}

void console::read_key(char32_t& key_char, char32_t& key_code, bool& alt, bool& shift, bool& ctrl) {
  auto input_record = INPUT_RECORD {};
  do {
    auto nb_events_read = DWORD {};
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &input_record, 1, &nb_events_read);
  } while (!(input_record.EventType == KEY_EVENT && (input_record.Event.KeyEvent.bKeyDown == 1 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x10 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x11 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x12)));
  
  key_char = input_record.Event.KeyEvent.uChar.UnicodeChar;
  key_code = input_record.Event.KeyEvent.wVirtualKeyCode;
  alt = (input_record.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED || (input_record.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED;
  shift = (input_record.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED) == SHIFT_PRESSED;
  ctrl = (input_record.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED || (input_record.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED;
}

void console::register_user_cancel_callback(std::function<bool(int_least32_t)> user_cancel_callback) {
  ::user_cancel_callback = user_cancel_callback;
}

bool console::reset_color() {
  return console::background_color(CONSOLE_COLOR_DEFAULT) && console::foreground_color(CONSOLE_COLOR_DEFAULT);
}

bool console::set_cursor_position(int_least32_t left, int_least32_t top) {
  ::cursor_left = left;
  ::cursor_top = top;
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.X = static_cast<int_least16_t>(left);
  csbi.dwCursorPosition.Y = static_cast<int_least16_t>(top);
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition) == TRUE;
}

std::string console::title() {
  auto title = std::wstring {MAX_PATH, 0};
  ::title =  GetConsoleTitle(title.data(), MAX_PATH) == 0 ? "" : win32::strings::to_string(title);
  return ::title;
}

bool console::title(const std::string& title) {
  ::title = title;
  return SetConsoleTitle(win32::strings::to_wstring(title).c_str()) == TRUE;
}

bool console::treat_control_c_as_input() {
  //auto mode = DWORD {};
  //::treat_control_c_as_input = GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode) == TRUE ? (mode & ENABLE_PROCESSED_INPUT) != ENABLE_PROCESSED_INPUT : false;
  return ::treat_control_c_as_input;
}

bool console::treat_control_c_as_input(bool treat_control_c_as_input) {
  ::treat_control_c_as_input = treat_control_c_as_input;
  auto mode = DWORD {};
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  if (treat_control_c_as_input) mode &= ~ENABLE_PROCESSED_INPUT;
  else mode |= ENABLE_PROCESSED_INPUT;
  return SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode) == TRUE;
}

int_least32_t console::window_height() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::window_height = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.srWindow.Bottom - csbi.srWindow.Top + 1 : 25;
  return ::window_height;
}

bool console::window_height(int_least32_t height) {
  ::window_height = height;
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Bottom = static_cast<int_least16_t>(csbi.srWindow.Top + height - 1);
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

int_least32_t console::window_left() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::window_left = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.srWindow.Left : 0;
  return ::window_left;
}

bool console::window_left(int_least32_t left) {
  ::window_left = left;
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Left = static_cast<int_least16_t>(left);
  csbi.srWindow.Right += static_cast<int_least16_t>(left);

  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

int_least32_t console::window_top() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::window_top = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.srWindow.Top : 0;
  return ::window_top;
}

bool console::window_top(int_least32_t top) {
  ::window_top = top;
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Top = static_cast<int_least16_t>(top);
  csbi.srWindow.Bottom += static_cast<int_least16_t>(top);
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}

int_least32_t console::window_width() {
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  ::window_width = GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi) == TRUE ? csbi.srWindow.Right - csbi.srWindow.Left + 1 : 80;
  return ::window_width;
}

bool console::window_width(int_least32_t width) {
  ::window_width = width;
  auto csbi = CONSOLE_SCREEN_BUFFER_INFO {};
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.srWindow.Right = static_cast<int_least16_t>(csbi.srWindow.Left + width - 1);
  return SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &csbi.srWindow) == TRUE;
}
