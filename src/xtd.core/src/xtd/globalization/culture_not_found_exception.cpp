#include "../../../include/xtd/globalization/culture_not_found_exception.hpp"

using namespace xtd;
using namespace xtd::globalization;

culture_not_found_exception::culture_not_found_exception(const diagnostics::stack_frame& stack_frame) : system_exception(get_default_message(), stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ARGUMENT));
}

culture_not_found_exception::culture_not_found_exception(const std::optional<string>& message, const diagnostics::stack_frame& stack_frame) : system_exception(message == nullopt ? get_default_message() : message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ARGUMENT));
}

const string& culture_not_found_exception::get_default_message() {
  static auto message = string {"Culture is not supported."_t};
  return message;
}

