#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      client_size({300, 300});
      text("form1");
      font({font().font_family(), 18.0f, drawing::font_style::bold, drawing::graphics_unit::point, 0});
    }

  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      // Paint a string in different styles depending on whether the application is active.
      if (app_active) {
        e.graphics().fill_rectangle(solid_brush(system_colors::menu_highlight()), 10, 10, 280, 50);
        e.graphics().draw_string("Application is active", font(), solid_brush(system_colors::control_text()), 10, 10);
      } else {
        e.graphics().fill_rectangle(solid_brush(system_colors::control()), 10, 10, 280, 50);
        e.graphics().draw_string("Application is inactive", font(), solid_brush(system_colors::control_text()), 10, 10);
      }
    }
    
    void wnd_proc(message& m) override {
      // Listen for operating system messages.
      switch (m.msg()) {
          // The WM_ACTIVATEAPP message occurs when the application becomes the active application or becomes inactive.
        case WM_ACTIVATEAPP:
          // The wparam value identifies what is occurring.
          app_active = (static_cast<int>(m.wparam()) != 0);
          // Invalidate to get new text painted.
          invalidate();
          break;
      }
      form::wnd_proc(m);
    }

  private:
    bool app_active = true;
  };
}

int main() {
  application::run(examples::form1());
}
