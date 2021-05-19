#include <xtd/native/console.h>
#include <xtd/native/console_color.h>
#include <xtd/native/console_special_key.h>

#include <csignal>
#include <conio.h>
#include <Windows.h>
#undef max
#undef min

using namespace xtd::native;

namespace {
  std::function<bool(int32_t)> user_cancel_callback;

  int32_t __background_color() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return (csbi.wAttributes & 0x00F0) >> 4;
  }

  int32_t __foreground_color() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.wAttributes & 0x000F;
  }

  BOOL WINAPI __handler_routine(DWORD ctrl_type) {
    if (ctrl_type == CTRL_C_EVENT || ctrl_type == CTRL_BREAK_EVENT) {
      //xtd::console_cancel_event_args console_cancel(false, ctrl_type == CTRL_C_EVENT ? xtd::console_special_key::control_c : xtd::console_special_key::control_break);
      //xtd::console::__internal_cancel_key_press__(console_cancel);
      //return console_cancel.cancel() == TRUE;
      return user_cancel_callback && user_cancel_callback(ctrl_type == CTRL_C_EVENT ? CONSOLE_SPECIAL_KEY_CTRL_C : CONSOLE_SPECIAL_KEY_CTRL_BREAK) == true;
    }
    return FALSE;
  }

  int32_t backColor = __background_color();
  int32_t foreColor = __foreground_color();
  bool treat_control_c_as_input = [&]()-> bool {
    SetConsoleCtrlHandler(&__handler_routine, TRUE);
    return false;
  }();

  class terminal final {
  public:
    static terminal terminal_;

    void force_compiler_optimizer_to_create_object() {
    }

  private:
    terminal() = default;
    ~terminal() {
      CONSOLE_SCREEN_BUFFER_INFO csbi;
      GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

      csbi.wAttributes &= 0xFF0F;
      csbi.wAttributes |= ((int32_t)backColor_ << 4) | (int32_t)foreColor_;
      SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
    }

    int32_t backColor_ = __background_color();
    int32_t foreColor_ = __foreground_color();
  };

  terminal terminal::terminal_;
}

int32_t console::background_color() {
  return __background_color();
}

void console::background_color(int32_t color) {
  terminal::terminal_.force_compiler_optimizer_to_create_object();
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFF0F;
  csbi.wAttributes |= color << 4;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
}

void console::beep(uint32_t frequency, uint32_t duration) {
  if (frequency < 37 || frequency > 32767) return;
  
  Beep(frequency, duration);
}

int32_t console::buffer_height() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.Y;
}

void console::buffer_height(int32_t height) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.Y = static_cast<int16_t>(height);
  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize);
}

int32_t console::buffer_width() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.X;
}

void console::buffer_width(int32_t width) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.X = static_cast<int16_t>(width);
  SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize);
}

bool console::caps_lock() {
  return (GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
}

void console::clear() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  console::set_cursor_position(0, 0);
}

int32_t console::cursor_left() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.X;
}

int32_t console::cursor_size() {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  return cci.dwSize;
}

void console::cursor_size(int32_t size) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int32_t console::cursor_top() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.Y;
}

bool console::cursor_visible() {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  return cci.bVisible != FALSE;
}

void console::cursor_visible(bool visible) {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int32_t console::foreground_color() {
  return __foreground_color();
}

void console::foreground_color(int32_t color) {
  terminal::terminal_.force_compiler_optimizer_to_create_object();
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= color;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
}

int32_t console::input_code_page() {
  return GetConsoleCP();
}

void console::input_code_page(int32_t codePage) {
  SetConsoleCP(codePage);
}

bool console::key_available() {
  return _kbhit() != 0;
}

int32_t console::largest_window_height() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int32_t console::largest_window_width() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

bool console::number_lock() {
  return (GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
}

int32_t console::output_code_page() {
  return GetConsoleOutputCP();
}

void console::output_code_page(int32_t codePage) {
  SetConsoleOutputCP(codePage) == TRUE;
}

void console::read_key(int32_t& key_char, int32_t& key_code, bool& alt, bool& shift, bool& ctrl) {
  INPUT_RECORD input_record;
  do {
    DWORD nb_events_read = 0;
    ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &input_record, 1, &nb_events_read);
  } while (!(input_record.EventType == KEY_EVENT && (input_record.Event.KeyEvent.bKeyDown == 1 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x10 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x11 && input_record.Event.KeyEvent.wVirtualKeyCode != 0x12)));
  
  key_char = input_record.Event.KeyEvent.uChar.AsciiChar;
  key_code = input_record.Event.KeyEvent.wVirtualKeyCode;
  alt = (input_record.Event.KeyEvent.dwControlKeyState & LEFT_ALT_PRESSED) == LEFT_ALT_PRESSED || (input_record.Event.KeyEvent.dwControlKeyState & RIGHT_ALT_PRESSED) == RIGHT_ALT_PRESSED;
  shift = (input_record.Event.KeyEvent.dwControlKeyState & SHIFT_PRESSED) == SHIFT_PRESSED;
  ctrl = (input_record.Event.KeyEvent.dwControlKeyState & LEFT_CTRL_PRESSED) == LEFT_CTRL_PRESSED || (input_record.Event.KeyEvent.dwControlKeyState & RIGHT_CTRL_PRESSED) == RIGHT_CTRL_PRESSED;
}

void console::register_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback) {
  ::user_cancel_callback = user_cancel_callback;
}

void console::reset_color() {
  console::background_color(backColor);
  console::foreground_color(foreColor);
}

void console::set_cursor_position(int32_t left, int32_t top) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.X = static_cast<int16_t>(left);
  csbi.dwCursorPosition.Y = static_cast<int16_t>(top);
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition);
}

std::string console::title() {
  char title[MAX_PATH];
  if (GetConsoleTitle(title, MAX_PATH) == 0) return "";
  return title;
}

void console::title(const std::string& title) {
  SetConsoleTitle(title.c_str());
}

bool console::treat_control_c_as_input() {
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  return  (mode & ENABLE_PROCESSED_INPUT) != ENABLE_PROCESSED_INPUT;
}

void console::treat_control_c_as_input(bool treat_control_c_as_input) {
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  if (treat_control_c_as_input)
    mode &= ~ENABLE_PROCESSED_INPUT;
  else
    mode |= ENABLE_PROCESSED_INPUT;
  SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);
}

void console::unregister_user_cancel_callback(std::function<bool(int32_t)> user_cancel_callback) {
  ::user_cancel_callback = nullptr;
}

int32_t console::window_height() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int32_t console::window_left() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

int32_t console::window_top() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Top;
}

int32_t console::window_width() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}
