#include "../include/xtd/guid.hpp"
#include "../include/xtd/__opaque_environment.hpp"

using namespace xtd;

guid guid::new_guid() noexcept {
  return __opaque_environment::new_guid();
}
