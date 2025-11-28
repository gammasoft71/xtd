#include <xtd/xtd>

namespace colors_example {
  class color_chooser final : public user_control {
    class color_panel final : public user_control {
    public:
      color_panel() {
        size({200, 40});
        color(color::empty);
      }
      
      void on_paint(paint_event_args& e) override {
        user_control::on_paint(e);
        e.graphics().fill_rectangle(drawing_2d::hatch_brush(drawing_2d::hatch_style::wide_checker_board, color::from_argb(0x66, 0x66, 0x66), color::from_argb(0x99, 0x99, 0x99)), 6, 4, 94, e.clip_rectangle().height - 8);
        e.graphics().fill_rectangle(solid_brush(color_), 6, 4, 94, e.clip_rectangle().height - 8);
        auto name = color_.name().replace("apple_", "").replace("crayon_", "");
        e.graphics().draw_string(name, font(), solid_brush {fore_color()}, 110, (e.clip_rectangle().height - e.graphics().measure_string(name, font()).height) / 2);
      }
      
      auto color() const {return color_;}
      void color(const drawing::color& value) {
        if (color_ != value) {
          color_ = value;
          invalidate();
        }
      }
      
    private:
      drawing::color color_;
    };
    
  public:
    color_chooser() {
      size({300, 250});
      controls().add_range({main_panel_, colors_choice_});

      colors_choice_.location({10, 10});
      colors_choice_.width(280);
      colors_choice_.items().add_range({
        {"Apple - xtd::drawing::apple_colors", &apple_colors::get_colors},
        {"Basic - xtd::drawing::basic_colors", &basic_colors::get_colors},
        {"Blue - xtd::drawing::blue_colors", &blue_colors::get_colors},
        {"Brown - xtd::drawing::brown_colors", &brown_colors::get_colors},
        {"Crayons - xtd::drawing::crayon_colors", &crayon_colors::get_colors},
        {"Cyan - xtd::drawing::cyan_colors", &cyan_colors::get_colors},
        {"Gray - xtd::drawing::gray_colors", &gray_colors::get_colors},
        {"Green - xtd::drawing::green_colors", &green_colors::get_colors},
        {"Orange - xtd::drawing::orange_colors", &orange_colors::get_colors},
        {"Pink - xtd::drawing::pink_colors", &pink_colors::get_colors},
        {"Purple - xtd::drawing::purple_colors", &purple_colors::get_colors},
        {"Red - xtd::drawing::red_colors", &red_colors::get_colors},
        {"White - xtd::drawing::white_colors", &white_colors::get_colors},
        {"Yellow - xtd::drawing::yellow_colors", &yellow_colors::get_colors},
        {"Web - xtd::drawing::colors", &colors::get_colors},
        {"System - xtd::drawing::system_colors", &system_colors::get_colors},
      });
      colors_choice_.selected_index_changed += {*this, &color_chooser::on_colors_choice_selected_index_changed};
      colors_choice_.selected_index(0);

      main_panel_.location({10, 40});
      //main_panel_.padding(2);
      //main_panel_.border_style(border_style::fixed_single);
      main_panel_.back_color(system_colors::window());
      main_panel_.fore_color(system_colors::window_text());
      main_panel_.size({280, 200});
      main_panel_.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
      main_panel_.auto_scroll(true);
    }
    
    size_t selected_index() const {return selected_index_;}
    void selected_index(size_t value) {
      if (selected_index_ == value) return;
      selected_index_ = value;
      on_selected_index_changed(event_args::empty);
    }
    
    const drawing::color& selected_color() const {return selected_color_;}
    void selected_color(const drawing::color& value) {
      if (selected_color_ == value) return;
      selected_color_ = value;
      on_selected_color_changed(event_args::empty);
    }
    
    event<color_chooser, event_handler> selected_index_changed;
    event<color_chooser, event_handler> selected_color_changed;
    
    static const size_t npos = std::numeric_limits<size_t>::max();
    
  private:
    void add_color_panel(const drawing::color& color) {
      auto color_panel = new_ptr<color_chooser::color_panel>();
      color_panel->dock(dock_style::top);
      color_panel->color(color);
      color_panel->tag(colors_.count());
      colors_.add(color_panel);
      main_panel_.controls().add(*color_panel);
      color_panel->click += {*this, &color_chooser::on_color_panel_click};
    }
    
    void on_colors_choice_selected_index_changed(object & sender, const event_args & e) {
      suspend_layout();
      auto index = selected_index();
      selected_index(npos);
      colors_.clear();
      auto colors = as<const array<drawing::color>&(*)() noexcept>(colors_choice_.selected_item().tag());
      for (auto iterator = colors().items().rbegin(); iterator != colors().items().rend(); ++iterator)
        add_color_panel(*iterator);
      if (index == npos || colors_.count() == 0) return;
      if (index < colors_.count()) selected_index(index);
      else selected_index(colors_.count() - 1);
      resume_layout();
    }
    
    void on_color_panel_click(object & sender, const event_args & e) {
      selected_index(npos);
      selected_index(colors_.count() - 1 - as<size_t>(as<control>(sender).tag()));
    }
    
    void on_selected_index_changed(const event_args& e) {
      if (previous_selected_index_ != npos) colors_[colors_.count() - 1 - previous_selected_index_]->back_color(main_panel_.back_color());
      if (previous_selected_index_ != npos) colors_[colors_.count() - 1 - previous_selected_index_]->fore_color(main_panel_.fore_color());
      if (selected_index_ == npos) selected_color(drawing::color::empty);
      else {
        colors_[colors_.count() - 1 - selected_index_]->back_color(drawing::system_colors::accent());
        colors_[colors_.count() - 1 - selected_index_]->fore_color(drawing::system_colors::accent_text());
        selected_color(colors_[colors_.count() - 1 - selected_index_]->color());
      }
      previous_selected_index_ = selected_index_;
      selected_index_changed(*this, e);
    }
    
    void on_selected_color_changed(const event_args& e) {
      for (auto color : colors_)
        if (color->color() == selected_color_) {
          selected_index(colors_.count() - 1 - as<size_t>(color->tag()));
          break;
        }
      selected_color_changed(*this, e);
    }
    
    xtd::size previous_selected_index_ = npos;
    xtd::size selected_index_ = npos;
    drawing::color selected_color_ = drawing::color::empty;
    choice colors_choice_;
    panel main_panel_;
    list<ptr<color_panel>> colors_;
  };
}
