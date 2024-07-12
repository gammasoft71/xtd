#include "../../include/xtd/as.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/hash_code.h"
#include "../../include/xtd/random.h"

using namespace xtd;

bool hash_code::force_uniqueness_by_os_process_ = true;

bool hash_code::equals(const object& other) const noexcept {
  return is<hash_code>(other) ? hash_code_ == as<hash_code>(other).hash_code_ : object::equals(other);
}

size_t hash_code::get_hash_code() const noexcept {
  return hash_code_;
}

size_t hash_code::to_hash_code() const noexcept {
  return hash_code_;
}

xtd::size hash_code::hash_combine(xtd::size seed, xtd::size value) noexcept {
  // https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values
  return seed ^ value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

size_t hash_code::combine() noexcept {
  static auto uniqueness = xtd::random {}.next<xtd::size>(); // Force the uniqueness by operating system process.
  return force_uniqueness_by_os_process_ ? uniqueness : 0;
}
