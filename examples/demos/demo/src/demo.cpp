#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  form form_main;
  form_main.client_size({1280, 850});
  form_main.text("Demo forms");
  
  tab_control tab_control_main;
  tab_control_main.location({10, 10});
  tab_control_main.parent(form_main);
  tab_control_main.size(form_main.client_size() - size(20, 20));
  tab_control_main.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
  
  tab_page tab_page_controls;
  tab_page_controls.parent(tab_control_main);
  tab_page_controls.text("Controls");
  tab_page_controls.auto_scroll(true);

  label label_one;
  label_one.location({10, 10});
  label_one.parent(tab_page_controls);
  label_one.text("Label");
  
  label label_border_fixed_single;
  label_border_fixed_single.border_style(forms::border_style::fixed_single);
  label_border_fixed_single.location({120, 10});
  label_border_fixed_single.parent(tab_page_controls);
  label_border_fixed_single.text("Single border");
  
  label label_border_fixed_3d;
  label_border_fixed_3d.border_style(forms::border_style::fixed_3d);
  label_border_fixed_3d.location({230, 10});
  label_border_fixed_3d.parent(tab_page_controls);
  label_border_fixed_3d.text("3d border");
  
  label label_disabled;
  label_disabled.enabled(false);
  label_disabled.location({340, 10});
  label_disabled.parent(tab_page_controls);
  label_disabled.text("Disabled");

  button button_enabled;
  button_enabled.location({10, 50});
  button_enabled.parent(tab_page_controls);
  button_enabled.text("Click me");
  
  button button_flat;
  //button_flat.button_style;
  button_flat.location({120, 50});
  button_flat.parent(tab_page_controls);
  button_flat.text("Flat");
  
  button button_disabled;
  button_disabled.enabled(false);
  button_disabled.location({230, 50});
  button_disabled.parent(tab_page_controls);
  button_disabled.text("Disabled");

  check_box check_box_two_state;
  check_box_two_state.checked(true);
  check_box_two_state.location({10, 90});
  check_box_two_state.parent(tab_page_controls);
  check_box_two_state.text("Check box");
  
  check_box check_box_three_state;
  check_box_three_state.check_state(forms::check_state::indeterminate);
  check_box_three_state.three_state(true);
  check_box_three_state.location({120, 90});
  check_box_three_state.parent(tab_page_controls);
  check_box_three_state.text("Three state");
  
  check_box check_box_button;
  check_box_button.appearance(forms::appearance::button);
  check_box_button.location({230, 90});
  check_box_button.parent(tab_page_controls);
  check_box_button.text("button");
  
  check_box check_box_disabled;
  check_box_disabled.enabled(false);
  check_box_disabled.location({340, 90});
  check_box_disabled.parent(tab_page_controls);
  check_box_disabled.text("Disabled");
  
  check_box check_box_button_disabled;
  check_box_button_disabled.appearance(forms::appearance::button);
  check_box_button_disabled.enabled(false);
  check_box_button_disabled.location({450, 90});
  check_box_button_disabled.parent(tab_page_controls);
  check_box_button_disabled.text("button");

  radio_button radio_button_one;
  radio_button_one.checked(true);
  radio_button_one.location({10, 130});
  radio_button_one.parent(tab_page_controls);
  radio_button_one.text("radio 1");

  radio_button radio_button_two;
  radio_button_two.location({120, 130});
  radio_button_two.parent(tab_page_controls);
  radio_button_two.text("radio 2");

  radio_button radio_button_button;
  radio_button_button.appearance(forms::appearance::button);
  radio_button_button.location({230, 130});
  radio_button_button.parent(tab_page_controls);
  radio_button_button.text("radio 3");
  
  radio_button radio_button_disabled;
  radio_button_disabled.enabled(false);
  radio_button_disabled.location({340, 130});
  radio_button_disabled.parent(tab_page_controls);
  radio_button_disabled.text("Disabled");
  
  radio_button radio_button_button_disabled;
  radio_button_button_disabled.enabled(false);
  radio_button_button_disabled.appearance(forms::appearance::button);
  radio_button_button_disabled.location({450, 130});
  radio_button_button_disabled.parent(tab_page_controls);
  radio_button_button_disabled.text("Disabled");
  
  tab_page tab_page_texts;
  tab_page_texts.parent(tab_control_main);
  tab_page_texts.text("Texts");
  tab_page_texts.auto_scroll(true);

  tab_page tab_page_lists;
  tab_page_lists.parent(tab_control_main);
  tab_page_lists.text("Lists");
  tab_page_lists.auto_scroll(true);

  list_box list_box_items;
  list_box_items.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
  list_box_items.location({10, 10});
  list_box_items.parent(tab_page_lists);
  list_box_items.selected_index(1);
  list_box_items.size({200, 300});
  
  list_box list_box_disabled;
  list_box_disabled.enabled(false);
  list_box_disabled.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
  list_box_disabled.location({220, 10});
  list_box_disabled.parent(tab_page_lists);
  list_box_disabled.selected_index(1);
  list_box_disabled.size({200, 300});
  
  checked_list_box checked_list_box_items;
  checked_list_box_items.items().push_back_range({{"Item 1", true}, {"Item 2", true}, {"Item 3", false}, {"Item 4", false}, {"Item 5", true}, {"Item 6", true}, {"Item 7", false}, {"Item 8", false}, {"Item 9", true}, {"Item 10", true}});
  checked_list_box_items.location({10, 320});
  checked_list_box_items.parent(tab_page_lists);
  checked_list_box_items.selected_index(2);
  checked_list_box_items.size({200, 300});
  
  checked_list_box checked_list_box_disabled;
  checked_list_box_disabled.enabled(false);
  checked_list_box_disabled.items().push_back_range({{"Item 1", true}, {"Item 2", true}, {"Item 3", false}, {"Item 4", false}, {"Item 5", true}, {"Item 6", true}, {"Item 7", false}, {"Item 8", false}, {"Item 9", true}, {"Item 10", true}});
  checked_list_box_disabled.location({220, 320});
  checked_list_box_disabled.parent(tab_page_lists);
  checked_list_box_disabled.selected_index(2);
  checked_list_box_disabled.size({200, 300});
  
  combo_box combo_box_drop_down;
  combo_box_drop_down.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
  combo_box_drop_down.location({10, 630});
  combo_box_drop_down.parent(tab_page_lists);
  combo_box_drop_down.selected_index(2);
  combo_box_drop_down.width(200);
  
  combo_box combo_box_drop_down_list;
  combo_box_drop_down_list.drop_down_style(combo_box_style::drop_down_list);
  combo_box_drop_down_list.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
  combo_box_drop_down_list.location({220, 630});
  combo_box_drop_down_list.parent(tab_page_lists);
  combo_box_drop_down_list.selected_index(2);
  combo_box_drop_down_list.width(200);

  combo_box combo_box_simple;
  combo_box_simple.drop_down_style(combo_box_style::simple);
  combo_box_simple.items().push_back_range({"Item 1", "Item 2", "Item 3", "Item 4", "Item 5", "Item 6", "Item 7", "Item 8", "Item 9", "Item 10"});
  combo_box_simple.location({430, 630});
  combo_box_simple.parent(tab_page_lists);
  combo_box_simple.selected_index(2);
  combo_box_simple.width(200);

  tab_page tab_page_pickers;
  tab_page_pickers.parent(tab_control_main);
  tab_page_pickers.text("Pickers");
  tab_page_pickers.auto_scroll(true);

  tab_page tab_page_containers;
  tab_page_containers.parent(tab_control_main);
  tab_page_containers.text("Containers");
  tab_page_containers.auto_scroll(true);

  group_box group_box1;
  group_box1.location({10, 10});
  group_box1.parent(tab_page_containers);
  group_box1.size({400, 250});
  group_box1.text("group_box");
  
  group_box group_box2;
  group_box2.location({420, 10});
  group_box2.parent(tab_page_containers);
  group_box2.size({400, 250});
  
  panel panel1;
  panel1.border_style(forms::border_style::fixed_single);
  panel1.location({830, 10});
  panel1.parent(tab_page_containers);
  panel1.size({400, 250});
  
  panel panel2;
  panel2.border_style(forms::border_style::fixed_3d);
  panel2.location({830, 270});
  panel2.parent(tab_page_containers);
  panel2.size({400, 250});
  
  panel panel3;
  panel3.back_color(system_colors::window());
  panel3.location({830, 530});
  panel3.parent(tab_page_containers);
  panel3.size({400, 250});

  tab_control tab_control_top;
  tab_control_top.location({10, 270});
  tab_control_top.parent(tab_page_containers);
  tab_control_top.size({400, 250});
  tab_page tab_page_top1;
  tab_page_top1.parent(tab_control_top);
  tab_page_top1.text("Page 1");
  tab_page tab_page_top2;
  tab_page_top2.parent(tab_control_top);
  tab_page_top2.text("Page 2");
  tab_page tab_page_top3;
  tab_page_top3.parent(tab_control_top);
  tab_page_top3.text("Page 3");
  
  tab_control tab_control_right;
  tab_control_right.alignment(tab_alignment::right);
  tab_control_right.location({420, 270});
  tab_control_right.parent(tab_page_containers);
  tab_control_right.size({400, 250});
  tab_page tab_page_right1;
  tab_page_right1.parent(tab_control_right);
  tab_page_right1.text("Page 1");
  tab_page tab_page_right2;
  tab_page_right2.parent(tab_control_right);
  tab_page_right2.text("Page 2");
  tab_page tab_page_right3;
  tab_page_right3.parent(tab_control_right);
  tab_page_right3.text("PAge 3");
  
  tab_control tab_control_bottom;
  tab_control_bottom.alignment(tab_alignment::bottom);
  tab_control_bottom.location({10, 530});
  tab_control_bottom.parent(tab_page_containers);
  tab_control_bottom.size({400, 250});
  tab_page tab_page_bottom1;
  tab_page_bottom1.parent(tab_control_bottom);
  tab_page_bottom1.text("Page 1");
  tab_page tab_page_bottom2;
  tab_page_bottom2.parent(tab_control_bottom);
  tab_page_bottom2.text("Page 2");
  tab_page tab_page_bottom3;
  tab_page_bottom3.parent(tab_control_bottom);
  tab_page_bottom3.text("Page 3");
  
  tab_control tab_control_left;
  tab_control_left.alignment(tab_alignment::left);
  tab_control_left.location({420, 530});
  tab_control_left.parent(tab_page_containers);
  tab_control_left.size({400, 250});
  tab_page tab_page_left1;
  tab_page_left1.parent(tab_control_left);
  tab_page_left1.text("Page 1");
  tab_page tab_page_left2;
  tab_page_left2.parent(tab_control_left);
  tab_page_left2.text("Page 2");
  tab_page tab_page_left3;
  tab_page_left3.parent(tab_control_left);
  tab_page_left3.text("Page 3");

  tab_page tab_page_dialogs;
  tab_page_dialogs.parent(tab_control_main);
  tab_page_dialogs.text("Dialogs");
  tab_page_dialogs.auto_scroll(true);

  panel panel_color;
  panel_color.location({10, 10});
  panel_color.border_style(forms::border_style::fixed_single);
  panel_color.back_color(system_colors::window());
  panel_color.parent(tab_page_dialogs);
  panel_color.size({400, 250});
  panel_color.click += [&] {
    color_dialog dialog;
    dialog.color(panel_color.back_color());
    if (dialog.show_dialog() == dialog_result::ok)
      panel_color.back_color(dialog.color());
  };
  
  panel panel_font;
  panel_font.border_style(forms::border_style::fixed_single);
  panel_font.location({420, 10});
  panel_font.parent(tab_page_dialogs);
  panel_font.size({400, 250});
  label label_font;
  label_font.dock(dock_style::fill);
  label_font.parent(panel_font);
  label_font.text(u8"The quick brown fox jumps over the lazy dog.\n"
  u8"THE QUICK BROWN FOX JUMPS OVER THE LAZY DOG.\n"
  u8"0123456789+-*/%~^&|=<>≤≥±÷≠{{[()]}},;:.?¿!¡\n"
  u8"àçéèêëïî@@°_#§$ù£€æœøπµ©®∞\\\"'\n"
  u8"\u0400\u0401\u0402\u0403\u0404\u0405\u0406\u0407\u0408\u0409\u040a\u040b\u040c\u040d\u040e\u040f\n"
  u8"\u0410\u0411\u0412\u0413\u0414\u0415\u0416\u0417\u0418\u0419\u041a\u041b\u041c\u041d\u041e\u041f\n"
  u8"\u4ea0\u4ea1\u4ea2\u4ea3\u4ea4\u4ea5\u4ea6\u4ea7\u4ea8\u4ea9\u4eaa\u4eab\u4eac\u4ead\u4eae\u4eaf\n"
  u8"\u4eb0\u4eb1\u4eb2\u4eb3\u4eb4\u4eb5\u4eb6\u4eb7\u4eb8\u4eb9\u4eba\u4ebb\u4ebc\u4ebd\u4ebe\u4ebf\n"
  u8"\U0001F428");
  label_font.click += [&] {
    font_dialog dialog;
    dialog.color(label_font.fore_color());
    dialog.font(label_font.font());
    if (dialog.show_dialog() == dialog_result::ok) {
      label_font.fore_color(dialog.color());
      label_font.font(dialog.font());
    }
  };

  application::run(form_main);
}
