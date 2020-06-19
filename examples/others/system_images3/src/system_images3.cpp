#include <map>
#include <string>
#include <vector>
#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("System images example");
      client_size({676, 330});
      controls().push_back_range({choice_theme, choice_context, picture_16, picture_32, picture_64, picture_128, picture_256, label_picture_name, button_previous, button_next});

      picture_16.back_color(system_colors::window());
      picture_16.border_style(forms::border_style::fixed_3d);
      picture_16.bounds({10, 40, 30, 30});
      picture_16.size_mode(picture_box_size_mode::center_image);

      picture_32.back_color(system_colors::window());
      picture_32.border_style(forms::border_style::fixed_3d);
      picture_32.bounds({50, 40, 56, 56});
      picture_32.size_mode(picture_box_size_mode::center_image);

      picture_64.back_color(system_colors::window());
      picture_64.border_style(forms::border_style::fixed_3d);
      picture_64.bounds({126, 40, 88, 88});
      picture_64.size_mode(picture_box_size_mode::center_image);
      
      picture_128.back_color(system_colors::window());
      picture_128.border_style(forms::border_style::fixed_3d);
      picture_128.bounds({224, 40, 152, 152});
      picture_128.size_mode(picture_box_size_mode::center_image);
      
      picture_256.back_color(system_colors::window());
      picture_256.border_style(forms::border_style::fixed_3d);
      picture_256.bounds({386, 40, 280, 280});
      picture_256.size_mode(picture_box_size_mode::center_image);

      choice_theme.bounds({10, 10, 280, 25});
      choice_theme.items().push_back("default_theme");
      choice_theme.items().push_back_range(system_images::themes());
      choice_theme.selected_index(0);
      choice_theme.selected_index_changed += {*this, &form1::update_form};

      choice_context.bounds({300, 10, 280, 25});
      choice_context.items().push_back_range(system_images::contexts());
      choice_context.selected_index(0);
      choice_context.selected_index_changed += [&] {
        current_image_index = 0;
        update_form();
      };

      label_picture_name.bounds({10, 240, 280, label_picture_name.height()});

      button_previous.auto_repeat(true);
      button_previous.enabled(false);
      button_previous.image(button_images::previous());
      button_previous.image_align(content_alignment::middle_left);
      button_previous.text(texts::previous);
      button_previous.bounds({10, 280, 125, 40});
      button_previous.click += [&] {
        if (current_image_index > 0) --current_image_index;
        update_form();
      };

      button_next.auto_repeat(true);
      button_next.image(button_images::next());
      button_next.image_align(content_alignment::middle_right);
      button_next.text(texts::next);
      button_next.bounds({165, 280, 125, 40});
      button_next.click += [&] {
        if (current_image_index < system_images::names(choice_context.selected_item().value()).size()) ++current_image_index;
        update_form();
      };
      
      update_form();
    }
    
  private:
    void update_form() {
      auto theme = choice_theme.selected_index() == 0 ? system_images::default_theme() : choice_theme.selected_item().value();
      picture_16.image(system_images::from_name(theme, system_images::names(choice_context.selected_item().value())[current_image_index], drawing::size {16, 16}));
      picture_32.image(system_images::from_name(theme, system_images::names(choice_context.selected_item().value())[current_image_index], drawing::size {32, 32}));
      picture_64.image(system_images::from_name(theme, system_images::names(choice_context.selected_item().value())[current_image_index], drawing::size {64, 64}));
      picture_128.image(system_images::from_name(theme, system_images::names(choice_context.selected_item().value())[current_image_index], drawing::size {128, 128}));
      picture_256.image(system_images::from_name(theme, system_images::names(choice_context.selected_item().value())[current_image_index], drawing::size {256, 256}));

      label_picture_name.text(system_images::names(choice_context.selected_item().value())[current_image_index]);
      button_previous.enabled(current_image_index > 0);
      button_next.enabled(current_image_index < system_images::names(choice_context.selected_item().value()).size() - 1);
    }
    
    int current_image_index = 0;
    choice choice_theme;
    choice choice_context;
    picture_box picture_16;
    picture_box picture_32;
    picture_box picture_64;
    picture_box picture_128;
    picture_box picture_256;
    label label_picture_name;
    button button_previous;
    button button_next;
  };
}

int main() {
  application::enable_button_images();
  application::run(example::form1());
}
