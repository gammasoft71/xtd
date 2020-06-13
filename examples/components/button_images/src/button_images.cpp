#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Button images example");
      client_size({310, 170});

      button_ok.parent(*this);
      button_ok.image(button_images::ok());
      button_ok.image_align(content_alignment::middle_left);
      button_ok.text(texts::ok);
      button_ok.location({10, 10});
      button_ok.width(90);

      button_apply.parent(*this);
      button_apply.image(button_images::apply());
      button_apply.image_align(content_alignment::middle_left);
      button_apply.text(texts::apply);
      button_apply.location({110, 10});
      button_apply.width(90);

      button_cancel.parent(*this);
      button_cancel.image(button_images::cancel());
      button_cancel.image_align(content_alignment::middle_left);
      button_cancel.text(texts::cancel);
      button_cancel.location({210, 10});
      button_cancel.width(90);

      button_yes.parent(*this);
      button_yes.image(button_images::yes());
      button_yes.image_align(content_alignment::middle_left);
      button_yes.text(texts::yes);
      button_yes.location({10, 50});
      button_yes.width(90);
      
      button_no.parent(*this);
      button_no.image(button_images::no());
      button_no.image_align(content_alignment::middle_left);
      button_no.text(texts::no);
      button_no.location({110, 50});
      button_no.width(90);

      button_add.parent(*this);
      button_add.image(button_images::add());
      button_add.image_align(content_alignment::middle_left);
      button_add.text(texts::add);
      button_add.location({10, 90});
      button_add.width(90);
      
      button_remove.parent(*this);
      button_remove.image(button_images::remove());
      button_remove.image_align(content_alignment::middle_left);
      button_remove.text(texts::remove);
      button_remove.location({110, 90});
      button_remove.width(90);

      button_previous.parent(*this);
      button_previous.image(button_images::previous());
      button_previous.image_align(content_alignment::middle_left);
      button_previous.text(texts::previous);
      button_previous.location({10, 130});
      button_previous.width(90);
      
      button_next.parent(*this);
      button_next.image(button_images::next());
      button_next.image_align(content_alignment::middle_left);
      button_next.text(texts::next);
      button_next.location({110, 130});
      button_next.width(90);
      
      button_go_home.parent(*this);
      button_go_home.image(button_images::from_name("go-home"));
      button_go_home.image_align(content_alignment::middle_left);
      button_go_home.text(texts::next);
      button_go_home.location({210, 130});
      button_go_home.width(90);
    }
    
  private:
    button button_ok;
    button button_apply;
    button button_cancel;
    button button_yes;
    button button_no;
    button button_add;
    button button_remove;
    button button_previous;
    button button_next;
    button button_go_home;
  };
}

int main() {
  application::run(examples::form1());
}
