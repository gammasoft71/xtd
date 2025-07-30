#define DEBUG
#include <xtd/xtd>

class form_main : public form {
public:
  form_main() {
    button_.parent(*this);
    button_.location({10, 10});
    button_.text("Error...");
    button_.click += [&] {
      debug_message_box::show(*this, "An unknown process error occured.");
    };
  }
  
  static auto main() {
    auto df = debug_form {};
    application::run(form_main {});
  }
  
private:
  button button_;
};

startup_(form_main::main);
