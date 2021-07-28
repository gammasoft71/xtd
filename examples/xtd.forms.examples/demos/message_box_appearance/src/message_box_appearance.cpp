#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Message box appearance");
    client_size({300, 185});
    
    label_caption.text("Caption : ");
    label_caption.auto_size(true);
    label_caption.location({10, 13});
    label_caption.parent(*this);

    text_caption.text("xtd_forms");
    text_caption.location({90, 10});
    text_caption.parent(*this);
    text_caption.width(200);

    label_message.text("Message : ");
    label_message.auto_size(true);
    label_message.location({10, 48});
    label_message.parent(*this);

    text_message.text("It's fantastic !");
    text_message.location({90, 45});
    text_message.parent(*this);
    text_message.width(200);
    
    label_buttons.text("Buttons : ");
    label_buttons.auto_size(true);
    label_buttons.location({10, 83});
    label_buttons.parent(*this);

    choice_buttons.items().push_back_range({{"ok", message_box_buttons::ok}, {"ok_cancel", message_box_buttons::ok_cancel}, {"abort_retry_ignore", message_box_buttons::abort_retry_ignore}, {"yes_no_cancel", message_box_buttons::yes_no_cancel}, {"yes_no", message_box_buttons::yes_no}, {"retry_cancel", message_box_buttons::retry_cancel}});
    choice_buttons.selected_index(0);
    choice_buttons.location({90, 80});
    choice_buttons.parent(*this);
    choice_buttons.width(200);
    
    label_icons.text("Icons : ");
    label_icons.auto_size(true);
    label_icons.location({10, 118});
    label_icons.parent(*this);

    choice_icons.items().push_back_range({{"none", message_box_icon::none}, {"hand", message_box_icon::hand}, {"stop", message_box_icon::stop}, {"error", message_box_icon::error}, {"question", message_box_icon::question}, {"exclamation", message_box_icon::exclamation}, {"warning", message_box_icon::warning}, {"asterisk", message_box_icon::asterisk}, {"information", message_box_icon::information}});
    choice_icons.selected_index(0);
    choice_icons.location({90, 115});
    choice_icons.parent(*this);
    choice_icons.width(200);

    button_try_it.text("Try it");
    button_try_it.location({10, 150});
    button_try_it.parent(*this);
    button_try_it.click += [&] {
      label_dialog_result.text("result = ");
      label_dialog_result.text(ustring::format("result = {}", message_box::show(*this, text_message.text(), text_caption.text(), any_cast<message_box_buttons>(choice_buttons.selected_item().tag()), any_cast<message_box_icon>(choice_icons.selected_item().tag()))));
    };

    label_dialog_result.text("result = ");
    label_dialog_result.auto_size(true);
    label_dialog_result.location({90, 153});
    label_dialog_result.parent(*this);
  }
  
private:
  label label_caption;
  text_box text_caption;
  label label_message;
  text_box text_message;
  label label_buttons;
  choice choice_buttons;
  label label_icons;
  choice choice_icons;
  button button_try_it;
  label label_dialog_result;
};

int main() {
  application::run(form1());
}
