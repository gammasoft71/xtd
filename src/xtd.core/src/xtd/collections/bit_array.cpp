#include "../../../include/xtd/collections/bit_array.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"

using namespace xtd;
using namespace xtd::collections;

bool& bit_array::boolean_ref::get_boolean_ref(bool v, size i) noexcept {
  index = i;
  value = v;
  return value;
}

const bool& bit_array::boolean_ref::get_boolean_ref(bool v, size i) const noexcept {
  index = i;
  value = v;
  return value;
}

void bit_array::boolean_ref::from_boolean(bit_array& parent) noexcept {
  if (index != npos) parent.set_bit_value(index, value);
  index = npos;
}

bit_array::bit_array(const array<byte>& values) {
  length_ = values.length() * bits_per_byte;
  auto position = 0_z;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    for (auto index_bits = 0_z; index_bits < bits_per_byte; ++index_bits)
      set(position++, (values[index] & (1 << index_bits)) == (1 << index_bits));
}

bit_array::bit_array(const array<bool>& values) {
  length_ = values.length();
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    set(index, values[index]);
}

bit_array::bit_array(const array<int32>& values) {
  length_ = values.length() * bits_per_int32;
  auto position = 0_z;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    for (auto index_bits = 0_z; index_bits < bits_per_int32; ++index_bits)
      set(position++, (values[index] & (1 << index_bits)) == (1 << index_bits));
}

bit_array::bit_array(size length) {
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
}

bit_array::bit_array(size length, bool default_value) {
  if (length_ < 0) throw argument_out_of_range_exception {};
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(default_value ? 0xFFFFFFFFL : 0);
  auto extra_bits = length & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  if (extra_bits > 0) bit_array_[bit_array_.size() - 1] = (1 << extra_bits) - 1;
}

bit_array::bit_array(std::initializer_list<bool> il) {
  length_ = il.size();
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  auto index = 0_z;
  for (auto item : il)
    set(index++, item);
}

size bit_array::count() const noexcept {
  return length_;
}

size bit_array::length() const noexcept {
  return length_;
}

void bit_array::length(xtd::size value) {
  length_ = value;
  bit_array_.resize(bits_per_int32 / bits_per_int32 + (bits_per_int32 % bits_per_int32 ? 1 : 0), 0);
}

bool bit_array::is_read_only() const noexcept {
  return bit_array_.is_read_only();
}

bool bit_array::is_synchronized() const noexcept {
  return bit_array_.is_synchronized();
}

const object& bit_array::sync_root() const noexcept {
  return bit_array_.sync_root();
}

const bit_array& bit_array::and_(const bit_array& value) {
  if (count() != value.count()) throw argument_exception {};
  for (auto index = 0_z; index < length(); ++index)
    (*this)[index] = (*this)[index] && value[index];
  return *this;
}

uptr<object> bit_array::clone() const {
  return new_uptr<bit_array>(*this);
}


void bit_array::copy_to(array<bool>& array, size index) const {
  if (index + length() > array.length()) throw argument_exception {};
  for (auto item : *this)
    array[++index] = item;
}

bool bit_array::equals(const bit_array& value) const noexcept {
  if (length() != value.length()) return false;
  for (auto index = 0_z; index < length(); ++index)
    if (get(index) != value.get(index)) return false;
  return true;
}

bool bit_array::equals(const object& obj) const noexcept {
  return is<bit_array>(obj) && equals(static_cast<const bit_array&>(obj));
}

bool bit_array::get(size index) const {
  if (index >= length_) throw argument_out_of_range_exception {};
  const_cast<boolean_ref&>(value_ref_).from_boolean(const_cast<bit_array&>(*this));
  return const_cast<boolean_ref&>(value_ref_).get_boolean_ref(get_bit_value(index), index);
}

bool& bit_array::get(size index) {
  if (index >= length_) throw argument_out_of_range_exception {};
  value_ref_.from_boolean(*this);
  return value_ref_.get_boolean_ref(get_bit_value(index), index);
}

generic::enumerator<bool> bit_array::get_enumerator() const {
  class enumerator : public object, public generic::ienumerator<bool> {
  public:
    enumerator(bit_array* bit_array) : bit_array_(bit_array) {}
    bool move_next() override {return ++pos_ < bit_array_->length();}
    
    void reset() override {pos_ = npos;}
    const bool& current() const override {
      if (pos_ == npos || pos_ >= bit_array_->length()) throw invalid_operation_exception {};
      return (*bit_array_)[pos_];
    }
    
  private:
    size npos = std::numeric_limits<size>::max();
    size pos_ = npos;
    bit_array* bit_array_ = null;
  };
  
  return generic::enumerator<bool>(new_ptr<enumerator>(const_cast<bit_array*>(this)));
}

const bit_array& bit_array::not_() {
  for (auto index = 0_z; index < length(); ++index)
    (*this)[index] = !((*this)[index]);
  return *this;
}

const bit_array& bit_array::or_(const bit_array& value) {
  if (count() != value.count()) throw argument_exception {};
  for (auto index = 0_z; index < length(); ++index)
    (*this)[index] = (*this)[index] || value[index];
  return *this;
}

void bit_array::set(size index, bool value) {
  (*this)[index] = value;
}

void bit_array::set_all(bool value) {
  for (auto index = 0_z; index < length(); ++index)
    (*this)[index] = value;
}

string bit_array::to_string() const noexcept {
  return string::format( "[{}]", string::join(", ", *this));
}

const bit_array& bit_array::xor_(const bit_array& value) {
  if (count() != value.count()) throw argument_exception {};
  for (auto index = 0_z; index < length(); ++index)
    (*this)[index] = (*this)[index] ^ value[index];
  return *this;
}

const bool& bit_array::operator[](size index) const {
  if (index >= length_) throw argument_out_of_range_exception {};
  const_cast<boolean_ref&>(value_ref_).from_boolean(const_cast<bit_array&>(*this));
  return value_ref_.get_boolean_ref(get_bit_value(index), index);
}

bool& bit_array::operator[](size index) {
  if (index >= length()) throw argument_out_of_range_exception {};
  value_ref_.from_boolean(*this);
  return value_ref_.get_boolean_ref(get_bit_value(index), index);
}

void bit_array::add(const bool&) {
}

void bit_array::clear() {
}

bool bit_array::contains(const bool&) const noexcept {
  return false;
}

bool bit_array::remove(const bool&) {
  return false;
}

inline size bit_array::get_list_position(size index) const noexcept {
  return index / bits_per_int32;
}

inline size bit_array::get_bit_position(size index) const noexcept {
  return index % bits_per_int32;
}

inline size bit_array::get_list_length(size length_) const noexcept {
  return get_list_position(length_) + (get_bit_position(length_) ? 1 : 0);
}

bool bit_array::get_bit_value(size index) const noexcept {
  return (bit_array_[get_list_position(index)] & (1 << get_bit_position(index))) == (1 << get_bit_position(index));
}

void bit_array::set_bit_value(size index, bool value) noexcept {
  if (value) bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] | (1 << (get_bit_position(index)));
  else bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] & ~(1 << (get_bit_position(index)));
}
