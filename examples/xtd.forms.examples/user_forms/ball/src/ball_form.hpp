#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/forms/form>
#include <xtd/diagnostics/debug>
#include <xtd/math>

namespace ball {
  /// @brief Represents the ball forms.
  /// @remarks The ball has two colors:
  ///  * ball::ball_form::color which represents the color of the ball.
  ///  * ball::ball_form::gradient_color2 which represents the color of the ball's light point to create a 3D effect.
  class ball_form : public xtd::forms::form {
  public:
    /// @name Public Constructors
    
    /// @{
    ball_form() {
      form_border_style(forms::form_border_style::none);
      double_buffered(true);      
      size({300, 300});

      // Radial gradient
      paint += [&](xtd::object& sender, xtd::forms::paint_event_args& e) {
        e.graphics().fill_rectangle(xtd::drawing::drawing_2d::radial_gradient_brush {xtd::drawing::point {e.clip_rectangle().width * 2 / 5, e.clip_rectangle().height * 35 /100}, {light_point_color_, color_}, e.clip_rectangle().width * 55_f / 100}, e.clip_rectangle());
      };
    }
    /// @)
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the color of the ball.
    /// @return The color ball.
    const xtd::drawing::color& color() const noexcept {return color_;}
    /// @brief Sets the color of the ball.
    /// @param value The color of the ball.
    /// @return This current instance.
    ball_form& color(const xtd::drawing::color& value) noexcept {
      color_ = value;
      return *this;
    }

    /// @brief Gets the color of the ball's light point to create a 3D effect.
    /// @return The the color of the ball's light point.
    const xtd::drawing::color& light_point_color() const noexcept {return light_point_color_;}
    /// @brief Sets the color of the ball's light point to create a 3D effect
    /// @param value Thethe color of the ball's light point.
    /// @return This current instance.
    ball_form& light_point_color(const xtd::drawing::color& value) noexcept {
      light_point_color_ = value;
      return *this;
    }
    
    /// @brief Gets the height and width of the ball.
    /// @return The size that represents the height and width of the ball in pixels.
    xtd::drawing::size size() const noexcept override {return client_size();}
    /// @brief Gets the height and width of the ball.
    /// @param value The size that represents the height and width of the ball in pixels.
    /// @return This current instance.
    control& size(const xtd::drawing::size& value) override {
      if (client_size() == value) return *this;
      client_size(value);
      
      // Create a circular region
      xtd::drawing::drawing_2d::graphics_path path;
      path.add_ellipse(client_rectangle());
      region(xtd::drawing::region(path));
      return *this;
    }
    /// @)

  private:
    xtd::drawing::color color_;
    xtd::drawing::color light_point_color_;
  };
}
