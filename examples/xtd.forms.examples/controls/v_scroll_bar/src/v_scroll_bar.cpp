#include <xtd/diagnostics/debug>
#include <xtd/forms/application>
#include <xtd/forms/debug_form>
#include <xtd/forms/form>
#include <xtd/forms/v_scroll_bar>

using namespace xtd::forms;

namespace v_scroll_bar_example {
  class form1 : public form {
  public:
    form1() {
      text("vertical scroll bar example");
      
      v_scroll_bar1.parent(*this);
      v_scroll_bar1.location({30, 10});
      
      v_scroll_bar2.parent(*this);
      v_scroll_bar2.location({70, 10});
      v_scroll_bar2.height(220);
      v_scroll_bar2.large_change(2);
      v_scroll_bar2.minimum(0);
      v_scroll_bar2.maximum(20);
      v_scroll_bar2.value(10);
      v_scroll_bar2.scroll += [&] {
        xtd::diagnostics::debug::write_line(xtd::ustring::format("v_scrolbar2 value = {}", v_scroll_bar2.value()));
      };
    }
    
  private:
    v_scroll_bar v_scroll_bar1;
    v_scroll_bar v_scroll_bar2;
  };
}

auto main() -> int {
  auto df = debug_form {};
  application::run(v_scroll_bar_example::form1 {});
}
