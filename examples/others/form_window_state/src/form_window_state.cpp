#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Window state example");
    resize += [this] {
      button_full_screen.enabled(window_state() != form_window_state::full_screen && window_state() != form_window_state::maximized);
      button_maximize.enabled(window_state() != form_window_state::maximized && window_state() != form_window_state::full_screen);
      button_normal.enabled(window_state() != form_window_state::normal);
      button_minimize.enabled(window_state() != form_window_state::minimized && window_state() != form_window_state::full_screen);

      cdebug << format("resize: {}, {}", size(), window_state()) << std::endl;
    };
    client_size({365, 200});
    window_state(form_window_state::maximized);
    
    button_full_screen.parent(*this);
    button_full_screen.location({10, 10});
    button_full_screen.text("FullScreen");
    button_full_screen.click += [&] {
      window_state(form_window_state::full_screen);
    };

    button_maximize.parent(*this);
    button_maximize.location({100, 10});
    button_maximize.text("Maximize");
    button_maximize.click += [&] {
      window_state(form_window_state::maximized);
    };
    
    button_normal.parent(*this);
    button_normal.location({190, 10});
    button_normal.text("Normal");
    button_normal.click += [&] {
      window_state(form_window_state::normal);
    };

    button_minimize.parent(*this);
    button_minimize.location({280, 10});
    button_minimize.text("Minimize");
    button_minimize.click += [&] {
      window_state(form_window_state::minimized);
    };
  }
  
private:
  button button_full_screen;
  button button_maximize;
  button button_normal;
  button button_minimize;
};

int main() {
  application::run(form1());
}
