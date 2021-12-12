#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_pens.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/tool_bar.h"
#include "../../../include/xtd/forms/tool_bar_images.h"

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

void tool_bar::tool_bar_separator_control::on_paint(paint_event_args& e) {
  control::on_paint(e);
  auto left = e.clip_rectangle().width() / 2;
  auto top = 4;
  auto right = left;
  auto bottom = e.clip_rectangle().height() - 4;

  e.graphics().draw_line(system_pens::gray_text(), point {left, top}, point {right, bottom});
}

tool_bar::tool_bar() {
  data_->items.item_added += {*this, &tool_bar::on_item_added};
  data_->items.item_updated += {*this, &tool_bar::on_item_updated};
  data_->items.item_removed += {*this, &tool_bar::on_item_removed};
  
  data_->image_list.image_size(tool_bar_images::size());
  data_->border_style = forms::border_style::fixed_single;
  dock(xtd::forms::dock_style::top);
  padding(2);
  size(default_size());
  height(tool_bar_images::size().height() + 10);
}

void tool_bar::on_paint(xtd::forms::paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() == forms::control_appearance::standard)
    control_paint::draw_border_from_back_color(e.graphics(), data_->border_style, back_color(), e.clip_rectangle());
}

void tool_bar::fill() {
  controls().clear();
  data_->tool_bar_items.clear();
  auto reversed_items = data_->items;
  std::reverse(reversed_items.begin(), reversed_items.end());
  for (auto& item : reversed_items) {
    if (is<tool_bar_button>(item.get())) {
      auto& button_item = as<tool_bar_button>(item.get());
      auto button_control = std::make_shared<tool_bar_button_control>();
      
      button_control->parent(*this);
      button_control->tool_bar_item(button_item);
      button_control->dock(dock_style::left);
      button_control->flat_style(xtd::forms::flat_style::flat);
      button_control->flat_appearance().border_size(0);
      button_control->image_align(content_alignment::middle_center);
      button_control->width(data_->image_list.image_size().width() + 6);
      
      if (button_item.image_index() < data_->image_list.images().size()) button_control->image(data_->image_list.images()[button_item.image_index()]);
      //button_control->text(button_item.text());
      data_->tool_bar_items.push_back(button_control);
    } else if (is<tool_bar_separator>(item.get())) {
      //auto& separator_item = as<tool_bar_button>(item.get());
      auto separator_control = std::make_shared<tool_bar_separator_control>();
      separator_control->parent(*this);
      separator_control->dock(dock_style::left);
      separator_control->width(data_->image_list.image_size().width() / 2);
      data_->tool_bar_items.push_back(separator_control);
    }
  }
}

void tool_bar::on_item_added(size_t pos, tool_bar_item_ref item) {
  fill();
}

void tool_bar::on_item_updated(size_t pos, tool_bar_item_ref item) {
  fill();
}

void tool_bar::on_item_removed(size_t pos, tool_bar_item_ref item) {
  fill();
}

const xtd::forms::image_list& tool_bar::image_list() const {
  return data_->image_list;
}

xtd::forms::image_list& tool_bar::image_list() {
  return data_->image_list;
}

xtd::forms::tool_bar& tool_bar::image_list(const xtd::forms::image_list& value) {
  if (data_->image_list != value) {
    data_->image_list = value;
    height(tool_bar_images::size().height() + 8);
  }
  return *this;
}

xtd::drawing::size tool_bar::default_size() const {
  return {200, 40};
}

const tool_bar::tool_bar_item_collection& tool_bar::items() const {
  return data_->items;
}

tool_bar::tool_bar_item_collection& tool_bar::items() {
  return data_->items;
}
