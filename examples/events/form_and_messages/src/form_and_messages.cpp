#define TRACE
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
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
      case WM_ACTIVATEAPP: ctrace << format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam()) << endl; break;
      case WM_CANCELMODE: ctrace << "WM_CANCELMODE"<< endl; break;
      case WM_CLOSE: ctrace << "WM_CLOSE"<< endl; break;
      case WM_COMMAND: ctrace << format("WM_COMMAND [type=0x{0:X8}, control={1}]", message.wparam(), message.lparam()) << endl; break;
      case WM_CREATE: ctrace << format("WM_CREATE [CREATESTRUCT={}]", message.lparam()) << endl; break;
      case WM_DESTROY: ctrace << "WM_DESTROY"<< endl; break;
      case WM_ENTERSIZEMOVE: ctrace << "WM_ENTERSIZEMOVE"<< endl; break;
      case WM_EXITSIZEMOVE: ctrace << "WM_EXITSIZEMOVE"<< endl; break;
      case WM_GETTEXT: ctrace << format("WM_GETTEXT [size={0}, buffer={1}]", message.wparam(), message.lparam()) << endl; break;
      case WM_GETTEXTLENGTH: ctrace << "WM_GETTEXTLENGTH"<< endl; break;
      case WM_KILLFOCUS: ctrace << "WM_KILLFOCUS"<< endl; break;
      case WM_LBUTTONDBLCLK: ctrace << format("WM_LBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_LBUTTONDOWN: ctrace << format("WM_LBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_LBUTTONUP: ctrace << format("WM_LBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONDBLCLK: ctrace << format("WM_MBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONDOWN: ctrace << format("WM_MBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MBUTTONUP: ctrace << format("WM_MBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOVE: ctrace << format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSEENTER: ctrace << "WM_MOUSEENTER"<< endl; break;
      case WM_MOUSEHWHEEL: ctrace << format("WM_MOUSEHWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSELEAVE: ctrace << "WM_MOUSELEAVE"<< endl; break;
      case WM_MOUSEMOVE: ctrace << format("WM_MOUSEMOVE [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_MOUSEWHEEL: ctrace << format("WM_MOUSEWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_RBUTTONDBLCLK: ctrace << format("WM_RBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_RBUTTONDOWN: ctrace << format("WM_RBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_RBUTTONUP: ctrace << format("WM_RBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_SETFOCUS: ctrace << "WM_SETFOCUS"<< endl; break;
      case WM_SETTEXT: ctrace << format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam())) << endl; break;
      case WM_SHOWWINDOW: ctrace << format("WM_SHOWWINDOW [show={}]", message.wparam()) << endl; break;
      case WM_SIZE: ctrace << format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONDBLCLK: ctrace << format("WM_XBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONDOWN: ctrace << format("WM_XBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      case WM_XBUTTONUP: ctrace << format("WM_XBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << endl; break;
      default: ctrace << format("[{}]", message) << endl; break;
    }
  }
};

int main() {
  application::run(form1());
}
