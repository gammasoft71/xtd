#define TRACE
#include <xtd/xtd>

class form_main : public form {
public:
  form_main() {
    button_.parent(*this);
    button_.location({10, 10});
    button_.text("Error...");
    button_.click += delegate_ {
      trace_message_box::show(*this, "An unknown process error occured.");
    };
  }
  
  static auto main() {
    auto tf = trace_form {};
    xtd::forms::application::run(form_main());
  }
private:
  button button_;
};

startup_(form_main::main);
