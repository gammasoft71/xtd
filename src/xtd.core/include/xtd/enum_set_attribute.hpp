/// @file
/// @brief Contains xtd::enum_set_attribute strcut.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "enum_attribute.hpp"
#include "enum_register.hpp"
#include "number_styles.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"
#include "helpers/exception_case.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the set attribute struct for enumerations.
  /// ```cpp
  /// template<class enum_t>
  /// struct enum_set_attribute
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_set_attribute>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The overloading of this operator is necessary for enum classes to be recognized as having a flags attribute to be properly handled by xtd::string::format().
  /// @remarks For more information about enumeration, see [enum class](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/enum_class) guide.
  /// @remarks When an enumeration is registered, we can display its name instead of its value, we can format it and parse it.
  /// @remarks See [Enumeration Format Strings](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings). For more information about formatting in general, see [Formatting Types](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/overview).
  /// @par Examples
  /// The following code show how to use xtd::enum_set_attribute operator.
  /// @include format_enum_class_flags_without_helpers.cpp
  template<class enum_t>
  struct enum_set_attribute {
    /// Allows to set attribute to an enumeration that can be used by xtd::enum_object.
    /// @return One of xtd::enum_attribute values.
    /// @remarks To set attribute to an enumeration just override xtd::enum_set_attribute.
    /// @par Examples
    /// The following code show how to set attribute to the value_flags enum class.
    /// ```cpp
    /// enum class value_flags {
    ///   value_none = 0,
    ///   value_one = 0b1,
    ///   value_two = 0b10,
    ///   value_three = 0b100,
    /// };
    ///
    /// template<>
    /// xtd::enum_set_attribute<value_flags> {
    ///   explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
    /// };
    /// ```
    explicit operator auto() const noexcept {return xtd::enum_attribute::standard;}
  };
}

/// @cond
template<> struct xtd::enum_register<xtd::enum_attribute> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::enum_attribute> {{enum_attribute::standard, "standard"}, {enum_attribute::flags, "flags"}};}
};

template<> struct xtd::enum_set_attribute<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_attribute::flags;}
};

template<> struct xtd::enum_register<xtd::number_styles> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::number_styles> {{xtd::number_styles::none, "none"}, {xtd::number_styles::allow_leading_white, "allow_leading_white"}, {xtd::number_styles::allow_trailing_white, "allow_trailing_white"}, {xtd::number_styles::allow_leading_sign, "allow_leading_sign"}, {xtd::number_styles::allow_trailing_sign, "allow_trailing_sign"}, {xtd::number_styles::allow_parentheses, "allow_parentheses"}, {xtd::number_styles::allow_decimal_point, "allow_decimal_point"}, {xtd::number_styles::allow_thousands, "allow_thousands"}, {xtd::number_styles::allow_exponent, "allow_exponent"}, {xtd::number_styles::allow_currency_symbol, "allow_currency_symbol"}, {xtd::number_styles::allow_hex_specifier, "allow_hex_specifier"}, {xtd::number_styles::allow_binary_specifier, "allow_binary_specifier"}, {xtd::number_styles::allow_octal_specifier, "allow_octal_specifier"}, {xtd::number_styles::integer, "integer"}, {xtd::number_styles::number, "number"}, {xtd::number_styles::fixed_point, "fixed_point"}, {xtd::number_styles::currency, "currency"}, {xtd::number_styles::any, "any"}, {xtd::number_styles::hex_number, "hex_number"}, {xtd::number_styles::binary_number, "binary_number"}, {xtd::number_styles::octal_number, "octal_number"}};}
};

template<> struct xtd::enum_register<xtd::string_comparison> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_comparison> {{xtd::string_comparison::current_culture, "current_culture"}, {xtd::string_comparison::current_culture_ignore_case, "current_culture_ignore_case"}, {xtd::string_comparison::invariant_culture, "invariant_culture"}, {xtd::string_comparison::invariant_culture_ignore_case, "invariant_culture_ignore_case"}, {xtd::string_comparison::ordinal, "ordinal"}, {xtd::string_comparison::ordinal_ignore_case, "ordinal_ignore_case"}};}
};

template<> struct xtd::enum_register<xtd::string_split_options> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::string_split_options> {{xtd::string_split_options::none, "none"}, {xtd::string_split_options::remove_empty_entries, "remove_empty_entries"}};}
};

template<> struct xtd::enum_register<xtd::helpers::exception_case> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::helpers::exception_case> {{xtd::helpers::exception_case::abandoned_mutex, "abandoned_mutex"}, {xtd::helpers::exception_case::access_violation, "access_violation"}, {xtd::helpers::exception_case::argument, "argument"}, {xtd::helpers::exception_case::argument_null, "argument_null"}, {xtd::helpers::exception_case::argument_out_of_range, "argument_out_of_range"}, {xtd::helpers::exception_case::arithmetic, "arithmetic"}, {xtd::helpers::exception_case::barrier_post_phase, "barrier_post_phase"}, {xtd::helpers::exception_case::culture_not_found, "culture_not_found"}, {xtd::helpers::exception_case::directory_not_found, "directory_not_found"}, {xtd::helpers::exception_case::divided_by_zero, "divided_by_zero"}, {xtd::helpers::exception_case::end_of_stream, "end_of_stream"}, {xtd::helpers::exception_case::file_not_found, "file_not_found"}, {xtd::helpers::exception_case::format, "format"}, {xtd::helpers::exception_case::format_closing_bracket_without_open_bracket, "format_closing_bracket_without_open_bracket"}, {xtd::helpers::exception_case::format_opened_bracket_without_end_bracket, "format_opened_bracket_without_end_bracket"}, {xtd::helpers::exception_case::format_no_start_colon, "format_no_start_colon"}, {xtd::helpers::exception_case::format_not_iformatable, "format_not_iformatable"}, {xtd::helpers::exception_case::index_out_of_range, "index_out_of_range"}, {xtd::helpers::exception_case::invalid_cast, "invalid_cast"}, {xtd::helpers::exception_case::invalid_operation, "invalid_operation"}, {xtd::helpers::exception_case::interrupt, "interrupt"}, {xtd::helpers::exception_case::io, "io"}, {xtd::helpers::exception_case::key_not_found, "key_not_found"}, {xtd::helpers::exception_case::lock_recursion, "lock_recursion"}, {xtd::helpers::exception_case::not_implemented, "not_implemented"}, {xtd::helpers::exception_case::not_supported, "not_supported"}, {xtd::helpers::exception_case::null_pointer, "null_pointer"}, {xtd::helpers::exception_case::object_closed, "object_closed"}, {xtd::helpers::exception_case::operation_canceled, "operation_canceled"}, {xtd::helpers::exception_case::overflow, "overflow"}, {xtd::helpers::exception_case::out_of_memory, "out_of_memory"}, {xtd::helpers::exception_case::path_too_long, "path_too_long"}, {xtd::helpers::exception_case::platform_not_supported, "platform_not_supported"}, {xtd::helpers::exception_case::rank, "rank"}, {xtd::helpers::exception_case::semaphore_full, "semaphore_full"}, {xtd::helpers::exception_case::socket, "socket"}, {xtd::helpers::exception_case::software_termination, "software_termination"}, {xtd::helpers::exception_case::synchronization_lock, "synchronization_lock"}, {xtd::helpers::exception_case::task_canceled, "task_canceled"}, {xtd::helpers::exception_case::thread_abort, "thread_abort"}, {xtd::helpers::exception_case::thread_interrupted, "thread_interrupted"}, {xtd::helpers::exception_case::thread_state, "thread_state"}, {xtd::helpers::exception_case::time_zone_not_found, "time_zone_not_found"}, {xtd::helpers::exception_case::unauthorized_access, "unauthorized_access"}, {xtd::helpers::exception_case::uri_format, "uri_format"}};}
};
/// @endcond
