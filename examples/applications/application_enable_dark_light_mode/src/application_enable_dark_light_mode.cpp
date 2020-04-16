#include <xtd/xtd.forms>

using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    enable_dark_mode_button.parent(*this);
    enable_dark_mode_button.auto_size(true);
    enable_dark_mode_button.location({10, 10});
    enable_dark_mode_button.text("Dark mode");
    enable_dark_mode_button.click += [] {
      application::enable_dark_mode();
    };

    enable_light_mode_button.parent(*this);
    enable_light_mode_button.auto_size(true);
    enable_light_mode_button.location({110, 10});
    enable_light_mode_button.text("Light mode");
    enable_light_mode_button.click += [] {
      application::enable_light_mode();
    };
  }
  
private:
  button enable_dark_mode_button;
  button enable_light_mode_button;
};

int main() {
  xtd::forms::application::run(form1());
}
