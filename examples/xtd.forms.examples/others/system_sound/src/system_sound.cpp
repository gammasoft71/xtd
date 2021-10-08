#include <xtd/xtd>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::media;

namespace example {
  class form1 : public form {
  public:
    form1() {
      client_size({485, 100});
      controls().push_back(layout_panel);
      padding(5);
      text("System sound example");

      layout_panel.dock(dock_style::fill);
      layout_panel.controls().push_back_range({button_asterisk, button_beep, button_exclamation, button_hand, button_question});
      layout_panel.control_layout_style(button_asterisk, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_beep, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_exclamation, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_hand, {size_type::auto_size, true});
      layout_panel.control_layout_style(button_question, {size_type::auto_size, true});

      button_asterisk.text("asterisk");
      button_asterisk.image(button_images::from_name("dialog-information", drawing::size(64, 64)));
      button_asterisk.image_align(content_alignment::top_center);
      button_asterisk.text_align(content_alignment::bottom_center);
      button_asterisk.click += [&] {
        system_sounds::asterisk().play();
      };
      
      button_beep.text("beep");
      button_beep.image(button_images::from_name("dialog-ok", drawing::size(64, 64)));
      button_beep.image_align(content_alignment::top_center);
      button_beep.text_align(content_alignment::bottom_center);
      button_beep.click += [&] {
        system_sounds::beep().play();
      };
      
      button_exclamation.text("exclamation");
      button_exclamation.image(button_images::from_name("dialog-warning", drawing::size(64, 64)));
      button_exclamation.image_align(content_alignment::top_center);
      button_exclamation.text_align(content_alignment::bottom_center);
      button_exclamation.click += [&] {
        system_sounds::exclamation().play();
      };

      button_hand.text("hand");
      button_hand.image(button_images::from_name("dialog-error", drawing::size(64, 64)));
      button_hand.image_align(content_alignment::top_center);
      button_hand.text_align(content_alignment::bottom_center);
      button_hand.click += [&] {
        system_sounds::hand().play();
      };

      button_question.text("question");
      button_question.image(button_images::from_name("dialog-question", drawing::size(64, 64)));
      button_question.image_align(content_alignment::top_center);
      button_question.text_align(content_alignment::bottom_center);
      button_question.click += [&] {
        system_sounds::question().play();
      };
    }
    
    static void main() {
      application::run(form1());
    }
    
  private:
    horizontal_layout_panel layout_panel;
    button button_asterisk;
    button button_beep;
    button button_exclamation;
    button button_hand;
    button button_question;
  };
}

startup_(example::form1);
