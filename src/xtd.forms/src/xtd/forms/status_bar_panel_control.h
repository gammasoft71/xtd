#pragma once
#include "../../../include/xtd/forms/label.h"
#include "../../../include/xtd/forms/status_bar.h"

class xtd::forms::status_bar::status_bar_panel_control : public xtd::forms::label {
public:
  status_bar_panel_control() {
    set_can_focus(false);
  }
  
  void control(const xtd::forms::control* value) {
    if (data_->control != value) {
      data_->control = value;
      update_size();
    }
  }
  
  xtd::drawing::font default_font() const override {return xtd::drawing::system_fonts::tool_font();}
  
  using xtd::forms::label::image;
  label& image(const xtd::drawing::image& value) override {
    if (image() != value) {
      label::image(value);
      update_size();
    }
    return *this;
  }
  
  bool is_horizontal() const {return dock() == dock_style::left || dock() == dock_style::right;}
  
  xtd::drawing::size size() const override {return control::size();}
  
  xtd::forms::control& size(const xtd::drawing::size& value) override {
    if (size() != value) {
      control::size(value);
      update_size();
    }
    return *this;
  }
  
  xtd::forms::status_bar_panel_style style() const {return data_->style;}
  
  void style(xtd::forms::status_bar_panel_style value) {
    if (data_->style != value) {
      data_->style = value;
      update_size();
    }
  }
  
  using xtd::forms::control::text;
  xtd::forms::control& text(const xtd::ustring& value) override {
    if (text() != value) {
      label::text(value);
      update_size();
    }
    return *this;
  }
  
  void status_bar_panel_auto_size(xtd::forms::status_bar_panel_auto_size value) {
    if (data_->status_bar_panel_auto_size != value) {
      data_->status_bar_panel_auto_size = value;
      update_size();
    }
  }
  
  void status_bar_panel(status_bar_panel_ref value) {data_->status_bar_panel = value;}
  
protected:
  void on_paint(paint_event_args& e) override {
    if (data_->style == status_bar_panel_style::text) draw_panel(e);
    else if (data_->style == status_bar_panel_style::control) draw_control(e);
    control::on_paint(e);
  }
  
private:
  friend status_bar;
  
  void draw_panel(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    status_bar_panel_renderer::draw_status_bar_panel(style, e.graphics(), e.clip_rectangle(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
  }
  
  void draw_control(xtd::forms::paint_event_args& e) {
    auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
    xtd::forms::style_sheets::status_bar_panel current_style_sheet = style.status_bar_panel(xtd::forms::style_sheets::pseudo_state::standard);
    current_style_sheet.font(font());
    xtd::drawing::rectangle text_rect = current_style_sheet.get_content_rectangle(e.clip_rectangle());
    text_renderer::draw_text(e.graphics(), text_rect, text(), current_style_sheet);
  }
  
  void update_size() {
    auto size = this->size();
    
    this->size(size);
  }
  
  struct data {
    const xtd::forms::control* control = nullptr;
    std::optional<status_bar_panel_ref> status_bar_panel;
    xtd::forms::status_bar_panel_style style = xtd::forms::status_bar_panel_style::text;
    xtd::forms::status_bar_panel_auto_size status_bar_panel_auto_size = xtd::forms::status_bar_panel_auto_size::none;
  };
  
  std::shared_ptr<data> data_ = std::make_shared<data>();
};
