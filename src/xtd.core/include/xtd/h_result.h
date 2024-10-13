/// @file
/// @brief Contains xtd::h_result class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "int32.h"
#include "static.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__array_definition.h"
#include "internal/__string_definitions.h"
#undef __XTD_CORE_INTERNAL__
#include <unordered_map>
#include <system_error>
#include <vector>

// See [Interpreting HRESULTS returned from .NET/CLR: 0x8013XXXX](https://learn.microsoft.com/en-gb/archive/blogs/yizhang/interpreting-hresults-returned-from-netclr-0x8013xxxx)

/// @cond
#if defined(_WIN32)
#  undef S_OK
#  undef S_FALSE
#  undef CO_E_NOTINITIALIZED
#  undef DISP_E_PARAMNOTFOUND
#  undef DISP_E_TYPEMISMATCH
#  undef DISP_E_BADVARTYPE
#  undef DISP_E_OVERFLOW
#  undef DISP_E_DIVBYZERO
#  undef E_ABORT
#  undef E_BOUNDS
#  undef E_CHANGED_STATE
#  undef E_FAIL
#  undef E_HANDLE
#  undef E_INVALIDARG
#  undef E_NOTIMPL
#  undef E_POINTER
#  undef E_UNEXPECTED
#  undef ERROR_MRM_MAP_NOT_FOUND
#  undef ERROR_TIMEOUT
#  undef RO_E_CLOSED
#  undef RPC_E_CHANGED_MODE
#  undef TYPE_E_TYPEMISMATCH
#  undef STG_E_PATHNOTFOUND
#  undef ERROR_TOO_MANY_OPEN_FILES
#  undef ERROR_SHARING_VIOLATION
#  undef ERROR_LOCK_VIOLATION
#  undef ERROR_OPEN_FAILED
#  undef ERROR_DISK_CORRUPT
#  undef ERROR_UNRECOGNIZED_VOLUME
#  undef ERROR_DLL_INIT_FAILED
#  undef ERROR_FILE_INVALID
#endif
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the HRESULT values used by xtd.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core exceptions
  /// @remarks For more information, see Winerror.h from Micorosft's Win32 API.
  /// @remarks HRESULTs are 32 bit values laid out as follows:
  /// ```
  ///   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
  ///   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
  ///  +-+-+-+-+-+---------------------+-------------------------------+
  ///  |S|R|C|N|r|    Facility         |               Code            |
  ///  +-+-+-+-+-+---------------------+-------------------------------+
  ///
  ///  where
  ///
  ///      S - Severity - indicates success/fail
  ///
  ///          0 - Success
  ///          1 - Fail (COERROR)
  ///
  ///      R - reserved portion of the facility code, corresponds to NT's 
  ///              second severity bit.
  ///
  ///      C - reserved portion of the facility code, corresponds to NT's
  ///              C field.
  ///
  ///      N - reserved portion of the facility code. Used to indicate a
  ///              mapped NT status value.
  ///
  ///      r - reserved portion of the facility code. Reserved for internal
  ///              use. Used to indicate HRESULT values that are not status
  ///              values, but are instead message ids for display strings.
  ///
  ///      Facility - is the facility code
  ///
  ///      Code - is the facility's status code
  /// ```
  class h_result static_ {
  public:
    /// @name Public Static Fields
    
    /// @{
    /// @brief Operation successful.
    static constexpr int32 S_OK = static_cast<int32>(0x00000000);
    /// @brief Operation successful but returned no results.
    static constexpr int32 S_FALSE = static_cast<int32>(0x00000001);
    /// @brief The wait completed due to an abandoned mutex.
    static constexpr int32 COR_E_ABANDONEDMUTEX = static_cast<int32>(0x8013152D);
    /// @brief Ambiguous implementation found.
    static constexpr int32 COR_E_AMBIGUOUSIMPLEMENTATION = static_cast<int32>(0x8013106A);
    /// @brief Ambiguous match found.
    static constexpr int32 COR_E_AMBIGUOUSMATCH = static_cast<int32>(0x8000211D);
    /// @brief Attempted to access an unloaded AppDomain.
    static constexpr int32 COR_E_APPDOMAINUNLOADED = static_cast<int32>(0x80131014);
    /// @brief Error in the application.
    static constexpr int32 COR_E_APPLICATION = static_cast<int32>(0x80131600);
    /// @brief Value does not fall within the expected range.
    static constexpr int32 COR_E_ARGUMENT = static_cast<int32>(0x80070057); // Duplicate with E_INVALIDARG
    /// @brief Specified argument was out of the range of valid values.
    static constexpr int32 COR_E_ARGUMENTOUTOFRANGE = static_cast<int32>(0x80131502);
    /// @brief Overflow or underflow in the arithmetic operation.
    static constexpr int32 COR_E_ARITHMETIC = static_cast<int32>(0x80070216);
    /// @brief Attempted to access an element as a type incompatible with the array.
    static constexpr int32 COR_E_ARRAYTYPEMISMATCH = static_cast<int32>(0x80131503);
    /// @brief Format of the executable (.exe) cannot be run.
    static constexpr int32 COR_E_BADEXEFORMAT = static_cast<int32>(0x800700C1);
    /// @brief Format of the executable (.exe) or library (.dll) is invalid.
    static constexpr int32 COR_E_BADIMAGEFORMAT = static_cast<int32>(0x8007000B);
    /// @brief Attempt to unload the AppDomain failed.
    static constexpr int32 COR_E_CANNOTUNLOADAPPDOMAIN = static_cast<int32>(0x80131015);
    /// @brief A code contract (ie, precondition, postcondition, invariant, or assert) failed.
    static constexpr int32 COR_E_CODECONTRACTFAILED = static_cast<int32>(0x80131542);
    /// @brief Attempted to marshal an object across a context boundary.
    static constexpr int32 COR_E_CONTEXTMARSHAL = static_cast<int32>(0x80131504);
    /// @brief Binary format of the specified custom attribute was invalid.
    static constexpr int32 COR_E_CUSTOMATTRIBUTEFORMAT = static_cast<int32>(0x80131605);
    /// @brief A datatype misalignment was detected in a load or store instruction.
    static constexpr int32 COR_E_DATAMISALIGNED = static_cast<int32>(0x80131541);
    /// @brief Attempted to access a path that is not on the disk.
    static constexpr int32 COR_E_DIRECTORYNOTFOUND = static_cast<int32>(0x80070003);
    /// @brief Attempted to divide by zero.
    static constexpr int32 COR_E_DIVIDEBYZERO = static_cast<int32>(0x80020012); // Duplicate with DISP_E_DIVBYZERO
    /// @brief Dll was not found.
    static constexpr int32 COR_E_DLLNOTFOUND = static_cast<int32>(0x80131524);
    /// @brief Could not find the drive. The drive might not be ready or might not be mapped.
    static constexpr int32 COR_E_DRIVENOTFOUND = static_cast<int32>(0x80070007);
    /// @brief Duplicate objects in argument.
    static constexpr int32 COR_E_DUPLICATEWAITOBJECT = static_cast<int32>(0x80131529);
    /// @brief Attempted to read past the end of the stream.
    static constexpr int32 COR_E_ENDOFSTREAM = static_cast<int32>(0x80070026);
    /// @brief Entry point was not found.
    static constexpr int32 COR_E_ENTRYPOINTNOTFOUND = static_cast<int32>(0x80131523);
    /// @brief Exception of type 'xtd::exception' was thrown.
    static constexpr int32 COR_E_EXCEPTION = static_cast<int32>(0x80131500);
    /// @brief Internal error in the runtime.
    static constexpr int32 COR_E_EXECUTIONENGINE = static_cast<int32>(0x80131506);
    /// @brief Fail fast.
    static constexpr int32 COR_E_FAILFAST = static_cast<int32>(0x80131623);
    /// @brief Attempted to access a field that is not accessible by the caller.
    static constexpr int32 COR_E_FIELDACCESS = static_cast<int32>(0x80131507);
    /// @brief Could not load the specified file.
    static constexpr int32 COR_E_FILELOAD = static_cast<int32>(0x80131621);
    /// @brief Unable to find the specified file.
    static constexpr int32 COR_E_FILENOTFOUND = static_cast<int32>(0x80070002); // Duplicate with E_FILENOTFOUND
    /// @brief One of the identified items was in an invalid format.
    static constexpr int32 COR_E_FORMAT = static_cast<int32>(0x80131537);
    /// @brief Index was outside the bounds of the array.
    static constexpr int32 COR_E_INDEXOUTOFRANGE = static_cast<int32>(0x80131508);
    /// @brief Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space.
    static constexpr int32 COR_E_INSUFFICIENTEXECUTIONSTACK = static_cast<int32>(0x80131578);
    /// @brief Insufficient memory to continue the execution of the program.
    static constexpr int32 COR_E_INSUFFICIENTMEMORY = static_cast<int32>(0x8013153D);
    /// @brief Specified cast is not valid.
    static constexpr int32 COR_E_INVALIDCAST = static_cast<int32>(0x80004002);
    /// @brief Attempt has been made to use a COM object that does not have a backing class factory.
    static constexpr int32 COR_E_INVALIDCOMOBJECT = static_cast<int32>(0x80131527);
    /// @brief Specified filter criteria was invalid.
    static constexpr int32 COR_E_INVALIDFILTERCRITERIA = static_cast<int32>(0x80131601);
    /// @brief Specified OLE variant was invalid.
    static constexpr int32 COR_E_INVALIDOLEVARIANTTYPE = static_cast<int32>(0x80131531);
    /// @brief Operation is not valid due to the current state of the object.
    static constexpr int32 COR_E_INVALIDOPERATION = static_cast<int32>(0x80131509);
    /// @brief xtd detected an invalid program.
    static constexpr int32 COR_E_INVALIDPROGRAM = static_cast<int32>(0x8013153A);
    /// @brief I/O error occurred.
    static constexpr int32 COR_E_IO = static_cast<int32>(0x80131620);
    /// @brief The given key was not present in the dictionary.
    static constexpr int32 COR_E_KEYNOTFOUND = static_cast<int32>(0x80131577);
    /// @brief Marshaling directives are invalid.
    static constexpr int32 COR_E_MARSHALDIRECTIVE = static_cast<int32>(0x80131535);
    /// @brief Cannot access member.
    static constexpr int32 COR_E_MEMBERACCESS = static_cast<int32>(0x8013151A);
    /// @brief Attempt to access the method failed.
    static constexpr int32 COR_E_METHODACCESS = static_cast<int32>(0x80131510);
    /// @brief Attempted to access a non-existing field.
    static constexpr int32 COR_E_MISSINGFIELD = static_cast<int32>(0x80131511);
    /// @brief Attempted to access a missing manifest resource.
    static constexpr int32 COR_E_MISSINGMANIFESTRESOURCE = static_cast<int32>(0x80131532);
    /// @brief Attempted to access a missing member.
    static constexpr int32 COR_E_MISSINGMEMBER = static_cast<int32>(0x80131512);
    /// @brief Attempted to access a missing method.
    static constexpr int32 COR_E_MISSINGMETHOD = static_cast<int32>(0x80131513);
    /// @brief Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application.
    static constexpr int32 COR_E_MISSINGSATELLITEASSEMBLY = static_cast<int32>(0x80131536);
    /// @brief Attempted to add multiple callbacks to a delegate that does not support multicast.
    static constexpr int32 COR_E_MULTICASTNOTSUPPORTED = static_cast<int32>(0x80131514);
    /// @brief Number encountered was not a finite quantity.
    static constexpr int32 COR_E_NOTFINITENUMBER = static_cast<int32>(0x80131528);
    /// @brief Specified method is not supported.
    static constexpr int32 COR_E_NOTSUPPORTED = static_cast<int32>(0x80131515);
    /// @brief Cannot access a closed object.
    static constexpr int32 COR_E_OBJECTCLOSED = static_cast<int32>(0x80131622);
    /// @brief The operation was canceled.
    static constexpr int32 COR_E_OPERATIONCANCELED = static_cast<int32>(0x8013153B);
    /// @brief Insufficient memory to continue the execution of the program.
    static constexpr int32 COR_E_OUTOFMEMORY = static_cast<int32>(0x8007000E);
    /// @brief Arithmetic operation resulted in an overflow.
    static constexpr int32 COR_E_OVERFLOW = static_cast<int32>(0x80131516);
    /// @brief The specified file name or path is too long, or a component of the specified path is too long.
    static constexpr int32 COR_E_PATHTOOLONG = static_cast<int32>(0x800700CE);
    /// @brief Operation is not supported on this platform.
    static constexpr int32 COR_E_PLATFORMNOTSUPPORTED = static_cast<int32>(0x80131539);
    /// @brief Attempted to operate on an array with the incorrect number of dimensions.
    static constexpr int32 COR_E_RANK = static_cast<int32>(0x80131517);
    /// @brief Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown.
    static constexpr int32 COR_E_REFLECTIONTYPELOAD = static_cast<int32>(0x80131602);
    /// @brief An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception.
    static constexpr int32 COR_E_RUNTIMEWRAPPED = static_cast<int32>(0x8013153E);
    /// @brief Specified array was not of the expected rank.
    static constexpr int32 COR_E_SAFEARRAYRANKMISMATCH = static_cast<int32>(0x80131538);
    /// @brief Specified array was not of the expected type.
    static constexpr int32 COR_E_SAFEARRAYTYPEMISMATCH = static_cast<int32>(0x80131533);
    /// @brief Security error.
    static constexpr int32 COR_E_SECURITY = static_cast<int32>(0x8013150A);
    /// @brief Serialization error.
    static constexpr int32 COR_E_SERIALIZATION = static_cast<int32>(0x8013150C);
    /// @brief Operation caused a stack overflow.
    static constexpr int32 COR_E_STACKOVERFLOW = static_cast<int32>(0x800703E9);
    /// @brief Object synchronization method was called from an unsynchronized block of code.
    static constexpr int32 COR_E_SYNCHRONIZATIONLOCK = static_cast<int32>(0x80131518);
    /// @brief System error.
    static constexpr int32 COR_E_SYSTEM = static_cast<int32>(0x80131501);
    /// @brief Exception of type 'xtd::reflection::target_exception' was thrown.
    static constexpr int32 COR_E_TARGET = static_cast<int32>(0x80131603);
    /// @brief Exception has been thrown by the target of an invocation.
    static constexpr int32 COR_E_TARGETINVOCATION = static_cast<int32>(0x80131604);
    /// @brief Number of parameters specified does not match the expected number.
    static constexpr int32 COR_E_TARGETPARAMCOUNT = static_cast<int32>(0x8002000E);
    /// @brief Thread was aborted.
    static constexpr int32 COR_E_THREADABORTED = static_cast<int32>(0x80131530);
    /// @brief Thread was interrupted from a waiting state.
    static constexpr int32 COR_E_THREADINTERRUPTED = static_cast<int32>(0x80131519);
    /// @brief Thread start failure.
    static constexpr int32 COR_E_THREADSTART = static_cast<int32>(0x80131525);
    /// @brief Thread was in an invalid state for the operation being executed.
    static constexpr int32 COR_E_THREADSTATE = static_cast<int32>(0x80131520);
    /// @brief The operation has timed out.
    static constexpr int32 COR_E_TIMEOUT = static_cast<int32>(0x80131505);
    /// @brief Attempt to access the type failed.
    static constexpr int32 COR_E_TYPEACCESS = static_cast<int32>(0x80131543);
    /// @brief The type initializer for 'value' threw an exception.
    static constexpr int32 COR_E_TYPEINITIALIZATION = static_cast<int32>(0x80131534);
    /// @brief Failure has occurred while loading a type.
    static constexpr int32 COR_E_TYPELOAD = static_cast<int32>(0x80131522);
    /// @brief Type had been unloaded.
    static constexpr int32 COR_E_TYPEUNLOADED = static_cast<int32>(0x80131013);
    /// @brief Attempted to perform an unauthorized operation.
    static constexpr int32 COR_E_UNAUTHORIZEDACCESS = static_cast<int32>(0x80070005);
    /// @brief Operation could destabilize the runtime.
    static constexpr int32 COR_E_VERIFICATION = static_cast<int32>(0x8013150D);
    /// @brief No handle of the given name exists.
    static constexpr int32 COR_E_WAITHANDLECANNOTBEOPENED = static_cast<int32>(0x8013152C);
    /// @brief Not initialized
    static constexpr int32 CO_E_NOTINITIALIZED = static_cast<int32>(0x800401F0);
    /// @brief Could not find the parameter.
    static constexpr int32 DISP_E_PARAMNOTFOUND = static_cast<int32>(0x80020004);
    /// @brief Attempt to access a variable with an incompatible type.
    static constexpr int32 DISP_E_TYPEMISMATCH = static_cast<int32>(0x80020005);
    /// @brief Invalid variable type.
    static constexpr int32 DISP_E_BADVARTYPE = static_cast<int32>(0x80020008);
    /// @brief Arithmetic operation resulted in an overflow.
    static constexpr int32 DISP_E_OVERFLOW = static_cast<int32>(0x8002000A);
    /// @brief Attempted to divide by zero.
    static constexpr int32 DISP_E_DIVBYZERO = static_cast<int32>(0x80020012); // Duplicate with COR_E_DIVIDEBYZERO
    /// @brief Operation aborted.
    static constexpr int32 E_ABORT = static_cast<int32>(0x80004004);
    /// @brief Bounds exception.
    static constexpr int32 E_BOUNDS = static_cast<int32>(0x8000000B);
    /// @brief The state has been modified.
    static constexpr int32 E_CHANGED_STATE = static_cast<int32>(0x8000000C);
    /// @brief Unable to find the specified file.
    static constexpr int32 E_FILENOTFOUND = static_cast<int32>(0x80070002); // Duplicate with COR_E_FILENOTFOUND
    /// @brief Unspecified failure.
    static constexpr int32 E_FAIL = static_cast<int32>(0x80004005);
    /// @brief The handle is invalid.
    static constexpr int32 E_HANDLE = static_cast<int32>(0x80070006);
    /// @brief Value does not fall within the expected range.
    static constexpr int32 E_INVALIDARG = static_cast<int32>(0x80070057); // Duplicate with COR_E_ARGUMENT
    /// @brief The method or operation is not implemented.
    static constexpr int32 E_NOTIMPL = static_cast<int32>(0x80004001);
    /// @brief Attempted to read or write protected memory. This is often an indication that other memory is corrupt.
    static constexpr int32 E_POINTER = static_cast<int32>(0x80004003);
    /// @brief Unexpected failure.
    static constexpr int32 E_UNEXPECTED = static_cast<int32>(0x8000FFFF);
    /// @brief Resource map not found.
    static constexpr int32 ERROR_MRM_MAP_NOT_FOUND = static_cast<int32>(0x80073B1F);
    /// @brief The operation has timed out.
    static constexpr int32 ERROR_TIMEOUT = static_cast<int32>(0x800705B4);
    /// @brief The object has been closed.
    static constexpr int32 RO_E_CLOSED = static_cast<int32>(0x80000013);
    /// @brief Cannot change the current thread mode.
    static constexpr int32 RPC_E_CHANGED_MODE = static_cast<int32>(0x80010106);
    /// @brief Incompatible type.
    static constexpr int32 TYPE_E_TYPEMISMATCH = static_cast<int32>(0x80028CA0);
    /// @brief Attempted to access a path that is not on the disk.
    static constexpr int32 STG_E_PATHNOTFOUND = static_cast<int32>(0x80030003);
    /// @brief Attempted to access a path that is not on the disk.
    static constexpr int32 CTL_E_PATHNOTFOUND = static_cast<int32>(0x800A004C);
    /// @brief Unable to find the specified file.
    static constexpr int32 CTL_E_FILENOTFOUND = static_cast<int32>(0x800A0035);
    /// @brief Fusion invalid name exception.
    static constexpr int32 FUSION_E_INVALID_NAME = static_cast<int32>(0x80131047);
    /// @brief Fusion the reference definition is incompatible.
    static constexpr int32 FUSION_E_REF_DEF_MISMATCH = static_cast<int32>(0x80131040);
    /// @brief Too many open files.
    static constexpr int32 ERROR_TOO_MANY_OPEN_FILES = static_cast<int32>(0x80070004);
    /// @brief Sharing violation.
    static constexpr int32 ERROR_SHARING_VIOLATION = static_cast<int32>(0x80070020);
    /// @brief Lock violations.
    static constexpr int32 ERROR_LOCK_VIOLATION = static_cast<int32>(0x80070021);
    /// @brief Open failed.
    static constexpr int32 ERROR_OPEN_FAILED = static_cast<int32>(0x8007006E);
    /// @brief Disk corrupt.
    static constexpr int32 ERROR_DISK_CORRUPT = static_cast<int32>(0x80070571);
    /// @brief Unrecognized volume.
    static constexpr int32 ERROR_UNRECOGNIZED_VOLUME = static_cast<int32>(0x800703ED);
    /// @brief DLL init failed.
    static constexpr int32 ERROR_DLL_INIT_FAILED = static_cast<int32>(0x8007045A);
    /// @brief Assembly load in progress.
    static constexpr int32 MSEE_E_ASSEMBLYLOADINPROGRESS = static_cast<int32>(0x80131016);
    /// @brief File invalid.
    static constexpr int32 ERROR_FILE_INVALID = static_cast<int32>(0x800703EE);
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Provides a generic fail test for the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return `true` is failed; otherwise `false`.
    static bool failed(int32 h_result) noexcept;

    /// @brief Gets the code portion of the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return The code portion of `h_result`.
    static int32 get_code(int32 h_result) noexcept;

    /// @brief The facility of the specified HRESULT, which indicates what API or framework originated this error.
    /// @param h_result The HRESULT value.
    /// @return The facility of `h_result`.
    /// @remarks The facility of an HRESULT is stored in bits 16-26 of the HRESULT.
    /// @par Possible values
    /// | FACILITY                                          | Decimal | Hex   |
    /// | ------------------------------------------------- | ------- | ----- |
    /// | FACILITY_NULL                                     | 0       | 0x0   |
    /// | FACILITY_RPC                                      | 1       | 0x1   |
    /// | FACILITY_DISPATCH                                 | 2       | 0x2   |
    /// | FACILITY_STORAGE                                  | 3       | 0x3   |
    /// | FACILITY_ITF                                      | 4       | 0x4   |
    /// | FACILITY_WIN32                                    | 7       | 0x7   |
    /// | FACILITY_WINDOWS                                  | 8       | 0x8   |
    /// | FACILITY_SECURITY                                 | 9       | 0x9   |
    /// | FACILITY_SSPI                                     | 9       | 0x9   |
    /// | FACILITY_CONTROL                                  | 10      | 0xA   |
    /// | FACILITY_CERT                                     | 11      | 0xB   |
    /// | FACILITY_INTERNET                                 | 12      | 0xC   |
    /// | FACILITY_MEDIASERVER                              | 13      | 0xD   |
    /// | FACILITY_MSMQ                                     | 14      | 0xE   |
    /// | FACILITY_SETUPAPI                                 | 15      | 0xF   |
    /// | FACILITY_SCARD                                    | 16      | 0x10  |
    /// | FACILITY_COMPLUS                                  | 17      | 0x11  |
    /// | FACILITY_AAF                                      | 18      | 0x12  |
    /// | FACILITY_URT                                      | 19      | 0x13  |
    /// | FACILITY_ACS                                      | 20      | 0x14  |
    /// | FACILITY_DPLAY                                    | 21      | 0x15  |
    /// | FACILITY_UMI                                      | 22      | 0x16  |
    /// | FACILITY_SXS                                      | 23      | 0x17  |
    /// | FACILITY_WINDOWS_CE                               | 24      | 0x18  |
    /// | FACILITY_HTTP                                     | 25      | 0x19  |
    /// | FACILITY_USERMODE_COMMONLOG                       | 26      | 0x1A  |
    /// | FACILITY_WER                                      | 27      | 0x1B  |
    /// | FACILITY_USERMODE_FILTER_MANAGER                  | 31      | 0x1F  |
    /// | FACILITY_BACKGROUNDCOPY                           | 32      | 0x20  |
    /// | FACILITY_CONFIGURATION                            | 33      | 0x21  |
    /// | FACILITY_WIA                                      | 33      | 0x21  |
    /// | FACILITY_STATE_MANAGEMENT                         | 34      | 0x22  |
    /// | FACILITY_METADIRECTORY                            | 35      | 0x23  |
    /// | FACILITY_WINDOWSUPDATE                            | 36      | 0x24  |
    /// | FACILITY_DIRECTORYSERVICE                         | 37      | 0x25  |
    /// | FACILITY_GRAPHICS                                 | 38      | 0x26  |
    /// | FACILITY_NAP                                      | 39      | 0x27  |
    /// | FACILITY_SHELL                                    | 39      | 0x27  |
    /// | FACILITY_TPM_SERVICES                             | 40      | 0x28  |
    /// | FACILITY_TPM_SOFTWARE                             | 41      | 0x29  |
    /// | FACILITY_UI                                       | 42      | 0x2A  |
    /// | FACILITY_XAML                                     | 43      | 0x2B  |
    /// | FACILITY_ACTION_QUEUE                             | 44      | 0x2C  |
    /// | FACILITY_PLA                                      | 48      | 0x30  |
    /// | FACILITY_WINDOWS_SETUP                            | 48      | 0x30  |
    /// | FACILITY_FVE                                      | 49      | 0x31  |
    /// | FACILITY_FWP                                      | 50      | 0x32  |
    /// | FACILITY_WINRM                                    | 51      | 0x33  |
    /// | FACILITY_NDIS                                     | 52      | 0x34  |
    /// | FACILITY_USERMODE_HYPERVISOR                      | 53      | 0x35  |
    /// | FACILITY_CMI                                      | 54      | 0x36  |
    /// | FACILITY_USERMODE_VIRTUALIZATION                  | 55      | 0x37  |
    /// | FACILITY_USERMODE_VOLMGR                          | 56      | 0x38  |
    /// | FACILITY_BCD                                      | 57      | 0x39  |
    /// | FACILITY_USERMODE_VHD                             | 58      | 0x3A  |
    /// | FACILITY_SDIAG                                    | 60      | 0x3C  |
    /// | FACILITY_WEBSERVICES                              | 61      | 0x3D  |
    /// | FACILITY_WINPE                                    | 61      | 0x3D  |
    /// | FACILITY_WPN                                      | 62      | 0x3E  |
    /// | FACILITY_WINDOWS_STORE                            | 63      | 0x3F  |
    /// | FACILITY_INPUT                                    | 64      | 0x40  |
    /// | FACILITY_EAP                                      | 66      | 0x42  |
    /// | FACILITY_WINDOWS_DEFENDER                         | 80      | 0x50  |
    /// | FACILITY_OPC                                      | 81      | 0x51  |
    /// | FACILITY_XPS                                      | 82      | 0x52  |
    /// | FACILITY_RAS                                      | 83      | 0x53  |
    /// | FACILITY_MBN                                      | 84      | 0x54  |
    /// | FACILITY_POWERSHELL                               | 84      | 0x54  |
    /// | FACILITY_EAS                                      | 85      | 0x55  |
    /// | FACILITY_P2P_INT                                  | 98      | 0x62  |
    /// | FACILITY_P2P                                      | 99      | 0x63  |
    /// | FACILITY_DAF                                      | 100     | 0x64  |
    /// | FACILITY_BLUETOOTH_ATT                            | 101     | 0x65  |
    /// | FACILITY_AUDIO                                    | 102     | 0x66  |
    /// | FACILITY_VISUALCPP                                | 109     | 0x6D  |
    /// | FACILITY_SCRIPT                                   | 112     | 0x70  |
    /// | FACILITY_PARSE                                    | 113     | 0x71  |
    /// | FACILITY_BLB                                      | 120     | 0x78  |
    /// | FACILITY_BLB_CLI                                  | 121     | 0x79  |
    /// | FACILITY_WSBAPP                                   | 122     | 0x7A  |
    /// | FACILITY_BLBUI                                    | 128     | 0x80  |
    /// | FACILITY_USN                                      | 129     | 0x81  |
    /// | FACILITY_USERMODE_VOLSNAP                         | 130     | 0x82  |
    /// | FACILITY_TIERING                                  | 131     | 0x83  |
    /// | FACILITY_WSB_ONLINE                               | 133     | 0x85  |
    /// | FACILITY_ONLINE_ID                                | 134     | 0x86  |
    /// | FACILITY_DLS                                      | 153     | 0x99  |
    /// | FACILITY_SOS                                      | 160     | 0xA0  |
    /// | FACILITY_DEBUGGERS                                | 176     | 0xB0  |
    /// | FACILITY_USERMODE_SPACES                          | 231     | 0xE7  |
    /// | FACILITY_DMSERVER                                 | 256     | 0x100 |
    /// | FACILITY_RESTORE                                  | 256     | 0x100 |
    /// | FACILITY_SPP                                      | 256     | 0x100 |
    /// | FACILITY_DEPLOYMENT_SERVICES_SERVER               | 257     | 0x101 |
    /// | FACILITY_DEPLOYMENT_SERVICES_IMAGING              | 258     | 0x102 |
    /// | FACILITY_DEPLOYMENT_SERVICES_MANAGEMENT           | 259     | 0x103 |
    /// | FACILITY_DEPLOYMENT_SERVICES_UTIL                 | 260     | 0x104 |
    /// | FACILITY_DEPLOYMENT_SERVICES_BINLSVC              | 261     | 0x105 |
    /// | FACILITY_DEPLOYMENT_SERVICES_PXE                  | 263     | 0x107 |
    /// | FACILITY_DEPLOYMENT_SERVICES_TFTP                 | 264     | 0x108 |
    /// | FACILITY_DEPLOYMENT_SERVICES_TRANSPORT_MANAGEMENT | 272     | 0x110 |
    /// | FACILITY_DEPLOYMENT_SERVICES_DRIVER_PROVISIONING  | 278     | 0x116 |
    /// | FACILITY_DEPLOYMENT_SERVICES_MULTICAST_SERVER     | 289     | 0x121 |
    /// | FACILITY_DEPLOYMENT_SERVICES_MULTICAST_CLIENT     | 290     | 0x122 |
    /// | FACILITY_DEPLOYMENT_SERVICES_CONTENT_PROVIDER     | 293     | 0x125 |
    /// | FACILITY_LINGUISTIC_SERVICES                      | 305     | 0x131 |
    /// | FACILITY_WEB                                      | 885     | 0x375 |
    /// | FACILITY_WEB_SOCKET                               | 886     | 0x376 |
    /// | FACILITY_AUDIOSTREAMING                           | 1094    | 0x446 |
    /// | FACILITY_ACCELERATOR                              | 1536    | 0x600 |
    /// | FACILITY_MOBILE                                   | 1793    | 0x701 |
    /// | FACILITY_WMAAECMA                                 | 1996    | 0x7CC |
    /// | FACILITY_WEP                                      | 2049    | 0x801 |
    /// | FACILITY_SYNCENGINE                               | 2050    | 0x802 |
    /// | FACILITY_DIRECTMUSIC                              | 2168    | 0x878 |
    /// | FACILITY_DIRECT3D10                               | 2169    | 0x879 |
    /// | FACILITY_DXGI                                     | 2170    | 0x87A |
    /// | FACILITY_DXGI_DDI                                 | 2171    | 0x87B |
    /// | FACILITY_DIRECT3D11                               | 2172    | 0x87C |
    /// | FACILITY_LEAP                                     | 2184    | 0x888 |
    /// | FACILITY_AUDCLNT                                  | 2185    | 0x889 |
    /// | FACILITY_WINCODEC_DWRITE_DWM                      | 2200    | 0x898 |
    /// | FACILITY_DIRECT2D                                 | 2201    | 0x899 |
    /// | FACILITY_DEFRAG                                   | 2304    | 0x900 |
    /// | FACILITY_USERMODE_SDBUS                           | 2305    | 0x901 |
    /// | FACILITY_JSCRIPT                                  | 2306    | 0x902 |
    /// | FACILITY_PIDGENX                                  | 2561    | 0xA01 |
    static int32 get_facility(int32 h_result) noexcept;

    /// @brief Gets an array of HRESULT.
    /// @return An array of HRESULT.
    static const xtd::array<int32>& get_h_results() noexcept;
    
    /// @brief Gets the message of the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return The message of `h_result`.
    static string get_message(int32 h_result) noexcept;

    /// @brief Gets The HRESULT messages.
    /// @return The h_result messages.
    static const std::unordered_map<int32, string>& get_messages() noexcept;

    /// @brief Gets the name of the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return The name of `h_result`.
    static string get_name(int32 h_result) noexcept;
    
    /// @brief Gets The HRESULT names.
    /// @return The h_result names.
    static const std::unordered_map<int32, string>& get_names() noexcept;

    /// @brief The severity of the specified HRESULT, which indicates what API or framework originated this error.
    /// @param h_result The HRESULT value.
    /// @return The severity of `h_result`.
    /// @par Possible values
    /// | SEVERIFY         | Decimal | Hex |
    /// | ---------------- | ------- | --- |
    /// | SEVERITY_SUCCESS | 0       | 0x0 |
    /// | SEVERITY_ERROR   | 1       | 0x1 |
    static int32 get_severity(int32 h_result) noexcept;

    /// @brief Obtains a reference to the static error category object for HRESULT errors. The object is required to override the virtual function error_category::name() to return a pointer to the string "h_result_category". It is used to identify error conditions that correspond to the HRESULT error codes.
    /// @return A reference to the static object of unspecified runtime type, derived from [std::error_category](https://en.cppreference.com/w/cpp/error/error_category).
    static const std::error_category& h_result_category() noexcept;

    /// @brief Provides a generic is error test for the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return `true` is error; otherwise `false`.
    static bool is_error(int32 h_result) noexcept;

    /// @brief Creates error code value for the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return Error code corresponding to `h_result`.
    static std::error_code make_error_code(int h_result) noexcept;

    /// @brief Provides a generic success test for the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return `true` is secceeded; otherwise `false`.
    static bool succeeded(int32 h_result) noexcept;

    /// @brief Gets the name of the specified HRESULT.
    /// @param h_result The HRESULT value.
    /// @return The name of `h_result`.
    static string to_string(int32 h_result) noexcept;
    /// &}
  };
}
