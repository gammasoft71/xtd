#include <xtd/drawing/colors>
#include <xtd/drawing/pens>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/tab_control>
#include <xtd/forms/tab_page>
#include <xtd/cdebug>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Colored Tab pages example");
    controls().push_back(colored_tab_control);
    size({600, 450});
    
    color_image_list.image_size({16, 16});
    for(auto color : {colors::light_pink(), colors::light_green(), colors::light_blue(), colors::light_yellow()}) {
      color_image_list.images().push_back(image_from_color(color_image_list.image_size(), color));
      
      auto colored_tab_page = make_unique<forms::tab_page>();
      colored_tab_page->image_index(colored_tab_pages.size()).parent(colored_tab_control).text(color.name()).back_color(color);
      colored_tab_pages.push_back(std::move(colored_tab_page));
    };
    
    colored_tab_control.image_list(color_image_list);
    colored_tab_control.dock(dock_style::fill);
    colored_tab_control.alignment(tab_alignment::bottom);
  }
  
private:
  auto image_from_color(const drawing::size& size, const color& color)->image {
    auto colored_bitmap = bitmap {size};
    auto g = graphics::from_image(colored_bitmap);
    g.fill_ellipse(solid_brush {color}, 0, 0, colored_bitmap.width(), colored_bitmap.height());
    g.draw_ellipse(pens::black(), 0, 0, colored_bitmap.width() - 1, colored_bitmap.height() - 1);
    return colored_bitmap;
  }
  
  image_list color_image_list;
  tab_control colored_tab_control;
  vector<unique_ptr<tab_page>> colored_tab_pages;
};

auto main() -> int {
  application::run(form1 {});
}
