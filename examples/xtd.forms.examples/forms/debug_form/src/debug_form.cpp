#define DEBUG // Force debug mode even if example is builded in release.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Debug form example");
    
    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Write line...");
    button1.click += delegate_ {
      static auto counter = 0;
      diagnostics::debug::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  auto df = debug_form {};
  df.back_color(xtd::drawing::color::black);
  df.fore_color(xtd::drawing::color::lime);
  
  application::run(form1 {});
}
