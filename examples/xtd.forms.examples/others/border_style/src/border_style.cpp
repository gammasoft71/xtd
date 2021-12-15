#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    static void main() {
      application::run(form1());
    }
    
    form1() {
      text("Border style example");
      client_size({700, 170 + as<int>(20 + bordered_labels.size() / 4 * 70)});
      controls().push_back_range({colored_panel, control_panel});
      maximum_client_size(client_size());
      minimum_client_size(client_size());

      colored_panel.border_style(border_style::fixed_3d);
      colored_panel.controls().push_back_range(bordered_labels);
      colored_panel.dock(dock_style::fill);

      for (auto index = 0UL; index < bordered_labels.size(); ++index) {
        bordered_labels[index].border_style(border_styles[index]);
        bordered_labels[index].bounds(rectangle(as<int>(20 + index % 4 * 170), as<int>(20 + index / 4 * 70), 150, 50));
        bordered_labels[index].text(convert::to_string(border_styles[index]));
        bordered_labels[index].text_align(content_alignment::middle_center);
      }

      control_panel.border_style(border_style::fixed_3d);
      control_panel.controls().push_back_range({choose_color_label, colors_chooser});
      control_panel.dock(dock_style::bottom);

      choose_color_label.auto_size(true);
      choose_color_label.location({20, 37});
      choose_color_label.text("Choose color");

      for (auto color : colors::get_colors())
        colors_chooser.items().push_back({color.name(), color});
      colors_chooser.items()[0] = {back_color().name(), back_color()}; // Replace transparent color by control color.
      colors_chooser.bounds({120, 35, 220, colors_chooser.default_size().height()});
      colors_chooser.selected_index(0);

      colors_chooser.selected_index_changed += [&] {
        auto color = as<drawing::color>(colors_chooser.selected_item().tag());
        colored_panel.back_color(color);
        colored_panel.fore_color(color.is_dark() ? control_paint::light(color, 2.0/3) : control_paint::dark(color, 2.0/3));
      };
    }
    
  private:
    inline static const vector<border_style> border_styles {border_style::none, border_style::fixed_single, border_style::thin_sunken, border_style::thin_raised, border_style::bevel_sunken, border_style::bevel_raised, border_style::etched, border_style::bump, border_style::themed, border_style::rounded_single, border_style::dot_single, border_style::dash_single, border_style::dash_dot_single, border_style::dash_dot_dot_single, border_style::fixed_double};
    panel colored_panel;
    vector<label> bordered_labels {border_styles.size()};
    panel control_panel;
    label choose_color_label;
    choice colors_chooser;
  };
}

startup_(examples::form1);
