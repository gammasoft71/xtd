#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Button renderer example");
      client_size({400, 300});
      set_color(color::blue);
      set_color(nullptr);

      choice_theme.parent(*this);
      choice_theme.location({10, 10});
      choice_theme.items().push_back("default theme");
      choice_theme.items().push_back_range(theme::theme_names());
      choice_theme.selected_index(0);
      choice_theme.selected_index_changed += [&] {
        application::theme(choice_theme.selected_index() == 0 ? theme::default_theme_name() : choice_theme.selected_item().value());
        color_picker_background.color(back_color());
        color_picker_foreground.color(fore_color());
        bcolor.reset();
        fcolor.reset();
        button_system.back_color(nullptr);
        button_system.fore_color(nullptr);
        button_standard.back_color(nullptr);
        button_standard.fore_color(nullptr);
      };
      
      color_picker_background.parent(*this);
      color_picker_background.location({140, 10});
      color_picker_background.color(back_color());
      color_picker_background.color_changed += [&] {
        bcolor = color_picker_background.color();
        button_system.back_color(bcolor.value());
        button_standard.back_color(bcolor.value());
      };
      
      color_picker_foreground.parent(*this);
      color_picker_foreground.location({250, 10});
      color_picker_foreground.color(fore_color());
      color_picker_foreground.color_changed += [&] {
        fcolor = color_picker_foreground.color();
        button_system.fore_color(fcolor.value());
        button_standard.fore_color(fcolor.value());
      };

      button_system.parent(*this);
      button_system.flat_style(xtd::forms::flat_style::system);
      button_system.location({10, 170});
      button_system.text("System");

      button_standard.parent(*this);
      button_standard.location({100, 170});
      button_standard.text("Standard");
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      button_renderer::draw_button(e.graphics(), {10, 70, 75, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {100, 70, 75, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {190, 70, 75, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {10, 110, 75, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {100, 110, 75, 25}, "Default", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, bcolor, fcolor);
    }

  private:
    void set_color(const color& color) {
      cdebug << format("color = {}", color.to_string()) << endl;
    }
    void set_color(nullptr_t) {
      cdebug << "color = (nullptr)" << endl;
    }
    optional<color> bcolor;
    optional<color> fcolor;
    choice choice_theme;
    color_picker color_picker_background;
    color_picker color_picker_foreground;
    button button_system;
    button button_standard;
  };
}

int main() {
  application::run(examples::form1());
}
