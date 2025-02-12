#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/types>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include "../../include/xtd/basic_string.hpp"
#include "../../include/xtd/typeof.hpp"
#include "../../include/xtd/argument_exception.hpp"
#include "../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../include/xtd/format_exception.hpp"
#include "../../include/xtd/index_out_of_range_exception.hpp"
#include "../../include/xtd/null_pointer_exception.hpp"
#include "../../include/xtd/diagnostics/stack_frame.hpp"

using namespace xtd;

namespace xtd {
  class __xtd_demangle {
  public:
    std::basic_string<char> operator()(const std::basic_string<char>& value) {
      return native::types::demangle(value);
    }
  };
}

std::basic_string<char> __xtd_demangle(const std::basic_string<char>& value) noexcept {
  return xtd::__xtd_demangle {}(value);
}

std::basic_string<char> __xtd_get_class_name(const std::type_info& value) noexcept {
  return typeof_(value).name();
}

std::basic_string<char> __xtd_get_full_class_name(const std::type_info& value) noexcept {
  return typeof_(value).full_name();
}
