#include "../../../include/xtd/forms/link.h"

using namespace std;
using namespace xtd;

xtd::forms::link::link(size_t start, size_t length) : length_(length), start_(start) {
}

xtd::forms::link::link(size_t start, size_t length, std::any link_data) : length_(length), link_data_(link_data), start_(start) {
}

const xtd::ustring& xtd::forms::link::description() const {
  return description_;
}

xtd::forms::link& xtd::forms::link::description(const xtd::ustring& value) {
  description_ = value;
  return *this;
}

bool xtd::forms::link::enabled() const {
  return enabled_;
}

xtd::forms::link& xtd::forms::link::enabled(bool value) {
  enabled_ = value;
  return *this;
}

size_t xtd::forms::link::length() const {
  return length_;
}

xtd::forms::link& xtd::forms::link::length(size_t value) {
  length_ = value;
  return *this;
}

std::any xtd::forms::link::link_data() const {
  return link_data_;
}

xtd::forms::link& xtd::forms::link::link_data(std::any value) {
  link_data_ = value;
  return *this;
}

const xtd::ustring& xtd::forms::link::name() const {
  return name_;
}

xtd::forms::link& xtd::forms::link::name(const xtd::ustring& value) {
  name_ = value;
  return *this;
}

size_t xtd::forms::link::start() const {
  return start_;
}

xtd::forms::link& xtd::forms::link::start(size_t value) {
  start_ = value;
  return *this;
}

std::any xtd::forms::link::tag() const {
  return tag_;
}

xtd::forms::link& xtd::forms::link::tag(std::any value) {
  tag_ = value;
  return *this;
}

bool xtd::forms::link::visited() const {
  return visited_;
}

xtd::forms::link& xtd::forms::link::visited(bool value) {
  visited_ = value;
  return *this;
}
