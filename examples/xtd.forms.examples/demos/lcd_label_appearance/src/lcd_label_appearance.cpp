#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace lcd_label_appearance_example {
  class form_lcd_label : public form {
  public:
    form_lcd_label() {
      auto_scroll(true);
      client_size({870, 240});
      text("LCD label example");
      controls().push_back_range({group_box_properties, label_lcd_label});
      
      group_box_properties.controls().push_back({panel_properties});
      group_box_properties.location({10, 10});
      group_box_properties.size({340, 220});
      group_box_properties.anchor(anchor_styles::left | anchor_styles::top | anchor_styles::bottom);
      group_box_properties.text("properties");
      
      panel_properties.auto_scroll(true);
      panel_properties.controls().push_back_range({lcd_style_label, lcd_style_choice, segment_style_label, segment_style_choice, height_label, height_numeric_up_down, fore_color_label, fore_color_color_picker, show_digit_background_label, show_digit_background_togle_button});
      panel_properties.dock(dock_style::fill);
      
      lcd_style_label.auto_size(true);
      lcd_style_label.location({10, 13});
      lcd_style_label.text("Lcd style: ");
      
      lcd_style_choice.location({120, 10});
      lcd_style_choice.width(180);
      lcd_style_choice.items().push_back_range({{"Seven segment display", lcd_style::seven_segment_display}, {"Nine segment display", lcd_style::nine_segment_display}, {"Fourteen segment display", lcd_style::fourteen_segment_display}, {"Sixteen segment display", lcd_style::sixteen_segment_display}, {"Dot matrix display", lcd_style::dot_matrix_display}});
      lcd_style_choice.selected_value_changed += [&] {
        label_lcd_label.lcd_style(std::any_cast<lcd_style>(lcd_style_choice.selected_item().tag()));
        segment_style_choice.items().clear();
        if (lcd_style_choice.selected_item().value() == "Dot matrix display") {
          segment_style_choice.items().push_back_range({{"Standard (or round)", dot_matrix_style::standard}, {"Square", dot_matrix_style::square}});
          segment_style_choice.selected_index(as<int>(label_lcd_label.dot_matrix_style()));
        } else {
          segment_style_choice.items().push_back_range({{"Standard", segment_style::standard}, {"Modern", segment_style::modern}, {"Mixed", segment_style::mixed}, {"expanded", segment_style::expanded}, {"Design", segment_style::design}, {"Stick", segment_style::stick}});
          segment_style_choice.selected_index(as<int>(label_lcd_label.segment_style()));
        }
      };
      lcd_style_choice.selected_index(0);
      
      segment_style_label.auto_size(true);
      segment_style_label.location({10, 48});
      segment_style_label.text("Segment style: ");
      
      segment_style_choice.location({120, 45});
      segment_style_choice.width(180);
      segment_style_choice.selected_value_changed += [&] {
        auto style = segment_style_choice.selected_item().tag();
        if (std::any_cast<dot_matrix_style>(&style))
          label_lcd_label.dot_matrix_style(std::any_cast<forms::dot_matrix_style>(segment_style_choice.selected_item().tag()));
        else
          label_lcd_label.segment_style(std::any_cast<forms::segment_style>(segment_style_choice.selected_item().tag()));
      };
      segment_style_choice.selected_index(0);
      
      height_label.auto_size(true);
      height_label.location({10, 83});
      height_label.text("Height: ");
      
      height_numeric_up_down.location({120, 80});
      height_numeric_up_down.width(180);
      height_numeric_up_down.set_range(1, 400);
      height_numeric_up_down.value_changed += [&] {
        label_lcd_label.height(as<int>(height_numeric_up_down.value()));
      };
      height_numeric_up_down.value(50);
      
      fore_color_label.auto_size(true);
      fore_color_label.location({10, 118});
      fore_color_label.text("Foreground: ");
      
      fore_color_color_picker.location({120, 115});
      fore_color_color_picker.width(180);
      fore_color_color_picker.color(label_lcd_label.fore_color());
      fore_color_color_picker.color_picker_changed += [&] {
        label_lcd_label.fore_color(fore_color_color_picker.color());
      };
      
      show_digit_background_label.auto_size(true);
      show_digit_background_label.location({10, 153});
      show_digit_background_label.text("Show digit: ");
      
      show_digit_background_togle_button.location({120, 150});
      show_digit_background_togle_button.width(180);
      show_digit_background_togle_button.auto_size(true);
      show_digit_background_togle_button.checked(true);
      show_digit_background_togle_button.text("true");
      show_digit_background_togle_button.checked_changed += [&] {
        show_digit_background_togle_button.text(show_digit_background_togle_button.checked() ? "True" : "False");
        label_lcd_label.show_back_digit(show_digit_background_togle_button.checked());
      };
      
      label_lcd_label.location({380, 30});
      label_lcd_label.text("1234567890");
      label_lcd_label.auto_size(true);
    }
    
  private:
    group_box group_box_properties;
    panel panel_properties;
    
    label lcd_style_label;
    choice lcd_style_choice;
    label segment_style_label;
    choice segment_style_choice;
    label height_label;
    numeric_up_down height_numeric_up_down;
    label fore_color_label;
    color_picker fore_color_color_picker;
    label show_digit_background_label;
    toggle_button show_digit_background_togle_button;
    
    lcd_label label_lcd_label;
  };
}

auto main() -> int {
  application::run(lcd_label_appearance_example::form_lcd_label());
}
