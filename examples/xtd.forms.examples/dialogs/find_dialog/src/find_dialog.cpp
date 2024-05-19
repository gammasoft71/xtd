#include <xtd/diagnostics/debug>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/debug_form>
#include <xtd/forms/find_dialog>
#include <xtd/forms/form>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Find dialog example");
    
    find_button.parent(*this);
    find_button.text("find...");
    find_button.location({10, 10});
    find_button.click += [&] {
      find_dialog.show(*this);
    };
    
    find_dialog.title("Find");
    find_dialog.find_string("Gammasoft");
    find_dialog.find_next += [&](object& sender, const find_event_args& e) {
      diagnostics::debug::write_line(ustring::format("Find next : find string [{}], match case [{}], search direction [{}], whole word [{}]", e.find_string(), e.match_case(), e.search_direction(), e.whole_word()));
    };
  }
  
private:
  debug_form df;
  button find_button;
  xtd::forms::find_dialog find_dialog;
};

auto main() -> int {
  application::run(form1 {});
}
