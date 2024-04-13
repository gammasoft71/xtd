#include <xtd/diagnostics/process>
#include <xtd/forms/application>
#include <xtd/forms/choice>
#include <xtd/forms/form>
#include <xtd/forms/link_label>
#include "../properties/resources.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace form_background_image2 {
  class form1 : public form {
  public:
    form1() {
      background_image(application::dark_mode() ? properties::resources::bliss_night() : properties::resources::bliss_day());
      client_size({600, 450});
      controls().push_back_range({bliss_url, image_layout_choice});
      double_buffered(true);
      text("form with background image example 2");

      bliss_url.back_color(color::from_argb(64, system_colors::control()));
      bliss_url.dock(dock_style::bottom);
      bliss_url.text_align(xtd::forms::content_alignment::middle_center);
      bliss_url.text("MACOS BLISS");
      bliss_url.links().push_back({0, bliss_url.text().size(), "https://basicappleguy.com/basicappleblog/macosbliss"});
      bliss_url.link_clicked += [](object & sender, link_label_clicked_event_args & e) {
        e.visited(true);
        process::start(as<ustring>(e.link().link_data()));
      };

      for (auto [value, name] : enum_object<>::get_entries<xtd::forms::image_layout>())
        image_layout_choice.items().push_back({name, value});
      image_layout_choice.location({10, 10});
      image_layout_choice.selected_index_changed += [&] {
        background_image_layout(as<xtd::forms::image_layout>(image_layout_choice.selected_item().tag()));
      };
      image_layout_choice.selected_index(0);
    }

  protected:
    void on_system_colors_changed(const event_args &e) {
      form::on_system_colors_changed(e);
      background_image(application::dark_mode() ? properties::resources::bliss_night() : properties::resources::bliss_day());
      bliss_url.back_color(color::from_argb(64, system_colors::control()));
    }

  private:
    link_label bliss_url;
    choice image_layout_choice;
  };
}

auto main()->int {
  application::run(::form_background_image2::form1 {});
}
