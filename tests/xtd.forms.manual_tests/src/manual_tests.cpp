#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::windows::forms;

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
      //xtd::forms::table_layout_panel_grow_style grow_style_ = xtd::forms::table_layout_panel_grow_style::add_rows;
    };
  }
}

class manual_test_form : public form {
public:
  static void main() {
    application::run(manual_test_form());
  }
  
  manual_test_form() {
    text("Manual tests");

    button1.parent(*this);
    button1.location({10, 10});
    button1.text("button1");
    
    button2.parent(*this);
    button2.location({120, 10});
    button2.text("button2");

    button3.parent(*this);
    button3.location({10, 50});
    button3.text("button3");
    button3.flat_style(xtd::forms::flat_style::flat);
    
    button4.parent(*this);
    button4.location({120, 50});
    button4.text("button4");
    button4.flat_style(xtd::forms::flat_style::popup);

    /*
     form_main.client_size({300, 300});
     table_layout_panel table_layout_panel;
     table_layout_panel.parent(form_main);
     table_layout_panel.dock(dock_style::fill);
     */
  }
  
private:
  button button1;
  button button2;
  button button3;
  button button4;
};

startup_(manual_test_form);
