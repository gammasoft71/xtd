#include <xtd/xtd>

namespace splitter_example {
  class form1 : public form {
  public:
    form1() {
      text("Splitter example");
      client_size({300, 300});
      controls().add_range({panel_fill, splitter_top, panel_top, splitter_right, panel_right, splitter_left, panel_left});
      
      panel_left.dock(dock_style::left);
      panel_left.back_color(drawing::color::light_blue);
      panel_left.width(70);
      
      splitter_left.dock(dock_style::left);
      
      panel_right.dock(dock_style::right);
      panel_right.back_color(drawing::color::light_yellow);
      panel_right.width(70);
      
      splitter_right.dock(dock_style::right);
      
      panel_top.dock(dock_style::top);
      panel_top.back_color(drawing::color::light_pink);
      panel_top.height(150);
      
      splitter_top.dock(dock_style::top);
      
      panel_fill.dock(dock_style::fill);
      panel_fill.back_color(drawing::color::light_green);
    }
    
  private:
    panel panel_left;
    splitter splitter_left;
    panel panel_right;
    splitter splitter_right;
    panel panel_top;
    splitter splitter_top;
    panel panel_fill;
  };
}

auto main() -> int {
  application::run(splitter_example::form1 {});
}
