#include <xtd/xtd.forms>

using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");
  }
};

int main() {
  application::run(form_test());
}
