#include <iostream>
#include <xtd/strings>
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
    this->text("form1");

    control1.parent(*this);
    control1.size({100, 100});
  }
  
  void wnd_proc(xtd::forms::message& message) override {
    this->form::wnd_proc(message);
    
    switch (message.msg()) {
      case WM_MOVE: write_line_debug_string(xtd::strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_SIZE: write_line_debug_string(xtd::strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      default: break;
    }
  }
  
private:
  control control1;
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
