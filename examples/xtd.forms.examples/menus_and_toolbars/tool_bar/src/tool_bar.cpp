#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/list_box>
#include <xtd/forms/progress_bar>
#include <xtd/forms/timer>
#include <xtd/forms/tool_bar>
#include <xtd/forms/tool_bar_images>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace tool_bar_example {
  class form1 : public form {
  public:
    form1() {
      text("Toolbar example");
      client_size({820, 500});
      controls().push_back_range({list_box1, tool_bar2, tool_bar1});
      tool_bar(tool_bar1);
      active_control(list_box1);
      
      list_box1.dock(dock_style::fill);
      
      choice1.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      choice1.selected_index(0);
      choice1.selected_value_changed += [&] {
        list_box1.items().push_back(ustring::format("{} selected", choice1.selected_item()));
        list_box1.selected_index(list_box1.items().size() - 1);
      };
      
      progress_bar1.width(150);
      
      progress_timer1.interval_milliseconds(50);
      progress_timer1.start();
      progress_timer1.tick += [&] {
        progress_bar1.value(progress_bar1.value() < progress_bar1.maximum() ? progress_bar1.value() + 1 : progress_bar1.minimum());
      };
      
      tool_bar1.image_list().images().push_back_range({tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save(), tool_bar_images::file_print(), tool_bar_images::edit_cut(), tool_bar_images::edit_copy(), tool_bar_images::edit_paste(), tool_bar_images::help()});
      tool_bar1.buttons().push_back_range({new_tool_bar_button, open_tool_bar_button, save_tool_bar_button, print_tool_bar_button, tool_bar1_separator1, cut_tool_bar_button, copy_tool_bar_button, paste_tool_bar_button, tool_bar1_separator2, choice_tool_bar_button, tool_bar1_separator3, help_tool_bar_button});
      tool_bar1.button_click += {*this, &form1::on_tool_bar_button_click};
      
      tool_bar2.dock(dock_style::bottom);
      tool_bar2.show_text(true);
      tool_bar2.text_align(xtd::forms::tool_bar_text_align::right);
      tool_bar2.image_list().image_size({24, 24});
      tool_bar2.image_list().images().push_back_range({tool_bar_images::from_name("media-playback-start"), tool_bar_images::from_name("media-skip-backward"), tool_bar_images::from_name("media-playback-stop"), tool_bar_images::from_name("media-skip-forward"), tool_bar_images::from_name("media-record"), tool_bar_images::from_name("media-eject")});
      tool_bar2.buttons().push_back_range({play_tool_bar_button, tool_bar2_separator1, skip_backward_tool_bar_button, stop_tool_bar_button, skip_forward_tool_bar_button, tool_bar2_separator2, record_tool_bar_button, tool_bar2_separator3, progress_tool_bar_button, tool_bar2_separator4, eject_tool_bar_button});
      tool_bar2.button_click += {*this, &form1::on_tool_bar_button_click};
      
      record_tool_bar_button.enabled(false);
    }
    
  private:
    void on_tool_bar_button_click(object& sender, const tool_bar_button_click_event_args& e) {
      if (e.button().style() == tool_bar_button_style::toggle_button)
        list_box1.items().push_back(ustring::format("Button {} clicked, pushed = {}", e.button().text(), e.button().pushed()));
      else
        list_box1.items().push_back(ustring::format("Button {} clicked", e.button().text()));
      list_box1.selected_index(list_box1.items().size() - 1);
    }
    
    void on_menu_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("Menu item {} clicked", as<menu_item>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
    }
    
    list_box list_box1;
    
    menu_item context_help_context_menu_item {"Help context", {*this, &form1::on_menu_click}};
    menu_item context_help_index_menu_item {"Help index", {*this, &form1::on_menu_click}};
    menu_item context_help_search_menu_item {"Help search", {*this, &form1::on_menu_click}};
    menu_item context_separator_menu_item {"-"};
    menu_item context_about_menu_item {texts::about(), {*this, &form1::on_menu_click}};
    forms::context_menu context_menu1 {context_help_context_menu_item, context_help_index_menu_item, context_help_search_menu_item, context_separator_menu_item, context_about_menu_item};
    
    forms::tool_bar tool_bar1;
    choice choice1;
    tool_bar_button new_tool_bar_button = tool_bar_button::create_push_button(texts::new_(), 0);
    tool_bar_button open_tool_bar_button = tool_bar_button::create_push_button(texts::open(), 1);
    tool_bar_button save_tool_bar_button = tool_bar_button::create_push_button(texts::save(), 2);
    tool_bar_button print_tool_bar_button = tool_bar_button::create_push_button(texts::print(), 3);
    tool_bar_button tool_bar1_separator1 = tool_bar_button::create_separator();
    tool_bar_button cut_tool_bar_button = tool_bar_button::create_push_button(texts::cut(), 4);
    tool_bar_button copy_tool_bar_button = tool_bar_button::create_push_button(texts::copy(), 5);
    tool_bar_button paste_tool_bar_button = tool_bar_button::create_push_button(texts::paste(), 6);
    tool_bar_button tool_bar1_separator2 = tool_bar_button::create_separator();
    tool_bar_button choice_tool_bar_button = tool_bar_button::create_control("Items", choice1);
    tool_bar_button tool_bar1_separator3 = tool_bar_button::create_stretchable_separator();
    tool_bar_button help_tool_bar_button = tool_bar_button::create_drop_down_button(texts::help(), 7, context_menu1);
    
    forms::tool_bar tool_bar2;
    progress_bar progress_bar1;
    timer progress_timer1;
    tool_bar_button play_tool_bar_button = tool_bar_button::create_push_button("&Play", 0);
    tool_bar_button tool_bar2_separator1 = tool_bar_button::create_separator();
    tool_bar_button skip_backward_tool_bar_button = tool_bar_button::create_push_button("Skip &Backward", 1);
    tool_bar_button stop_tool_bar_button = tool_bar_button::create_push_button("S&top", 2);
    tool_bar_button skip_forward_tool_bar_button = tool_bar_button::create_push_button("Skip &Forward", 3);
    tool_bar_button tool_bar2_separator2 = tool_bar_button::create_separator();
    tool_bar_button record_tool_bar_button = tool_bar_button::create_push_button("&Record", 4);
    tool_bar_button tool_bar2_separator3 = tool_bar_button::create_separator();
    tool_bar_button progress_tool_bar_button = tool_bar_button::create_control(progress_bar1);
    tool_bar_button tool_bar2_separator4 = tool_bar_button::create_stretchable_separator();
    tool_bar_button eject_tool_bar_button = tool_bar_button::create_toggle_button("&Eject", 5);
  };
}

auto main()->int {
  application::run(tool_bar_example::form1 {});
}
