#include <xtd/argument_exception.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/texture_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/image_value.h"
#include "../../../../include/xtd/forms/style_sheets/color_property.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

image_value::image_value(const ustring& url) : image_type_(style_sheets::image_type::url), url_(url) {
}

image_value::image_value(const vector<color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

image_value::image_value(const vector<color>& colors, int32_t angle) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

image_value::image_value(style_sheets::image_type image_type, const vector<color>& colors) : image_type_(image_type), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception(csf_);
}

image_value::image_value(style_sheets::image_type image_type, const vector<color>& colors, int32_t angle) : image_type_(image_type), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2U) throw argument_exception(csf_);
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception(csf_);
}

image_value::image_value(const std::initializer_list<xtd::drawing::color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

int32_t image_value::angle() const noexcept {
  return angle_;
}

void image_value::angle(int32_t value) noexcept {
  angle_ = value;
}

const std::vector<xtd::drawing::color>& image_value::colors() const noexcept {
  return colors_;
}

void image_value::colors(const std::vector<xtd::drawing::color>& value) {
  colors_ = value;
  if (colors_.size() < 2U) throw argument_exception(csf_);
}

const xtd::ustring& image_value::url() const noexcept {
  return url_;
}

void image_value::url(const xtd::ustring& value) noexcept {
  url_ = value;
}

style_sheets::image_type image_value::image_type() const noexcept {
  return image_type_;
}

void image_value::image_type(style_sheets::image_type value) noexcept {
  image_type_ = value;
}

bool image_value::from_css(const xtd::ustring& css_text, image_value& result) {
  return try_parse(css_text, result);
}

std::unique_ptr<xtd::drawing::brush> image_value::make_brush(const xtd::forms::style_sheets::image_value& image, const xtd::drawing::rectangle& rect) {
  if (image.image_type() == style_sheets::image_type::linear_gradient) {
    auto angle = image.angle() % 360;
    if (angle < 0) angle = 360 + angle;
    if (image.angle() <= 45) return make_unique<linear_gradient_brush>(rect, image.colors()[1], image.colors()[0], linear_gradient_mode::vertical);
    if (image.angle() <= 135) return make_unique<linear_gradient_brush>(rect, image.colors()[0], image.colors()[1], linear_gradient_mode::horizontal);
    if (image.angle() <= 225) return make_unique<linear_gradient_brush>(rect, image.colors()[0], image.colors()[1], linear_gradient_mode::vertical);
    if (image.angle() <= 315) return make_unique<linear_gradient_brush>(rect, image.colors()[1], image.colors()[0], linear_gradient_mode::horizontal);
    return make_unique<linear_gradient_brush>(rect, image.colors()[1], image.colors()[0], linear_gradient_mode::vertical);
  }
  if (image.image_type() == style_sheets::image_type::url)
    return make_unique<texture_brush>(image::from_file(image.url()));
  return null;
}

image_value image_value::parse(const xtd::ustring& text) {
  image_value result;
  if (!try_parse(text, result))
    throw argument_exception(csf_);
  return result;
}

xtd::ustring image_value::to_string() const noexcept {
  return ustring::format("[image_type={}, url={}, colors=[{}], angle={}]", image_type(), url(), colors(), angle());
}

xtd::ustring image_value::to_css() const noexcept {
  if (image_type() == style_sheets::image_type::url) return ustring::format("url({})", url());
  if (image_type() == style_sheets::image_type::linear_gradient) {
    ustring result = "linear-gradient(";
    if (angle() != 180) result += angle_to_string(angle());
    for (auto i = 0U; i < colors().size(); ++i)
      result += ustring::format("{}{}", i != 0 || angle() != 180 ? ", " : "", color_to_string(colors()[i]));
    return result + ")";
  }
  return "transparent";
}

bool image_value::try_parse(const xtd::ustring& text, image_value& result) {
  auto value = remove_key(text);
  if (text.starts_with("url(") && text.ends_with(")")) return try_parse_url(value, result);
  if (text.starts_with("linear-gradient(") && text.ends_with(")")) return try_parse_linear_gradient_color(value, result);
  return false;
}

xtd::ustring image_value::angle_to_string(int32_t angle) {
  if (angle == 0) return "to top";
  if (angle == 45) return "to top right";
  if (angle == 90) return "to right";
  if (angle == 135) return "to bottom right";
  if (angle == 180) return "to botom";
  if (angle == 225) return "to bottom left";
  if (angle == 270) return "to left";
  if (angle == 315) return "to top left";
  return ustring::format("{}deg", angle);
}

xtd::ustring image_value::color_to_string(const drawing::color& color) {
  static map<ustring, drawing::color> colors {{"accent", system_colors::accent()}, {"accent_text", system_colors::accent_text()}, {"active_border", system_colors::active_border()}, {"active_caption", system_colors::active_caption()}, {"active_caption_text", system_colors::active_caption_text()}, {"app_workspace", system_colors::app_workspace()}, {"button_face", system_colors::button_face()}, {"button_highlight", system_colors::button_highlight()}, {"button_shadow", system_colors::button_shadow()}, {"control", system_colors::control()}, {"control_dark", system_colors::control_dark()}, {"control_dark_dark", system_colors::control_dark_dark()}, {"control_light", system_colors::control_light()}, {"control_light_light", system_colors::control_light_light()}, {"control_text", system_colors::control_text()}, {"desktop", system_colors::desktop()}, {"gradient_active_caption", system_colors::gradient_active_caption()}, {"gradient_inactive_caption", system_colors::gradient_inactive_caption()}, {"gray_text", system_colors::gray_text()}, {"highlight", system_colors::highlight()}, {"highlight_text", system_colors::highlight_text()}, {"hot_track", system_colors::hot_track()}, {"inactive_border", system_colors::inactive_border()}, {"inactive_caption", system_colors::inactive_caption()}, {"inactive_caption_text", system_colors::inactive_caption_text()}, {"info", system_colors::info()}, {"info_text", system_colors::info_text()}, {"menu", system_colors::menu()}, {"menu_bar", system_colors::menu_bar()}, {"menu_highlight", system_colors::menu_highlight()}, {"menu_text", system_colors::menu_text()}, {"scroll_bar", system_colors::scroll_bar()}, {"text_box", system_colors::text_box()}, {"text_box_text", system_colors::text_box_text()}, {"window", system_colors::window()}, {"window_frame", system_colors::window_frame()}, {"window_text", system_colors::window_text()}};
  auto it = colors.find(color.name());
  if (it != colors.end()) return ustring::format("system-color({})", color.name().replace("_", "-"));
  if (color.name() != ustring::format("{:X8}", color.to_argb())) return color.name().replace("_", "");
  if (color.a() == 255) return ustring::format("#{:X2}{:X2}{:X2}", color.r(), color.g(), color.b());
  return ustring::format("rgba({}, {}, {}, {})", color.r(), color.g(), color.b(), color.a());
}

ustring image_value::remove_key(const xtd::ustring& text) {
  auto result = text.trim();
  if (result.starts_with("color:")) result = result.replace("color:", "");
  if (result.starts_with("border-color:")) result = result.replace("border-color:", "");
  if (result.starts_with("background-color:")) result = result.replace("background-color:", "");
  result = result.trim_end(';');
  return result.trim();
}

bool image_value::try_parse_url(const xtd::ustring& text, image_value& result) {
  auto value = text.remove(text.size()-1).replace("url(", "");
  result = image_value(value);
  return true;
}

vector<ustring> image_value::split_arguments(const xtd::ustring& text) {
  return color_property::split_colors(text);
}

bool image_value::try_parse_linear_gradient_color(const xtd::ustring& text, image_value& result) {
  vector<ustring> arguments = split_arguments(text.remove(text.size()-1).replace("linear-gradient(", ""));
  vector<color> colors;
  int32_t angle = -1;
  for (auto argument : arguments) {
    color_property color;
    if (argument == "to top") {
      if (angle != -1) return false;
      angle = 0;
    } else if (argument == "to top right") {
      if (angle != -1) return false;
      angle = 45;
    } else if (argument == "to right") {
      if (angle != -1) return false;
      angle = 90;
    } else if (argument == "to bottom right") {
      if (angle != -1) return false;
      angle = 135;
    } else if (argument == "to bottom") {
      if (angle != -1) return false;
      angle = 180;
    } else if (argument == "to bottom left") {
      if (angle != -1) return false;
      angle = 225;
    } else if (argument == "to left") {
      if (angle != -1) return false;
      angle = 270;
    } else if (argument == "to top left") {
      if (angle != -1) return false;
      angle = 315;
    } else if (argument.ends_with("deg")) {
      argument = argument.replace("deg", "");
      if (angle != -1 || xtd::try_parse<int32_t>(argument, angle) == false) return false;
    } else if (color_property::try_parse(argument, color))
      colors.push_back(color.color());
  }
  if (colors.size() < 2) return false;
  result = image_value(style_sheets::image_type::linear_gradient, colors, angle == -1? 180 : angle);
  return true;
}
