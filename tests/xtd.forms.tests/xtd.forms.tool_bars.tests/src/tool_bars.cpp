#include <xtd/forms/application>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/forms/tool_bar>
#include <xtd/forms/tool_bar_images>
#include <xtd/drawing/texts>
#include <xtd/startup>

namespace xtd::forms::tests {
  class tool_bars_form : public form {
    using tool_bar_ptr_t = sptr<forms::tool_bar>;
    using tool_bars_t = list<tool_bar_ptr_t>;
    using tool_bar_button_ptr_t = sptr<tool_bar_button>;
    using tool_bar_items_t = list<tool_bar_button_ptr_t>;
    
  public:
    static auto main() {
      application::run(tool_bars_form());
    }
    
    tool_bars_form() {
      text("Tool_bars tests - system");
      padding(10);
      client_size({1100, 600});
      
      tab_control.parent(*this);
      tab_control.dock(dock_style::fill);
      
      tab_page_top.parent(tab_control);
      tab_page_top.text("Top");
      
      create_tool_bars(tab_page_top, dock_style::top);
      
      style_sheet_choice.parent(*this);
      style_sheet_choice.dock(dock_style::bottom);
      style_sheet_choice.items({"GNOME (dark)", "GNOME (light)", "KDE (dark)", "KDE (light)", "macOS (dark)", "macOS (light)", "Windows (dark)", "Windows (light)", "default"});
      style_sheet_choice.selected_index_changed += [&] {
        application::style_sheet(application::get_style_sheet_from_name(style_sheet_choice.selected_item().value()));
        text(string::format("Tool_bars tests - {}", style_sheet_choice.selected_item().value()));
      };
      style_sheet_choice.selected_item(style_sheets::style_sheet::system_style_sheet().theme().name());
    }
    
  private:
    void create_tool_bars(const control& parent_control, forms::dock_style style) {
      tool_bar_ptr_t tool_bar_ptr;
      tool_bar_button_ptr_t tool_bar_button_ptr;
      
      tool_bar_ptr = xtd::new_sptr<forms::tool_bar>();
      tool_bars.add(tool_bar_ptr);
      tool_bar_ptr->dock(style).parent(parent_control);
      
      tool_bar_ptr = xtd::new_sptr<forms::tool_bar>();
      tool_bars.add(tool_bar_ptr);
      tool_bar_ptr->dock(style).parent(parent_control);
      tool_bar_ptr->image_list().images().add_range({tool_bar_images::file_new(), tool_bar_images::file_open(), tool_bar_images::file_save(), tool_bar_images::file_print(), tool_bar_images::edit_cut(), tool_bar_images::edit_copy(), tool_bar_images::edit_paste(), tool_bar_images::help_about()});
      
      tool_bar_button_ptr = xtd::new_sptr<tool_bar_button>(tool_bar_button::create_push_button(texts::new_(), 0));
      tool_bar_ptr->buttons().add(*tool_bar_button_ptr);
      tool_bar_items.add(tool_bar_button_ptr);
      
      tool_bar_button_ptr = xtd::new_sptr<tool_bar_button>(tool_bar_button::create_push_button(texts::open(), 1));
      tool_bar_ptr->buttons().add(*tool_bar_button_ptr);
      tool_bar_items.add(tool_bar_button_ptr);
      
    }
    
    forms::tab_control tab_control;
    forms::tab_page tab_page_top;
    
    choice style_sheet_choice;
    
    tool_bars_t tool_bars;
    tool_bar_items_t tool_bar_items;
  };
}

startup_(tests::tool_bars_form::main);
