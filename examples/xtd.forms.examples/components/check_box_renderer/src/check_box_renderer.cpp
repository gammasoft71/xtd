#include <xtd/forms/application>
#include <xtd/forms/check_box>
#include <xtd/forms/check_box_renderer>
#include <xtd/forms/choice>
#include <xtd/forms/color_picker>
#include <xtd/forms/form>
#include <xtd/cdebug>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace check_box_renderer_example {
  class form1 : public form {
  public:
    form1() {
      text("Check box renderer example");
      client_size({500, 300});
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
        check_box_system.back_color(nullptr);
        check_box_system.fore_color(nullptr);
        check_box_standard.back_color(nullptr);
        check_box_standard.fore_color(nullptr);
      };
      
      color_picker_background.parent(*this);
      color_picker_background.location({180, 10});
      color_picker_background.color(back_color());
      color_picker_background.color_picker_changed += [&] {
        bcolor = color_picker_background.color();
        check_box_system.back_color(bcolor.value());
        check_box_standard.back_color(bcolor.value());
      };
      
      color_picker_foreground.parent(*this);
      color_picker_foreground.location({290, 10});
      color_picker_foreground.color(fore_color());
      color_picker_foreground.color_picker_changed += [&] {
        fcolor = color_picker_foreground.color();
        check_box_system.fore_color(fcolor.value());
        check_box_standard.fore_color(fcolor.value());
      };
      
      check_box_system.parent(*this);
      check_box_system.flat_style(xtd::forms::flat_style::system);
      check_box_system.location({10, 210});
      check_box_system.text("System");
      check_box_system.three_state(true);
      
      check_box_standard.parent(*this);
      check_box_standard.location({100, 210});
      check_box_standard.text("Standard");
      check_box_standard.three_state(true);
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      check_box_renderer::draw_check_box(e.graphics(), {10, 70, 104, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::unchecked_normal, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {124, 70, 104, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::unchecked_hot, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {238, 70, 104, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::unchecked_pressed, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {352, 70, 104, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::unchecked_disabled, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {10, 110, 104, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::checked_normal, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {124, 110, 104, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::checked_hot, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {238, 110, 104, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::checked_pressed, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {352, 110, 104, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::checked_disabled, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {10, 150, 104, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::mixed_normal, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {124, 150, 104, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::mixed_hot, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {238, 150, 104, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::mixed_pressed, bcolor, fcolor);
      check_box_renderer::draw_check_box(e.graphics(), {352, 150, 104, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center | xtd::forms::text_format_flags::left, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::check_box_state::mixed_disabled, bcolor, fcolor);
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
    check_box check_box_system;
    check_box check_box_standard;
  };
}

auto main() -> int {
  application::run(check_box_renderer_example::form1 {});
}
