#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace font_family_example {
  class form1 : public form {
  public:
    form1() {
      text("Font families example");
      start_position(form_start_position::manual);
      location({300, 150});
      client_size({400, 500});
      
      label_font_famlies_count.parent(*this);
      label_font_famlies_count.auto_size(true);
      label_font_famlies_count.location({20, 20});
      
      list_box_font_families.parent(*this);
      list_box_font_families.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      list_box_font_families.bounds({20, 60, 360, 420});
      
      std::vector<drawing::font_family> font_families = drawing::font_family::families();
      label_font_famlies_count.text(strings::format("There are {0} font families :", font_families.size()));
      for (drawing::font_family fontFamily : font_families)
        list_box_font_families.items().push_back(fontFamily.name());
    }
    
  private:
    label label_font_famlies_count;
    list_box list_box_font_families;
  };
}

int main() {
  application::run(font_family_example::form1());
}
