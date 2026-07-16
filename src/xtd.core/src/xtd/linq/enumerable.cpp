#include "../../../include/xtd/linq/enumerable.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::helpers;
using namespace xtd::linq;

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
