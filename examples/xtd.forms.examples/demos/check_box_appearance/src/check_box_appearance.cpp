#include <limits>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Button appearance");
    client_size({800, 450});
    controls().push_back_range({group_box_properties, check_box_demo});
    
    group_box_properties.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::bottom);
    group_box_properties.controls().push_back(panel_properties);
    group_box_properties.location({10, 10});
    group_box_properties.size({340, 430});
    group_box_properties.text("properties");
    
    panel_properties.auto_scroll(true);
    panel_properties.controls().push_back_range({label_text, text_box_text, label_text_align, choice_text_align, label_image, choice_image, label_image_align, choice_image_align, label_appearance, choice_appearance, label_flat_style, choice_flat_style, label_back_color, color_picker_back_color, label_fore_color, color_picker_fore_color, label_width, numeric_up_down_width, label_height, numeric_up_down_height, label_auto_size, check_box_auto_size, label_three_state, check_box_three_state, label_enebaled, check_box_enabled});
    panel_properties.dock(dock_style::fill);

    label_text.auto_size(true);
    label_text.location({10, 13});
    label_text.text("Text: ");

    text_box_text.text_changed += [&] {
      check_box_demo.text(text_box_text.text());
    };
    text_box_text.location({100, 10});
    text_box_text.text("&Check me!");
    text_box_text.width(200);
    text_box_text.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_text_align.auto_size(true);
    label_text_align.location({10, 48});
    label_text_align.text("text_align: ");

    choice_text_align.selected_value_changed += [&] {
      check_box_demo.text_align(any_cast<content_alignment>(choice_text_align.selected_item().tag()));
    };
    choice_text_align.location({100, 45});
    choice_text_align.items().push_back_range({{"top_left", content_alignment::top_left}, {"top_center", content_alignment::top_center}, {"top_right", content_alignment::top_right}, {"middle_left", content_alignment::middle_left}, {"middle_center", content_alignment::middle_center}, {"middle_right", content_alignment::middle_right}, {"bottom_left", content_alignment::bottom_left}, {"bottom_center", content_alignment::bottom_center}, {"bottom_right", content_alignment::bottom_right}});
    choice_text_align.selected_index(3);
    choice_text_align.width(200);
    choice_text_align.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_image.text("image: ");
    label_image.auto_size(true);
    label_image.location({10, 83});
    
    choice_image.selected_value_changed += [&] {
      if (choice_image.selected_index() == 0) check_box_demo.image(xtd::drawing::image::empty);
      else check_box_demo.image(button_images::from_name(choice_image.selected_item().value()));
    };
    choice_image.items().push_back("none");
    choice_image.items().push_back_range(system_images::names());
    choice_image.selected_index(0);
    choice_image.location({100, 80});
    choice_image.width(200);
    choice_image.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_image_align.text("image_align: ");
    label_image_align.auto_size(true);
    label_image_align.location({10, 118});
    
    choice_image_align.selected_value_changed += [&] {
      check_box_demo.image_align(any_cast<content_alignment>(choice_image_align.selected_item().tag()));
    };
    choice_image_align.items().push_back_range({{"top_left", content_alignment::top_left}, {"top_center", content_alignment::top_center}, {"top_right", content_alignment::top_right}, {"middle_left", content_alignment::middle_left}, {"middle_center", content_alignment::middle_center}, {"middle_right", content_alignment::middle_right}, {"bottom_left", content_alignment::bottom_left}, {"bottom_center", content_alignment::bottom_center}, {"bottom_right", content_alignment::bottom_right}});
    choice_image_align.selected_index(4);
    choice_image_align.location({100, 115});
    choice_image_align.width(200);
    choice_image_align.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_appearance.text("appearance: ");
    label_appearance.auto_size(true);
    label_appearance.location({10, 153});
    
    choice_appearance.selected_value_changed += [&] {
      check_box_demo.appearance(any_cast<appearance>(choice_appearance.selected_item().tag()));
    };
    choice_appearance.items().push_back_range({{"normal", appearance::normal}, {"button", appearance::button}});
    choice_appearance.selected_index(0);
    choice_appearance.location({100, 150});
    choice_appearance.width(200);
    choice_appearance.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_flat_style.text("flat_style: ");
    label_flat_style.auto_size(true);
    label_flat_style.location({10, 188});
    
    choice_flat_style.selected_value_changed += [&] {
      check_box_demo.flat_style(any_cast<flat_style>(choice_flat_style.selected_item().tag()));
    };
    choice_flat_style.items().push_back_range({{"flat", flat_style::flat}, {"popup", flat_style::popup}, {"standard", flat_style::standard}, {"system", flat_style::system}});
    choice_flat_style.selected_index(2);
    choice_flat_style.location({100, 185});
    choice_flat_style.width(200);
    choice_flat_style.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_back_color.text("back_color: ");
    label_back_color.auto_size(true);
    label_back_color.location({10, 223});
    
    color_picker_back_color.alpha_color(true);
    color_picker_back_color.color(check_box_demo.back_color());
    color_picker_back_color.color_changed += [&] {
      check_box_demo.back_color(color_picker_back_color.color());
    };
    color_picker_back_color.location({100, 220});
    color_picker_back_color.width(200);
    color_picker_back_color.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_fore_color.text("fore_color: ");
    label_fore_color.auto_size(true);
    label_fore_color.location({10, 258});
    
    color_picker_fore_color.alpha_color(true);
    color_picker_fore_color.color(check_box_demo.fore_color());
    color_picker_fore_color.color_changed += [&] {
      check_box_demo.fore_color(color_picker_fore_color.color());
    };
    color_picker_fore_color.location({100, 255});
    color_picker_fore_color.width(200);
    color_picker_fore_color.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_width.text("width: ");
    label_width.auto_size(true);
    label_width.location({10, 293});
    
    numeric_up_down_width.value_changed += [&] {
      check_box_demo.width(as<int>(numeric_up_down_width.value()));
    };
    numeric_up_down_width.value(check_box_demo.width());
    numeric_up_down_width.set_range(0, std::numeric_limits<int32_t>::max());
    numeric_up_down_width.location({100, 290});
    numeric_up_down_width.width(200);
    numeric_up_down_width.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_height.text("height: ");
    label_height.auto_size(true);
    label_height.location({10, 328});
    
    numeric_up_down_height.value_changed += [&] {
      check_box_demo.height(as<int>(numeric_up_down_height.value()));
    };
    numeric_up_down_height.value(check_box_demo.height());
    numeric_up_down_height.set_range(0, std::numeric_limits<int32_t>::max());
    numeric_up_down_height.location({100, 325});
    numeric_up_down_height.width(200);
    numeric_up_down_height.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_auto_size.text("auto_size: ");
    label_auto_size.auto_size(true);
    label_auto_size.location({10, 363});
    
    check_box_auto_size.checked_changed += [&] {
      check_box_demo.auto_size(check_box_auto_size.checked());
      numeric_up_down_width.enabled(!check_box_auto_size.checked());
      numeric_up_down_height.enabled(!check_box_auto_size.checked());
      numeric_up_down_width.value(check_box_demo.width());
      numeric_up_down_height.value(check_box_demo.height());
      check_box_auto_size.text(check_box_auto_size.checked() ? "true" : "false");
    };
    check_box_auto_size.appearance(forms::appearance::button);
    check_box_auto_size.checked(check_box_demo.auto_size());
    check_box_auto_size.location({100, 360});
    check_box_auto_size.width(200);
    check_box_auto_size.text("false");
    check_box_auto_size.text_align(content_alignment::middle_center);
    check_box_auto_size.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_three_state.text("three_state: ");
    label_three_state.auto_size(true);
    label_three_state.location({10, 398});
    
    check_box_three_state.checked_changed += [&] {
      check_box_demo.three_state(check_box_three_state.checked());
      check_box_three_state.text(check_box_three_state.checked() ? "true" : "false");
    };
    check_box_three_state.appearance(forms::appearance::button);
    check_box_three_state.checked(accept_button().has_value());
    check_box_three_state.location({100, 395});
    check_box_three_state.width(200);
    check_box_three_state.text("false");
    check_box_three_state.text_align(content_alignment::middle_center);
    check_box_three_state.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    label_enebaled.text("enabled: ");
    label_enebaled.auto_size(true);
    label_enebaled.location({10, 433});
    
    check_box_enabled.checked_changed += [&] {
      check_box_demo.enabled(check_box_enabled.checked());
      check_box_enabled.text(check_box_enabled.checked() ? "true" : "false");
    };
    check_box_enabled.appearance(forms::appearance::button);
    check_box_enabled.checked(check_box_demo.enabled());
    check_box_enabled.location({100, 430});
    check_box_enabled.width(200);
    check_box_enabled.text("true");
    check_box_enabled.text_align(content_alignment::middle_center);
    check_box_enabled.anchor(anchor_styles::left|anchor_styles::top|anchor_styles::right);

    check_box_demo.location({380, 30});
    check_box_demo.click += [&] {
      //message_box::show(*this, "Button clicked", "Button appearance");
    };
  }
  
private:
  group_box group_box_properties;
  panel panel_properties;
  label label_text;
  text_box text_box_text;
  label label_text_align;
  choice choice_text_align;
  label label_image;
  choice choice_image;
  label label_image_align;
  choice choice_image_align;
  label label_appearance;
  choice choice_appearance;
  label label_flat_style;
  choice choice_flat_style;
  label label_back_color;
  color_picker color_picker_back_color;
  label label_fore_color;
  color_picker color_picker_fore_color;
  label label_width;
  numeric_up_down numeric_up_down_width;
  label label_height;
  numeric_up_down numeric_up_down_height;
  label label_auto_size;
  check_box check_box_auto_size;
  label label_three_state;
  check_box check_box_three_state;
  label label_enebaled;
  check_box check_box_enabled;

  check_box check_box_demo;
};

int main() {
  application::run(form1());
}
