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

namespace xtd {
  namespace forms {
    class link_label : public label {
    public:
      class link {
      public:
        link() = default;
      };
      using link_collection  = xtd::forms::layout::arranged_element_collection<xtd::forms::link_label::link>;
      link_label() {
      }
      
    protected:
      void on_paint(paint_event_args& e) override {
        label::on_paint(e);
        //e.graphics().clear(back_color());
        //e.graphics().draw_string(text_, {font(), xtd::drawing::font_style::underline}, xtd::drawing::brushes::blue(), 0, 0, string_format());
      }
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

    /*
     form_main.client_size({300, 300});
     table_layout_panel table_layout_panel;
     table_layout_panel.parent(form_main);
     table_layout_panel.dock(dock_style::fill);
     */
    
    
    /*
     link_label link_label1;
     link_label1.location({10, 10});
     link_label1.auto_size(true);
     link_label1.parent(form_main);
     link_label1.text("Gammasoft present xtd_forms examples\nNext line...");
     */
    
  }
};

startup_(manual_test_form);
