#include "../../include/xtd/make_error_code.h"
#include "../../include/xtd/h_result.h"

using namespace xtd;

std::error_code xtd::make_error_code(int h_result) noexcept {
  return xtd::h_result::make_error_code(h_result);
}
