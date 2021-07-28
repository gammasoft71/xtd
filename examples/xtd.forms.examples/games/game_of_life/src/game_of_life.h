#pragma once
#include <chrono>
#include <random>
#include <thread>
#include <xtd/xtd>
#include "grid.h"

namespace game_of_life {
  class form_game_of_life : public xtd::forms::form {
    using figure_delegate = xtd::delegate<void()>;
  public:
    static void main() {
      xtd::forms::application::run(game_of_life::form_game_of_life());
    }

    form_game_of_life() {
      text("John Conway's Game of Life");
      client_size({715, 485});
      
      form_closed += [&] {
        closed_ = true;
        thread_run_.join();
      };
      
      button_run_.parent(*this);
      button_run_.text("Run");
      button_run_.location({10, 10});
      button_run_.click += [&] {
        run_enabled_ = !run_enabled_;
        button_run_.text(run_enabled_ ? "Stop" : "Run");
        button_clear_.enabled(!run_enabled_ );
        button_next_.enabled(!run_enabled_ );
      };
      
      button_next_.parent(*this);
      button_next_.text("Next");
      button_next_.location({100, 10});
      button_next_.click += xtd::event_handler(*this, & form_game_of_life::next);
      
      button_clear_.parent(*this);
      button_clear_.text("Clear");
      button_clear_.location({190, 10});
      button_clear_.click += xtd::event_handler(*this, & form_game_of_life::clear);
      
      choice_figures_.parent(*this);
      choice_figures_.items().push_back_range({{"Figure", figure_delegate(*this, &form_game_of_life::nothing)}, {"Random cells", figure_delegate(*this, &form_game_of_life::random)}, {"Blinker", figure_delegate(*this, &form_game_of_life::blinker)}, {"Toad", figure_delegate(*this, &form_game_of_life::toad)}, {"beacon", figure_delegate(*this, &form_game_of_life::beacon)}, {"galaxy", figure_delegate(*this, &form_game_of_life::galaxy)}, {"Pulsar", figure_delegate(*this, &form_game_of_life::pulsar)}, {"Penta-decathlon", figure_delegate(*this, &form_game_of_life::penta_decathlon)}, {"Glider", figure_delegate(*this, &form_game_of_life::glider)}, {"Small exploder", figure_delegate(*this, &form_game_of_life::small_exploder)}, {"Exploder", figure_delegate(*this, &form_game_of_life::exploder)}, {"Lightweight spaceship", figure_delegate(*this, &form_game_of_life::lightweight_spaceship)}, {"Middleweight spaceship", figure_delegate(*this, &form_game_of_life::middleweight_spaceship)}, {"Heavyweight spaceship", figure_delegate(*this, &form_game_of_life::heavyweight_spaceship)}, {"Fireship", figure_delegate(*this, &form_game_of_life::fireship)}, {"Tumbler", figure_delegate(*this, &form_game_of_life::tumbler)}, {"Gosper glider gun", figure_delegate(*this, &form_game_of_life::gosper_glider_gun)}, {"Simkin glider gun", figure_delegate(*this, &form_game_of_life::simkin_glider_gun)}});
      choice_figures_.location({280, 11});
      choice_figures_.selected_index(0);
      choice_figures_.width(220);
      choice_figures_.selected_index_changed += [&] {
        std::any_cast<figure_delegate>(choice_figures_.items()[choice_figures_.selected_index()].tag())();
        choice_figures_.selected_index(0);
      };
      
      label_iterations_.parent(*this);
      label_iterations_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_iterations_.font(xtd::drawing::font(xtd::drawing::font_family::generic_monospace(), label_iterations_.font().size()));
      label_iterations_.text_align(xtd::forms::content_alignment::middle_right);
      label_iterations_.text(xtd::ustring::format("Iterations : {}", iterations_));
      label_iterations_.width(150);
      label_iterations_.location({555, 15});
      
      label_zoom_.parent(*this);
      label_zoom_.location({10, 45});
      label_zoom_.text(xtd::ustring::format("Zoom : {}", zoom_));
      
      track_bar_zoom_.parent(*this);
      track_bar_zoom_.auto_size(false);
      track_bar_zoom_.location({90, 40});
      track_bar_zoom_.minimum(1);
      track_bar_zoom_.maximum(50);
      track_bar_zoom_.tick_style(xtd::forms::tick_style::none);
      track_bar_zoom_.value(zoom_);
      track_bar_zoom_.value_changed += [&] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width())
          track_bar_zoom_.value(panel_grid_.client_size().width() / grid::columns + 1);
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height())
          track_bar_zoom_.value(panel_grid_.client_size().height() / grid::rows + 1);
        zoom_ = track_bar_zoom_.value();
        panel_grid_.invalidate();
        label_zoom_.text(xtd::ustring::format("Zoom : {}", zoom_));
      };
      track_bar_zoom_.size({200, 25});
      
      label_speed_.parent(*this);
      label_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      label_speed_.location({425, 45});
      label_speed_.text(xtd::ustring::format("Speed : {}", speed_));
      
      track_bar_speed_.parent(*this);
      track_bar_speed_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      track_bar_speed_.auto_size(false);
      track_bar_speed_.location({505, 40});
      track_bar_speed_.minimum(1);
      track_bar_speed_.maximum(100);
      track_bar_speed_.tick_style(xtd::forms::tick_style::none);
      track_bar_speed_.value(speed_);
      track_bar_speed_.value_changed += [&] {
        speed_ = track_bar_speed_.value();
        interval_milliseconds_ = 1000 / speed_;
        label_speed_.text(xtd::ustring::format("Speed : {}", speed_));
      };
      track_bar_speed_.size({200, 25});
      
      panel_grid_.parent(*this);
      panel_grid_.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::bottom | xtd::forms::anchor_styles::right);
      panel_grid_.back_color(empty_color_);
      panel_grid_.border_style(xtd::forms::border_style::fixed_single);
      panel_grid_.location({10, 75});
      panel_grid_.size({695, 395});
      panel_grid_.double_buffered(true);
      
      panel_grid_.mouse_down += [&](object& sender, const xtd::forms::mouse_event_args& e) {
        current_state_ = grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] == cell::populated ? cell::empty : cell::populated;
        grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] = current_state_;
        panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
      };
      
      panel_grid_.mouse_move += [&](object& sender, const xtd::forms::mouse_event_args& e) {
        if (e.button() == xtd::forms::mouse_buttons::left) {
          grid_.cells()[offset_y_ + e.location().y() / zoom_][offset_x_ + e.location().x() / zoom_] = current_state_;
          panel_grid_.invalidate(xtd::drawing::rectangle(e.location().x() / zoom_ * zoom_, e.location().y() / zoom_ * zoom_, zoom_, zoom_), false);
        }
      };
      
      panel_grid_.paint += [&](object& sender, xtd::forms::paint_event_args& e) {
        e.graphics().clear(back_color());
        if ((track_bar_zoom_.value() * grid::columns) >= panel_grid_.client_size().width() && (track_bar_zoom_.value() * grid::rows) >= panel_grid_.client_size().height())
          for (auto y = 0; y < panel_grid_.client_size().height(); y += zoom_)
            for (auto x = 0; x < panel_grid_.client_size().width(); x += zoom_)
              if (grid_.cells()[offset_y_ + y / zoom_][offset_x_ + x / zoom_] != cell::empty)
                e.graphics().fill_rectangle(xtd::drawing::solid_brush(populated_color_), x, y, zoom_, zoom_);
        if (zoom_ > 3) {
          for (auto index = 0; index < panel_grid_.client_size().width(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), index, 0, 1, panel_grid_.client_size().height());
          for (auto index = 0; index < panel_grid_.client_size().height(); index += zoom_)
            e.graphics().fill_rectangle(xtd::drawing::solid_brush(line_color_), 0, index, panel_grid_.client_size().width(), 1);
        }
      };
      
      panel_grid_.resize += [&] {
        if ((track_bar_zoom_.value() * grid::columns) < panel_grid_.client_size().width()) {
          zoom_ = panel_grid_.client_size().width() / grid::columns + 1;
          track_bar_zoom_.value(zoom_);
        }
        if ((track_bar_zoom_.value() * grid::rows) < panel_grid_.client_size().height()) {
          zoom_ = panel_grid_.client_size().height() / grid::rows + 1;
          track_bar_zoom_.value(zoom_);
        }
      };
      
      grid_.cells_updated += [&] {
        panel_grid_.begin_invoke([&] {
          panel_grid_.invalidate();
          label_iterations_.text(xtd::ustring::format("Iterations : {}", iterations_));
        });
      };

      thread_run_ = std::thread([&] {
        while (!closed_) {
          if (!run_enabled_)
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
          else {
            next();
            static auto lastRunTime = std::chrono::high_resolution_clock::now();
            auto elapsedTime = std::chrono::high_resolution_clock::now() - lastRunTime;
            if (elapsedTime < std::chrono::milliseconds(interval_milliseconds_)) std::this_thread::sleep_for(std::chrono::milliseconds(interval_milliseconds_) - elapsedTime);
            else std::this_thread::yield(); 
            lastRunTime = std::chrono::high_resolution_clock::now();
          }
        }
      });
    }
    
  private:
    void clear() {
      grid_.clear();
      iterations_ = 0;
      label_iterations_.text(xtd::ustring::format("Iterations : {}", iterations_));
      panel_grid_.invalidate();
    }
    
    void nothing() {}
    
    void next() {
      grid_.next();
      ++iterations_;
    }
    
    void random() {
      std::random_device rand;
      auto max = std::uniform_int_distribution<int>{ 50, 200 }(rand);
      auto max_x = panel_grid_.client_size().width() / zoom_;
      auto max_y = panel_grid_.client_size().height() / zoom_;
      for (auto counter = 0; counter < max; counter++) {
        auto x = std::uniform_int_distribution<int>(0, max_x)(rand);
        auto y = std::uniform_int_distribution<int>(0, max_y)(rand);
        grid_.cells()[offset_y_ + y][offset_x_ + x] = cell::populated;
        panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
      }
    }
    
    void fill_figure(const std::vector<std::string>& figure) {
      auto height = static_cast<int>(figure.size());
      auto width = 0U;
      for (auto line : figure)
        if (line.length() > width) width = static_cast<int>(line.length());
      
      auto start_x = (panel_grid_.client_size().width() / zoom_ / 2) - (width / 2);
      auto y = (panel_grid_.client_size().height() / zoom_ / 2) - (height / 2);
      
      if (start_x < 5) start_x = 5;
      if (y < 5) y = 5;
      
      for (auto line : figure) {
        auto x = start_x;
        for (auto cell : line) {
          grid_.cells()[offset_y_ + y][offset_x_ + x] = cell != ' ' ? cell::populated : cell::empty;
          panel_grid_.invalidate(xtd::drawing::rectangle(x * zoom_, y * zoom_, zoom_, zoom_), false);
          x++;
        }
        y++;
      }
    }
    
    void beacon() {
      fill_figure({
        "**  ",
        "*   ",
        "   *",
        "  **"
      });
    }
    
    void blinker() {
      fill_figure({
        "*",
        "*",
        "*"
      });
    }
    
    void exploder() {
      fill_figure({
        "* * *",
        "*   *",
        "*   *",
        "*   *",
        "* * *"
      });
    }
    
    void fireship() {
      fill_figure({
        "         **    ",
        "         **    ",
        "        *  *   ",
        "        ****   ",
        "       * ** *  ",
        "        *  *   ",
        "               ",
        "       **  **  ",
        "      *      * ",
        "               ",
        "       *    *  ",
        "        *  *   ",
        "         **    ",
        "               ",
        "      **    ** ",
        "     *  *  *  *",
        "      **    ** ",
        "       *    *  ",
        "               ",
        "               ",
        "               ",
        "**             ",
        " **            ",
        "*              ",
      });
    }
    
    void galaxy() {
      fill_figure({
        "****** **",
        "****** **",
        "       **",
        "**     **",
        "**     **",
        "**     **",
        "**       ",
        "** ******",
        "** ******",
      });
    }
    void glider() {
      fill_figure({
        " * ",
        "  *",
        "***"
      });
    }
    
    void gosper_glider_gun() {
      fill_figure({
        "                       **         **  ",
        "                      * *         **  ",
        "**       **           **              ",
        "**      * *                           ",
        "        **      **                    ",
        "                * *                   ",
        "                *                     ",
        "                                   ** ",
        "                                   * *",
        "                                   *  ",
        "                                      ",
        "                                      ",
        "                        ***           ",
        "                        *             ",
        "                         *            "
      });
    }
    void heavyweight_spaceship() {
      fill_figure({
        "  **   ",
        "*    * ",
        "      *",
        "*     *",
        " ******"
      });
    }
    
    void lightweight_spaceship() {
      fill_figure({
        "*  * ",
        "    *",
        "*   *",
        " ****"
      });
    }
    
    void middleweight_spaceship() {
      fill_figure({
        "  *   ",
        "*   * ",
        "     *",
        "*    *",
        " *****"
      });
    }
    
    void penta_decathlon() {
      fill_figure({
        "**********"
      });
    }
    void pulsar() {
      fill_figure({
        "  ***   ***  ",
        "             ",
        "*    * *    *",
        "*    * *    *",
        "*    * *    *",
        "  ***   ***  ",
        "             ",
        "  ***   ***  ",
        "*    * *    *",
        "*    * *    *",
        "*    * *    *",
        "             ",
        "  ***   ***  "
      });
    }
    
    void simkin_glider_gun() {
      fill_figure({
        "                    *            ",
        "**     **         ** *           ",
        "**     **        *    *          ",
        "                     *           ",
        "    **           ****            ",
        "    **                           ",
        "                                 ",
        "                                 ",
        "                                 ",
        "                           **    ",
        "                           **    ",
        "                                 ",
        "                        **     **",
        "                        **     **",
      });
    }

    void small_exploder() {
      fill_figure({
        " * ",
        "***",
        "* *",
        " * "
      });
    }

    void toad() {
      fill_figure({
        " ***",
        "*** "
      });
    }
    
    void tumbler() {
      fill_figure({
        " ** ** ",
        " ** ** ",
        "  * *  ",
        "* * * *",
        "* * * *",
        "**   **"
      });
    }
    
    cell current_state_ = cell::empty;
    grid grid_;
    int iterations_ = 0;
    int zoom_ = 15;
    int speed_ = 10;
    int offset_x_ = 200;
    int offset_y_ = 200;
    bool closed_ = false;
    bool run_enabled_ = false;
    int interval_milliseconds_ = 1000/speed_;

    xtd::forms::button button_run_;
    xtd::forms::button button_next_;
    xtd::forms::button button_clear_;
    xtd::forms::choice choice_figures_;
    xtd::forms::label label_iterations_;
    xtd::forms::label label_zoom_;
    xtd::forms::track_bar track_bar_zoom_;
    xtd::forms::label label_speed_;
    xtd::forms::track_bar track_bar_speed_;
    xtd::forms::panel panel_grid_;
    std::thread thread_run_;
    xtd::drawing::color line_color_ = xtd::drawing::system_colors::window_text();
    xtd::drawing::color empty_color_ = xtd::drawing::system_colors::window();
    xtd::drawing::color populated_color_ = xtd::drawing::system_colors::window_text();
  };
}
