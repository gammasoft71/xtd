#include "../../include/xtd/make_error_code.hpp"
#include "../../include/xtd/h_result.hpp"

using namespace xtd;

std::error_code xtd::make_error_code(int h_result) noexcept {
  return xtd::h_result::make_error_code(h_result);
}
