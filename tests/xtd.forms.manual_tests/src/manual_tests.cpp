#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form_test : public form {
public:
  drawing::size compute_label_size(const label& label) const {
    return drawing::size::round(this->create_graphics().measure_string(label.text(), label.font())) + drawing::size(2 + (label.border_style() == border_style::none ? 0 : 4), 1 + (label.border_style() == border_style::none ? 0 : 4));
  }

  form_test() {
    this->text("xtd.forms.manual_tests");
    this->font(drawing::font("Arial", 34, font_style::bold | font_style::italic, graphics_unit::point));
    this->controls().push_back(this->label1);
    this->controls().push_back(this->label2);

    this->label1.auto_size(true);
    this->label1.location({0, 0});
    this->label1.border_style(forms::border_style::fixed_3d);
    this->label1.back_color(color::dark_green);
    this->label1.text("Hello, World!");
    cdebug << format("label1.size = {}", label1.size()) << endl;

    this->label2.location({0, 62});
    this->label2.border_style(forms::border_style::fixed_3d);
    this->label2.back_color(color::dark_green);
    this->label2.text("Hello, World!");
    this->label2.size(compute_label_size(this->label2));
    cdebug << format("label2.size = {}", label2.size()) << endl;

    /*
    this->paint += [&](const control& sender, paint_event_args& e) {
      drawing::size size = drawing::size::truncate(e.graphics().measure_string(this->label1.text(), this->label1.font()));
      //e.graphics().draw_rectangle(pen(color::red), 0, 60, size.width() + 4, size.height() + 4);
      e.graphics().draw_string(this->label1.text(), this->label1.font(), solid_brush(system_colors::control_text), {{2.0f, 62.0f}, size});
      //cdebug << format("measure_string = {}", size) << endl;
    };
     */
  }
private:
  label label1;
  label label2;
};

int main() {
  application::run(form_test());
}
