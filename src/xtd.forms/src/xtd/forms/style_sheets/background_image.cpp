#include <xtd/argument_exception.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/texture_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/background_image.h"
#include "../../../../include/xtd/forms/style_sheets/border_color.h"
#include "../../../../include/xtd/forms/style_sheets/color_property.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

background_image::background_image(const ustring& url) : image_type_(style_sheets::image_type::url), url_(url) {
}

background_image::background_image(const vector<color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

background_image::background_image(const vector<color>& colors, int32_t angle) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

background_image::background_image(style_sheets::image_type image_type, const vector<color>& colors) : image_type_(image_type), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception(csf_);
}

background_image::background_image(style_sheets::image_type image_type, const vector<color>& colors, int32_t angle) : image_type_(image_type), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2U) throw argument_exception(csf_);
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception(csf_);
}

background_image::background_image(const std::initializer_list<xtd::drawing::color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2U) throw argument_exception(csf_);
}

int32_t background_image::angle() const noexcept {
  return angle_;
}

void background_image::angle(int32_t value) noexcept {
  angle_ = value;
}

const std::vector<xtd::drawing::color>& background_image::colors() const noexcept {
  return colors_;
}

void background_image::colors(const std::vector<xtd::drawing::color>& value) {
  colors_ = value;
  if (colors_.size() < 2U) throw argument_exception(csf_);
}

const xtd::ustring& background_image::url() const noexcept {
  return url_;
}

void background_image::url(const xtd::ustring& value) noexcept {
  url_ = value;
}

style_sheets::image_type background_image::image_type() const noexcept {
  return image_type_;
}

void background_image::image_type(style_sheets::image_type value) noexcept {
  image_type_ = value;
}

bool background_image::from_css(const xtd::ustring& css_text, background_image& result) {
  return try_parse(css_text, result);
}

std::unique_ptr<xtd::drawing::brush> background_image::make_brush(const xtd::forms::style_sheets::background_image& image, const xtd::drawing::rectangle& rect) {
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

background_image background_image::parse(const xtd::ustring& text) {
  background_image result;
  if (!try_parse(text, result))
    throw argument_exception(csf_);
  return result;
}

xtd::ustring background_image::to_string() const noexcept {
  return ustring::format("[image_type={}, url={}, colors=[{}], angle={}]", image_type(), url(), colors(), angle());
}

xtd::ustring background_image::to_css() const noexcept {
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

bool background_image::try_parse(const xtd::ustring& text, background_image& result) {
  auto value = remove_key(text);
  if (text.starts_with("url(") && text.ends_with(")")) return try_parse_url(value, result);
  if (text.starts_with("linear-gradient(") && text.ends_with(")")) return try_parse_linear_gradient_color(value, result);
  return false;
}

xtd::ustring background_image::angle_to_string(int32_t angle) {
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

xtd::ustring background_image::color_to_string(const drawing::color& color) {
  static map<ustring, drawing::color> colors {{"accent", system_colors::accent()}, {"accent_text", system_colors::accent_text()}, {"active_border", system_colors::active_border()}, {"active_caption", system_colors::active_caption()}, {"active_caption_text", system_colors::active_caption_text()}, {"app_workspace", system_colors::app_workspace()}, {"button_face", system_colors::button_face()}, {"button_highlight", system_colors::button_highlight()}, {"button_shadow", system_colors::button_shadow()}, {"control", system_colors::control()}, {"control_dark", system_colors::control_dark()}, {"control_dark_dark", system_colors::control_dark_dark()}, {"control_light", system_colors::control_light()}, {"control_light_light", system_colors::control_light_light()}, {"control_text", system_colors::control_text()}, {"desktop", system_colors::desktop()}, {"gradient_active_caption", system_colors::gradient_active_caption()}, {"gradient_inactive_caption", system_colors::gradient_inactive_caption()}, {"gray_text", system_colors::gray_text()}, {"highlight", system_colors::highlight()}, {"highlight_text", system_colors::highlight_text()}, {"hot_track", system_colors::hot_track()}, {"inactive_border", system_colors::inactive_border()}, {"inactive_caption", system_colors::inactive_caption()}, {"inactive_caption_text", system_colors::inactive_caption_text()}, {"info", system_colors::info()}, {"info_text", system_colors::info_text()}, {"menu", system_colors::menu()}, {"menu_bar", system_colors::menu_bar()}, {"menu_highlight", system_colors::menu_highlight()}, {"menu_text", system_colors::menu_text()}, {"scroll_bar", system_colors::scroll_bar()}, {"text_box", system_colors::text_box()}, {"text_box_text", system_colors::text_box_text()}, {"window", system_colors::window()}, {"window_frame", system_colors::window_frame()}, {"window_text", system_colors::window_text()}};
  auto it = colors.find(color.name());
  if (it != colors.end()) return ustring::format("system-color({})", color.name().replace("_", "-"));
  if (color.name() != ustring::format("{:X8}", color.to_argb())) return color.name().replace("_", "");
  if (color.a() == 255) return ustring::format("#{:X2}{:X2}{:X2}", color.r(), color.g(), color.b());
  return ustring::format("rgba({}, {}, {}, {})", color.r(), color.g(), color.b(), color.a());
}

ustring background_image::remove_key(const xtd::ustring& text) {
  auto result = text.trim();
  if (result.starts_with("color:")) result = result.replace("color:", "");
  if (result.starts_with("border-color:")) result = result.replace("border-color:", "");
  if (result.starts_with("background-color:")) result = result.replace("background-color:", "");
  result = result.trim_end(';');
  return result.trim();
}

bool background_image::try_parse_url(const xtd::ustring& text, background_image& result) {
  auto value = text.remove(text.size()-1).replace("url(", "");
  result = background_image(value);
  return true;
}

vector<ustring> background_image::split_arguments(const xtd::ustring& text) {
  //return border_color::split_colors(text);
  
  /// @todo remove when merge in style_sheet and use split_colors_form_css
  static vector<ustring> color_keywords = {"rgb(", "rgba(", "argb(", "hsl(", "hsla(", "ahsl(", "hsv(", "hsva(", "ahsv(", "system-color("};
  auto string_starts_with_any = [](const ustring& text, const vector<ustring>& values)->ustring {
    for (auto value : values)
      if (text.starts_with(value)) return value;
    return "";
  };
  vector<ustring> result;
  auto value = text.trim();
  while (!value.empty()) {
    auto color_keyword = string_starts_with_any(value, color_keywords);
    if (color_keyword != "") {
      result.push_back(value.substring(0, value.find(")") + 1).trim());
      value = value.remove(0, value.find(")") + 1).trim();
      if (value[0] == ',') value = value.remove(0, 1).trim();
    } else if (value.find(",") == ustring::npos) {
      result.push_back(value.trim());
      value = "";
    } else if (value.find(",") != ustring::npos) {
      result.push_back(value.substring(0, value.find(",")).trim());
      value = value.remove(0, value.find(",") + 1).trim();
    }
  }
  return result;
}

bool background_image::try_parse_linear_gradient_color(const xtd::ustring& text, background_image& result) {
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
  result = background_image(style_sheets::image_type::linear_gradient, colors, angle == -1? 180 : angle);
  return true;
}
