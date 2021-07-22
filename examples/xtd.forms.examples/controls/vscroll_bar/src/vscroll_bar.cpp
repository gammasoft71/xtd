#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("vertical scroll bar example");
      
      vscroll_bar1.parent(*this);
      vscroll_bar1.location({30, 10});
      
      vscroll_bar2.parent(*this);
      vscroll_bar2.location({70, 10});
      vscroll_bar2.height(220);
      vscroll_bar2.large_change(2);
      vscroll_bar2.minimum(0);
      vscroll_bar2.maximum(20);
      vscroll_bar2.value(10);
      vscroll_bar2.scroll += [&] {
        xtd::diagnostics::debug::write_line(xtd::strings::format("vscrolbar2 value = {}", vscroll_bar2.value()));
      };
    }
    
  private:
    vscroll_bar vscroll_bar1;
    vscroll_bar vscroll_bar2;
  };
}

int main() {
  application::run(examples::form1());
}
