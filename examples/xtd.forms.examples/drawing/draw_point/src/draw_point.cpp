#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class form1 : public form {
    struct colored_point {
      point location;
      xtd::drawing::color color;
      int width;
    };
    
  public:
    form1() {
      text("Draw point example");
      
      generate_colored_points_timer.interval_milliseconds(100);
      generate_colored_points_timer.tick += event_handler(*this, &form1::generate_colored_points);
      generate_colored_points_timer.start();
    }
    
  protected:
    void on_paint(paint_event_args& e) override {
      e.graphics().clear(color::black);
      for (auto colored_point : colored_points)
        e.graphics().draw_point(pen(colored_point.color, colored_point.width), colored_point.location);
      form::on_paint(e);
    }
    
  private:
    void generate_colored_points() {
      static xtd::random random;
      static vector colors = {color::red, color::green, color::blue, color::yellow, color::cyan, color::magenta, color::white};
      colored_points.resize(random.next(height() * width() / 600, height() * width() / 300));
      for (auto& colored_point : colored_points)
        colored_point = {point(random.next(client_size().width()), random.next(client_size().height())), colors[random.next(colors.size())], random.next(1, 5)};
      invalidate();
    }
    
    vector<colored_point> colored_points;
    timer generate_colored_points_timer;
  };
}

int main() {
  application::run(examples::form1());
}
