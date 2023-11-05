#include <xtd/drawing/system_colors>
#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/loading_indicators>

using namespace xtd::forms;

namespace loading_indicators_example {
  class form1 : public form {
  public:
    form1() {
      text("Loading indicatorss example");
      fore_color(xtd::drawing::system_colors::accent());
      
      mouse_click += [&](object& sender, const mouse_event_args& e) {
        for (auto item : {&loading_indicator1, &loading_indicator2, &loading_indicator3, &loading_indicator4, &loading_indicator5, &loading_indicator6, &loading_indicator7, &loading_indicator8, &loading_indicator9, &loading_indicator10, &loading_indicator11, &loading_indicator12, &loading_indicator13}) {
          if (e.button() == xtd::forms::mouse_buttons::left) item->running(!item->running());
          if (e.button() == xtd::forms::mouse_buttons::right) item->enabled(!item->enabled());
        }
      };
    }
    
  private:
    loading_indicator loading_indicator1 = loading_indicators::system(*this, {10, 10}, {32, 32});
    loading_indicator loading_indicator2 = loading_indicators::circle_bars(*this, {50, 10});
    loading_indicator loading_indicator3 = loading_indicators::circle_blinks(*this, {90, 10});
    loading_indicator loading_indicator4 = loading_indicators::five_lines(*this, {130, 10});
    loading_indicator loading_indicator5 = loading_indicators::five_lines_center(*this, {170, 10});
    loading_indicator loading_indicator6 = loading_indicators::five_lines_chronological(*this, {210, 10});
    loading_indicator loading_indicator7 = loading_indicators::five_lines_pulse(*this, {250, 10});
    loading_indicator loading_indicator8 = loading_indicators::five_lines_wave(*this, {10, 50});
    loading_indicator loading_indicator9 = loading_indicators::pulse(*this, {50, 50});
    loading_indicator loading_indicator10 = loading_indicators::pulse_outline(*this, {90, 50});
    loading_indicator loading_indicator11 = loading_indicators::three_balls(*this, {130, 50});
    loading_indicator loading_indicator12 = loading_indicators::three_balls_bouncing(*this, {170, 50});
    loading_indicator loading_indicator13 = loading_indicators::three_balls_rotation(*this, {210, 50});
  };
}

auto main()->int {
  application::run(loading_indicators_example::form1 {});
}
