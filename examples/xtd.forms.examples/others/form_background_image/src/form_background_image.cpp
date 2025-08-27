#include <xtd/xtd>

namespace form_background_image_example {
  class form_main : public form {
  public:
    static auto main() {
      application::run(form_main());
    }
    
    form_main() {
      double_buffered(true);
      background_image(images::from_name("xtd", drawing::size(64, 64)));
      text("form with background image example");
      
      button.parent(*this);
      button.text("Close");
      button.location({10, 10});
      button.click += event_handler(*this, &form::close);
    }
    
  private:
    forms::button button;
  };
}

startup_(form_background_image_example::form_main::main);
