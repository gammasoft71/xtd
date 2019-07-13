#include <xtd/xtd.forms>

#if defined(WIN32)
#include <Windows.h>
void write_line_debug_string(const std::string& str) {
  OutputDebugString(str.c_str());
  OutputDebugString("\n");
}
#else
#include <iostream>
void write_line_debug_string(const std::string& str) {
  std::cout << str;
  std::cout << std::endl << std::flush;
}
#endif

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("Form and Messages");
    this->location({100, 100});
  }

protected:
  void wnd_proc(xtd::forms::message& message) override {
    this->form::wnd_proc(message);
    
    switch (message.msg()) {
      case WM_ACTIVATEAPP: write_line_debug_string(xtd::strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam())); break;
      case WM_CANCELMODE: write_line_debug_string("WM_CANCELMODE"); break;
      case WM_CLOSE: write_line_debug_string("WM_CLOSE"); break;
      case WM_COMMAND: write_line_debug_string(xtd::strings::format("WM_COMMAND [type=0x{0:X8}, control={1}]", message.wparam(), message.lparam())); break;
      case WM_CREATE: write_line_debug_string(xtd::strings::format("WM_CREATE [create_struct{}]", message.lparam())); break;
      case WM_DESTROY: write_line_debug_string("WM_DESTROY"); break;
      case WM_ENTERSIZEMOVE: write_line_debug_string("WM_ENTERSIZEMOVE"); break;
      case WM_EXITSIZEMOVE: write_line_debug_string("WM_EXITSIZEMOVE"); break;
      case WM_MOVE: write_line_debug_string(xtd::strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_NULL: write_line_debug_string("WM_NULL"); break;
      case WM_SETTEXT: write_line_debug_string(xtd::strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam()))); break;
      case WM_SHOWWINDOW: write_line_debug_string(xtd::strings::format("WM_SHOWWINDOW [show={}]", message.wparam())); break;
      case WM_SIZE: write_line_debug_string(xtd::strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      default: break;
    }
  }
};

int main() {
  application::run(form1());
}
