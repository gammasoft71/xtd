#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");

    this->button1.parent(*this);
    this->button1.text("button 1");
    this->button1.tag("Information text");
    this->button1.location({10, 10});
    this->button1.click += [&](const control& sender, const event_args& e) {
      message_box::show(strings::format("button = {}", any_cast<const char*>(sender.tag())));
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form_test());
}
