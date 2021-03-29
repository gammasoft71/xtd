#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Color box example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("Color...");
    button1.click += [&] {
      color color = back_color();
      if (color_box::show(color, *this) == forms::dialog_result::ok)
        back_color(color);
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
