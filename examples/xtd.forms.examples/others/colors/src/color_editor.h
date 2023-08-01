#include <xtd/drawing/drawing_2d/hatch_brush>
#include <xtd/forms/control_paint>
#include <xtd/forms/label>
#include <xtd/forms/numeric_up_down>
#include <xtd/forms/panel>
#include <xtd/forms/track_bar>
#include <xtd/forms/user_control>

namespace colors_example {
  class color_editor final : public xtd::forms::user_control {
  public:
    color_editor() {
      border_style(xtd::forms::border_style::fixed_3d);
      size({300, 400});
      minimum_size(size());
      
      label_alpha.parent(*this);
      label_alpha.location({10, 15});
      label_alpha.auto_size(true);
      label_alpha.text("A");
      
      track_bar_alpha.parent(*this);
      track_bar_alpha.location({40, 12});
      track_bar_alpha.auto_size(false);
      track_bar_alpha.maximum(255);
      track_bar_alpha.size({190, 25});
      track_bar_alpha.tick_style(xtd::forms::tick_style::none);
      track_bar_alpha.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      track_bar_alpha.value_changed += [&] {
        color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(track_bar_alpha.value()), color_.r(), color_.g(), color_.b()));
      };
      
      numeric_up_down_alpha.parent(*this);
      numeric_up_down_alpha.bounds({240, 12, 50, 20});
      numeric_up_down_alpha.minimum(0);
      numeric_up_down_alpha.maximum(255);
      numeric_up_down_alpha.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      numeric_up_down_alpha.value_changed += [&] {
        color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(numeric_up_down_alpha.value()), color_.r(), color_.g(), color_.b()));
      };
      
      label_red.parent(*this);
      label_red.location({10, 60});
      label_red.auto_size(true);
      label_red.text("R");
      
      track_bar_red.parent(*this);
      track_bar_red.location({40, 57});
      track_bar_red.auto_size(false);
      track_bar_red.maximum(255);
      track_bar_red.size({190, 25});
      track_bar_red.tick_style(xtd::forms::tick_style::none);
      track_bar_red.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      track_bar_red.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), xtd::as<unsigned char>(track_bar_red.value()), color_.g(), color_.b()));
      };
      
      numeric_up_down_red.parent(*this);
      numeric_up_down_red.bounds({240, 57, 50, 20});
      numeric_up_down_red.minimum(0);
      numeric_up_down_red.maximum(255);
      numeric_up_down_red.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      numeric_up_down_red.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), xtd::as<unsigned char>(numeric_up_down_red.value()), color_.g(), color_.b()));
      };
      
      label_green.parent(*this);
      label_green.location({10, 105});
      label_green.auto_size(true);
      label_green.text("G");
      
      track_bar_green.parent(*this);
      track_bar_green.location({40, 102});
      track_bar_green.auto_size(false);
      track_bar_green.maximum(255);
      track_bar_green.size({190, 25});
      track_bar_green.tick_style(xtd::forms::tick_style::none);
      track_bar_green.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      track_bar_green.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), color_.r(), xtd::as<unsigned char>(track_bar_green.value()), color_.b()));
      };
      
      numeric_up_down_green.parent(*this);
      numeric_up_down_green.bounds({240, 102, 50, 20});
      numeric_up_down_green.minimum(0);
      numeric_up_down_green.maximum(255);
      numeric_up_down_green.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      numeric_up_down_green.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), color_.r(), xtd::as<unsigned char>(numeric_up_down_green.value()), color_.b()));
      };
      
      label_blue.parent(*this);
      label_blue.location({10, 150});
      label_blue.auto_size(true);
      label_blue.text("B");
      
      track_bar_blue.parent(*this);
      track_bar_blue.location({40, 147});
      track_bar_blue.auto_size(false);
      track_bar_blue.maximum(255);
      track_bar_blue.size({190, 25});
      track_bar_blue.tick_style(xtd::forms::tick_style::none);
      track_bar_blue.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::right);
      track_bar_blue.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), color_.r(), color_.g(), xtd::as<unsigned char>(track_bar_blue.value())));
      };
      
      numeric_up_down_blue.parent(*this);
      numeric_up_down_blue.bounds({240, 147, 50, 20});
      numeric_up_down_blue.minimum(0);
      numeric_up_down_blue.maximum(255);
      numeric_up_down_blue.anchor(xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right);
      numeric_up_down_blue.value_changed += [&] {
        color(xtd::drawing::color::from_argb(color_.a(), color_.r(), color_.g(), xtd::as<unsigned char>(numeric_up_down_blue.value())));
      };
      
      panel_color_box.parent(*this);
      panel_color_box.location({55, 195});
      panel_color_box.size({190, 190});
      panel_color_box.double_buffered(true);
      panel_color_box.border_style(xtd::forms::border_style::fixed_3d);
      panel_color_box.anchor(xtd::forms::anchor_styles::left | xtd::forms::anchor_styles::top | xtd::forms::anchor_styles::right | xtd::forms::anchor_styles::bottom);
      panel_color_box.paint += [&](xtd::object& sender, xtd::forms::paint_event_args& e) {
        e.graphics().fill_rectangle(xtd::drawing::drawing_2d::hatch_brush(xtd::drawing::drawing_2d::hatch_style::wide_checker_board, xtd::drawing::color::from_argb(0x54, 0x54, 0x54), xtd::drawing::color::from_argb(0xA8, 0xA8, 0xA8)), e.clip_rectangle());
        e.graphics().fill_rectangle(xtd::drawing::solid_brush(color_), e.clip_rectangle());
        xtd::forms::control_paint::draw_border(panel_color_box, e.graphics(), panel_color_box.border_style(), panel_color_box.border_sides(), xtd::forms::application::style_sheet().system_colors().control_text(), e.clip_rectangle());
      };
    }
    
    void color(const xtd::drawing::color& value) {
      if (color_ != value) {
        color_ = value;
        on_color_changed(xtd::event_args::empty);
      }
    }
    
    xtd::event<color_editor, xtd::event_handler> color_changed;
    
  protected:
    void on_color_changed(const xtd::event_args& e) {
      panel_color_box.invalidate();
      track_bar_alpha.value(color_.a());
      numeric_up_down_alpha.value(color_.a());
      track_bar_red.value(color_.r());
      numeric_up_down_red.value(color_.r());
      track_bar_green.value(color_.g());
      numeric_up_down_green.value(color_.g());
      track_bar_blue.value(color_.b());
      numeric_up_down_blue.value(color_.b());
      color_changed(*this, e);
    }
    
  private:
  
    void on_argb_changed() {
      color(xtd::drawing::color::from_argb(xtd::as<unsigned char>(track_bar_alpha.value()), xtd::as<unsigned char>(track_bar_red.value()), xtd::as<unsigned char>(track_bar_green.value()), xtd::as<unsigned char>(track_bar_blue.value())));
    }
    
    xtd::forms::label label_alpha;
    xtd::forms::label label_red;
    xtd::forms::label label_green;
    xtd::forms::label label_blue;
    xtd::forms::track_bar track_bar_alpha;
    xtd::forms::track_bar track_bar_red;
    xtd::forms::track_bar track_bar_green;
    xtd::forms::track_bar track_bar_blue;
    xtd::forms::numeric_up_down numeric_up_down_alpha;
    xtd::forms::numeric_up_down numeric_up_down_red;
    xtd::forms::numeric_up_down numeric_up_down_green;
    xtd::forms::numeric_up_down numeric_up_down_blue;
    xtd::forms::panel panel_color_box;
    xtd::drawing::color color_ = xtd::drawing::color::empty;
  };
}
