#include "../../include/xtd/guid.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;

guid guid::new_guid() noexcept {
  return guid(native::environment::new_guid());
}

const guid guid::empty;
