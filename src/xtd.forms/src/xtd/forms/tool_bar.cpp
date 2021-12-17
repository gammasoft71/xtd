#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_pens.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/tool_bar.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

class tool_bar::system_tool_bar : public control {
public:
  system_tool_bar() {
  }
  
  const xtd::forms::image_list& image_list() const {return *image_list_;};
  tool_bar::system_tool_bar& image_list(const xtd::forms::image_list& value) {
    image_list_ = &value;
    return *this;
  }
  
  
  const tool_bar::tool_bar_item_collection& tool_bar_items() const {return tool_bar_items_;}
  tool_bar::system_tool_bar& tool_bar_items(const tool_bar::tool_bar_item_collection& value) {
    tool_bar_items_ = value;
    
    for (auto& item : tool_bar_items_) {
      if (is<tool_bar_button>(item.get())) {
        auto& button_item = as<tool_bar_button>(item.get());
        tool_bar_item_handles_.push_back(native::tool_bar::add_tool_bar_button(handle(), button_item.text(), button_item.image_index() < image_list_->images().size() ? image_list_->images()[button_item.image_index()].handle() : image::empty.handle()));
      } else if (is<tool_bar_separator>(item.get())) {
        tool_bar_item_handles_.push_back(native::tool_bar::add_tool_bar_separator(handle()));
      }
    }
    
    return *this;
  }
  
protected:
  forms::create_params create_params() const override {
    forms::create_params create_params = control::create_params();
    
    create_params.class_name("toolbar");
    
    return create_params;
  }
  
  void wnd_proc(message& message) override {
    if (message.msg() == WM_MENUCOMMAND && handle() == message.hwnd()) wm_click(message);
    else control::wnd_proc(message);
  }
  
private:
  void wm_click(message& message) {
    for (size_t index = 0; index < tool_bar_item_handles_.size(); ++index) {
      if (index < tool_bar_item_handles_.size() && message.wparam() == tool_bar_item_handles_[index]) {
        tool_bar_items_[index].get().perform_click();
        break;
      }
    }
  }
  
  std::vector<intptr_t> tool_bar_item_handles_;
  tool_bar::tool_bar_item_collection tool_bar_items_;
  const xtd::forms::image_list* image_list_ = nullptr;
};

tool_bar::tool_bar_button_control::tool_bar_button_control() {
  set_can_focus(false);
}

tool_bar::tool_bar_separator_control::tool_bar_separator_control() {
  set_can_focus(false);
}

void tool_bar::tool_bar_separator_control::on_paint(paint_event_args& e) {
  control::on_paint(e);
  auto left = e.clip_rectangle().width() / 2;
  auto top = 4;
  auto right = left;
  auto bottom = e.clip_rectangle().height() - 4;
  auto percent_of_color = 1.0/3;
  auto color = back_color().get_lightness() < 0.5 ? xtd::forms::control_paint::light(back_color(), percent_of_color) : xtd::forms::control_paint::dark(back_color(), percent_of_color);
  e.graphics().draw_line(color, point {left, top}, point {right, bottom});
}

tool_bar::tool_bar() {
  data_->items.item_added += {*this, &tool_bar::on_item_added};
  data_->items.item_updated += {*this, &tool_bar::on_item_updated};
  data_->items.item_removed += {*this, &tool_bar::on_item_removed};
  
  data_->image_list.image_size(environment::os_version().is_windows_platform() ? drawing::size {16, 16} : drawing::size {24, 24});
  data_->border_style = forms::border_style::fixed_single;
  dock(xtd::forms::dock_style::top);
  padding(2);
  height(data_->image_list.image_size().height() + 10);
  set_can_focus(false);
}

void tool_bar::on_handle_created(const event_args &e) {
  control::on_handle_created(e);
  if (data_->is_system_tool_bar) create_system_tool_bar();
}

void tool_bar::on_handle_destroyed(const event_args &e) {
  control::on_handle_destroyed(e);
  if (data_->internal_system_tool_bar) data_->internal_system_tool_bar->parent(nullptr);
  data_->internal_system_tool_bar.reset();
}

void tool_bar::on_paint(xtd::forms::paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() == forms::control_appearance::standard)
    control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
}

void tool_bar::set_system_tool_bar() {
  data_->is_system_tool_bar = true;
  if (is_handle_created()) create_system_tool_bar();
}

void tool_bar::reset_system_tool_bar() {
  data_->is_system_tool_bar = false;
  if (is_handle_created()) destroy_system_tool_bar();
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
    height(data_->image_list.image_size().height() + 8);
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

void tool_bar::create_system_tool_bar() {
  if (!data_->is_system_tool_bar) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = parent().value().get().client_size();
  
  data_->internal_system_tool_bar = make_shared<system_tool_bar>();
  data_->internal_system_tool_bar->parent(parent().value().get());
  data_->internal_system_tool_bar->image_list(image_list());
  data_->internal_system_tool_bar->tool_bar_items(items());
  
  if (native::tool_bar::set_system_tool_bar(parent().value().get().handle(), data_->internal_system_tool_bar->handle())) {
    control::hide();
  } else {
    data_->is_system_tool_bar = false;
    data_->internal_system_tool_bar->parent(nullptr);
    data_->internal_system_tool_bar.reset();
  }
  
  // Workaround : Force the client size with the previously saved client size.
  parent().value().get().client_size(prev_client_size);
}

void tool_bar::destroy_system_tool_bar() {
  if (!data_->internal_system_tool_bar) return;
  
  // Workaround : Get client size because afer changing tool bar to system, the client size does not correct.
  auto prev_client_size = parent().value().get().client_size();
  
  native::tool_bar::set_system_tool_bar(handle(), 0);
  data_->internal_system_tool_bar->parent(nullptr);
  data_->internal_system_tool_bar.reset();
  control::show();
  
  // Workaround : Force the client size with the previously saved client size.
  parent().value().get().client_size(prev_client_size);
}
