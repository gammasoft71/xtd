#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/tool_bar.h"
#include "../../../include/xtd/forms/tool_bar_renderer.h"
#include "../../../include/xtd/forms/tool_bar_button_renderer.h"
#include "tool_bar_button_control.h"
#include "tool_bar_button_data.h"
#include <xtd/drawing/system_pens>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/control>
#include <xtd/forms/native/tool_bar>
#include <xtd/forms/native/tool_bar_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages>
#include <xtd/as>
#include <xtd/is>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  struct parent_client_size_guard {
    explicit parent_client_size_guard(control& control) : control_(&control) {
      client_size_ = control_->parent().value().get().client_size();
    }
    
    ~parent_client_size_guard() {
      control_->parent().value().get().client_size(client_size_);
    }
    
  private:
    control* control_;
    drawing::size client_size_;
  };
}

struct tool_bar::data {
  xtd::forms::tool_bar_appearance appearance = xtd::forms::tool_bar_appearance::normal;
  forms::border_sides border_sides = forms::border_sides::all;
  std::optional<xtd::forms::border_style> border_style;
  std::optional<xtd::drawing::size> button_size;
  bool divider = true;
  bool drop_down_arrows = true;
  xtd::forms::image_list image_list;
  tool_bar_button_collection buttons;
  bool is_system_tool_bar = false;
  dock_style non_system_dock = dock_style::none;
  bool show_icon = true;
  bool show_text = false;
  bool show_tool_tips = false;
  std::vector<std::shared_ptr<xtd::forms::tool_bar::tool_bar_button_control>> stretchable_separators;
  std::vector<std::shared_ptr<xtd::forms::tool_bar::tool_bar_button_control>> tool_bar_buttons;
  std::vector<intptr> system_tool_bar_button_handles;
  xtd::forms::tool_bar_text_align text_align = xtd::forms::tool_bar_text_align::underneath;
  bool wrappable = false;
};

tool_bar::tool_bar() : data_(std::make_shared<data>()) {
  data_->buttons.item_added += {*this, &tool_bar::on_item_added};
  data_->buttons.item_updated += {*this, &tool_bar::on_item_updated};
  data_->buttons.item_removed += {*this, &tool_bar::on_item_removed};
  
  if (environment::os_version().is_windows_platform()) data_->image_list.image_size(drawing::size {16, 16});
  else if (environment::os_version().is_macos_platform()) data_->image_list.image_size(drawing::size {32, 32});
  else data_->image_list.image_size(drawing::size {24, 24});
  
  auto_size(true);
  dock(dock_style::top);
  padding(forms::padding {2});
  set_can_focus(false);
  set_style(control_styles::user_paint, false);
  set_style(control_styles::fixed_height, auto_size());
  set_style(control_styles::fixed_width, false);
  
}

xtd::forms::tool_bar_appearance tool_bar::appearance() const noexcept {
  return data_->appearance;
}

tool_bar& tool_bar::appearance(xtd::forms::tool_bar_appearance value) {
  if (data_->appearance == value) return *this;
  data_->appearance = value;
  if (value != tool_bar_appearance::system) invalidate();
  else  post_recreate_handle();
  return *this;
}

forms::border_sides tool_bar::border_sides() const noexcept {
  return data_->border_sides;
}

tool_bar& tool_bar::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides == border_sides) return *this;
  data_->border_sides = border_sides;
  if (control_appearance() == forms::control_appearance::standard) invalidate();
  return *this;
}

forms::border_style tool_bar::border_style() const noexcept {
  return data_->border_style.value_or(xtd::forms::border_style::none);
}

tool_bar& tool_bar::border_style(forms::border_style border_style) {
  if (data_->border_style == border_style) return *this;
  data_->border_style = border_style;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

tool_bar& tool_bar::border_style(std::nullptr_t) {
  if (!data_->border_style) return *this;
  data_->border_style.reset();
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

xtd::drawing::size tool_bar::button_size() const noexcept {
  return data_->button_size.value_or(image_size() + drawing::size(12, 12));
}

tool_bar& tool_bar::button_size(const xtd::drawing::size& value) {
  if (data_->button_size.has_value() && data_->button_size == value) return *this;
  data_->button_size = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

tool_bar& tool_bar::button_size(std::nullptr_t) {
  if (!data_->button_size.has_value()) return *this;
  data_->button_size.reset();
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

bool tool_bar::divider() const noexcept {
  return data_->divider;
}

tool_bar& tool_bar::divider(bool value) {
  if (data_->divider == value) return *this;
  data_->divider = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

dock_style tool_bar::dock() const noexcept {
  //if (is_system_tool_bar()) return data_->non_system_dock;
  return control::dock();
}

control& tool_bar::dock(dock_style dock) {
  if (is_system_tool_bar()) {
    data_->non_system_dock = dock;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  } else {
    int32 current_size = is_horizontal() ? height() : width();
    control::dock(dock);
    if (is_horizontal()) height(current_size);
    else width(current_size);
  }
  return *this;
}

bool tool_bar::drop_down_arrows() const noexcept {
  return data_->drop_down_arrows;
}

tool_bar& tool_bar::drop_down_arrows(bool value) {
  if (data_->drop_down_arrows == value) return *this;
  data_->drop_down_arrows = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  return *this;
}

const xtd::forms::image_list& tool_bar::image_list() const noexcept {
  return data_->image_list;
}

xtd::forms::image_list& tool_bar::image_list() {
  return data_->image_list;
}

xtd::forms::tool_bar& tool_bar::image_list(const xtd::forms::image_list& value) {
  if (data_->image_list == value) return *this;
  data_->image_list = value;
  height(data_->image_list.image_size().height() + 8);
  return *this;
}

xtd::drawing::size tool_bar::image_size() const noexcept {
  return data_->image_list.image_size();
}

const tool_bar::tool_bar_button_collection& tool_bar::buttons() const noexcept {
  return data_->buttons;
}

tool_bar::tool_bar_button_collection& tool_bar::buttons() {
  return data_->buttons;
}

bool tool_bar::show_icon() const noexcept {
  return data_->show_icon;
}

tool_bar& tool_bar::show_icon(bool value) {
  if (data_->show_icon == value) return *this;
  data_->show_icon = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

bool tool_bar::show_text() const noexcept {
  return data_->show_text;
}

tool_bar& tool_bar::show_text(bool value) {
  if (data_->show_text == value) return *this;
  data_->show_text = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

bool tool_bar::show_tool_tips() const noexcept {
  return data_->show_tool_tips;
}

tool_bar& tool_bar::show_tool_tips(bool value) {
  if (data_->show_tool_tips == value) return *this;
  data_->show_tool_tips = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  return *this;
}

xtd::forms::tool_bar_text_align tool_bar::text_align() const noexcept {
  return data_->text_align;
}

tool_bar& tool_bar::text_align(xtd::forms::tool_bar_text_align value) {
  if (data_->text_align == value) return *this;
  data_->text_align = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

bool tool_bar::wrappable() const noexcept {
  return data_->wrappable;
}

tool_bar& tool_bar::wrappable(bool value) {
  if (data_->wrappable == value) return *this;
  data_->wrappable = value;
  if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  else invalidate();
  return *this;
}

forms::create_params tool_bar::create_params() const noexcept {
  auto create_params = control::create_params();
  
  if (is_system_tool_bar())
    create_params.class_name("toolbar");
    
  if (data_->appearance == tool_bar_appearance::flat) create_params.style(create_params.style() | TBSTYLE_FLAT);
  if (!data_->divider) create_params.style(create_params.style() | TBSTYLE_NODIVIDER);
  if (data_->non_system_dock == dock_style::left) create_params.style(create_params.style() | TBSTYLE_LEFT);
  else if (data_->non_system_dock == dock_style::right) create_params.style(create_params.style() | TBSTYLE_RIGHT);
  else if (data_->non_system_dock == dock_style::bottom) create_params.style(create_params.style() | TBSTYLE_BOTTOM);
  if (!data_->show_icon) create_params.style(create_params.style() | TBSTYLE_NOSHOWICON);
  if (data_->show_text) create_params.style(create_params.style() | TBSTYLE_SHOWTEXT);
  if (!data_->show_tool_tips) create_params.style(create_params.style() | TBSTYLE_TOOLTIPS);
  if (data_->text_align == tool_bar_text_align::right) create_params.style(create_params.style() | TBSTYLE_TEXTRIGHTALIGN);
  if (data_->wrappable) create_params.style(create_params.style() | TBSTYLE_WRAPABLE);
  
  return create_params;
}

xtd::drawing::font tool_bar::default_font() const noexcept {
  return xtd::drawing::system_fonts::tool_font();
}

drawing::size tool_bar::default_size() const noexcept {
  return native::control::default_size("toolbar");
}

void tool_bar::on_button_click(const xtd::forms::tool_bar_button_click_event_args& e) {
  button_click(*this, e);
}

void tool_bar::on_button_drop_down(const xtd::forms::tool_bar_button_click_event_args& e) {
  if (e.button().drop_down_menu().has_value() && e.handle())
    e.button().drop_down_menu().value().get().show(*this, xtd::drawing::point(reinterpret_cast<tool_bar_button_control*>(e.handle())->left(), reinterpret_cast<tool_bar_button_control*>(e.handle())->bottom() + 2));
  button_drop_down(*this, e);
}

void tool_bar::on_handle_created(const event_args& e) {
  control::on_handle_created(e);
  fill();
  resize_stretchable_separtors();
}

void tool_bar::on_handle_destroyed(const event_args& e) {
  if (is_system_tool_bar()) {
    native::tool_bar::set_system_tool_bar(parent().value().get().handle(), 0);
    data_->system_tool_bar_button_handles.clear();
  }
  control::on_handle_destroyed(e);
}

void tool_bar::on_paint(xtd::forms::paint_event_args& e) {
  control::on_paint(e);
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  if (control_appearance() == forms::control_appearance::standard) tool_bar_renderer::draw_tool_bar(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, data_->border_style, data_->border_sides);
}

void tool_bar::on_resize(const event_args& e) {
  control::on_resize(e);
  resize_stretchable_separtors();
}

bool tool_bar::is_horizontal() const noexcept {
  return dock() != dock_style::left && dock() != dock_style::right;
}

bool tool_bar::is_system_tool_bar() const noexcept {
  auto result = data_->is_system_tool_bar || data_->appearance == tool_bar_appearance::system;
  return result;
}

tool_bar& tool_bar::is_system_tool_bar(bool value) {
  if (data_->is_system_tool_bar != value) {
    if (!value) control::dock(data_->non_system_dock);
    else {
      data_->non_system_dock = control::dock();
      control::dock(dock_style::none);
    }
    data_->is_system_tool_bar = value;
    post_recreate_handle();
  }
  return *this;
}

void tool_bar::fill() {
  if (data_->buttons.size() == 0) return;
  suspend_layout();
  controls().clear();
  data_->stretchable_separators.clear();
  data_->tool_bar_buttons.clear();
  auto reversed_buttons = data_->buttons;
  if (!is_system_tool_bar()) std::reverse(reversed_buttons.begin(), reversed_buttons.end());
  if (!is_system_tool_bar() && auto_size())
    size({padding().left() + padding().right(), padding().top() + padding().bottom()});
  for (auto index = 0_sz; index < reversed_buttons.size(); ++index) {
    auto& button_item = reversed_buttons[index].get();
    auto control_handle = 0_sz;
    if (is_system_tool_bar()) {
      if (reversed_buttons[index].get().style() == tool_bar_button_style::push_button || (!data_->drop_down_arrows && button_item.style() == tool_bar_button_style::drop_down_button))
        control_handle = native::tool_bar::add_tool_bar_button(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::toggle_button)
        control_handle = native::tool_bar::add_tool_bar_toggle_button(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, reversed_buttons[index].get().pushed(), button_item.enabled(), button_item.visible());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::separator)
        control_handle = native::tool_bar::add_tool_bar_separator(handle());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::drop_down_button)
        control_handle = native::tool_bar::add_tool_bar_drop_down_button(handle(), button_item.text(), button_item.tool_tip_text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible(), button_item.drop_down_menu().has_value() ? button_item.drop_down_menu().value().get().handle() : 0);
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::stretchable_separator)
        control_handle = native::tool_bar::add_tool_bar_stretchable_separator(handle());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::control) {
        if (button_item.control().has_value()) button_item.control().value().get().parent(*this);
        control_handle = native::tool_bar::add_tool_bar_control(handle(), button_item.control().has_value() ? button_item.control().value().get().handle() : 0, button_item.text(), button_item.tool_tip_text());
      }
      reversed_buttons[index].get().data_->handle = control_handle;
      data_->system_tool_bar_button_handles.push_back(control_handle);
      button_item.data_->rectangle = drawing::rectangle(native::tool_bar::tool_bar_item_rectangle(handle(), control_handle));
    } else {
      auto button_control = std::make_shared<tool_bar_button_control>();
      button_item.data_->handle = reinterpret_cast<intptr>(button_control.get());
      button_control->parent(*this);
      button_control->tool_bar_button(button_item);
      if (is_horizontal()) button_control->dock(dock_style::left);
      else button_control->dock(dock_style::top);
      button_control->enabled(button_item.enabled());
      button_control->flat(appearance() == tool_bar_appearance::flat);
      button_control->image_size(image_size());
      button_control->show_icon(data_->show_icon);
      button_control->show_text(data_->show_text);
      button_control->size(button_size());
      if (!data_->drop_down_arrows && button_item.style() == tool_bar_button_style::drop_down_button)
        button_control->style(tool_bar_button_style::push_button);
      else
        button_control->style(button_item.style());
      button_control->tool_bar_text_align(data_->text_align);
      button_control->pushed(button_item.pushed());
      button_control->visible(button_item.visible());
      if (button_item.style() == tool_bar_button_style::separator || button_item.style() == tool_bar_button_style::stretchable_separator) {
        button_control->height(image_size().height() / 2);
        button_control->width(image_size().width() / 2);
      }
      if (button_item.style() == tool_bar_button_style::stretchable_separator)
        data_->stretchable_separators.push_back(button_control);
      if (button_item.style() == tool_bar_button_style::control && button_item.control().has_value()) {
        button_control->control(&button_item.control().value().get());
        button_item.control().value().get().parent(*button_control);
      }
      if (button_item.style() == tool_bar_button_style::drop_down_button && button_item.drop_down_menu().has_value())
        button_control->drop_down_menu(const_cast<forms::context_menu*>(&button_item.drop_down_menu().value().get()));
        
      /// @todo Add xtd::forms::tool_tip when implemented.
      
      if ((data_->show_icon || !data_->show_text) && button_item.image_index() < data_->image_list.images().size()) button_control->image(data_->image_list.images()[button_item.image_index()]);
      if (data_->show_text) button_control->text(button_item.text());
      
      if (auto_size()) {
        if (is_horizontal() && height() < button_control->height()) height(button_control->height() + padding().top() + padding().bottom());
        if (!is_horizontal() && width() < button_control->width()) width(button_control->width() + padding().left() + padding().right());
        if (is_horizontal()) width(width() + button_control->width());
        else height(height() + button_control->height());
      }
      
      button_item.data_->rectangle = drawing::rectangle(button_control->location(), button_control->size());
      
      data_->tool_bar_buttons.push_back(button_control);
    }
  }
  
  if (is_system_tool_bar()) {
    auto pcsg = parent_client_size_guard {*this}; // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
    native::tool_bar::set_system_tool_bar(parent().value().get().handle(), handle());
  }
  
  resume_layout();
}

void tool_bar::on_item_added(size_t pos, tool_bar_button_ref item) {
  auto pcsg = parent_client_size_guard {*this}; // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().data_->parent = this;
  post_recreate_handle();
}

void tool_bar::on_item_updated(size_t pos, tool_bar_button_ref item) {
  auto pcsg = parent_client_size_guard {*this}; // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  post_recreate_handle();
}

void tool_bar::on_item_removed(size_t pos, tool_bar_button_ref item) {
  auto pcsg = parent_client_size_guard {*this}; // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().data_->parent = nullptr;
  post_recreate_handle();
}

void tool_bar::wnd_proc(message& message) {
  if (is_system_tool_bar() && message.msg() == WM_MENUCOMMAND && handle() == message.hwnd()) wm_click(message);
  else control::wnd_proc(message);
}

void tool_bar::resize_stretchable_separtors() {
  if (data_->stretchable_separators.size()) {
    auto remaining_size = is_horizontal() ? size().width() - padding().left() - padding().right() : size().height() - padding().top() - padding().bottom();
    for (auto tool_bar_button : data_->tool_bar_buttons) {
      if (tool_bar_button->style() != tool_bar_button_style::stretchable_separator && tool_bar_button->visible())
        remaining_size -= is_horizontal() ? tool_bar_button->size().width() : tool_bar_button->size().height();
    }
    
    auto stretchable_size = remaining_size / as<int32>(data_->stretchable_separators.size());
    for (auto stretchable_separator : data_->stretchable_separators) {
      auto default_stretchable_size = (is_horizontal() ? image_size().width() : image_size().height()) / 2;
      if (stretchable_size > default_stretchable_size) {
        if (is_horizontal()) stretchable_separator->width(stretchable_size);
        else stretchable_separator->height(stretchable_size);
      } else {
        if (is_horizontal()) stretchable_separator->width(default_stretchable_size);
        else stretchable_separator->height(default_stretchable_size);
      }
    }
    perform_layout();
  }
}

void tool_bar::update_toolbar_button_control(intptr handle, const xtd::ustring& text, const xtd::ustring& tool_tip_text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!handle) return;
  if (is_system_tool_bar())
    native::tool_bar::update_tool_bar_item(this->handle(), handle, text, tool_tip_text, image, pushed, enabled, visible);
  else {
    reinterpret_cast<tool_bar_button_control*>(handle)->text(text);
    reinterpret_cast<tool_bar_button_control*>(handle)->text(text);
    reinterpret_cast<tool_bar_button_control*>(handle)->image(image);
    reinterpret_cast<tool_bar_button_control*>(handle)->pushed(pushed);
    reinterpret_cast<tool_bar_button_control*>(handle)->enabled(enabled);
    reinterpret_cast<tool_bar_button_control*>(handle)->visible(visible);
    resize_stretchable_separtors();
  }
}

void tool_bar::wm_click(const message& message) {
  auto found_button_or_menu = false;
  for (auto index = 0_sz; !found_button_or_menu && index < data_->system_tool_bar_button_handles.size(); ++index) {
    if (index < data_->system_tool_bar_button_handles.size() && message.wparam() == data_->system_tool_bar_button_handles[index]) {
      if (data_->buttons[index].get().style() == tool_bar_button_style::toggle_button)
        data_->buttons[index].get().pushed(!data_->buttons[index].get().pushed());
      on_button_click(xtd::forms::tool_bar_button_click_event_args(data_->buttons[index].get()));
      found_button_or_menu = true;
    }
  }
  
  for (auto index = 0_sz; !found_button_or_menu && index < data_->system_tool_bar_button_handles.size(); ++index) {
    if (data_->buttons[index].get().style() == tool_bar_button_style::drop_down_button && data_->buttons[index].get().drop_down_menu().has_value())
      found_button_or_menu = on_context_menu_item_click(data_->buttons[index].get().drop_down_menu().value(), message.wparam());
  }
  
  if (!found_button_or_menu)
    on_click(event_args::empty);
}
