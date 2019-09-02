#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");

    /*
    this->radio1.parent(*this);
    this->radio1.text("radio 1");
    this->radio1.location({ 10, 10 });
    
    this->radio2.parent(*this);
    this->radio2.text("radio 2");
    this->radio2.checked(true);
    this->radio2.location({ 10, 40 });

    this->text_box1.parent(*this);
    this->text_box1.text("text box 1");
    this->text_box1.location({ 10, 70 });
     */

    this->mouse_move += [] {
      cdebug << format("mouse move") << endl;
    };

    this->handle_destroyed += [] {
      cdebug << format("handle destroyed") << endl;
    };
  }
  
private:
  //radio_button radio1;
  //radio_button radio2;
  //text_box text_box1;
};

int main() {
  application::run(form_test());
}
