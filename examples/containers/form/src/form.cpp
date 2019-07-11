#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");
  }
};

int main() {
  application::run(form1());
}
