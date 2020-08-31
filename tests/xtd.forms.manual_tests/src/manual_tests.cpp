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

namespace xtd {
  namespace forms {
      
    class theme_image : public theme_base {
    public:
      using theme_image_collection = std::vector<theme_image>;

      static std::vector<std::string> contexts();
      static std::map<std::string, std::vector<std::string>> context_names();
      static std::vector<std::string> names();
      static std::vector<std::string> names(const std::string& context) {return context_names()[context];}
      static std::vector<xtd::drawing::size> sizes();
      static theme_image_collection themes();
    };
  }
}

int main() {
  /*
  theme_color::current_theme(theme_color("frozen", xtd::forms::theme_style::light, {[](xtd::forms::known_themed_color color)->xtd::drawing::color {
    switch (color) {
      case known_themed_color::accent: return color::white;
      case known_themed_color::accent_text: return color::dark_gray;
      case known_themed_color::active_border: return color::dark_gray;
      case known_themed_color::active_caption: return color::alice_blue;
      case known_themed_color::active_caption_text: return color::dark_gray;
      case known_themed_color::app_workspace: return color::alice_blue;
      case known_themed_color::button_face: return color::white;
      case known_themed_color::button_highlight: return color::white;
      case known_themed_color::button_shadow: return color::light_gray;
      case known_themed_color::control: return color::alice_blue;
      case known_themed_color::control_dark: return color::dark_gray;
      case known_themed_color::control_dark_dark: return color::dark_gray;
      case known_themed_color::control_light: return color::white;
      case known_themed_color::control_light_light: return color::white;
      case known_themed_color::control_text: return color::dark_gray;
      case known_themed_color::desktop: return color::alice_blue;
      case known_themed_color::gradient_active_caption: return color::alice_blue;
      case known_themed_color::gradient_inactive_caption: return color::alice_blue;
      case known_themed_color::gray_text: return color::gray;
      case known_themed_color::highlight: return system_colors::highlight();
      case known_themed_color::highlight_text: return system_colors::highlight_text();
      case known_themed_color::hot_track: return system_colors::hot_track();
      case known_themed_color::inactive_border: return color::dark_gray;
      case known_themed_color::inactive_caption: return color::alice_blue;
      case known_themed_color::inactive_caption_text: return color::dark_gray;
      case known_themed_color::info: return system_colors::info();
      case known_themed_color::info_text: return system_colors::info_text();
      case known_themed_color::menu: return color::alice_blue;;
      case known_themed_color::menu_text: return color::dark_gray;
      case known_themed_color::menu_bar: return color::alice_blue;;
      case known_themed_color::menu_highlight: return system_colors::menu_highlight();
      case known_themed_color::scroll_bar: return color::alice_blue;
      case known_themed_color::text_box: return color::white;
      case known_themed_color::text_box_text: return color::dark_gray;
      case known_themed_color::window: return color::white;
      case known_themed_color::window_frame: return color::dark_gray;
      case known_themed_color::window_text: return color::dark_gray;
      default: throw std::invalid_argument("unknown know_color");
    }
  }}));
  */
  
  theme::current_theme("kde");
  
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

  /*
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
   */

  link_label link_label1;
  link_label1.location({10, 10});
  link_label1.auto_size(true);
  link_label1.parent(form_main);
  link_label1.text("Gammasoft present xtd_forms examples\nNext line...");

  button button1;
  //button1.enabled(false);
  button1.text("&Click me");
  button1.location({10, 50});
  button1.parent(form_main);
  //button1.fore_color(xtd::drawing::system_colors::accent());
  
  button button2;
  //button2.flat_style(xtd::forms::flat_style::system);
  //button2.enabled(false);
  button2.text("Click me");
  button2.location({100, 50});
  button2.parent(form_main);
  //button2.fore_color(xtd::drawing::system_colors::accent());

  text_box text_box1;
  text_box1.location({10, 90});
  text_box1.parent(form_main);
  text_box1.text("Text box line");
  
  picture_box picture_box1;
  picture_box1.location({10, 120});
  picture_box1.parent(form_main);
  picture_box1.image(system_images::from_name("folder"));

  //form_main.back_color(drawing::color::red);

  application::run(form_main);
}
