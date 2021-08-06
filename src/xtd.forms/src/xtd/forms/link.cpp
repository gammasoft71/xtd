#include "../../../include/xtd/forms/link.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

link::link(size_t start, size_t length) : length_(length), start_(start) {
}

link::link(size_t start, size_t length, std::any link_data) : length_(length), link_data_(link_data), start_(start) {
}

const xtd::ustring& link::description() const {
  return description_;
}

link& link::description(const xtd::ustring& value) {
  description_ = value;
  return *this;
}

bool link::enabled() const {
  return enabled_;
}

link& link::enabled(bool value) {
  enabled_ = value;
  return *this;
}

size_t link::length() const {
  return length_;
}

link& length(size_t value);

std::any link::link_data() const {
  return link_data_;
}

link& link::link_data(std::any value) {
  link_data_ = value;
  return *this;
}

const xtd::ustring& link::name() const {
  return name_;
}

link& link::name(const xtd::ustring& value) {
  name_ = value;
  return *this;
}

size_t link::start() const {
  return start_;
}

link& link::start(size_t value) {
  start_ = value;
  return *this;
}

std::any link::tag() const {
  return tag_;
}

link& link::tag(std::any value) {
  tag_ = value;
  return *this;
}

bool link::visited() const {
  return visited_;
}

link& link::visited(bool value) {
  visited_ = value;
  return *this;
}
