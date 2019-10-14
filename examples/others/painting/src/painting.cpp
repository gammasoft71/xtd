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
    xtd::drawing::color col;
  };

  class form1 : public form {
  public:
    form1() {
      text("Painting example");
      client_size({640, 480});
      
      panel_colors_container.parent(*this);
      panel_colors_container.border_style(forms::border_style::fixed_single);
      panel_colors_container.location({10, 10});
      panel_colors_container.client_size({512, 32});
      
      for (color color : {color::dark_magenta, color::dark_cyan, color::brown, color::dark_blue, color::dark_green, color::dark_red, color::gray, color::dark_gray, color::magenta, color::cyan, color::yellow, color::blue, color::green, color::red, color::white, color::black}) {
        shared_ptr<panel> panel_color = control::create<panel>(panel_colors_container, {0, 0}, {32, 32}, color);
        panel_color->dock(dock_style::left);
        panel_color->click += {*this, &form1::choose_current_color};
        panel_colors.push_back(panel_color);
      }
      current_color = panel_colors[panel_colors.size() - 1]->back_color();
      panel_colors[panel_colors.size() - 1]->border_style(forms::border_style::fixed_single);

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
          this->pixels.push_back({point(e.location().x() / line_width * line_width, e.location().y() / line_width * line_width), current_color});
          panel_painting.invalidate(rectangle(e.location().x() / line_width * line_width, e.location().y() / line_width * line_width, line_width, line_width), false);
        }
      };
      
      panel_painting.mouse_move += [this](const control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          this->pixels.push_back({point(e.location().x() / line_width * line_width, e.location().y() / line_width * line_width), current_color});
          panel_painting.invalidate(rectangle(e.location().x() / line_width * line_width, e.location().y() / line_width * line_width, line_width, line_width), false);
        }
      };

      panel_painting.paint += [this](const control& sender, paint_event_args& e) {
        for (auto pixel : pixels)
          e.graphics().fill_rectangle(solid_brush(pixel.color()), pixel.location().x(), pixel.location().y(), line_width, line_width);
        for (int index = 0; index < panel_painting.client_size().width(); index += line_width)
          e.graphics().fill_rectangle(solid_brush(color::light_blue), index, 0, 1, panel_painting.client_size().height());
        for (int index = 0; index < panel_painting.client_size().height(); index += line_width)
          e.graphics().fill_rectangle(solid_brush(color::light_blue), 0, index, panel_painting.client_size().width(), 1);
      };
    }
  
  private:
    void choose_current_color(const control& sender, const event_args& e) {
      for (auto panel : panel_colors)
        panel->border_style(panel->handle() != sender.handle() ? forms::border_style::none : forms::border_style::fixed_single);
      current_color = sender.back_color();
    };

    size_t line_width = 20;
    panel panel_colors_container;
    vector<shared_ptr<panel>> panel_colors;
    button button_clear;
    panel panel_painting;
    vector<pixel> pixels;
    drawing::color current_color;
  };
}

int main() {
  application::run(examples::form1());
}
