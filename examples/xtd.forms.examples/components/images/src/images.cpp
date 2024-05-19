#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/button_images>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/label>
#include <xtd/forms/picture_box>
#include <xtd/drawing/system_colors>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace example {
  class form1 : public form {
  public:
    form1() {
      text("Images example");
      client_size({430, 530});
      minimum_client_size(client_size());
      controls().push_back_range({choice_theme, choice_context, choice_size, picture, label_picture_name, button_previous, button_next});
      
      picture.back_color(system_colors::window());
      picture.border_style(forms::border_style::fixed_3d);
      picture.bounds({75, 125, 280, 280});
      picture.anchor(anchor_styles::all);
      picture.size_mode(picture_box_size_mode::center_image);
      
      choice_theme.bounds({75, 25, 280, 25});
      choice_theme.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
      choice_theme.items().push_back("current theme");
      auto names = application::style_sheet_names();
      sort(names.begin(), names.end());
      choice_theme.items().push_back_range(names);
      choice_theme.selected_index(0);
      choice_theme.selected_index_changed += event_handler(*this, &form1::update_form);
      
      choice_context.bounds({75, 55, 280, 25});
      choice_context.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
      choice_context.items().push_back_range(images::contexts());
      choice_context.selected_index(0);
      choice_context.selected_index_changed += [&] {
        current_image_index = 0;
        update_form();
      };
      
      choice_size.bounds({75, 85, 280, 25});
      choice_size.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
      for (auto size : images::sizes())
        choice_size.items().push_back({ustring::format("{}x{} pixels", size.width(), size.height()), size});
      choice_size.selected_index(7);
      choice_size.selected_index_changed += event_handler(*this, &form1::update_form);
      
      label_picture_name.bounds({75, 420, 280, label_picture_name.height()});
      label_picture_name.anchor(anchor_styles::bottom | anchor_styles::left | anchor_styles::right);
      label_picture_name.text_align(content_alignment::middle_center);
      
      button_previous.auto_repeat(true);
      button_previous.bounds({75, 460, 125, 40});
      button_previous.anchor(anchor_styles::bottom | anchor_styles::left);
      button_previous.enabled(false);
      button_previous.image(button_images::previous());
      button_previous.image_align(content_alignment::middle_left);
      button_previous.text(texts::previous());
      button_previous.click += [&] {
        if (current_image_index > 0) --current_image_index;
        update_form();
      };
      
      button_next.auto_repeat(true);
      button_next.bounds({230, 460, 125, 40});
      button_next.anchor(anchor_styles::bottom | anchor_styles::right);
      button_next.image(button_images::next());
      button_next.image_align(content_alignment::middle_right);
      button_next.text(texts::next());
      button_next.click += [&] {
        if (current_image_index < images::names(choice_context.selected_item().value()).size()) ++current_image_index;
        update_form();
      };
      
      update_form();
    }
    
  private:
    void update_form() {
      picture.image(images::from_name(choice_theme.selected_item().value(), images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())) != drawing::image::empty ? images::from_name(choice_theme.selected_index() == 0 ? application::style_sheet().theme().name() : choice_theme.selected_item().value(), images::names(choice_context.selected_item().value())[current_image_index], any_cast<drawing::size>(choice_size.selected_item().tag())) : images::from_name("image-missing",  any_cast<drawing::size>(choice_size.selected_item().tag())));
      label_picture_name.text(images::names(choice_context.selected_item().value())[current_image_index]);
      button_previous.enabled(current_image_index > 0);
      button_next.enabled(current_image_index < images::names(choice_context.selected_item().value()).size() - 1);
    }
    
    size_t current_image_index = 0;
    choice choice_theme;
    choice choice_context;
    choice choice_size;
    picture_box picture;
    label label_picture_name;
    button button_previous;
    button button_next;
  };
}

auto main() -> int {
  application::run(example::form1 {});
}
