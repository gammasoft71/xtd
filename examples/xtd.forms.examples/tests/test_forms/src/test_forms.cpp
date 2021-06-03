/// @todo #include<numbers> instead #include <cmath> when all is in c++20
//#include <numbers>
#define _USE_MATH_DEFINES
#include <cmath>
#include <xtd/forms/control.h>

namespace xtd {
  namespace forms {
    class activitty_indicator : public xtd::forms::control {
    public:
      activitty_indicator() {
        size(default_size());
        timer_.interval_milliseconds(interval_);
        timer_.tick += {*this, &activitty_indicator::on_timer_tick};
      }

      xtd::drawing::size default_size() const override {return {32, 32};}

      int32_t interval() const {return interval_;}
      void interval(int32_t value) {
        if (interval_ != value) {
          interval_ = value;
          timer_.interval_milliseconds(value);
        }
      }

      int32_t intervals() const {return intervals_;}
      void intervals(int32_t value) {intervals_ = value;}
      
      bool is_running() const {return timer_.enabled();}

      int32_t radius_factor() const {return radius_factor_;}
      void radius_factor(int32_t value) {radius_factor_ = value;}
      
      void start() {timer_.start();}
      void stop() {timer_.stop();}

    protected:
      void on_paint(xtd::forms::paint_event_args& e) override {
        e.graphics().translate_clip(e.clip_rectangle().width() / 2, e.clip_rectangle().height() / 2);
        const float angle = degrees_to_radians(360.f / intervals_);
        e.graphics().rotate_transform(frame_ * angle);
        const float height = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / radius_factor_;
        const float width = static_cast<float>(std::min(e.clip_rectangle().width(), e.clip_rectangle().height())) / radius_factor_;
        for (int n = 0; n < intervals_; n++) {
          const int opacity_index = enabled() ? n + 1 : 2;
          const int opacity = opacity_index*(255 + 1)/intervals_ - 1;
          e.graphics().fill_ellipse(xtd::drawing::solid_brush(xtd::drawing::color::from_argb(opacity, fore_color())), -(radius_factor_ / 2.f - 1.f) * width + width / radius_factor_ * 2.f, -(radius_factor_ / 2.f - 1.f) * height + height / radius_factor_ * 2.f, 2.f * width, 2.f *height);
          e.graphics().rotate_transform(angle);
        }
        xtd::forms::control::on_paint(e);
      }
      
      void on_timer_tick(timer& timer, const xtd::event_args& e) {
        if (++frame_ == intervals_) frame_ = 0;
        invalidate();
      }

    private:
      static float degrees_to_radians(float degrees) {
        /// @todo replace by std::numbers::pi when all is in c++20
        return M_PI / 180 * degrees;
      }
      xtd::forms::timer timer_;
      int32_t intervals_ = 8;
      int32_t radius_factor_ = 10;
      int32_t frame_ = 0;
      int32_t interval_ = 150;
    };
  }
}

#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;
using namespace xtd::diagnostics;
using namespace xtd::forms;

class form_main : public form {
public:
  static void main() {
    xtd::forms::application::run(form_main());
  }

  form_main() {
    controls().push_back_range({create_button, kill_button /*,  activitty_indicator}*/});
    create_button.location({10, 10});
    create_button.text("create");
    create_button.click += [&] {
      //proc = process::start(process_start_info(path::combine(environment::get_folder_path(environment::special_folder::my_pictures), "switch.png")));
      process_start_info psi("calc.exe");
      psi.use_shell_execute(false);
      proc = process::start(psi);
      debug::write_line("start time : {}", proc.start_time());
      proc.wait_for_exit();
    };

    proc.exited += {*this, &form_main::on_process_exit};

    kill_button.location({100, 10});
    kill_button.text("kill");
    kill_button.click += [&] {
      proc.kill();
    };
    
    //activitty_indicator.location({10, 10});
    //activitty_indicator.fore_color(xtd::drawing::color::dodger_blue);
    //activitty_indicator.fore_color(xtd::drawing::system_colors::accent());
    //activitty_indicator.enabled(false);
    //activitty_indicator.dock(dock_style::fill);
    //activitty_indicator.start();
  }

private:
  void on_process_exit(const process& p, const event_args e) {
    debug::write_line("exit time : {}", p.exit_time());
    debug::write_line("exit code : {}", p.exit_code());
  }
  button create_button;
  button kill_button;
  process proc;
  //activitty_indicator activitty_indicator;
};

startup_(form_main);
