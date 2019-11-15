#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("Image list example");
      client_size({300, 250});
      click += [this] {
        load_images();
      };

      image_list.image_size({128, 128});
      
      picture.parent(*this);
      picture.back_color(system_colors::window());
      picture.border_style(forms::border_style::fixed_3d);
      picture.bounds({75, 25, 152, 152});
      picture.size_mode(picture_box_size_mode::center_image);
      picture.click += [this] {
        load_images();
      };

      button_previous.parent(*this);
      button_previous.text("<");
      button_previous.location({73, 200});
      button_previous.enabled(false);
      button_previous.click += [this] {
        if (current_image_index > 0) {
          current_image_index--;
          picture.image(image_list.images()[current_image_index]);
        }
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < image_list.images().size() - 1);
      };
      
      button_next.parent(*this);
      button_next.text(">");
      button_next.location({152, 200});
      button_next.enabled(false);
      button_next.click += [this] {
        if (current_image_index < image_list.images().size()) {
          current_image_index++;
          picture.image(image_list.images()[current_image_index]);
        }
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < image_list.images().size() - 1);
      };

      show();
      load_images();
    }
    
  private:
    void load_images() {
      open_file_dialog ofd;
      ofd.multi_select(true);
      ofd.filter("All Image Files|*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.tif;*.tiff;*.xpm|Bitmap Files|*.bmp|Gif Files|*.gif|Jpeg Files|*.jpg;*.jpeg|Png Files|*.png|Tiff Files|*.tif;*.tiff|xpm Files|*.xpm");
      if (ofd.show_dialog() == dialog_result::ok) {
        image_list.images().clear();
        for (const auto& file : ofd.file_names())
          image_list.images().push_back(drawing::image::from_file(file));
        current_image_index = 0;
        picture.image(image_list.images()[0]);
        button_previous.enabled(false);
        button_next.enabled(image_list.images().size() > 1);
      }
    }

    forms::image_list image_list;
    int current_image_index = 0;

    picture_box picture;
    button button_previous;
    button button_next;
  };
}

int main() {
  application::run(example::form1());
}
