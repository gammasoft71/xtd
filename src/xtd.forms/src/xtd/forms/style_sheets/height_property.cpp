#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/height_property.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

const height_property height_property::empty;

int32_t height_property::height() const noexcept {
  return height_;
}

void height_property::height(int32_t value) noexcept {
  height_ = value;
}

bool height_property::equals(const object& other) const noexcept {
  return is<height_property>(other) ? equals(static_cast<const height_property&>(other)) : false;
}

bool height_property::equals(const height_property& other) const noexcept {
  return height_ == other.height_;
}

bool height_property::from_css(const xtd::ustring& css_text, height_property& result) noexcept {
  auto value = css_text.trim();
  if (value == "auto" || value == "initial" || value == "inherit") {
    result.height_ = -1;
    return true;
  }
  if (value.ends_with("cm")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("cm", ""), w)) return false;
    result.height_ = as<int32_t>(w / 2.54 * 96.0);
    return true;
  }
  if (value.ends_with("mm")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("mm", ""), w)) return false;
    result.height_ = as<int32_t>(w / 2.54 * 96.0 * 1000.0);
    return true;
  }
  if (value.ends_with("in")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("in", ""), w)) return false;
    result.height_ = as<int32_t>(w * 96.0);
    return true;
  }
  if (value.ends_with("px")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("px", ""), w)) return false;
    result.height_ = as<int32_t>(w);
    return true;
  }
  if (value.ends_with("pt")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("pt", ""), w)) return false;
    result.height_ = as<int32_t>(w / 96.0 * 72.0);
    return true;
  }
  if (value.ends_with("pc")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("pc", ""), w)) return false;
    result.height_ = as<int32_t>(w * 12.0 / 96.0 * 72.0);
    return true;
  }
  return false;
}

height_property height_property::from_css(const xtd::ustring& css_text, const height_property& default_value) noexcept {
  auto result = default_value;
  from_css(css_text, result);
  return default_value;
}

xtd::ustring height_property::to_css() const noexcept {
  if (height() == -1) return "auto";
  return ustring::format("{}px", height());
}
