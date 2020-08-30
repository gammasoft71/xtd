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
      client_size({880, 820});
      controls().push_back_range({label_picture_kde_theme, label_picture_gnome_theme, label_picture_macos_theme, label_picture_symbolic_theme, label_picture_windows_theme, label_picture_xtd_theme, picture_kde_theme, picture_gnome_theme, picture_macos_theme, picture_symbolic_theme, picture_windows_theme, picture_xtd_theme, panel_separator_line, label_picture_context, label_picture_name, label_picture_size, button_context_previous, button_context_next, button_name_previous, button_name_next, button_decrease, button_increase});

      label_picture_kde_theme.text_align(content_alignment::middle_center);
      label_picture_kde_theme.bounds({10, 25, 280, label_picture_name.height()});
      label_picture_kde_theme.text("kde");
      label_picture_kde_theme.border_style(forms::border_style::fixed_3d);
      label_picture_kde_theme.back_color(label_picture_kde_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_kde_theme.fore_color(label_picture_kde_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      label_picture_gnome_theme.text_align(content_alignment::middle_center);
      label_picture_gnome_theme.bounds({300, 25, 280, label_picture_name.height()});
      label_picture_gnome_theme.text("gnome");
      label_picture_gnome_theme.border_style(forms::border_style::fixed_3d);
      label_picture_gnome_theme.back_color(label_picture_gnome_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_gnome_theme.fore_color(label_picture_gnome_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      label_picture_macos_theme.text_align(content_alignment::middle_center);
      label_picture_macos_theme.bounds({590, 25, 280, label_picture_name.height()});
      label_picture_macos_theme.text("macos");
      label_picture_macos_theme.border_style(forms::border_style::fixed_3d);
      label_picture_macos_theme.back_color(label_picture_macos_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_macos_theme.fore_color(label_picture_macos_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      label_picture_symbolic_theme.text_align(content_alignment::middle_center);
      label_picture_symbolic_theme.bounds({10, 360, 280, label_picture_name.height()});
      label_picture_symbolic_theme.text("symbolic");
      label_picture_symbolic_theme.border_style(forms::border_style::fixed_3d);
      label_picture_symbolic_theme.back_color(label_picture_symbolic_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_symbolic_theme.fore_color(label_picture_symbolic_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      label_picture_windows_theme.text_align(content_alignment::middle_center);
      label_picture_windows_theme.bounds({300, 360, 280, label_picture_name.height()});
      label_picture_windows_theme.text("windows");
      label_picture_windows_theme.border_style(forms::border_style::fixed_3d);
      label_picture_windows_theme.back_color(label_picture_windows_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_windows_theme.fore_color(label_picture_windows_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      label_picture_xtd_theme.text_align(content_alignment::middle_center);
      label_picture_xtd_theme.bounds({590, 360, 280, label_picture_name.height()});
      label_picture_xtd_theme.text("xtd");
      label_picture_xtd_theme.border_style(forms::border_style::fixed_3d);
      label_picture_xtd_theme.back_color(label_picture_xtd_theme.text() == system_images::default_theme() ? system_colors::menu_highlight() : system_colors::window());
      label_picture_xtd_theme.fore_color(label_picture_xtd_theme.text() == system_images::fallback_theme() ? system_colors::menu_highlight() : system_colors::window_text());

      picture_kde_theme.back_color(system_colors::window());
      picture_kde_theme.border_style(forms::border_style::fixed_3d);
      picture_kde_theme.bounds({10, 65, 280, 280});
      picture_kde_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_gnome_theme.back_color(system_colors::window());
      picture_gnome_theme.border_style(forms::border_style::fixed_3d);
      picture_gnome_theme.bounds({300, 65, 280, 280});
      picture_gnome_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_macos_theme.back_color(system_colors::window());
      picture_macos_theme.border_style(forms::border_style::fixed_3d);
      picture_macos_theme.bounds({590, 65, 280, 280});
      picture_macos_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_symbolic_theme.back_color(system_colors::window());
      picture_symbolic_theme.border_style(forms::border_style::fixed_3d);
      picture_symbolic_theme.bounds({10, 400, 280, 280});
      picture_symbolic_theme.size_mode(picture_box_size_mode::center_image);

      picture_windows_theme.back_color(system_colors::window());
      picture_windows_theme.border_style(forms::border_style::fixed_3d);
      picture_windows_theme.bounds({300, 400, 280, 280});
      picture_windows_theme.size_mode(picture_box_size_mode::center_image);
      
      picture_xtd_theme.back_color(system_colors::window());
      picture_xtd_theme.border_style(forms::border_style::fixed_3d);
      picture_xtd_theme.bounds({590, 400, 280, 280});
      picture_xtd_theme.size_mode(picture_box_size_mode::center_image);
      
      panel_separator_line.back_color(system_colors::control_text());
      panel_separator_line.bounds({10, 695, 860, 1});

      label_picture_context.text_align(content_alignment::middle_center);
      label_picture_context.border_style(forms::border_style::fixed_3d);
      label_picture_context.back_color(system_colors::window());
      label_picture_context.bounds({10, 710, 280, label_picture_name.height()});

      label_picture_name.text_align(content_alignment::middle_center);
      label_picture_name.border_style(forms::border_style::fixed_3d);
      label_picture_name.back_color(system_colors::window());
      label_picture_name.bounds({300, 710, 280, label_picture_name.height()});
      
      label_picture_size.text_align(content_alignment::middle_center);
      label_picture_size.border_style(forms::border_style::fixed_3d);
      label_picture_size.back_color(system_colors::window());
      label_picture_size.bounds({590, 710, 280, label_picture_name.height()});

      button_context_previous.auto_repeat(true);
      button_context_previous.enabled(false);
      button_context_previous.image(button_images::previous(drawing::size {32, 32}));
      button_context_previous.image_align(content_alignment::middle_left);
      button_context_previous.text(texts::previous);
      button_context_previous.bounds({10, 750, 125, 40});
      button_context_previous.click += [&] {
        current_context_index--;
        current_name_index= 0;
        update_form();
      };
   
      button_context_next.auto_repeat(true);
      button_context_next.image(button_images::next(drawing::size {32, 32}));
      button_context_next.image_align(content_alignment::middle_right);
      button_context_next.text(texts::next);
      button_context_next.bounds({165, 750, 125, 40});
      button_context_next.click += [&] {
        current_context_index++;
        current_name_index= 0;
        update_form();
      };

      button_name_previous.auto_repeat(true);
      button_name_previous.enabled(false);
      button_name_previous.image(button_images::previous(drawing::size {32, 32}));
      button_name_previous.image_align(content_alignment::middle_left);
      button_name_previous.text("P&revious");
      button_name_previous.bounds({300, 750, 125, 40});
      button_name_previous.click += [&] {
        current_name_index--;
        update_form();
      };
      
      button_name_next.auto_repeat(true);
      button_name_next.image(button_images::next(drawing::size {32, 32}));
      button_name_next.image_align(content_alignment::middle_right);
      button_name_next.text("N&ext");
      button_name_next.bounds({455, 750, 125, 40});
      button_name_next.click += [&] {
        current_name_index++;
        update_form();
      };

      button_decrease.auto_repeat(true);
      button_decrease.enabled(false);
      button_decrease.image(button_images::remove(drawing::size {32, 32}));
      button_decrease.image_align(content_alignment::middle_left);
      button_decrease.text("&Decrease");
      button_decrease.bounds({590, 750, 125, 40});
      button_decrease.click += [&] {
        current_size_index--;
        update_form();
      };
      
      button_increase.auto_repeat(true);
      button_increase.image(button_images::add(drawing::size {32, 32}));
      button_increase.image_align(content_alignment::middle_right);
      button_increase.text("&Increase");
      button_increase.bounds({745, 750, 125, 40});
      button_increase.click += [&] {
        current_size_index++;
        update_form();
      };

      update_form();
    }
    
  private:
    void update_form() {
      picture_kde_theme.image(system_images::from_name("kde", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("kde", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      picture_gnome_theme.image(system_images::from_name("gnome", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("gnome", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      picture_macos_theme.image(system_images::from_name("macos", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("macos", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      picture_symbolic_theme.image(system_images::from_name("symbolic", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("symbolic", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      picture_windows_theme.image(system_images::from_name("windows", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("windows", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      picture_xtd_theme.image(system_images::from_name("xtd", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) != image::empty ? system_images::from_name("xtd", system_images::names(system_images::contexts()[current_context_index])[current_name_index], system_images::sizes()[current_size_index]) : system_images::image_missing({256, 256}));
      label_picture_context.text(system_images::contexts()[current_context_index]);
      label_picture_name.text(system_images::names(system_images::contexts()[current_context_index])[current_name_index]);
      label_picture_size.text(strings::format("{}x{} pixels", system_images::sizes()[current_size_index].width(), system_images::sizes()[current_size_index].height()));
      button_context_previous.enabled(current_context_index > 0);
      button_context_next.enabled(current_context_index < system_images::contexts().size() - 1);
      button_name_previous.enabled(current_name_index > 0);
      button_name_next.enabled(current_name_index < system_images::names(system_images::contexts()[current_context_index]).size() - 1);
      button_decrease.enabled(current_size_index > 0);
      button_increase.enabled(current_size_index < system_images::sizes().size() - 1);
    }
    
    int current_context_index = 0;
    int current_name_index = 0;
    int current_size_index = 7;
    label label_picture_kde_theme;
    label label_picture_gnome_theme;
    label label_picture_macos_theme;
    label label_picture_symbolic_theme;
    label label_picture_windows_theme;
    label label_picture_xtd_theme;
    picture_box picture_kde_theme;
    picture_box picture_gnome_theme;
    picture_box picture_macos_theme;
    picture_box picture_symbolic_theme;
    picture_box picture_windows_theme;
    picture_box picture_xtd_theme;
    panel panel_separator_line;
    label label_picture_context;
    label label_picture_name;
    label label_picture_size;
    button button_context_previous;
    button button_context_next;
    button button_name_previous;
    button button_name_next;
    button button_decrease;
    button button_increase;
  };
}

int main() {
  //application::enable_dark_mode();
  //application::enable_light_mode();
  application::run(example::form1());
}
