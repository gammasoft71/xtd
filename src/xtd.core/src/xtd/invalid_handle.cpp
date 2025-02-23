#include "../../include/xtd/invalid_handle.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__

namespace xtd {
  struct __xtd__handle__ {
    inline static const xtd::intptr invalid_handle = native::types::invalid_handle();
  };
}

const xtd::intptr xtd::invalid_handle = xtd::__xtd__handle__::invalid_handle;
