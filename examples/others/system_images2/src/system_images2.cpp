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
      text("System images 2 example");
      client_size({1170, 470});
      controls().push_back_range({choice_context, choice_size, picture_xtd_theme, picture_gnome_theme, picture_macos_theme, picture_windows_theme, label_picture_name, label_picture_xtd_theme, label_picture_gnome_theme, label_picture_macos_theme, label_picture_windows_theme, button_previous, button_next});

      picture_xtd_theme.back_color(system_colors::window());
      picture_xtd_theme.border_style(forms::border_style::fixed_3d);
      picture_xtd_theme.bounds({10, 65, 280, 280});
      picture_xtd_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_gnome_theme.back_color(system_colors::window());
      picture_gnome_theme.border_style(forms::border_style::fixed_3d);
      picture_gnome_theme.bounds({300, 65, 280, 280});
      picture_gnome_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_macos_theme.back_color(system_colors::window());
      picture_macos_theme.border_style(forms::border_style::fixed_3d);
      picture_macos_theme.bounds({590, 65, 280, 280});
      picture_macos_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_windows_theme.back_color(system_colors::window());
      picture_windows_theme.border_style(forms::border_style::fixed_3d);
      picture_windows_theme.bounds({880, 65, 280, 280});
      picture_windows_theme.size_mode(picture_box_size_mode::center_image);
      
      choice_context.bounds({10, 25, 280, 25});
      choice_context.items().push_back_range(system_images::contexts());
      choice_context.selected_index(0);
      choice_context.selected_index_changed += [&] {
        current_image_index = 0;
        update_form();
      };

      choice_size.bounds({300, 25, 280, 25});
      for (auto size  : system_images::sizes())
        if (size.width() <= picture_xtd_theme.width() && size.height() <= picture_xtd_theme.height())
          choice_size.items().push_back({strings::format("{}x{} pixels", size.width(), size.height()), size});
      choice_size.selected_index(7);
      choice_size.selected_index_changed += {*this, &form1::update_form};

      label_picture_name.text_align(content_alignment::middle_center);
      label_picture_name.border_style(forms::border_style::fixed_3d);
      label_picture_name.back_color(system_colors::window());
      label_picture_name.bounds({590, 25, 280, label_picture_name.height()});

      label_picture_xtd_theme.text_align(content_alignment::middle_center);
      label_picture_xtd_theme.bounds({10, 360, 280, label_picture_name.height()});
      label_picture_xtd_theme.text("xtd");
      
      label_picture_gnome_theme.text_align(content_alignment::middle_center);
      label_picture_gnome_theme.bounds({300, 360, 280, label_picture_name.height()});
      label_picture_gnome_theme.text("gnome");
      
      label_picture_macos_theme.text_align(content_alignment::middle_center);
      label_picture_macos_theme.bounds({590, 360, 280, label_picture_name.height()});
      label_picture_macos_theme.text("macos");
      
      label_picture_windows_theme.text_align(content_alignment::middle_center);
      label_picture_windows_theme.bounds({880, 360, 280, label_picture_name.height()});
      label_picture_windows_theme.text("windows");
      
      button_previous.auto_repeat(true);
      button_previous.enabled(false);
      button_previous.image(system_images::from_name("go-previous"));
      button_previous.image_align(content_alignment::middle_left);
      button_previous.text("&Previous");
      button_previous.bounds({10, 400, 125, 40});
      button_previous.click += [&] {
        if (current_image_index > 0) --current_image_index;
        update_form();
      };

      button_next.auto_repeat(true);
      button_next.image(system_images::from_name("go-next"));
      button_next.image_align(content_alignment::middle_right);
      button_next.text("&Next");
      button_next.bounds({165, 400, 125, 40});
      button_next.click += [&] {
        if (current_image_index < system_images::names(choice_context.selected_item().value()).size()) ++current_image_index;
        update_form();
      };
      
      update_form();
    }
    
  private:
    void update_form() {
      picture_xtd_theme.image(system_images::from_name("xtd", system_images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())));
      picture_gnome_theme.image(system_images::from_name("gnome", system_images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())));
      picture_macos_theme.image(system_images::from_name("macos", system_images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())));
      picture_windows_theme.image(system_images::from_name("windows", system_images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())));
      label_picture_name.text(system_images::names(choice_context.selected_item().value())[current_image_index]);
      button_previous.enabled(current_image_index > 0);
      button_next.enabled(current_image_index < system_images::names(choice_context.selected_item().value()).size() - 1);
    }
    
    int current_image_index = 0;
    choice choice_context;
    choice choice_size;
    picture_box picture_xtd_theme;
    picture_box picture_gnome_theme;
    picture_box picture_macos_theme;
    picture_box picture_windows_theme;
    label label_picture_name;
    label label_picture_xtd_theme;
    label label_picture_gnome_theme;
    label label_picture_macos_theme;
    label label_picture_windows_theme;
    button button_previous;
    button button_next;
  };
}

int main() {
  application::run(example::form1());
}
