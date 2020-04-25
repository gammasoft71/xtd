#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class log_form : public form {
  text_box text_;
public:
  log_form() {
    start_position(form_start_position::manual).location({screen::get_working_area(handle_).left() + screen::get_working_area(handle_).width() - screen::get_working_area(handle_).width() / 4, screen::get_working_area(handle_).top()}).size({screen::get_working_area(handle_).width() / 4, screen::get_working_area(handle_).height()}).visible(true);
    text_.multiline(true).read_only(true).word_wrap(false).parent(*this).dock(dock_style::fill);
  }
  
  void append(const std::string& log_str) {text_.append_text(log_str + "\n");}
};

class form1 : public form {
public:
  form1() {
    log_form_.text("Debug form");
    text("Form and Messages");
    location({100, 100});
  }

protected:
  void wnd_proc(message& message) override {
    form::wnd_proc(message);
    
    switch (message.msg()) {
      case WM_ACTIVATE: log_form_.append(strings::format("WM_ACTIVATE [activate={}]", static_cast<bool>(message.lparam()))); break;
      case WM_ACTIVATEAPP: log_form_.append(strings::format("WM_ACTIVATEAPP [activate={}, threat={}]", static_cast<bool>(message.wparam()), message.lparam())); break;
      case WM_CANCELMODE: log_form_.append("WM_CANCELMODE"); break;
      case WM_CLOSE: log_form_.append("WM_CLOSE"); break;
      case WM_COMMAND: log_form_.append(strings::format("WM_COMMAND [type=0x{:X8}, control={}]", message.wparam(), message.lparam())); break;
      case WM_CREATE: log_form_.append(strings::format("WM_CREATE [CREATESTRUCT={}]", message.lparam())); break;
      case WM_DESTROY: log_form_.append("WM_DESTROY"); break;
      case WM_ENTERSIZEMOVE: log_form_.append("WM_ENTERSIZEMOVE"); break;
      case WM_EXITSIZEMOVE: log_form_.append("WM_EXITSIZEMOVE"); break;
      case WM_GETTEXT: log_form_.append(strings::format("WM_GETTEXT [size={}, buffer={}]", message.wparam(), message.lparam())); break;
      case WM_GETTEXTLENGTH: log_form_.append("WM_GETTEXTLENGTH"); break;
      case WM_KILLFOCUS: log_form_.append("WM_KILLFOCUS"); break;
      case WM_LBUTTONDBLCLK: log_form_.append(strings::format("WM_LBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_LBUTTONDOWN: log_form_.append(strings::format("WM_LBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_LBUTTONUP: log_form_.append(strings::format("WM_LBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONDBLCLK: log_form_.append(strings::format("WM_MBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONDOWN: log_form_.append(strings::format("WM_MBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MBUTTONUP: log_form_.append(strings::format("WM_MBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOVE: log_form_.append(strings::format("WM_MOVE [x={}, y={}]", LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSEENTER: log_form_.append("WM_MOUSEENTER"); break;
      case WM_MOUSEHWHEEL: log_form_.append(strings::format("WM_MOUSEHWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSELEAVE: log_form_.append("WM_MOUSELEAVE"); break;
      case WM_MOUSEMOVE: log_form_.append(strings::format("WM_MOUSEMOVE [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_MOUSEWHEEL: log_form_.append(strings::format("WM_MOUSEWHEEL [Buttons={}, delta={}, x={}, y={}]", LOWORD(message.wparam()), HIWORD(message.wparam()), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONDBLCLK: log_form_.append(strings::format("WM_RBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONDOWN: log_form_.append(strings::format("WM_RBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_RBUTTONUP: log_form_.append(strings::format("WM_RBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_SETFOCUS: log_form_.append("WM_SETFOCUS"); break;
      case WM_SETTEXT: log_form_.append(strings::format("WM_SETTEXT [text=\"{}\"]", reinterpret_cast<char*>(message.lparam()))); break;
      case WM_SHOWWINDOW: log_form_.append(strings::format("WM_SHOWWINDOW [show={}]", static_cast<bool>(message.wparam()))); break;
      case WM_SIZE: log_form_.append(strings::format("WM_SIZE [type={}, width={}, heignt={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONDBLCLK: log_form_.append(strings::format("WM_XBUTTONDBLCLK [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONDOWN: log_form_.append(strings::format("WM_XBUTTONDOWN [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      case WM_XBUTTONUP: log_form_.append(strings::format("WM_XBUTTONUP [Buttons={}, x={}, y={}]", message.wparam(), LOWORD(message.lparam()), HIWORD(message.lparam()))); break;
      default: log_form_.append(strings::format("[{}]", message)); break;
    }
  }
  
private:
  log_form log_form_;
};

int main() {
  application::run(form1());
}
