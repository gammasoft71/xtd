#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/forms/form>
#include <xtd/diagnostics/debug>
#include <xtd/math>

namespace ball {
  class ball_form : public xtd::forms::form {
  public:
    //explicit ball_form(const xtd::drawing::size& size) {
    ball_form() {
      form_border_style(forms::form_border_style::none);
      double_buffered(true);
      
      // Radial gradient
      paint += [&](xtd::object& sender, xtd::forms::paint_event_args& e) {
        e.graphics().fill_rectangle(xtd::drawing::drawing_2d::radial_gradient_brush {xtd::drawing::point {e.clip_rectangle().width * 2 / 5, e.clip_rectangle().height * 35 /100}, {gradient_color2_, gradient_color1_}, e.clip_rectangle().width * 55_f / 100}, e.clip_rectangle());
      };
    }
    
    const xtd::drawing::color& gradient_color1() const noexcept {return gradient_color1_;}
    ball_form& gradient_color1(const xtd::drawing::color& value) noexcept {
      gradient_color1_ = value;
      return *this;
    }

    const xtd::drawing::color& gradient_color2() const noexcept {return gradient_color2_;}
    ball_form& gradient_color2(const xtd::drawing::color& value) noexcept {
      gradient_color2_ = value;
      return *this;
    }
    
    using xtd::forms::form::size;
    control& size(const xtd::drawing::size& value) override {
      form::size(value);
      recreate_handle();
      
      // Create a circular region
      xtd::drawing::drawing_2d::graphics_path path;
      path.add_ellipse(client_rectangle());
      region(xtd::drawing::region(path));
      return *this;
    }

  private:
    xtd::drawing::color gradient_color1_;
    xtd::drawing::color gradient_color2_;
  };
}
