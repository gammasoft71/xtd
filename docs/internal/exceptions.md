# Exceptions list (**Internal use only**)

## std

* exception
  * logic_error
    * invalid_argument
    * domain_error
    * length_error
    * out_of_range
  * runtime_error
    * range_error
    * overflow_error
    * underflow_error
    * system_error
  * tx_error

## xtd

* excpetion
  * system_exception (*)
    * aggregate_exception
    * argument_exception (*)
      * argument_null_exception (*)
      * argument_out_of_range_exception (*)
    * arithmetic_exception (*)
      * divide_by_zero_exception (*)
      * not_finite_number_exception (*)
      * overflow_exception (*)
      * underflow_exception (*)
    * domain_exception (*)
    * format_exception (*)
      * file_format_exception (*)
    * io_exception (*)
      * directory_not_found_exception (*)
      * drive_not_found_exception (*)
      * end_of_stream_exception (*)
      * file_load_exception (*)
      * file_not_found_exception (*)
      * path_too_long_exception (*)
    * index_out_of_range_exception (*)
    * invalid_cast_exception (*)
    * invalid_operation_exception (*)
    * invalid_program_exception (*)
    * key_not_found_exception (*)
    * length_exception (*)
    * not_implemented_exception (*)
    * not_supported_exception (*)
      * platform_not_supported_exception (*)
    * null_pointer_exception (*)
    * operation_canceled_exception (*)
    * time_out_exception (*)
    * xml_syntax_exception (*)

(*) Implemented

## mscorelib (.Net Framework)

* Exception
  * AggregateException
  * ApplicationException
    * WaitHandleCannotBeOpenedException
  * InvalidTimeZoneException
  * LockRecursionException
  * SystemException
    * AbandonedMutexException
    * AccessViolationException
    * AppDomainUnloadException
    * ArgumentException
      * ArgumentNullException
      * ArgumentOutOfRangeException
      * DuplicateWaitException
    * ArithmeticException
      * DivideByZeroException
      * NotFiniteNumberException
      * OverflowException
    * ArrayTypeMismatchException
    * BadImageFormatException
    * CannotUploadAppDomainException
    * ContextMarshalException
    * DataMissalignedException
    * ExecutionEngineException
    * FormatException
      * FileFormatException
    * HostProtectionException
    * IOException
      * DirectoryNotFoundException
      * DriveNotFoundException
      * EndOfStreamException
      * FileLoadException
      * FileNotFoundException
      * PathTooLongException
    * IndexOutOfRangeException
    * InsufficientExecutionStackException
    * InvalidCastException
    * InvalidOperationException
      * ObjectDisposedException
    * InvalidProgramException
    * KeyNotFoundException
    * MemberAccessException
      * FieldAccessException
      * MethodAccessException
      * MissingMemberException
        * MissingFiledException
        * MissingMethodException
    * MulticastNotSupportedException
    * NotImplementedException
    * NotSupportedException
      * PlatformNotSupportedException
    * NullPointerException
    * NullReferenceException
    * OperationCanceledException
    * OutOfMemoryException
      * InsufficientMemoryException
    * RankException
    * SecurityException
    * SerializationException
    * StackOverflowException
    * SynchronizationLockException
    * ThreadAbortException
    * ThreadInterruptException
    * ThreadStartException
    * ThreadStateException
    * TimeOutException
    * TimeZoneNotFoundException
    * TypeInitializationException
    * TypeLoadException
      * DllNotFoundException
      * EntryPointNotFoundException
      * TypeAccessException
    * TypeUnloadException
    * UnauthorizedAccessException
    * VerificationException
    * XmlSyntaxException
  