#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void on_menu_click(component& sender, const event_args& e) {
  cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
}

namespace xtd {
  namespace forms {
    enum class table_layout_panel_grow_style {
      fixed_size = 0,
      add_rows = 1,
      add_columns = 2
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, table_layout_panel_grow_style value) {return os << to_string(value, {{table_layout_panel_grow_style::fixed_size, "fixed_size"}, {table_layout_panel_grow_style::add_rows, "add_rows"}, {table_layout_panel_grow_style::add_columns, "add_columns"}});}
    inline std::wostream& operator<<(std::wostream& os, table_layout_panel_grow_style value) {return os << to_string(value, {{table_layout_panel_grow_style::fixed_size, L"fixed_size"}, {table_layout_panel_grow_style::add_rows, L"add_rows"}, {table_layout_panel_grow_style::add_columns, L"add_columns"}});}
    /// @endcond

    class table_layout_panel : public xtd::forms::panel {
    public:
      table_layout_panel() {
        
      }
      
      virtual int column_count() const {return row_count_;}
      virtual table_layout_panel& column_count(int column_count) {
        if (column_count_ != column_count) {
          column_count_ = column_count;
          perform_layout();
        }
        return *this;
      }
      
      virtual int row_count() const {return row_count_;}
      virtual table_layout_panel& row_count(int row_count) {
        if (row_count_ != row_count) {
          row_count_ = row_count;
          perform_layout();
        }
        return *this;
      }
      
      virtual xtd::forms::border_style cell_border_style() const {return cell_border_style_;}
      virtual table_layout_panel& cell_border_style(xtd::forms::border_style cell_border_style) {
        if (cell_border_style_ != cell_border_style) {
          cell_border_style_ = cell_border_style;
          perform_layout();
        }
        return *this;
      }

    private:
      xtd::forms::border_style cell_border_style_ = xtd::forms::border_style::none;
      int column_count_ = 0;
      int row_count_ = 0;
      xtd::forms::table_layout_panel_grow_style grow_style_ = xtd::forms::table_layout_panel_grow_style::add_rows;
    };
  }
}

int main() {
  /*
  main_menu menu;
  menu.menu_items().push_back("&File");
  menu.menu_items().push_back("&Edit");
  menu.menu_items().push_back("&View");
  menu.menu_items().push_back("&Window");
  menu.menu_items().push_back("&Help");
   */

  form form_main;
  form_main.text("Manual tests");
  //form_main.menu(menu);
  form_main.menu(forms::main_menu::create_standard_items([&](component& sender, const event_args& e) {
    cdebug << format("Clik on menu item : {}", static_cast<menu_item&>(sender).text()) << endl;
  }));
  //form_main.menu(nullptr);
  
  /*
  table_layout_panel table_layout_panel;
  table_layout_panel.parent(form_main);
  table_layout_panel.dock(dock_style::fill);
   */
  
  
  form_main.client_size({300, 300});
  form_main.padding(10);
  
  panel panel_left;
  panel_left.dock(dock_style::left);
  panel_left.back_color(color::light_green);
  panel_left.width(150);

  form_main.controls().push_back_range({panel_left});

  button button_left1;
  button_left1.parent(panel_left);
  button_left1.location({50, 100});
  //button_left1.location({50, -5});
  button_left1.anchor(anchor_styles::left|anchor_styles::bottom);
  //button_left1.parent().value().get().size_changed += [&] {
  //  cdebug << format("new size = {}", button_left1.parent().value().get().size()) << endl;
  //};
  

  application::enable_menu_images();
  application::run(form_main);
}
