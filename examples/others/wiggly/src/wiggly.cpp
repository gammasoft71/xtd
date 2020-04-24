#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class wiggly : public user_control {
  public:
    wiggly() {
      back_color(system_colors::window());
      timer.interval(60);
      timer.tick += [&] {
        step++;
        invalidate();
      };
      timer.enabled(true);
    }

  protected:
    void on_paint(paint_event_args& e) override {
      point pos((e.clip_rectangle().size().width() - static_cast<int>(e.graphics().measure_string(text(), font()).width())) / 2, (e.clip_rectangle().size().height() - static_cast<int>(e.graphics().measure_string(text(), font()).height())) / 2);
      for (auto i = 0; i < text().length(); i++) {
        auto index = (step + i) % sin.size();
        e.graphics().draw_string(strings::format("{}", text()[i]), font(), solid_brush(color::from_hsb(static_cast<float>(15 - index) * 16 / 255 * 360, 1.0f, 0.75f)), point(pos.x(), pos.y() + sin[index] * (e.clip_rectangle().height() - font().height()) / 400));
        pos.x(pos.x() + static_cast<int>(e.graphics().measure_string(strings::format("{}", text()[i]), font()).width()));
      }
    }
    
  private:
    forms::timer timer;
    const vector<int> sin = {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
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
        this->wiggly.text(text_box.text());
      };
      text_box.text("Habemus papam");
      text_box.width(290);
      text_box.anchor(anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      text_box.focus();
      
      wiggly.bounds({20, 20, 290, 60});
      wiggly.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right | anchor_styles::bottom);
      wiggly.font(drawing::font(wiggly.font(), 22.0f));
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
