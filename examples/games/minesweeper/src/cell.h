#pragma once
#include "cell_state.h"
#include "../properties/resources.h"
#include <xtd/xtd.forms>

namespace minesweeper {
  class cell : public xtd::forms::user_control {
  public:
    cell() {
      font(xtd::drawing::font(font(), 16));
      size({30, 30});
    };
    
    const xtd::drawing::point& cell_location() const {return cell_location_;}
    void cell_location(const xtd::drawing::point& value) {
      if (cell_location_ != value) {
        cell_location_ = value;
      }
    }
    
    bool has_mine() const {return has_mine_;}
    void has_mine(bool value) {
      if (has_mine_ != value) {
        has_mine_ = value;
      }
    }
    
    bool has_neighbors() const {return neighbors_;}
    
    int neighbors() const {return neighbors_;}
    void neighbors(int value) {
      if (neighbors_ != value)
        neighbors_ = value;
    }
    
    cell_state state() const {return state_;}
    void state(cell_state value) {
      if (state_ != value) {
        state_ = value;
        invalidate();
      }
    }
    
    void clear() {
      has_mine_ = false;
      neighbors_ = 0;
      if (state_ != cell_state::unchecked) {
        state_ = cell_state::unchecked;
        invalidate();
      }
    }
    
  protected:
    void on_paint(xtd::forms::paint_event_args& e) override {
      using namespace xtd;
      using namespace xtd::forms;
      std::map<cell_state, delegate<void(paint_event_args&)>> draw_state {{cell_state::unchecked, {*this, &cell::do_draw_unchecked}}, {cell_state::checked, {*this, &cell::do_draw_checked}}, {cell_state::flag, {*this, &cell::do_draw_flag}}, {cell_state::question, {*this, &cell::do_draw_question}}, {cell_state::mine, {*this, &cell::do_draw_mine}}, {cell_state::exploded_mine, {*this, &cell::do_draw_exploded_mine}}, {cell_state::error, {*this, &cell::do_draw_error}}};
      draw_state[state_](e);
      user_control::on_paint(e);
    }
    
  private:
    void do_draw_unchecked(xtd::forms::paint_event_args& e) {
      draw_border_unchecked(e);
    }
    
    void do_draw_checked(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      draw_border_checked(e);
      color text_color = system_colors::control_text();
      if (neighbors_ == 8) text_color = color::dark_gray;
      if (neighbors_ == 7) text_color = color::black;
      if (neighbors_ == 6) text_color = color::dark_green;
      if (neighbors_ == 5) text_color = color::dark_red;
      if (neighbors_ == 4) text_color = color::dark_blue;
      if (neighbors_ == 3) text_color = color::red;
      if (neighbors_ == 2) text_color = color::green;
      if (neighbors_ == 1) text_color = color::blue;
      if (neighbors_ != 0) {
        std::string text = std::to_string(neighbors_);
        auto x = (e.clip_rectangle().width() - e.graphics().measure_string(text, font()).width()) / 2;
        auto y = (e.clip_rectangle().height() - e.graphics().measure_string(text, font()).height()) / 2;
        if (back_color().get_brightness() < 0.5f) {
          e.graphics().draw_string(text, font(), solid_brush(color::lighter(color::lighter(text_color))), x - 1, y - 1);
          e.graphics().draw_string(text, font(), solid_brush(color::darker(color::darker(text_color))), x + 1, y + 1);
        }
        e.graphics().draw_string(text, font(), solid_brush(text_color), x, y);
      }
    }
    
    void do_draw_flag(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      draw_border_unchecked(e);
      static image flag = bitmap(properties::resources::flag(), {16, 16});
      auto x = (e.clip_rectangle().width() - flag.width()) / 2;
      auto y = (e.clip_rectangle().height() - flag.height()) / 2;
      e.graphics().draw_image(flag, x, y);
    }
    
    void do_draw_question(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      draw_border_unchecked(e);
      auto x = (e.clip_rectangle().width() - e.graphics().measure_string("?", font()).width()) / 2;
      auto y = (e.clip_rectangle().height() - e.graphics().measure_string("?", font()).height()) / 2;
      e.graphics().draw_string("?", font(), solid_brush(fore_color()), x, y);
    }
    
    void do_draw_mine(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      draw_border_checked(e);
      static image mine = bitmap(properties::resources::mine(), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
    }
    
    void do_draw_exploded_mine(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      e.graphics().clear(color::red);
      draw_border_checked(e);
      static image mine = bitmap(properties::resources::mine(), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
    }
    
    void do_draw_error(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      draw_border_checked(e);
      static image mine = bitmap(properties::resources::mine(), {16, 16});
      auto x = (e.clip_rectangle().width() - mine.width()) / 2;
      auto y = (e.clip_rectangle().height() - mine.height()) / 2;
      e.graphics().draw_image(mine, x, y);
      e.graphics().draw_line(pen(color::red, 2), 0, 0, e.clip_rectangle().width(), e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::red, 2), e.clip_rectangle().width(), 0, 0, e.clip_rectangle().height());
    }
    
    void draw_border_unchecked(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 0, 1, e.clip_rectangle().width(), 1);
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, 2, e.clip_rectangle().width(), 2);
      e.graphics().draw_line(pen(color::lighter(color::lighter(color::lighter(back_color())))), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(color::lighter(back_color()))), 1, 1, 1, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 2, 2, 2, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::darker(back_color())), 2, e.clip_rectangle().height() - 3, e.clip_rectangle().width(), e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), 1, e.clip_rectangle().height() - 2, e.clip_rectangle().width(), e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), 0, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::darker(back_color())), e.clip_rectangle().width() - 3, 2, e.clip_rectangle().width() - 3, e.clip_rectangle().height() - 3);
      e.graphics().draw_line(pen(color::darker(color::darker(back_color()))), e.clip_rectangle().width() - 2, 1, e.clip_rectangle().width() - 2, e.clip_rectangle().height() - 2);
      e.graphics().draw_line(pen(color::darker(color::darker(color::darker(back_color())))), e.clip_rectangle().width() - 1, 0, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    void draw_border_checked(xtd::forms::paint_event_args& e) {
      using namespace xtd::drawing;
      
      e.graphics().draw_line(pen(color::darker(back_color())), 0, 0, e.clip_rectangle().width(), 0);
      e.graphics().draw_line(pen(color::darker(back_color())), 0, 0, 0, e.clip_rectangle().height());
      e.graphics().draw_line(pen(color::lighter(back_color())), 1, e.clip_rectangle().height() - 1, e.clip_rectangle().width(), e.clip_rectangle().height() - 1);
      e.graphics().draw_line(pen(color::lighter(back_color())), e.clip_rectangle().width() - 1, 1, e.clip_rectangle().width() - 1, e.clip_rectangle().height() - 1);
    }
    
    cell_state state_ = cell_state::unchecked;
    bool has_mine_ = false;
    int neighbors_ = 0;
    xtd::drawing::point cell_location_;
  };
}
