#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/vertical_control_layout_style.h"

using namespace xtd;
using namespace xtd::forms;

vertical_control_layout_style::vertical_control_layout_style(float height) : height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height) : height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(xtd::forms::size_type size_type) : control_layout_style(size_type) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, xtd::forms::size_type size_type) : control_layout_style(size_type), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, xtd::forms::size_type size_type) : control_layout_style(size_type), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(bool expanded) : control_layout_style(expanded) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, bool expanded) : control_layout_style(expanded), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, bool expanded) : control_layout_style(expanded), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(xtd::forms::content_alignment align) : control_layout_style(align) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, xtd::forms::content_alignment align) : control_layout_style(align), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, xtd::forms::content_alignment align) : control_layout_style(align), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), height_(static_cast<float>(height)) {
}

vertical_control_layout_style::vertical_control_layout_style(bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align) {
}

vertical_control_layout_style::vertical_control_layout_style(float height, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), height_(height) {
}

vertical_control_layout_style::vertical_control_layout_style(int32 height, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), height_(static_cast<float>(height)) {
}

std::optional<float> vertical_control_layout_style::height() const noexcept {
  return height_;
}

void vertical_control_layout_style::height(float height) {
  height_ = height;
}

bool vertical_control_layout_style::equals(const vertical_control_layout_style& value) const noexcept {
  return height_ == value.height_ && control_layout_style::equals(value);
}

xtd::ustring vertical_control_layout_style::to_string() const noexcept {
  return ustring::format("vertical_control_layout_style=[expanded={}, align={}, size_type={}, height={}]", expanded(), align(), size_type(), height_.value_or(-1));
}
