#include "../../../include/xtd/io/end_of_stream_exception.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::io;

end_of_stream_exception::end_of_stream_exception(const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
}

end_of_stream_exception::end_of_stream_exception(const optional<string>& message, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
}

/// @todo remove deprecated in version 0.4.0
/// @{
end_of_stream_exception::end_of_stream_exception(const string& message, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

end_of_stream_exception::end_of_stream_exception(const string& message, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
  this->help_link(help_link);
}

end_of_stream_exception::end_of_stream_exception(const string& message, const std::error_code& error, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}

end_of_stream_exception::end_of_stream_exception(const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
}

end_of_stream_exception::end_of_stream_exception(const string& message, const std::exception& inner_exception, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
}

end_of_stream_exception::end_of_stream_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
}

end_of_stream_exception::end_of_stream_exception(const string& message, const std::exception& inner_exception, const string& help_link, const stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(h_result::make_error_code(h_result::COR_E_ENDOFSTREAM));
  this->help_link(help_link);
}

end_of_stream_exception::end_of_stream_exception(const string& message, const std::exception& inner_exception, const std::error_code& error, const string& help_link, const xtd::diagnostics::stack_frame& stack_frame) : io_exception(message, stack_frame) {
  error_code(error);
  this->help_link(help_link);
}
/// @}
