#include <xtd/drawing/color_converter>
#include <xtd/forms/application>
#include <xtd/forms/dot_matrix_display>
#include <xtd/forms/form>
#include <xtd/forms/timer>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    dot_matrix_display1.height(250);
    dot_matrix_display1.location({(client_size().width - dot_matrix_display1.width()) / 2, (client_size().height - dot_matrix_display1.height()) / 2});
    dot_matrix_display1.parent(*this);
    dot_matrix_display1.fore_color(color::red);
    dot_matrix_display1.anchor(anchor_styles::top | anchor_styles::bottom);
    
    timer1.interval(300_ms);
    timer1.enabled(true);
    timer1.tick += delegate_ {
      dot_matrix_display1.dot_matrix_style(dot_matrix_styles[(counter / chase.size()) % dot_matrix_styles.size()]);
      dot_matrix_display1.set_dots(chase[counter++ % chase.size()]);
    };
    
    back_color(color_converter::average(color::black, dot_matrix_display1.fore_color(), 0.20));
    text("Dot matrix display example");
    resize += delegate_ {
      dot_matrix_display1.left((client_size().width - dot_matrix_display1.width()) / 2);
    };
  }
  
private:
  int counter = 0;
  list<dot_matrix_display::points_collection> chase = {
    {},
    {{3, 3}},
    {{3, 3}, {2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 4}, {4, 2}, {4, 3}, {4, 4}},
    {{3, 3}, {2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 4}, {4, 2}, {4, 3}, {4, 4}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 1}, {2, 5}, {3, 1}, {3, 5}, {4, 1}, {4, 5}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}},
    {{3, 3}, {2, 2}, {2, 3}, {2, 4}, {3, 2}, {3, 4}, {4, 2}, {4, 3}, {4, 4}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 1}, {2, 5}, {3, 1}, {3, 5}, {4, 1}, {4, 5}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {1, 0}, {1, 6}, {2, 0}, {2, 6}, {3, 0}, {3, 6}, {4, 0}, {4, 6}, {5, 0}, {5, 6}, {6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}},
  };
  dot_matrix_display dot_matrix_display1;
  list<dot_matrix_style> dot_matrix_styles = {
    dot_matrix_style::standard,
    dot_matrix_style::square
  };
  timer timer1;
};

auto main() -> int {
  application::run(form1 {});
}
