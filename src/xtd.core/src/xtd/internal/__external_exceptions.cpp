#define __XTD_CORE_INTERNAL__
#include "../../../include/xtd/internal/__external_exceptions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../include/xtd/argument_exception.hpp"
#include "../../../include/xtd/argument_null_exception.hpp"
#include "../../../include/xtd/argument_out_of_range_exception.hpp"
#include "../../../include/xtd/format_exception.hpp"
#include "../../../include/xtd/index_out_of_range_exception.hpp"
#include "../../../include/xtd/invalid_operation_exception.hpp"
#include "../../../include/xtd/null_pointer_exception.hpp"
#include "../../../include/xtd/rank_exception.hpp"
#include "../../../include/xtd/diagnostics/stack_frame.hpp"

using namespace xtd;

void __throw_argument_exception(const char* message, const char* file, uint32 line, const char* func) {
  throw argument_exception {message, {file, line, func}};
}

void __throw_argument_exception(const char* file, uint32 line, const char* func) {
  throw argument_exception {{file, line, func}};
}

void __throw_argument_null_exception(const char* message, const char* file, uint32 line, const char* func) {
  throw argument_exception {message, {file, line, func}};
}

void __throw_argument_null_exception(const char* file, uint32 line, const char* func) {
  throw argument_exception {{file, line, func}};
}

void __throw_argument_out_of_range_exception(const char* message, const char* file, uint32 line, const char* func) {
  throw argument_out_of_range_exception {message, {file, line, func}};
}

void __throw_argument_out_of_range_exception(const char* file, uint32 line, const char* func) {
  throw argument_out_of_range_exception {{file, line, func}};
}

void __throw_format_exception(const char* message, const char* file, uint32 line, const char* func) {
  throw format_exception {message, {file, line, func}};
}

void __throw_format_exception(const char* file, uint32 line, const char* func) {
  throw format_exception {{file, line, func}};
}

void __throw_format_exception_close_bracket(const char* message, const char* file, uint32 line, const char* func) {
  throw format_exception {message, {file, line, func}};
}

void __throw_format_exception_close_bracket(const char* file, uint32 line, const char* func) {
  throw format_exception {{file, line, func}};
}

void __throw_format_exception_open_bracket(const char* message, const char* file, uint32 line, const char* func) {
  throw format_exception {message, {file, line, func}};
}

void __throw_format_exception_open_bracket(const char* file, uint32 line, const char* func) {
  throw format_exception {{file, line, func}};
}

void __throw_format_exception_start_colon(const char* message, const char* file, uint32 line, const char* func) {
  throw format_exception {message, {file, line, func}};
}

void __throw_format_exception_start_colon(const char* file, uint32 line, const char* func) {
  throw format_exception {{file, line, func}};
}

void __throw_index_out_of_range_exception(const char* message, const char* file, xtd::uint32 line, const char* func) {
  throw index_out_of_range_exception {message, {file, line, func}};
}

void __throw_index_out_of_range_exception(const char* file, xtd::uint32 line, const char* func) {
  throw index_out_of_range_exception {{file, line, func}};
}

void __throw_invalid_operation_exception(const char* message, const char* file, xtd::uint32 line, const char* func) {
  throw invalid_operation_exception {message, {file, line, func}};
}

void __throw_invalid_operation_exception(const char* file, xtd::uint32 line, const char* func) {
  throw invalid_operation_exception {{file, line, func}};
}

void __throw_null_pointer_exception(const char* message, const char* file, xtd::uint32 line, const char* func) {
  throw null_pointer_exception {message, {file, line, func}};
}

void __throw_null_pointer_exception(const char* file, xtd::uint32 line, const char* func) {
  throw null_pointer_exception {{file, line, func}};
}

void __throw_rank_exception(const char* message, const char* file, xtd::uint32 line, const char* func) {
  throw rank_exception {message, {file, line, func}};
}

void __throw_rank_exception(const char* file, xtd::uint32 line, const char* func) {
  throw rank_exception {{file, line, func}};
}
