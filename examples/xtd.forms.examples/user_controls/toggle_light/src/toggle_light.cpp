#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

namespace toggle_light_example {
  class toggle_light : public xtd::forms::user_control {
  public:
    toggle_light() = default;
    
  protected:
    void on_mouse_enter(const xtd::event_args&) override {
      on = !on;
      refresh();
    }
    
    void on_paint(xtd::forms::paint_event_args& e) override {
      e.graphics().clear(back_color());
      if (on) e.graphics().fill_ellipse(xtd::drawing::system_brushes::accent(), e.clip_rectangle());
    }
    
  private:
    bool on = false;
  };
  
  class main_form : public xtd::forms::form {
  public:
    main_form() {
      text("Toggle light");
      client_size({600, 600});
      
      for (auto y = 0; y < num_y; ++y)
        for (auto x = 0; x < num_x; ++x)
          toggle_lights[x][y].parent(*this);
    }
    
    static void main() {
      xtd::forms::application::run(main_form {});
    }
    
  protected:
    void on_resize(const xtd::event_args&) override {
      auto step_x = client_size().width() / num_x;
      auto step_y = client_size().height() / num_y;
      
      for (auto y = 0; y < num_y; ++y)
        for (auto x = 0; x < num_x; ++x)
          toggle_lights[x][y].bounds({x * step_x, y * step_y, step_x, step_y});
    }
    
  private:
    static constexpr int num_x = 20;
    static constexpr int num_y = 20;
    std::array<std::array<toggle_light, num_y>, num_x> toggle_lights;
  };
}

auto main()->int {
  application::run(toggle_light_example::main_form {});
}
