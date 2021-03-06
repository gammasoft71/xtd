/// @file
/// @brief Contains xtd::strings class.
#pragma once

/// @defgroup keywords keywords
/// @brief Keywords are predefined, reserved identifiers that have special meanings to the compiler.

/// @defgroup types types
/// @brief Types definitions

/// @defgroup literals literals
/// @brief Literals Allows integer, floating-point, character, and string literals to produce objects.

/// @defgroup xtd_core xtd.core
/// @brief xtd.core library contains all fundamental classes to access Hardware, Os, System, and more.

#include "__generic_stream_output.h" // must be included first
#include "__get_err_rdbuf.h"
#include "__get_in_rdbuf.h"
#include "__get_out_rdbuf.h"
#include "__opaque_console.h"
#include "action.h"
#include "argument_exception.h"
#include "argument_null_exception.h"
#include "argument_out_of_range_exception.h"
#include "arithmetic_exception.h"
#include "background_color.h"
#include "basic_console.h"
#include "beep.h"
#include "bit_converter.h"
#include "block_scope.h"
#include "build_type.h"
#include "caller_info.h"
#include "cdebug.h"
#include "compiler.h"
#include "compiler_id.h"
#include "console.h"
#include "console_cancel_event_args.h"
#include "console_cancel_event_handler.h"
#include "console_color.h"
#include "console_key.h"
#include "console_key_info.h"
#include "console_modifiers.h"
#include "console_special_key.h"
#include "cpp_language.h"
#include "ctrace.h"
#include "debugstreambuf.h"
#include "delegate.h"
#include "divided_by_zero_exception.h"
#include "domain_exception.h"
#include "environment.h"
#include "environment_variable_target.h"
#include "event.h"
#include "event_args.h"
#include "event_handler.h"
#include "foreground_color.h"
#include "format.h"
#include "format_exception.h"
#include "func.h"
#include "guid.h"
#include "icomparable.h"
#include "iequatable.h"
#include "index_out_of_range_exception.h"
#include "interface.h"
#include "invalid_cast_exception.h"
#include "invalid_operation_exception.h"
#include "invalid_program_exception.h"
#include "is.h"
#include "istring.h"
#include "language_id.h"
#include "length_exception.h"
#include "literals.h"
#include "nameof.h"
#include "not_finite_number_exception.h"
#include "not_implemented_exception.h"
#include "not_supported_exception.h"
#include "null_pointer_exception.h"
#include "number_styles.h"
#include "object.h"
#include "operating_system.h"
#include "operation_canceled_exception.h"
#include "overflow_exception.h"
#include "overload.h"
#include "parse.h"
#include "platform_id.h"
#include "platform_not_supported_exception.h"
#include "predicate.h"
#include "processor.h"
#include "random.h"
#include "reset_color.h"
#include "startup.h"
#include "static.h"
#include "string_comparison.h"
#include "string_split_options.h"
#include "strings.h"
#include "system_exception.h"
#include "tick.h"
#include "ticks.h"
#include "time_out_exception.h"
#include "to_string.h"
#include "tracestreambuf.h"
#include "translator.h"
#include "typeof.h"
#include "types.h"
#include "underflow_exception.h"
#include "unused.h"
#include "using.h"
#include "va_args_comma.h"
#include "version.h"
#include "xml_syntax_exception.h"
#include "collections/any_pair.h"
#include "collections/key_not_found_exception.h"
#include "collections/vector_list.h"
#include "collections/specialized/string_map.h"
#include "collections/specialized/string_pair.h"
#include "collections/specialized/string_vector.h"
#include "diagnostics/console_trace_listener.h"
#include "diagnostics/debug.h"
#include "diagnostics/default_trace_listener.h"
#include "diagnostics/event_type_filter.h"
#include "diagnostics/ostream_trace_listener.h"
#include "diagnostics/process.h"
#include "diagnostics/process_start_info.h"
#include "diagnostics/process_window_style.h"
#include "diagnostics/source_filter.h"
#include "diagnostics/source_levels.h"
#include "diagnostics/source_switch.h"
#include "diagnostics/stack_frame.h"
#include "diagnostics/stack_trace.h"
#include "diagnostics/stopwatch.h"
#include "diagnostics/switch_base.h"
#include "diagnostics/trace.h"
#include "diagnostics/trace_event_cache.h"
#include "diagnostics/trace_event_type.h"
#include "diagnostics/trace_filter.h"
#include "diagnostics/trace_level.h"
#include "diagnostics/trace_listener.h"
#include "diagnostics/trace_listener_collection.h"
#include "diagnostics/trace_options.h"
#include "diagnostics/trace_source.h"
#include "diagnostics/trace_switch.h"
#include "html/css/parser.h"
#include "html/css/property.h"
#include "html/css/property_map.h"
#include "html/css/selector.h"
#include "html/css/selector_map.h"
#include "html/css/writer.h"
#include "io/cnull.h"
#include "io/directory_not_found_exception.h"
#include "io/drive_not_found_exception.h"
#include "io/end_of_stream_exception.h"
#include "io/file.h"
#include "io/file_attributes.h"
#include "io/file_format_exception.h"
#include "io/file_load_exception.h"
#include "io/file_not_found_exception.h"
#include "io/ioexception.h"
#include "io/path.h"
#include "io/path_too_long_exception.h"
#include "io/stream_reader.h"
#include "io/stream_writer.h"
#include "io/string_reader.h"
#include "io/string_writer.h"
#include "io/text_reader.h"
#include "io/text_writer.h"
