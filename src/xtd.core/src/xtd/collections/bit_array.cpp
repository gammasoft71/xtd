#include "../../../include/xtd/collections/bit_array.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
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

bit_array::bit_array(size length) noexcept {
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
}

bit_array::bit_array(size length, bool default_value) noexcept {
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(default_value ? 0xFFFFFFFFL : 0);
  if (!default_value) return;
  auto extra_bits = length & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  if (extra_bits > 0) bit_array_[bit_array_.size() - 1] = static_cast<int32>(1 << extra_bits) - 1;
}

bit_array::bit_array(std::initializer_list<bool> il) noexcept {
  length_ = il.size();
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  auto index = 0_z;
  for (auto item : il)
    set_bit_value(index++, item);
}

bit_array::bit_array(const array<bool>& values) noexcept {
  length_ = values.length();
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    set(index, values[index]);
}

bit_array::bit_array(const array<byte>& values) noexcept {
  length_ = values.length() * bits_per_byte;
  auto position = 0_z;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    for (auto index_bits = 0_z; index_bits < bits_per_byte; ++index_bits)
      set(position++, (values[index] & (1 << index_bits)) == (1 << index_bits));
}

bit_array::bit_array(const array<int32>& values) noexcept {
  length_ = values.length() * bits_per_int32;
  auto position = 0_z;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
  for (auto index = 0_z; index < values.length(); ++index)
    for (auto index_bits = 0_z; index_bits < bits_per_int32; ++index_bits)
      set(position++, (values[index] & (1 << index_bits)) == (1 << index_bits));
}

bit_array::bit_array(const std::vector<bool>& booleans) noexcept : bit_array(booleans.size()) {
  for (auto index = 0_z; index < booleans.size(); ++index)
    set(index, booleans[index]);
}

size bit_array::count() const noexcept {
  flush(); // Must be call first
  return length_;
}

size bit_array::length() const noexcept {
  flush(); // Must be call first
  return length_;
}

void bit_array::length(xtd::size value) {
  flush(); // Must be call first
  length_ = value;
  bit_array_.resize(bits_per_int32 / bits_per_int32 + (bits_per_int32 % bits_per_int32 ? 1 : 0), 0);
}

bool bit_array::is_read_only() const noexcept {
  flush(); // Must be call first
  return bit_array_.is_read_only();
}

bool bit_array::is_synchronized() const noexcept {
  flush(); // Must be call first
  return bit_array_.is_synchronized();
}

const object& bit_array::sync_root() const noexcept {
  flush(); // Must be call first
  return bit_array_.sync_root();
}

const bit_array& bit_array::and_(const bit_array& value) {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) && value[index]);
  return *this;
}

bool bit_array::at(size index) const {
  return operator [](index);
}

bool& bit_array::at(size index) {
  return operator [](index);
}

uptr<object> bit_array::clone() const {
  flush(); // Must be call first
  return new_uptr<bit_array>(*this);
}


void bit_array::copy_to(array<bool>& array, size index) const {
  flush(); // Must be call first
  if (index + length() > array.length()) throw_helper::throws(exception_case::argument);
  for (auto item : *this)
    array[index++] = item;
}

bool bit_array::equals(const bit_array& value) const noexcept {
  flush(); // Must be call first
  if (length() != value.length()) return false;
  for (auto index = 0_z; index < length(); ++index)
    if (get(index) != value.get(index)) return false;
  return true;
}

bool bit_array::equals(const object& obj) const noexcept {
  flush(); // Must be call first
  return is<bit_array>(obj) && equals(static_cast<const bit_array&>(obj));
}

bool bit_array::get(size index) const {
  return operator [](index);
}

bool& bit_array::get(size index) {
  return operator [](index);
}

generic::enumerator<bool> bit_array::get_enumerator() const {
  class enumerator : public object, public generic::ienumerator<bool> {
  public:
    enumerator(bit_array* bit_array) : bit_array_(bit_array) {}
    bool move_next() override {return ++pos_ < bit_array_->length();}
    
    void reset() override {pos_ = npos;}
    const bool& current() const override {
      if (pos_ == npos || pos_ >= bit_array_->length()) throw_helper::throws(exception_case::invalid_operation);
      return (*bit_array_)[pos_];
    }
    
  private:
    size npos = std::numeric_limits<size>::max();
    size pos_ = npos;
    bit_array* bit_array_ = null;
  };
  flush(); // Must be call first
  return generic::enumerator<bool>(new_ptr<enumerator>(const_cast<bit_array*>(this)));
}

bool bit_array::has_all_set() const noexcept {
  flush(); // Must be call first
  auto extra_bits = length_ & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  auto int_count = get_int32_array_length_from_bit_length(length_);
  if (extra_bits) --int_count;
  
  constexpr int32 all_set_bits = -1; // 0xFFFFFFFF
  for (auto index = 0_z; index < int_count; ++index)
    if (bit_array_[index] != all_set_bits) return false;
  
  if (!extra_bits) return true;
  
  auto mask = static_cast<int32>(1 << extra_bits) - 1;
  return (bit_array_[int_count] & mask) == mask;
}

bool bit_array::has_any_set() const noexcept {
  flush(); // Must be call first
  auto extra_bits = length_ & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  auto int_count = get_int32_array_length_from_bit_length(length_);
  if (extra_bits) int_count--;

  for (auto index = 0_z; index < int_count; ++index)
    if (bit_array_[index] != 0) return true;
  
  if (!extra_bits) return false;
  
  return ((bit_array_[int_count] & (1 << extra_bits)) - 1) != 0;
}

bit_array& bit_array::left_shift(xtd::size count) noexcept {
  return *this <<= count;
}

const bit_array& bit_array::not_() {
  flush(); // Must be call first
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, !get_bit_value(index));
  return *this;
}

const bit_array& bit_array::or_(const bit_array& value) {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) || value[index]);
  return *this;
}

bit_array& bit_array::right_shift(xtd::size count) noexcept {
  return *this >>= count;
}

void bit_array::set(size index, bool value) {
  flush(); // Must be call first
  if (index >= length()) throw_helper::throws(exception_case::argument_out_of_range);
  set_bit_value(index, value);
}

void bit_array::set_all(bool value) {
  flush(); // Must be call first
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, value);
}

string bit_array::to_string() const noexcept {
  flush(); // Must be call first
  return string::format( "[{}]", string::join(", ", *this));
}

const bit_array& bit_array::xor_(const bit_array& value) {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) != value[index]);
  return *this;
}

const bool& bit_array::operator [](size index) const {
  flush(); // Must be call first
  if (index >= length_) throw_helper::throws(exception_case::argument_out_of_range);
  return value_ref_.get_boolean_ref(get_bit_value(index), index);
}

bool& bit_array::operator [](size index) {
  flush(); // Must be call first
  if (index >= length()) throw_helper::throws(exception_case::argument_out_of_range);
  return value_ref_.get_boolean_ref(get_bit_value(index), index);
}

bit_array bit_array::operator >>(xtd::size pos) const noexcept {
  flush(); // Must be call first
  auto result = bit_array(count());
  for (auto index = count() - 1; index > 0; --index)
    result[index] = index >= pos ? at(index - pos) : false;
  result.flush(); // Must be call first
  return result;
}

bit_array& bit_array::operator >>=(xtd::size pos) noexcept {
  *this = *this >> pos;
  return *this;
}

bit_array bit_array::operator <<(xtd::size pos) const noexcept {
  flush(); // Must be call first
  auto result = bit_array(count());
  for (auto index = xtd::size {0}; index < count(); ++index)
    result[index] = index + pos < count() ? at(index + pos) : false;
  result.flush(); // Must be call first
  return result;
}

bit_array& bit_array::operator <<=(xtd::size pos) noexcept {
  *this = *this << pos;
  return *this;
}

void bit_array::add(const bool& value) {
  flush(); // Must be call first
  length(length() + 1);
  set_bit_value(length() - 1, value);
}

void bit_array::clear() {
  flush(); // Must be call first
  length(0);
}

bool bit_array::contains(const bool& value) const noexcept {
  flush(); // Must be call first
  for (auto bit : *this)
    if (bit == value) return true;
  return false;
}

bool bit_array::remove(const bool&) {
  flush(); // Must be call first
  return false;
}

void bit_array::flush() const noexcept {
  value_ref_.from_boolean(const_cast<bit_array&>(*this));
}

size bit_array::get_int32_array_length_from_bit_length(size n) const noexcept {
  return (n - 1 + (1 << bit_shift_per_int32)) >> bit_shift_per_int32;
}

size bit_array::get_list_position(size index) const noexcept {
  return index / bits_per_int32;
}

size bit_array::get_bit_position(size index) const noexcept {
  return index % bits_per_int32;
}

size bit_array::get_list_length(size length_) const noexcept {
  return get_list_position(length_) + (get_bit_position(length_) ? 1 : 0);
}

bool bit_array::get_bit_value(size index) const noexcept {
  return (bit_array_[get_list_position(index)] & (1 << get_bit_position(index))) == (1 << get_bit_position(index));
}

void bit_array::set_bit_value(size index, bool value) noexcept {
  if (value) bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] | (1 << (get_bit_position(index)));
  else bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] & ~(1 << (get_bit_position(index)));
}
