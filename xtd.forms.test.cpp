#include "application.h"
#include "form.h"

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");
  }
};

int main(int argc, char* argv[]) {
  //application::run();
  //application::run(form());
  application::run(form1());
}
