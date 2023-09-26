#include "../../../../include/xtd/forms/style_sheets/background_image"
#include <xtd/drawing/solid_brush>
#include <xtd/drawing/texture_brush>
#include <xtd/drawing/system_colors>
#include <xtd/drawing/drawing_2d/linear_gradient_brush>
#include <xtd/argument_exception>
#include <xtd/as>
#include <xtd/not_supported_exception>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::drawing::drawing_2d;
using namespace xtd::forms;
using namespace xtd::forms::style_sheets;

const background_image background_image::empty;

background_image::background_image(const ustring& url) : image_type_(style_sheets::image_type::url), url_(url) {
}

background_image::background_image(const vector<color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2_sz) throw argument_exception {csf_};
}

background_image::background_image(const vector<color>& colors, int32 angle) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2_sz) throw argument_exception {csf_};
}

background_image::background_image(style_sheets::image_type image_type, const vector<color>& colors) : image_type_(image_type), colors_(colors) {
  if (colors.size() < 2_sz) throw argument_exception {csf_};
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception {csf_};
}

background_image::background_image(style_sheets::image_type image_type, const vector<color>& colors, int32 angle) : image_type_(image_type), colors_(colors), angle_((angle % 360) < 0 ? 360 + (angle % 360) : (angle % 360)) {
  if (colors.size() < 2_sz) throw argument_exception {csf_};
  if (image_type != style_sheets::image_type::linear_gradient) throw not_supported_exception {csf_};
}

background_image::background_image(const std::initializer_list<xtd::drawing::color>& colors) : image_type_(style_sheets::image_type::linear_gradient), colors_(colors) {
  if (colors.size() < 2_sz) throw argument_exception {csf_};
}

int32 background_image::angle() const noexcept {
  return angle_;
}

void background_image::angle(int32 value) noexcept {
  angle_ = value;
}

const std::vector<xtd::drawing::color>& background_image::colors() const noexcept {
  return colors_;
}

void background_image::colors(const std::vector<xtd::drawing::color>& value) {
  colors_ = value;
  if (colors_.size() < 2_sz) throw argument_exception {csf_};
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

std::unique_ptr<xtd::drawing::brush> background_image::make_brush(const xtd::forms::style_sheets::background_image& image, const xtd::drawing::rectangle& rect) {
  if (image.image_type() == style_sheets::image_type::linear_gradient)
    return make_unique<linear_gradient_brush>(rect, image.colors(), as<float>(image.angle() - 90.0f));
  if (image.image_type() == style_sheets::image_type::url)
    return make_unique<texture_brush>(image::from_file(image.url().to_string()));
  return nullptr;
}

xtd::ustring background_image::to_string() const noexcept {
  return ustring::format("[image_type={}, url={}, colors=[{}], angle={}]", image_type(), url(), colors(), angle());
}
