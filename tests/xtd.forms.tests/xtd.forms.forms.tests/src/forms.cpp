#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class forms_form : public form {
public:
  static void main() {
    debug_form df;
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
    form_styles_tab_control.controls().push_back_range({decorations_tab_page, window_state_tab_page, show_tab_page});

    decorations_tab_page.text("decorations");
    decorations_tab_page.controls().push_back_range({form_border_style_choice, caption_label, caption_text_box, minimize_box_label, minimize_box_switch_button, maximize_box_label, maximize_box_switch_button, close_box_label, close_box_switch_button, control_box_label, control_box_switch_button, help_button_label, help_button_switch_button, show_icon_label, show_icon_switch_button, show_in_taskbar_label, show_in_taskbar_switch_button});

    window_state_tab_page.text("state");
    window_state_tab_page.controls().push_back_range({state_full_screen_button, state_maximize_button, state_normal_button, state_minimize_button});

    show_tab_page.text("show");
    show_tab_page.controls().push_back_range({show_normal_button, show_modeless_button, show_top_most_button, show_modal_button, show_sheet_button, show_sheet_modal_button});

    form_border_style_choice.location({10, 10});
    form_border_style_choice.width(200);
    form_border_style_choice.items().push_back_range({
      {"none", forms::form_border_style::none},
      {"fixed_single", forms::form_border_style::fixed_single},
      {"fixed_3d", forms::form_border_style::fixed_3d},
      {"fixed_dialog", forms::form_border_style::fixed_dialog},
      {"sizable", forms::form_border_style::sizable},
      {"fixed_tool_window", forms::form_border_style::fixed_tool_window},
      {"sizable_tool_window", forms::form_border_style::sizable_tool_window},
    });
    form_border_style_choice.selected_index(static_cast<size_t>(form_border_style()));
    form_border_style_choice.selected_index_changed += [&] {
      form_border_style(static_cast<forms::form_border_style>(form_border_style_choice.selected_index()));
    };
    
    caption_label.location({10, 42});
    caption_label.text("caption");
    
    caption_text_box.location({110, 40});
    caption_text_box.width(100);
    caption_text_box.text(text());
    caption_text_box.text_changed += [&] {
      text(caption_text_box.text());
    };
    
    minimize_box_label.location({10, 72});
    minimize_box_label.text("Minimize box");
    
    minimize_box_switch_button.location({160, 70});
    minimize_box_switch_button.checked(minimize_box());
    minimize_box_switch_button.checked_changed += [&] {
      minimize_box(minimize_box_switch_button.checked());
    };
    
    maximize_box_label.location({10, 102});
    maximize_box_label.text("Maximize box");
    
    maximize_box_switch_button.location({160, 100});
    maximize_box_switch_button.checked(maximize_box());
    maximize_box_switch_button.checked_changed += [&] {
      maximize_box(maximize_box_switch_button.checked());
    };
    
    close_box_label.location({10, 132});
    close_box_label.text("Close box");
    
    close_box_switch_button.location({160, 130});
    close_box_switch_button.checked(close_box());
    close_box_switch_button.checked_changed += [&] {
      close_box(close_box_switch_button.checked());
    };
    
    control_box_label.location({10, 162});
    control_box_label.text("Control box");
    
    control_box_switch_button.location({160, 160});
    control_box_switch_button.checked(control_box());
    control_box_switch_button.checked_changed += [&] {
      control_box(control_box_switch_button.checked());
    };
    
    help_button_label.location({10, 192});
    help_button_label.text("Help button");
    
    help_button_switch_button.location({160, 190});
    help_button_switch_button.checked(help_button());
    help_button_switch_button.checked_changed += [&] {
      help_button(help_button_switch_button.checked());
    };
    
    show_icon_label.location({10, 222});
    show_icon_label.text("Show icon");
    
    show_icon_switch_button.location({160, 220});
    show_icon_switch_button.checked(show_icon());
    show_icon_switch_button.checked_changed += [&] {
      show_icon(show_icon_switch_button.checked());
    };
    
    show_in_taskbar_label.location({10, 252});
    show_in_taskbar_label.text("Show in taskbar");
    
    show_in_taskbar_switch_button.location({160, 250});
    show_in_taskbar_switch_button.checked(show_in_taskbar());
    show_in_taskbar_switch_button.checked_changed += [&] {
      show_in_taskbar(show_in_taskbar_switch_button.checked());
    };

    state_full_screen_button.location({10, 10});
    state_full_screen_button.text("Full screen");
    state_full_screen_button.width(90);
    state_full_screen_button.click += [&] {
      window_state(form_window_state::full_screen);
    };
    
    state_maximize_button.location({10, 40});
    state_maximize_button.text("Maximize");
    state_maximize_button.width(90);
    state_maximize_button.click += [&] {
      window_state(form_window_state::maximized);
    };
    
    state_normal_button.location({10, 70});
    state_normal_button.text("Normal");
    state_normal_button.width(90);
    state_normal_button.click += [&] {
      window_state(form_window_state::normal);
    };
    
    state_minimize_button.location({10, 100});
    state_minimize_button.text("Minimize");
    state_minimize_button.width(90);
    state_minimize_button.click += [&] {
      window_state(form_window_state::minimized);
    };

    show_normal_button.location({10, 10});
    show_normal_button.width(140);
    show_normal_button.text("Show normal");
    show_normal_button.click += [&] {
      auto dialog = control::create<form>("dialog show normal", {}, {250, 100});
      dialog->show();
      dialogs.push_back(move(dialog));
    };
    
    show_modeless_button.location({10, 40});
    show_modeless_button.width(140);
    show_modeless_button.text("Show modeless");
    show_modeless_button.click += [&] {
      auto dialog = control::create<form>("dialog show modeless", {}, {250, 100});
      dialog->owner(*this).show();
      dialogs.push_back(move(dialog));
    };
    
    show_top_most_button.location({10, 70});
    show_top_most_button.width(140);
    show_top_most_button.text("Show top most");
    show_top_most_button.click += [&] {
      auto dialog = control::create<form>("dialog top most", {}, {250, 100});
      dialog->top_most(true).show();
      dialogs.push_back(move(dialog));
    };
    
    show_modal_button.location({10, 100});
    show_modal_button.width(140);
    show_modal_button.text("Show modal");
    show_modal_button.click += [&] {
      auto dialog = control::create<form>("dialog show modal", {}, {250, 100});
      dialog->show_dialog(*this);
    };
    
    show_sheet_button.location({10, 130});
    show_sheet_button.width(140);
    show_sheet_button.text("Show sheet");
    show_sheet_button.click += [&] {
      auto dialog = control::create<form>("dialog show sheet", {}, {250, 100});
      dialog->key_up += [&](object & control, key_event_args & e) {
        if (e.key_code() == keys::escape) as<form&>(control).close();
      };
      dialog->show_sheet(*this);
      dialogs.push_back(move(dialog));
    };
    
    show_sheet_modal_button.location({10, 160});
    show_sheet_modal_button.width(140);
    show_sheet_modal_button.text("Show sheet modal");
    show_sheet_modal_button.click += [&] {
      auto dialog = control::create<form>("dialog show sheet modal", {}, {250, 100});
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

startup_(forms_form);
