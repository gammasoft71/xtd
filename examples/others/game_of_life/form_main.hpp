
#pragma once
#include <random>
#include <xtd/xtd.forms>
#include "grid.hpp"

namespace game_of_life {
  class form_main : public xtd::forms::form {
    using figure_delegate = xtd::delegate<void()>;
  public:
    form_main() {
      text("John Conway's Game of Life");
      client_size({715, 485});

      button_run_.parent(*this);
      button_run_.text("Run");
      button_run_.location({10, 10});
      button_run_.click += [this] {
        timer_evolve_.enabled(!timer_evolve_.enabled());
        button_run_.text(timer_evolve_.enabled() ? "Stop" : "Run");
      };

      button_next_.parent(*this);
      button_next_.text("Next");
      button_next_.location({100, 10});
      button_next_.click += {*this, & form_main::evolve};

      button_clear_.parent(*this);
      button_clear_.text("Clear");
      button_clear_.location({190, 10});
      button_clear_.click += {*this, & form_main::clear};

      combo_box_figures_.parent(*this);
      combo_box_figures_.drop_down_style(xtd::forms::combo_box_style::drop_down_list);
      combo_box_figures_.items().push_back_range({{"Figure", figure_delegate(*this, &form_main::nothing)}, {"Random cells", figure_delegate(*this, &form_main::random)}, {"Blinker", figure_delegate(*this, &form_main::blinker)}, {"Toad", figure_delegate(*this, &form_main::toad)}, {"beacon", figure_delegate(*this, &form_main::beacon)}, {"Pulsar", figure_delegate(*this, &form_main::pulsar)}, {"Penta-decathlon", figure_delegate(*this, &form_main::penta_decathlon)}, {"Glider", figure_delegate(*this, &form_main::glider)}, {"Small exploder", figure_delegate(*this, &form_main::small_exploder)}, {"Exploder", figure_delegate(*this, &form_main::exploder)}, {"Lightweight spaceship", figure_delegate(*this, &form_main::lightweight_spaceship)}, {"Middleweight spaceship", figure_delegate(*this, &form_main::middleweight_spaceship)}, {"Heavyweight spaceship", figure_delegate(*this, &form_main::heavyweight_spaceship)}, {"Tumbler", figure_delegate(*this, &form_main::tumbler)}, {"Gosper glider gun", figure_delegate(*this, &form_main::gosper_glider_gun)}});
      combo_box_figures_.location({280, 11});
      combo_box_figures_.selected_index(0);
      combo_box_figures_.width(200);
      combo_box_figures_.selected_index_changed += [this] {
        std::any_cast<figure_delegate>(combo_box_figures_.items()[combo_box_figures_.selected_index()].tag())();
        combo_box_figures_.selected_index(0);
      };

      label_iterations_.parent(*this);
      label_iterations_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_iterations_.font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), label_iterations_.font().size()));
      label_iterations_.text_align(xtd::forms::content_alignment::middle_right);
      label_iterations_.text(xtd::strings::format("Iterations : {}", iterations_));
      label_iterations_.width(150);
      label_iterations_.location({555, 15});

      label_zoom_.parent(*this);
      label_zoom_.location({10, 45});
      label_zoom_.text(xtd::strings::format("Zoom : {}", zoom_));

      track_bar_zoom_.parent(*this);
      track_bar_zoom_.auto_size(false);
      track_bar_zoom_.location({90, 40});
      track_bar_zoom_.minimum(1);
      track_bar_zoom_.maximum(50);
      track_bar_zoom_.tick_style(xtd::forms::tick_style::none);
      track_bar_zoom_.value(zoom_);
      track_bar_zoom_.value_changed += [this] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width())
          track_bar_zoom_.value(panel_grid_.client_size().width() / grid::columns + 1);
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height())
          track_bar_zoom_.value(panel_grid_.client_size().height() / grid::rows + 1);
        zoom_ = track_bar_zoom_.value();
        panel_grid_.invalidate();
        label_zoom_.text(xtd::strings::format("Zoom : {}", zoom_));
      };
      track_bar_zoom_.size({200, 25});

      label_speed_.parent(*this);
      label_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_speed_.location({425, 45});
      label_speed_.text(xtd::strings::format("Speed : {}", speed_));

      track_bar_speed_.parent(*this);
      track_bar_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      track_bar_speed_.auto_size(false);
      track_bar_speed_.location({505, 40});
      track_bar_speed_.minimum(1);
      track_bar_speed_.maximum(100);
      track_bar_speed_.tick_style(xtd::forms::tick_style::none);
      track_bar_speed_.value(speed_);
      track_bar_speed_.value_changed += [this] {
        speed_ = track_bar_speed_.value();
        timer_evolve_.interval(1000 / speed_);
        label_speed_.text(xtd::strings::format("Speed : {}", speed_));
      };
      track_bar_speed_.size({200, 25});

      panel_grid_.parent(*this);
      panel_grid_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      panel_grid_.border_style(xtd::forms::border_style::fixed_single);
      panel_grid_.location({10, 75});
      panel_grid_.size({695, 395});

      panel_grid_.mouse_down += [this](const control& sender, const xtd::forms::mouse_event_args& e) {
        current_state_ = grid_.cells()[e.location().x() / zoom_][e.location().y() / zoom_] == cell::alive ? cell::dead : cell::alive;
        grid_.cells()[e.location().x() / zoom_][e.location().y() / zoom_] = current_state_;
        panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
      };

      panel_grid_.mouse_move += [this](const control& sender, const xtd::forms::mouse_event_args& e) {
        if (e.button() == xtd::forms::mouse_buttons::left) {
          grid_.cells()[e.location().x() / zoom_][e.location().y() / zoom_] = current_state_;
          panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
        }
      };

      panel_grid_.paint += [this](const control& sender, xtd::forms::paint_event_args& e) {
        if ((track_bar_zoom_.value() * grid::columns) >= panel_grid_.client_size().width() && (track_bar_zoom_.value() * grid::rows) >= panel_grid_.client_size().height())
          for (int y = 0; y < panel_grid_.client_size().height(); y += zoom_)
            for (int x = 0; x < panel_grid_.client_size().width(); x += zoom_)
              e.graphics().fill_rectangle(xtd::drawing::solid_brush(grid_.cells()[x / zoom_][y / zoom_] == cell::dead ? dead_color_ : alive_color_), x, y, zoom_, zoom_);
        if (zoom_ > 3) {
          for (int index = 0; index < panel_grid_.client_size().width(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), index, 0, 1, panel_grid_.client_size().height());
          for (int index = 0; index < panel_grid_.client_size().height(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), 0, index, panel_grid_.client_size().width(), 1);
        }
      };

      panel_grid_.resize += [this] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width()) {
          zoom_ = panel_grid_.client_size().width() / grid::columns + 1;
          track_bar_zoom_.value(zoom_);
        }
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height()) {
          zoom_ = panel_grid_.client_size().height() / grid::rows + 1;
          track_bar_zoom_.value(zoom_);
        }
      };

      timer_evolve_.interval(1000 / speed_);
      timer_evolve_.tick += {*this, &form_main::evolve};

      grid_.status_changed += [this](const grid& sender, const state_event_args& e) {
        panel_grid_.invalidate(xtd::drawing::rectangle(e.x() * zoom_, e.y() * zoom_, zoom_, zoom_), false);
      };
    }

  private:
    void clear() {
      grid_.clear();
      iterations_ = 0;
      label_iterations_.text(xtd::strings::format("Iterations : {}", iterations_));
      panel_grid_.invalidate();
    }

    void nothing() {}

    void evolve() {
      label_iterations_.text(xtd::strings::format("Iterations : {}", ++iterations_));
      grid_.evolve();
    }

    void random() {
      std::random_device rand;
      int max = std::uniform_int_distribution<int>{ 50, 200 }(rand);
      int max_x = panel_grid_.client_size().width() / zoom_;
      int max_y = panel_grid_.client_size().height() / zoom_;
      for (int counter = 0; counter < max; counter++) {
        int x = std::uniform_int_distribution<int>(0, max_x)(rand);
        int y = std::uniform_int_distribution<int>(0, max_y)(rand);
        grid_.cells()[x][y] = cell::alive;
        panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
      }
    }

    void fill_figure(const std::vector<xtd::ustring>& figure) {
      int height = static_cast<int>(figure.size());
      int width = 0;
      for (xtd::ustring line : figure)
        if (line.length() > width) width = static_cast<int>(line.length());

      int start_x = (panel_grid_.client_size().width() / zoom_ / 2) - (width / 2);
      int y = (panel_grid_.client_size().height() / zoom_ / 2) - (height / 2);

      if (start_x < 5) start_x = 5;
      if (y < 5) y = 5;

      for (xtd::ustring line : figure) {
        int x = start_x;
        for (char cell : line) {
          grid_.cells()[x][y] = cell != ' ' ? cell::alive : cell::dead;
          panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
          x++;
        }
        y++;
      }
    }

    void beacon() { fill_figure({ "**  ", "*   ", "   *", "  **" }); }
    void blinker() { fill_figure({ "*", "*", "*" }); }
    void exploder() { fill_figure({ "* * *", "*   *", "*   *", "*   *", "* * *" }); }
    void glider() { fill_figure({ " * ", "  *", "***" }); }
    void gosper_glider_gun() { fill_figure({ "                       **         **  ", "                      * *         **  ", "**       **           **              ", "**      * *                           ", "        **      **                    ", "                * *                   ", "                *                     ", "                                   ** ", "                                   * *", "                                   *  ", "                                      ", "                                      ", "                        ***           ", "                        *             ", "                         *            " }); }
    void heavyweight_spaceship() { fill_figure({ "  **   ", "*    * ", "      *", "*     *", " ******" }); }
    void lightweight_spaceship() { fill_figure({ "*  * ", "    *", "*   *", " ****" }); }
    void middleweight_spaceship() { fill_figure({ "  *   ", "*   * ", "     *", "*    *", " *****" }); }
    void penta_decathlon() { fill_figure({ "*", "*", "*", "*", "*", "*", "*", "*", "*", "*" }); }
    void pulsar() { fill_figure({ "  ***   ***  ", "             ", "*    * *    *", "*    * *    *", "*    * *    *", "  ***   ***  ", "             ", "  ***   ***  ", "*    * *    *", "*    * *    *", "*    * *    *", "             ", "  ***   ***  " }); }
    void small_exploder() { fill_figure({ " * ", "***", "* *", " * " }); }
    void toad() { fill_figure({ " ***", "*** " }); }
    void tumbler() { fill_figure({ " ** ** ", " ** ** ", "  * *  ", "* * * *", "* * * *", "**   **" }); }

    xtd::forms::button button_run_;
    xtd::forms::button button_next_;
    xtd::forms::button button_clear_;
    xtd::forms::combo_box combo_box_figures_;
    xtd::forms::label label_iterations_;
    xtd::forms::label label_zoom_;
    xtd::forms::track_bar track_bar_zoom_;
    xtd::forms::label label_speed_;
    xtd::forms::track_bar track_bar_speed_;
    xtd::forms::panel panel_grid_;
    xtd::forms::timer timer_evolve_;
    xtd::drawing::color line_color_ = xtd::drawing::system_colors::window_text();
    xtd::drawing::color dead_color_ = xtd::drawing::system_colors::window();
    xtd::drawing::color alive_color_ = xtd::drawing::system_colors::window_text();

    cell current_state_ = cell::dead;
    grid grid_;
    int iterations_ = 0;
    int zoom_ = 15;
    int speed_ = 25;
  };
}
