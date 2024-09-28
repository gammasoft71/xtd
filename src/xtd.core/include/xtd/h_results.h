/// @file
/// @brief Contains h_results class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "h_results_category.h"
#include "int32.h"
#include "static.h"

/// @cond
#if defined(_WIN32)
#undef S_OK
#undef S_FALSE
#undef CO_E_NOTINITIALIZED
#undef DISP_E_OVERFLOW
#undef E_ABORT
#undef E_BOUNDS
#undef E_CHANGED_STATE
#undef E_FAIL
#undef E_HANDLE
#undef E_INVALIDARG
#undef E_NOTIMPL
#undef E_POINTER
#undef E_UNEXPECTED
#undef ERROR_MRM_MAP_NOT_FOUND
#undef ERROR_TIMEOUT
#undef RO_E_CLOSED
#undef RPC_E_CHANGED_MODE
#undef TYPE_E_TYPEMISMATCH
#undef STG_E_PATHNOTFOUND
#undef ERROR_TOO_MANY_OPEN_FILES
#undef ERROR_SHARING_VIOLATION
#undef ERROR_LOCK_VIOLATION
#undef ERROR_OPEN_FAILED
#undef ERROR_DISK_CORRUPT
#undef ERROR_UNRECOGNIZED_VOLUME
#undef ERROR_DLL_INIT_FAILED
#undef ERROR_FILE_INVALID
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
  class h_results static_ {
  public:
    /// @name Public Fields
    
    /// @{
    /// @brief Operation successful.
    static constexpr int32 S_OK = static_cast<int32>(0x00000000);
    /// @brief Operation successful but returned no results.
    static constexpr int32 S_FALSE = static_cast<int32>(0x1);
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
    static constexpr int32 COR_E_ARGUMENT = static_cast<int32>(0x80070057);
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
    /// @brief
    static constexpr int32 COR_E_CODECONTRACTFAILED = static_cast<int32>(0x80131542);
    /// @brief
    static constexpr int32 COR_E_CONTEXTMARSHAL = static_cast<int32>(0x80131504);
    /// @brief
    static constexpr int32 COR_E_CUSTOMATTRIBUTEFORMAT = static_cast<int32>(0x80131605);
    /// @brief
    static constexpr int32 COR_E_DATAMISALIGNED = static_cast<int32>(0x80131541);
    /// @brief
    static constexpr int32 COR_E_DIRECTORYNOTFOUND = static_cast<int32>(0x80070003);
    /// @brief
    static constexpr int32 COR_E_DIVIDEBYZERO = static_cast<int32>(0x80020012); // DISP_E_DIVBYZERO
    /// @brief
    static constexpr int32 COR_E_DLLNOTFOUND = static_cast<int32>(0x80131524);
    /// @brief
    static constexpr int32 COR_E_DUPLICATEWAITOBJECT = static_cast<int32>(0x80131529);
    /// @brief
    static constexpr int32 COR_E_ENDOFSTREAM = static_cast<int32>(0x80070026);
    /// @brief
    static constexpr int32 COR_E_ENTRYPOINTNOTFOUND = static_cast<int32>(0x80131523);
    /// @brief Exception of type 'xtd::exception' was thrown.
    static constexpr int32 COR_E_EXCEPTION = static_cast<int32>(0x80131500);
    /// @brief
    static constexpr int32 COR_E_EXECUTIONENGINE = static_cast<int32>(0x80131506);
    /// @brief
    static constexpr int32 COR_E_FAILFAST = static_cast<int32>(0x80131623);
    /// @brief
    static constexpr int32 COR_E_FIELDACCESS = static_cast<int32>(0x80131507);
    /// @brief
    static constexpr int32 COR_E_FILELOAD = static_cast<int32>(0x80131621);
    /// @brief
    static constexpr int32 COR_E_FILENOTFOUND = static_cast<int32>(0x80070002);
    /// @brief
    static constexpr int32 COR_E_FORMAT = static_cast<int32>(0x80131537);
    /// @brief
    static constexpr int32 COR_E_INDEXOUTOFRANGE = static_cast<int32>(0x80131508);
    /// @brief
    static constexpr int32 COR_E_INSUFFICIENTEXECUTIONSTACK = static_cast<int32>(0x80131578);
    /// @brief
    static constexpr int32 COR_E_INSUFFICIENTMEMORY = static_cast<int32>(0x8013153D);
    /// @brief
    static constexpr int32 COR_E_INVALIDCAST = static_cast<int32>(0x80004002);
    /// @brief
    static constexpr int32 COR_E_INVALIDCOMOBJECT = static_cast<int32>(0x80131527);
    /// @brief
    static constexpr int32 COR_E_INVALIDFILTERCRITERIA = static_cast<int32>(0x80131601);
    /// @brief
    static constexpr int32 COR_E_INVALIDOLEVARIANTTYPE = static_cast<int32>(0x80131531);
    /// @brief
    static constexpr int32 COR_E_INVALIDOPERATION = static_cast<int32>(0x80131509);
    /// @brief
    static constexpr int32 COR_E_INVALIDPROGRAM = static_cast<int32>(0x8013153A);
    /// @brief
    static constexpr int32 COR_E_IO = static_cast<int32>(0x80131620);
    /// @brief
    static constexpr int32 COR_E_KEYNOTFOUND = static_cast<int32>(0x80131577);
    /// @brief
    static constexpr int32 COR_E_MARSHALDIRECTIVE = static_cast<int32>(0x80131535);
    /// @brief
    static constexpr int32 COR_E_MEMBERACCESS = static_cast<int32>(0x8013151A);
    /// @brief
    static constexpr int32 COR_E_METHODACCESS = static_cast<int32>(0x80131510);
    /// @brief
    static constexpr int32 COR_E_MISSINGFIELD = static_cast<int32>(0x80131511);
    /// @brief
    static constexpr int32 COR_E_MISSINGMANIFESTRESOURCE = static_cast<int32>(0x80131532);
    /// @brief
    static constexpr int32 COR_E_MISSINGMEMBER = static_cast<int32>(0x80131512);
    /// @brief
    static constexpr int32 COR_E_MISSINGMETHOD = static_cast<int32>(0x80131513);
    /// @brief
    static constexpr int32 COR_E_MISSINGSATELLITEASSEMBLY = static_cast<int32>(0x80131536);
    /// @brief
    static constexpr int32 COR_E_MULTICASTNOTSUPPORTED = static_cast<int32>(0x80131514);
    /// @brief
    static constexpr int32 COR_E_NOTFINITENUMBER = static_cast<int32>(0x80131528);
    /// @brief
    static constexpr int32 COR_E_NOTSUPPORTED = static_cast<int32>(0x80131515);
    /// @brief
    static constexpr int32 COR_E_OBJECTDISPOSED = static_cast<int32>(0x80131622);
    /// @brief
    static constexpr int32 COR_E_OPERATIONCANCELED = static_cast<int32>(0x8013153B);
    /// @brief
    static constexpr int32 COR_E_OUTOFMEMORY = static_cast<int32>(0x8007000E);
    /// @brief
    static constexpr int32 COR_E_OVERFLOW = static_cast<int32>(0x80131516);
    /// @brief
    static constexpr int32 COR_E_PATHTOOLONG = static_cast<int32>(0x800700CE);
    /// @brief
    static constexpr int32 COR_E_PLATFORMNOTSUPPORTED = static_cast<int32>(0x80131539);
    /// @brief Attempted to operate on an array with the incorrect number of dimensions.
    static constexpr int32 COR_E_RANK = static_cast<int32>(0x80131517);
    /// @brief
    static constexpr int32 COR_E_REFLECTIONTYPELOAD = static_cast<int32>(0x80131602);
    /// @brief
    static constexpr int32 COR_E_RUNTIMEWRAPPED = static_cast<int32>(0x8013153E);
    /// @brief
    static constexpr int32 COR_E_SAFEARRAYRANKMISMATCH = static_cast<int32>(0x80131538);
    /// @brief
    static constexpr int32 COR_E_SAFEARRAYTYPEMISMATCH = static_cast<int32>(0x80131533);
    /// @brief
    static constexpr int32 COR_E_SECURITY = static_cast<int32>(0x8013150A);
    /// @brief
    static constexpr int32 COR_E_SERIALIZATION = static_cast<int32>(0x8013150C);
    /// @brief
    static constexpr int32 COR_E_STACKOVERFLOW = static_cast<int32>(0x800703E9);
    /// @brief
    static constexpr int32 COR_E_SYNCHRONIZATIONLOCK = static_cast<int32>(0x80131518);
    /// @brief System error.
    static constexpr int32 COR_E_SYSTEM = static_cast<int32>(0x80131501);
    /// @brief
    static constexpr int32 COR_E_TARGET = static_cast<int32>(0x80131603);
    /// @brief
    static constexpr int32 COR_E_TARGETINVOCATION = static_cast<int32>(0x80131604);
    /// @brief
    static constexpr int32 COR_E_TARGETPARAMCOUNT = static_cast<int32>(0x8002000E);
    /// @brief
    static constexpr int32 COR_E_THREADABORTED = static_cast<int32>(0x80131530);
    /// @brief
    static constexpr int32 COR_E_THREADINTERRUPTED = static_cast<int32>(0x80131519);
    /// @brief
    static constexpr int32 COR_E_THREADSTART = static_cast<int32>(0x80131525);
    /// @brief
    static constexpr int32 COR_E_THREADSTATE = static_cast<int32>(0x80131520);
    /// @brief
    static constexpr int32 COR_E_TIMEOUT = static_cast<int32>(0x80131505);
    /// @brief
    static constexpr int32 COR_E_TYPEACCESS = static_cast<int32>(0x80131543);
    /// @brief
    static constexpr int32 COR_E_TYPEINITIALIZATION = static_cast<int32>(0x80131534);
    /// @brief
    static constexpr int32 COR_E_TYPELOAD = static_cast<int32>(0x80131522);
    /// @brief
    static constexpr int32 COR_E_TYPEUNLOADED = static_cast<int32>(0x80131013);
    /// @brief
    static constexpr int32 COR_E_UNAUTHORIZEDACCESS = static_cast<int32>(0x80070005);
    /// @brief
    static constexpr int32 COR_E_VERIFICATION = static_cast<int32>(0x8013150D);
    /// @brief
    static constexpr int32 COR_E_WAITHANDLECANNOTBEOPENED = static_cast<int32>(0x8013152C);
    /// @brief
    static constexpr int32 CO_E_NOTINITIALIZED = static_cast<int32>(0x800401F0);
    /// @brief
    static constexpr int32 DISP_E_OVERFLOW = static_cast<int32>(0x8002000A);
    /// @brief Operation aborted.
    static constexpr int32 E_ABORT = static_cast<int32>(0x80004004);
    /// @brief
    static constexpr int32 E_BOUNDS = static_cast<int32>(0x8000000B);
    /// @brief
    static constexpr int32 E_CHANGED_STATE = static_cast<int32>(0x8000000C);
    /// @brief
    static constexpr int32 E_FILENOTFOUND = static_cast<int32>(0x80070002);
    /// @brief Unspecified failure.
    static constexpr int32 E_FAIL = static_cast<int32>(0x80004005);
    /// @brief
    static constexpr int32 E_HANDLE = static_cast<int32>(0x80070006);
    /// @brief
    static constexpr int32 E_INVALIDARG = static_cast<int32>(0x80070057);
    /// @brief Not implemented.
    static constexpr int32 E_NOTIMPL = static_cast<int32>(0x80004001);
    /// @brief Attempted to read or write protected memory. This is often an indication that other memory is corrupt.
    static constexpr int32 E_POINTER = static_cast<int32>(0x80004003);
    /// @brief Unexpected failure.
    static constexpr int32 E_UNEXPECTED = static_cast<int32>(0x8000FFFF);
    /// @brief
    static constexpr int32 ERROR_MRM_MAP_NOT_FOUND = static_cast<int32>(0x80073B1F);
    /// @brief
    static constexpr int32 ERROR_TIMEOUT = static_cast<int32>(0x800705B4);
    /// @brief
    static constexpr int32 RO_E_CLOSED = static_cast<int32>(0x80000013);
    /// @brief
    static constexpr int32 RPC_E_CHANGED_MODE = static_cast<int32>(0x80010106);
    /// @brief
    static constexpr int32 TYPE_E_TYPEMISMATCH = static_cast<int32>(0x80028CA0);
    /// @brief
    static constexpr int32 STG_E_PATHNOTFOUND = static_cast<int32>(0x80030003);
    /// @brief
    static constexpr int32 CTL_E_PATHNOTFOUND = static_cast<int32>(0x800A004C);
    /// @brief
    static constexpr int32 CTL_E_FILENOTFOUND = static_cast<int32>(0x800A0035);
    /// @brief
    static constexpr int32 FUSION_E_INVALID_NAME = static_cast<int32>(0x80131047);
    /// @brief
    static constexpr int32 FUSION_E_REF_DEF_MISMATCH = static_cast<int32>(0x80131040);
    /// @brief
    static constexpr int32 ERROR_TOO_MANY_OPEN_FILES = static_cast<int32>(0x80070004);
    /// @brief
    static constexpr int32 ERROR_SHARING_VIOLATION = static_cast<int32>(0x80070020);
    /// @brief
    static constexpr int32 ERROR_LOCK_VIOLATION = static_cast<int32>(0x80070021);
    /// @brief
    static constexpr int32 ERROR_OPEN_FAILED = static_cast<int32>(0x8007006E);
    /// @brief
    static constexpr int32 ERROR_DISK_CORRUPT = static_cast<int32>(0x80070571);
    /// @brief
    static constexpr int32 ERROR_UNRECOGNIZED_VOLUME = static_cast<int32>(0x800703ED);
    /// @brief
    static constexpr int32 ERROR_DLL_INIT_FAILED = static_cast<int32>(0x8007045A);
    /// @brief
    static constexpr int32 MSEE_E_ASSEMBLYLOADINPROGRESS = static_cast<int32>(0x80131016);
    /// @brief
    static constexpr int32 ERROR_FILE_INVALID = static_cast<int32>(0x800703EE);
    /// @}

    /// @name Public Static Methods
    
    /// @{
   static  const std::error_category& h_results_category() noexcept {return xtd::h_results_category();}
    /// &}
  };
}
