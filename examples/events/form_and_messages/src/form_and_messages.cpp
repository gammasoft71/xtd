#define TRACE
#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Form and Messages");
  }

protected:
  void wnd_proc(message& message) override {
    form::wnd_proc(message);
    
    switch (message.msg()) {
      case WM_ACTIVATE: trace::write_line("WM_ACTIVATE [activate={}]", static_cast<bool>(message.lparam())); break;
      case WM_ACTIVATEAPP: trace::write_line("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam()); break;
      case WM_CANCELMODE: trace::write_line("WM_CANCELMODE"); break;
      case WM_CLOSE: trace::write_line("WM_CLOSE"); break;
      case WM_COMMAND: trace::write_line("WM_COMMAND [type=0x{:X8}, control={}]", message.wparam(), message.lparam()); break;
      case WM_CREATE: trace::write_line("WM_CREATE [CREATESTRUCT={}]", message.lparam()); break;
      case WM_DESTROY: trace::write_line("WM_DESTROY"); break;
      case WM_ENTERSIZEMOVE: trace::write_line("WM_ENTERSIZEMOVE"); break;
      case WM_EXITSIZEMOVE: trace::write_line("WM_EXITSIZEMOVE"); break;
      case WM_GETTEXT: trace::write_line("WM_GETTEXT [size={}, buffer={}]", message.wparam(), message.lparam()); break;
      case WM_GETTEXTLENGTH: trace::write_line("WM_GETTEXTLENGTH"); break;
      case WM_KILLFOCUS: trace::write_line("WM_KILLFOCUS"); break;
      case WM_LBUTTONDBLCLK: trace::write_line("WM_LBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_LBUTTONDOWN: trace::write_line("WM_LBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_LBUTTONUP: trace::write_line("WM_LBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MBUTTONDBLCLK: trace::write_line("WM_MBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MBUTTONDOWN: trace::write_line("WM_MBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MBUTTONUP: trace::write_line("WM_MBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MOVE: trace::write_line("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MOUSEENTER: trace::write_line("WM_MOUSEENTER"); break;
      case WM_MOUSEHWHEEL: trace::write_line("WM_MOUSEHWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MOUSELEAVE: trace::write_line("WM_MOUSELEAVE"); break;
      case WM_MOUSEMOVE: trace::write_line("WM_MOUSEMOVE [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_MOUSEWHEEL: trace::write_line("WM_MOUSEWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_PAINT: trace::write_line("WM_PAINT"); break;
      case WM_RBUTTONDBLCLK: trace::write_line("WM_RBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_RBUTTONDOWN: trace::write_line("WM_RBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_RBUTTONUP: trace::write_line("WM_RBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_SETFOCUS: trace::write_line("WM_SETFOCUS"); break;
      case WM_SETTEXT: trace::write_line("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam())); break;
      case WM_SHOWWINDOW: trace::write_line("WM_SHOWWINDOW [show={}]", static_cast<bool>(message.wparam())); break;
      case WM_SIZE: trace::write_line("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_XBUTTONDBLCLK: trace::write_line("WM_XBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_XBUTTONDOWN: trace::write_line("WM_XBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      case WM_XBUTTONUP: trace::write_line("WM_XBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())); break;
      default: trace::write_line("[{}]", message); break;
    }
  }
};

int main() {
  trace_form trace;
  application::run(form1());
}
