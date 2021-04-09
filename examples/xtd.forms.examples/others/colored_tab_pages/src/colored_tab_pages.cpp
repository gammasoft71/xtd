#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Colored Tab pages example");
    controls().push_back(tab_control_colored);
    size({600, 450});
    
    image_list_.image_size({16, 16});
    for_each(colors.begin(), colors.end(), [&](auto color) {
      auto bitmap = drawing::bitmap(image_list_.image_size());
      auto graphics = drawing::graphics::from_image(bitmap);
      graphics.fill_ellipse(solid_brush(color), 0, 0, bitmap.width(), bitmap.height());
      graphics.draw_ellipse(pens::black(), 0, 0, bitmap.width() - 1, bitmap.height() - 1);
      image_list_.images().push_back(bitmap);

      auto tab_page = control::create<forms::tab_page>(tab_control_colored, color.name(), drawing::point::empty, drawing::size::empty, color);
      tab_page->image_index(tab_pages.size());
      tab_pages.push_back(move(tab_page));
    });
    
    tab_control_colored.image_list(image_list_);
    tab_control_colored.dock(dock_style::fill);
    tab_control_colored.alignment(tab_alignment::bottom);
  }
  
private:
  vector<color> colors = {colors::light_pink(), colors::light_green(), colors::light_blue(), colors::light_yellow()};
  image_list image_list_;
  tab_control tab_control_colored;
  vector<shared_ptr<tab_page>> tab_pages;
};

int main() {
  application::run(form1());
}
