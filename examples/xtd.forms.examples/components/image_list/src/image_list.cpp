#include <xtd/xtd>

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("Image list example");
      client_size({300, 250});
      controls().add_range({picture, button_previous, button_next});
      
      pictures.image_size({128, 128});
      
      picture.back_color(system_colors::window());
      picture.border_style(forms::border_style::fixed_3d);
      picture.bounds({75, 25, 150, 150});
      picture.size_mode(picture_box_size_mode::center_image);
      picture.click += delegate_ {
        load_images();
      };
      
      button_previous.auto_repeat(true);
      button_previous.image(button_images::previous());
      button_previous.location({75, 200});
      button_previous.enabled(false);
      button_previous.click += delegate_ {
        if (current_image_index > 0) picture.image(pictures.images()[--current_image_index]);
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < pictures.images().size() - 1);
      };
      
      button_next.auto_repeat(true);
      button_next.image(button_images::next());
      button_next.location({150, 200});
      button_next.enabled(false);
      button_next.click += delegate_ {
        if (current_image_index < pictures.images().size()) picture.image(pictures.images()[++current_image_index]);
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < pictures.images().size() - 1);
      };
      
      show();
      load_images();
    }
    
  private:
    void load_images() {
      auto dialog = open_file_dialog {};
      dialog.multiselect(true);
      dialog.filter("All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff;*.xpm|Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|xpm Files|*.xpm");
      if (dialog.show_dialog() == dialog_result::ok) {
        pictures.images().clear();
        for (auto file : dialog.file_names())
          pictures.images().add(drawing::image::from_file(file));
        current_image_index = 0;
        picture.image(pictures.images()[current_image_index]);
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < pictures.images().size() - 1);
      }
    }
    
    size_t current_image_index = 0;
    image_list pictures;
    picture_box picture;
    button button_previous;
    button button_next;
  };
}

auto main() -> int {
  application::run(example::form1 {});
}
