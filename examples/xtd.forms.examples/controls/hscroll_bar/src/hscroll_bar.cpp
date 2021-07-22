#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("horizontal scroll bar example");

      hscroll_bar1.parent(*this);
      hscroll_bar1.location({30, 40});
      
      hscroll_bar2.parent(*this);
      hscroll_bar2.location({30, 80});
      hscroll_bar2.large_change(2);
      hscroll_bar2.minimum(0);
      hscroll_bar2.maximum(20);
      hscroll_bar2.value(10);
      hscroll_bar2.width(220);
      hscroll_bar2.scroll += [&] {
        xtd::diagnostics::debug::write_line(xtd::strings::format("hscrolbar2 value = {}", hscroll_bar2.value()));
      };
    }
    
  private:
    hscroll_bar hscroll_bar1;
    hscroll_bar hscroll_bar2;
  };
}

int main() {
  application::run(examples::form1());
}
