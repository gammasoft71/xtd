#include "../../include/xtd/h_result_category.hpp"
#include "../../include/xtd/h_result.hpp"

using namespace xtd;

const std::error_category& xtd::h_result_category() noexcept {
  return xtd::h_result::h_result_category();
}
