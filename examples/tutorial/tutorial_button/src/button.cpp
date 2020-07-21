#include <xtd/xtd.forms>

namespace tutorial {
  class form_button : public xtd::forms::form {
  public:
    form_button() {
      text("Button");
      start_position(xtd::forms::form_start_position::center_screen);
      active_control(button_quit);
      
      button_quit.parent(*this);
      button_quit.image(xtd::drawing::system_images::from_name("application-exit", xtd::drawing::size(16, 16)));
      button_quit.image_align(xtd::forms::content_alignment::middle_left);
      button_quit.text("&Quit");
      button_quit.location(xtd::drawing::point(20, 20));
      button_quit.click += xtd::event_handler<xtd::forms::control&>(*this, &form_button::on_quit);
    }

    static void main() {
      xtd::forms::application::enable_button_images();
      xtd::forms::application::run(form_button());
    }
    
  private:
    void on_quit(xtd::forms::control& sender, const xtd::event_args& e) {
      close();
    }
    
    xtd::forms::button button_quit;
  };
}

startup_(tutorial::form_button);
