#include "../../../include/xtd/forms/link.h"

using namespace std;
using namespace xtd;

struct xtd::forms::link::data {
  xtd::ustring description;
  bool enabled = true;
  size_t length = 0;
  std::any link_data;
  xtd::ustring name;
  size_t start = 0;
  std::any tag;
  bool visited = false;
  bool active = false;
};

xtd::forms::link::link() : data_(std::make_shared<data>()) {
}

xtd::forms::link::link(size_t start, size_t length) : data_(std::make_shared<data>()) {
  data_->length = length;
  data_->start = start;
}

xtd::forms::link::link(size_t start, size_t length, std::any link_data) : data_(std::make_shared<data>()) {
  data_->length = length;
  data_->link_data = link_data;
  data_->start = start;
}

xtd::forms::link::link(const link& value) : data_(std::make_shared<data>()) {
  *data_ = *value.data_;
}

xtd::forms::link& xtd::forms::link::operator =(const link& value) {
  *data_ = *value.data_;
  return *this;
}

const xtd::ustring& xtd::forms::link::description() const noexcept {
  return data_->description;
}

xtd::forms::link& xtd::forms::link::description(const xtd::ustring& value) {
  data_->description = value;
  return *this;
}

bool xtd::forms::link::enabled() const noexcept {
  return data_->enabled;
}

xtd::forms::link& xtd::forms::link::enabled(bool value) {
  data_->enabled = value;
  return *this;
}

size_t xtd::forms::link::length() const noexcept {
  return data_->length;
}

xtd::forms::link& xtd::forms::link::length(size_t value) {
  data_->length = value;
  return *this;
}

std::any xtd::forms::link::link_data() const noexcept {
  return data_->link_data;
}

xtd::forms::link& xtd::forms::link::link_data(std::any value) {
  data_->link_data = value;
  return *this;
}

const xtd::ustring& xtd::forms::link::name() const noexcept {
  return data_->name;
}

xtd::forms::link& xtd::forms::link::name(const xtd::ustring& value) {
  data_->name = value;
  return *this;
}

size_t xtd::forms::link::start() const noexcept {
  return data_->start;
}

xtd::forms::link& xtd::forms::link::start(size_t value) {
  data_->start = value;
  return *this;
}

std::any xtd::forms::link::tag() const noexcept {
  return data_->tag;
}

xtd::forms::link& xtd::forms::link::tag(std::any value) {
  data_->tag = value;
  return *this;
}

bool xtd::forms::link::visited() const noexcept {
  return data_->visited;
}

xtd::forms::link& xtd::forms::link::visited(bool value) {
  data_->visited = value;
  return *this;
}

bool xtd::forms::link::equals(const xtd::forms::link& other) const noexcept {
  return data_->enabled == other.data_->enabled && data_->length == other.data_->length && data_->name == other.data_->name && data_->start == other.data_->start;
}

bool xtd::forms::link::active_() const noexcept {
  return data_->active;
}


void xtd::forms::link::active_(bool active) noexcept {
  data_->active = active;
}
