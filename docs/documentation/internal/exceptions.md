# Exceptions list (**Internal use only**)

## std

<br/>[std::exception](https://en.cppreference.com/w/cpp/error/exception)
<br/>├─ [std::bad_alloc](https://en.cppreference.com/w/cpp/memory/new/bad_alloc)
<br/>│  └─ [std::bad_array_new_length](https://en.cppreference.com/w/cpp/memory/new/bad_array_new_length)
<br/>├─ [std::bad_cast](https://en.cppreference.com/w/cpp/types/bad_cast)
<br/>│  └─ [std::bad_any_cast](https://en.cppreference.com/w/cpp/utility/any/bad_any_cast)
<br/>├─ [std::bad_exception](https://en.cppreference.com/w/cpp/error/bad_exception)
<br/>├─ [std::bad_expected_access](https://en.cppreference.com/w/cpp/utility/expected/bad_expected_access)
<br/>├─ [std::bad_function_call](https://en.cppreference.com/w/cpp/utility/functional/bad_function_call)
<br/>├─ [std::bad_optional_access](https://en.cppreference.com/w/cpp/utility/optional/bad_optional_access)
<br/>├─ [std::bad_typeid](https://en.cppreference.com/w/cpp/types/bad_typeid)
<br/>├─ [std::bad_variant_access](https://en.cppreference.com/w/cpp/utility/variant/bad_variant_access)
<br/>├─ [std::bad_weak_ptr](https://en.cppreference.com/w/cpp/memory/bad_weak_ptr)
<br/>├─ [std::logic_error](https://en.cppreference.com/w/cpp/error/logic_error)
<br/>│  ├─ [std::domain_error](https://en.cppreference.com/w/cpp/error/domain_error)
<br/>│  ├─ [std::future_error](https://en.cppreference.com/w/cpp/thread/future_error)
<br/>│  ├─ [std::invalid_argument](https://en.cppreference.com/w/cpp/error/invalid_argument)
<br/>│  ├─ [std::length_error](https://en.cppreference.com/w/cpp/error/length_error)
<br/>│  └─ [std::out_of_range](https://en.cppreference.com/w/cpp/error/out_of_range)
<br/>└─ [std::runtime_error](https://en.cppreference.com/w/cpp/error/runtime_error)
<br/>   ├─ [std::chrono::ambiguous_local_time](https://en.cppreference.com/w/cpp/chrono/ambiguous_local_time)
<br/>   ├─ [std::chrono::nonexistent_local_time](https://en.cppreference.com/w/cpp/chrono/nonexistent_local_time)
<br/>   ├─ [std::format_error](https://en.cppreference.com/w/cpp/utility/format/format_error)
<br/>   ├─ [std::overflow_error](https://en.cppreference.com/w/cpp/error/overflow_error)
<br/>   ├─ [std::range_error](https://en.cppreference.com/w/cpp/error/range_error)
<br/>   ├─ [std::regex_error](https://en.cppreference.com/w/cpp/regex/regex_error)
<br/>   ├─ [std::system_error](https://en.cppreference.com/w/cpp/error/system_error)
<br/>   │  ├─ [std::ios_base::failure](https://en.cppreference.com/w/cpp/io/ios_base/failure)
<br/>   │  └─ [std::filesystem::filesystem_error](https://en.cppreference.com/w/cpp/filesystem/filesystem_error)
<br/>   ├─ [std::underflow_error](https://en.cppreference.com/w/cpp/error/underflow_error)
<br/>   └─ [std::tx_exception](https://en.cppreference.com/w/cpp/error/tx_exception)

## xtd.core

<br/>[std::exception](https://en.cppreference.com/w/cpp/error/exception)
<br/>└─ [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html)
<br/>  └─ [xtd::system_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1system__exception.html)
<br/>     ├─ [xtd::access_violation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1access__violation__exception.html)
<br/>     ├─ [xtd::argument_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__exception.html)
<br/>     │  ├─ [xtd::argument_null_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__null__exception.html)
<br/>     │  └─ [xtd::argument_out_of_range_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1argument__out__of__range__exception.html)
<br/>     ├─ [xtd::arithmetic_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1arithmetic__exception.html)
<br/>     │  ├─ [xtd::divided_by_zero_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1divided__by__zero__exception.html)
<br/>     │  ├─ [xtd::not_finite_number_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1not__finite__number__exception.html)
<br/>     │  ├─ [xtd::overflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1overflow__exception.html)
<br/>     │  └─ [xtd::underflow_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1underflow__exception.html)
<br/>     ├─ [xtd::collections::key_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1collections_1_1key__not__found__exception.html)
<br/>     ├─ [xtd::domain_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1domain__exception.html)
<br/>     ├─ [xtd::format_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1format__exception.html)
<br/>     │  ├─ [xtd::io::file_format_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__format__exception.html)
<br/>     │  ├─ [xtd::net::cookie_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1cookie__exception.html)
<br/>     │  └─ [xtd::uri_format_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1uri__format__exception.html)
<br/>     ├─ [xtd::index_out_of_range_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1index__out__of__range__exception.html)
<br/>     ├─ [xtd::interrupt_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1interrupt__exception.html)
<br/>     ├─ [xtd::invalid_cast_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__cast__exception.html)
<br/>     ├─ [xtd::invalid_operation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__operation__exception.html)
<br/>     │  ├─ [xtd::net::protocol_violation_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1protocol__violation__exception.html)
<br/>     │  └─ [xtd::net::web_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1web__exception.html)
<br/>     ├─ [xtd::invalid_program_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1invalid__program__exception.html)
<br/>     ├─ [xtd::io::io_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1io__exception.html)
<br/>     │  ├─ [xtd::io::directory_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__not__found__exception.html)
<br/>     │  ├─ [xtd::io::drive_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1drive__not__found__exception.html)
<br/>     │  ├─ [xtd::io::end_of_stream_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1end__of__stream__exception.html)
<br/>     │  ├─ [xtd::io::file_load_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__load__exception.html)
<br/>     │  ├─ [xtd::io::file_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__not__found__exception.html)
<br/>     │  └─ [xtd::io::path_too_long_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1path__too__long__exception.html)
<br/>     ├─ [xtd::length_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1length__exception.html)
<br/>     ├─ [xtd::net::socket::socket_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1net_1_1sockets_1_1socket__exception.html)
<br/>     ├─ [xtd::not_implemented_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1not__implemented__exception.html)
<br/>     ├─ [xtd::not_supported_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1not__supported__exception.html)
<br/>     │  └─ [xtd::platform_not_supported_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1platform__not__supported__exception.html)  
<br/>     ├─ [xtd::null_pointer_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1null__pointer__exception.html)
<br/>     ├─ [xtd::object_closed_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1object__closed__exception.html)
<br/>     ├─ [xtd::operation_canceled_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1operation__canceled__exception.html)
<br/>     ├─ [xtd::out_of_memory_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1out__of__memory__exception.html)
<br/>     ├─ [xtd::rank_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1rank__exception.html)
<br/>     ├─ [xtd::security::security_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1security_1_1security__exception.html)
<br/>     ├─ [xtd::security::xml_syntax_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1security_1_1xml__syntax__exception.html)
<br/>     ├─ [xtd::software_termination_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1software__termination__exception.html)
<br/>     ├─ [xtd::threading::abandoned_mutex_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1abandoned__mutex__exception.html)
<br/>     ├─ [xtd::threading::barrier_post_phase_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1barrier__post__phase__exception.html)
<br/>     ├─ [xtd::threading::lock_recursion_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1lock__recursion__exception.html)
<br/>     ├─ [xtd::threading::semaphore_full_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1semaphore__full__exception.html)
<br/>     ├─ [xtd::threading::synchronization_lock_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1synchronization__lock__exception.html)
<br/>     ├─ [xtd::threading::thread_abort_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread__abort__exception.html)
<br/>     ├─ [xtd::threading::thread_interrupted_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread__interrupted__exception.html)
<br/>     ├─ [xtd::threading::thread_state_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1thread__state__exception.html)
<br/>     ├─ [xtd::threading::wait_handle_cannot_be_opened_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1threading_1_1wait__handle__cannot__be__opened__exception.html)
<br/>     ├─ [xtd::time_zone_not_found_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1time__zone__not__found__exception.html)
<br/>     ├─ [xtd::timeout_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1timeout__exception.html)
<br/>     ├─ [xtd::unauthorized_access_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1unauthorized__access__exception.html)
<br/>     └─ [xtd::uri_template_match_exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1uri__template__match__exception.html)

## xtd.tunit

<br/>[std::exception](https://en.cppreference.com/w/cpp/error/exception)
<br/>└─ [xtd::exception](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1exception.html)
<br/>  ├─ [xtd::tunit::abort_error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1abort__error.html)
<br/>  ├─ [xtd::tunit::assert_error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1assert__error.html)
<br/>  └─ [xtd::tunit::ignore_error](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1tunit_1_1ignore__error.html)

## mscorelib (.Net Framework)

<br/>[System.Exception](https://learn.microsoft.com/en-us/dotnet/api/system.exception?view=net-8.0)
<br/>├─ [System.AggregateException](https://learn.microsoft.com/en-us/dotnet/api/system.aggregateexception?view=net-8.0)
<br/>├─ [System.ApplicationException](https://learn.microsoft.com/en-us/dotnet/api/system.applicationexception?view=net-8.0)
<br/>│  └─ [System.Threading.WaitHandleCannotBeOpenedException](https://learn.microsoft.com/en-us/dotnet/api/system.threading.waithandlecannotbeopenedexception?view=net-8.0)
<br/>├─ [System.InvalidTimeZoneException](https://learn.microsoft.com/en-us/dotnet/api/system.invalidtimezoneexception?view=net-8.0)
<br/>├─ [System.Threading.LockRecursionException](https://learn.microsoft.com/en-us/dotnet/api/system.threading.lockrecursionexception?view=net-8.0)
<br/>└─ [System.SystemException](https://learn.microsoft.com/en-us/dotnet/api/system.systemexception?view=net-8.0)
<br/>  ├─ [System.Threading.AbandonedMutexException](https://learn.microsoft.com/en-us/dotnet/api/system.threading.abandonedmutexexception?view=net-8.0)
<br/>  ├─ [System.AccessViolationException](https://learn.microsoft.com/en-us/dotnet/api/system.accessviolationexception?view=net-8.0)
<br/>  ├─ [System.AppDomainUnloadedException](https://learn.microsoft.com/en-us/dotnet/api/system.appdomainunloadedexception?view=net-8.0)
<br/>  ├─ [System.ArgumentException](https://learn.microsoft.com/en-us/dotnet/api/system.argumentexception?view=net-8.0)
<br/>  │  ├─ [System.ArgumentNullException](https://learn.microsoft.com/en-us/dotnet/api/system.argumentnullexception?view=net-8.0)
<br/>  │  ├─ [System.ArgumentOutOfRangeException](https://learn.microsoft.com/en-us/dotnet/api/system.argumentoutofrangeexception?view=net-8.0)
<br/>  │  └─ [System.DuplicateWaitException](https://learn.microsoft.com/en-us/dotnet/api/system.duplicatewaitobjectexception?view=net-8.0)
<br/>  ├─ [System.ArithmeticException](https://learn.microsoft.com/en-us/dotnet/api/system.arithmeticexception?view=net-8.0)
<br/>  │  ├─ [System.DivideByZeroException](https://learn.microsoft.com/en-us/dotnet/api/system.dividebyzeroexception?view=net-8.0)
<br/>  │  ├─ [System.NotFiniteNumberException](https://learn.microsoft.com/en-us/dotnet/api/system.notfinitenumberexception?view=net-8.0)
<br/>  │  └─ [System.OverflowException](https://learn.microsoft.com/en-us/dotnet/api/system.overflowexception?view=net-8.0)
<br/>  ├─ [System.ArrayTypeMismatchException](https://learn.microsoft.com/en-us/dotnet/api/system.arraytypemismatchexception?view=net-8.0)
<br/>  ├─ [System.BadImageFormatException](https://learn.microsoft.com/en-us/dotnet/api/system.badimageformatexception?view=net-8.0)
<br/>  ├─ [System.CannotUnloadAppDomainException](https://learn.microsoft.com/en-us/dotnet/api/system.cannotunloadappdomainexception?view=net-8.0)
<br/>  ├─ [System.ContextMarshalException](https://learn.microsoft.com/en-us/dotnet/api/system.contextmarshalexception?view=net-8.0)
<br/>  ├─ [System.DataMissalignedException](https://learn.microsoft.com/en-us/dotnet/api/system.datamisalignedexception?view=net-8.0)
<br/>  ├─ [System.ExecutionEngineException](https://learn.microsoft.com/en-us/dotnet/api/system.executionengineexception?view=net-8.0)
<br/>  ├─ [System.FormatException](https://learn.microsoft.com/en-us/dotnet/api/system.formatexception?view=net-8.0)
<br/>  │  ├─ [System.IO.FileFormatException](https://learn.microsoft.com/en-us/dotnet/api/system.io.fileformatexception?view=net-8.0)
<br/>  │  ├─ [System.Net.CookieException](https://learn.microsoft.com/en-us/dotnet/api/system.net.cookieexception?view=net-8.0)
<br/>  │  ├─ [System.Reflection.CustomAttributeFormatException](https://learn.microsoft.com/en-us/dotnet/api/system.reflection.customattributeformatexception?view=net-8.0)
<br/>  │  └─ [System.UriFormatException](https://learn.microsoft.com/en-us/dotnet/api/system.uriformatexception?view=net-8.0)
<br/>  ├─ [System.Security.HostProtectionException](https://learn.microsoft.com/en-us/dotnet/api/system.security.hostprotectionexception?view=net-8.0)
<br/>  ├─ [System.IO.IOException](https://learn.microsoft.com/en-us/dotnet/api/system.io.ioexception?view=net-8.0)
<br/>  │  ├─ [System.IO.DirectoryNotFoundException](https://learn.microsoft.com/en-us/dotnet/api/system.io.directorynotfoundexception?view=net-8.0)
<br/>  │  ├─ [System.IO.DriveNotFoundException](https://learn.microsoft.com/en-us/dotnet/api/system.io.drivenotfoundexception?view=net-8.0)
<br/>  │  ├─ [System.IO.EndOfStreamException](https://learn.microsoft.com/en-us/dotnet/api/system.io.endofstreamexception?view=net-8.0)
<br/>  │  ├─ [System.IO.FileLoadException](https://learn.microsoft.com/en-us/dotnet/api/system.io.fileloadexception?view=net-8.0)
<br/>  │  ├─ [System.IO.FileNotFoundException](https://learn.microsoft.com/en-us/dotnet/api/system.io.filenotfoundexception?view=net-8.0)
<br/>  │  ├─ [System.IO.PathTooLongException](https://learn.microsoft.com/en-us/dotnet/api/system.io.pathtoolongexception?view=net-8.0)
<br/>  │  ├─ [System.IO.PipeException](https://learn.microsoft.com/en-us/dotnet/api/system.io.pipeexception?view=net-8.0)
<br/>  │  ├─ [System.Net.Http.HttpIOException](https://learn.microsoft.com/en-us/dotnet/api/system.net.http.httpioexception?view=net-8.0)
<br/>  │  └─ [System.Net.Quic.QuicException](https://learn.microsoft.com/en-us/dotnet/api/system.net.quic.quicexception?view=net-8.0)
<br/>  ├─ [System.IndexOutOfRangeException](https://learn.microsoft.com/en-us/dotnet/api/system.indexoutofrangeexception?view=net-8.0)
<br/>  ├─ InsufficientExecutionStackException
<br/>  ├─ InvalidCastException
<br/>  ├─ InvalidOperationException
<br/>  │  └─ ObjectDisposedException
<br/>  ├─ InvalidProgramException
<br/>  ├─ KeyNotFoundException
<br/>  ├─ MemberAccessException
<br/>  │  ├─ FieldAccessException
<br/>  │  ├─ MethodAccessException
<br/>  │  └─ MissingMemberException
<br/>  │     ├─ MissingFiledException
<br/>  │     └─ MissingMethodException
<br/>  ├─ MulticastNotSupportedException
<br/>  ├─ NotImplementedException
<br/>  ├─ NotSupportedException
<br/>  │  └─ PlatformNotSupportedException
<br/>  ├─ NullPointerException
<br/>  ├─ NullReferenceException
<br/>  ├─ OperationCanceledException
<br/>  ├─ OutOfMemoryException
<br/>  │  └─ InsufficientMemoryException
<br/>  ├─ RankException
<br/>  ├─ SecurityException
<br/>  ├─ SerializationException
<br/>  ├─ StackOverflowException
<br/>  ├─ SynchronizationLockException
<br/>  ├─ ThreadAbortException
<br/>  ├─ ThreadInterruptException
<br/>  ├─ ThreadStartException
<br/>  ├─ ThreadStateException
<br/>  ├─ TimeOutException
<br/>  ├─ TimeZoneNotFoundException
<br/>  ├─ TypeInitializationException
<br/>  ├─ TypeLoadException
<br/>  │  ├─ DllNotFoundException
<br/>  │  ├─ EntryPointNotFoundException
<br/>  │  └─ TypeAccessException
<br/>  ├─ TypeUnloadException
<br/>  ├─ UnauthorizedAccessException
<br/>  ├─ VerificationException
<br/>  └─ XmlSyntaxException
