#include "../../../include/xtd/linq/enumerable.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::linq;

decimal enumerable::average(const ienumerable<decimal>& source) {
  auto average = .0l;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

double enumerable::average(const ienumerable<double>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

float enumerable::average(const ienumerable<float>& source) {
  auto average = .0f;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

double enumerable::average(const ienumerable<int32>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

double enumerable::average(const ienumerable<int64>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

optional<decimal> enumerable::average(const ienumerable<optional<decimal>>& source) noexcept {
  auto average = .0l;
  auto count = 0;
  for (auto item : source) {
    if (!item.has_value()) continue;
    average += item.value();
    ++count;
  }
  if (count == 0) return nullopt;
  return average / count;
}

optional<double> enumerable::average(const ienumerable<optional<double>>& source) noexcept {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item.has_value()) continue;
    average += item.value();
    ++count;
  }
  if (count == 0) return nullopt;
  return average / count;
}

optional<float> enumerable::average(const ienumerable<optional<float>>& source) noexcept {
  auto average = .0f;
  auto count = 0;
  for (auto item : source) {
    if (!item.has_value()) continue;
    average += item.value();
    ++count;
  }
  if (count == 0) return nullopt;
  return average / count;
}

optional<double> enumerable::average(const ienumerable<optional<int32>>& source) noexcept {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item.has_value()) continue;
    average += as<double>(item.value());
    ++count;
  }
  if (count == 0) return nullopt;
  return average / count;
}

optional<double> enumerable::average(const ienumerable<optional<int64>>& source) noexcept {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    if (!item.has_value()) continue;
    average += as<double>(item.value());
    ++count;
  }
  if (count == 0) return nullopt;
  return average / count;
}

const enumerable::ienumerable<sbyte>& enumerable::range(sbyte count) {
  return range(sbyte {0}, count, sbyte {1});
}

const enumerable::ienumerable<sbyte>& enumerable::range(sbyte start, sbyte count) {
  return range(start, static_cast<sbyte>(start + count), sbyte {1});
}

const enumerable::ienumerable<sbyte>& enumerable::range(sbyte start, sbyte stop, sbyte step) {
  if (stop < 0) throw_helper::throws(exception_case::argument_out_of_range);
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<sbyte> {};
  result = __opaque_xtd_linq_enumerable_collection__<sbyte> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<int16>& enumerable::range(int16 count) {
  return range(int16 {0}, count, int16 {1});
}

const enumerable::ienumerable<int16>& enumerable::range(int16 start, int16 count) {
  return range(start, static_cast<int16>(start + count), int16 {1});
}

const enumerable::ienumerable<int16>& enumerable::range(int16 start, int16 stop, int16 step) {
  if (stop < 0) throw_helper::throws(exception_case::argument_out_of_range);
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<int16> {};
  result = __opaque_xtd_linq_enumerable_collection__<int16> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<int32>& enumerable::range(int32 count) {
  return range(int32 {0}, count, int32 {1});
}

const enumerable::ienumerable<int32>& enumerable::range(int32 start, int32 count) {
  return range(start, static_cast<int32>(start + count), int32 {1});
}

const enumerable::ienumerable<int32>& enumerable::range(int32 start, int32 stop, int32 step) {
  if (stop < 0) throw_helper::throws(exception_case::argument_out_of_range);
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<int32> {};
  result = __opaque_xtd_linq_enumerable_collection__<int32> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<int64>& enumerable::range(int64 count) {
  return range(int64 {0}, count, int64 {1});
}

const enumerable::ienumerable<int64>& enumerable::range(int64 start, int64 count) {
  return range(start, static_cast<int64>(start + count), int64 {1});
}

const enumerable::ienumerable<int64>& enumerable::range(int64 start, int64 stop, int64 step) {
  if (stop < 0) throw_helper::throws(exception_case::argument_out_of_range);
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<int64> {};
  result = __opaque_xtd_linq_enumerable_collection__<int64> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

/*
const enumerable::ienumerable<slong>& enumerable::range(slong count) {
  return range(slong {0}, count, slong {1});
}

const enumerable::ienumerable<slong>& enumerable::range(slong start, slong count) {
  return range(start, static_cast<slong>(start + count), slong {1});
}

const enumerable::ienumerable<slong>& enumerable::range(slong start, slong stop, slong step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<slong> {};
  result = __opaque_xtd_linq_enumerable_collection__<slong> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}
 */

const enumerable::ienumerable<byte>& enumerable::range(byte count) {
  return range(byte {0}, count, byte {1});
}

const enumerable::ienumerable<byte>& enumerable::range(byte start, byte count) {
  return range(start, static_cast<byte>(start + count), byte {1});
}

const enumerable::ienumerable<byte>& enumerable::range(byte start, byte stop, byte step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<byte> {};
  result = __opaque_xtd_linq_enumerable_collection__<byte> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<uint16>& enumerable::range(uint16 count) {
  return range(uint16 {0}, count, uint16 {1});
}

const enumerable::ienumerable<uint16>& enumerable::range(uint16 start, uint16 count) {
  return range(start, static_cast<uint16>(start + count), uint16 {1});
}

const enumerable::ienumerable<uint16>& enumerable::range(uint16 start, uint16 stop, uint16 step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<uint16> {};
  result = __opaque_xtd_linq_enumerable_collection__<uint16> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<uint32>& enumerable::range(uint32 count) {
  return range(uint32 {0}, count, uint32 {1});
}

const enumerable::ienumerable<uint32>& enumerable::range(uint32 start, uint32 count) {
  return range(start, static_cast<uint32>(start + count), uint32 {1});
}

const enumerable::ienumerable<uint32>& enumerable::range(uint32 start, uint32 stop, uint32 step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<uint32> {};
  result = __opaque_xtd_linq_enumerable_collection__<uint32> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<uint64>& enumerable::range(uint64 count) {
  return range(uint64 {0}, count, uint64 {1});
}

const enumerable::ienumerable<uint64>& enumerable::range(uint64 start, uint64 count) {
  return range(start, static_cast<uint64>(start + count), uint64 {1});
}

const enumerable::ienumerable<uint64>& enumerable::range(uint64 start, uint64 stop, uint64 step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<uint64> {};
  result = __opaque_xtd_linq_enumerable_collection__<uint64> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}

const enumerable::ienumerable<ulong>& enumerable::range(ulong count) {
  return range(ulong {0}, count, ulong {1});
}

const enumerable::ienumerable<ulong>& enumerable::range(ulong start, ulong count) {
  return range(start, static_cast<ulong>(start + count), ulong {1});
}

const enumerable::ienumerable<ulong>& enumerable::range(ulong start, ulong stop, ulong step) {
  static thread_local auto result = __opaque_xtd_linq_enumerable_collection__<ulong> {};
  result = __opaque_xtd_linq_enumerable_collection__<ulong> {};
  for (auto index = start; index < stop; index += step)
    result.items.push_back(index);
  return result;
}
