#include <xtd/forms/application>
#include <xtd/forms/loading_indicator>
#include <xtd/forms/form>
#include <xtd/forms/list_box>
#include <xtd/forms/panel>
#include <xtd/drawing/system_colors>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace loading_indicator_example {
  class form1 : public form {
  public:
    form1() {
      text("Loading indicator example");
      start_position(form_start_position::manual);
      location({200, 200});
      client_size({360, 240});
      
      list_box1.parent(*this);
      list_box1.bounds({20, 20, 150, 200});
      list_box1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
      list_box1.items().push_back_range({{"Standard", loading_indicator_style::standard}, {"System", loading_indicator_style::system}, {"Bar", loading_indicator_style::bar}, {"Circle bars", loading_indicator_style::circle_bars}, {"Circle blinks", loading_indicator_style::circle_blinks}, {"Five lines", loading_indicator_style::five_lines}, {"Five lines center", loading_indicator_style::five_lines_center}, {"Five lines chronological", loading_indicator_style::five_lines_chronological}, {"Five lines pulse", loading_indicator_style::five_lines_pulse}, {"Five lines wave", loading_indicator_style::five_lines_wave}, {"Pulse", loading_indicator_style::pulse}, {"Pulse outline", loading_indicator_style::pulse_outline}, {"Three balls", loading_indicator_style::three_balls}, {"Three balls bouncing", loading_indicator_style::three_balls_bouncing}, {"Three balls rotation", loading_indicator_style::three_balls_rotation}});
      list_box1.selected_index_changed += [&] {
        loading_indicator1.loading_indicator_style(any_cast<forms::loading_indicator_style>(list_box1.selected_item().tag()));
      };
      list_box1.selected_item("Standard");
      
      panel1.parent(*this);
      panel1.border_style(border_style::fixed_3d);
      panel1.back_color(drawing::system_colors::window());
      panel1.bounds({190, 20, 150, 200});
      panel1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      panel1.click += loading_indicator1.click += [&] {
        loading_indicator1.running(!loading_indicator1.running());
      };
      
      
      loading_indicator1.parent(panel1);
      loading_indicator1.location({59, 84});
      loading_indicator1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      loading_indicator1.running(true);
    }
    
  private:
    list_box list_box1;
    panel panel1;
    loading_indicator loading_indicator1;
  };
}

auto main()->int {
  application::run(loading_indicator_example::form1 {});
}
