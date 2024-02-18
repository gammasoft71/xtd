#include <xtd/drawing/apple_colors>
#include <xtd/drawing/colors>
#include <xtd/drawing/system_colors>
#include <xtd/forms/user_control>
#include <xtd/as>

namespace colors_example {
  class color_chooser final : public xtd::forms::user_control {
    class color_panel final : public xtd::forms::user_control {
    public:
      color_panel() {
        size({200, 30});
        color(xtd::drawing::color::empty);
      }
      
      void on_paint(xtd::forms::paint_event_args& e) override {
        xtd::forms::user_control::on_paint(e);
        e.graphics().fill_rectangle(xtd::drawing::solid_brush {xtd::drawing::system_colors::control()}, 0, 0, 100, e.clip_rectangle().height());
        e.graphics().fill_rectangle(xtd::drawing::solid_brush(color_), 0, 0, 100, e.clip_rectangle().height());
        e.graphics().draw_string(color_.name(), font(), xtd::drawing::solid_brush {fore_color()}, 120, (e.clip_rectangle().height() - e.graphics().measure_string(color_.name(), font()).height()) / 2);
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
      auto_scroll(true);
      
      for (auto iterator = xtd::drawing::apple_colors::get_colors().rbegin(); iterator != xtd::drawing::apple_colors::get_colors().rend(); ++iterator)
        add_color_panel(*iterator);

      for (auto iterator = xtd::drawing::system_colors::get_colors().rbegin(); iterator != xtd::drawing::system_colors::get_colors().rend(); ++iterator)
        add_color_panel(*iterator);
      
      for (auto iterator = xtd::drawing::colors::get_colors().rbegin(); iterator != xtd::drawing::colors::get_colors().rend(); ++iterator)
        add_color_panel(*iterator);
    }
    
    auto selected_index() const {return selected_index_;}
    void selected_index(size_t value) {
      if (selected_index_ != value) {
        selected_index_ = value;
        on_selected_index_changed(xtd::event_args::empty);
      }
    }
    
    auto selected_color() const {return selected_color_;}
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
      controls().push_back(*color_panel);
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
    std::vector<std::shared_ptr<color_panel>> colors_;
  };
}
