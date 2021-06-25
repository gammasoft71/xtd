#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class main_form : public form {
public:
  static void main() {
    application::run(main_form());
  }
  
  main_form() {
    text("application and assert example");
    
    // Uncomment following line to remove assert dialog
    //diagnostics::debug::show_assert_dialog(false);

    generate_assert_button.auto_size(true);
    generate_assert_button.location({10, 10});
    generate_assert_button.parent(*this);
    generate_assert_button.text("Generate assert");
    generate_assert_button.click += {*this, &main_form::generate_assert};
  }
  
private:
  void generate_assert() {
    auto index = 0;
    assert_(index > 0, "Index must be greather than 0");
  }
  
  button generate_assert_button;
};

startup_(main_form);
