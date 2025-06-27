#include <xtd/forms/application>
#include <xtd/forms/countries>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/list_box>
#include <xtd/forms/picture_box>
#include <xtd/diagnostics/debug>
#include <xtd/drawing/system_colors>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace countries_example {
  class main_form : public form {
  public:
    static auto main() {
      //locale::global(locale {"fr_FR.utf-8"});
      application::run(main_form());
    }
    
    main_form() {
      text("Countries example");
      client_size({600, 500});
      
      countries_list_box.parent(*this);
      countries_list_box.location({10, 10});
      countries_list_box.size({200, 480});
      countries_list_box.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::bottom);
      for (auto country : countries::get_countries())
        countries_list_box.items().push_back({country.name(), country});
      countries_list_box.sorted(true);
      countries_list_box.selected_value_changed += [&] {
        country_flag_picture_box.image(bitmap(as<forms::country>(countries_list_box.selected_item().tag()).flag(), {256, 192}));
        country_flag_squared_picture_box.image(bitmap(as<forms::country>(countries_list_box.selected_item().tag()).flag_squared(), {128, 128}));
        country_emoticon_label.text(as<forms::country>(countries_list_box.selected_item().tag()).emoticon());
        country_code_label.text(string::format("Codes : {} ({}) / {}", as<forms::country>(countries_list_box.selected_item().tag()).alpha_3_code(), as<forms::country>(countries_list_box.selected_item().tag()).alpha_2_code(), as<forms::country>(countries_list_box.selected_item().tag()).numeric_code()));
      };
      countries_list_box.selected_item(countries::belgium().name());
      
      country_panel.parent(*this);
      country_panel.location({220, 10});
      country_panel.size({370, 480});
      country_panel.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::right | anchor_styles::bottom);
      country_panel.border_style(forms::border_style::fixed_3d);
      country_panel.back_color(system_colors::window());
      country_panel.auto_scroll(true);
      
      country_flag_picture_box.parent(country_panel);
      country_flag_picture_box.location({10, 10});
      country_flag_picture_box.size({256, 192});
      
      country_flag_squared_picture_box.parent(country_panel);
      country_flag_squared_picture_box.location({10, 212});
      country_flag_squared_picture_box.size({128, 128});
      
      country_emoticon_label.flat_style(xtd::forms::flat_style::system);
      country_emoticon_label.parent(country_panel);
      country_emoticon_label.font({country_emoticon_label.font(), 64});
      country_emoticon_label.location({10, 350});
      country_emoticon_label.auto_size(true);
      
      country_code_label.parent(country_panel);
      country_code_label.location({10, 445});
      country_code_label.auto_size(true);
    }
    
  private:
    list_box countries_list_box;
    panel country_panel;
    picture_box country_flag_picture_box;
    picture_box country_flag_squared_picture_box;
    label country_emoticon_label;
    label country_code_label;
  };
}

startup_(countries_example::main_form::main);
