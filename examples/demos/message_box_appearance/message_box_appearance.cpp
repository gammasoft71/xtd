#include <xtd/xtd.forms>

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

    combo_box_buttons.items().push_back_range({{"ok", message_box_buttons::ok}, {"ok_cancel", message_box_buttons::ok_cancel}, {"abort_retry_ignore", message_box_buttons::abort_retry_ignore}, {"yes_no_cancel", message_box_buttons::yes_no_cancel}, {"yes_no", message_box_buttons::yes_no}, {"retry_cancel", message_box_buttons::retry_cancel}});
    combo_box_buttons.drop_down_style(combo_box_style::drop_down_list);
    combo_box_buttons.selected_index(0);
    combo_box_buttons.location({90, 80});
    combo_box_buttons.parent(*this);
    combo_box_buttons.width(200);
    
    label_icons.text("Icons : ");
    label_icons.auto_size(true);
    label_icons.location({10, 118});
    label_icons.parent(*this);

    combo_box_icons.items().push_back_range({{"none", message_box_icon::none}, {"hand", message_box_icon::hand}, {"stop", message_box_icon::stop}, {"error", message_box_icon::error}, {"question", message_box_icon::question}, {"exclamation", message_box_icon::exclamation}, {"warning", message_box_icon::warning}, {"asterick", message_box_icon::asterisk}, {"information", message_box_icon::information}});
    combo_box_icons.drop_down_style(combo_box_style::drop_down_list);
    combo_box_icons.selected_index(0);
    combo_box_icons.location({90, 115});
    combo_box_icons.parent(*this);
    combo_box_icons.width(200);

    button_try_it.text("Try it");
    button_try_it.location({10, 150});
    button_try_it.height(30);
    button_try_it.parent(*this);
    button_try_it.click += [this] {
      label_dialog_result.text("dialog_result = ");
      enum dialog_result result = message_box::show(*this, text_message.text(), text_caption.text(), any_cast<message_box_buttons>(combo_box_buttons.selected_item().tag()), any_cast<message_box_icon>(combo_box_icons.selected_item().tag()));
      label_dialog_result.text(strings::format("dialog_result = {}", result));
    };

    label_dialog_result.text("dialog_result = ");
    label_dialog_result.auto_size(true);
    label_dialog_result.location({90, 156});
    label_dialog_result.parent(*this);
  }
  
private:
  label label_caption;
  text_box text_caption;
  label label_message;
  text_box text_message;
  label label_buttons;
  combo_box combo_box_buttons;
  label label_icons;
  combo_box combo_box_icons;
  button button_try_it;
  label label_dialog_result;
};

int main() {
  application::run(form1());
}
