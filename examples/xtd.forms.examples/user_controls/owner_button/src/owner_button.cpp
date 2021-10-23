#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class owner_button : public button {
  public:
    void on_paint(paint_event_args& e) {
      auto background_color = back_color_.has_value() ? back_color_.value() : xtd::forms::theme_colors::current_theme().control();
      auto foreground_color = fore_color_.has_value() ? fore_color_.value() : xtd::forms::theme_colors::current_theme().control_text();
      auto button_color = control_paint::light(background_color, .05);
      auto border_color = control_paint::light(background_color, .15);
      auto text_color = foreground_color;
      
      if (state() == xtd::forms::visual_styles::push_button_state::hot) {
        border_color = control_paint::light(border_color, .15);
        button_color = control_paint::light(background_color, .15);
        text_color = control_paint::light(foreground_color, .15);
      } else if (state() == xtd::forms::visual_styles::push_button_state::pressed || state() == xtd::forms::visual_styles::push_button_state::checked) {
        border_color = control_paint::light(border_color, .30);
        button_color = control_paint::light(background_color, .30);
        text_color = control_paint::light(foreground_color, .30);
      } else if (state() == xtd::forms::visual_styles::push_button_state::disabled) {
        border_color = color::from_argb(85, 85, 55);
        text_color = xtd::forms::theme_colors::current_theme().gray_text();
      } else if (state() == xtd::forms::visual_styles::push_button_state::default_state) {
        border_color = control_paint::light(border_color, .15);
        button_color = control_paint::light(background_color, .15);
        text_color = control_paint::light(foreground_color, .15);
      }
      
      e.graphics().fill_rounded_rectangle(drawing2d::linear_gradient_brush(point {e.clip_rectangle().x(), e.clip_rectangle().top()}, point {e.clip_rectangle().x(), e.clip_rectangle().bottom()}, control_paint::light(button_color, .1), control_paint::dark(button_color)), e.clip_rectangle().x(), e.clip_rectangle().y(), e.clip_rectangle().width(), e.clip_rectangle().height(), e.clip_rectangle().height() / 2);
      e.graphics().draw_rounded_rectangle(pen(border_color, 1), e.clip_rectangle().x(), e.clip_rectangle().y(), e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1, e.clip_rectangle().height() / 2);
      e.graphics().draw_string(text(), font(), solid_brush(text_color), rectangle(e.clip_rectangle().x() + 5, e.clip_rectangle().y() + 3, e.clip_rectangle().width() - 10, e.clip_rectangle().height() - 7), string_format().alignment(xtd::drawing::string_alignment::center).line_alignment(xtd::drawing::string_alignment::center));
    }
  };

  class form1 : public form {
  public:
    form1() {
      owner_button1.location({145, 25});
      owner_button2.size({80, 25});
      owner_button1.text("Button 1");
      
      owner_button2.location({105, 70});
      owner_button2.size({160, 50});
      owner_button2.back_color(color::red);
      owner_button2.fore_color(color::white);
      owner_button2.text("Button 2");
      
      owner_button3.location({25, 145});
      owner_button3.size({320, 100});
      owner_button3.back_color(color::blue);
      owner_button3.fore_color(color::white);
      owner_button3.text("Button 3");

      text("Owner button example");
      client_size({370, 270});
      controls().push_back_range({owner_button1, owner_button2, owner_button3});
    }
    
  private:
    owner_button owner_button1;
    owner_button owner_button2;
    owner_button owner_button3;
  };
}

int main() {
  application::run(examples::form1());
}
