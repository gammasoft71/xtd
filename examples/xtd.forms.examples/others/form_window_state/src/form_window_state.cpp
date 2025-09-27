#define TRACE // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    *this << button_full_screen << button_maximize << button_minimize << button_normal;
    text("Window state example");
    resize += delegate_ {
      button_full_screen.enabled(window_state() != form_window_state::full_screen&& window_state() != form_window_state::maximized);
      button_maximize.enabled(window_state() != form_window_state::maximized&& window_state() != form_window_state::full_screen);
      button_normal.enabled(window_state() != form_window_state::normal);
      button_minimize.enabled(window_state() != form_window_state::minimized&& window_state() != form_window_state::full_screen);
      
      ctrace << string::format("resize: {}, {}", size(), window_state()) << environment::new_line;
    };
    client_size({410, 200});
    window_state(form_window_state::maximized);
    
    button_full_screen.location({10, 10});
    button_full_screen.text("Full screen");
    button_full_screen.width(90);
    button_full_screen.click += delegate_ {
      window_state(form_window_state::full_screen);
    };
    
    button_maximize.location({110, 10});
    button_maximize.text("Maximize");
    button_maximize.width(90);
    button_maximize.click += delegate_ {
      window_state(form_window_state::maximized);
    };
    
    button_normal.location({210, 10});
    button_normal.text("Normal");
    button_normal.width(90);
    button_normal.click += delegate_ {
      window_state(form_window_state::normal);
    };
    
    button_minimize.location({310, 10});
    button_minimize.text("Minimize");
    button_minimize.width(90);
    button_minimize.click += delegate_ {
      window_state(form_window_state::minimized);
    };
  }
  
private:
  button button_full_screen;
  button button_maximize;
  button button_normal;
  button button_minimize;
};

auto main() -> int {
  application::run(form1 {});
}
