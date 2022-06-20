#include <xtd/xtd.forms.h>

using namespace xtd;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Toolbar example");
      client_size({820, 500});
      
      controls().push_back_range({list_box1, tool_bar2, tool_bar1});
      tool_bar(tool_bar1);
      
      list_box1.dock(dock_style::fill);
      
      choice1.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      choice1.selected_index(0);
      choice1.selected_value_changed += [&] {
        list_box1.items().push_back(ustring::format("Choice item {} selected", choice1.selected_item()));
        list_box1.selected_index(list_box1.items().size() - 1);
      };
      
      choice2.items().push_back_range({"Item1", "Item2", "Item3", "Item4", "Item5", "Item6", "Item7", "Item8", "Item9", "Item10"});
      choice2.selected_index(0);
      choice2.selected_value_changed += [&] {
        list_box1.items().push_back(ustring::format("Choice item {} clicked", choice2.selected_item()));
        list_box1.selected_index(list_box1.items().size() - 1);
      };
      
      //tool_bar1.appearance(xtd::forms::tool_bar_appearance::system);
      tool_bar1.dock(dock_style::top);
      tool_bar1.appearance(xtd::forms::tool_bar_appearance::flat);
      tool_bar1.show_text(true);
      //tool_bar1.show_icon(false);
      tool_bar1.text_align(xtd::forms::tool_bar_text_align::underneath);
      tool_bar1.show_tool_tips(true);
      
      tool_bar1.image_list().image_size({24, 24});
      tool_bar1.image_list().images().push_back_range({tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save(), tool_bar_images::file_print(), tool_bar_images::edit_cut(), tool_bar_images::edit_copy(), tool_bar_images::edit_paste(), tool_bar_images::help()});
      tool_bar1.buttons().push_back_range({new_tool_bar_button, open_tool_bar_button, save_tool_bar_button, print_tool_bar_button, tool_bar1_separator1, cut_tool_bar_button, copy_tool_bar_button, paste_tool_bar_button, tool_bar1_separator2, choice_tool_bar_button, tool_bar1_separator3, help_tool_bar_button});
      tool_bar1.button_click += {*this, &form1::on_tool_bar_button_click};
      
      tool_bar2.dock(dock_style::bottom);
      tool_bar2.appearance(xtd::forms::tool_bar_appearance::flat);
      tool_bar2.show_text(true);
      //tool_bar2.show_icon(false);
      //tool_bar2.text_align(xtd::forms::tool_bar_text_align::right);
      
      tool_bar2.image_list().image_size({24, 24});
      tool_bar2.image_list().images().push_back_range({tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save(), tool_bar_images::file_print(), tool_bar_images::edit_cut(), tool_bar_images::edit_copy(), tool_bar_images::edit_paste(), tool_bar_images::help()});
      tool_bar2.buttons().push_back_range({new_tool_bar_button2, open_tool_bar_button2, save_tool_bar_button2, print_tool_bar_button2, tool_bar2_separator1, cut_tool_bar_button2, copy_tool_bar_button2, paste_tool_bar_button2, tool_bar2_separator2, choice_tool_bar_button2, tool_bar2_separator3, help_tool_bar_button2});
      tool_bar2.button_click += {*this, &form1::on_tool_bar_button_click};
    }
    
  private:
    void on_tool_bar_button_click(object& sender, const tool_bar_button_click_event_args& e) {
      if (e.button().style() == tool_bar_button_style::toggle_button)
        list_box1.items().push_back(ustring::format("Tool bar button {} clicked, pushed = {}", e.button().text(), e.button().pushed()));
      else
        list_box1.items().push_back(ustring::format("Tool bar button {} clicked", e.button().text()));
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
    menu_item context_about_menu_item {system_texts::about(), {*this, &form1::on_menu_click}};
    forms::context_menu context_menu1 {context_help_context_menu_item, context_help_index_menu_item, context_help_search_menu_item, context_separator_menu_item, context_about_menu_item};
    
    forms::tool_bar tool_bar1;
    choice choice1;
    tool_bar_button new_tool_bar_button = tool_bar_button::create_push_button(system_texts::new_(), 0);
    tool_bar_button open_tool_bar_button = tool_bar_button::create_push_button(system_texts::open(), 1);
    tool_bar_button save_tool_bar_button = tool_bar_button::create_push_button(system_texts::save(), 2);
    tool_bar_button print_tool_bar_button = tool_bar_button::create_push_button(system_texts::print(), 3);
    tool_bar_button tool_bar1_separator1 = tool_bar_button::create_separator();
    tool_bar_button cut_tool_bar_button = tool_bar_button::create_push_button(system_texts::cut(), 4);
    tool_bar_button copy_tool_bar_button = tool_bar_button::create_push_button(system_texts::copy(), 5);
    tool_bar_button paste_tool_bar_button = tool_bar_button::create_push_button(system_texts::paste(), 6);
    tool_bar_button tool_bar1_separator2 = tool_bar_button::create_separator();
    tool_bar_button choice_tool_bar_button = tool_bar_button::create_control("Items", choice1);
    tool_bar_button tool_bar1_separator3 = tool_bar_button::create_stretchable_separator();
    tool_bar_button help_tool_bar_button = tool_bar_button::create_drop_down_button(system_texts::help(), 7, context_menu1);
    
    menu_item context_help_context_menu_item2 {"Help context", {*this, &form1::on_menu_click}};
    menu_item context_help_index_menu_item2 {"Help index", {*this, &form1::on_menu_click}};
    menu_item context_help_search_menu_item2 {"Help search", {*this, &form1::on_menu_click}};
    menu_item context_separator_menu_item2 {"-"};
    menu_item context_about_menu_item2 {system_texts::about(), {*this, &form1::on_menu_click}};
    forms::context_menu context_menu2 {context_help_context_menu_item2, context_help_index_menu_item2, context_help_search_menu_item2, context_separator_menu_item2, context_about_menu_item2};
    
    forms::tool_bar tool_bar2;
    choice choice2;
    tool_bar_button new_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::new_(), 0);
    tool_bar_button open_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::open(), 1);
    tool_bar_button save_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::save(), 2);
    tool_bar_button print_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::print(), 3);
    tool_bar_button tool_bar2_separator1 = tool_bar_button::create_separator();
    tool_bar_button cut_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::cut(), 4);
    tool_bar_button copy_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::copy(), 5);
    tool_bar_button paste_tool_bar_button2 = tool_bar_button::create_push_button(system_texts::paste(), 6);
    tool_bar_button tool_bar2_separator2 = tool_bar_button::create_separator();
    tool_bar_button choice_tool_bar_button2 = tool_bar_button::create_control("Items", choice2);
    tool_bar_button tool_bar2_separator3 = tool_bar_button::create_stretchable_separator();
    tool_bar_button help_tool_bar_button2 = tool_bar_button::create_drop_down_button(system_texts::help(), 7, context_menu2);
  };
  
  class form2 : public form {
  public:
    form2() {
      text("Message notifier example");
      client_size({350, 200});
      start_position(form_start_position::center_screen);
      btn.parent(*this)
      .text("notify")
      .size({200, 35})
      .click += [&] {
        notifier.reset();
        notifier.notifier_style(notifier_style::standard);
        notifier.title("This is a notification title");
        notifier.message("Where this is the notification message");
        notifier.icon(xtd::drawing::system_icons::xtd_logo());
        //notifier.notifier_icon(message_notifier_icon::information);
        notifier.buttons(message_notifier_buttons::yes_no_cancel);
        notifier.close_timeout_enabled(true);
        notifier.close_timeout_interval(std::chrono::seconds(2) + std::chrono::milliseconds(1000));
        
        notifier.notifier_closed += [&](object&, const notifier_closed_event_args & e) {
          diagnostics::debug::write_line("notifier closed => {}", e.notifier_result());
          //if (e.notifier_result() == notifier_result::ok) // or: if (notifier.notifier_result() == notifier_result::ok)
        };
        notifier.show();
      };
      
    }
    
  private:
    button btn;
    message_notifier notifier;
  };
}

int main() {
  application::run(examples::form2());
}
