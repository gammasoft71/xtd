#if defined(_WIN32)

#include "../include/xtd/__console_color.hpp"
#include <Windows.h>

namespace {
  xtd::console_color __foreground_color() noexcept {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return static_cast<xtd::console_color>(csbi.wAttributes & 0x000F);
  }
  
  xtd::console_color foreColor = __foreground_color();
}

void __opaque_foreground_color(__console_color color) {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
  
  csbi.wAttributes &= 0xFFF0;
  csbi.wAttributes |= (int)color;
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), csbi.wAttributes);
}

void __opaque_reset_color() {
  __opaque_foreground_color(foreColor);
}

#endif
