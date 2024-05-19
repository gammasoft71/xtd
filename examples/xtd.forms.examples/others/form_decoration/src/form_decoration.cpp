#define TRACE
#include <xtd/forms/application>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/text_box>
#include <xtd/forms/switch_button>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    client_size({320, 325});
    controls().push_back_range({form_border_style_choice, caption_label, caption_text_box, minimize_box_label, minimize_box_switch_button, maximize_box_label, maximize_box_switch_button, close_box_label, close_box_switch_button, control_box_label, control_box_switch_button, help_button_label, help_button_switch_button, show_icon_label, show_icon_switch_button, show_in_taskbar_label, show_in_taskbar_switch_button});
    location({400, 200});
    minimum_client_size({client_size()});
    start_position(form_start_position::manual);
    text("Form decoration example");
    
    form_border_style_choice.location({10, 10});
    form_border_style_choice.width(300);
    form_border_style_choice.items().push_back_range({{"none", forms::form_border_style::none}, {"fixed_single", forms::form_border_style::fixed_single}, {"fixed_3d", forms::form_border_style::fixed_3d}, {"fixed_dialog", forms::form_border_style::fixed_dialog}, {"sizable", forms::form_border_style::sizable}, {"fixed_tool_window", forms::form_border_style::fixed_tool_window}, {"sizable_tool_window", forms::form_border_style::sizable_tool_window}});
    form_border_style_choice.selected_index(as<size_t>(form_border_style()));
    form_border_style_choice.selected_index_changed += [&] {
      form_border_style(as<forms::form_border_style>(form_border_style_choice.selected_index()));
    };
    
    caption_label.location({10, 62});
    caption_label.auto_size(true);
    caption_label.text("caption");
    
    caption_text_box.location({110, 60});
    caption_text_box.width(200);
    caption_text_box.text(text());
    caption_text_box.text_changed += [&] {
      text(caption_text_box.text());
    };
    
    minimize_box_label.location({10, 112});
    minimize_box_label.auto_size(true);
    minimize_box_label.text("Minimize box");
    
    minimize_box_switch_button.location({260, 110});
    minimize_box_switch_button.checked(minimize_box());
    minimize_box_switch_button.checked_changed += [&] {
      minimize_box(minimize_box_switch_button.checked());
    };
    
    maximize_box_label.location({10, 142});
    maximize_box_label.auto_size(true);
    maximize_box_label.text("Maximize box");
    
    maximize_box_switch_button.location({260, 140});
    maximize_box_switch_button.checked(maximize_box());
    maximize_box_switch_button.checked_changed += [&] {
      maximize_box(maximize_box_switch_button.checked());
    };
    
    close_box_label.location({10, 172});
    close_box_label.auto_size(true);
    close_box_label.text("Close box");
    
    close_box_switch_button.location({260, 170});
    close_box_switch_button.checked(close_box());
    close_box_switch_button.checked_changed += [&] {
      close_box(close_box_switch_button.checked());
    };
    
    control_box_label.location({10, 202});
    control_box_label.auto_size(true);
    control_box_label.text("Control box");
    
    control_box_switch_button.location({260, 200});
    control_box_switch_button.checked(control_box());
    control_box_switch_button.checked_changed += [&] {
      control_box(control_box_switch_button.checked());
    };
    
    help_button_label.location({10, 232});
    help_button_label.auto_size(true);
    help_button_label.text("Help button");
    
    help_button_switch_button.location({260, 230});
    help_button_switch_button.checked(help_button());
    help_button_switch_button.checked_changed += [&] {
      help_button(help_button_switch_button.checked());
    };
    
    show_icon_label.location({10, 262});
    show_icon_label.auto_size(true);
    show_icon_label.text("Show icon");
    
    show_icon_switch_button.location({260, 260});
    show_icon_switch_button.checked(show_icon());
    show_icon_switch_button.checked_changed += [&] {
      show_icon(show_icon_switch_button.checked());
    };
    
    show_in_taskbar_label.location({10, 292});
    show_in_taskbar_label.auto_size(true);
    show_in_taskbar_label.text("Show in taskbar");
    
    show_in_taskbar_switch_button.location({260, 290});
    show_in_taskbar_switch_button.checked(show_in_taskbar());
    show_in_taskbar_switch_button.checked_changed += [&] {
      show_in_taskbar(show_in_taskbar_switch_button.checked());
    };
  }
  
private:
  choice form_border_style_choice;
  label caption_label;
  text_box caption_text_box;
  label minimize_box_label;
  switch_button minimize_box_switch_button;
  label maximize_box_label;
  switch_button maximize_box_switch_button;
  label close_box_label;
  switch_button close_box_switch_button;
  label control_box_label;
  switch_button control_box_switch_button;
  label help_button_label;
  switch_button help_button_switch_button;
  label show_icon_label;
  switch_button show_icon_switch_button;
  label show_in_taskbar_label;
  switch_button show_in_taskbar_switch_button;
};

auto main() -> int {
  application::run(form1 {});
}
