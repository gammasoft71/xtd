#include "../../include/xtd/as.h"
#include "../../include/xtd/is.h"
#include "../../include/xtd/hash_code.h"
#include "../../include/xtd/random.h"

using namespace xtd;
using namespace xtd::collections::generic;

bool hash_code::equals(const object& other) const noexcept {
  return is<hash_code>(other) ? hash_code_ == as<hash_code>(other).hash_code_ : object::equals(other);
}

size hash_code::get_hash_code() const noexcept {
  return hash_code_;
}

size hash_code::to_hash_code() const noexcept {
  return hash_code_;
}

size hash_code::combine_iterator(size seed) noexcept {
  return seed;
}

size hash_code::hash_combine(size seed, size value) noexcept {
  // https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values
  return seed ^ value + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

size hash_code::generate_uniqueness_seed() noexcept {
  static auto uniqueness_seed = hasher<int32> {}(random {}.next());
  return hash_combine(0, uniqueness_seed);
}
