#include <xtd/xtd>

namespace animation_example {
  class form1 : public form {
  public:
    form1() {
      text("Animation example").client_size({800, 600}).controls().add(fish_animation);
      
      fish_animation.frames_per_second(60).dock(dock_style::fill);
      fish_animation.start();
      fish_animation.click += [](object& sender, const event_args& e) {as<animation>(sender).running(!as<animation>(sender).running());};
      fish_animation.updated += [](object& sender, const animation_updated_event_args& e){diagnostics::debug::write_line("frame_counter = {}, elapsed = {}", e.frame_counter(), e.elapsed());};
      fish_animation.paint += [](object& sender, paint_event_args& e) {
        e.graphics().clear(basic_colors::teal());
        static const auto fish_length = 15;
        auto points = list<point_f> {};
        for (auto index = 0; index < fish_length; ++index) {
          auto radius = e.clip_rectangle().width / 4.0 + 10.0 * math::sin(as<animation>(sender).frame_counter() * 0.1 + index * 0.5);
          auto x = as<float>(e.clip_rectangle().width / 2.0 + 1.5 * radius * math::sin(as<animation>(sender).frame_counter() * 0.02 + index * 0.12));
          auto y = as<float>(e.clip_rectangle().height / 2.0 + 1.0 * radius * math::cos(as<animation>(sender).frame_counter() * 0.04 + index * 0.12f));
          e.graphics().fill_ellipse(brushes::aqua(), x - index, y - index, 2.0f + 2.0f * index, 2.0f + 2.0f * index);
          points.add({x, y});
        }
        e.graphics().draw_beziers(pens::aqua(4), points.to_array());
      };
    }
    
  private:
    animation fish_animation;
  };
}

auto main() -> int {
  application::run(animation_example::form1 {});
}
