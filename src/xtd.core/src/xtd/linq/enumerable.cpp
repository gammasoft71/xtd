#include "../../../include/xtd/linq/enumerable.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/literals.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::linq;

decimal enumerable::average(const ienumerable<decimal>& source) {
  auto average = .0l;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw invalid_operation_exception {};
  return average / count;
}

double enumerable::average(const ienumerable<double>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw invalid_operation_exception {};
  return average / count;
}

float enumerable::average(const ienumerable<float>& source) {
  auto average = .0f;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw invalid_operation_exception {};
  return average / count;
}

double enumerable::average(const ienumerable<int32>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw invalid_operation_exception {};
  return average / count;
}

double enumerable::average(const ienumerable<int64>& source) {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw invalid_operation_exception {};
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

enumerable_collection<int32> enumerable::range(int32 start, int32 count) {
  if (count < 0) throw argument_out_of_range_exception {};
  auto result = enumerable_collection<int32> {};
  for (auto index = start; index < start + count; ++index)
    result.items.push_back(index);
  return result;
}

void enumerable::throw_invalid_operation_exception() {
  throw invalid_operation_exception {};
}
