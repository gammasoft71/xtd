#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
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
        picture = bitmap(picture_width, picture_height);
        panel_painting.invalidate();
      };
      
      track_bar_zoom.parent(*this);
      track_bar_zoom.auto_size(false);
      track_bar_zoom.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::right);
      track_bar_zoom.location({10, 50});
      track_bar_zoom.set_range(1, 50);
      track_bar_zoom.tick_style(forms::tick_style::none);
      track_bar_zoom.value(zoom);
      track_bar_zoom.value_changed += [this] {
        zoom = track_bar_zoom.value();
        panel_painting.invalidate();
      };
      track_bar_zoom.size({client_size().width() - 20, 25});

      panel_painting.parent(*this);
      panel_painting.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      panel_painting.back_color(color::white_smoke);
      panel_painting.border_style(forms::border_style::fixed_single);
      panel_painting.location({10, 82});
      panel_painting.size({620, 388});

      panel_painting.mouse_down += [this](control& sender, const mouse_event_args& e) {
        picture.set_pixel(e.x()/zoom, e.y()/zoom, e.button() == mouse_buttons::left ? current_color : color::empty);
        panel_painting.invalidate(rectangle(e.x() / zoom * zoom, e.y() / zoom * zoom, zoom, zoom));
      };
      
      panel_painting.mouse_move += [this](control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          picture.set_pixel(e.x()/zoom, e.y()/zoom, current_color);
          panel_painting.invalidate(rectangle(e.x() / zoom * zoom, e.y() / zoom * zoom, zoom, zoom));
        }
      };

      panel_painting.paint += [this](control& sender, paint_event_args& e) {
        for (int y = 0; y < panel_painting.client_size().height(); y += zoom)
          for (int x = 0; x < panel_painting.client_size().width(); x += zoom)
            if (!picture.get_pixel(x/zoom, y/zoom).is_empty())
              e.graphics().fill_rectangle(solid_brush(picture.get_pixel(x/zoom, y/zoom)), x, y, zoom, zoom);
        if (zoom > 3) {
          for (int index = 0; index < panel_painting.client_size().width(); index += zoom)
            e.graphics().draw_line(pen(color::light_blue, 1), index, 0, index, panel_painting.client_size().height());
          for (int index = 0; index < panel_painting.client_size().height(); index += zoom)
            e.graphics().draw_line(pen(color::light_blue, 1), 0, index, panel_painting.client_size().width(), index);
        }
      };
    }
  
  private:
    void choose_current_color(control& sender, const event_args& e) {
      for (auto panel : panel_colors)
        panel->border_style(panel->handle() != sender.handle() ? forms::border_style::none : forms::border_style::fixed_single);
      current_color = sender.back_color();
    }

    static constexpr int picture_width = 5000;
    static constexpr int picture_height = 5000;
    int zoom = 20;
    drawing::color current_color;
    bitmap picture {picture_width, picture_height};

    panel panel_colors_container;
    vector<shared_ptr<panel>> panel_colors;
    button button_clear;
    panel panel_painting;
    track_bar track_bar_zoom;
  };
}

int main() {
  application::run(examples::form1());
}
