#include <xtd/xtd>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("horizontal scroll bar example");

      h_scroll_bar1.parent(*this);
      h_scroll_bar1.location({30, 40});
      
      h_scroll_bar2.parent(*this);
      h_scroll_bar2.location({30, 80});
      h_scroll_bar2.large_change(2);
      h_scroll_bar2.minimum(0);
      h_scroll_bar2.maximum(20);
      h_scroll_bar2.value(10);
      h_scroll_bar2.width(220);
      h_scroll_bar2.scroll += [&] {
        xtd::diagnostics::debug::write_line(xtd::ustring::format("h_scroll_bar2 value = {}", h_scroll_bar2.value()));
      };
    }
    
  private:
    h_scroll_bar h_scroll_bar1;
    h_scroll_bar h_scroll_bar2;
  };
}

int main() {
  application::run(examples::form1());
}
