#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/button_renderer>
#include <xtd/forms/choice>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/cdebug>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace button_renderer_example {
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
      auto names = application::style_sheet_names();
      sort(names.begin(), names.end());
      choice_theme.items().push_back_range(names);
      choice_theme.selected_index(0);
      choice_theme.selected_index_changed += [&] {
        application::style_sheet(choice_theme.selected_index() == 0 ? application::system_style_sheet() : application::get_style_sheet_from_name(choice_theme.selected_item().value()));
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
      color_picker_background.location({180, 10});
      color_picker_background.color(back_color());
      color_picker_background.color_picker_changed += [&] {
        bcolor = color_picker_background.color();
        button_system.back_color(bcolor.value());
        button_standard.back_color(bcolor.value());
      };
      
      color_picker_foreground.parent(*this);
      color_picker_foreground.location({290, 10});
      color_picker_foreground.color(fore_color());
      color_picker_foreground.color_picker_changed += [&] {
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
      button_renderer::draw_button(e.graphics(), {10, 70, 75, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {100, 70, 75, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {190, 70, 75, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {10, 110, 75, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, bcolor, fcolor);
      button_renderer::draw_button(e.graphics(), {100, 110, 75, 25}, "Default", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, bcolor, fcolor);
    }
    
  private:
    void set_color(const color& color) {
      cdebug << ustring::format("color = {}", color.to_string()) << endl;
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

auto main() -> int {
  application::run(button_renderer_example::form1 {});
}
