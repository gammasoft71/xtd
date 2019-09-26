#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
  public:
    form1() {
      this->text("Wiggly");
      this->client_size({330, 130});
      this->controls().push_back_range({this->panel, this->text_box});

      this->panel.bounds({20, 20, 290, 60});
      this->panel.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right | anchor_styles::bottom);
      this->panel.back_color(system_colors::window());
      this->panel.font(drawing::font(this->panel.font().name(), 22.0f));
      this->panel.paint += {*this, &form1::on_panel_paint};
      
      this->text_box.location({20, 90});
      this->text_box.text("Hello, World!");
      this->text_box.width(290);
      this->text_box.anchor(anchor_styles::left | anchor_styles::bottom | anchor_styles::right);

      this->timer.interval(60);
      this->timer.tick += {*this, &form1::on_timer};
      this->timer.enabled(true);
    }
    
  private:
    void on_panel_paint(const control& sender, paint_event_args& e) {
      point pos((e.clip_rectangle().size().width() - (int)e.graphics().measure_string(this->text_box.text(), this->panel.font()).width()) / 2, (e.clip_rectangle().size().height() - (int)e.graphics().measure_string(this->text_box.text(), this->panel.font()).height()) / 2);
      for (int i = 0; i < this->text_box.text().length(); i++) {
        int index = (this->step + i) % sin.size();
        e.graphics().draw_string(strings::format("{}", this->text_box.text()[i]), this->panel.font(), solid_brush(color::from_hsb((float)(15 - index) * 16 / 255 * 360, 1.0f, 0.75f)), point(pos.x(), pos.y() + sin[index] * (e.clip_rectangle().height() - this->panel.font().height()) / 400));
        pos.x(pos.x() + (int)e.graphics().measure_string(strings::format("{}", this->text_box.text()[i]), this->panel.font()).width());
      }
    }
    
    void on_timer() {
      this->step++;
      this->refresh();
    }
    
    forms::panel panel;
    forms::text_box text_box;
    forms::timer timer;
    const vector<int> sin = {0, 38, 71, 92, 100, 92, 71, 38, 0, -38, -71, -92, -100, -92, -71, -38};
    int step = 0;
  };
}

int main() {
  application::run(examples::form1());
}
