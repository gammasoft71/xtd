#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form_lcd_label : public form {
  public:
    form_lcd_label() {
      auto_scroll(true);
      client_size({400, 200});
      choice_lcd_style.location({10, 10});
      choice_lcd_style.items().push_back_range({{"Seven segment display", lcd_style::seven_segment_display}, {"Nine segment display", lcd_style::nine_segment_display}, {"Fourteen segment display", lcd_style::fourteen_segment_display}, {"Sixteen segment display", lcd_style::sixteen_segment_display}, {"Dot matrix display", lcd_style::dot_matrix_display}});
      choice_lcd_style.selected_value_changed += [this] {
        label.text("");
        label.lcd_style(std::any_cast<lcd_style>(choice_lcd_style.selected_item().tag()));
        label.text(label.valid_characters());
      };
      choice_lcd_style.selected_index(0);

      choice_segment_style.location({140, 10});
      choice_segment_style.items().push_back_range({{"Standard", segment_style::standard}, {"Modern", segment_style::modern}, {"Mixed", segment_style::mixed}, {"expanded", segment_style::expanded}, {"Design", segment_style::design}, {"Stick", segment_style::stick}});
      choice_segment_style.selected_value_changed += [this] {
        label.segment_style(std::any_cast<forms::segment_style>(choice_segment_style.selected_item().tag()));
      };
      choice_segment_style.selected_index(0);

      numeric_up_down_height.location({270, 10});
      numeric_up_down_height.set_range(1, 400);
      numeric_up_down_height.value_changed += [this] {
        label.height(numeric_up_down_height.value());
      };
      numeric_up_down_height.value(25);
      
      label.location({10, 45});
      label.text(label.valid_characters());
      label.auto_size(true);

      text("LCD label example");
      controls().push_back_range({choice_lcd_style, choice_segment_style, numeric_up_down_height, label});
    }
  private:
    choice choice_lcd_style;
    choice choice_segment_style;
    numeric_up_down numeric_up_down_height;
    lcd_label label;
  };
}

int main() {
  application::run(examples::form_lcd_label());
}
