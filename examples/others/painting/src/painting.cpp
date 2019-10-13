#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace examples {
  class pixel {
  public:
    pixel() = default;
    pixel(const xtd::drawing::point& location) : location_(location) {}
    pixel(const xtd::drawing::point& location, const xtd::drawing::color& color) : location_(location), color_(color) {}
    pixel(int x, int y) : location_(x, y) {}
    pixel(int x, int y, const xtd::drawing::color& color) : location_(x, y), color_(color) {}

    const xtd::drawing::color color() const {return color_;}
    const xtd::drawing::point location() const {return location_;}
    const int x() const {return location_.x();}
    const int y() const {return location_.y();}

  private:
    xtd::drawing::point location_;
    xtd::drawing::color color_ = xtd::drawing::color::black;
  };

  using pixel_collection = std::vector<pixel>;

  class form1 : public form {
  public:
    form1() {
      text("Painting example");
      client_size({640, 480});
      
      panel_colors.parent(*this);
      panel_colors.border_style(forms::border_style::fixed_single);
      panel_colors.location({10, 10});
      panel_colors.size({512, 32});
      
      panel_dark_magenta.parent(panel_colors);
      panel_dark_magenta.width(32);
      panel_dark_magenta.dock(dock_style::left);
      panel_dark_magenta.back_color(xtd::drawing::color::dark_magenta);
      panel_dark_magenta.click += {*this, &form1::choose_current_color};

      panel_dark_cyan.parent(panel_colors);
      panel_dark_cyan.width(32);
      panel_dark_cyan.dock(dock_style::left);
      panel_dark_cyan.back_color(xtd::drawing::color::dark_cyan);
      panel_dark_cyan.click += {*this, &form1::choose_current_color};

      panel_dark_yellow.parent(panel_colors);
      panel_dark_yellow.width(32);
      panel_dark_yellow.dock(dock_style::left);
      panel_dark_yellow.back_color(xtd::drawing::color::brown);
      panel_dark_yellow.click += {*this, &form1::choose_current_color};

      panel_dark_blue.parent(panel_colors);
      panel_dark_blue.width(32);
      panel_dark_blue.dock(dock_style::left);
      panel_dark_blue.back_color(xtd::drawing::color::dark_blue);
      panel_dark_blue.click += {*this, &form1::choose_current_color};

      panel_dark_green.parent(panel_colors);
      panel_dark_green.width(32);
      panel_dark_green.dock(dock_style::left);
      panel_dark_green.back_color(xtd::drawing::color::dark_green);
      panel_dark_green.click += {*this, &form1::choose_current_color};

      panel_dark_red.parent(panel_colors);
      panel_dark_red.width(32);
      panel_dark_red.dock(dock_style::left);
      panel_dark_red.back_color(xtd::drawing::color::dark_red);
      panel_dark_red.click += {*this, &form1::choose_current_color};

      panel_gray.parent(panel_colors);
      panel_gray.width(32);
      panel_gray.dock(dock_style::left);
      panel_gray.back_color(xtd::drawing::color::gray);
      panel_gray.click += {*this, &form1::choose_current_color};

      panel_dark_gray.parent(panel_colors);
      panel_dark_gray.width(32);
      panel_dark_gray.dock(dock_style::left);
      panel_dark_gray.back_color(xtd::drawing::color::dark_gray);
      panel_dark_gray.click += {*this, &form1::choose_current_color};

      panel_magenta.parent(panel_colors);
      panel_magenta.width(32);
      panel_magenta.dock(dock_style::left);
      panel_magenta.back_color(xtd::drawing::color::magenta);
      panel_magenta.click += {*this, &form1::choose_current_color};

      panel_cyan.parent(panel_colors);
      panel_cyan.dock(dock_style::left);
      panel_cyan.back_color(xtd::drawing::color::cyan);
      panel_cyan.width(32);
      panel_cyan.click += {*this, &form1::choose_current_color};

      panel_yellow.parent(panel_colors);
      panel_yellow.dock(dock_style::left);
      panel_yellow.back_color(xtd::drawing::color::yellow);
      panel_yellow.width(32);
      panel_yellow.click += {*this, &form1::choose_current_color};

      panel_blue.parent(panel_colors);
      panel_blue.width(32);
      panel_blue.dock(dock_style::left);
      panel_blue.back_color(xtd::drawing::color::blue);
      panel_blue.click += {*this, &form1::choose_current_color};

      panel_green.parent(panel_colors);
      panel_green.width(32);
      panel_green.dock(dock_style::left);
      panel_green.back_color(xtd::drawing::color::green);
      panel_green.click += {*this, &form1::choose_current_color};

      panel_red.parent(panel_colors);
      panel_red.width(32);
      panel_red.dock(dock_style::left);
      panel_red.back_color(xtd::drawing::color::red);
      panel_red.click += {*this, &form1::choose_current_color};

      panel_white.parent(panel_colors);
      panel_white.width(32);
      panel_white.dock(dock_style::left);
      panel_white.back_color(xtd::drawing::color::white);
      panel_white.click += {*this, &form1::choose_current_color};

      panel_black.parent(panel_colors);
      panel_black.width(32);
      panel_black.dock(dock_style::left);
      panel_black.back_color(xtd::drawing::color::black);
      panel_black.click += {*this, &form1::choose_current_color};

      button_clear.parent(*this);
      button_clear.text("Clear");
      button_clear.location({542, 15});
      button_clear.click += [this] {
        pixels.clear();
        panel_painting.refresh();
      };
      
      panel_painting.parent(*this);
      panel_painting.border_style(forms::border_style::fixed_single);
      panel_painting.back_color(color::white);
      panel_painting.location({10, 52});
      panel_painting.size({620, 418});
      
      panel_painting.mouse_down += [this](const control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          this->pixels.push_back({e.location(), current_color});
          panel_painting.refresh();
        }
      };
      
      panel_painting.mouse_move += [this](const control& sender, const mouse_event_args& e) {
        if (e.button() == mouse_buttons::left) {
          this->pixels.push_back({e.location(), current_color});
          panel_painting.refresh();
        }
      };

      panel_painting.paint += [this](const control& sender, paint_event_args& e) {
        for (auto pixel : pixels) {
          e.graphics().fill_rectangle(solid_brush(pixel.color()), pixel.x(), pixel.y(), 10, 10);
        };
      };
    }
  
  private:
    void choose_current_color(const control& sender, const event_args& e) {
      current_color = sender.back_color();
    };

    panel panel_painting;
    panel panel_colors;
    panel panel_black;
    panel panel_white;
    panel panel_red;
    panel panel_green;
    panel panel_blue;
    panel panel_yellow;
    panel panel_cyan;
    panel panel_magenta;
    panel panel_dark_red;
    panel panel_dark_green;
    panel panel_dark_blue;
    panel panel_dark_yellow;
    panel panel_dark_cyan;
    panel panel_dark_magenta;
    panel panel_dark_gray;
    panel panel_gray;
    button button_clear;
    pixel_collection pixels;
    drawing::color current_color = drawing::color::black;
  };
}

int main() {
  application::run(examples::form1());
}
