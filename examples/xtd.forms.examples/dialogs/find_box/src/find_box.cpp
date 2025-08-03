#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Find box example");
    
    find_button.parent(*this);
    find_button.text("find...");
    find_button.location({10, 10});
    find_button.click += [&] {
      find_box::show(*this, "Gammasoft", "Find", [&](object& sender, const find_event_args& e) {
        diagnostics::debug::write_line(string::format("Find next : find string [{}], match case [{}], search direction [{}], whole word [{}]", e.find_string(), e.match_case(), e.search_direction(), e.whole_word()));
      });
    };
  }
  
private:
  button find_button;
};

auto main() -> int {
  auto df = debug_form {};
  application::run(form1 {});
}
