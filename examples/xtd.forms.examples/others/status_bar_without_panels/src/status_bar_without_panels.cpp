#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      back_color(drawing::system_colors::text_box());
      diagnostics::debug::write_line(ustring::format("color = 0x{:X8}", drawing::system_colors::text_box().to_argb()));
      size({400, 250});
      text("Status bar without panels example");
      
      mouse_click += [&](object& sender, const mouse_event_args& e) {
        status_bar1.text(ustring::format("Mouse click at location : {}", e.location()));
      };
      
      status_bar1.parent(*this);
      status_bar1.back_color(drawing::system_colors::control());
      status_bar1.text("Click anywhere on the client form...");
    }
    
  private:
    forms::status_bar status_bar1;
  };
}

int main() {
  application::run(examples::form1 {});
}
