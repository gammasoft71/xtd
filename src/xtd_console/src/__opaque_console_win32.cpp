#if defined(_WIN32)

#include "../include/xtd/__opaque_console.h"
#include "../include/xtd/console.h"

#include <csignal>
#include <conio.h>
#include <Windows.h>

namespace {
  xtd::console_color __background_color() noexcept {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return static_cast<xtd::console_color>((csbi.wAttributes & 0x00F0) >> 4);
  }

  xtd::console_color __foreground_color() noexcept {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return static_cast<xtd::console_color>(csbi.wAttributes & 0x000F);
  }

  BOOL WINAPI __handler_routine(DWORD ctrl_type) {
    if (ctrl_type == CTRL_C_EVENT || ctrl_type == CTRL_BREAK_EVENT) {
      xtd::console_cancel_event_args console_cancel(false, ctrl_type == CTRL_C_EVENT ? xtd::console_special_key::control_c : xtd::console_special_key::control_break);
      xtd::console::__internal_cancel_key_press__(console_cancel);
      return console_cancel.cancel() == TRUE;
    }
    return FALSE;
  }

  xtd::console_color backColor = __background_color();
  xtd::console_color foreColor = __foreground_color();
  bool treat_control_c_as_input = [&]()-> bool {
    SetConsoleCtrlHandler(&__handler_routine, TRUE);
    return false;
  }();
}

xtd::console_color __opaque_console::background_color() noexcept {
  return __background_color();
}

bool __opaque_console::background_color(xtd::console_color color) noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFF0F;
  csbi.wAttributes |= (int)color << 4;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

bool __opaque_console::beep(unsigned int frequency, unsigned int duration) noexcept {
  if (frequency < 37 || frequency > 32767)
    return false;
  
  Beep(frequency, duration);
  return true;
}

int __opaque_console::buffer_height() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.Y;
}

bool __opaque_console::buffer_height(int height) noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.Y = static_cast<int16_t>(height);
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

int __opaque_console::buffer_width() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwSize.X;
}

bool __opaque_console::buffer_width(int width) noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwSize.X = static_cast<int16_t>(width);
  return SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwSize) == TRUE;
}

bool __opaque_console::caps_lock() noexcept {
  return (GetKeyState(VK_CAPITAL) & 0x0001) == 0x0001;
}

bool __opaque_console::clear() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  const COORD coord = {0, 0};
  DWORD nbCharsWritten = 0;
  FillConsoleOutputAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  FillConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE), ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &nbCharsWritten);
  return __opaque_console::set_cursor_position(0, 0);
}

int __opaque_console::cursor_left() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.X;
}

int __opaque_console::cursor_size() noexcept {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  return cci.dwSize;
}

void __opaque_console::cursor_size(int size) noexcept {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.dwSize = size;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

int __opaque_console::cursor_top() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.dwCursorPosition.Y;
}

bool __opaque_console::cursor_visible() noexcept {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  return cci.bVisible != FALSE;
}

void __opaque_console::cursor_visible(bool visible) noexcept {
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
  
  cci.bVisible = visible;
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

xtd::console_color __opaque_console::foreground_color() noexcept {
  return __foreground_color();
}

bool __opaque_console::foreground_color(xtd::console_color color) noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= (int)color;
  return SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes) == TRUE;
}

int __opaque_console::input_code_page() noexcept {
  return GetConsoleCP();
}

bool __opaque_console::input_code_page(int codePage) noexcept {
  return SetConsoleCP(codePage) == TRUE;
}

bool __opaque_console::key_available() noexcept {
  return _kbhit() != 0;
}

int __opaque_console::largest_window_height() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int __opaque_console::largest_window_width() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

bool __opaque_console::number_lock() noexcept {
  return (GetKeyState(VK_NUMLOCK) & 0x0001) == 0x0001;
}

int __opaque_console::output_code_page() noexcept {
  return GetConsoleOutputCP();
}

bool __opaque_console::output_code_page(int codePage) noexcept {
  return SetConsoleOutputCP(codePage) == TRUE;
}

void __opaque_console::read_key(int& key_char, int& key_code, bool& alt, bool& shift, bool& ctrl) noexcept {
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

bool __opaque_console::reset_color() noexcept {
  return __opaque_console::background_color(backColor) && __opaque_console::foreground_color(foreColor);
}

bool __opaque_console::set_cursor_position(int left, int top) noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  csbi.dwCursorPosition.X = static_cast<int16_t>(left);
  csbi.dwCursorPosition.Y = static_cast<int16_t>(top);
  return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), csbi.dwCursorPosition) == TRUE;
}

std::string __opaque_console::title() noexcept {
  char title[MAX_PATH];
  if (GetConsoleTitle(title, MAX_PATH) == 0) return "";
  return title;
}

bool __opaque_console::title(const std::string& title) noexcept {
  return SetConsoleTitle(title.c_str());
}

bool __opaque_console::treat_control_c_as_input() noexcept {
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  return  (mode & ENABLE_PROCESSED_INPUT) != ENABLE_PROCESSED_INPUT;
}

void __opaque_console::treat_control_c_as_input(bool treat_control_c_as_input) {
  DWORD mode = 0;
  GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode);
  if (treat_control_c_as_input)
    mode &= ~ENABLE_PROCESSED_INPUT;
  else
    mode |= ENABLE_PROCESSED_INPUT;
  SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), mode);
}

int __opaque_console::window_height() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}

int __opaque_console::window_left() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Left;
}

int __opaque_console::window_top() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Top;
}

int __opaque_console::window_width() noexcept {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

#endif
