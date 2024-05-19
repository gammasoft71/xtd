#include <xtd/drawing/basic_colors>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/random>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace draw_point_example {
  class form1 : public form {
    struct colored_point {
      point location;
      xtd::drawing::color color;
      int width = 0;
    };
    
  public:
    form1() {
      text("Draw point example");
      
      generate_colored_points_timer.interval(200_ms);
      generate_colored_points_timer.tick += event_handler {*this, &form1::generate_colored_points};
      generate_colored_points_timer.start();
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      form::on_paint(e);
      e.graphics().clear(color::black);
      for (auto colored_point : colored_points)
        e.graphics().draw_point(pen(colored_point.color, as<float>(colored_point.width)), colored_point.location);
    }
    
  private:
    void generate_colored_points() {
      static auto random = xtd::random {};
      static auto colors = basic_colors::get_colors();
      colored_points.resize(random.next(height() * width() / 800, height() * width() / 400));
      for (auto& colored_point : colored_points)
        colored_point = {{random.next(client_size().width()), random.next(client_size().height())}, colors[random.next(colors.size())], random.next(1, 10)};
      invalidate();
    }
    
    vector<colored_point> colored_points;
    timer generate_colored_points_timer;
  };
}

auto main() -> int {
  application::run(draw_point_example::form1 {});
}
