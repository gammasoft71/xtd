#include <xtd/xtd>

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
      active_control(list_box1);
      
      list_box1.dock(dock_style::fill);
      
      tool_bar1.image_list().images().push_back_range({tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save(), tool_bar_images::file_print(), tool_bar_images::edit_cut(), tool_bar_images::edit_copy(), tool_bar_images::edit_paste(), tool_bar_images::help_about()});
      tool_bar1.buttons().push_back_range({new_tool_bar_button, open_tool_bar_button, save_tool_bar_button, print_tool_bar_button, tool_bar1_separator1, cut_tool_bar_button, copy_tool_bar_button, paste_tool_bar_button, tool_bar1_separator2, about_tool_bar_button});
      
      tool_bar2.appearnce(xtd::forms::tool_bar_appearance::flat);
      tool_bar2.dock(dock_style::bottom);
      tool_bar2.show_text(true);
      tool_bar2.text_align(xtd::forms::tool_bar_text_align::right);
      tool_bar2.image_list().image_size({24, 24});
      tool_bar2.image_list().images().push_back_range({tool_bar_images::from_name("media-playback-start"), tool_bar_images::from_name("media-skip-backward"), tool_bar_images::from_name("media-playback-stop"), tool_bar_images::from_name("media-skip-forward"), tool_bar_images::from_name("media-record"), tool_bar_images::from_name("media-eject")});
      tool_bar2.buttons().push_back_range({play_tool_bar_button, tool_bar2_separator1, skip_backward_tool_bar_button, stop_tool_bar_button, skip_forward_tool_bar_button, tool_bar2_separator2, record_tool_bar_button, tool_bar2_separator3, eject_tool_bar_button});
      
      record_tool_bar_button.enabled(false);
    }
    
  private:
    void on_tool_bar_item_click(object& sender, const event_args& e) {
      list_box1.items().push_back(ustring::format("{} clicked", as<tool_bar_button>(sender).text()));
      list_box1.selected_index(list_box1.items().size() - 1);
    }
    
    list_box list_box1;
    forms::tool_bar tool_bar1;
    tool_bar_button new_tool_bar_button {system_texts::new_(), 0, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button open_tool_bar_button {system_texts::open(), 1, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button save_tool_bar_button {system_texts::save(), 2, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button print_tool_bar_button {system_texts::print(), 3, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_separator tool_bar1_separator1;
    tool_bar_button cut_tool_bar_button {system_texts::cut(), 4, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button copy_tool_bar_button {system_texts::copy(), 5, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button paste_tool_bar_button {system_texts::paste(), 6, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_stretchable_separator tool_bar1_separator2;
    tool_bar_button about_tool_bar_button {system_texts::about(), 7, {*this, &form1::on_tool_bar_item_click}};
    
    forms::tool_bar tool_bar2;
    tool_bar_button play_tool_bar_button {"&Play", 0, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_separator tool_bar2_separator1;
    tool_bar_button skip_backward_tool_bar_button {"Skip &Backward", 1, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button stop_tool_bar_button {"S&top", 2, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_button skip_forward_tool_bar_button {"Skip &Forward", 3, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_separator tool_bar2_separator2;
    tool_bar_button record_tool_bar_button {"&Record", 4, {*this, &form1::on_tool_bar_item_click}};
    tool_bar_stretchable_separator tool_bar2_separator3;
    tool_bar_button eject_tool_bar_button {"&Eject", 5, {*this, &form1::on_tool_bar_item_click}};
  };
}

int main() {
  application::run(examples::form1());
}
