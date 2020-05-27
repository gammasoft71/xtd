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
      text("System icons example");
      client_size({430, 530});
      controls().push_back_range({choice_theme, choice_context, choice_size, picture, label_picture_name, button_previous, button_next});

      picture.back_color(system_colors::window());
      picture.border_style(forms::border_style::fixed_3d);
      picture.bounds({75, 125, 280, 280});
      picture.size_mode(picture_box_size_mode::center_image);

      choice_theme.bounds({75, 25, 280, 25});
      choice_theme.items().push_back("default_theme");
      choice_theme.items().push_back_range(system_icons::themes());
      choice_theme.selected_index(0);
      choice_theme.selected_index_changed += {*this, &form1::update_form};

      choice_context.bounds({75, 55, 280, 25});
      choice_context.items().push_back_range(system_icons::contexts());
      choice_context.selected_index(0);
      choice_context.selected_index_changed += [&] {
        current_image_index = 0;
        update_form();
      };

      choice_size.bounds({75, 85, 280, 25});
      for (auto size  : system_icons::sizes())
        if (size.width() <= picture.width() && size.height() <= picture.height())
          choice_size.items().push_back({strings::format("{}x{} pixels", size.width(), size.height()), size});
      choice_size.selected_index(7);
      choice_size.selected_index_changed += {*this, &form1::update_form};

      label_picture_name.text_align(content_alignment::middle_center);
      label_picture_name.bounds({75, 420, 280, label_picture_name.height()});

      button_previous.auto_repeat(true);
      button_previous.enabled(false);
      button_previous.image(system_icons::from_name("go-previous").to_bitmap());
      button_previous.image_align(content_alignment::middle_left);
      button_previous.text("&Previous");
      button_previous.click += [&] {
        if (current_image_index > 0) --current_image_index;
        update_form();
      };

      button_previous.bounds({75, 460, 125, 40});
      button_next.auto_repeat(true);
      button_next.image(system_icons::from_name("go-next").to_bitmap());
      button_next.image_align(content_alignment::middle_right);
      button_next.text("&Next");
      button_next.bounds({230, 460, 125, 40});
      button_next.click += [&] {
        if (current_image_index < system_icons::names(choice_context.selected_item().value()).size()) ++current_image_index;
        update_form();
      };
      
      update_form();
    }
    
  private:
    void update_form() {
      if (choice_theme.selected_index() == 0)
        picture.image(system_icons::from_name(system_icons::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())).to_bitmap());
      else
        picture.image(system_icons::from_name(choice_theme.selected_item().value(), system_icons::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())).to_bitmap());
      label_picture_name.text(system_icons::names(choice_context.selected_item().value())[current_image_index]);
      button_previous.enabled(current_image_index > 0);
      button_next.enabled(current_image_index < system_icons::names(choice_context.selected_item().value()).size() - 1);
    }
    
    int current_image_index = 0;
    choice choice_theme;
    choice choice_context;
    choice choice_size;
    picture_box picture;
    label label_picture_name;
    button button_previous;
    button button_next;
  };
}

int main() {
  application::run(example::form1());
}
