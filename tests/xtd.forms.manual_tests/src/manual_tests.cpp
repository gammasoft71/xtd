#include <xtd/xtd.forms>

using namespace xtd::forms;

class manual_test_form : public form {
public:
  static void main() {
    application::run(manual_test_form());
  }

  manual_test_form() {
    text("Manual tests");
  }
};

startup_(manual_test_form);
