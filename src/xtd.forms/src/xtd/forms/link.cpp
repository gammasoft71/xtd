#include "../../../include/xtd/forms/link.hpp"

using namespace xtd;
using namespace xtd::forms;

struct forms::link::data {
  string description;
  bool enabled = true;
  size_t length = 0;
  any_object link_data;
  string name;
  size_t start = 0;
  any_object tag;
  bool visited = false;
  bool active = false;
};

forms::link::link() : data_(xtd::new_sptr<data>()) {
}

forms::link::link(size_t start, size_t length) : data_(xtd::new_sptr<data>()) {
  data_->length = length;
  data_->start = start;
}

forms::link::link(size_t start, size_t length, const any_object& link_data) : data_(xtd::new_sptr<data>()) {
  data_->length = length;
  data_->link_data = link_data;
  data_->start = start;
}

forms::link::link(const link& value) : data_(xtd::new_sptr<data>()) {
  *data_ = *value.data_;
}

forms::link& forms::link::operator =(const link& value) {
  *data_ = *value.data_;
  return *this;
}

const xtd::string& forms::link::description() const noexcept {
  return data_->description;
}

forms::link& forms::link::description(const xtd::string& value) {
  data_->description = value;
  return *this;
}

bool forms::link::enabled() const noexcept {
  return data_->enabled;
}

forms::link& forms::link::enabled(bool value) {
  data_->enabled = value;
  return *this;
}

size_t forms::link::length() const noexcept {
  return data_->length;
}

forms::link& forms::link::length(size_t value) {
  data_->length = value;
  return *this;
}

const any_object& forms::link::link_data() const noexcept {
  return data_->link_data;
}

forms::link& forms::link::link_data(const any_object& value) {
  data_->link_data = value;
  return *this;
}

const xtd::string& forms::link::name() const noexcept {
  return data_->name;
}

forms::link& forms::link::name(const xtd::string& value) {
  data_->name = value;
  return *this;
}

size_t forms::link::start() const noexcept {
  return data_->start;
}

forms::link& forms::link::start(size_t value) {
  data_->start = value;
  return *this;
}

const any_object& forms::link::tag() const noexcept {
  return data_->tag;
}

forms::link& forms::link::tag(const any_object& value) {
  data_->tag = value;
  return *this;
}

bool forms::link::visited() const noexcept {
  return data_->visited;
}

forms::link& forms::link::visited(bool value) {
  data_->visited = value;
  return *this;
}

bool forms::link::equals(const object& obj) const noexcept {
  return is<forms::link>(obj) && equals(static_cast<const forms::link&>(obj));
}

bool forms::link::equals(const forms::link& other) const noexcept {
  return data_->description == other.data_->description && data_->enabled == other.data_->enabled && data_->length == other.data_->length && /*data_->link_data == other.data_->link_data &&*/ data_->name == other.data_->name && data_->start == other.data_->start;
}

xtd::size forms::link::get_hash_code() const noexcept {
  return hash_code::combine(data_->description, data_->enabled, data_->length, /*data_->link_data,*/ data_->name, data_->start);
}

bool forms::link::active_() const noexcept {
  return data_->active;
}

void forms::link::active_(bool active) noexcept {
  data_->active = active;
}
