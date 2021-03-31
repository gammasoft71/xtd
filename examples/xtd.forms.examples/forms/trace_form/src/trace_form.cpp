#define TRACE
#include <xtd/xtd>

using namespace xtd::diagnostics;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Trace form example");
    
    write_trace_button.auto_size(true);
    write_trace_button.location({10, 10});
    write_trace_button.parent(*this);
    write_trace_button.text("Write trace...");
    write_trace_button.click += [&] {
      static int counter = 0;
      trace::write_line("Write line {}...", ++counter);
    };
  }
  
private:
  button write_trace_button;
};

int main() {
  trace_form trace_form;
  application::run(form1());
}
