#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/drawing/apple_colors>
#include <xtd/drawing/basic_colors>
#include <xtd/drawing/blue_colors>
#include <xtd/drawing/brown_colors>
#include <xtd/drawing/colors>
#include <xtd/drawing/crayons_colors>
#include <xtd/drawing/cyan_colors>
#include <xtd/drawing/gray_colors>
#include <xtd/drawing/green_colors>
#include <xtd/drawing/orange_colors>
#include <xtd/drawing/pink_colors>
#include <xtd/drawing/purple_colors>
#include <xtd/drawing/red_colors>
#include <xtd/drawing/white_colors>
#include <xtd/drawing/yellow_colors>
#include <xtd/drawing/system_colors>
#include <xtd/forms/choice>
#include <xtd/forms/user_control>
#include <xtd/as>

namespace colors_example {
  class color_chooser final : public xtd::forms::user_control {
    class color_panel final : public xtd::forms::user_control {
    public:
      color_panel() {
        size({200, 40});
        color(xtd::drawing::color::empty);
      }
      
      void on_paint(xtd::forms::paint_event_args& e) override {
        xtd::forms::user_control::on_paint(e);
        e.graphics().fill_rectangle(xtd::drawing::drawing_2d::hatch_brush(xtd::drawing::drawing_2d::hatch_style::wide_checker_board, xtd::drawing::color::from_argb(0x54, 0x54, 0x54), xtd::drawing::color::from_argb(0xA8, 0xA8, 0xA8)), 6, 4, 94, e.clip_rectangle().height() - 8);
        e.graphics().fill_rectangle(xtd::drawing::solid_brush(color_), 6, 4, 94, e.clip_rectangle().height() - 8);
        auto name = color_.name().replace("apple_", "").replace("crayons_", "");
        e.graphics().draw_string(name, font(), xtd::drawing::solid_brush {fore_color()}, 110, (e.clip_rectangle().height() - e.graphics().measure_string(name, font()).height()) / 2);
      }
      
      auto color() const {return color_;}
      void color(const xtd::drawing::color& value) {
        if (color_ != value) {
          color_ = value;
          invalidate();
        }
      }
      
    private:
      xtd::drawing::color color_;
    };
    
  public:
    color_chooser() {
      border_style(xtd::forms::border_style::fixed_3d);
      back_color(xtd::drawing::system_colors::window());
      fore_color(xtd::drawing::system_colors::window_text());
      controls().push_back_range({main_panel, colors_choice});
      padding(4);

      colors_choice.dock(xtd::forms::dock_style::top);
      colors_choice.items().push_back_range({
        {"Basic - xtd::drawing::basic_colors", &xtd::drawing::basic_colors::get_colors},
        {"Apple - xtd::drawing::apple_colors", &xtd::drawing::apple_colors::get_colors},
        {"Blue - xtd::drawing::blue_colors", &xtd::drawing::blue_colors::get_colors},
        {"Brown - xtd::drawing::brown_colors", &xtd::drawing::brown_colors::get_colors},
        {"Crayons - xtd::drawing::crayons_colors", &xtd::drawing::crayons_colors::get_colors},
        {"Cyan - xtd::drawing::cyan_colors", &xtd::drawing::cyan_colors::get_colors},
        {"Gray - xtd::drawing::gray_colors", &xtd::drawing::gray_colors::get_colors},
        {"Green - xtd::drawing::green_colors", &xtd::drawing::green_colors::get_colors},
        {"Orange - xtd::drawing::orange_colors", &xtd::drawing::orange_colors::get_colors},
        {"Pink - xtd::drawing::pink_colors", &xtd::drawing::pink_colors::get_colors},
        {"Purple - xtd::drawing::purple_colors", &xtd::drawing::purple_colors::get_colors},
        {"Red - xtd::drawing::red_colors", &xtd::drawing::red_colors::get_colors},
        {"White - xtd::drawing::white_colors", &xtd::drawing::white_colors::get_colors},
        {"Yellow - xtd::drawing::yellow_colors", &xtd::drawing::yellow_colors::get_colors},
        {"Web - xtd::drawing::colors", &xtd::drawing::colors::get_colors},
        {"System - xtd::drawing::system_colors", &xtd::drawing::system_colors::get_colors},
      });
      colors_choice.selected_index_changed += [&] {
        auto index = selected_index();
        selected_index(npos);
        colors_.clear();
        auto colors = std::any_cast<const std::vector<xtd::drawing::color>&(*)() noexcept>(colors_choice.selected_item().tag());
        for (auto iterator = colors().rbegin(); iterator != colors().rend(); ++iterator)
          add_color_panel(*iterator);
        if (index == npos || colors_.size() == 0) return;
        if (index < colors_.size()) selected_index(index);
        else selected_index(colors_.size() - 1);
        
      };
      colors_choice.selected_index(0);

      main_panel.dock(xtd::forms::dock_style::fill);
      main_panel.auto_scroll(true);
    }
    
    size_t selected_index() const {return selected_index_;}
    void selected_index(size_t value) {
      if (selected_index_ != value) {
        selected_index_ = value;
        on_selected_index_changed(xtd::event_args::empty);
      }
    }
    
    const xtd::drawing::color& selected_color() const {return selected_color_;}
    void selected_color(const xtd::drawing::color& value) {
      if (selected_color_ != value) {
        selected_color_ = value;
        on_selected_color_changed(xtd::event_args::empty);
      }
    }
    
    xtd::event<color_chooser, xtd::event_handler> selected_index_changed;
    xtd::event<color_chooser, xtd::event_handler> selected_color_changed;
    
    static const size_t npos = std::numeric_limits<size_t>::max();
    
  private:
    void add_color_panel(const xtd::drawing::color& color) {
      auto color_panel = std::make_shared<color_chooser::color_panel>();
      color_panel->dock(xtd::forms::dock_style::top);
      color_panel->color(color);
      color_panel->tag(colors_.size());
      colors_.push_back(color_panel);
      main_panel.controls().push_back(*color_panel);
      color_panel->click += [&](xtd::object & sender, const xtd::event_args & e) {
        selected_index(colors_.size() - 1 - std::any_cast<size_t>(xtd::as<control>(sender).tag()));
      };
    }
    
    void on_selected_index_changed(const xtd::event_args& e) {
      if (previous_selected_index_ != npos) colors_[colors_.size() - 1 - previous_selected_index_]->back_color(back_color());
      if (previous_selected_index_ != npos) colors_[colors_.size() - 1 - previous_selected_index_]->fore_color(fore_color());
      if (selected_index_ == npos)
        selected_color(xtd::drawing::color::empty);
      else {
        colors_[colors_.size() - 1 - selected_index_]->back_color(xtd::drawing::system_colors::accent());
        colors_[colors_.size() - 1 - selected_index_]->fore_color(xtd::drawing::system_colors::accent_text());
        selected_color(colors_[colors_.size() - 1 - selected_index_]->color());
      }
      previous_selected_index_ = selected_index_;
      selected_index_changed(*this, e);
    }
    
    void on_selected_color_changed(const xtd::event_args& e) {
      for (auto color : colors_)
        if (color->color() == selected_color_) {
          selected_index(colors_.size() - 1 - std::any_cast<size_t>(color->tag()));
          break;
        }
      selected_color_changed(*this, e);
    }
    
    size_t previous_selected_index_ = npos;
    size_t selected_index_ = npos;
    xtd::drawing::color selected_color_ = xtd::drawing::color::empty;
    xtd::forms::choice colors_choice;
    xtd::forms::panel main_panel;
    std::vector<std::shared_ptr<color_panel>> colors_;
  };
}
