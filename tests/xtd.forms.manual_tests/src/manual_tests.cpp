#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");
  }
  
private:
};

// The main entry point for the application.
int main() {
  application::run(form1());
}
