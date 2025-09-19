#pragma once
#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/panel.hpp"
#include "../../../include/xtd/forms/status_bar.hpp"
#include <xtd/drawing/color_converter>

class xtd::forms::status_bar::sizing_grip_control : public xtd::forms::panel {
public:
  sizing_grip_control() {
    set_can_focus(false);
    cursor(xtd::forms::cursors::size_nwse());
  }
  
protected:
  xtd::uptr<xtd::object> clone() const override {
    auto result = xtd::new_uptr<sizing_grip_control>(*this);
    if (typeof_(*result) != typeof_(*this)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_cast, xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()).chars().c_str());
    return result;
  }
  
  void on_paint(paint_event_args& e) override {
    /// @todo Replace following code by drawing style_sheet sizing grip image.
    auto sizing_grip_color = back_color().is_dark() ? xtd::drawing::color_converter::light(back_color()) : xtd::drawing::color_converter::dark(back_color());
    auto offset_sizing_grip = 2;
    auto rectangles = xtd::array<xtd::drawing::rectangle> {{e.clip_rectangle().right() - 4 - offset_sizing_grip, e.clip_rectangle().bottom() - 10 - offset_sizing_grip, 2, 2}, {e.clip_rectangle().right() - 7 - offset_sizing_grip, e.clip_rectangle().bottom() - 7 - offset_sizing_grip, 2, 2}, {e.clip_rectangle().right() - 4 - offset_sizing_grip, e.clip_rectangle().bottom() - 7 - offset_sizing_grip, 2, 2}, {e.clip_rectangle().right() - 10 - offset_sizing_grip, e.clip_rectangle().bottom() - 4 - offset_sizing_grip, 2, 2}, {e.clip_rectangle().right() - 7 - offset_sizing_grip, e.clip_rectangle().bottom() - 4 - offset_sizing_grip, 2, 2}, {e.clip_rectangle().right() - 4 - offset_sizing_grip, e.clip_rectangle().bottom() - 4 - offset_sizing_grip, 2, 2}};
    e.graphics().fill_rectangles(xtd::drawing::solid_brush(sizing_grip_color), rectangles);
    control::on_paint(e);
  }
  
  void on_mouse_down(const mouse_event_args& e) override {
    mouse_location = e.location();
  };
  
  void on_mouse_up(const mouse_event_args& e) override {
    mouse_location = xtd::drawing::point::empty;
  };
  
  void on_mouse_move(const mouse_event_args& e) override {
    if (mouse_location != xtd::drawing::point::empty && top_level_control().has_value())
      top_level_control().value().get().size(top_level_control().value().get().size() + xtd::drawing::size(e.location() - mouse_location));
  };
  
  
private:
  friend status_bar;
  xtd::drawing::point mouse_location = xtd::drawing::point::empty;
};
