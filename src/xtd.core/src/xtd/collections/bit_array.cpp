#include "../../../include/xtd/as_const.hpp"
#include "../../../include/xtd/collections/bit_array.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::collections;

auto bit_array::boolean_ref::get_boolean_ref(bool v, xtd::size i) noexcept -> bool& {
  index = i;
  value = v;
  return value;
}

auto bit_array::boolean_ref::get_boolean_ref(bool v, xtd::size i) const noexcept -> const bool& {
  index = i;
  value = v;
  return value;
}

auto bit_array::boolean_ref::from_boolean(bit_array& parent) noexcept -> void {
  if (index != npos) parent.set_bit_value(index, value);
  index = npos;
}

bit_array::bit_array(xtd::size length) noexcept {
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(0);
}

bit_array::bit_array(xtd::size length, bool default_value) noexcept {
  length_ = length;
  while (bit_array_.count() < get_list_length(length_))
    bit_array_.add(default_value ? 0xFFFFFFFFL : 0);
  if (!default_value) return;
  auto extra_bits = length & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  if (extra_bits > 0) bit_array_[bit_array_.count() - 1] = static_cast<int32>(1 << extra_bits) - 1;
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

auto bit_array::count() const noexcept -> xtd::size {
  flush(); // Must be call first
  return length_;
}

auto bit_array::length() const noexcept -> xtd::size {
  flush(); // Must be call first
  return length_;
}

auto bit_array::length(xtd::size value) -> void {
  flush(); // Must be call first
  length_ = value;
  bit_array_.items().resize(bits_per_int32 / bits_per_int32 + (bits_per_int32 % bits_per_int32 ? 1 : 0), 0);
}

auto bit_array::and_(const bit_array& value) -> const bit_array& {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) && value[index]);
  return *this;
}

auto bit_array::clone() const -> uptr<object> {
  flush(); // Must be call first
  return new_uptr<bit_array>(*this);
}


auto bit_array::copy_to(array<bool>& array, xtd::size index) const -> void {
  flush(); // Must be call first
  if (index + length() > array.length()) throw_helper::throws(exception_case::argument);
  for (auto item : *this)
    array[index++] = item;
}

auto bit_array::equals(const bit_array& value) const noexcept -> bool {
  flush(); // Must be call first
  if (length() != value.length()) return false;
  for (auto index = 0_z; index < length(); ++index)
    if (get(index) != value.get(index)) return false;
  return true;
}

auto bit_array::equals(const object& obj) const noexcept -> bool {
  flush(); // Must be call first
  return is<bit_array>(obj) && equals(static_cast<const bit_array&>(obj));
}

auto bit_array::get(xtd::size index) const -> bool {
  return operator [](index);
}

auto bit_array::get(xtd::size index) -> bool& {
  return operator [](index);
}

auto bit_array::get_enumerator() const -> generic::enumerator<bool> {
  struct bit_array_enumerator : public object, public generic::ienumerator<bool> {
    explicit bit_array_enumerator(const bit_array& items) : items_(items) {}
    
    const bool& current() const override {
      if (index_ >= items_.length()) throw_helper::throws(exception_case::invalid_operation);
      return items_[index_];
    }
    
    bool move_next() override {return ++index_ < items_.length();}
    void reset() override {index_ = npos;}
    
  private:
    xtd::size index_ = npos;
    const bit_array& items_;
  };
  flush(); // Must be call first
  return {new_ptr<bit_array_enumerator>(self_)};
}

auto bit_array::has_all_set() const noexcept -> bool {
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

auto bit_array::has_any_set() const noexcept -> bool {
  flush(); // Must be call first
  auto extra_bits = length_ & (32 - 1); // equivalent to length % 32, since 32 is a power of 2
  auto int_count = get_int32_array_length_from_bit_length(length_);
  if (extra_bits) int_count--;
  
  for (auto index = 0_z; index < int_count; ++index)
    if (bit_array_[index] != 0) return true;
    
  if (!extra_bits) return false;
  
  return ((bit_array_[int_count] & (1 << extra_bits)) - 1) != 0;
}

auto bit_array::left_shift(xtd::size count) noexcept -> bit_array& {
  return *this <<= count;
}

auto bit_array::not_() -> const bit_array& {
  flush(); // Must be call first
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, !get_bit_value(index));
  return *this;
}

auto bit_array::or_(const bit_array& value) -> const bit_array& {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) || value[index]);
  return *this;
}

auto bit_array::right_shift(xtd::size count) noexcept -> bit_array& {
  return *this >>= count;
}

auto bit_array::set(xtd::size index, bool value) -> void {
  flush(); // Must be call first
  if (index >= length()) throw_helper::throws(exception_case::argument_out_of_range);
  set_bit_value(index, value);
}

auto bit_array::set_all(bool value) -> void {
  flush(); // Must be call first
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, value);
}

auto bit_array::to_string() const noexcept -> string {
  flush(); // Must be call first
  return string::format("[{}]", string::join(", ", *this));
}

auto bit_array::xor_(const bit_array& value) -> const bit_array& {
  flush(); // Must be call first
  if (count() != value.count()) throw_helper::throws(exception_case::argument);
  for (auto index = 0_z; index < length(); ++index)
    set_bit_value(index, get_bit_value(index) != value[index]);
  return *this;
}

auto bit_array::operator [](xtd::size index) const -> const bool& {
  flush(); // Must be call first
  if (index >= length() && index != epos) throw_helper::throws(exception_case::argument_out_of_range);
  auto idx = index == epos ? length() - 1 : index;
  return value_ref_.get_boolean_ref(get_bit_value(idx), idx);
}

auto bit_array::operator [](xtd::size index) -> bool& {
  flush(); // Must be call first
  if (index >= length() && index != epos) throw_helper::throws(exception_case::argument_out_of_range);
  auto idx = index == epos ? length() - 1 : index;
  return value_ref_.get_boolean_ref(get_bit_value(idx), idx);
}

auto bit_array::operator &(const bit_array& value) const -> bit_array {
  flush(); // Must be call first
  auto result = self_;
  result &= value;
  return result;
}

auto bit_array::operator &=(const bit_array& value) -> bit_array& {
  and_(value);
  return self_;
}

auto bit_array::operator |(const bit_array& value) const -> bit_array {
  flush(); // Must be call first
  auto result = self_;
  result |= value;
  return result;
}

auto bit_array::operator |=(const bit_array& value) -> bit_array& {
  or_(value);
  return self_;
}

auto bit_array::operator ^(const bit_array& value) const -> bit_array {
  flush(); // Must be call first
  auto result = self_;
  result ^= value;
  return result;
}

auto bit_array::operator ^=(const bit_array& value) -> bit_array& {
  xor_(value);
  return self_;
}

auto bit_array::operator ~() const -> bit_array {
  flush(); // Must be call first
  auto result = self_;
  result.not_();
  return result;
}

auto bit_array::operator >>(xtd::size pos) const noexcept -> bit_array {
  flush(); // Must be call first
  auto result = bit_array(count());
  for (auto index = count() - 1; index > 0; --index)
    result[index] = index >= pos ? self_[index - pos] : false;
  result.flush();
  return result;
}

auto bit_array::operator >>=(xtd::size pos) noexcept -> bit_array& {
  *this = as_const(*this) >> pos;
  return *this;
}

auto bit_array::operator <<(xtd::size pos) const noexcept -> bit_array {
  flush(); // Must be call first
  auto result = bit_array(count());
  for (auto index = xtd::size {0}; index < count(); ++index)
    result[index] = index + pos < count() ? self_[index + pos] : false;
  result.flush();
  return result;
}

auto bit_array::operator <<=(xtd::size pos) noexcept -> bit_array& {
  *this = as_const(*this) << pos;
  return *this;
}

auto bit_array::is_read_only() const noexcept -> bool {
  flush(); // Must be call first
  return as<icollection<int32>>(bit_array_).is_read_only();
}

auto bit_array::is_synchronized() const noexcept -> bool {
  flush(); // Must be call first
  return as<icollection<int32>>(bit_array_).is_synchronized();
}

auto bit_array::sync_root() const noexcept -> const object& {
  flush(); // Must be call first
  return as<icollection<int32>>(bit_array_).sync_root();
}

auto bit_array::add(const bool& value) -> void {
  flush(); // Must be call first
  length(length() + 1);
  set_bit_value(length() - 1, value);
}

auto bit_array::clear() -> void {
  flush(); // Must be call first
  length(0);
}

auto bit_array::contains(const bool& value) const noexcept -> bool {
  flush(); // Must be call first
  for (auto bit : *this)
    if (bit == value) return true;
  return false;
}

auto bit_array::remove(const bool&) -> bool {
  flush(); // Must be call first
  return false;
}

auto bit_array::flush() const noexcept -> void {
  value_ref_.from_boolean(const_cast<bit_array&>(*this));
}

auto bit_array::get_int32_array_length_from_bit_length(xtd::size n) const noexcept -> xtd::size {
  return (n - 1 + (1 << bit_shift_per_int32)) >> bit_shift_per_int32;
}

auto bit_array::get_list_position(xtd::size index) const noexcept -> xtd::size {
  return index / bits_per_int32;
}

auto bit_array::get_bit_position(xtd::size index) const noexcept -> xtd::size {
  return index % bits_per_int32;
}

auto bit_array::get_list_length(xtd::size length_) const noexcept -> xtd::size {
  return get_list_position(length_) + (get_bit_position(length_) ? 1 : 0);
}

auto bit_array::get_bit_value(xtd::size index) const noexcept -> bool {
  return (bit_array_[get_list_position(index)] & (1 << get_bit_position(index))) == (1 << get_bit_position(index));
}

auto bit_array::set_bit_value(xtd::size index, bool value) noexcept -> void {
  if (value) bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] | (1 << (get_bit_position(index)));
  else bit_array_[get_list_position(index)] = bit_array_[get_list_position(index)] & ~(1 << (get_bit_position(index)));
}
