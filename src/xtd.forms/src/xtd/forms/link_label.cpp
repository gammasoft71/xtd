#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/control_paint.h"
#include "../../../include/xtd/forms/label_renderer.h"
#include "../../../include/xtd/forms/link_label.h"
#include "../../../include/xtd/forms/screen.h"
#include "../../../include/xtd/forms/system_information.h"
#include <xtd/as>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

namespace {
  link_label::link link_empty;
};

struct link_label::data {
  bool mouse_hover = false;
  std::optional<xtd::drawing::color> active_link_color;
  std::optional<xtd::drawing::color> disabled_link_color;
  xtd::forms::link_area link_area;
  xtd::forms::link_behavior link_behavior = xtd::forms::link_behavior::system_default;
  std::optional<xtd::drawing::color> link_color;
  link_collection links;
  xtd::forms::cursor original_cursor;
  std::optional<xtd::forms::cursor> override_cursor;
  std::optional<xtd::drawing::color> visited_link_color;
};

link_label::link_collection::link_collection(const link_label::link_collection::allocator_type& allocator) : link_label::link_collection::base(allocator) {
}

link_label::link_collection::link_collection(const link_label::link_collection::base& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection::link_collection(const link_label::link_collection& collection) : link_label::link_collection::base(collection) {}
link_label::link_collection& link_label::link_collection::operator =(const link_label::link_collection& collection) {
  base::operator =(collection);
  return *this;
}

link_label::link_collection::const_reference link_label::link_collection::operator [](const string& name) const noexcept {
  for (auto& item : *this)
    if (item.name() == name) return item;
  static auto link_empty = value_type {};
  return link_empty;
}

link_label::link_collection::reference link_label::link_collection::operator [](const string& name) noexcept {
  for (auto& item : *this)
    if (item.name() == name) return item;
  static auto link_empty = value_type {};
  return link_empty;
}

link_label::link_label() : data_(xtd::new_sptr<data>()) {
  double_buffered(true);
  set_style(control_styles::all_painting_in_wm_paint | control_styles::optimized_double_buffer | control_styles::opaque | control_styles::user_paint | control_styles::standard_click | control_styles::resize_redraw, true);
  data_->links.item_added += {*this, &link_label::on_links_link_added};
  data_->links.item_removed += {*this, &link_label::on_links_link_removed};
  data_->links.item_updated += {*this, &link_label::on_links_link_updated};
}

link_label::link_label(link_label&& rhs) : label(std::move(rhs)), data_ {std::move(rhs.data_)} {
  data_->links.item_added -= {rhs, &link_label::on_links_link_added};
  data_->links.item_removed -= {rhs, &link_label::on_links_link_removed};
  data_->links.item_updated -= {rhs, &link_label::on_links_link_updated};
  data_->links.item_added += {*this, &link_label::on_links_link_added};
  data_->links.item_removed += {*this, &link_label::on_links_link_removed};
  data_->links.item_updated += {*this, &link_label::on_links_link_updated};
}

xtd::drawing::color link_label::active_link_color() const noexcept {
  return data_->active_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().active_text());
}

link_label& link_label::active_link_color(const xtd::drawing::color& color) {
  if (data_->active_link_color == color) return *this;
  data_->active_link_color = color;
  invalidate();
  return *this;
}

xtd::drawing::color link_label::disabled_link_color() const noexcept {
  return data_->disabled_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().gray_text());
}

link_label& link_label::disabled_link_color(const xtd::drawing::color& color) {
  if (data_->active_link_color == color) return *this;
  data_->disabled_link_color = color;
  invalidate();
  return *this;
}

xtd::forms::link_area link_label::link_area() const noexcept {
  return data_->link_area;
}

link_label& link_label::link_area(xtd::forms::link_area value) {
  if (data_->link_area == value) return *this;
  data_->link_area = value;
  invalidate();
  return *this;
}

xtd::forms::link_behavior link_label::link_behavior() const noexcept {
  return data_->link_behavior;
}

link_label& link_label::link_behavior(xtd::forms::link_behavior value) {
  if (data_->link_behavior == value) return *this;
  data_->link_behavior = value;
  invalidate();
  return *this;
}

xtd::drawing::color link_label::link_color() const noexcept {
  return data_->link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().link_text());
}

link_label& link_label::link_color(const xtd::drawing::color& color) {
  if (data_->link_color == color) return *this;
  data_->link_color = color;
  invalidate();
  return *this;
}

const link_label::link_collection& link_label::links() const noexcept {
  return data_->links;
}

link_label::link_collection& link_label::links() {
  return data_->links;
}

link_label& link_label::links(const link_collection& value) {
  data_->links = value;
  return *this;
}

xtd::forms::cursor link_label::override_cursor() const noexcept {
  return data_->override_cursor.value_or(xtd::forms::cursors::hand());
}

link_label& link_label::override_cursor(const xtd::forms::cursor& cursor) {
  data_->override_cursor = cursor;
  return *this;
}

xtd::drawing::color link_label::visited_link_color() const noexcept {
  return data_->visited_link_color.value_or(xtd::forms::style_sheets::style_sheet::current_style_sheet().system_colors().visited_text());
}

link_label& link_label::visited_link_color(const xtd::drawing::color& color) {
  if (data_->visited_link_color == color) return *this;
  data_->visited_link_color = color;
  invalidate();
  return *this;
}

link_label link_label::create() {
  return link_label {};
}

link_label link_label::create(const drawing::point& location) {
  auto result = link_label {};
  result.location(location);
  return result;
}

link_label link_label::create(const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

link_label link_label::create(const xtd::string& text) {
  auto result = link_label {};
  result.text(text);
  return result;
}

link_label link_label::create(const xtd::string& text, const drawing::point& location) {
  auto result = link_label {};
  result.text(text);
  result.location(location);
  return result;
}

link_label link_label::create(const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

link_label link_label::create(const xtd::string& text, const link_collection& links) {
  auto result = link_label {};
  result.text(text);
  result.links(links);
  return result;
}

link_label link_label::create(const xtd::string& text, const link_collection& links, const drawing::point& location) {
  auto result = link_label {};
  result.text(text);
  result.links(links);
  result.location(location);
  return result;
}

link_label link_label::create(const xtd::string& text, const link_collection& links, const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.text(text);
  result.links(links);
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const xtd::string& text, const link_collection& links, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.text(text);
  result.links(links);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

link_label link_label::create(const control& parent) {
  auto result = link_label {};
  result.parent(parent);
  return result;
}

link_label link_label::create(const control& parent, const drawing::point& location) {
  auto result = link_label {};
  result.parent(parent);
  result.location(location);
  return result;
}

link_label link_label::create(const control& parent, const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.parent(parent);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const drawing::point& location) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const link_collection& links) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.links(links);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const link_collection& links, const drawing::point& location) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.links(links);
  result.location(location);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const link_collection& links, const drawing::point& location, const drawing::size& size) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.links(links);
  result.location(location);
  result.size(size);
  return result;
}

link_label link_label::create(const control& parent, const xtd::string& text, const link_collection& links, const drawing::point& location, const drawing::size& size, const xtd::string& name) {
  auto result = link_label {};
  result.parent(parent);
  result.text(text);
  result.links(links);
  result.location(location);
  result.size(size);
  result.name(name);
  return result;
}

xtd::uptr<xtd::object> link_label::clone() const {
  auto result = xtd::new_uptr<link_label>(*this);
  if (typeof_(*result) != typeof_(*this)) throw xtd::invalid_cast_exception(xtd::string::format("The {} does not implement clone method.", typeof_(*this).full_name()), csf_);
  return result;
}

drawing::size link_label::measure_control() const noexcept {
  auto bounds = rectangle {};
  for (auto [rect, is_link] : generate_text_rects())
    bounds = drawing::rectangle::make_union(bounds, rect);
  return bounds.size() + drawing::size(2, 1) + drawing::size(border_style() == border_style::none ? 0 : 4, border_style() == border_style::none ? 0 : 4);
}

void link_label::on_cursor_changed(const event_args& e) {
  label::on_cursor_changed(e);
  if (!data_->mouse_hover)
    data_->original_cursor = cursor();
}

void link_label::on_mouse_click(const mouse_event_args& e) {
  label::on_mouse_click(e);
  if (!enabled()) return;
  auto& link = point_in_link(e.location());
  if (link != link_empty && link.enabled()) {
    link_label_clicked_event_args args(link, e.button());
    link_clicked(*this, args);
    if (args.visited()) {
      link.visited(true);
      invalidate();
    }
  }
}

void link_label::on_mouse_down(const mouse_event_args& e) {
  label::on_mouse_down(e);
  if (!enabled()) return;
  auto& link = point_in_link(e.location());
  if (link != link_empty) {
    link.active_(true);
    invalidate();
  }
}

void link_label::on_mouse_up(const mouse_event_args& e) {
  label::on_mouse_up(e);
  if (!enabled()) return;
  for (auto& link : data_->links)
    link.active_(false);
  invalidate();
}

void link_label::on_mouse_move(const mouse_event_args& e) {
  label::on_mouse_move(e);
  if (!enabled()) return;
  data_->mouse_hover = true;
  const auto& link = point_in_link(e.location());
  cursor(link != link_empty && link.enabled() ? override_cursor() : data_->original_cursor);
  data_->mouse_hover = false;
}

void link_label::on_paint(paint_event_args& e) {
  control::on_paint(e);
  if (control_appearance() == forms::control_appearance::system) return;
  auto style = style_sheet() != style_sheets::style_sheet::empty ? style_sheet() : style_sheets::style_sheet::current_style_sheet();
  label_renderer::draw_link_label(style, e.graphics(), e.clip_rectangle(), control_state(), back_color() != default_back_color() ? std::optional<drawing::color> {back_color()} : std::nullopt, text(), data_->links.to_array(), text_align(), fore_color() != default_fore_color() ? std::optional<drawing::color> {fore_color()} : std::nullopt, data_->link_color, data_->visited_link_color, font() != default_font() ? std::optional<drawing::font> {font()} : std::nullopt, data_->link_behavior, image(), image_align(), border_style(), border_sides(), shadows(), auto_ellipsis());
  
  if (system_information::is_operating_system_double_buffered() || double_buffered())
    e.graphics().clear(back_color());
  auto line_number = 0_z;
  auto index = 0_z;
  for (auto line : text().split('\n')) {
    auto text_location = get_text_location(line_number);
    auto line_index = 0_z;
    auto size_text = drawing::size {};
    auto text = string::empty_string;
    for (auto link : data_->links) {
      auto color = link_color();
      if (!link.enabled()) color = disabled_link_color();
      else if (link.active_()) color = active_link_color();
      else if (link.visited()) color = visited_link_color();
      
      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        if (enabled())
          e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
        else
          e.graphics().draw_string(text, font(), solid_brush(application::style_sheet().system_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length() - link.start() - index);
        size_text = drawing::size::ceiling(e.graphics().measure_string(text, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        if (enabled())
          e.graphics().draw_string(text, link_font(), solid_brush(color), {text_location, size_text});
        else
          e.graphics().draw_string(text, link_font(), solid_brush(application::style_sheet().system_colors().gray_text()), {text_location, size_text});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length() - line_index);
      size_text = drawing::size::ceiling(e.graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
      if (enabled())
        e.graphics().draw_string(text, font(), solid_brush(fore_color()), {text_location, size_text});
      else
        e.graphics().draw_string(text, font(), solid_brush(style_sheet().system_colors().gray_text()), {text_location, size_text});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }
  control_paint::draw_border_from_back_color(*this, e.graphics(), border_style(), border_sides(), back_color(), e.clip_rectangle());
}

void link_label::on_text_align_changed(const event_args& e) {
  label::on_text_changed(e);
  invalidate();
}

void link_label::on_text_changed(const event_args& e) {
  if (data_->links.empty()) data_->links.push_back({0, text().length()});
  label::on_text_changed(e);
  invalidate();
}

link_label::link& link_label::point_in_link(const xtd::drawing::point& point) {
  auto link_index = 0_z;
  for (auto [rect, is_link] : generate_text_rects())
    if (is_link) {
      if (rect.contains(point)) return data_->links[link_index];
      ++link_index;
    }
    
  return link_empty;
}

xtd::drawing::point link_label::get_text_location(size_t line_number) const noexcept {
  auto line_index = 0_z;
  for (auto line : text().split('\n')) {
    auto text_location = point {};
    auto text_size = drawing::size::ceiling(screen::create_graphics().measure_string(line, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
    switch (text_align()) {
      case content_alignment::top_left: text_location = point(0, text_size.height() * as<int32>(line_number)); break;
      case content_alignment::top_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, text_size.height() * as<int32>(line_number)); break;
      case content_alignment::top_right: text_location = point(client_rectangle().width() - text_size.width(), text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_left: text_location = point(0, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::middle_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() / 2 - text_size.height() / 2 + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_left: text_location = point(0, client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_center: text_location = point(client_rectangle().width() / 2 - text_size.width() / 2, client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      case content_alignment::bottom_right: text_location = point(client_rectangle().width() - text_size.width(), client_rectangle().height() - text_size.height() + text_size.height() * as<int32>(line_number)); break;
      default: break;
    }
    if (line_number == line_index) return text_location;
    ++line_index;
  }
  return {0, 0};
}

std::vector<std::tuple<xtd::drawing::rectangle, bool>> link_label::generate_text_rects() const noexcept {
  auto text_rects = std::vector<std::tuple<xtd::drawing::rectangle, bool>> {};
  auto line_number = 0_z;
  auto index = 0_z;
  for (auto line : text().split('\n')) {
    auto line_index = 0_z;
    auto text_location = get_text_location(line_number);
    auto size_text = drawing::size {};
    auto text = string::empty_string;
    for (auto link : data_->links) {
      if (index < link.start()) {
        text = line.substring(line_index, link.start() - line_index);
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        text_rects.push_back({{text_location, size_text}, false});
        text_location.x(text_location.x() + size_text.width());
        line_index += text.length();
      }
      
      if (index <= link.start() && line.length() + index > link.start()) {
        text = line.substring(link.start() - index, link.length() - link.start() - index);
        size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, link_font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
        text_rects.push_back({{text_location, size_text}, true});
        text_location.x(text_location.x() + size_text.width());
        line_index = link.start() - index + text.length();
      }
    }
    
    if (line_index < line.length()) {
      text = line.substring(line_index, line.length() - line_index);
      size_text = drawing::size::ceiling(screen::create_graphics().measure_string(text, font(), size_f(0.0f, 0.0f), string_format(string_format_flags::measure_trailing_spaces)));
      text_rects.push_back({{text_location, size_text}, false});
      line_index = line.length();
    }
    index += line_index + 1;
    ++line_number;
  }
  
  return text_rects;
}

xtd::drawing::font link_label::link_font() const noexcept {
  return {font(), xtd::drawing::font_style::underline};
}

void link_label::on_links_link_added(size_t pos, const link& link) {
  if (data_->links.size() == 2 && data_->links[0].start() == 0 && data_->links[0].length() == text().length())
    data_->links.erase_at(0);
  //tab_stop(true);
  invalidate();
}

void link_label::on_links_link_removed(size_t pos, const link& item) {
  invalidate();
}

void link_label::on_links_link_updated(size_t pos, const link& link) {
  invalidate();
}

