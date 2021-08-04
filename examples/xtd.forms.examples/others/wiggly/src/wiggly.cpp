#include <xtd/xtd>

using namespace std;
using namespace std::literals;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class wiggly : public user_control {
  public:
    wiggly() {
      back_color(system_colors::window());
      font({font(), font().size() + 12});
      timer.interval(60ms);
      timer.tick += [&] {
        step++;
        invalidate();
      };
      timer.enabled(true);
    }

  protected:
    void on_paint(paint_event_args& e) override {
      static const vector sins = {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
      auto pos = point {(e.clip_rectangle().size().width() - static_cast<int>(e.graphics().measure_string(text(), font()).width())) / 2, (e.clip_rectangle().size().height() - static_cast<int>(e.graphics().measure_string(text(), font()).height())) / 2};
      for (auto i = 0U; i < wiggly_text.length(); i++) {
        auto index = (step + i) % sins.size();
        e.graphics().draw_string(ustring::format("{}", wiggly_text[i]), font(), solid_brush {color::from_hsb(360.0f / sins.size() * index, 1.0f, 0.75f)}, point::subtract(pos, point(0, sins[index] * font().height() / 400)));
        pos.x(pos.x() + static_cast<int>(e.graphics().measure_string(ustring::format("{}", wiggly_text[i]), font()).width()));
      }
    }
    
    void on_text_changed(const event_args& e) override {
      user_control::on_text_changed(e);
      wiggly_text = convert_string::to_u32string(text());
    }

  private:
    forms::timer timer;
    u32string wiggly_text;
    int step = 0;
  };

  class form1 : public form {
  public:
    form1() {
      text("Wiggly");
      client_size({330, 130});
      controls().push_back_range({wiggly, text_box});
      
      text_box.location({20, 90});
      text_box.text_changed += [&] {
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
    examples::wiggly wiggly;
  };
}

int main() {
  application::run(examples::form1());
}
