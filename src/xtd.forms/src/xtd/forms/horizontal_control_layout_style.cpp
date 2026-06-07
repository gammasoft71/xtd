#include "../../../include/xtd/forms/application.hpp"
#include "../../../include/xtd/forms/horizontal_control_layout_style.hpp"

using namespace xtd;
using namespace xtd::forms;

horizontal_control_layout_style::horizontal_control_layout_style(float width) : width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width) : width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type) : control_layout_style(size_type) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type) : control_layout_style(size_type), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(bool expanded) : control_layout_style(expanded) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, bool expanded) : control_layout_style(expanded), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, bool expanded) : control_layout_style(expanded), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::content_alignment align) : control_layout_style(align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::content_alignment align) : control_layout_style(align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, xtd::forms::content_alignment align) : control_layout_style(align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, bool expanded) : control_layout_style(size_type, expanded), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, xtd::forms::content_alignment align) : control_layout_style(size_type, align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, xtd::forms::size_type size_type, bool expanded, xtd::forms::content_alignment align) : control_layout_style(size_type, expanded, align), width_(static_cast<float>(width)) {
}

horizontal_control_layout_style::horizontal_control_layout_style(bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align) {
}

horizontal_control_layout_style::horizontal_control_layout_style(float width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(width) {
}

horizontal_control_layout_style::horizontal_control_layout_style(int32 width, bool expanded, xtd::forms::content_alignment align) : control_layout_style(expanded, align), width_(static_cast<float>(width)) {
}

auto horizontal_control_layout_style::width() const noexcept -> std::optional<float> {
  return width_;
}

auto horizontal_control_layout_style::width(float width) -> horizontal_control_layout_style& {
  width_ = width;
  return *this;
}

auto horizontal_control_layout_style::equals(const horizontal_control_layout_style& other) const noexcept -> bool {
  return width_ == other.width_ && as<control_layout_style>(*this).equals(as<control_layout_style>(other));
}

auto horizontal_control_layout_style::get_hash_code() const noexcept -> usize {
  return hash_code::combine(width_, as<control_layout_style>(*this).get_hash_code());
}

auto horizontal_control_layout_style::to_string() const noexcept -> string {
  return string::format("horizontal_control_layout_style=[expanded={}, align={}, size_type={}, width={}]", expanded(), align(), size_type(), width_.value_or(-1));
}
