#include <xtd/xtd>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  form form_main;
  form_main.size({1024, 768});
  form_main.text("Demo forms");
  form_main.menu(forms::main_menu::create_standard_items([&](component& sender, const event_args& e) {
    if (static_cast<menu_item&>(sender).text() == texts::exit()) application::exit();
  }));
  
  tab_control tab_control_main;
  tab_control_main.location({10, 10});
  tab_control_main.parent(form_main);
  tab_control_main.size(form_main.client_size() - drawing::size(20, 20));
  tab_control_main.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
  
  tab_page tab_page_labels;
  tab_page_labels.parent(tab_control_main);
  tab_page_labels.text("Labels");
  tab_page_labels.auto_scroll(true);

  link_label label_label;
  label_label.auto_size(true);
  label_label.location({10, 10});
  label_label.parent(tab_page_labels);
  label_label.text("xtd::forms::label");
  label_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1label.html");
  };

  label default_label;
  default_label.location({30, 40});
  default_label.parent(tab_page_labels);
  default_label.text("Default label");

  label border_fixed_single_label;
  border_fixed_single_label.border_style(forms::border_style::fixed_single);
  border_fixed_single_label.location({140, 40});
  border_fixed_single_label.parent(tab_page_labels);
  border_fixed_single_label.text("Single border");
  border_fixed_single_label.text_align(content_alignment::middle_left);
  
  label border_fixed_3d_label;
  border_fixed_3d_label.border_style(forms::border_style::fixed_3d);
  border_fixed_3d_label.location({250, 40});
  border_fixed_3d_label.parent(tab_page_labels);
  border_fixed_3d_label.text("3d border");
  border_fixed_3d_label.text_align(content_alignment::middle_left);

  label disabled_label;
  disabled_label.enabled(false);
  disabled_label.location({360, 40});
  disabled_label.parent(tab_page_labels);
  disabled_label.text("Disabled label");
  
  label colored_label;
  colored_label.back_color(color::blue);
  colored_label.fore_color(color::yellow);
  colored_label.location({470, 40});
  colored_label.parent(tab_page_labels);
  colored_label.text("Colored label");
  
  label image_label;
  image_label.location({580, 40});
  //image_label.image(system_images::from_name("folder-home", {16, 16}));
  //image_label.image_align(content_alignment::middle_left);
  image_label.parent(tab_page_labels);
  image_label.text("Home");
  //image_label.text_align(content_alignment::middle_right);

  label multiline_label;
  multiline_label.auto_size(true);
  multiline_label.text_align(xtd::forms::content_alignment::middle_center);
  multiline_label.location({690, 40});
  multiline_label.parent(tab_page_labels);
  multiline_label.text("Multiline label\nwith text alignment middle center");
  
  link_label link_label_label;
  link_label_label.auto_size(true);
  link_label_label.location({10, 100});
  link_label_label.parent(tab_page_labels);
  link_label_label.text("xtd::forms::link_label");
  link_label_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1link__label.html");
  };
  
  link_label default_link_label;
  default_link_label.location({30, 130});
  default_link_label.parent(tab_page_labels);
  default_link_label.text("Default label");
  
  link_label border_fixed_single_link_label;
  border_fixed_single_link_label.border_style(forms::border_style::fixed_single);
  border_fixed_single_link_label.location({140, 130});
  border_fixed_single_link_label.parent(tab_page_labels);
  border_fixed_single_link_label.text("Single border");
  border_fixed_single_link_label.text_align(content_alignment::middle_left);

  link_label border_fixed_3d_link_label;
  border_fixed_3d_link_label.border_style(forms::border_style::fixed_3d);
  border_fixed_3d_link_label.location({250, 130});
  border_fixed_3d_link_label.parent(tab_page_labels);
  border_fixed_3d_link_label.text("3d border");
  border_fixed_3d_link_label.text_align(content_alignment::middle_left);

  link_label disabled_link_label;
  disabled_link_label.enabled(false);
  disabled_link_label.location({360, 130});
  disabled_link_label.parent(tab_page_labels);
  disabled_link_label.text("Disabled link");
  
  link_label colored_link_label;
  colored_link_label.back_color(color::blue);
  colored_link_label.link_color(color::yellow);
  colored_link_label.active_link_color(color::lime);
  colored_link_label.location({470, 130});
  colored_link_label.parent(tab_page_labels);
  colored_link_label.text("Colored link");
  
  link_label multiline_link_label;
  multiline_link_label.auto_size(true);
  multiline_link_label.location({580, 130});
  multiline_link_label.parent(tab_page_labels);
  multiline_link_label.text("Multi link label");
  multiline_link_label.links().push_back({0, 5});
  multiline_link_label.links().push_back({11, 5});

  link_label lcd_label_label;
  lcd_label_label.auto_size(true);
  lcd_label_label.location({10, 190});
  lcd_label_label.parent(tab_page_labels);
  lcd_label_label.text("xtd::forms::lcd_label");
  lcd_label_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1lcd__label.html");
  };

  lcd_label default_lcd_label;
  default_lcd_label.auto_size(true);
  default_lcd_label.location({30, 220});
  default_lcd_label.parent(tab_page_labels);
  default_lcd_label.text("1234567890");
  
  lcd_label dot_matrix_lcd_label;
  dot_matrix_lcd_label.auto_size(true);
  dot_matrix_lcd_label.location({180, 220});
  dot_matrix_lcd_label.parent(tab_page_labels);
  dot_matrix_lcd_label.text("ABCDEFG");
  dot_matrix_lcd_label.lcd_style(forms::lcd_style::dot_matrix_display);

  lcd_label disabled_lcd_label;
  disabled_lcd_label.auto_size(true);
  disabled_lcd_label.location({350, 220});
  disabled_lcd_label.parent(tab_page_labels);
  disabled_lcd_label.text("1234567890");
  disabled_lcd_label.enabled(false);

  lcd_label colored_lcd_label;
  colored_lcd_label.auto_size(true);
  colored_lcd_label.back_color(color::blue);
  colored_lcd_label.fore_color(color::yellow);
  colored_lcd_label.location({500, 220});
  colored_lcd_label.parent(tab_page_labels);
  colored_lcd_label.text("1234567890");

  tab_page tab_page_buttons;
  tab_page_buttons.parent(tab_control_main);
  tab_page_buttons.text("Buttons");
  tab_page_buttons.auto_scroll(true);

  link_label button_label;
  button_label.auto_size(true);
  button_label.location({10, 10});
  button_label.parent(tab_page_buttons);
  button_label.text("xtd::forms::button");
  button_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1button.html");
  };

  button default_button;
  default_button.location({30, 40});
  default_button.parent(tab_page_buttons);
  default_button.text("Button");
  
  button flat_button;
  flat_button.flat_style(xtd::forms::flat_style::flat);
  flat_button.location({120, 40});
  flat_button.parent(tab_page_buttons);
  flat_button.text("Flat");
  
  button popup_button;
  popup_button.flat_style(xtd::forms::flat_style::popup);
  popup_button.location({210, 40});
  popup_button.parent(tab_page_buttons);
  popup_button.text("Popup");
  
  button image_button;
  image_button.location({300, 40});
  image_button.width(100);
  image_button.image(button_images::from_name("folder-home"));
  image_button.image_align(content_alignment::middle_left);
  image_button.parent(tab_page_buttons);
  image_button.text("Home");

  button colored_button;
  colored_button.back_color(color::blue);
  colored_button.fore_color(color::yellow);
  colored_button.location({415, 40});
  colored_button.parent(tab_page_buttons);
  colored_button.text("Colored");

  button disabled_button;
  disabled_button.enabled(false);
  disabled_button.location({505, 40});
  disabled_button.parent(tab_page_buttons);
  disabled_button.text("Disabled");

  link_label toggle_button_label;
  toggle_button_label.auto_size(true);
  toggle_button_label.location({10, 100});
  toggle_button_label.parent(tab_page_buttons);
  toggle_button_label.text("xtd::forms::toggle_button");
  toggle_button_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1toggle__button.html");
  };
  
  toggle_button default_toggle_button;
  default_toggle_button.location({30, 130});
  default_toggle_button.parent(tab_page_buttons);
  default_toggle_button.text("Toggle");
  
  toggle_button flat_toggle_button;
  flat_toggle_button.flat_style(xtd::forms::flat_style::flat);
  flat_toggle_button.location({150, 130});
  flat_toggle_button.parent(tab_page_buttons);
  flat_toggle_button.text("Flat");
  
  toggle_button popup_toggle_button;
  popup_toggle_button.flat_style(xtd::forms::flat_style::flat);
  popup_toggle_button.location({270, 130});
  popup_toggle_button.parent(tab_page_buttons);
  popup_toggle_button.text("Popup");
  
  toggle_button image_toggle_button;
  image_toggle_button.location({390, 130});
  image_toggle_button.image(button_images::from_name("folder-home"));
  image_toggle_button.image_align(content_alignment::middle_left);
  image_toggle_button.parent(tab_page_buttons);
  image_toggle_button.text("Home");
 
  toggle_button colored_toggle_button;
  colored_toggle_button.back_color(color::blue);
  colored_toggle_button.fore_color(color::yellow);
  colored_toggle_button.location({510, 130});
  colored_toggle_button.parent(tab_page_buttons);
  colored_toggle_button.text("Colored");

  toggle_button disabled_toggle_button;
  disabled_toggle_button.enabled(false);
  disabled_toggle_button.location({630, 130});
  disabled_toggle_button.parent(tab_page_buttons);
  disabled_toggle_button.text("Disabled");

  link_label swicth_button_label;
  swicth_button_label.auto_size(true);
  swicth_button_label.location({10, 190});
  swicth_button_label.parent(tab_page_buttons);
  swicth_button_label.text("xtd::forms::switch_button");
  swicth_button_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1switch__button.html");
  };
  
  switch_button default_swicth_button;
  default_swicth_button.location({30, 220});
  default_swicth_button.parent(tab_page_buttons);
  default_swicth_button.checked(true);
  
  switch_button rectangle_swicth_button;
  rectangle_swicth_button.location({120, 220});
  rectangle_swicth_button.parent(tab_page_buttons);
  rectangle_swicth_button.checked(true);
  rectangle_swicth_button.rounded(false);
  
  switch_button colored_swicth_button;
  colored_swicth_button.slider_color(color::yellow);
  colored_swicth_button.checked_back_color(color::blue);
  colored_swicth_button.location({210, 220});
  colored_swicth_button.parent(tab_page_buttons);
  colored_swicth_button.checked(true);
  colored_swicth_button.show_text(true);

  switch_button colored_rectangle_swicth_button;
  colored_rectangle_swicth_button.slider_color(color::yellow);
  colored_rectangle_swicth_button.checked_back_color(color::blue);
  colored_rectangle_swicth_button.fore_color(color::white);
  colored_rectangle_swicth_button.location({300, 220});
  colored_rectangle_swicth_button.parent(tab_page_buttons);
  colored_rectangle_swicth_button.rounded(false);
  colored_rectangle_swicth_button.checked(true);
  colored_rectangle_swicth_button.show_text(true);

  switch_button disabled_swicth_button;
  disabled_swicth_button.location({390, 220});
  disabled_swicth_button.parent(tab_page_buttons);
  disabled_swicth_button.enabled(false);

  switch_button disabled_rectangle_swicth_button;
  disabled_rectangle_swicth_button.location({480, 220});
  disabled_rectangle_swicth_button.parent(tab_page_buttons);
  disabled_rectangle_swicth_button.rounded(false);
  disabled_rectangle_swicth_button.enabled(false);

  link_label check_box_label;
  check_box_label.auto_size(true);
  check_box_label.location({10, 280});
  check_box_label.parent(tab_page_buttons);
  check_box_label.text("xtd::forms::check_box");
  check_box_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1check__box.html");
  };

  check_box default_check_box;
  default_check_box.checked(true);
  default_check_box.location({30, 310});
  default_check_box.parent(tab_page_buttons);
  default_check_box.text("Check box");
  
  check_box check_box_three_state;
  check_box_three_state.check_state(forms::check_state::indeterminate);
  check_box_three_state.three_state(true);
  check_box_three_state.location({140, 310});
  check_box_three_state.parent(tab_page_buttons);
  check_box_three_state.text("Three state");
  
  check_box check_box_button;
  check_box_button.appearance(forms::appearance::button);
  check_box_button.location({250, 310});
  check_box_button.parent(tab_page_buttons);
  check_box_button.text("button");
  
  check_box image_check_box;
  image_check_box.location({360, 310});
  image_check_box.image(button_images::from_name("folder-home"));
  image_check_box.image_align(content_alignment::middle_left);
  image_check_box.parent(tab_page_buttons);
  image_check_box.text("Home");
  image_check_box.text_align(content_alignment::middle_center);

  check_box colored_check_box;
  colored_check_box.location({470, 310});
  colored_check_box.back_color(color::blue);
  colored_check_box.fore_color(color::yellow);
  colored_check_box.parent(tab_page_buttons);
  colored_check_box.text("Colored");

  check_box check_box_disabled;
  check_box_disabled.enabled(false);
  check_box_disabled.location({580, 310});
  check_box_disabled.parent(tab_page_buttons);
  check_box_disabled.text("Disabled");
  
  check_box check_box_button_disabled;
  check_box_button_disabled.appearance(forms::appearance::button);
  check_box_button_disabled.enabled(false);
  check_box_button_disabled.location({690, 310});
  check_box_button_disabled.parent(tab_page_buttons);
  check_box_button_disabled.text("button");

  link_label radio_button_label;
  radio_button_label.auto_size(true);
  radio_button_label.location({10, 370});
  radio_button_label.parent(tab_page_buttons);
  radio_button_label.text("xtd::forms::radio_button");
  radio_button_label.link_clicked += [] {
    process::start("https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1forms_1_1radio__button.html");
  };

  radio_button radio_button_one;
  radio_button_one.checked(true);
  radio_button_one.location({30, 400});
  radio_button_one.parent(tab_page_buttons);
  radio_button_one.text("radio 1");

  radio_button radio_button_two;
  radio_button_two.location({140, 400});
  radio_button_two.parent(tab_page_buttons);
  radio_button_two.text("radio 2");

  radio_button radio_button_button;
  radio_button_button.appearance(forms::appearance::button);
  radio_button_button.location({250, 400});
  radio_button_button.parent(tab_page_buttons);
  radio_button_button.text("radio 3");
  
  radio_button image_radio_button;
  image_radio_button.location({360, 400});
  image_radio_button.image(button_images::from_name("folder-home"));
  image_radio_button.image_align(content_alignment::middle_left);
  image_radio_button.parent(tab_page_buttons);
  image_radio_button.text("Home");
  image_radio_button.text_align(content_alignment::middle_center);
  
  radio_button colored_radio_button;
  colored_radio_button.location({470, 400});
  colored_radio_button.back_color(color::blue);
  colored_radio_button.fore_color(color::yellow);
  colored_radio_button.parent(tab_page_buttons);
  colored_radio_button.text("Colored");

  radio_button radio_button_disabled;
  radio_button_disabled.enabled(false);
  radio_button_disabled.location({580, 400});
  radio_button_disabled.parent(tab_page_buttons);
  radio_button_disabled.text("Disabled");
  
  radio_button radio_button_button_disabled;
  radio_button_button_disabled.enabled(false);
  radio_button_button_disabled.appearance(forms::appearance::button);
  radio_button_button_disabled.location({690, 400});
  radio_button_button_disabled.parent(tab_page_buttons);
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
  u8"\U0001F428"_s);
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
