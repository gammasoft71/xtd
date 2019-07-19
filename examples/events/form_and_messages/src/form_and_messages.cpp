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
      case WM_ACTIVATEAPP: xtd::cdebug << xtd::strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam()) << std::endl; break;
      case WM_CANCELMODE: xtd::cdebug << "WM_CANCELMODE"<< std::endl; break;
      case WM_CLOSE: xtd::cdebug << "WM_CLOSE"<< std::endl; break;
      case WM_COMMAND: xtd::cdebug << xtd::strings::format("WM_COMMAND [type=0x{0:X8}, control={1}]", message.wparam(), message.lparam()) << std::endl; break;
      case WM_CREATE: xtd::cdebug << xtd::strings::format("WM_CREATE [CREATESTRUCT={}]", message.lparam()) << std::endl; break;
      case WM_DESTROY: xtd::cdebug << "WM_DESTROY"<< std::endl; break;
      case WM_ENTERSIZEMOVE: xtd::cdebug << "WM_ENTERSIZEMOVE"<< std::endl; break;
      case WM_EXITSIZEMOVE: xtd::cdebug << "WM_EXITSIZEMOVE"<< std::endl; break;
      case WM_GETTEXT: xtd::cdebug << xtd::strings::format("WM_GETTEXT [size={0}, buffer={1}]", message.wparam(), message.lparam()) << std::endl; break;
      case WM_GETTEXTLENGTH: xtd::cdebug << "WM_GETTEXTLENGTH"<< std::endl; break;
      case WM_KILLFOCUS: xtd::cdebug << "WM_KILLFOCUS"<< std::endl; break;
      case WM_LBUTTONDBLCLK: xtd::cdebug << xtd::strings::format("WM_LBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_LBUTTONDOWN: xtd::cdebug << xtd::strings::format("WM_LBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_LBUTTONUP: xtd::cdebug << xtd::strings::format("WM_LBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MBUTTONDBLCLK: xtd::cdebug << xtd::strings::format("WM_MBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MBUTTONDOWN: xtd::cdebug << xtd::strings::format("WM_MBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MBUTTONUP: xtd::cdebug << xtd::strings::format("WM_MBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MOVE: xtd::cdebug << xtd::strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MOUSEENTER: xtd::cdebug << "WM_MOUSEENTER"<< std::endl; break;
      case WM_MOUSEHWHEEL: xtd::cdebug << xtd::strings::format("WM_MOUSEHWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MOUSELEAVE: xtd::cdebug << "WM_MOUSELEAVE"<< std::endl; break;
      case WM_MOUSEMOVE: xtd::cdebug << xtd::strings::format("WM_MOUSEMOVE [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_MOUSEWHEEL: xtd::cdebug << xtd::strings::format("WM_MOUSEWHEEL [keys={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_RBUTTONDBLCLK: xtd::cdebug << xtd::strings::format("WM_RBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_RBUTTONDOWN: xtd::cdebug << xtd::strings::format("WM_RBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_RBUTTONUP: xtd::cdebug << xtd::strings::format("WM_RBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_SETFOCUS: xtd::cdebug << "WM_SETFOCUS"<< std::endl; break;
      case WM_SETTEXT: xtd::cdebug << xtd::strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam())) << std::endl; break;
      case WM_SHOWWINDOW: xtd::cdebug << xtd::strings::format("WM_SHOWWINDOW [show={}]", message.wparam()) << std::endl; break;
      case WM_SIZE: xtd::cdebug << xtd::strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_XBUTTONDBLCLK: xtd::cdebug << xtd::strings::format("WM_XBUTTONDBLCLK [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_XBUTTONDOWN: xtd::cdebug << xtd::strings::format("WM_XBUTTONDOWN [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      case WM_XBUTTONUP: xtd::cdebug << xtd::strings::format("WM_XBUTTONUP [keys={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam())) << std::endl; break;
      default: xtd::cdebug << xtd::strings::format("[{}]", message) << std::endl; break;
    }
  }
};

int main() {
  application::run(form1());
}
