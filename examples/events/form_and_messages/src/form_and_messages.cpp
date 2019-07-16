#include <xtd/xtd.forms>

using namespace xtd::diagnostics;
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
      case WM_ACTIVATEAPP: debug::write_line(xtd::strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam())); break;
      case WM_CANCELMODE: debug::write_line("WM_CANCELMODE"); break;
      case WM_CLOSE: debug::write_line("WM_CLOSE"); break;
      case WM_COMMAND: debug::write_line(xtd::strings::format("WM_COMMAND [type=0x{0:X8}, control={1}]", message.wparam(), message.lparam())); break;
      case WM_CREATE: debug::write_line(xtd::strings::format("WM_CREATE [create_struct{}]", message.lparam())); break;
      case WM_DESTROY: debug::write_line("WM_DESTROY"); break;
      case WM_ENTERSIZEMOVE: debug::write_line("WM_ENTERSIZEMOVE"); break;
      case WM_EXITSIZEMOVE: debug::write_line("WM_EXITSIZEMOVE"); break;
      case WM_KILLFOCUS: debug::write_line("WM_KILLFOCUS"); break;
      case WM_LBUTTONDBLCLK: debug::write_line(xtd::strings::format("WM_LBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_LBUTTONDOWN: debug::write_line(xtd::strings::format("WM_LBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_LBUTTONUP: debug::write_line(xtd::strings::format("WM_LBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONDBLCLK: debug::write_line(xtd::strings::format("WM_MBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONDOWN: debug::write_line(xtd::strings::format("WM_MBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONUP: debug::write_line(xtd::strings::format("WM_MBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOVE: debug::write_line(xtd::strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSEENTER: debug::write_line("WM_MOUSEENTER"); break;
      case WM_MOUSEHWHEEL: debug::write_line(xtd::strings::format("WM_MOUSEHWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSELEAVE: debug::write_line("WM_MOUSELEAVE"); break;
      //case WM_MOUSEMOVE: debug::write_line(xtd::strings::format("WM_MOUSEMOVE [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSEWHEEL: debug::write_line(xtd::strings::format("WM_MOUSEWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONDBLCLK: debug::write_line(xtd::strings::format("WM_RBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONDOWN: debug::write_line(xtd::strings::format("WM_RBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONUP: debug::write_line(xtd::strings::format("WM_RBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_SETFOCUS: debug::write_line("WM_SETFOCUS"); break;
      case WM_SETTEXT: debug::write_line(xtd::strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam()))); break;
      case WM_SHOWWINDOW: debug::write_line(xtd::strings::format("WM_SHOWWINDOW [show={}]", message.wparam())); break;
      case WM_SIZE: debug::write_line(xtd::strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONDBLCLK: debug::write_line(xtd::strings::format("WM_XBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONDOWN: debug::write_line(xtd::strings::format("WM_XBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONUP: debug::write_line(xtd::strings::format("WM_XBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      //default: debug::write_line(xtd::strings::format("0x{:X4}", message.msg())); break;
    }
  }
};

int main() {
  application::run(form1());
}
