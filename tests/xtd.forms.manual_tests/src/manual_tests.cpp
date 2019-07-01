#include <xtd/forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("form1");
  }
};

// The main entry point for the application.
int main() {
  application_informations::company_name("gammasoft71");
  application_informations::product_name("manual_tests");
  application_informations::product_version("1.0.0");
  application::run(form1());
}
