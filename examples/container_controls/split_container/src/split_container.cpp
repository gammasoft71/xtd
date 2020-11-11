#include <xtd/xtd.forms>

using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Split container example");
    client_size({300, 300});
    
    split_container_left.parent(*this);
    split_container_left.dock(dock_style::fill);
    split_container_left.panel1().back_color(color::light_blue);
    split_container_left.splitter_distance(70);
    
    split_container_right.dock(dock_style::fill);
    split_container_right.panel2().back_color(color::light_yellow);
    split_container_right.parent(split_container_left.panel2());
    split_container_right.splitter_distance(160);
    
    split_container_center.dock(dock_style::fill);
    split_container_center.orientation(xtd::forms::orientation::horzontal);
    split_container_center.panel1().back_color(color::pink);
    split_container_center.panel2().back_color(color::light_green);
    split_container_center.parent(split_container_right.panel1());
    split_container_center.splitter_distance(150);
  }
  
private:
  split_container split_container_left;
  split_container split_container_right;
  split_container split_container_center;
};

int main() {
  application::run(form1());
}
