#pragma once
#include "../../../include/xtd/forms/border_style.h"
#include "../../../include/xtd/forms/horizontal_alignment.h"
#include "../../../include/xtd/forms/image_renderer.h"
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/status_bar.h"
#include "../../../include/xtd/forms/status_bar_panel_border_style.h"

class xtd::forms::status_bar::status_bar_panel_control : public xtd::forms::label {
public:
  status_bar_panel_control() {
    set_can_focus(false);
  }
  
  void alignment(xtd::forms::horizontal_alignment value) {
    data_->alignment = value;
  }
  
  status_bar_panel_control& control(const xtd::forms::control* value) {
    if (data_->control == value) return *this;
    data_->control = value;
    update_size();
    return *this;
  }
  
  using xtd::forms::label::image;
  label& image(const xtd::drawing::image& value) override {
    if (image() == value) return *this;
    label::image(value);
    update_size();
    return *this;
  }
  
  bool is_horizontal() const {return dock() == dock_style::left || dock() == dock_style::right;}
  
  status_bar_panel_control& min_width(int32 value) {
    data_->min_width = value;
    return *this;
  }
  
  xtd::drawing::size size() const noexcept override {return control::size();}
  
  xtd::forms::control& size(const xtd::drawing::size& value) override {
    if (size() == value) return *this;
    control::size(value);
    update_size();
    return *this;
  }
  
  xtd::forms::status_bar_panel_style style() const {return data_->style;}
  
  status_bar_panel_control& style(xtd::forms::status_bar_panel_style value) {
    if (data_->style == value) return *this;
    data_->style = value;
    update_size();
    return *this;
  }
  
  using xtd::forms::control::text;
  xtd::forms::control& text(const xtd::ustring& value) override {
    if (text() == value) return *this;
    label::text(value);
    update_size();
    return *this;
  }
  
  void tool_tip_text(const xtd::ustring& value) {
    data_->tool_tip_text = value;
  }
  
  status_bar_panel_control& status_bar_panel_auto_size(xtd::forms::status_bar_panel_auto_size value) {
    if (data_->status_bar_panel_auto_size == value) return *this;
    data_->status_bar_panel_auto_size = value;
    update_size();
    return *this;
  }
  
  status_bar_panel_control& status_bar_panel_border_style(xtd::forms::status_bar_panel_border_style value) {
    data_->status_bar_panel_border_style = value;
    return *this;
  }
  
  status_bar_panel_control& status_bar_panel(status_bar_panel_ref value) {
    data_->status_bar_panel = value;
    return *this;
  }
  
protected:
  xtd::drawing::font default_font() const noexcept override {return xtd::drawing::system_fonts::tool_font();}
  
  void on_paint(paint_event_args& e) override {
    if (data_->style == status_bar_panel_style::text) draw_panel(e);
    else if (data_->style == status_bar_panel_style::control) draw_control(e);
    control::on_paint(e);
  }
  
private:
  friend status_bar;
  
  void draw_panel(xtd::forms::paint_event_args& e) {
    auto sstyle = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    xtd::forms::style_sheets::status_bar_panel current_style_sheet = sstyle.status_bar_panel(xtd::forms::style_sheets::pseudo_state::standard);
    current_style_sheet.font(font());
    auto content_rectangle = current_style_sheet.get_content_rectangle(e.clip_rectangle());
    auto image_rect = content_rectangle;
    auto text_rect = content_rectangle;
    if (data_->alignment == horizontal_alignment::left) {
      image_rect.width(image().width());
      image_rect.height(image().height());
      text_rect.x(image_rect.x() + image_rect.width());
      text_rect.width(text_rect.width() - image_rect.width());
    } else if (data_->alignment == horizontal_alignment::center) {
      auto image_and_text_width = image().width() + as<int32>(e.graphics().measure_string(text(), current_style_sheet.font(), xtd::drawing::size_f(0.0f, 0.0f), xtd::drawing::string_format(xtd::drawing::string_format_flags::measure_trailing_spaces)).width());
      image_rect.x(content_rectangle.width() / 2 - image_and_text_width / 2);
      image_rect.width(image().width());
      image_rect.height(image().height());
      text_rect.x(image_rect.x() + image_rect.width());
      text_rect.width(text_rect.width() - image_rect.width());
    } else if (data_->alignment == horizontal_alignment::right) {
      auto text_width = as<int32>(e.graphics().measure_string(text(), current_style_sheet.font(), xtd::drawing::size_f(0.0f, 0.0f), xtd::drawing::string_format(xtd::drawing::string_format_flags::measure_trailing_spaces)).width());
      text_rect.x(text_rect.x() + content_rectangle.right() - text_width);
      text_rect.width(text_rect.width() - text_width);
      image_rect.x(text_rect.x() - image().width());
      image_rect.width(image().width());
      image_rect.height(image().height());
    }
    image_renderer::draw_image(e.graphics(), image_rect, image(), true, xtd::drawing::color::transparent, current_style_sheet);
    text_renderer::draw_text(e.graphics(), text_rect, text(), current_style_sheet);
  }
  
  void draw_control(xtd::forms::paint_event_args& e) {
    auto sstyle = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    status_bar_panel_renderer::draw_status_bar_panel(sstyle, e.graphics(), e.clip_rectangle(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
  }
  
  void update_size() {
    auto current_size = this->size();
    
    this->size(current_size);
  }
  
  struct data {
    const xtd::forms::control* control = nullptr;
    xtd::forms::horizontal_alignment alignment = xtd::forms::horizontal_alignment::left;
    int32 min_width = 0;
    std::optional<status_bar_panel_ref> status_bar_panel;
    xtd::forms::status_bar_panel_style style = xtd::forms::status_bar_panel_style::text;
    xtd::forms::status_bar_panel_border_style status_bar_panel_border_style = xtd::forms::status_bar_panel_border_style::none;
    xtd::forms::status_bar_panel_auto_size status_bar_panel_auto_size = xtd::forms::status_bar_panel_auto_size::none;
    xtd::ustring tool_tip_text;
  };
  
  std::shared_ptr<data> data_ = std::make_shared<data>();
};
