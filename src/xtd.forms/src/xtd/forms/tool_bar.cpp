#include <xtd/as.h>
#include <xtd/is.h>
#include <xtd/drawing/system_pens.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/tool_bar.h>
#include <xtd/forms/native/tool_bar_styles.h>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/window_messages.h>
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/tool_bar.h"
#include "../../../include/xtd/forms/tool_bar_renderer.h"
#include "../../../include/xtd/forms/tool_bar_button_renderer.h"

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

tool_bar::tool_bar_button_control::tool_bar_button_control() {
  set_can_focus(false);
  flat_style(xtd::forms::flat_style::flat);
}

void tool_bar::tool_bar_button_control::control(const xtd::forms::control* value) {
  if (data_->control != value) {
    data_->control = value;
    update_size();
    update_layout();
  }
}

void tool_bar::tool_bar_button_control::drop_down_menu(xtd::forms::context_menu* value) {
  if (data_->drop_down_menu != value) {
    data_->drop_down_menu = value;
    update_size();
    update_layout();
  }
}

xtd::drawing::font tool_bar::tool_bar_button_control::default_font() const {
  return xtd::drawing::system_fonts::toolbar_font();
}

void tool_bar::tool_bar_button_control::flat(bool value) {
  if (data_->flat != value) {
    data_->flat = value;
    update_size();
    update_layout();
  }
}

button_base& tool_bar::tool_bar_button_control::image(const xtd::drawing::image& value) {
  if (image() != value) {
    button_base::image(value);
    update_size();
    update_layout();
  }
  return *this;
}

const xtd::drawing::size& tool_bar::tool_bar_button_control::image_size() const {
  return data_->image_size;
}

void tool_bar::tool_bar_button_control::image_size(const xtd::drawing::size& value) {
  if (data_->image_size != value) {
    data_->image_size = value;
    update_size();
    update_layout();
  }
}

bool tool_bar::tool_bar_button_control::is_horizontal() const {
  return dock() == dock_style::left || dock() == dock_style::right;
}

void tool_bar::tool_bar_button_control::pushed(bool value) {
  if (data_->pushed != value) {
    data_->pushed = value;
    update_size();
    update_layout();
  }
}

void tool_bar::tool_bar_button_control::show_icon(bool value) {
  if (data_->show_icon != value) {
    data_->show_icon = value;
    update_size();
    update_layout();
  }
}

void tool_bar::tool_bar_button_control::show_text(bool value) {
  if (data_->show_text != value) {
    data_->show_text = value;
    update_size();
    update_layout();
  }
}

xtd::drawing::size tool_bar::tool_bar_button_control::size() const {
  return control::size();
}

control& tool_bar::tool_bar_button_control::size(const xtd::drawing::size& value) {
  if (size() != value) {
    control::size(value);
    update_size();
    update_layout();
  }
  return *this;
}

xtd::forms::tool_bar_button_style tool_bar::tool_bar_button_control::style() const {
  return data_->style;
}

void tool_bar::tool_bar_button_control::style(xtd::forms::tool_bar_button_style value) {
  if (data_->style != value) {
    data_->style = value;
    update_size();
    update_layout();
  }
}

void tool_bar::tool_bar_button_control::tool_bar_text_align(xtd::forms::tool_bar_text_align value) {
  if (data_->tool_bar_text_align != value) {
    data_->tool_bar_text_align = value;
    update_size();
    update_layout();
  }
}

control& tool_bar::tool_bar_button_control::text(const xtd::ustring& value) {
  if (text() != value) {
    button_base::text(value);
    update_size();
    update_layout();
  }
  return *this;
}

void tool_bar::tool_bar_button_control::on_click(const xtd::event_args& e) {
  button::on_click(e);
  if (data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(point_to_client(mouse_position())) && data_->drop_down_menu)
    data_->drop_down_menu->show(parent().value().get(), point(left(), bottom() + 2));
  else {
    if (data_->tool_bar_button.has_value()) {
      if (data_->style == tool_bar_button_style::toggle_button) {
        data_->pushed = !data_->pushed;
        data_->tool_bar_button.value().get().pushed(data_->pushed);
      }
      if (data_->style != tool_bar_button_style::separator && data_->style != tool_bar_button_style::stretchable_separator && data_->style != tool_bar_button_style::control && parent().has_value())
        as<tool_bar>(parent().value().get()).on_button_click(xtd::forms::tool_bar_button_click_event_args(data_->tool_bar_button.value().get()));
    }
  }
}

void tool_bar::tool_bar_button_control::on_mouse_down(const mouse_event_args& e) {
  if (e.button() == mouse_buttons::left && data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(e.location()) && data_->drop_down_menu) {
    data_->mouse_down_on_drop_down_menu = true;
    invalidate();
  } else
    button::on_mouse_down(e);
}

void tool_bar::tool_bar_button_control::on_mouse_enter(const event_args& e) {
  data_->mouse_on_drop_down_menu = data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(point_to_client(mouse_position())) && data_->drop_down_menu;
  button::on_mouse_enter(e);
}

void tool_bar::tool_bar_button_control::on_mouse_move(const mouse_event_args& e) {
  auto mouse_on_drop_down_menu = data_->style == tool_bar_button_style::drop_down_button && drop_down_rectangle().contains(e.location()) && data_->drop_down_menu;
  if (data_->mouse_on_drop_down_menu != mouse_on_drop_down_menu) {
    data_->mouse_on_drop_down_menu = mouse_on_drop_down_menu;
    invalidate();
  }
  xtd::forms::button::on_mouse_move(e);
}

void tool_bar::tool_bar_button_control::on_mouse_leave(const event_args& e) {
  data_->mouse_on_drop_down_menu = false;
  data_->mouse_down_on_drop_down_menu = false;
  button::on_mouse_leave(e);
}

void tool_bar::tool_bar_button_control::on_mouse_up(const mouse_event_args& e) {
  if (e.button() == mouse_buttons::left && data_->style == tool_bar_button_style::drop_down_button) {
    data_->mouse_down_on_drop_down_menu = false;
    invalidate();
  }
  button::on_mouse_up(e);
}

void tool_bar::tool_bar_button_control::on_paint(paint_event_args& e) {
  if (data_->style == tool_bar_button_style::push_button) draw_push_button(e);
  else if (data_->style == tool_bar_button_style::toggle_button) draw_toggle_button(e);
  else if (data_->style == tool_bar_button_style::separator) draw_separator(e);
  else if (data_->style == tool_bar_button_style::drop_down_button) draw_drop_down_button(e);
  else if (data_->style == tool_bar_button_style::stretchable_separator) draw_stretchable_separator(e);
  else if (data_->style == tool_bar_button_style::control) draw_control(e);
  control::on_paint(e);
}

void tool_bar::tool_bar_button_control::draw_push_button(xtd::forms::paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), e.clip_rectangle(), state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
}

void tool_bar::tool_bar_button_control::draw_toggle_button(xtd::forms::paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), e.clip_rectangle(), data_->pushed ? visual_styles::push_button_state::checked : state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
}

void tool_bar::tool_bar_button_control::draw_drop_down_button(xtd::forms::paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  auto button_rect = e.clip_rectangle();
  button_rect.width(button_rect.width() - drop_down_rectangle().width());
  visual_styles::push_button_state current_state = state();
  if (data_->mouse_on_drop_down_menu) current_state = visual_styles::push_button_state::normal;
  tool_bar_button_renderer::draw_tool_bar_button(style, e.graphics(), button_rect, current_state, back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, flat_appearance(), text(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, font(), image(), image_align());
  xtd::forms::style_sheets::tool_bar_button current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::standard);
  if (data_->mouse_on_drop_down_menu) current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::hover);
  if (data_->mouse_down_on_drop_down_menu) current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::pressed);
  auto center_drop_down = point(e.clip_rectangle().right() - drop_down_rectangle().width() / 2, e.clip_rectangle().top() + drop_down_rectangle().height() / 2);
  auto drop_down_size = drawing::size(drop_down_rectangle().width() - 4, (drop_down_rectangle().width() - 4) / 2);
  box_renderer::draw_box(e.graphics(), drop_down_rectangle(), current_style_sheet);
  e.graphics().fill_polygon(solid_brush(current_style_sheet.color()), vector<point> {point {center_drop_down.x() - drop_down_size.width() / 2, center_drop_down.y() - drop_down_size.height() / 2}, point {center_drop_down.x() + drop_down_size.width() / 2, center_drop_down.y() - drop_down_size.height() / 2}, point {center_drop_down.x(), center_drop_down.y() + drop_down_size.height() / 2} });
}

void tool_bar::tool_bar_button_control::draw_separator(xtd::forms::paint_event_args& e) {
  if (data_->flat) {
    auto percent_of_color = 1.0 / 6;
    auto color = back_color().get_lightness() < 0.5 ? xtd::forms::control_paint::light(back_color(), percent_of_color) : xtd::forms::control_paint::dark(back_color(), percent_of_color);
    if (is_horizontal()) {
      auto left = image_size().width() / 4;
      auto top = 4;
      auto right = left;
      auto bottom = e.clip_rectangle().height() - 4;
      e.graphics().draw_line(pen {color}, point {left, top}, point {right, bottom});
    } else {
      auto left = 4;
      auto top = image_size().height() / 4;
      auto right = e.clip_rectangle().width() - 4;
      auto bottom = top;
      e.graphics().draw_line(pen {color}, point {left, top}, point {right, bottom});
    }
  }
}

void tool_bar::tool_bar_button_control::draw_stretchable_separator(xtd::forms::paint_event_args& e) {
  draw_separator(e);
}

void tool_bar::tool_bar_button_control::draw_control(xtd::forms::paint_event_args& e) {
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  xtd::forms::style_sheets::tool_bar_button current_style_sheet = style.tool_bar_button(xtd::forms::style_sheets::pseudo_state::standard);
  current_style_sheet.font(font());
  xtd::drawing::rectangle text_rect = current_style_sheet.get_content_rectangle(e.clip_rectangle());
  if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
    text_rect.width(text_rect.width() - data_->control->width() - 4);
    text_rect.x(text_rect.x() + data_->control->width() + 4);
  } else {
    text_rect.height(text_rect.height() - data_->control->height() - 2);
    text_rect.y(text_rect.y() + data_->control->height() + 2);
  }
  text_renderer::draw_text(e.graphics(), text_rect, text(), current_style_sheet);
}

xtd::drawing::rectangle tool_bar::tool_bar_button_control::drop_down_rectangle() const {
  if (data_->style != tool_bar_button_style::drop_down_button) return {};
  return {width() - 16, 0, 16, height()};
}

void tool_bar::tool_bar_button_control::update_layout() {
  if (data_->show_text == false) {
    image_align(content_alignment::middle_center);
  } else if (data_->show_text == true && data_->show_icon == false) {
    text_align(content_alignment::middle_center);
  } else if (data_->show_text == true && data_->show_icon == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
    image_align(content_alignment::middle_left);
    text_align(content_alignment::middle_left);
  }  else {
    image_align(content_alignment::top_center);
    text_align(content_alignment::bottom_center);
  }
}

void tool_bar::tool_bar_button_control::update_size() {
  auto size = this->size();
  auto text_size = measure_text();
  auto drop_down_size = drop_down_rectangle().size();

  if (data_->style == tool_bar_button_style::control && data_->control) {
    if (size.height() < data_->control->height()) size.height(data_->control->height());
    if (size.width() < data_->control->width()) size.width(data_->control->width());

    if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
      if (size.width() < (data_->control->size().width() + text_size.width() + 6)) size.width(data_->control->size().width() + text_size.width() + 6);
      if (size.height() < text_size.height()) size.height(text_size.height());
      const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width() - text_size.width()) / 2, (size.height() - data_->control->height()) / 2});
    } else if (data_->show_text == true && data_->tool_bar_text_align == tool_bar_text_align::underneath) {
      if (size.width() < text_size.width()) size.width(text_size.width());
      if (size.height() < (data_->control->size().height() + text_size.height() + 6)) size.height(data_->control->size().height() + text_size.height() + 6);
      const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width()) / 2, (size.height() - data_->control->height() - text_size.height()) / 2});
    } else
      const_cast<xtd::forms::control*>(data_->control)->location({(size.width() - data_->control->width()) / 2, (size.height() - data_->control->height()) / 2});
  } else if (data_->style != tool_bar_button_style::separator && data_->style != tool_bar_button_style::stretchable_separator) {
    if (data_->show_text == false) {
      if (size.width() < image_size().width() + drop_down_size.width()) size.width(image_size().width() + drop_down_size.width() + 12);
      if (size.height() < image_size().height()) size.height(image_size().height() + 12);
    } else if (data_->show_text == true && data_->show_icon == false) {
      if (size.width() < text_size.width() + drop_down_size.width()) size.width(text_size.width() + drop_down_size.width());
      if (size.height() < text_size.height()) size.height(text_size.height());
    } else if (data_->show_text == true && data_->show_icon == true && data_->tool_bar_text_align == tool_bar_text_align::right) {
      if (size.width() < (image_size().width() + text_size.width() + drop_down_size.width() + 4)) size.width(image_size().width() + text_size.width() + drop_down_size.width() + 4);
      if (size.height() < text_size.height()) size.height(text_size.height());
    }  else {
      if (size.width() < text_size.width() + drop_down_size.width()) size.width(text_size.width() + drop_down_size.width());
      if (size.height() < (image_size().height() + text_size.height() + 6)) size.height(image_size().height() + text_size.height() + 6);
    }
  }
  this->size(size);
}

tool_bar::tool_bar() {
  data_->buttons.item_added += {*this, &tool_bar::on_item_added};
  data_->buttons.item_updated += {*this, &tool_bar::on_item_updated};
  data_->buttons.item_removed += {*this, &tool_bar::on_item_removed};
  
  if (environment::os_version().is_windows_platform()) data_->image_list.image_size(drawing::size {16, 16});
  else if (environment::os_version().is_macos_platform()) data_->image_list.image_size(drawing::size {32, 32});
  else data_->image_list.image_size(drawing::size {24, 24});

  dock(xtd::forms::dock_style::top);
  padding(forms::padding {2});
  set_can_focus(false);
}

xtd::forms::tool_bar_appearance tool_bar::appearnce() const {
  return data_->appearnce;
}

tool_bar& tool_bar::appearnce(xtd::forms::tool_bar_appearance value) {
  if (data_->appearnce != value) {
    data_->appearnce = value;
    if (value != tool_bar_appearance::system) invalidate();
    else  post_recreate_handle();
  }
  return *this;
}

tool_bar& tool_bar::border_sides(forms::border_sides border_sides) {
  if (data_->border_sides != border_sides) {
    data_->border_sides = border_sides;
    if (control_appearance() == forms::control_appearance::standard) invalidate();
  }
  return *this;
}

tool_bar& tool_bar::border_style(forms::border_style border_style) {
  if (data_->border_style != border_style) {
    data_->border_style = border_style;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

tool_bar& tool_bar::border_style(std::nullptr_t) {
  if (data_->border_style) {
    data_->border_style.reset();
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

xtd::drawing::size tool_bar::button_size() const {
  return data_->button_size.value_or(image_size() + drawing::size(12, 12));
}

tool_bar& tool_bar::button_size(const xtd::drawing::size& value) {
  if (!data_->button_size.has_value() || data_->button_size != value) {
    data_->button_size = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

dock_style tool_bar::dock() const {
  //if (is_system_tool_bar()) return data_->non_system_dock;
  return control::dock();
}

control& tool_bar::dock(dock_style dock) {
  if (is_system_tool_bar()) {
    data_->non_system_dock = dock;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
  } else {
    int32_t current_size = is_horizontal() ? height() : width();
    control::dock(dock);
    if (is_horizontal()) height(current_size);
    else width(current_size);
  }
  return *this;
}

xtd::drawing::font tool_bar::default_font() const {
  return xtd::drawing::system_fonts::toolbar_font();
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

xtd::drawing::size tool_bar::image_size() const {
  return data_->image_list.image_size();
}

const tool_bar::tool_bar_button_collection& tool_bar::buttons() const {
  return data_->buttons;
}

tool_bar::tool_bar_button_collection& tool_bar::buttons() {
  return data_->buttons;
}

bool tool_bar::show_icon() const {
  return data_->show_icon;
}

tool_bar& tool_bar::show_icon(bool value) {
  if (data_->show_icon != value) {
    data_->show_icon = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

bool tool_bar::show_text() const {
  return data_->show_text;
}

tool_bar& tool_bar::show_text(bool value) {
  if (data_->show_text != value) {
    data_->show_text = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

xtd::forms::tool_bar_text_align tool_bar::text_align() const {
  return data_->text_align;
}

tool_bar& tool_bar::text_align(xtd::forms::tool_bar_text_align value) {
  if (data_->text_align != value) {
    data_->text_align = value;
    if (control_appearance() == forms::control_appearance::system) post_recreate_handle();
    else invalidate();
  }
  return *this;
}

forms::create_params tool_bar::create_params() const {
  forms::create_params create_params = control::create_params();
  
  if (is_system_tool_bar())
    create_params.class_name("toolbar");
  
  if (data_->appearnce == tool_bar_appearance::flat) create_params.style(create_params.style() | TBSTYLE_FLAT);
  if (data_->non_system_dock == dock_style::left) create_params.style(create_params.style() | TBSTYLE_LEFT);
  else if (data_->non_system_dock == dock_style::right) create_params.style(create_params.style() | TBSTYLE_RIGHT);
  else if (data_->non_system_dock == dock_style::bottom) create_params.style(create_params.style() | TBSTYLE_BOTTOM);
  if (data_->show_text) create_params.style(create_params.style() | TBSTYLE_SHOWTEXT);
  if (!data_->show_icon) create_params.style(create_params.style() | TBSTYLE_NOSHOWICON);
  if (data_->text_align == tool_bar_text_align::right) create_params.style(create_params.style() | TBSTYLE_TEXTRIGHTALIGN);
  return create_params;
}

void tool_bar::on_button_click(const xtd::forms::tool_bar_button_click_event_args &e) {
  button_click(*this, e);
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

bool tool_bar::is_horizontal() const {
  return dock() == dock_style::top || dock() == dock_style::bottom;
}

bool tool_bar::is_system_tool_bar() const {
  auto result = data_->is_system_tool_bar || data_->appearnce == tool_bar_appearance::system;
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
  suspend_layout();
  controls().clear();
  data_->stretchable_separators.clear();
  data_->tool_bar_buttons.clear();
  auto reversed_buttons = data_->buttons;
  if (!is_system_tool_bar()) std::reverse(reversed_buttons.begin(), reversed_buttons.end());
  for (size_t index = 0; index < reversed_buttons.size(); ++index) {
    auto& button_item = reversed_buttons[index].get();
    intptr_t control_handle = 0;
    if (is_system_tool_bar()) {
      if (reversed_buttons[index].get().style() == tool_bar_button_style::push_button)
        control_handle = native::tool_bar::add_tool_bar_button(handle(), button_item.text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::toggle_button)
        control_handle = native::tool_bar::add_tool_bar_toggle_button(handle(), button_item.text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, reversed_buttons[index].get().pushed(), button_item.enabled(), button_item.visible());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::separator)
        control_handle = native::tool_bar::add_tool_bar_separator(handle());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::drop_down_button)
        control_handle = native::tool_bar::add_tool_bar_drop_down_button(handle(), button_item.text(), button_item.image_index() < data_->image_list.images().size() ? data_->image_list.images()[button_item.image_index()] : image::empty, button_item.enabled(), button_item.visible(), button_item.drop_down_menu().has_value() ? button_item.drop_down_menu().value().get().handle() : 0);
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::stretchable_separator)
        control_handle = native::tool_bar::add_tool_bar_stretchable_separator(handle());
      else if (reversed_buttons[index].get().style() == tool_bar_button_style::control) {
        if (button_item.control().has_value()) button_item.control().value().get().parent(*this);
        control_handle = native::tool_bar::add_tool_bar_control(handle(), button_item.control().has_value() ? button_item.control().value().get().handle() : 0, button_item.text());
      }
      reversed_buttons[index].get().data_->handle = control_handle;
      data_->system_tool_bar_button_handles.push_back(control_handle);
    } else {
      auto button_control = std::make_shared<tool_bar_button_control>();
      button_item.data_->handle = reinterpret_cast<intptr_t>(button_control.get());
      button_control->parent(*this);
      button_control->tool_bar_button(button_item);
      if (is_horizontal()) button_control->dock(dock_style::left);
      else button_control->dock(dock_style::top);
      button_control->enabled(button_item.enabled());
      button_control->flat(appearnce() == tool_bar_appearance::flat);
      button_control->image_size(image_size());
      button_control->show_icon(data_->show_icon);
      button_control->show_text(data_->show_text);
      button_control->size(button_size());
      button_control->style(button_item.style());
      button_control->tool_bar_text_align(data_->text_align);
      button_control->pushed(button_item.pushed());
      button_control->visible(button_item.visible());
      if (button_item.style() == tool_bar_button_style::separator) {
        button_control->height(image_size().height() / 2);
        button_control->width(image_size().width() / 2);
      }
      if (button_item.style() == tool_bar_button_style::stretchable_separator)
        data_->stretchable_separators.push_back(button_control);
      if (button_item.style() == tool_bar_button_style::control && button_item.control().has_value()) {
        button_control->control(&button_item.control().value().get());
        button_item.control().value().get().parent(*button_control);
      }
      if (button_item.style() == tool_bar_button_style::drop_down_button && button_item.drop_down_menu().has_value()) {
        button_control->drop_down_menu(const_cast<forms::context_menu*>(&button_item.drop_down_menu().value().get()));
      }

      if ((data_->show_icon || !data_->show_text) && button_item.image_index() < data_->image_list.images().size()) button_control->image(data_->image_list.images()[button_item.image_index()]);
      if (data_->show_text) button_control->text(button_item.text());

      if (is_horizontal()) {
        if (height() < button_control->height()) height(button_control->height() + 4);
      } else {
        if (width() < button_control->width()) width(button_control->width() + 4);
      }

      data_->tool_bar_buttons.push_back(button_control);
    }
  }
  if (is_system_tool_bar()) {
    parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
    native::tool_bar::set_system_tool_bar(parent().value().get().handle(), handle());
  }
  
  resume_layout();
}

void tool_bar::on_item_added(size_t pos, tool_bar_button_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  item.get().data_->parent = this;
  post_recreate_handle();
}

void tool_bar::on_item_updated(size_t pos, tool_bar_button_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
  post_recreate_handle();
}

void tool_bar::on_item_removed(size_t pos, tool_bar_button_ref item) {
  parent_client_size_guard pcsg(*this); // Workaround : Get client size because after changing tool bar to system, the client size does not correct.
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
    
    auto stretchable_size = remaining_size / as<int32_t>(data_->stretchable_separators.size());
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

void tool_bar::update_toolbar_button_control(intptr_t handle, const xtd::ustring& text, const xtd::drawing::image& image, bool pushed, bool enabled, bool visible) {
  if (!handle) return;
  if (is_system_tool_bar())
    native::tool_bar::update_tool_bar_item(this->handle(), handle, text, image, pushed, enabled, visible);
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
  bool found_button_or_menu = false;
  for (size_t index = 0; !found_button_or_menu && index < data_->system_tool_bar_button_handles.size(); ++index) {
    if (index < data_->system_tool_bar_button_handles.size() && message.wparam() == data_->system_tool_bar_button_handles[index]) {
      if (data_->buttons[index].get().style() == tool_bar_button_style::toggle_button)
        data_->buttons[index].get().pushed(!data_->buttons[index].get().pushed());
      on_button_click(xtd::forms::tool_bar_button_click_event_args(data_->buttons[index].get()));
      found_button_or_menu = true;
    }
  }

  for (size_t index = 0; !found_button_or_menu && index < data_->system_tool_bar_button_handles.size(); ++index) {
    if (data_->buttons[index].get().style() == tool_bar_button_style::drop_down_button && data_->buttons[index].get().drop_down_menu().has_value())
      found_button_or_menu = on_context_menu_item_click(data_->buttons[index].get().drop_down_menu().value(), message.wparam());
  }
        
  if (!found_button_or_menu)
    on_click(event_args::empty);
}
