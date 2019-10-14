#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class pixel {
  public:
    pixel(const xtd::drawing::point& location, const xtd::drawing::color& color) : loc(location), col(color) {}

    const xtd::drawing::color color() const {return col;}

    const xtd::drawing::point location() const {return loc;}

  private:
    xtd::drawing::point loc;
    xtd::drawing::color col = xtd::drawing::color::black;
  };

  using pixel_collection = std::vector<pixel>;

  class form1 : public form {
  public:
    form1() {
      text("Painting example");
      client_size({640, 480});
      
      panel_colors_container.parent(*this);
      panel_colors_container.border_style(forms::border_style::fixed_single);
      panel_colors_container.location({10, 10});
      panel_colors_container.size({512, 32});
      
      for (size_t index = 0; index < panel_colors.size(); ++index) {
        panel_colors[index].parent(panel_colors_container);
        panel_colors[index].width(32);
        panel_colors[index].dock(dock_style::left);
        panel_colors[index].back_color(colors[index]);
        panel_colors[index].click += {*this, &form1::choose_current_color};
      }
           
      button_clear.parent(*this);
      button_clear.text("Clear");
      button_clear.location({542, 15});
      button_clear.click += [this] {
        pixels.clear();
        panel_painting.refresh();
      };
      
      panel_painting.parent(*this);
      panel_painting.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      panel_painting.border_style(forms::border_style::fixed_single);
      panel_painting.back_color(color::white);
      panel_painting.location({10, 52});
      panel_painting.size({620, 418});
      
      panel_painting.mouse_down += [this](const control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          xtd::drawing::point location = {e.location().x() / 10 * 10, e.location().y() / 10 * 10};
          this->pixels.push_back({location, current_color});
          panel_painting.refresh();
        }
      };
      
      panel_painting.mouse_move += [this](const control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          xtd::drawing::point location = {e.location().x() / 10 * 10, e.location().y() / 10 * 10};
          this->pixels.push_back({location, current_color});
          panel_painting.refresh();
        }
      };

      panel_painting.paint += [this](const control& sender, paint_event_args& e) {
        for (int index = 0; index < panel_painting.client_size().width(); index += 10)
          e.graphics().fill_rectangle(solid_brush(color::light_gray), index, 0, 1, panel_painting.client_size().height());
        for (int index = 0; index < panel_painting.client_size().height(); index += 10)
          e.graphics().fill_rectangle(solid_brush(color::light_gray), 0, index, panel_painting.client_size().width(), 1);
        for (auto pixel : pixels) {
          e.graphics().fill_rectangle(solid_brush(pixel.color()), pixel.location().x(), pixel.location().y(), 10, 10);
        };
      };
    }
  
  private:
    void choose_current_color(const control& sender, const event_args& e) {
      current_color = sender.back_color();
    };

    vector<color> colors = {color::dark_magenta, color::dark_cyan, color::brown, color::dark_blue, color::dark_green, color::dark_red, color::gray, color::dark_gray, color::magenta, color::cyan, color::yellow, color::blue, color::green, color::red, color::white, color::black};
    panel panel_colors_container;
    vector<panel> panel_colors {colors.size()};
    button button_clear;
    panel panel_painting;
    pixel_collection pixels;
    drawing::color current_color = drawing::color::black;
  };
}

int main() {
  application::run(examples::form1());
}
