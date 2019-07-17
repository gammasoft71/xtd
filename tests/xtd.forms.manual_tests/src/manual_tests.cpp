#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::diagnostics;

using key = int;

class form1 : public form {
public:
  form1() {
    this->name("form1");
    this->text("form1");
    this->location({100, 100});
    //this->enabled(false);
    
    this->button1.name("button1");
    this->button1.parent(*this);
    this->button1.text("Click me");
  }

protected:
  void wnd_proc(xtd::forms::message& message) override {
    this->form::wnd_proc(message);
    
    switch (message.msg()) {
      case WM_CHAR: debug::write_line(xtd::strings::format("WM_CHAR [char={}, repeat={}]", static_cast<char>(message.wparam()), message.lparam())); break;
      case WM_KEYDOWN: debug::write_line(xtd::strings::format("WM_KEYDOWN [key={}, repeat={}]", static_cast<key>(message.wparam()), message.lparam())); break;
      case WM_KEYUP: debug::write_line(xtd::strings::format("WM_KEYUP [key={}, repeat={}]", static_cast<key>(message.wparam()), message.lparam())); break;
        /*
      case WM_ACTIVATEAPP: debug::write_line(xtd::strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam())); break;
      case WM_CANCELMODE: debug::write_line("WM_CANCELMODE"); break;
      case WM_CLOSE: debug::write_line("WM_CLOSE"); break;
      case WM_COMMAND: debug::write_line(xtd::strings::format("WM_COMMAND [type=0x{0:X8}, control={1}]", message.wparam(), message.lparam())); break;
      case WM_CREATE: debug::write_line(xtd::strings::format("WM_CREATE [create_struct{}]", message.lparam())); break;
      case WM_DESTROY: debug::write_line("WM_DESTROY"); break;
      case WM_ENTERSIZEMOVE: debug::write_line("WM_ENTERSIZEMOVE"); break;
      case WM_EXITSIZEMOVE: debug::write_line("WM_EXITSIZEMOVE"); break;
      case WM_MOVE: debug::write_line(xtd::strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_NULL: debug::write_line("WM_NULL"); break;
      case WM_SETTEXT: debug::write_line(xtd::strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam()))); break;
      case WM_SHOWWINDOW: debug::write_line(xtd::strings::format("WM_SHOWWINDOW [show={}]", message.wparam())); break;
      case WM_SIZE: debug::write_line(xtd::strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
         */
      //default: debug::write_line(xtd::strings::format("[{}]", message)); break;
    }
  }
  
private:
  button button1;
};

// The main entry point for the application.
int main() {
  debug::write_line(strings::format("{}", keys::a));
  application::run(form1());
}
