#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/helpers/throw_helper.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/collections/generic/key_not_found_exception.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/argument_null_exception.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/format_exception.hpp"
#include "../../../include/xtd/index_out_of_range_exception.hpp"
#include "../../../include/xtd/invalid_cast_exception.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/not_implemented_exception.hpp"
#include "../../../include/xtd/null_pointer_exception.hpp"
#include "../../../include/xtd/overflow_exception.hpp"
#include "../../../include/xtd/rank_exception.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;
using namespace xtd::helpers;

namespace {
  stack_frame to_stack_frame(const throw_helper::source_location& location) {
    return stack_frame {location.file_name(), location.line(), location.function_name(), location.column()};
  }
}

void throw_helper::throws(enum exception_case exception_case, const source_location& location) {
  switch (exception_case) {
    case exception_case::argument: throw argument_exception {to_stack_frame(location)};
    case exception_case::argument_null: throw argument_null_exception {to_stack_frame(location)};
    case exception_case::argument_out_of_range: throw argument_out_of_range_exception {to_stack_frame(location)};
    case exception_case::format: throw format_exception {to_stack_frame(location)};
    case exception_case::format_closing_bracket_without_open_bracket: throw format_exception("Invalid format expression : closing bracket '{' without open bracket '}'"_t, to_stack_frame(location));
    case exception_case::format_opened_bracket_without_end_bracket: throw format_exception("Invalid format expression : open bracket '}' without end bracket '{'"_t, to_stack_frame(location));
    case exception_case::format_no_start_colon: throw format_exception("Invalid format expression : format argument must be start by ':'"_t, to_stack_frame(location));
    case exception_case::index_out_of_range: throw index_out_of_range_exception {to_stack_frame(location)};
    case exception_case::invalid_cast: throw invalid_cast_exception {to_stack_frame(location)};
    case exception_case::invalid_operation: throw invalid_operation_exception {to_stack_frame(location)};
    case exception_case::key_not_found: throw key_not_found_exception {to_stack_frame(location)};
    case exception_case::not_implemented: throw not_implemented_exception {to_stack_frame(location)};
    case exception_case::null_pointer: throw null_pointer_exception {to_stack_frame(location)};
    case exception_case::overflow: throw overflow_exception {to_stack_frame(location)};
    case exception_case::rank: throw rank_exception {to_stack_frame(location)};
    default: throw argument_exception {"Invalid xtd::helpers::exception_case value"};
  }
}

void throw_helper::throws(enum exception_case exception_case, const char* message, const source_location& location) {
  if (!message) throws(exception_case, location);
  else switch (exception_case) {
    case exception_case::argument: throw argument_exception {message, to_stack_frame(location)};
    case exception_case::argument_null: throw argument_null_exception {message, to_stack_frame(location)};
    case exception_case::argument_out_of_range: throw argument_out_of_range_exception {message, to_stack_frame(location)};
    case exception_case::format: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_closing_bracket_without_open_bracket: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_opened_bracket_without_end_bracket: throw format_exception {message, to_stack_frame(location)};
    case exception_case::format_no_start_colon: throw format_exception {message, to_stack_frame(location)};
    case exception_case::index_out_of_range: throw index_out_of_range_exception {message, to_stack_frame(location)};
    case exception_case::invalid_cast: throw invalid_cast_exception {message, to_stack_frame(location)};
    case exception_case::invalid_operation: throw invalid_operation_exception {message, to_stack_frame(location)};
    case exception_case::key_not_found: throw key_not_found_exception {message, to_stack_frame(location)};
    case exception_case::not_implemented: throw not_implemented_exception {message, to_stack_frame(location)};
    case exception_case::null_pointer: throw null_pointer_exception {message, to_stack_frame(location)};
    case exception_case::overflow: throw overflow_exception {message, to_stack_frame(location)};
    case exception_case::rank: throw rank_exception {message, to_stack_frame(location)};
    default: throw argument_exception {"Invalid xtd::helpers::exception_case value"};
  }
}
