#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    this->text("xtd.forms.manual_tests");
    this->show();
    
    this->label.parent(*this);
    this->label.auto_size(true);
    this->label.location({0, 0});
    this->label.font(drawing::font("Arial", 34, font_style::bold | font_style::italic, graphics_unit::point));
    cdebug << format("lsize in points = {}", label.font().size_in_points()) << endl;

    this->label.text("Hello, World!");
    cdebug << format("label.size = {}", label.size()) << endl;
    this->paint += [&](const control& sender, paint_event_args& e) {
      //e.graphics().draw_line(pen(color::spring_green), 4, 0, 4, 300);
      size_f size = e.graphics().measure_string(this->label.text(), this->label.font()) + size_f {5.0f, 0.0f};
      e.graphics().draw_rectangle(pen(color::red), 0.0, 55.0, size.width(), size.height());
      e.graphics().draw_string(this->label.text(), this->label.font(), solid_brush(system_colors::control_text), {{0.0f, 55.0f}, size});
      cdebug << format("measure_string = {}", size) << endl;
    };

  }
private:
  label label;
};

int main() {
  application::run(form1());
}
