#include <xtd/argument_exception.h>
#include <xtd/as.h>
#include <xtd/drawing/solid_brush.h>
#include <xtd/drawing/system_colors.h>
#include <xtd/drawing/drawing2d/linear_gradient_brush.h>
#include <xtd/not_supported_exception.h>
#include "../../../../include/xtd/forms/style_sheets/width_property.h"

using namespace xtd;
using namespace xtd::forms::style_sheets;

const width_property width_property::empty;

int32_t width_property::width() const noexcept {
  return width_;
}

void width_property::width(int32_t value) noexcept {
  width_ = value;
}

bool width_property::equals(const object& other) const noexcept {
  return is<width_property>(other) ? equals(static_cast<const width_property&>(other)) : false;
}

bool width_property::equals(const width_property& other) const noexcept {
  return width_ == other.width_;
}

bool width_property::from_css(const xtd::ustring& css_text, width_property& result) noexcept {
  auto value = css_text.trim();
  if (value == "auto" || value == "initial" || value == "inherit") {
    result.width_ = -1;
    return true;
  }
  if (value.ends_with("cm")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("cm", ""), w)) return false;
    result.width_ = as<int32_t>(w / 2.54 * 96.0);
    return true;
  }
  if (value.ends_with("mm")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("mm", ""), w)) return false;
    result.width_ = as<int32_t>(w / 2.54 * 96.0 * 1000.0);
    return true;
  }
  if (value.ends_with("in")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("in", ""), w)) return false;
    result.width_ = as<int32_t>(w * 96.0);
    return true;
  }
  if (value.ends_with("px")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("px", ""), w)) return false;
    result.width_ = as<int32_t>(w);
    return true;
  }
  if (value.ends_with("pt")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("pt", ""), w)) return false;
    result.width_ = as<int32_t>(w / 96.0 * 72.0);
    return true;
  }
  if (value.ends_with("pc")) {
    auto w = .0;
    if (!::try_parse<double>(value.replace("pc", ""), w)) return false;
    result.width_ = as<int32_t>(w * 12.0 / 96.0 * 72.0);
    return true;
  }
  return false;
}

width_property width_property::from_css(const xtd::ustring& css_text, const width_property& default_value) noexcept {
  auto result = default_value;
  from_css(css_text, result);
  return default_value;
}

xtd::ustring width_property::to_css() const noexcept {
  if (width() == -1) return "auto";
  return ustring::format("{}px", width());
}
