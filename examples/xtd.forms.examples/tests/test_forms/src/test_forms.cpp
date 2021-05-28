#include <xtd/xtd>

using namespace xtd::forms;

class form_main : public form {
public:
  form_main() {
  }
  
  static void main() {
    xtd::forms::application::run(form_main());
  }
};

startup_(form_main);
