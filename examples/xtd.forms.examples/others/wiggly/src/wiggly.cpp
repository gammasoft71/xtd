#include <xtd/xtd>

namespace wiggly_example {
  class wiggly : public user_control {
  public:
    wiggly() {
      font({font(), font().size() + 12});
      timer.interval(60_ms);
      timer.tick += delegate_ {
        step++;
        invalidate();
      };
      timer.enabled(true);
    }
    
  protected:
    [[nodiscard]] auto default_back_color() const noexcept -> xtd::drawing::color override {return system_colors::window();}

    auto on_paint(paint_event_args& e) -> void override {
      static const auto sins = fixed_array {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      auto pos = point {(e.clip_rectangle().size().width - as<int>(e.graphics().measure_string(text(), font()).width)) / 2, (e.clip_rectangle().size().height - as<int>(e.graphics().measure_string(text(), font()).height)) / 2};
      e.graphics().clear(back_color());
      for (auto char_index = 0_z; const auto& c : text().to_u32string()) {
        auto sins_index = (step + char_index++) % sins.size();
        e.graphics().draw_string(string::format("{}", c), font(), solid_brush {color::from_hsv(360.0f / sins.size() * sins_index, 1.0f, 0.75f)}, point::subtract(pos, point(0, sins[sins_index] * font().height() / 400)));
        pos.x = pos.x + as<int>(e.graphics().measure_string(string::format("{}", c), font()).width);
      }
    }
    
  private:
    forms::timer timer;
    usize step = 0;
  };
  
  class form1 : public form {
  public:
    form1() {
      text("Wiggly");
      client_size({330, 130});
      controls().add_range({wiggly, text_box});
      
      text_box.location({20, 90});
      text_box.text_changed += delegate_ {
        wiggly.text(text_box.text());
      };
      text_box.text("Habemus papam");
      text_box.width(290);
      text_box.anchor(anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      text_box.focus();
      
      wiggly.bounds({20, 20, 290, 60});
      wiggly.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right | anchor_styles::bottom);
      wiggly.text(text_box.text());
    }
    
  private:
    forms::text_box text_box;
    wiggly_example::wiggly wiggly;
  };
}

auto main() -> int {
  application::run(wiggly_example::form1 {});
}
