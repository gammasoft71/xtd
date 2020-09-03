#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Button renderrer example");
      client_size({400, 300});
      
      choice_theme.parent(*this);
      choice_theme.location({10, 10});
      choice_theme.items().push_back("default theme");
      choice_theme.items().push_back_range(theme::theme_names());
      choice_theme.selected_index_changed += [&] {
        auto theme = choice_theme.selected_index() == 0 ? theme::default_theme_name() : choice_theme.selected_item().value();
        theme::current_theme(theme);
        invalidate(true);
      };
      choice_theme.selected_index(0);
      
      color_picker_background.parent(*this);
      color_picker_background.location({190, 10});
      color_picker_background.color(back_color());
      color_picker_background.color_changed += [&] {
        back_color(color_picker_background.color());
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
      button_renderer::draw_button(e.graphics(), {10, 50, 75, 25}, "Normal", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, back_color(), fore_color());
      button_renderer::draw_button(e.graphics(), {100, 50, 75, 25}, "Hot", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, back_color(), fore_color());
      button_renderer::draw_button(e.graphics(), {190, 50, 75, 25}, "Pressed", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, back_color(), fore_color());
      button_renderer::draw_button(e.graphics(), {10, 90, 75, 25}, "Disabled", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, back_color(), fore_color());
      button_renderer::draw_button(e.graphics(), {100, 90, 75, 25}, "Default", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, back_color(), fore_color());
    }

  private:
    choice choice_theme;
    color_picker color_picker_background;
    button button_system;
    button button_standard;
  };
}

int main() {
  application::run(examples::form1());
}
