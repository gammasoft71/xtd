# xtd.core Development status

## In this section

* [Status information](#status-information)
* [xtd](#xtd)
* [xtd::collections](#xtdcollections)
* [xtd::collections::specialized](#xtdcollectionsspecialized)
* [xtd::diagnostics](#xtddiagnostics)
* [xtd::io](#xtdio)
* [xtd::io::memory_mapped_files](#xtdiomemory_mapped_files)
* [xtd:media](#xtdmedia)
* [xtd::microsoft::win32](#xtdmicrosoftwin32)
* [xtd::net](#xtdnet)
* [xtd::net::sockets](#xtdnetsockets)
* [xtd::net::websockets](#xtdnetwebsockets)
* [xtd::reflection](#xtdreflection)
* [xtd::security](#xtdsecurity)
* [xtd::text](#xtdtext)
* [xtd::threading](#xtdthreading)
* [xtd::timers](#xtdtimers)
* [xtd::web::css](#xtdwebcss)

## Status information

* ![progress](/pictures/progress_ina.png) Not applicable
* ![progress](/pictures/progress0.png) Not started
* ![progress](/pictures/progress25.png) Started
* ![progress](/pictures/progress50.png) In progress
* ![progress](/pictures/progress75.png) Usable
* ![progress](/pictures/progress100.png) Complete

## xtd

| Name                                                                                                                                               | Type          | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- | -------------------------------------- |
| [action](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/action.h)                                                         | delegate      | ![progress](/pictures/progress100.png) |
| [architecture_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/architecture_id.h)                                       | enumeration   | ![progress](/pictures/progress100.png) |
| [argument_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_exception.h)                                 | exception     | ![progress](/pictures/progress100.png) |
| [argument_null_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_null_exception.h)                       | exception     | ![progress](/pictures/progress100.png) |
| [argument_out_of_range_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_out_of_range_exception.h)       | exception     | ![progress](/pictures/progress100.png) |
| [arithmetic_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/arithmetic_exception.h)                             | exception     | ![progress](/pictures/progress100.png) |
| [as](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/as.h)                                                                 | operator      | ![progress](/pictures/progress100.png) |
| [async_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/async_callback.h)                                         | delegate      | ![progress](/pictures/progress100.png) |
| [attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/attribute.h)                                                   | class         | ![progress](/pictures/progress100.png) |
| [background_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/background_color.h)                                     | iomanip       | ![progress](/pictures/progress100.png) |
| [beep](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/beep.h)                                                             | iomanip       | ![progress](/pictures/progress100.png) |
| [bit_converter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/bit_converter.h)                                           | static class  | ![progress](/pictures/progress100.png) |
| [block_scope_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/block_scope.h)                                              | keyword       | ![progress](/pictures/progress100.png) |
| [build_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/build_type.h)                                                 | enumeration   | ![progress](/pictures/progress100.png) |
| [cdebug](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cdebug.h)                                                         | object        | ![progress](/pictures/progress100.png) |
| [cnull](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cnull.h)                                                           | object        | ![progress](/pictures/progress100.png) |
| [compiler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/compiler.h)                                                     | class         | ![progress](/pictures/progress100.png) |
| [compiler_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/compiler_id.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [console](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console.h)                                                       | static class  | ![progress](/pictures/progress100.png) |
| [console_cancel_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_cancel_event_args.h)                   | class         | ![progress](/pictures/progress100.png) |
| [console_cancel_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_cancel_event_handler.h)             | delegate      | ![progress](/pictures/progress100.png) |
| [console_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_color.h)                                           | enumeration   | ![progress](/pictures/progress100.png) |
| [console_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_key.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [console_key_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_key_info.h)                                     | class         | ![progress](/pictures/progress100.png) |
| [console_modifiers](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_modifiers.h)                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [console_special_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_special_key.h)                               | enumeration   | ![progress](/pictures/progress100.png) |
| [convert](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert.h)                                                       | static class  | ![progress](/pictures/progress100.png) |
| [convert_pointer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert_pointer.h)                                       | static class  | ![progress](/pictures/progress100.png) |
| [convert_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert_string.h)                                         | static class  | ![progress](/pictures/progress100.png) |
| [cpp_language](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cpp_language.h)                                             | class         | ![progress](/pictures/progress100.png) |
| [ctrace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ctrace.h)                                                         | object        | ![progress](/pictures/progress100.png) |
| [date_time](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/date_time.h)                                                   | struct        | ![progress](/pictures/progress100.png) |
| [date_time_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/date_time_kind.h)                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [day_of_week](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/day_of_week.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [debugstreambuf](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/debugstreambuf.h)                                         | class         | ![progress](/pictures/progress100.png) |
| [delegate](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/delegate.h)                                                     | delegate      | ![progress](/pictures/progress100.png) |
| [divided_by_zero_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/dividde_by_zero_exception.h)                   | exception     | ![progress](/pictures/progress100.png) |
| [domain_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/domain_exception.h)                                     | exception     | ![progress](/pictures/progress100.png) |
| [environment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/environment.h)                                               | static class  | ![progress](/pictures/progress100.png) |
| [environment_variable_target](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/environment_variable_target.h)               | enumeration   | ![progress](/pictures/progress100.png) |
| [event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event.h)                                                           | event         | ![progress](/pictures/progress100.png) |
| [event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event_args.h)                                                 | class         | ![progress](/pictures/progress100.png) |
| [event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event_handler.h)                                           | event handler | ![progress](/pictures/progress100.png) |
| [foreground_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/foreground_color.h)                                     | iomanip       | ![progress](/pictures/progress100.png) |
| [format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/format_exception.h)                                     | exception     | ![progress](/pictures/progress100.png) |
| [func](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/func.h)                                                             | delegate      | ![progress](/pictures/progress100.png) |
| [guid](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/guid.h)                                                             | struct        | ![progress](/pictures/progress100.png) |
| [iasync_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iasync_result.h)                                           | interface     | ![progress](/pictures/progress100.png) |
| [icomparable](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/icomparable.h)                                               | interface     | ![progress](/pictures/progress100.png) |
| [iequatable](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iequatable.h)                                                 | interface     | ![progress](/pictures/progress100.png) |
| [index_out_of_range_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/index_out_of_range_exception.h)             | exception     | ![progress](/pictures/progress100.png) |
| [interface_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/interface.h)                                                  | keyword       | ![progress](/pictures/progress100.png) |
| [invalid_cast_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_cast_exception.h)                         | exception     | ![progress](/pictures/progress100.png) |
| [invalid_operation_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_operation_exception.h)               | exception     | ![progress](/pictures/progress100.png) |
| [invalid_program_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_program_exception.h)                   | exception     | ![progress](/pictures/progress100.png) |
| [is](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/is.h)                                                                 | operators     | ![progress](/pictures/progress100.png) |
| [language_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/language_id.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [length_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/length_exception.h)                                     | exception     | ![progress](/pictures/progress100.png) |
| [literals](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/literals.h)                                                     | operators     | ![progress](/pictures/progress100.png) |
| [lock_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/lock.h)                                                            | keyword       | ![progress](/pictures/progress0.png)   |
| [math](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/math.h)                                                             | static class  | ![progress](/pictures/progress100.png) |
| [nameof_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/nameof.h)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [not_finite_number_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_finite_number_exception.h)               | exception     | ![progress](/pictures/progress100.png) |
| [not_implemented_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_implemented_exception.h)                   | exception     | ![progress](/pictures/progress100.png) |
| [not_supported_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_supported_exception.h)                       | exception     | ![progress](/pictures/progress100.png) |
| [null_pointer_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/null_pointer_exception.h)                         | exception     | ![progress](/pictures/progress100.png) |
| [number_styles](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/number_styles.h)                                           | enumeration   | ![progress](/pictures/progress100.png) |
| [object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/object.h)                                                         | class         | ![progress](/pictures/progress75.png)  |
| [object_closed_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/object_closed_exception.h)                       | exception     | ![progress](/pictures/progress100.png) |
| [operating_system](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/operating_system.h)                                     | class         | ![progress](/pictures/progress100.png) |
| [operation_canceled_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/operation_canceled_exception.h)             | exception     | ![progress](/pictures/progress100.png) |
| [overflow_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/overflow_exception.h)                                 | exception     | ![progress](/pictures/progress100.png) |
| [overload](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/overload.h)                                                     | class         | ![progress](/pictures/progress100.png) |
| [parse](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/parse.h)                                                           | operators     | ![progress](/pictures/progress100.png) |
| [platform_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/platform_id.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [platform_not_supported_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/platform_not_supported_exception.h)     | class         | ![progress](/pictures/progress100.png) |
| [predicate](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/predicate.h)                                                   | delegate      | ![progress](/pictures/progress100.png) |
| [processor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/processor.h)                                                   | class         | ![progress](/pictures/progress100.png) |
| [random](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/random.h)                                                         | class         | ![progress](/pictures/progress100.png) |
| [reset_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reset_color.h)                                               | iomanip       | ![progress](/pictures/progress100.png) |
| [startup_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/startup.h)                                                      | keyword       | ![progress](/pictures/progress100.png) |
| [static_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/static.h)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [static_object_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/static.h)                                                 | keyword       | ![progress](/pictures/progress100.png) |
| [string_comparison](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/string_comparison.h)                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [string_split_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/string_split_options.h)                             | enumeration   | ![progress](/pictures/progress100.png) |
| [system_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/system_exception.h)                                     | exception     | ![progress](/pictures/progress100.png) |
| [system_exception_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/system_exception.h)                                    | keyword       | ![progress](/pictures/progress100.png) |
| [tick](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/tick.h)                                                             | class         | ![progress](/pictures/progress100.png) |
| [ticks](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ticks.h)                                                           | class         | ![progress](/pictures/progress100.png) |
| [time_zone_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/time_zone_info.h)                                         | class         | ![progress](/pictures/progress50.png)  |
| [time_time_zone_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/time_time_zone_not_found_exception.h) | exception     | ![progress](/pictures/progress100.png) |
| [to_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/to_string.h)                                                   | operators     | ![progress](/pictures/progress100.png) |
| [tracestreambuf](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/tracestreambuf.h)                                         | class         | ![progress](/pictures/progress100.png) |
| [translator](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/translator.h)                                                 | class         | ![progress](/pictures/progress100.png) |
| [typeof_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/typeof.h)                                                        | class         | ![progress](/pictures/progress100.png) |
| [type_code](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/type_code.h)                                                   | enumeration   | ![progress](/pictures/progress0.png)   |
| [type_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/type_object.h)                                               | class         | ![progress](/pictures/progress100.png) |
| [types](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/types.h)                                                           | aliases       | ![progress](/pictures/progress100.png) |
| [underflow_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/underflow_exception.h)                               | exception     | ![progress](/pictures/progress100.png) |
| [unused_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/unused.h)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [uri](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri.h)                                                               | class         | ![progress](/pictures/progress100.png) |
| [uri_components](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_components.h)                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_format.h)                                                 | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_format_exception.h)                             | exception     | ![progress](/pictures/progress100.png) |
| [uri_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_kind.h)                                                     | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_partial](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_partial.h)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_template_match_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_template_match_exception.h)             | exception     | ![progress](/pictures/progress100.png) |
| [using_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/using.h)                                                          | keyword       | ![progress](/pictures/progress100.png) |
| [ustring](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ustring.h)                                                       | class         | ![progress](/pictures/progress100.png) |
| [version](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/version.h)                                                       | class         | ![progress](/pictures/progress100.png) |
| [xml_syntax_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/xml_syntax_exception.h)                             | exception     | ![progress](/pictures/progress100.png) |

## xtd::collections

| Name                                                                                                                                     | Type          | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------- | ------------- | -------------------------------------- |
| [any_pair](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/any_pair.h)                               | alias         | ![progress](/pictures/progress100.png) |
| [key_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/key_not_found_exception.h) | class         | ![progress](/pictures/progress100.png) |
| [vector_list](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/vector_list.h)                         | alias         | ![progress](/pictures/progress100.png) |

## xtd::collections::specialized

| Name                                                                                                                             | Type          | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------- | ------------- | -------------------------------------- |
| [string_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_map.h)       | alias         | ![progress](/pictures/progress100.png) |
| [string_pair](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_pair.h)     | alias         | ![progress](/pictures/progress100.png) |
| [string_vector](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_vector.h) | alias         | ![progress](/pictures/progress100.png) |

## xtd::diagnostics

| Name                                                                                                                                             | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [assert_dialog_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/assert_dialog_result.h)               | enumeration  | ![progress](/pictures/progress100.png) |
| [boolean_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/boolean_switch.h)                           | class        | ![progress](/pictures/progress100.png) |
| [console_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/console_trace_listener.h)           | class        | ![progress](/pictures/progress100.png) |
| [csf_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_frame.h)                                        | keyword      | ![progress](/pictures/progress100.png) |
| [current_stack_frame_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_frame.h)                        | keyword      | ![progress](/pictures/progress100.png) |
| [data_received_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/data_received_event_args.h)       | class        | ![progress](/pictures/progress100.png) |
| [data_received_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/data_received_event_handler.h) | delegate     | ![progress](/pictures/progress100.png) |
| [debug](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/debug.h)                                             | static class | ![progress](/pictures/progress100.png) |
| [debugger](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/debugger.h)                                       | static class | ![progress](/pictures/progress100.png) |
| [default_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/default_trace_listener.h)           | class        | ![progress](/pictures/progress100.png) |
| [event_log](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/event_log.h)                                     | class        | ![progress](/pictures/progress0.png)   |
| [event_type_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/event_type_filter.h)                     | class        | ![progress](/pictures/progress100.png) |
| [ostream_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/ostream_trace_listener.h)           | class        | ![progress](/pictures/progress100.png) |
| [performance_counter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/performance_counter.h)                 | class        | ![progress](/pictures/progress0.png)   |
| [process](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process.h)                                         | class        | ![progress](/pictures/progress75.png)  |
| [process_priority_class](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_priority_class.h)           | enumeration  | ![progress](/pictures/progress100.png) |
| [process_start_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_start_info.h)                   | class        | ![progress](/pictures/progress100.png) |
| [process_window_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_window_style.h)               | enumeration  | ![progress](/pictures/progress100.png) |
| [source_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_filter.h)                             | class        | ![progress](/pictures/progress100.png) |
| [source_levels](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_levels.h)                             | enumeration  | ![progress](/pictures/progress100.png) |
| [source_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_switch.h)                             | class        | ![progress](/pictures/progress100.png) |
| [stack_frame](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_frame.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [stack_trace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_trace.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [stopwatch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stopwatch.h)                                     | class        | ![progress](/pictures/progress100.png) |
| [switch_base](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/switch_base.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [trace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace.h)                                             | static class | ![progress](/pictures/progress100.png) |
| [trace_event_cache](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_event_cache.h)                     | class        | ![progress](/pictures/progress100.png) |
| [trace_event_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_event_type.h)                       | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_filter.h)                               | class        | ![progress](/pictures/progress100.png) |
| [trace_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_level.h)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_listener.h)                           | class        | ![progress](/pictures/progress100.png) |
| [trace_listener_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_listener_collection.h)     | class        | ![progress](/pictures/progress100.png) |
| [trace_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_options.h)                             | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_source](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_source.h)                               | class        | ![progress](/pictures/progress100.png) |
| [trace_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_switch.h)                               | class        | ![progress](/pictures/progress100.png) |

## xtd::io

| Name                                                                                                                                             | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [binary_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/binary_reader.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [binary_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/binary_writer.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [directory](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory.h)                                              | static class | ![progress](/pictures/progress100.png) |
| [directory_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory_info.h)                                    | class        | ![progress](/pictures/progress100.png) |
| [directory_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory_not_found_exception.h)      | exception    | ![progress](/pictures/progress100.png) |
| [drive_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/drive_info.h)                                            | class        | ![progress](/pictures/progress100.png) |
| [drive_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/drive_not_found_exception.h)              | exception    | ![progress](/pictures/progress100.png) |
| [end_of_stream_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/end_of_stream_exception.h)                  | exception    | ![progress](/pictures/progress100.png) |
| [file](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file.h)                                                        | static class | ![progress](/pictures/progress100.png) |
| [file_attributes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_attributes.h)                                  | enumeration  | ![progress](/pictures/progress100.png) |
| [file_format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_format_exception.h)                      | exception    | ![progress](/pictures/progress100.png) |
| [file_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_info.h)                                              | class        | ![progress](/pictures/progress100.png) |
| [file_load_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_load_exception.h)                          | exception    | ![progress](/pictures/progress100.png) |
| [file_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_not_found_exception.h)                | exception    | ![progress](/pictures/progress100.png) |
| [file_system_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_system_info.h)                                | class        | ![progress](/pictures/progress100.png) |
| [file_system_watcher](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_system_watcher.h)                          | class        | ![progress](/pictures/progress0.png)   |
| [io_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/io_exception.h)                                        | exception    | ![progress](/pictures/progress100.png) |
| [path](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/path.h)                                                        | static class | ![progress](/pictures/progress100.png) |
| [path_too_long_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/path_too_long_exception.h)                  | exception    | ![progress](/pictures/progress100.png) |
| [stream_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/stream_reader.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [stream_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/stream_writer.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [string_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/string_reader.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [string_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/string_writer.h)                                      | class        | ![progress](/pictures/progress100.png) |
| [text_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/text_reader.h)                                          | class        | ![progress](/pictures/progress100.png) |
| [text_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/text_writer.h)                                          | class        | ![progress](/pictures/progress100.png) |

## xtd::io::memory_mapped_files

| Name                                                                                                                                                        | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [memory_mapped_file](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file.h)                   | class        | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_access](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_access.h)     | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_options.h)   | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_rights](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_rights.h)     | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_view_accessor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_view_accessor.h) | class        | ![progress](/pictures/progress0.png)   |
| [memory_mapped_view_stream](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_view_stream.h)     | class        | ![progress](/pictures/progress0.png)   |

## xtd::media

| Name                                                                                                                                             | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [sound_player](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/sound_player.h)                                     | class        | ![progress](/pictures/progress0.png)   |
| [system_sound](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/system_sound.h)                                     | class        | ![progress](/pictures/progress100.png) |
| [system_sounds](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/system_sounds.h)                                   | static class | ![progress](/pictures/progress100.png) |

## xtd::microsoft::win32

| Name                                                                                                                                                     | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [registry](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry.h)                                           | class        | ![progress](/pictures/progress0.png)   |
| [registry_hive](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_hive.h)                                 | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_key.h)                                   | class        | ![progress](/pictures/progress0.png)   |
| [registry_key_permission_check](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_key_permission_check.h) | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_options.h)                           | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_value_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_value_kind.h)                     | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_value_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_value_options.h)               | enumeration  | ![progress](/pictures/progress0.png)   |
| [Registry_view](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_view.h)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net

| Name                                                                                                                                       | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [cookie_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/cookie_exception.h)                         | exception    | ![progress](/pictures/progress100.png) |
| [dns](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/dns.h)                                                   | static class | ![progress](/pictures/progress100.png) |
| [dns_end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/dns_end_point.h)                               | class        | ![progress](/pictures/progress100.png) |
| [end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/end_point.h)                                       | class        | ![progress](/pictures/progress100.png) |
| [ip_address](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_address.h)                                     | class        | ![progress](/pictures/progress100.png) |
| [ip_end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_end_point.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [ip_host_entry](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_host_entry.h)                               | class        | ![progress](/pictures/progress100.png) |
| [network_credential](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/network_credential.h)                     | class        | ![progress](/pictures/progress100.png) |
| [protocol_violation_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/protocol_violation_exception.h) | exception    | ![progress](/pictures/progress100.png) |
| [socket_address](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/socket_address.h)                             | class        | ![progress](/pictures/progress100.png) |
| [web_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_exception.h)                               | exception    | ![progress](/pictures/progress100.png) |
| [web_request](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_end_point.h)                                 | class        | ![progress](/pictures/progress0.png)   |
| [web_request_methods](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_request_methods.h)                   | static class | ![progress](/pictures/progress0.png)   |
| [web_response](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_response.h)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net::sockets

| Name                                                                                                                                                           | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [address_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/address_family.h)                                         | enumeration  | ![progress](/pictures/progress100.png) |
| [io_control_code](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/io_control_code.h)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [ip_packet_information](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_packet_information.h)                           | class        | ![progress](/pictures/progress100.png) |
| [ip_protection_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_protection_level.h)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [ip_v6_multicast_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_v6_multicast_option.h)                         | class        | ![progress](/pictures/progress100.png) |
| [linger_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/linger_option.h)                                           | class        | ![progress](/pictures/progress100.png) |
| [multicast_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/multicast_option.h)                                     | class        | ![progress](/pictures/progress100.png) |
| [network_stream](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/network_stream.h)                                         | class        | ![progress](/pictures/progress100.png) |
| [protocol_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/protocol_family.h)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [protocol_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/protocol_type.h)                                           | enumeration  | ![progress](/pictures/progress100.png) |
| [select_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/select_mode.h)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [send_packets_element](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/send_packets_element.h)                             | class        | ![progress](/pictures/progress100.png) |
| [socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket.h)                                                         | class        | ![progress](/pictures/progress75.png)  |
| [socket_async_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_async_event_args.h)                       | class        | ![progress](/pictures/progress100.png) |
| [socket_async_operation](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_async_operation.h)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_error](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_error.h)                                             | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_exception.h)                                     | exception    | ![progress](/pictures/progress100.png) |
| [socket_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_flags.h)                                             | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_information](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_information.h)                                 | class        | ![progress](/pictures/progress100.png) |
| [socket_information_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_information_options.h)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_option_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_option_level.h)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_option_name](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_option_name.h)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_receive_from_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_receive_from_result.h)                 | class        | ![progress](/pictures/progress0.png)   |
| [socket_receive_message_from_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_receive_message_from_result.h) | class        | ![progress](/pictures/progress0.png)   |
| [socket_shutdown](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_shutdown.h)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_type.h)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [tcp_client](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/tcp_client.h)                                                 | class        | ![progress](/pictures/progress75.png)  |
| [tcp_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/tcp_listener.h)                                             | class        | ![progress](/pictures/progress75.png)  |
| [transmit_file_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/transmit_file_options.h)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [udp_client](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/udp_client.h)                                                 | class        | ![progress](/pictures/progress75.png)  |
| [udp_receive_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/udp_receive_result.h)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net::web_sockets

| Name                                                                                                                                        | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [client_web_socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/client_web_socket.h)             | class        | ![progress](/pictures/progress0.png)   |
| [web_socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket.h)                           | class        | ![progress](/pictures/progress0.png)   |
| [web_socket_close_status](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_close_status.h) | enumeration  | ![progress](/pictures/progress0.png)   |
| [web_socket_message_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_message_type.h) | enumeration  | ![progress](/pictures/progress0.png)   |
| [web_socket_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_state.h)               | enumeration  | ![progress](/pictures/progress0.png)   |

## xtd::reflection

| Name                                                                                                                                                      | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [assembly](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly.h)                                                 | class        | ![progress](/pictures/progress100.png) |
| [assembly_company_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_company_attribute.h)             | class        | ![progress](/pictures/progress100.png) |
| [assembly_configuration_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_configuration_attribute.h) | class        | ![progress](/pictures/progress100.png) |
| [assembly_copyright_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_copyright_attribute.h)         | class        | ![progress](/pictures/progress100.png) |
| [assembly_description_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_description_attribute.h)     | class        | ![progress](/pictures/progress100.png) |
| [assembly_file_version_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_file_version_attribute.h)   | class        | ![progress](/pictures/progress100.png) |
| [assembly_guid_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_guid_attribute.h)                   | class        | ![progress](/pictures/progress100.png) |
| [assembly_identifier_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_identifier_attribute.h)       | class        | ![progress](/pictures/progress100.png) |
| [assembly_name_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_name_attribute.h)                   | class        | ![progress](/pictures/progress100.png) |
| [assembly_product_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_product_attribute.h)             | class        | ![progress](/pictures/progress100.png) |
| [assembly_title_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_title_attribute.h)                 | class        | ![progress](/pictures/progress100.png) |
| [assembly_trademark_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_trademark_attribute.h)         | class        | ![progress](/pictures/progress100.png) |
| [assembly_version_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_version_attribute.h)             | class        | ![progress](/pictures/progress100.png) |

## xtd::security

| Name                                                                                                              | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [secure_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/security/secure_string.h) | all          | ![progress](/pictures/progress100.png) |

## xtd::text

| Name                                                                                                                                             | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------ | ------------ | -------------------------------------- |
| [string_builder](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/text/string_builder)                                    | all          | ![progress](/pictures/progress0.png)   |

## xtd::threading

| Name                                                                                                                                                                 | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [abandoned_mutex_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/abandoned_mutex_exception.h)                           | exception    | ![progress](/pictures/progress0.png)   |
| [auto_reset_event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/auto_reset_event.h)                                             | class        | ![progress](/pictures/progress0.png)   |
| [event_reset_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/event_reset_mode.h)                                             | enumeration  | ![progress](/pictures/progress0.png)   |
| [event_wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/event_wait_handle.h)                                           | class        | ![progress](/pictures/progress0.png)   |
| [interlocked](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/interlocked.h)                                                       | class        | ![progress](/pictures/progress100.png) |
| [lock_recursion_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/lock_recursion_exception.h)                             | exception    | ![progress](/pictures/progress0.png)   |
| [manual_reset_event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/manual_reset_event.h)                                         | class        | ![progress](/pictures/progress0.png)   |
| [monitor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/monitor.h)                                                               | class        | ![progress](/pictures/progress0.png)   |
| [mutex](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/mutex.h)                                                                   | class        | ![progress](/pictures/progress75.png)  |
| [registered_wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/registered_wait_handle.h)                                 | class        | ![progress](/pictures/progress0.png)   |
| [synchronization_lock_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/synchronization_lock_exception.h)                 | exception    | ![progress](/pictures/progress0.png)   |
| [thread](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread.h)                                                                 | class        | ![progress](/pictures/progress50.png)  |
| [thread_abort_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_abort_exception.h)                                 | exception    | ![progress](/pictures/progress100.png) |
| [thread_interrupted_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_interrupted_exception.h)                     | exception    | ![progress](/pictures/progress100.png) |
| [thread_local\<T\>](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_local.h)                                                | class        | ![progress](/pictures/progress0.png)   |
| [thread_pool](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_pool.h)                                                       | class        | ![progress](/pictures/progress0.png)   |
| [thread_priority](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_priority.h)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [thread_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_state.h)                                                     | enumeration  | ![progress](/pictures/progress100.png) | 
| [thread_state_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_state_exception.h)                                 | exception    | ![progress](/pictures/progress100.png) |
| [timeout](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timeout.h)                                                               | class        | ![progress](/pictures/progress100.png) |
| [timer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timer.h)                                                                   | class        | ![progress](/pictures/progress0.png)   |
| [timer_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timer_callback.h)                                                 | delegate     | ![progress](/pictures/progress0.png)   |
| [wait_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_callback.h)                                                   | delegate     | ![progress](/pictures/progress0.png)   |
| [wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_handle.h)                                                       | class        | ![progress](/pictures/progress100.png) |
| [wait_handle_cannot_be_opened_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_handle_cannot_be_opened_exception.h) | exception    | ![progress](/pictures/progress0.png)   |
| [wait_or_timer_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_or_timer_callback.h)                                 | delegate     | ![progress](/pictures/progress0.png)   |

## xtd::timers

| Name                                                                                                                            | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [elapsed_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/elapsed_event_args.h)       | class        | ![progress](/pictures/progress0.png)   |
| [elapsed_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/elapsed_event_handler.h) | delegate     | ![progress](/pictures/progress0.png)   |
| [timer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/timer.h)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::web::css

| Name                                                                                                           | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [css_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/css_reader.h)     | class        | ![progress](/pictures/progress100.png) |
| [css_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/css_writer.h)     | class        | ![progress](/pictures/progress100.png) |
| [property](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/property.h)         | class        | ![progress](/pictures/progress100.png) |
| [property_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/property_map.h) | alias        | ![progress](/pictures/progress100.png) |
| [selector](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/selector.h)         | class        | ![progress](/pictures/progress100.png) |
| [selector_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/selector_map.h) | alias        | ![progress](/pictures/progress100.png) |

## See also

* [Development status](/docs/documentation/Development%20status)
* [Documentation](/docs/documentation)
