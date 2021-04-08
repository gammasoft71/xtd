#define TRACE
#include <xtd/xtd>

using namespace std;
using namespace xtd;
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
      case WM_ACTIVATE: ctrace << strings::format("WM_ACTIVATE [activate={}]", static_cast<bool>(message.lparam())) << endl; break;
      case WM_ACTIVATEAPP: ctrace << strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam()) << endl; break;
      case WM_CANCELMODE: ctrace << "WM_CANCELMODE" << endl; break;
      case WM_CLOSE: ctrace << "WM_CLOSE" << endl; break;
      case WM_COMMAND: ctrace << strings::format("WM_COMMAND [type=0x{:X8}, control={}]", message.wparam(), message.lparam()) << endl; break;
      case WM_CREATE: ctrace << strings::format("WM_CREATE [CREATESTRUCT={}]", message.lparam()) << endl; break;
      case WM_DESTROY: ctrace << "WM_DESTROY" << endl; break;
      case WM_ENTERSIZEMOVE: ctrace << "WM_ENTERSIZEMOVE" << endl; break;
      case WM_EXITSIZEMOVE: ctrace << "WM_EXITSIZEMOVE" << endl; break;
      case WM_GETTEXT: ctrace << strings::format("WM_GETTEXT [size={}, buffer={}]", message.wparam(), message.lparam()) << endl; break;
      case WM_GETTEXTLENGTH: ctrace << "WM_GETTEXTLENGTH" << endl; break;
      case WM_KILLFOCUS: ctrace << "WM_KILLFOCUS" << endl; break;
      case WM_LBUTTONDBLCLK: ctrace << strings::format("WM_LBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_LBUTTONDOWN: ctrace << strings::format("WM_LBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_LBUTTONUP: ctrace << strings::format("WM_LBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONDBLCLK: ctrace << strings::format("WM_MBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONDOWN: ctrace << strings::format("WM_MBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONUP: ctrace << strings::format("WM_MBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOVE: ctrace << strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSEENTER: ctrace << "WM_MOUSEENTER" << endl; break;
      case WM_MOUSEHWHEEL: ctrace << strings::format("WM_MOUSEHWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSELEAVE: ctrace << "WM_MOUSELEAVE" << endl; break;
      case WM_MOUSEMOVE: ctrace << strings::format("WM_MOUSEMOVE [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSEWHEEL: ctrace << strings::format("WM_MOUSEWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_PAINT: ctrace << "WM_PAINT" << endl; break;
      case WM_RBUTTONDBLCLK: ctrace << strings::format("WM_RBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_RBUTTONDOWN: ctrace << strings::format("WM_RBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_RBUTTONUP: ctrace << strings::format("WM_RBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_SETFOCUS: ctrace << "WM_SETFOCUS" << endl; break;
      case WM_SETTEXT: ctrace << strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam())) << endl; break;
      case WM_SHOWWINDOW: ctrace << strings::format("WM_SHOWWINDOW [show={}]", static_cast<bool>(message.wparam())) << endl; break;
      case WM_SIZE: ctrace << strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONDBLCLK: ctrace << strings::format("WM_XBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONDOWN: ctrace << strings::format("WM_XBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONUP: ctrace << strings::format("WM_XBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      default: ctrace << strings::format("[{}]", message) << endl; break;
    }
  }
};

int main() {
  trace_form trace_form;
  application::run(form1());
}
