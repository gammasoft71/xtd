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
* [xtd::net::websockets](#xtdnetweb_sockets)
* [xtd::reflection](#xtdreflection)
* [xtd::security](#xtdsecurity)
* [xtd::speech::synthesis](#xtdspeechsynthesis)
* [xtd::text](#xtdtext)
* [xtd::threading](#xtdthreading)
* [xtd::threading::tasks](#xtdthreadingtasks)
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

| Name                                                                                                                                                 | Type          | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------- | ------------- | -------------------------------------- |
| [abstract](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/abstract.hpp)                                                     | alias         | ![progress](/pictures/progress100.png) |
| [abstract_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/abstract_object.hpp)                                       | class         | ![progress](/pictures/progress100.png) |
| [access_violation_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/access_violation_exception.hpp)                 | exception     | ![progress](/pictures/progress100.png) |
| [action](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/action.hpp)                                                         | delegate      | ![progress](/pictures/progress100.png) |
| [architecture_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/architecture_id.hpp)                                       | enumeration   | ![progress](/pictures/progress100.png) |
| [argument_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_exception.hpp)                                 | exception     | ![progress](/pictures/progress100.png) |
| [argument_null_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_null_exception.hpp)                       | exception     | ![progress](/pictures/progress100.png) |
| [argument_out_of_range_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/argument_out_of_range_exception.hpp)       | exception     | ![progress](/pictures/progress100.png) |
| [arithmetic_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/arithmetic_exception.hpp)                             | exception     | ![progress](/pictures/progress100.png) |
| [as](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/as.hpp)                                                                 | operator      | ![progress](/pictures/progress100.png) |
| [async_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/async_callback.hpp)                                         | delegate      | ![progress](/pictures/progress100.png) |
| [attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/attribute.hpp)                                                   | class         | ![progress](/pictures/progress100.png) |
| [background_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/background_color.hpp)                                     | iomanip       | ![progress](/pictures/progress100.png) |
| [beep](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/beep.hpp)                                                             | iomanip       | ![progress](/pictures/progress100.png) |
| [bit_converter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/bit_converter.hpp)                                           | static class  | ![progress](/pictures/progress100.png) |
| [block_scope_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/block_scope.hpp)                                              | keyword       | ![progress](/pictures/progress100.png) |
| [boolean_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/boolean_object.hpp)                                         | class         | ![progress](/pictures/progress100.png) |
| [box](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/box.hpp)                                                               | class         | ![progress](/pictures/progress100.png) |
| [box_char](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/box_char.hpp)                                                     | class         | ![progress](/pictures/progress100.png) |
| [box_floating_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/box_floating_point.hpp)                                 | class         | ![progress](/pictures/progress100.png) |
| [box_integer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/box_integer.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [boxing](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/boxing.hpp)                                                         | class         | ![progress](/pictures/progress100.png) |
| [build_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/build_type.hpp)                                                 | enumeration   | ![progress](/pictures/progress100.png) |
| [byte_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/byte_object.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [cdebug](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cdebug.hpp)                                                         | object        | ![progress](/pictures/progress100.png) |
| [char16_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/char16_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [char32_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/char32_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [char8_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/char8_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [char_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/char_object.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [cnull](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cnull.hpp)                                                           | object        | ![progress](/pictures/progress100.png) |
| [compiler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/compiler.hpp)                                                     | class         | ![progress](/pictures/progress100.png) |
| [compiler_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/compiler_id.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [console](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console.hpp)                                                       | static class  | ![progress](/pictures/progress100.png) |
| [console_cancel_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_cancel_event_args.hpp)                   | class         | ![progress](/pictures/progress100.png) |
| [console_cancel_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_cancel_event_handler.hpp)             | delegate      | ![progress](/pictures/progress100.png) |
| [console_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_color.hpp)                                           | enumeration   | ![progress](/pictures/progress100.png) |
| [console_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_key.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [console_key_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_key_info.hpp)                                     | class         | ![progress](/pictures/progress100.png) |
| [console_modifiers](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_modifiers.hpp)                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [console_special_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/console_special_key.hpp)                               | enumeration   | ![progress](/pictures/progress100.png) |
| [convert](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert.hpp)                                                       | static class  | ![progress](/pictures/progress100.png) |
| [convert_pointer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert_pointer.hpp)                                       | static class  | ![progress](/pictures/progress100.png) |
| [convert_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/convert_string.hpp)                                         | static class  | ![progress](/pictures/progress100.png) |
| [cpp_language](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/cpp_language.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [ctrace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ctrace.hpp)                                                         | object        | ![progress](/pictures/progress100.png) |
| [date_time](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/date_time.hpp)                                                   | struct        | ![progress](/pictures/progress100.png) |
| [date_time_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/date_time_kind.hpp)                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [day_of_week](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/day_of_week.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [debugstreambuf](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/debugstreambuf.hpp)                                         | class         | ![progress](/pictures/progress100.png) |
| [delegate](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/delegate.hpp)                                                     | delegate      | ![progress](/pictures/progress100.png) |
| [distribution](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/distribution.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [divided_by_zero_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/dividde_by_zero_exception.hpp)                   | exception     | ![progress](/pictures/progress100.png) |
| [domain_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/domain_exception.hpp)                                     | exception     | ![progress](/pictures/progress100.png) |
| [double_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/double_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [enum](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum.hpp)                                                             | class         | ![progress](/pictures/progress100.png) |
| [enum_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_attribute.hpp)                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [enum_class](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_class.hpp)                                                 | class         | ![progress](/pictures/progress100.png) |
| [enum_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_collection.hpp)                                       | alias         | ![progress](/pictures/progress100.png) |
| [enum_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_object.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [enum_register](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_register.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [enum_set_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_set_attribute.hpp)                                 | class         | ![progress](/pictures/progress100.png) |
| [enum_struct](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/enum_struct.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [environment](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/environment.hpp)                                               | static class  | ![progress](/pictures/progress100.png) |
| [environment_variable_target](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/environment_variable_target.hpp)               | enumeration   | ![progress](/pictures/progress100.png) |
| [event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event.hpp)                                                           | event         | ![progress](/pictures/progress100.png) |
| [event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event_args.hpp)                                                 | class         | ![progress](/pictures/progress100.png) |
| [event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/event_handler.hpp)                                           | event handler | ![progress](/pictures/progress100.png) |
| [exit_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/exit_mode.hpp)                                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [exit_status](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/exit_status.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [flags_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/flags_attribute.hpp)                                       | keyword       | ![progress](/pictures/progress100.png) |
| [foreground_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/foreground_color.hpp)                                     | iomanip       | ![progress](/pictures/progress100.png) |
| [format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/format_exception.hpp)                                     | exception     | ![progress](/pictures/progress100.png) |
| [func](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/func.hpp)                                                             | delegate      | ![progress](/pictures/progress100.png) |
| [guid](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/guid.hpp)                                                             | struct        | ![progress](/pictures/progress100.png) |
| [iasync_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iasync_result.hpp)                                           | interface     | ![progress](/pictures/progress100.png) |
| [icomparable](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/icomparable.hpp)                                               | interface     | ![progress](/pictures/progress100.png) |
| [iequatable](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iequatable.hpp)                                                 | interface     | ![progress](/pictures/progress100.png) |
| [index_out_of_range_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/index_out_of_range_exception.hpp)             | exception     | ![progress](/pictures/progress100.png) |
| [int16_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/int16_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [int32_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/int32_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [int64_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/int64_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [interface_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/interface.hpp)                                                  | keyword       | ![progress](/pictures/progress100.png) |
| [interrupt_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_cast_exception.hpp)                            | exception     | ![progress](/pictures/progress100.png) |
| [intptr_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/intptr_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [invalid_cast_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_cast_exception.hpp)                         | exception     | ![progress](/pictures/progress100.png) |
| [invalid_operation_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_operation_exception.hpp)               | exception     | ![progress](/pictures/progress100.png) |
| [invalid_program_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/invalid_program_exception.hpp)                   | exception     | ![progress](/pictures/progress100.png) |
| [iobservable](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iobservable.hpp)                                               | interface     | ![progress](/pictures/progress100.png) |
| [iobserver](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/iobserver.hpp)                                                   | interface     | ![progress](/pictures/progress100.png) |
| [is](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/is.hpp)                                                                 | operators     | ![progress](/pictures/progress100.png) |
| [isynchronize_invoke](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/isynchronize_invoke.hpp)                               | interface     | ![progress](/pictures/progress100.png) |
| [language_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/language_id.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [length_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/length_exception.hpp)                                     | exception     | ![progress](/pictures/progress100.png) |
| [literals](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/literals.hpp)                                                     | operators     | ![progress](/pictures/progress100.png) |
| [lock_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/lock.hpp)                                                            | keyword       | ![progress](/pictures/progress100.png) |
| [math](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/math.hpp)                                                             | static class  | ![progress](/pictures/progress100.png) |
| [month_of_year](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/month_of_year.hpp)                                           | enumeration   | ![progress](/pictures/progress100.png) |
| [nameof_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/nameof.hpp)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [not_finite_number_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_finite_number_exception.hpp)               | exception     | ![progress](/pictures/progress100.png) |
| [not_implemented_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_implemented_exception.hpp)                   | exception     | ![progress](/pictures/progress100.png) |
| [not_supported_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/not_supported_exception.hpp)                       | exception     | ![progress](/pictures/progress100.png) |
| [null_pointer_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/null_pointer_exception.hpp)                         | exception     | ![progress](/pictures/progress100.png) |
| [number_styles](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/number_styles.hpp)                                           | enumeration   | ![progress](/pictures/progress100.png) |
| [object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/object.hpp)                                                         | class         | ![progress](/pictures/progress100.png) |
| [object_closed_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/object_closed_exception.hpp)                       | exception     | ![progress](/pictures/progress100.png) |
| [operating_system](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/operating_system.hpp)                                     | class         | ![progress](/pictures/progress100.png) |
| [operation_canceled_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/operation_canceled_exception.hpp)             | exception     | ![progress](/pictures/progress100.png) |
| [overflow_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/overflow_exception.hpp)                                 | exception     | ![progress](/pictures/progress100.png) |
| [overload](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/overload.hpp)                                                     | class         | ![progress](/pictures/progress100.png) |
| [parse](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/parse.hpp)                                                           | operators     | ![progress](/pictures/progress100.png) |
| [platform_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/platform_id.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [platform_not_supported_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/platform_not_supported_exception.hpp)     | class         | ![progress](/pictures/progress100.png) |
| [predicate](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/predicate.hpp)                                                   | delegate      | ![progress](/pictures/progress100.png) |
| [processor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/processor.hpp)                                                   | class         | ![progress](/pictures/progress100.png) |
| [program_exit_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/program_exit_event_args.hpp)                       | class         | ![progress](/pictures/progress100.png) |
| [program_exit_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/program_exit_event_handler.hpp)                 | delegate      | ![progress](/pictures/progress100.png) |
| [random](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/random.hpp)                                                         | class         | ![progress](/pictures/progress100.png) |
| [register_any_stringer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/register_any_stringer.hpp)                           | class         | ![progress](/pictures/progress100.png) |
| [reset_color](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reset_color.hpp)                                               | iomanip       | ![progress](/pictures/progress100.png) |
| [sbyte_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/sbyte_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [signal](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/signal.hpp)                                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [signal_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/signal_event_args.hpp)                                   | class         | ![progress](/pictures/progress100.png) |
| [signal_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/signal_event_handler.hpp)                             | delegate      | ![progress](/pictures/progress100.png) |
| [single_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/single_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [size_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/size_object.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [slong_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/slong_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [software_termination_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/software_termination_exception.hpp)         | exception     | ![progress](/pictures/progress100.png) |
| [startup_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/startup.hpp)                                                      | keyword       | ![progress](/pictures/progress100.png) |
| [static_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/static.hpp)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [static_object_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/static.hpp)                                                 | keyword       | ![progress](/pictures/progress100.png) |
| [string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/string.hpp)                                                       | class         | ![progress](/pictures/progress100.png) |
| [string_comparison](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/string_comparison.hpp)                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [string_split_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/string_split_options.hpp)                             | enumeration   | ![progress](/pictures/progress100.png) |
| [system_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/system_exception.hpp)                                     | exception     | ![progress](/pictures/progress100.png) |
| [system_exception_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/system_exception.hpp)                                    | keyword       | ![progress](/pictures/progress100.png) |
| [target_id](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/target_id.hpp)                                                   | enumeration   | ![progress](/pictures/progress100.png) |
| [target_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/target_type.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [tick](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/tick.hpp)                                                             | class         | ![progress](/pictures/progress100.png) |
| [ticks](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ticks.hpp)                                                           | class         | ![progress](/pictures/progress100.png) |
| [time_span](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/time_span.hpp)                                                   | class         | ![progress](/pictures/progress100.png) |
| [time_zone_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/time_zone_info.hpp)                                         | class         | ![progress](/pictures/progress50.png)  |
| [time_time_zone_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/time_time_zone_not_found_exception.hpp) | exception     | ![progress](/pictures/progress100.png) |
| [timeout_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timeout_exception.hpp)                                   | exception     | ![progress](/pictures/progress100.png) |
| [to_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/to_string.hpp)                                                   | operators     | ![progress](/pictures/progress100.png) |
| [toolkit](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/toolkit.hpp)                                                       | class         | ![progress](/pictures/progress100.png) |
| [tracestreambuf](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/tracestreambuf.hpp)                                         | class         | ![progress](/pictures/progress100.png) |
| [translator](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/translator.hpp)                                                 | class         | ![progress](/pictures/progress100.png) |
| [typeof_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/typeof.hpp)                                                        | class         | ![progress](/pictures/progress100.png) |
| [type_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/type_object.hpp)                                               | class         | ![progress](/pictures/progress100.png) |
| [types](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/types.hpp)                                                           | aliases       | ![progress](/pictures/progress100.png) |
| [uint16_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uint16_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [uint32_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uint32_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [uint64_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uint64_object.hpp)                                           | class         | ![progress](/pictures/progress100.png) |
| [uintptr_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uintptr_object.hpp)                                         | class         | ![progress](/pictures/progress100.png) |
| [ulong_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/ulong_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [unauthorized_access_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/unauthorized_access_exception.hpp)           | exception     | ![progress](/pictures/progress100.png) |
| [unboxing](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/unboxing.hpp)                                                     | class         | ![progress](/pictures/progress100.png) |
| [underflow_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/underflow_exception.hpp)                               | exception     | ![progress](/pictures/progress100.png) |
| [unregister_any_stringer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/unregister_any_stringer.hpp)                       | class         | ![progress](/pictures/progress100.png) |
| [unused_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/unused.hpp)                                                        | keyword       | ![progress](/pictures/progress100.png) |
| [uri](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri.hpp)                                                               | class         | ![progress](/pictures/progress100.png) |
| [uri_components](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_components.hpp)                                         | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_format](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_format.hpp)                                                 | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_format_exception.hpp)                             | exception     | ![progress](/pictures/progress100.png) |
| [uri_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_kind.hpp)                                                     | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_partial](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_partial.hpp)                                               | enumeration   | ![progress](/pictures/progress100.png) |
| [uri_template_match_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/uri_template_match_exception.hpp)             | exception     | ![progress](/pictures/progress100.png) |
| [using_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/using.hpp)                                                          | keyword       | ![progress](/pictures/progress100.png) |
| [version](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/version.hpp)                                                       | class         | ![progress](/pictures/progress100.png) |
| [wchar_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/wchar_object.hpp)                                             | class         | ![progress](/pictures/progress100.png) |
| [xml_syntax_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/xml_syntax_exception.hpp)                             | exception     | ![progress](/pictures/progress100.png) |

## xtd::collections

| Name                                                                                                                                       | Type          | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------ | ------------- | -------------------------------------- |
| [any_pair](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/any_pair.hpp)                               | alias         | ![progress](/pictures/progress100.png) |
| [key_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/key_not_found_exception.hpp) | class         | ![progress](/pictures/progress100.png) |
| [vector_list](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/vector_list.hpp)                         | alias         | ![progress](/pictures/progress100.png) |

## xtd::collections::specialized

| Name                                                                                                                               | Type          | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------- | ------------- | -------------------------------------- |
| [string_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_map.hpp)       | alias         | ![progress](/pictures/progress100.png) |
| [string_pair](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_pair.hpp)     | alias         | ![progress](/pictures/progress100.png) |
| [string_vector](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/collections/specialized/string_vector.hpp) | alias         | ![progress](/pictures/progress100.png) |

## xtd::diagnostics

| Name                                                                                                                                               | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [assert_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/assert.hpp)                                          | keyword      | ![progress](/pictures/progress100.png) |
| [assert_dialog_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/assert_dialog_result.hpp)               | enumeration  | ![progress](/pictures/progress100.png) |
| [boolean_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/boolean_switch.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [console_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/console_trace_listener.hpp)           | class        | ![progress](/pictures/progress100.png) |
| [data_received_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/data_received_event_args.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [data_received_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/data_received_event_handler.hpp) | delegate     | ![progress](/pictures/progress100.png) |
| [debug](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/debug.hpp)                                             | static class | ![progress](/pictures/progress100.png) |
| [debug_break_](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/debug_break.hpp)                                | keyword      | ![progress](/pictures/progress100.png) |
| [debugger](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/debugger.hpp)                                       | static class | ![progress](/pictures/progress100.png) |
| [default_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/default_trace_listener.hpp)           | class        | ![progress](/pictures/progress100.png) |
| [event_type_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/event_type_filter.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [ostream_trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/ostream_trace_listener.hpp)           | class        | ![progress](/pictures/progress100.png) |
| [process](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process.hpp)                                         | class        | ![progress](/pictures/progress75.png)  |
| [process_priority_class](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_priority_class.hpp)           | enumeration  | ![progress](/pictures/progress100.png) |
| [process_start_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_start_info.hpp)                   | class        | ![progress](/pictures/progress100.png) |
| [process_window_style](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/process_window_style.hpp)               | enumeration  | ![progress](/pictures/progress100.png) |
| [source_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_filter.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [source_levels](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_levels.hpp)                             | enumeration  | ![progress](/pictures/progress100.png) |
| [source_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/source_switch.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [stack_frame](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_frame.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [stack_trace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stack_trace.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [stopwatch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/stopwatch.hpp)                                     | class        | ![progress](/pictures/progress100.png) |
| [switch_base](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/switch_base.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [trace](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace.hpp)                                             | static class | ![progress](/pictures/progress100.png) |
| [trace_event_cache](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_event_cache.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [trace_event_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_event_type.hpp)                       | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_filter](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_filter.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [trace_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_level.hpp)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_listener.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [trace_listener_collection](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_listener_collection.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [trace_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_options.hpp)                             | enumeration  | ![progress](/pictures/progress100.png) |
| [trace_source](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_source.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [trace_switch](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/diagnostics/trace_switch.hpp)                               | class        | ![progress](/pictures/progress100.png) |

## xtd::io

| Name                                                                                                                                               | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [binary_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/binary_reader.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [binary_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/binary_writer.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [directory](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory.hpp)                                              | static class | ![progress](/pictures/progress100.png) |
| [directory_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory_info.hpp)                                    | class        | ![progress](/pictures/progress100.png) |
| [directory_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/directory_not_found_exception.hpp)      | exception    | ![progress](/pictures/progress100.png) |
| [drive_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/drive_info.hpp)                                            | class        | ![progress](/pictures/progress100.png) |
| [drive_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/drive_not_found_exception.hpp)              | exception    | ![progress](/pictures/progress100.png) |
| [drive_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/drive_type.hpp)                                            | enumeration  | ![progress](/pictures/progress100.png) |
| [end_of_stream_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/end_of_stream_exception.hpp)                  | exception    | ![progress](/pictures/progress100.png) |
| [file](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file.hpp)                                                        | static class | ![progress](/pictures/progress100.png) |
| [file_attributes](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_attributes.hpp)                                  | enumeration  | ![progress](/pictures/progress100.png) |
| [file_format_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_format_exception.hpp)                      | exception    | ![progress](/pictures/progress100.png) |
| [file_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_info.hpp)                                              | class        | ![progress](/pictures/progress100.png) |
| [file_load_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_load_exception.hpp)                          | exception    | ![progress](/pictures/progress100.png) |
| [file_not_found_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_not_found_exception.hpp)                | exception    | ![progress](/pictures/progress100.png) |
| [file_permissions](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_permissions.hpp)                                | enumeration  | ![progress](/pictures/progress100.png) |
| [file_system_info](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_system_info.hpp)                                | class        | ![progress](/pictures/progress100.png) |
| [file_system_watcher](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/file_system_watcher.hpp)                          | class        | ![progress](/pictures/progress0.png)   |
| [io_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/io_exception.hpp)                                        | exception    | ![progress](/pictures/progress100.png) |
| [path](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/path.hpp)                                                        | static class | ![progress](/pictures/progress100.png) |
| [path_too_long_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/path_too_long_exception.hpp)                  | exception    | ![progress](/pictures/progress100.png) |
| [search_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/search_option.hpp)                                      | enumeration  | ![progress](/pictures/progress100.png) |
| [stream_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/stream_reader.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [stream_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/stream_writer.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [string_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/string_reader.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [string_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/string_writer.hpp)                                      | class        | ![progress](/pictures/progress100.png) |
| [text_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/text_reader.hpp)                                          | class        | ![progress](/pictures/progress100.png) |
| [text_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/text_writer.hpp)                                          | class        | ![progress](/pictures/progress100.png) |

## xtd::io::memory_mapped_files

| Name                                                                                                                                                          | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [memory_mapped_file](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file.hpp)                   | class        | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_access](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_access.hpp)     | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_options.hpp)   | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_file_rights](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_file_rights.hpp)     | enumeration  | ![progress](/pictures/progress0.png)   |
| [memory_mapped_view_accessor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_view_accessor.hpp) | class        | ![progress](/pictures/progress0.png)   |
| [memory_mapped_view_stream](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/io/memory_mapped_files/memory_mapped_view_stream.hpp)     | class        | ![progress](/pictures/progress0.png)   |

## xtd::media

| Name                                                                                                                                               | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [sound_player](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/sound_player.hpp)                                     | class        | ![progress](/pictures/progress0.png)   |
| [system_sound](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/system_sound.hpp)                                     | class        | ![progress](/pictures/progress100.png) |
| [system_sounds](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/media/system_sounds.hpp)                                   | static class | ![progress](/pictures/progress100.png) |

## xtd::microsoft::win32

| Name                                                                                                                                                       | Type         | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [registry](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry.hpp)                                           | class        | ![progress](/pictures/progress0.png)   |
| [registry_hive](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_hive.hpp)                                 | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_key](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_key.hpp)                                   | class        | ![progress](/pictures/progress0.png)   |
| [registry_key_permission_check](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_key_permission_check.hpp) | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_options.hpp)                           | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_value_kind](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_value_kind.hpp)                     | enumeration  | ![progress](/pictures/progress0.png)   |
| [registry_value_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_value_options.hpp)               | enumeration  | ![progress](/pictures/progress0.png)   |
| [Registry_view](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/microsoft/win32/registry_view.hpp)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net

| Name                                                                                                                                         | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [cookie_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/cookie_exception.hpp)                         | exception    | ![progress](/pictures/progress100.png) |
| [dns](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/dns.hpp)                                                   | static class | ![progress](/pictures/progress100.png) |
| [dns_end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/dns_end_point.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/end_point.hpp)                                       | class        | ![progress](/pictures/progress100.png) |
| [ip_address](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_address.hpp)                                     | class        | ![progress](/pictures/progress100.png) |
| [ip_end_point](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_end_point.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [ip_host_entry](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/ip_host_entry.hpp)                               | class        | ![progress](/pictures/progress100.png) |
| [network_credential](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/network_credential.hpp)                     | class        | ![progress](/pictures/progress100.png) |
| [protocol_violation_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/protocol_violation_exception.hpp) | exception    | ![progress](/pictures/progress100.png) |
| [socket_address](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/socket_address.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [web_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_exception.hpp)                               | exception    | ![progress](/pictures/progress100.png) |
| [web_request](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_end_point.hpp)                                 | class        | ![progress](/pictures/progress0.png)   |
| [web_request_methods](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_request_methods.hpp)                   | static class | ![progress](/pictures/progress0.png)   |
| [web_response](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/web_response.hpp)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net::sockets

| Name                                                                                                                                                             | Type         | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [address_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/address_family.hpp)                                         | enumeration  | ![progress](/pictures/progress100.png) |
| [io_control_code](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/io_control_code.hpp)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [ip_packet_information](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_packet_information.hpp)                           | class        | ![progress](/pictures/progress100.png) |
| [ip_protection_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_protection_level.hpp)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [ip_v6_multicast_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/ip_v6_multicast_option.hpp)                         | class        | ![progress](/pictures/progress100.png) |
| [linger_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/linger_option.hpp)                                           | class        | ![progress](/pictures/progress100.png) |
| [multicast_option](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/multicast_option.hpp)                                     | class        | ![progress](/pictures/progress100.png) |
| [network_stream](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/network_stream.hpp)                                         | class        | ![progress](/pictures/progress100.png) |
| [protocol_family](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/protocol_family.hpp)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [protocol_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/protocol_type.hpp)                                           | enumeration  | ![progress](/pictures/progress100.png) |
| [select_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/select_mode.hpp)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [send_packets_element](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/send_packets_element.hpp)                             | class        | ![progress](/pictures/progress100.png) |
| [socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket.hpp)                                                         | class        | ![progress](/pictures/progress75.png)  |
| [socket_async_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_async_event_args.hpp)                       | class        | ![progress](/pictures/progress100.png) |
| [socket_async_operation](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_async_operation.hpp)                         | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_error](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_error.hpp)                                             | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_exception.hpp)                                     | exception    | ![progress](/pictures/progress100.png) |
| [socket_flags](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_flags.hpp)                                             | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_information](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_information.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [socket_information_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_information_options.hpp)                 | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_option_level](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_option_level.hpp)                               | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_option_name](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_option_name.hpp)                                 | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_receive_from_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_receive_from_result.hpp)                 | class        | ![progress](/pictures/progress0.png)   |
| [socket_receive_message_from_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_receive_message_from_result.hpp) | class        | ![progress](/pictures/progress0.png)   |
| [socket_shutdown](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_shutdown.hpp)                                       | enumeration  | ![progress](/pictures/progress100.png) |
| [socket_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/socket_type.hpp)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [tcp_client](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/tcp_client.hpp)                                                 | class        | ![progress](/pictures/progress75.png)  |
| [tcp_listener](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/tcp_listener.hpp)                                             | class        | ![progress](/pictures/progress75.png)  |
| [transmit_file_options](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/transmit_file_options.hpp)                           | enumeration  | ![progress](/pictures/progress100.png) |
| [udp_client](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/udp_client.hpp)                                                 | class        | ![progress](/pictures/progress75.png)  |
| [udp_receive_result](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/sockets/udp_receive_result.hpp)                                 | class        | ![progress](/pictures/progress0.png)   |

## xtd::net::web_sockets

| Name                                                                                                                                          | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [client_web_socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/client_web_socket.hpp)             | class        | ![progress](/pictures/progress0.png)   |
| [web_socket](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket.hpp)                           | class        | ![progress](/pictures/progress0.png)   |
| [web_socket_close_status](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_close_status.hpp) | enumeration  | ![progress](/pictures/progress0.png)   |
| [web_socket_message_type](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_message_type.hpp) | enumeration  | ![progress](/pictures/progress0.png)   |
| [web_socket_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/net/websockets/web_socket_state.hpp)               | enumeration  | ![progress](/pictures/progress0.png)   |

## xtd::reflection

| Name                                                                                                                                                        | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [assembly](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly.hpp)                                                 | class        | ![progress](/pictures/progress100.png) |
| [assembly_company_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_company_attribute.hpp)             | class        | ![progress](/pictures/progress100.png) |
| [assembly_configuration_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_configuration_attribute.hpp) | class        | ![progress](/pictures/progress100.png) |
| [assembly_copyright_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_copyright_attribute.hpp)         | class        | ![progress](/pictures/progress100.png) |
| [assembly_description_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_description_attribute.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [assembly_file_version_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_file_version_attribute.hpp)   | class        | ![progress](/pictures/progress100.png) |
| [assembly_guid_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_guid_attribute.hpp)                   | class        | ![progress](/pictures/progress100.png) |
| [assembly_identifier_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_identifier_attribute.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [assembly_name_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_name_attribute.hpp)                   | class        | ![progress](/pictures/progress100.png) |
| [assembly_product_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_product_attribute.hpp)             | class        | ![progress](/pictures/progress100.png) |
| [assembly_title_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_title_attribute.hpp)                 | class        | ![progress](/pictures/progress100.png) |
| [assembly_trademark_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_trademark_attribute.hpp)         | class        | ![progress](/pictures/progress100.png) |
| [assembly_version_attribute](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/reflection/assembly_version_attribute.hpp)             | class        | ![progress](/pictures/progress100.png) |

## xtd::security

| Name                                                                                                                | Type         | Status                                 |
| ------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [secure_string](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/security/secure_string.hpp) | all          | ![progress](/pictures/progress100.png) |

## xtd::speech::synthesis

| Name                                                                                                                                                        | Type         | Status                                 |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [prompt](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/prompt.hpp)                                               | class        | ![progress](/pictures/progress100.png) |
| [prompt_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/prompt_event_args.hpp)                         | class        | ![progress](/pictures/progress100.png) |
| [speak_completed_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/speak_completed_event_args.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [speak_completed_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/speak_completed_event_handler.hpp) | delegate     | ![progress](/pictures/progress100.png) |
| [speak_started_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/speak_started_event_args.hpp)           | class        | ![progress](/pictures/progress100.png) |
| [speak_started_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/speak_started_event_handler.hpp)     | delegate     | ![progress](/pictures/progress100.png) |
| [speech_synthesizer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/speech_synthesizer.hpp)                       | class        | ![progress](/pictures/progress50.png)  |
| [state_changed_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/state_changed_event_args.hpp)           | class        | ![progress](/pictures/progress100.png) |
| [state_changed_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/state_changed_event_handler.hpp)     | delegate     | ![progress](/pictures/progress100.png) |
| [synthesizer_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/speech/synthesis/synthesizer_state.hpp)                         | enumeration  | ![progress](/pictures/progress100.png) |

## xtd::text

| Name                                                                                                                                               | Type         | Status                                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [string_builder](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/text/string_builder.hpp)                                  | class        | ![progress](/pictures/progress100.png) |

## xtd::threading

| Name                                                                                                                                                                   | Type         | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [barrier](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/barrier.hpp)                                                               | class        | ![progress](/pictures/progress100.png) |
| [barrier_post_phase_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/barrier_post_phase_exception.hpp)                     | exception    | ![progress](/pictures/progress100.png) |
| [abandoned_mutex_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/abandoned_mutex_exception.hpp)                           | exception    | ![progress](/pictures/progress100.png) |
| [auto_reset_event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/auto_reset_event.hpp)                                             | class        | ![progress](/pictures/progress100.png) |
| [cancellation_token](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/cancellation_token.hpp)                                         | class        | ![progress](/pictures/progress50.png)  |
| [cancellation_token_registration](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/cancellation_token_registration.hpp)               | class        | ![progress](/pictures/progress50.png)  |
| [cancellation_token_source](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/cancellation_token_source.hpp)                           | class        | ![progress](/pictures/progress50.png)  |
| [countdown_event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/countdown_event.hpp)                                               | class        | ![progress](/pictures/progress100.png) |
| [event_reset_mode](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/event_reset_mode.hpp)                                             | enumeration  | ![progress](/pictures/progress100.png) |
| [event_wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/event_wait_handle.hpp)                                           | class        | ![progress](/pictures/progress100.png) |
| [interlocked](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/interlocked.hpp)                                                       | class        | ![progress](/pictures/progress100.png) |
| [lock_recursion_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/lock_recursion_exception.hpp)                             | exception    | ![progress](/pictures/progress100.png) |
| [manual_reset_event](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/manual_reset_event.hpp)                                         | class        | ![progress](/pictures/progress100.png) |
| [monitor](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/monitor.hpp)                                                               | class        | ![progress](/pictures/progress100.png) |
| [mutex](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/mutex.hpp)                                                                   | class        | ![progress](/pictures/progress100.png) |
| [parameterized_thread_start](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/parameterized_thread_start.hpp)                         | delegate     | ![progress](/pictures/progress100.png) |
| [registered_wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/registered_wait_handle.hpp)                                 | class        | ![progress](/pictures/progress100.png) |
| [semaphore](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/semaphore.hpp)                                                           | class        | ![progress](/pictures/progress100.png) |
| [semaphore_full_execption](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/semaphore_full_execption.hpp)                             | exception    | ![progress](/pictures/progress100.png) |
| [spin_lock](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/spin_lock.hpp)                                                           | class        | ![progress](/pictures/progress100.png) |
| [synchronization_lock_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/synchronization_lock_exception.hpp)                 | exception    | ![progress](/pictures/progress100.png) |
| [thread](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread.hpp)                                                                 | class        | ![progress](/pictures/progress100.png) |
| [thread_abort_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_abort_exception.hpp)                                 | exception    | ![progress](/pictures/progress100.png) |
| [thread_interrupted_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_interrupted_exception.hpp)                     | exception    | ![progress](/pictures/progress100.png) |
| [thread_local_object](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_local_object.hpp)                                       | class        | ![progress](/pictures/progress100.png) |
| [thread_pool](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_pool.hpp)                                                       | class        | ![progress](/pictures/progress100.png) |
| [thread_priority](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_priority.hpp)                                               | enumeration  | ![progress](/pictures/progress100.png) |
| [thread_start](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_start.hpp)                                                     | delegate     | ![progress](/pictures/progress100.png) |
| [thread_state](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_state.hpp)                                                     | enumeration  | ![progress](/pictures/progress100.png) | 
| [thread_state_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/thread_state_exception.hpp)                                 | exception    | ![progress](/pictures/progress100.png) |
| [timeout](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timeout.hpp)                                                               | class        | ![progress](/pictures/progress100.png) |
| [timer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timer.hpp)                                                                   | class        | ![progress](/pictures/progress100.png) |
| [timer_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/timer_callback.hpp)                                                 | delegate     | ![progress](/pictures/progress100.png) |
| [wait_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_callback.hpp)                                                   | delegate     | ![progress](/pictures/progress100.png) |
| [wait_handle](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_handle.hpp)                                                       | class        | ![progress](/pictures/progress100.png) |
| [wait_handle_cannot_be_opened_exception](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_handle_cannot_be_opened_exception.hpp) | exception    | ![progress](/pictures/progress100.png) |
| [wait_or_timer_callback](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/wait_or_timer_callback.hpp)                                 | delegate     | ![progress](/pictures/progress100.png) |

## xtd::threading::tasks

| Name                                                                                                                                                                   | Type         | Status                                 |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [itask](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/itask.hpp)                                                                   | interface    | ![progress](/pictures/progress0.png)   |
| [parallel](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/parallel.hpp)                                                             | class        | ![progress](/pictures/progress0.png)   |
| [task](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/task.hpp)                                                                     | class        | ![progress](/pictures/progress0.png)   |
| [task_factory](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/task_factory.hpp)                                                     | class        | ![progress](/pictures/progress0.png)   |
| [task_status](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/threading/task_status.hpp)                                                       | enumeration  | ![progress](/pictures/progress0.png)   |

## xtd::timers

| Name                                                                                                                              | Type         | Status                                 |
| --------------------------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [elapsed_event_args](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/elapsed_event_args.hpp)       | class        | ![progress](/pictures/progress100.png) |
| [elapsed_event_handler](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/elapsed_event_handler.hpp) | delegate     | ![progress](/pictures/progress100.png) |
| [timer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/timers/timer.hpp)                                 | class        | ![progress](/pictures/progress100.png) |

## xtd::web::css

| Name                                                                                                             | Type         | Status                                 |
| ---------------------------------------------------------------------------------------------------------------- | ------------ | -------------------------------------- |
| [css_reader](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/css_reader.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [css_writer](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/css_writer.hpp)     | class        | ![progress](/pictures/progress100.png) |
| [property](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/property.hpp)         | class        | ![progress](/pictures/progress100.png) |
| [property_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/property_map.hpp) | alias        | ![progress](/pictures/progress100.png) |
| [selector](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/selector.hpp)         | class        | ![progress](/pictures/progress100.png) |
| [selector_map](https://github.com/gammasoft71/xtd/tree/master/src/xtd.core/include/xtd/web/css/selector_map.hpp) | alias        | ![progress](/pictures/progress100.png) |

## See also

* [Development status](/docs/documentation/development_status)
* [Documentation](/docs/documentation)
