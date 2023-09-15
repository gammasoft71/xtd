#include <xtd/forms/application>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/switch_button>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/forms/text_box>
#include <xtd/startup>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class forms_form : public form {
public:
  static auto main() {
    application::run(forms_form());
  }
  
  forms_form() {
    controls().push_back_range({form_styles_tab_control});
    start_position(form_start_position::manual);
    location({400, 200});
    size({600, 480});
    text("forms tests");
    padding(10);
    
    form_styles_tab_control.dock(dock_style::fill);
    form_styles_tab_control.tab_pages().push_back_range({decorations_tab_page, window_state_tab_page, show_tab_page});
    
    decorations_tab_page.text("decorations");
    decorations_tab_page.controls().push_back_range({form_border_style_choice, caption_label, caption_text_box, minimize_box_label, minimize_box_switch_button, maximize_box_label, maximize_box_switch_button, close_box_label, close_box_switch_button, control_box_label, control_box_switch_button, help_button_label, help_button_switch_button, show_icon_label, show_icon_switch_button, show_in_taskbar_label, show_in_taskbar_switch_button});
    
    window_state_tab_page.text("state");
    window_state_tab_page.controls().push_back_range({state_full_screen_button, state_maximize_button, state_normal_button, state_minimize_button});
    
    show_tab_page.text("show");
    show_tab_page.controls().push_back_range({show_normal_button, show_modeless_button, show_top_most_button, show_modal_button, show_sheet_button, show_sheet_modal_button});
    
    form_border_style_choice.location({10, 10});
    form_border_style_choice.width(200);
    form_border_style_choice.items().push_back_range({{"none", forms::form_border_style::none}, {"fixed_single", forms::form_border_style::fixed_single}, {"fixed_3d", forms::form_border_style::fixed_3d}, {"fixed_dialog", forms::form_border_style::fixed_dialog}, {"sizable", forms::form_border_style::sizable}, {"fixed_tool_window", forms::form_border_style::fixed_tool_window}, {"sizable_tool_window", forms::form_border_style::sizable_tool_window}});
    form_border_style_choice.selected_index(static_cast<size_t>(form_border_style()));
    form_border_style_choice.selected_index_changed += [&] {
      form_border_style(static_cast<forms::form_border_style>(form_border_style_choice.selected_index()));
    };
    
    caption_label.location({10, 62});
    caption_label.text("caption");
    
    caption_text_box.location({110, 60});
    caption_text_box.width(100);
    caption_text_box.text(text());
    caption_text_box.text_changed += [&] {
      text(caption_text_box.text());
    };
    
    minimize_box_label.location({10, 112});
    minimize_box_label.text("Minimize box");
    
    minimize_box_switch_button.location({160, 110});
    minimize_box_switch_button.checked(minimize_box());
    minimize_box_switch_button.checked_changed += [&] {
      minimize_box(minimize_box_switch_button.checked());
    };
    
    maximize_box_label.location({10, 142});
    maximize_box_label.text("Maximize box");
    
    maximize_box_switch_button.location({160, 140});
    maximize_box_switch_button.checked(maximize_box());
    maximize_box_switch_button.checked_changed += [&] {
      maximize_box(maximize_box_switch_button.checked());
    };
    
    close_box_label.location({10, 172});
    close_box_label.text("Close box");
    
    close_box_switch_button.location({160, 170});
    close_box_switch_button.checked(close_box());
    close_box_switch_button.checked_changed += [&] {
      close_box(close_box_switch_button.checked());
    };
    
    control_box_label.location({10, 202});
    control_box_label.text("Control box");
    
    control_box_switch_button.location({160, 200});
    control_box_switch_button.checked(control_box());
    control_box_switch_button.checked_changed += [&] {
      control_box(control_box_switch_button.checked());
    };
    
    help_button_label.location({10, 232});
    help_button_label.text("Help button");
    
    help_button_switch_button.location({160, 230});
    help_button_switch_button.checked(help_button());
    help_button_switch_button.checked_changed += [&] {
      help_button(help_button_switch_button.checked());
    };
    
    show_icon_label.location({10, 262});
    show_icon_label.text("Show icon");
    
    show_icon_switch_button.location({160, 260});
    show_icon_switch_button.checked(show_icon());
    show_icon_switch_button.checked_changed += [&] {
      show_icon(show_icon_switch_button.checked());
    };
    
    show_in_taskbar_label.location({10, 292});
    show_in_taskbar_label.text("Show in taskbar");
    
    show_in_taskbar_switch_button.location({160, 290});
    show_in_taskbar_switch_button.checked(show_in_taskbar());
    show_in_taskbar_switch_button.checked_changed += [&] {
      show_in_taskbar(show_in_taskbar_switch_button.checked());
    };
    
    state_full_screen_button.location({10, 10});
    state_full_screen_button.text("Full screen");
    state_full_screen_button.size({90, 30});
    state_full_screen_button.click += [&] {
      window_state(form_window_state::full_screen);
    };
    
    state_maximize_button.location({10, 50});
    state_maximize_button.text("Maximize");
    state_maximize_button.size({90, 30});
    state_maximize_button.click += [&] {
      window_state(form_window_state::maximized);
    };
    
    state_normal_button.location({10, 90});
    state_normal_button.text("Normal");
    state_normal_button.size({90, 30});
    state_normal_button.click += [&] {
      window_state(form_window_state::normal);
    };
    
    state_minimize_button.location({10, 130});
    state_minimize_button.text("Minimize");
    state_minimize_button.size({90, 30});
    state_minimize_button.click += [&] {
      window_state(form_window_state::minimized);
    };
    
    show_normal_button.location({10, 10});
    show_normal_button.size({140, 30});
    show_normal_button.text("Show normal");
    show_normal_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog show normal");
      dialog->size({250, 100});
      dialog->show();
      dialogs.push_back(std::move(dialog));
    };
    
    show_modeless_button.location({10, 50});
    show_modeless_button.size({140, 30});
    show_modeless_button.text("Show modeless");
    show_modeless_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog show modeless");
      dialog->size({250, 100});
      dialog->owner(*this).show();
      dialogs.push_back(std::move(dialog));
    };
    
    show_top_most_button.location({10, 90});
    show_top_most_button.size({140, 30});
    show_top_most_button.text("Show top most");
    show_top_most_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog top most");
      dialog->size({250, 100});
      dialog->top_most(true).show();
      dialogs.push_back(std::move(dialog));
    };
    
    show_modal_button.location({10, 130});
    show_modal_button.size({140, 30});
    show_modal_button.text("Show modal");
    show_modal_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog show modal");
      dialog->size({250, 100});
      dialog->show_dialog(*this);
    };
    
    show_sheet_button.location({10, 170});
    show_sheet_button.size({140, 30});
    show_sheet_button.text("Show sheet");
    show_sheet_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog show sheet");
      dialog->size({250, 100});
      dialog->key_up += [&](object & control, key_event_args & e) {
        if (e.key_code() == keys::escape) as<form&>(control).close();
      };
      dialog->show_sheet(*this);
      dialogs.push_back(std::move(dialog));
    };
    
    show_sheet_modal_button.location({10, 210});
    show_sheet_modal_button.size({140, 30});
    show_sheet_modal_button.text("Show sheet modal");
    show_sheet_modal_button.click += [&] {
      auto dialog = std::make_unique<form>();
      dialog->text("dialog show sheet modal");
      dialog->size({250, 100});
      dialog->key_up += [&](object & control, key_event_args & e) {
        if (e.key_code() == keys::escape) as<form&>(control).close();
      };
      dialog->show_sheet_dialog(*this);
    };
  }
  
private:
  tab_control form_styles_tab_control;
  tab_page decorations_tab_page;
  tab_page window_state_tab_page;
  tab_page show_tab_page;
  
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
  
  button state_full_screen_button;
  button state_maximize_button;
  button state_normal_button;
  button state_minimize_button;
  
  button show_normal_button;
  button show_modeless_button;
  button show_top_most_button;
  button show_modal_button;
  button show_sheet_button;
  button show_sheet_modal_button;
  vector<shared_ptr<form>> dialogs;
};

startup_(forms_form::main);
