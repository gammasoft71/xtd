#include <xtd/drawing/drawing_2d/radial_gradient_brush>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/math>
#include <xtd/startup>
#include "../properties/resources.hpp"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

namespace circular_form {
  class form_main : public form {
  public:
    static auto main() {
      application::run(form_main());
    }
    
    form_main() {
      icon(properties::resources::ball_ico());
      form_border_style(forms::form_border_style::none);
      start_position(form_start_position::manual);
      client_size({200, 200});
      double_buffered(true);
      location({screen::from_control(*this).working_area().left() + screen::from_control(*this).working_area().width / 2 - client_size().width / 2, screen::from_control(*this).working_area().bottom() - client_size().height});
      top_most(true);
      
      // Create a circular region
      graphics_path path;
      path.add_ellipse(client_rectangle());
      region(drawing::region(path));
      
      // Radial gradient
      paint += [&](object& sender, paint_event_args& e) {
        auto gradient_color1 = color::from_argb(0xBC, 0, 0);
        auto gradient_color2 = color::from_argb(0xFF, 0xAA, 0x7E);
        e.graphics().fill_rectangle(radial_gradient_brush {point {80, 70}, {gradient_color2, gradient_color1}, 110}, e.clip_rectangle());
      };
      
      // Mouse tracking
      mouse_down += [&](object& sender, const mouse_event_args& e) {
        if (is_dragging || e.button() == mouse_buttons::right) return;
        is_dragging = true;
        velocity = {0, 0}; // stop animation
        mouse_location = e.location();
        cursor(cursors::hand());
        animation_timer.enabled(false);
      };
      
      mouse_up += [&](object& sender, const mouse_event_args& e) {
        if (!is_dragging || e.button() == mouse_buttons::right) return;
        is_dragging = false;
        cursor(cursors::default_cursor());
        
        // Calculates release speed (diff between last 2 points)
        velocity = e.location() - last_mouse_move_location;
        animation_timer.enabled(true);
      };
      
      mouse_move += [&](object& sender, const mouse_event_args& e) {
        if (!is_dragging) return;
        auto new_location = bounds().location() + (e.location() - mouse_location);
        auto working_area = screen::from_control(*this).working_area();
        new_location.x = math::clamp(new_location.x, working_area.left(), working_area.right() - width());
        new_location.y = math::clamp(new_location.y, working_area.top(), working_area.bottom() - height());
        location(new_location);
        
        last_mouse_move_location = e.location(); // to estimate speed
      };
      
      // Animation inertie + rebonds
      animation_timer.interval(16_ms); // ~60 FPS
      animation_timer.tick += [&] {
        auto bounds = this->bounds();
        auto working_area = screen::from_control(*this).working_area();
        
        // Simple physics
        velocity.y = velocity.y + gravity;         // gravity
        velocity.x = velocity.x * friction;        // horizontal friction
        velocity.y = velocity.y * friction;        // vertical friction
        
        bounds.location(bounds.location() + point::truncate(velocity));
        
        // Low screen bounce
        if (bounds.bottom() >= working_area.bottom()) {
          bounds.y = working_area.bottom() - bounds.height;
          velocity.y = -velocity.y * bounce; // rebond avec perte
        }
        
        // Bounce sides
        if (bounds.left() < working_area.left()) {
          bounds.x = working_area.left();
          velocity.x = -velocity.x * bounce;
        } else if (bounds.right() > working_area.right()) {
          bounds.x = working_area.right() - bounds.width;
          velocity.x = -velocity.x * bounce;
        }
        
        location(bounds.location());
        
        // Stop if almost still
        if (math::abs(velocity.x) < 0.1 && math::abs(velocity.y) < 0.5 && bounds.bottom() >= working_area.bottom())
          animation_timer.enabled(false);
      };
    }
    
  private:
    point mouse_location = point::empty;
    point last_mouse_move_location = point::empty;
    drawing::point_f velocity = {0, 0};
    
    forms::timer animation_timer;
    bool is_dragging = false;
    
    const float gravity = 0.5f;
    const float friction = 0.98f;
    const float bounce = 0.6f;
  };
}
startup_(circular_form::form_main::main);
