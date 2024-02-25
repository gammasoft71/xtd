#include <xtd/forms/application>
#include <xtd/forms/form>
#include <xtd/forms/loading_indicators>

using namespace xtd::forms;

namespace loading_indicators_example {
  class form1 : public form {
  public:
    form1() {
      fore_color(application::style_sheet().system_colors().accent()).text("Loading indicatorss example");
    }
    
  private:
    void on_mouse_click(const mouse_event_args& e) override {
      for (auto item : {&loading_indicator1, &loading_indicator2, &loading_indicator3, &loading_indicator4, &loading_indicator5, &loading_indicator6, &loading_indicator7, &loading_indicator8, &loading_indicator9, &loading_indicator10, &loading_indicator11, &loading_indicator12, &loading_indicator13, &loading_indicator14}) {
        if (e.button() == xtd::forms::mouse_buttons::left) item->running(!item->running());
        if (e.button() == xtd::forms::mouse_buttons::right) item->enabled(!item->enabled());
      }
    }

    loading_indicator loading_indicator1 = loading_indicators::system(*this, true, {10, 10});
    loading_indicator loading_indicator2 = loading_indicators::bar(*this, true, {50, 10});
    loading_indicator loading_indicator3 = loading_indicators::circle_bars(*this, true, {90, 10});
    loading_indicator loading_indicator4 = loading_indicators::circle_blinks(*this, true, {130, 10});
    loading_indicator loading_indicator5 = loading_indicators::five_lines(*this, true, {170, 10});
    loading_indicator loading_indicator6 = loading_indicators::five_lines_center(*this, true, {210, 10});
    loading_indicator loading_indicator7 = loading_indicators::five_lines_chronological(*this, true, {250, 10});
    loading_indicator loading_indicator8 = loading_indicators::five_lines_pulse(*this, true, {10, 50});
    loading_indicator loading_indicator9 = loading_indicators::five_lines_wave(*this, true, {50, 50});
    loading_indicator loading_indicator10 = loading_indicators::pulse(*this, true, {90, 50});
    loading_indicator loading_indicator11 = loading_indicators::pulse_outline(*this, true, {130, 50});
    loading_indicator loading_indicator12 = loading_indicators::three_balls(*this, true, {170, 50});
    loading_indicator loading_indicator13 = loading_indicators::three_balls_bouncing(*this, true, {210, 50});
    loading_indicator loading_indicator14 = loading_indicators::three_balls_rotation(*this, true, {250, 50});
  };
}

auto main()->int {
  application::run(loading_indicators_example::form1 {});
}
