#include <filesystem>
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::diagnostics;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      back_color(color::dark_cyan);
      client_size({360, 280});
      controls().push_back(fish_animation);
      fore_color(color::cyan);
      text("Animation example");

      fish_animation.dock(dock_style::fill);
      fish_animation.frames_per_second(60);
      fish_animation.start();
      fish_animation.click += event_handler(*this, &form1::on_fish_animation_click);
      fish_animation.paint += paint_event_handler(*this, &form1::on_fish_animation_paint);
      fish_animation.updated += animation_updated_event_handler(*this, &form1::on_fish_animation_updated);
    }
    
  private:
    void on_fish_animation_click(object& sender, const event_args& e) {
      if (fish_animation.is_running()) fish_animation.stop();
      else fish_animation.start();
    }
    
    void on_fish_animation_paint(object& sender, paint_event_args& e) {
      e.graphics().clear(fish_animation.back_color());
      static const int fish_length = 16;
      for (auto i = 0; i < fish_length; ++i) {
        auto radius = 100 + 10 * std::sin(static_cast<float>(fish_animation.frame_counter()) * 0.1f + static_cast<float>(i) * 0.5f);
        auto point = point_f(static_cast<float>(e.clip_rectangle().width()) / 2.0f + 1.5f * radius * std::sin(static_cast<float>(fish_animation.frame_counter()) * 0.02f + static_cast<float>(i) * 0.12f), static_cast<float>(e.clip_rectangle().height()) / 2.0f + 1.0f * radius * std::cos(static_cast<float>(fish_animation.frame_counter()) * 0.04f + static_cast<float>(i) * 0.12f));
        e.graphics().fill_ellipse(solid_brush(fish_animation.fore_color()), point.x() - static_cast<float>(i), point.y() - static_cast<float>(i), 2.0f + 2.0f * static_cast<float>(i), 2.0f + 2.0f * static_cast<float>(i));
      }
    }
    
    void on_fish_animation_updated(object& sender, const animation_updated_event_args& e) {
      debug::write_line(strings::format("frame_counter={}, elapsed_milliseconds={}", e.frame_counter(), e.elapsed_milliseconds()));
    }

    animation fish_animation;
  };
}

int main() {
  application::run(examples::form1());
}
