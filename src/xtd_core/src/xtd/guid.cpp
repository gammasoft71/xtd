#include "../include/xtd/guid.h"
#include "../include/xtd/__opaque_environment.h"

using namespace xtd;

guid guid::new_guid() noexcept {
  return __opaque_environment::new_guid();
}

const guid guid::empty;
