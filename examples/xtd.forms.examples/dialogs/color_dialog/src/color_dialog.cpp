#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Color dialog example");
    controls().push_back(button1);

    button1.location({10, 10});
    button1.text("Color...");
    button1.click += [&] {
      color_dialog color_dialog;
      color_dialog.color(back_color());
      color_dialog.custom_colors({color::red.to_argb(), color::green.to_argb(), color::blue.to_argb(), color::yellow.to_argb(), system_colors::button_face().to_argb()});
      if (color_dialog.show_dialog(*this) == forms::dialog_result::ok)
        back_color(color_dialog.color());
    };
  }
  
private:
  button button1;
};

int main() {
  application::run(form1());
}
