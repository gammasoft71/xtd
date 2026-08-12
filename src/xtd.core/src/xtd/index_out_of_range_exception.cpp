#include "../../include/xtd/index_out_of_range_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

index_out_of_range_exception::index_out_of_range_exception(const stack_frame& stack_frame) : system_exception(std::nullopt, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE));
}

index_out_of_range_exception::index_out_of_range_exception(const std::optional<xtd::string>& message, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE));
}

/// @todo remove deprecated in version 1.2.0
/// @{
index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  self_.error_code(error);
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  self_.error_code(error);
  self_.help_link(help_link);
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE));
  self_.help_link(help_link);
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  self_.error_code(error);
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE));
  self_.help_link(help_link);
}

index_out_of_range_exception::index_out_of_range_exception(const xtd::string& message, const std::exception& inner_exception, const std::error_code& error, const xtd::string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : system_exception(message, inner_exception, stack_frame) {
  self_.error_code(error);
  self_.help_link(help_link);
}
/// @}
