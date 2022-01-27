#include "../../../../include/xtd/forms/style_sheets/box_data.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const color_property& background_color) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const image_value& background_image) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_image_(background_image) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const color_property& background_color, const image_value& background_image) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), background_image_(background_image) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const color_property& background_color, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), width_(width), height_(height) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const image_value& background_image, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_image_(background_image), width_(width), height_(height) {
}

box_data::box_data(const forms::padding& margin, const xtd::forms::style_sheets::border_style_property& border_style, const xtd::forms::style_sheets::border_color_property& border_color, const xtd::forms::style_sheets::border_width_property& border_width, const xtd::forms::style_sheets::border_radius_property& border_radius, const forms::padding& padding, const color_property& background_color, const image_value& background_image, optional<int32_t> width, optional<int32_t> height) : margin_(margin), border_style_(border_style), border_color_(border_color), border_width_(border_width), border_radius_(border_radius), padding_(padding), background_color_(background_color), background_image_(background_image), width_(width), height_(height) {
}

const color_property& box_data::background_color() const noexcept {
  return background_color_;
}

void box_data::background_color(const color_property& value) noexcept {
  background_color_ = value;
}

const image_value& box_data::background_image() const noexcept {
  return background_image_;
}

void box_data::background_image(const image_value& value) noexcept {
  background_image_ = value;
}

const xtd::forms::style_sheets::border_color_property& box_data::border_color() const noexcept {
  return border_color_;
}

void box_data::border_color(const xtd::forms::style_sheets::border_color_property& value) noexcept {
  border_color_ = value;
}

xtd::forms::style_sheets::border_radius_property box_data::border_radius() const noexcept {
  return border_radius_;
}

void box_data::border_radius(xtd::forms::style_sheets::border_radius_property value) noexcept {
  border_radius_ = value;
}

xtd::forms::style_sheets::border_style_property box_data::border_style() const noexcept {
  return border_style_;
}

void box_data::border_style(xtd::forms::style_sheets::border_style_property value) noexcept {
  border_style_ = value;
}

xtd::forms::style_sheets::border_width_property box_data::border_width() const noexcept {
  return border_width_;
}

void box_data::border_width(xtd::forms::style_sheets::border_width_property value) noexcept {
  border_width_ = value;
}

optional<int32_t> box_data::height() const noexcept {
  return height_;
}

const xtd::forms::padding& box_data::margin() const noexcept {
  return margin_;
}

const xtd::forms::padding& box_data::padding() const noexcept {
  return padding_;
}

optional<int32_t> box_data::width() const noexcept {
  return width_;
}

bool box_data::from_css(const xtd::ustring& css_text, box_data& result) {
  auto key_values = css_text.replace("\n", "").replace("\r", "").split({';'});
  result = box_data();
  for (auto item : key_values) {
    auto key_value = item.split({':'});
    if (key_values.size() != 2U) return false;
    key_value[0] = key_value[0].trim();
    key_value[1] = key_value[0].trim();
    
    if (key_value[0] == "border-style") {
      if (try_parse_border_style(key_value[1], result.border_style_) == false) return false;
    }
    if (key_value[0] == "border-color") {
      if (try_parse_border_color(key_value[1], result.border_color_) == false) return false;
    }
    if (key_value[0] == "border-width") {
      if (try_parse_border_width(key_value[1], result.border_width_) == false) return false;
    }
    if (key_value[0] == "border-radius") {
      if (try_parse_border_radius(key_value[1], result.border_radius_) == false) return false;
    }
  }
  return true;
}

rectangle box_data::get_border_rectangle(const rectangle& bounds) const noexcept {
  auto bounds_rect = bounds;
  if (width() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), margin().left() + border_width().left() + padding().left() + width().value() + padding().right() + border_width().right() + margin().right(), bounds_rect.height());
  if (height() != nullopt) bounds_rect = rectangle(bounds_rect.x(), bounds_rect.y(), bounds_rect.width(), margin().top() + border_width().top() + padding().top() + height().value() + padding().bottom() + border_width().bottom() + margin().bottom());
  
  auto border_rect = rectangle::offset(bounds_rect, margin().left(), margin().top());
  border_rect = rectangle::inflate(border_rect, -margin().right() - margin().left(), -margin().bottom() - margin().top());
  return border_rect;
}

rectangle box_data::get_fill_rectangle(const rectangle& bounds) const noexcept {
  auto fill_rect = rectangle::offset(get_border_rectangle(bounds), border_width().left(), border_width().top());
  fill_rect = rectangle::inflate(fill_rect, -border_width().left() - border_width().right(), -border_width().top() - border_width().bottom());
  return fill_rect;
}

rectangle box_data::get_content_rectangle(const rectangle& bounds) const noexcept {
  auto content_rect = rectangle::offset(get_fill_rectangle(bounds), padding().left(), padding().top());
  content_rect = rectangle::inflate(content_rect, -padding().left() - padding().right(), -padding().top() - padding().bottom());
  return content_rect;
}

xtd::ustring box_data::to_css() const noexcept {
  //return ustring::format("   border-style: {};\n  border-color: {};\n  border-width:{};  border-radius: {};\n", style(), color(), width(), radius());
  return "";
}

std::vector<xtd::ustring> box_data::split_border_colors(const xtd::ustring& text) {
  static vector<ustring> start_color_keywords {"rgb", "rgba", "argb", "hsv", "hsva", "ahsv", "hsl", "hsla", "ahsl", "#", "linear-gradient", "radial-gradient", "conic-gradient"};
  vector<ustring> result;
  
  return result;
}

bool box_data::try_parse_border_color(const ustring& text, xtd::forms::style_sheets::border_color_property& border_color) {
  vector<ustring> values = split_border_colors(text);
  if (values.size() < 1 || values.size() > 4) return false;

  color_property color;
  if (color_property::try_parse(values[0], color) == false) return false;
  border_color.all(color);

  if (values.size() >= 2U) {
    if (color_property::try_parse(values[1], color) == false) return false;
    border_color.right(color);
  }
  if (values.size() >= 3U) {
    if (color_property::try_parse(values[2], color) == false) return false;
    border_color.bottom(color);
  }
  if (values.size() >= 4U) {
    if (color_property::try_parse(values[3], color) == false) return false;
    border_color.left(color);
  }
  
  return false;
}

bool box_data::try_parse_border_style(const ustring& text, xtd::forms::style_sheets::border_style_property& border_style) {
  static map<ustring, xtd::forms::style_sheets::border_type> border_types = {{"none", border_type::none}, {"hidden", border_type::hidden}, {"dashed", border_type::dashed}, {"dot-dash", border_type::dot_dash},  {"dot-dot-dash", border_type::dot_dot_dash}, {"dotted", border_type::dotted}, {"double", border_type::double_border}, {"groove", border_type::groove}, {"inset", border_type::inset}, {"outset", border_type::outset}, {"ridge", border_type::ridge}, {"solid", border_type::solid}};
  auto values = text.split();
  if (values.size() < 1 || values.size() > 4) return false;

  auto it = border_types.find(values[0]);
  if (it == border_types.end()) return false;
  border_style.all(it->second);

  if (values.size() >= 2) {
    it = border_types.find(values[1]);
    if (it == border_types.end()) return false;
    border_style.right(it->second);
  }
  if (values.size() >= 3) {
    it = border_types.find(values[2]);
    if (it == border_types.end()) return false;
    border_style.bottom(it->second);
  }
  if (values.size() == 4) {
    it = border_types.find(values[3]);
    if (it == border_types.end()) return false;
    border_style.left(it->second);
  }
  
  return true;
}

bool box_data::try_parse_border_radius(const ustring &text, xtd::forms::style_sheets::border_radius_property& border_radius) {
  return false;
}

bool box_data::try_parse_border_width(const ustring &text, xtd::forms::style_sheets::border_width_property& border_width) {
  return false;
}

bool box_data::try_parse_padding(const ustring &text, xtd::forms::padding& padding) {
  return false;
}
