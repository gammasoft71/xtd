#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Button appearance");
    client_size({310, 350});
    controls().push_back_range({label_text, text_box_text, label_text_align, choice_text_align, label_image, choice_image, label_image_align, choice_image_align, label_flat_style, choice_flat_style, label_back_color, color_picker_back_color, label_fore_color, color_picker_fore_color, panel_line, button_enabled, button_disabled});
    
    label_text.auto_size(true);
    label_text.location({10, 13});
    label_text.text("Text: ");

    text_box_text.text_changed += [&] {
      button_enabled.text(text_box_text.text());
      button_disabled.text(text_box_text.text());
    };
    text_box_text.location({100, 10});
    text_box_text.text("Click");
    text_box_text.width(200);

    label_text_align.auto_size(true);
    label_text_align.location({10, 48});
    label_text_align.text("text_align: ");

    choice_text_align.selected_value_changed += [&] {
      button_enabled.text_align(any_cast<content_alignment>(choice_text_align.selected_item().tag()));
      button_disabled.text_align(any_cast<content_alignment>(choice_text_align.selected_item().tag()));
    };
    choice_text_align.location({100, 45});
    choice_text_align.items().push_back_range({{"top_left", content_alignment::top_left}, {"top_center", content_alignment::top_center}, {"top_right", content_alignment::top_right}, {"middle_left", content_alignment::middle_left}, {"middle_center", content_alignment::middle_center}, {"middle_right", content_alignment::middle_right}, {"bottom_left", content_alignment::bottom_left}, {"bottom_center", content_alignment::bottom_center}, {"bottom_right", content_alignment::bottom_right}});
    choice_text_align.selected_index(4);
    choice_text_align.width(200);
    
    label_image.text("image: ");
    label_image.auto_size(true);
    label_image.location({10, 83});
    
    choice_image.selected_value_changed += [&] {
      button_enabled.image(button_images::from_name(choice_image.selected_item().value()));
      button_disabled.image(button_images::from_name(choice_image.selected_item().value()));
    };
    choice_image.items().push_back("none");
    choice_image.items().push_back_range(system_images::names());
    choice_image.selected_index(0);
    choice_image.location({100, 80});
    choice_image.width(200);

    label_image_align.text("image_align: ");
    label_image_align.auto_size(true);
    label_image_align.location({10, 118});
    
    choice_image_align.selected_value_changed += [&] {
      button_enabled.image_align(any_cast<content_alignment>(choice_image_align.selected_item().tag()));
      button_disabled.image_align(any_cast<content_alignment>(choice_image_align.selected_item().tag()));
    };
    choice_image_align.items().push_back_range({{"top_left", content_alignment::top_left}, {"top_center", content_alignment::top_center}, {"top_right", content_alignment::top_right}, {"middle_left", content_alignment::middle_left}, {"middle_center", content_alignment::middle_center}, {"middle_right", content_alignment::middle_right}, {"bottom_left", content_alignment::bottom_left}, {"bottom_center", content_alignment::bottom_center}, {"bottom_right", content_alignment::bottom_right}});
    choice_image_align.selected_index(4);
    choice_image_align.location({100, 115});
    choice_image_align.width(200);

    label_flat_style.text("flat_style: ");
    label_flat_style.auto_size(true);
    label_flat_style.location({10, 153});
    
    choice_flat_style.selected_value_changed += [&] {
      button_enabled.flat_style(any_cast<flat_style>(choice_flat_style.selected_item().tag()));
      button_disabled.flat_style(any_cast<flat_style>(choice_flat_style.selected_item().tag()));
    };
    choice_flat_style.items().push_back_range({{"flat", flat_style::flat}, {"popup", flat_style::popup}, {"standard", flat_style::standard}, {"system", flat_style::system}});
    choice_flat_style.selected_index(2);
    choice_flat_style.location({100, 150});
    choice_flat_style.width(200);

    label_back_color.text("back_color: ");
    label_back_color.auto_size(true);
    label_back_color.location({10, 188});
    
    color_picker_back_color.color_changed += [&] {
      button_enabled.back_color(color_picker_back_color.color());
      button_disabled.back_color(color_picker_back_color.color());
    };
    color_picker_back_color.color(button_enabled.back_color());
    color_picker_back_color.location({100, 185});
    color_picker_back_color.width(200);

    label_fore_color.text("fore_color: ");
    label_fore_color.auto_size(true);
    label_fore_color.location({10, 223});
    
    color_picker_fore_color.color_changed += [&] {
      button_enabled.fore_color(color_picker_fore_color.color());
      button_disabled.fore_color(color_picker_fore_color.color());
    };
    color_picker_fore_color.color(button_enabled.fore_color());
    color_picker_fore_color.location({100, 220});
    color_picker_fore_color.width(200);

    panel_line.location({10, 255});
    panel_line.back_color(system_colors::control_text());
    panel_line.size({290, 1});

    button_enabled.location({53, 290});

    button_disabled.location({182, 290});
    button_disabled.enabled(false);
  }
  
private:
  label label_text;
  text_box text_box_text;
  label label_text_align;
  choice choice_text_align;
  label label_image;
  choice choice_image;
  label label_image_align;
  choice choice_image_align;
  label label_flat_style;
  choice choice_flat_style;
  label label_back_color;
  color_picker color_picker_back_color;
  label label_fore_color;
  color_picker color_picker_fore_color;
  panel panel_line;

  button button_enabled;
  button button_disabled;
};

int main() {
  application::run(form1());
}
