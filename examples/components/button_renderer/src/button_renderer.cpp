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
      choice_theme.items().push_back_range(theme::theme_names());
      choice_theme.selected_index_changed += [&] {
        theme = choice_theme.selected_item().value();
        invalidate();
      };
      choice_theme.selected_index(0);
      
      color_picker_background.parent(*this);
      color_picker_background.location({190, 10});
      color_picker_background.color(back_color());
      color_picker_background.color_changed += [&] {
        back_color(color_picker_background.color());
      };
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      button_renderer::draw_button(theme, e.graphics(), {10, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, back_color(), fore_color());
      button_renderer::draw_button(theme, e.graphics(), {10, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, back_color(), fore_color());
      button_renderer::draw_button(theme, e.graphics(), {10, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, back_color(), fore_color());
      button_renderer::draw_button(theme, e.graphics(), {10, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, back_color(), fore_color());
      button_renderer::draw_button(theme, e.graphics(), {10, 160, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, back_color(), fore_color());
      
      button_renderer::draw_button(theme, e.graphics(), {100, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {100, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {100, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {100, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {100, 160, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      
      button_renderer::draw_button(theme, e.graphics(), {190, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(75, 0, 160), xtd::drawing::color::white);
      button_renderer::draw_button(theme, e.graphics(), {190, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(75, 0, 160), xtd::drawing::color::white);
      button_renderer::draw_button(theme, e.graphics(), {190, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(75, 0, 160), xtd::drawing::color::white);
      button_renderer::draw_button(theme, e.graphics(), {190, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(75, 0, 160), xtd::drawing::color::white);
      button_renderer::draw_button(theme, e.graphics(), {190, 160, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(75, 0, 160), xtd::drawing::color::white);
      
      button_renderer::draw_button(theme, e.graphics(), {280, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {280, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {280, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {280, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderer::draw_button(theme, e.graphics(), {280, 160, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::vertical_center|xtd::forms::text_format_flags::horizontal_center, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
    }

  private:
    choice choice_theme;
    color_picker color_picker_background;
    std::string theme;
  };
}

int main() {
  application::run(examples::form1());
}
