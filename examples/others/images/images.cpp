#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("Images example");
      client_size({300, 250});

      image_list.image_size({128, 128});
      image_list.images().push_back_range({images::about_128x128, images::add_128x128, images::apply_128x128, images::archive_128x128, images::audio_disk_128x128, images::back_128x128, images::burn_disk_128x128, images::calendar_128x128, images::cancel2_128x128, images::cancel_128x128, images::compact_disk_128x128, images::copy2_128x128, images::copy_128x128, images::cut_128x128, images::delete_128x128, images::down2_128x128, images::down_128x128, images::download_128x128, images::dvd_disk_128x128, images::earth_128x128, images::edit_128x128, images::favorites_128x128, images::find_128x128, images::flash_disk_128x128, images::folder_128x128, images::forward_128x128, images::gammasoft_128x128, images::hard_disk_128x128, images::help_128x128, images::information_128x128, images::key_128x128, images::left2_128x128, images::left_128x128, images::mail_128x128, images::mail_forward_128x128, images::mail_send_128x128, images::multimedia_pause_128x128, images::multimedia_play_128x128, images::multimedia_stop_128x128, images::negative_128x128, images::new_128x128, images::next_128x128, images::open_128x128, images::paste_128x128, images::picture_128x128, images::positive_128x128, images::presentation_128x128, images::preview_128x128, images::previous_128x128, images::print_128x128, images::properties_128x128, images::quit_128x128, images::redo_128x128, images::refresh_128x128, images::remove_128x128, images::rename_128x128, images::right2_128x128, images::right_128x128, images::save_128x128, images::search_128x128, images::settings_128x128, images::stop_128x128, images::synchronize_128x128, images::text_document_128x128, images::undo_128x128, images::up2_128x128, images::up_128x128, images::upload_128x128, images::user_128x128, images::zoom_in_128x128, images::zoom_out_128x128});
      
      picture.parent(*this);
      picture.back_color(system_colors::window());
      picture.border_style(forms::border_style::fixed_3d);
      picture.bounds({75, 25, 152, 152});
      picture.size_mode(picture_box_size_mode::center_image);
      picture.image(image_list.images()[0]);

      button_previous.parent(*this);
      button_previous.auto_repeat(true);
      button_previous.text("&<");
      button_previous.location({73, 200});
      button_previous.enabled(false);
      button_previous.click += [&] {
        if (current_image_index > 0) {
          current_image_index--;
          picture.image(image_list.images()[current_image_index]);
        }
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < image_list.images().size() - 1);
      };
      
      button_next.parent(*this);
      button_next.auto_repeat(true);
      button_next.text("&>");
      button_next.location({152, 200});
      button_next.click += [&] {
        if (current_image_index < image_list.images().size()) {
          current_image_index++;
          picture.image(image_list.images()[current_image_index]);
        }
        button_previous.enabled(current_image_index > 0);
        button_next.enabled(current_image_index < image_list.images().size() - 1);
      };
      
      show();
    }
    
  private:
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
