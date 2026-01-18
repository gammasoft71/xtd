#include "../../../include/xtd/linq/enumerable.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/as.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::linq;

auto enumerable::average(const ienumerable<decimal>& source) -> decimal {
  auto average = .0l;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

auto enumerable::average(const ienumerable<double>& source) -> double {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

auto enumerable::average(const ienumerable<float>& source) -> float {
  auto average = .0f;
  auto count = 0;
  for (auto item : source) {
    average += item;
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

auto enumerable::average(const ienumerable<int32>& source) -> double {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

auto enumerable::average(const ienumerable<int64>& source) -> double {
  auto average = .0;
  auto count = 0;
  for (auto item : source) {
    average += as<double>(item);
    ++count;
  }
  if (count == 0) throw_helper::throws(exception_case::invalid_operation);
  return average / count;
}

auto enumerable::average(const ienumerable<optional<decimal >>& source) noexcept -> optional<decimal> {
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

auto enumerable::average(const ienumerable<optional<double >>& source) noexcept -> optional<double> {
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

auto enumerable::average(const ienumerable<optional<float >>& source) noexcept -> optional<float> {
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

auto enumerable::average(const ienumerable<optional<int32 >>& source) noexcept -> optional<double> {
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

auto enumerable::average(const ienumerable<optional<int64 >>& source) noexcept -> optional<double> {
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

