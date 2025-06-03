#include "ball.hpp"
#include "../properties/resources.hpp"
#include "../properties/settings.hpp"
#include <xtd/drawing/color_converter>
#include <xtd/drawing/texts>
#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/math>
#include <xtd/startup>

using namespace ball;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;

void main_form::main() {
  application::run(main_form());
}

main_form::main_form() {
  color(properties::settings::default_settings().color());
  light_point_color(properties::settings::default_settings().light_point_color());
  color(color::indigo);
  light_point_color(color_converter::light(color(), 0.66));
  size(properties::settings::default_settings().size());

  //context_menu(context_menu_);
  icon(properties::resources::ball_ico());
  start_position(form_start_position::manual);
  auto working_area = screen::from_control(*this).working_area();
  location({working_area.left() + working_area.width / 2 - size().width / 2, working_area.bottom() - size().height});
  top_most(true);
  
  // Inertia animation + bounces
  const auto fps = 60;
  animation_timer_.interval_milliseconds(1000 / fps);
  animation_timer_.tick += {*this, &main_form::on_animation_timer_tick};

  main_panel_.context_menu(context_menu_);
  main_panel_.parent(*this);
  main_panel_.dock(xtd::forms::dock_style::fill);
  main_panel_.mouse_down += [&](object& sender, const mouse_event_args& e) {on_mouse_down(e);};
  main_panel_.mouse_up += [&](object& sender, const mouse_event_args& e) {on_mouse_up(e);};
  main_panel_.mouse_move += [&](object& sender, const mouse_event_args& e) {on_mouse_move(e);};
}

void main_form::on_mouse_down(const xtd::forms::mouse_event_args& e) {
  form::on_mouse_down(e);
  
  if (is_dragging_ || e.button() == mouse_buttons::right) return;
  is_dragging_ = true;
  velocity = {0, 0}; // stop animation
  mouse_location_ = e.location();
  cursor(cursors::hand());
  animation_timer_.enabled(false);
}

void main_form::on_mouse_move(const xtd::forms::mouse_event_args& e) {
  form::on_mouse_move(e);
  
  if (!is_dragging_) return;
  auto new_location = bounds().location() + (e.location() - mouse_location_);
  auto working_area = screen::from_control(*this).working_area();
  new_location.x = math::clamp(new_location.x, working_area.left(), working_area.right() - width());
  new_location.y = math::clamp(new_location.y, working_area.top(), working_area.bottom() - height());
  location(new_location);
  
  last_mouse_move_location_ = e.location(); // to estimate speed
}

void main_form::on_mouse_up(const xtd::forms::mouse_event_args& e) {
  form::on_mouse_up(e);

  if (!is_dragging_ || e.button() == mouse_buttons::right) return;
  is_dragging_ = false;
  cursor(cursors::default_cursor());
  
  // Calculates release speed (diff between last 2 points)
  velocity = e.location() - last_mouse_move_location_;
  animation_timer_.enabled(true);
}

void main_form::on_animation_timer_tick(object& sender, const event_args& e) {
  const auto gravity = 0.5f;
  const auto friction = 0.98f;
  const auto bounce = 0.6f;
  
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
    animation_timer_.enabled(false);
}
 
void main_form::on_exit_menu_item_click(xtd::object& sender, const xtd::event_args& e) {
  main_form::close();
}

void main_form::on_settings_menu_item_click(xtd::object& sender, const xtd::event_args& e) {
  settings_form_.show();;
}
