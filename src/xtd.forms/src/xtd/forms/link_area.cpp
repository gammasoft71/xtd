#include "../../../include/xtd/forms/link_area.hpp"

using namespace xtd;
using namespace xtd::forms;

link_area::link_area(xtd::usize start, xtd::usize length) noexcept : start_(start), length_(length) {
}

bool link_area::is_empty() const noexcept {
  return start_ == 0 && length_ == 0;
}

xtd::usize link_area::length() const noexcept {
  return length_;
}

link_area& link_area::length(xtd::usize value) noexcept {
  length_ = value;
  return *this;
}

xtd::usize link_area::start() const noexcept {
  return start_;
}

link_area& link_area::start(xtd::usize value) noexcept {
  start_ = value;
  return *this;
}

bool link_area::equals(const object& obj) const noexcept {
  return is<link_area>(obj) && equals(static_cast<const link_area&>(obj));
}

bool link_area::equals(const link_area& other) const noexcept {
  return start_ == other.start_ && length_ == other.length_;
}

usize link_area::get_hash_code() const noexcept {
  return hash_code::combine(start_, length_);
}

string link_area::to_string() const noexcept {
  return string::format("{{start={}, length={}}}", start_, length_);
}
