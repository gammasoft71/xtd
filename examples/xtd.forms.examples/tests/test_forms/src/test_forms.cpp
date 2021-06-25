#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form_main : public form {
public:
  static void main() {
    xtd::forms::application::run(form_main());
  }

  form_main() {
    text("Assert example");
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Assert...");
    button1.click += [] {
      assert_(false, "Test assert");
    };
  }

private:
  button button1;
};

startup_(form_main);
