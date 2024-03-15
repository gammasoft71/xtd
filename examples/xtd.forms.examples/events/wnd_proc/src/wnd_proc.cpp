#include <xtd/drawing/system_brushes>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/window_messages>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace wnd_proc_example {
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
        e.graphics().fill_rectangle(system_brushes::menu_highlight(), 10, 10, 280, 50);
        e.graphics().draw_string("Application is active", font(), system_brushes::control_text(), 10, 10);
      } else {
        e.graphics().fill_rectangle(system_brushes::control(), 10, 10, 280, 50);
        e.graphics().draw_string("Application is inactive", font(), system_brushes::control_text(), 10, 10);
      }
    }
    
    void wnd_proc(message& m) override {
      // Listen for operating system messages.
      switch (m.msg()) {
        // The WM_ACTIVATEAPP message occurs when the application becomes the active application or becomes inactive.
        case WM_ACTIVATEAPP:
          // The wparam value identifies what is occurring.
          app_active = (as<int>(m.wparam()) != 0);
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

auto main()->int {
  application::run(wnd_proc_example::form1 {});
}
