#include "../../include/xtd/as.hpp"
#include "../../include/xtd/is.hpp"
#include "../../include/xtd/environment.hpp"
#include "../../include/xtd/hash_code.hpp"
#include "../../include/xtd/random.hpp"

using namespace xtd;
using namespace xtd::collections::generic::helpers;

namespace {
  static size final_mix(size x) noexcept {
    x ^= x >> 23;
    x *= static_cast<size>(0x2127599bf4325c37ull);
    x ^= x >> 47;
    return x;
  }
}

bool hash_code::equals(const object& other) const noexcept {
  return is<hash_code>(other) ? hash_code_ == as<hash_code>(other).hash_code_ : object::equals(other);
}

size hash_code::get_hash_code() const noexcept {
  return to_hash_code();
}

size hash_code::to_hash_code() const noexcept {
  return final_mix(hash_code_);
}

size hash_code::combine_iterator(size seed) noexcept {
  return seed;
}

size hash_code::hash_combine(size seed, size value) noexcept {
  // https://stackoverflow.com/questions/35985960/c-why-is-boosthash-combine-the-best-way-to-combine-hash-values
  return (seed ^ value) + (environment::is_64_bit_process() ? static_cast<size>(0x9e3779b97f4a7c15ull) : 0x9e3779b9) + (seed << 6) + (seed >> 2);
}

size hash_code::generate_uniqueness_seed() noexcept {
  static auto uniqueness_seed = hasher<int32> {}(random {}.next());
  return hash_combine(0, uniqueness_seed);
}
