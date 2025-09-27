#define TRACE // Force to trace even if example is builded with -DNTRACE.
#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Trace form example");
    
    button1.auto_repeat(true);
    button1.auto_size(true);
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Write line...");
    button1.click += delegate_ {
      static auto counter = 0;
      diagnostics::trace::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button button1;
};

auto main() -> int {
  auto tf = trace_form {};
  tf.back_color(color::navy);
  tf.fore_color(color::white);
  application::run(form1 {});
}
