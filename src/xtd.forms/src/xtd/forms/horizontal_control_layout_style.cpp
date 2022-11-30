#include "../../../include/xtd/forms/horizontal_control_layout_style.h"
#include "../../../include/xtd/forms/application.h"

using namespace xtd;
using namespace xtd::forms;

horizontal_control_layout_style::horizontal_control_layout_style(float width) : width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width) : width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type) : control_layout_style(size_type) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(bool expanded) : control_layout_style(expanded) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, bool expanded) : control_layout_style(expanded), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, bool expanded) : control_layout_style(expanded), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::content_alignment align) : control_layout_style(align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::content_alignment align) : control_layout_style(align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, xtd::forms::content_alignment align) : control_layout_style(align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32_t width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(static_cast<float>(width)) {
}

std::optional<float> horizontal_control_layout_style::width() const noexcept {
  return width_;
}

void horizontal_control_layout_style::width(float width) {
  width_ = width;
}

xtd::ustring horizontal_control_layout_style::to_string() const noexcept {
  return ustring::format("horizontal_control_layout_style=[expanded={}, align={}, size_type={}, width={}]", expanded(), align(), size_type(), width_.value_or(-1));
}

bool horizontal_control_layout_style::operator ==(const horizontal_control_layout_style& value) const noexcept {
  return width_ == value.width_ && control_layout_style::operator ==(value);
}

bool horizontal_control_layout_style::operator !=(const horizontal_control_layout_style& value) const noexcept {
  return !operator ==(value);
}
