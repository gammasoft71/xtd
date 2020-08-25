#include <xtd/xtd.forms>

using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      text("Button renderrer example");
      client_size({400, 300});
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      button_renderrer::draw_button(e.graphics(), {10, 10, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, back_color(), fore_color());
      button_renderrer::draw_button(e.graphics(), {10, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, back_color(), fore_color());
      button_renderrer::draw_button(e.graphics(), {10, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, back_color(), fore_color());
      button_renderrer::draw_button(e.graphics(), {10, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, back_color(), fore_color());
      button_renderrer::draw_button(e.graphics(), {10, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, back_color(), fore_color());
      
      button_renderrer::draw_button(e.graphics(), {100, 10, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {100, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {100, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {100, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {100, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(229, 229, 229), xtd::drawing::color::from_argb(0, 0, 0));
      
      button_renderrer::draw_button(e.graphics(), {190, 10, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(75, 0, 130), fore_color());
      button_renderrer::draw_button(e.graphics(), {190, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(75, 0, 130), fore_color());
      button_renderrer::draw_button(e.graphics(), {190, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(75, 0, 130), fore_color());
      button_renderrer::draw_button(e.graphics(), {190, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(75, 0, 130), fore_color());
      button_renderrer::draw_button(e.graphics(), {190, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(75, 0, 130), fore_color());
      
      button_renderrer::draw_button(e.graphics(), {280, 10, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::normal, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {280, 40, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::hot, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {280, 70, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::pressed, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {280, 100, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::disabled, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
      button_renderrer::draw_button(e.graphics(), {280, 130, 75, 25}, "Click me", font(), xtd::forms::text_format_flags::default_format, xtd::drawing::image::empty, {0, 0, 0, 0}, false, xtd::forms::visual_styles::push_button_state::default_state, xtd::drawing::color::from_argb(144, 238, 144), xtd::drawing::color::from_argb(0, 0, 0));
    }
  };
}

int main() {
  application::enable_button_images();
  application::run(examples::form1());
}
