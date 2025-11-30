#include "../../../../include/xtd/forms/style_sheets/background_image.hpp"
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/texture_brush>
#include <xtd/drawing/system_colors>
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/not_supported_exception>

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

const background_image background_image::empty;

background_image::background_image(const string& url) : image_type_(style_sheets::image_type::url), url_(url) {
}

background_image::background_image(const array<color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.length() < 2_z) throw_helper::throws(exception_case::argument);
}

background_image::background_image(const array<color>& colors, int32 angle) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.length() < 2_z) throw_helper::throws(exception_case::argument);
}

background_image::background_image(style_sheets::image_type image_type, const array<color>& colors) : image_type_(image_type), colors_(colors) {
  if (colors.length() < 2_z) throw_helper::throws(exception_case::argument);
  if (image_type != style_sheets::image_type::linear_gradient) throw_helper::throws(exception_case::not_supported);
}

background_image::background_image(style_sheets::image_type image_type, const array<color>& colors, int32 angle) : image_type_(image_type), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.length() < 2_z) throw_helper::throws(exception_case::argument);
  if (image_type != style_sheets::image_type::linear_gradient) throw_helper::throws(exception_case::not_supported);
}

background_image::background_image(const std::initializer_list<xtd::drawing::color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2_z) throw_helper::throws(exception_case::argument);
}

int32 background_image::angle() const noexcept {
  return angle_;
}

void background_image::angle(int32 value) noexcept {
  angle_ = value;
}

const array<xtd::drawing::color>& background_image::colors() const noexcept {
  return colors_;
}

void background_image::colors(const array<xtd::drawing::color>& value) {
  colors_ = value;
  if (colors_.length() < 2_z) throw_helper::throws(exception_case::argument);
}

const xtd::uri& background_image::url() const noexcept {
  return url_;
}

void background_image::url(const xtd::uri& value) noexcept {
  url_ = value;
}

style_sheets::image_type background_image::image_type() const noexcept {
  return image_type_;
}

void background_image::image_type(style_sheets::image_type value) noexcept {
  image_type_ = value;
}

xtd::uptr<xtd::drawing::brush> background_image::make_brush(const xtd::forms::style_sheets::background_image& image, const xtd::drawing::rectangle& rect) {
  if (image.image_type() == style_sheets::image_type::linear_gradient)
    return xtd::new_uptr<linear_gradient_brush>(rect, image.colors(), as<float>(image.angle() - 90.0f));
  if (image.image_type() == style_sheets::image_type::url)
    return xtd::new_uptr<texture_brush>(image::from_file(image.url().to_string()));
  return nullptr;
}

bool background_image::equals(const object& obj) const noexcept {
  return is<background_image>(obj) && equals(static_cast<const background_image&>(obj));
}

bool background_image::equals(const background_image& other) const noexcept {
  return image_type_ == other.image_type_ && url_ == other.url_ && colors_ == other.colors_ && angle_ == other.angle_;
}

xtd::size background_image::get_hash_code() const noexcept {
  auto result = hash_code {};
  result.add(image_type_);
  result.add(url_);
  for (const auto& color : colors_)
    result.add(color);
  result.add(angle_);
  return result.to_hash_code();
}

xtd::string background_image::to_string() const noexcept {
  return string::format("[image_type={}, url={}, colors=[{}], angle={}]", image_type(), url(), colors(), angle());
}
