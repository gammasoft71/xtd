#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/helpers/throw_helper.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/collections/generic/key_not_found_exception.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/io/directory_not_found_exception.hpp"
#include "../../../include/xtd/io/end_of_stream_exception.hpp"
#include "../../../include/xtd/io/file_not_found_exception.hpp"
#include "../../../include/xtd/io/io_exception.hpp"
#include "../../../include/xtd/io/path_too_long_exception.hpp"
#include "../../../include/xtd/threading/abandoned_mutex_exception.hpp"
#include "../../../include/xtd/threading/barrier_post_phase_exception.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/argument_null_exception.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/format_exception.hpp"
#include "../../../include/xtd/index_out_of_range_exception.hpp"
#include "../../../include/xtd/invalid_cast_exception.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/not_supported_exception.hpp"
#include "../../../include/xtd/null_pointer_exception.hpp"
#include "../../../include/xtd/object_closed_exception.hpp"
#include "../../../include/xtd/operation_canceled_exception.hpp"
#include "../../../include/xtd/overflow_exception.hpp"
#include "../../../include/xtd/platform_not_supported_exception.hpp"
#include "../../../include/xtd/rank_exception.hpp"
#include "../../../include/xtd/typeof.hpp"
#include "../../../include/xtd/unauthorized_access_exception.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;
using namespace xtd::helpers;
using namespace xtd::io;
using namespace xtd::threading;

namespace {
  stack_frame to_stack_frame(const throw_helper::source_location& location) {
    return stack_frame {location.file_name(), location.line(), location.function_name(), location.column()};
  }
}

void throw_helper::throws(enum exception_case exception_case, const source_location& location) {
  switch (exception_case) {
    case exception_case::abandoned_mutex: throw abandoned_mutex_exception {to_stack_frame(location)};
    case exception_case::argument: throw argument_exception {to_stack_frame(location)};
    case exception_case::argument_null: throw argument_null_exception {to_stack_frame(location)};
    case exception_case::argument_out_of_range: throw argument_out_of_range_exception {to_stack_frame(location)};
    case exception_case::barrier_post_phase: throw barrier_post_phase_exception {to_stack_frame(location)};
    case exception_case::directory_not_found: throw directory_not_found_exception {to_stack_frame(location)};
    case exception_case::end_of_stream: throw end_of_stream_exception {to_stack_frame(location)};
    case exception_case::file_not_found: throw file_not_found_exception {to_stack_frame(location)};
    case exception_case::format: throw format_exception {to_stack_frame(location)};
    case exception_case::format_closing_bracket_without_open_bracket: throw format_exception("Invalid format expression : closing bracket '{' without open bracket '}'"_t, to_stack_frame(location));
    case exception_case::format_opened_bracket_without_end_bracket: throw format_exception("Invalid format expression : open bracket '}' without end bracket '{'"_t, to_stack_frame(location));
    case exception_case::format_no_start_colon: throw format_exception("Invalid format expression : format argument must be start by ':'"_t, to_stack_frame(location));
    case exception_case::format_not_iformatable: throw format_exception(to_stack_frame(location));
    case exception_case::index_out_of_range: throw index_out_of_range_exception {to_stack_frame(location)};
    case exception_case::invalid_cast: throw invalid_cast_exception {to_stack_frame(location)};
    case exception_case::invalid_operation: throw invalid_operation_exception {to_stack_frame(location)};
    case exception_case::io: throw io_exception {to_stack_frame(location)};
    case exception_case::key_not_found: throw key_not_found_exception {to_stack_frame(location)};
    case exception_case::not_implemented: throw not_implemented_exception {to_stack_frame(location)};
    case exception_case::not_supported: throw not_supported_exception {to_stack_frame(location)};
    case exception_case::null_pointer: throw null_pointer_exception {to_stack_frame(location)};
    case exception_case::object_closed: throw object_closed_exception {to_stack_frame(location)};
    case exception_case::operation_canceled: throw operation_canceled_exception {to_stack_frame(location)};
    case exception_case::overflow: throw overflow_exception {to_stack_frame(location)};
    case exception_case::path_too_long: throw path_too_long_exception {to_stack_frame(location)};
    case exception_case::platform_not_supported: throw platform_not_supported_exception {to_stack_frame(location)};
    case exception_case::rank: throw rank_exception {to_stack_frame(location)};
    case exception_case::unauthorized_access: throw unauthorized_access_exception {to_stack_frame(location)};
    default: throw argument_exception {"Invalid xtd::helpers::exception_case value"};
  }
}

void throw_helper::throws(enum exception_case exception_case, const char* message, const source_location& location) {
  if (!message) throws(exception_case, location);
  else switch (exception_case) {
    case exception_case::abandoned_mutex: throw abandoned_mutex_exception {message, to_stack_frame(location)};
    case exception_case::argument: throw argument_exception {message, to_stack_frame(location)};
    case exception_case::argument_null: throw argument_null_exception {message, to_stack_frame(location)};
    case exception_case::argument_out_of_range: throw argument_out_of_range_exception {message, to_stack_frame(location)};
    case exception_case::barrier_post_phase: throw barrier_post_phase_exception {message, to_stack_frame(location)};
    case exception_case::directory_not_found: throw directory_not_found_exception {message, to_stack_frame(location)};
    case exception_case::end_of_stream: throw end_of_stream_exception {message, to_stack_frame(location)};
    case exception_case::file_not_found: throw file_not_found_exception {message, to_stack_frame(location)};
    case exception_case::format: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_closing_bracket_without_open_bracket: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_opened_bracket_without_end_bracket: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_no_start_colon: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_not_iformatable: throw format_exception {message, to_stack_frame(location)};
    case exception_case::index_out_of_range: throw index_out_of_range_exception {message, to_stack_frame(location)};
    case exception_case::invalid_cast: throw invalid_cast_exception {message, to_stack_frame(location)};
    case exception_case::invalid_operation: throw invalid_operation_exception {message, to_stack_frame(location)};
    case exception_case::io: throw io_exception {message, to_stack_frame(location)};
    case exception_case::key_not_found: throw key_not_found_exception {message, to_stack_frame(location)};
    case exception_case::not_implemented: throw not_implemented_exception {message, to_stack_frame(location)};
    case exception_case::not_supported: throw not_supported_exception {message, to_stack_frame(location)};
    case exception_case::null_pointer: throw null_pointer_exception {message, to_stack_frame(location)};
    case exception_case::object_closed: throw object_closed_exception {message, to_stack_frame(location)};
    case exception_case::operation_canceled: throw operation_canceled_exception {message, to_stack_frame(location)};
    case exception_case::overflow: throw overflow_exception {message, to_stack_frame(location)};
    case exception_case::path_too_long: throw path_too_long_exception {message, to_stack_frame(location)};
    case exception_case::platform_not_supported: throw platform_not_supported_exception {message, to_stack_frame(location)};
    case exception_case::rank: throw rank_exception {message, to_stack_frame(location)};
    case exception_case::unauthorized_access: throw unauthorized_access_exception {message, to_stack_frame(location)};
    default: throw argument_exception {"Invalid xtd::helpers::exception_case value"};
  }
}

void throw_helper::throws(enum exception_case exception_case, const xtd::type& type, const source_location& location) {
  throws(exception_case, (exception_case == exception_case::format_not_iformatable ? string::format("The `{0}` type does not inherit from `xtd::iformat` or the specialisation for the `{0}` type in the `xtd::to_string` specialisation method does not exist.", typeof_(type).full_name()) : typeof_(type).full_name()).c_str(), location);
}
