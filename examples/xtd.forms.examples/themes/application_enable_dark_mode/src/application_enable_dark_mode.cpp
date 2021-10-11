#include <xtd/xtd>

using namespace xtd::forms;

namespace xtd {
  namespace forms {
    using light_button = button;
  }
}

class form1 : public form {
public:
  form1() {
    client_size({650, 450});
    text("Dark theme example");
    
    tab_control_controls.parent(*this);
    tab_control_controls.location({10, 10});
    tab_control_controls.size({630, 430});
    tab_control_controls.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);

    tab_page_buttons.parent(tab_control_controls);
    tab_page_buttons.auto_scroll(true);
    tab_page_buttons.text("Buttons");
    tab_page_pickers.parent(tab_control_controls);
    tab_page_pickers.auto_scroll(true);
    tab_page_pickers.text("Pickers");
    tab_page_texts.parent(tab_control_controls);
    tab_page_texts.auto_scroll(true);
    tab_page_texts.text("Texts");
    tab_page_lcds.parent(tab_control_controls);
    tab_page_lcds.auto_scroll(true);
    tab_page_lcds.text("LCDs");
    tab_page_choices.parent(tab_control_controls);
    tab_page_choices.auto_scroll(true);
    tab_page_choices.text("Choices");
    tab_page_lists.parent(tab_control_controls);
    tab_page_lists.auto_scroll(true);
    tab_page_lists.text("Lists");
    tab_page_progress_and_track_bars.parent(tab_control_controls);
    tab_page_progress_and_track_bars.auto_scroll(true);
    tab_page_progress_and_track_bars.text("Progresses");
    tab_page_scrolls.parent(tab_control_controls);
    tab_page_scrolls.auto_scroll(true);
    tab_page_scrolls.text("Scrolls");
    tab_page_animations.parent(tab_control_controls);
    tab_page_animations.auto_scroll(true);
    tab_page_animations.text("Animations");

    button1.parent(tab_page_buttons);
    button1.location({10, 10});
    button1.text("Button");

    toggle_button1.parent(tab_page_buttons);
    toggle_button1.location({110, 10});
    toggle_button1.text("Toggle");

    flat_button1.parent(tab_page_buttons);
    flat_button1.flat_style(xtd::forms::flat_style::flat);
    flat_button1.location({10, 50});
    flat_button1.text("Flat");

    image_button1.parent(tab_page_buttons);
    image_button1.location({110, 50});
    image_button1.image(button_images::from_name("xtd"));

    light_button1.parent(tab_page_buttons);
    light_button1.location({10, 90});
    light_button1.text("Light");

    switch_button1.parent(tab_page_buttons);
    switch_button1.location({110, 90});
    
    radio_button1.parent(tab_page_buttons);
    radio_button1.auto_size(true);
    radio_button1.checked(true);
    radio_button1.location({10, 130});
    radio_button1.text("Radio 1");
    
    radio_button2.parent(tab_page_buttons);
    radio_button2.auto_size(true);
    radio_button2.location({110, 130});
    radio_button2.text("Radio 2");
    
    check_box1.parent(tab_page_buttons);
    check_box1.auto_size(true);
    check_box1.checked(true);
    check_box1.location({10, 170});
    check_box1.text("Check 1");
    
    check_box2.parent(tab_page_buttons);
    check_box2.auto_size(true);
    check_box2.three_state(true);
    check_box2.location({110, 170});
    check_box2.text("Check 2");
    
    up_down_button1.parent(tab_page_buttons);
    up_down_button1.location({10, 210});

    color_picker1.parent(tab_page_pickers);
    color_picker1.location({10, 10});
    color_picker1.text("Colors...");
    
    font_picker1.parent(tab_page_pickers);
    font_picker1.location({10, 50});
    font_picker1.color(xtd::drawing::system_colors::control_text());

    date_time_picker1.parent(tab_page_pickers);
    date_time_picker1.location({10, 90});

    label1.parent(tab_page_texts);
    label1.auto_size(true);
    label1.location({10, 13});
    label1.text("Simple label text.");

    link_label1.parent(tab_page_texts);
    link_label1.auto_size(true);
    link_label1.location({10, 43});
    link_label1.text("https://gammasoft71.wixsite.com/xtdpro");

    text_box1.parent(tab_page_texts);
    text_box1.location({10, 80});
    text_box1.text("Single line text");
    text_box1.width(390);

    text_box2.parent(tab_page_texts);
    text_box2.location({10, 120});
    text_box2.size({390, 250});
    text_box2.multiline(true);
    text_box2.text("Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultrices diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi. Proin porttitor, orci nec nonummy molestie, enim est eleifend mi, non fermentum diam nisl sit amet erat. Duis semper. Duis arcu massa, scelerisque vitae, consequat in, pretium a, enim. Pellentesque congue. Ut in risus volutpat libero pharetra tempor. Cras vestibulum bibendum augue. Praesent egestas leo in pede. Praesent blandit odio eu enim. Pellentesque sed dui ut augue blandit sodales. Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Aliquam nibh. Mauris ac mauris sed pede pellentesque fermentum. Maecenas adipiscing ante non diam sodales hendrerit.\n\nUt velit mauris, egestas sed, gravida nec, ornare ut, mi. Aenean ut orci vel massa suscipit pulvinar. Nulla sollicitudin. Fusce varius, ligula non tempus aliquam, nunc turpis ullamcorper nibh, in tempus sapien eros vitae ligula. Pellentesque rhoncus nunc et augue. Integer id felis. Curabitur aliquet pellentesque diam. Integer quis metus vitae elit lobortis egestas. Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Morbi vel erat non mauris convallis vehicula. Nulla et sapien. Integer tortor tellus, aliquam faucibus, convallis id, congue eu, quam. Mauris ullamcorper felis vitae erat. Proin feugiat, augue non elementum posuere, metus purus iaculis lectus, et tristique ligula justo vitae magna.\n\nAliquam convallis sollicitudin purus. Praesent aliquam, enim at fermentum mollis, ligula massa adipiscing nisl, ac euismod nibh nisl eu lectus. Fusce vulputate sem at sapien. Vivamus leo. Aliquam euismod libero eu enim. Nulla nec felis sed leo placerat imperdiet. Aenean suscipit nulla in justo. Suspendisse cursus rutrum augue. Nulla tincidunt tincidunt mi. Curabitur iaculis, lorem vel rhoncus faucibus, felis magna fermentum augue, et ultricies lacus lorem varius purus. Curabitur eu amet.\n");

    lcd_label1.parent(tab_page_lcds);
    lcd_label1.auto_size(true);
    lcd_label1.location({10, 10});
    lcd_label1.text("1234567890");

    dot_matrix_display1.parent(tab_page_lcds);
    dot_matrix_display1.height(50);;
    dot_matrix_display1.location({10, 50});
    dot_matrix_display1.set_dots({{3, 0}, {2, 1}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}});

    seven_segment_display1.parent(tab_page_lcds);
    seven_segment_display1.height(50);;
    seven_segment_display1.location({50, 50});
    seven_segment_display1.value(segments::a|segments::b|segments::d|segments::e|segments::g);

    nine_segment_display1.parent(tab_page_lcds);
    nine_segment_display1.height(50);;
    nine_segment_display1.location({90, 50});
    nine_segment_display1.value(segments::a|segments::g|segments::h|segments::i);

    fourteen_segment_display1.parent(tab_page_lcds);
    fourteen_segment_display1.height(50);;
    fourteen_segment_display1.location({130, 50});
    fourteen_segment_display1.value(segments::b|segments::c|segments::f|segments::g1|segments::g2);

    sixteen_segment_display1.parent(tab_page_lcds);
    sixteen_segment_display1.height(50);;
    sixteen_segment_display1.location({170, 50});
    sixteen_segment_display1.value(segments::a1|segments::a2|segments::c|segments::d1|segments::d2|segments::f|segments::g1|segments::g2);

    choice1.parent(tab_page_choices);
    choice1.location({10, 10});
    choice1.items().push_back_range({"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"});
    choice1.selected_item("Light red");
    
    combo_box1.parent(tab_page_choices);
    combo_box1.location({10, 50});
    combo_box1.items().push_back_range({"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"});
    combo_box1.selected_item("Light green");

    domain_up_down1.parent(tab_page_choices);
    domain_up_down1.location({10, 90});
    domain_up_down1.items().push_back_range({"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"});
    domain_up_down1.selected_item("Light blue");

    numeric_up_down1.parent(tab_page_choices);
    numeric_up_down1.location({10, 130});
    numeric_up_down1.value(10);

    list_box1.parent(tab_page_lists);
    list_box1.location({10, 10});
    list_box1.size({250, 150});
    list_box1.items().push_back_range({"Light red", "Light green", "Light blue", "Yellow", "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"});
    list_box1.selected_item("Light red");

    checked_list_box1.parent(tab_page_lists);
    checked_list_box1.location({10, 180});
    checked_list_box1.size({250, 150});
    checked_list_box1.items().push_back_range({{"Light red", true}, "Light green", "Light blue", {"Yellow", true}, "White", "Dark gray", "Light cyan", "Light magenta", "Red", "Green", "Blue", "Brown", "Light gray", "Black", "Cyan", "Magenta"});
    checked_list_box1.selected_item("Light green");
    
    track_bar1.parent(tab_page_progress_and_track_bars);
    track_bar1.location({10, 10});
    track_bar1.maximum(100);
    track_bar1.width(350);
    track_bar1.value_changed += [&] {
      progress_bar1.value(track_bar1.value());
    };
    track_bar1.value(50);
    
    progress_bar1.parent(tab_page_progress_and_track_bars);
    progress_bar1.location({10, 70});
    progress_bar1.maximum(100);
    progress_bar1.width(350);

    h_scroll_bar1.parent(tab_page_scrolls);
    h_scroll_bar1.location({40, 10});
    h_scroll_bar1.width(300);

    v_scroll_bar1.parent(tab_page_scrolls);
    v_scroll_bar1.location({10, 40});
    v_scroll_bar1.height(300);

    loading_indicator1.parent(tab_page_animations);
    loading_indicator1.location({10, 10});
    loading_indicator1.start();
  }
  
private:
  tab_control tab_control_controls;
  tab_page tab_page_buttons;
  tab_page tab_page_pickers;
  tab_page tab_page_texts;
  tab_page tab_page_lcds;
  tab_page tab_page_choices;
  tab_page tab_page_lists;
  tab_page tab_page_progress_and_track_bars;
  tab_page tab_page_scrolls;
  tab_page tab_page_animations;

  button button1;
  toggle_button toggle_button1;
  button flat_button1;
  button image_button1;
  light_button light_button1;
  switch_button switch_button1;
  radio_button radio_button1;
  radio_button radio_button2;
  check_box check_box1;
  check_box check_box2;
  up_down_button up_down_button1;

  color_picker color_picker1;
  font_picker font_picker1;
  date_time_picker date_time_picker1;

  label label1;
  link_label link_label1;
  text_box text_box1;
  text_box text_box2;

  lcd_label lcd_label1;
  dot_matrix_display dot_matrix_display1;
  seven_segment_display seven_segment_display1;
  nine_segment_display nine_segment_display1;
  fourteen_segment_display fourteen_segment_display1;
  sixteen_segment_display sixteen_segment_display1;

  choice choice1;
  combo_box combo_box1;
  domain_up_down domain_up_down1;
  numeric_up_down numeric_up_down1;

  list_box list_box1;
  checked_list_box checked_list_box1;
  
  progress_bar progress_bar1;
  track_bar track_bar1;

  h_scroll_bar h_scroll_bar1;
  v_scroll_bar v_scroll_bar1;

  loading_indicator loading_indicator1;
};

int main() {
  application::enable_dark_mode();
  xtd::forms::application::run(form1());
}
