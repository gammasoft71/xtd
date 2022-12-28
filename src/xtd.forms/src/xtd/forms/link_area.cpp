#include "../../../include/xtd/forms/link_area.h"

using namespace xtd;
using namespace xtd::forms;

link_area::link_area(size_t start, size_t length) noexcept : start_(start), length_(length) {
}

bool link_area::is_empty() const noexcept {
  return start_ == 0 && length_ == 0;
}

size_t link_area::length() const noexcept {
  return length_;
}

link_area& link_area::length(size_t value) noexcept {
  length_ = value;
  return *this;
}

size_t link_area::start() const noexcept {
  return start_;
}

link_area& link_area::start(size_t value) noexcept {
  start_ = value;
  return *this;
}

bool link_area::equals(const link_area& other) const noexcept {
  return start_ == other.start_ && length_ == other.length_;
}

xtd::ustring link_area::to_string() const noexcept {
  return ustring::format("{{start={}, length={}}}", start_, length_);
}
