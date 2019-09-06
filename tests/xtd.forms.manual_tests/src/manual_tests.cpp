#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form_test : public form {
public:
  form_test() {
    this->text("xtd.forms.manual_tests");
    this->auto_size(true);
    this->auto_size_mode(forms::auto_size_mode::grow_and_shrink);
    //this->back_color(drawing::color::spring_green);

    this->item1.parent(*this);
    //this->item1.back_color(drawing::color::red);
    this->item1.text("This is a long text for validate auto size.");
    this->item1.location({10, 30});

    this->item2.parent(*this);
    this->item2.auto_size(true);
    //this->item2.back_color(drawing::color::red);
    this->item2.text("This is a long text for validate auto size.");
    this->item2.location({10, 70});

    this->item3.parent(*this);
    this->item3.auto_size(true);
    this->item3.font(drawing::font("Arial", 23));
    //this->item3.back_color(drawing::color::red);
    this->item3.location({10, 110});
  }
  
private:
  radio_button item1;
  radio_button item2;
  text_box item3;
};

int main() {
  application::run(form_test());
}
