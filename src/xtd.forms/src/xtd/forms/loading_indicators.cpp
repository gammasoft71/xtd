#include "../../../include/xtd/forms/loading_indicators.h"

using namespace xtd;
using namespace xtd::forms;

loading_indicator loading_indicators::circle_blinks(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept {
  auto result = loading_indicator {};
  result.loading_indicator_style(xtd::forms::loading_indicator_style::circle_blinks);
  if (location.x() != -1 && location.y() != -1) result.location(location);
  if (size.width() != -1 && size.height() != -1) result.size(size);
  return result;
}

loading_indicator loading_indicators::standard(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept {
  auto result = loading_indicator {};
  result.loading_indicator_style(xtd::forms::loading_indicator_style::standard);
  if (location.x() != -1 && location.y() != -1) result.location(location);
  if (size.width() != -1 && size.height() != -1) result.size(size);
  return result;
}

loading_indicator loading_indicators::system(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept {
  auto result = loading_indicator {};
  result.loading_indicator_style(xtd::forms::loading_indicator_style::system);
  if (location.x() != -1 && location.y() != -1) result.location(location);
  if (size.width() != -1 && size.height() != -1) result.size(size);
  return result;
}

loading_indicator loading_indicators::three_balls(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept {
  auto result = loading_indicator {};
  result.loading_indicator_style(xtd::forms::loading_indicator_style::three_balls);
  if (location.x() != -1 && location.y() != -1) result.location(location);
  if (size.width() != -1 && size.height() != -1) result.size(size);
  return result;
}

loading_indicator loading_indicators::three_balls_bouncing(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept {
  auto result = loading_indicator {};
  result.loading_indicator_style(xtd::forms::loading_indicator_style::three_balls_bouncing);
  if (location.x() != -1 && location.y() != -1) result.location(location);
  if (size.width() != -1 && size.height() != -1) result.size(size);
  return result;
}
