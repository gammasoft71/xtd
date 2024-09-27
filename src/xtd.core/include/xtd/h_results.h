/// @file
/// @brief Contains h_results class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "int32.h"
#include "static.h"

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
    /// @brief The operation attempted to access data outside the valid range
    static constexpr int32 E_BOUNDS = static_cast<int32>(0x8000000B);
    static constexpr int32 E_CHANGED_STATE = static_cast<int32>(0x8000000C);
    /// @brief The object has been closed.
    static constexpr int32 RO_E_CLOSED = static_cast<int32>(0x80000013);
    static constexpr int32 E_FAIL = static_cast<int32>(0x80004005);
    static constexpr int32 E_NOTIMPL = static_cast<int32>(0x80004001);
    /// @brief Invalid pointer
    static constexpr int32 E_POINTER = static_cast<int32>(0x80004003);
    static constexpr int32 REGDB_E_CLASSNOTREG = static_cast<int32>(0x80040154);
    static constexpr int32 COR_E_AMBIGUOUSMATCH = static_cast<int32>(0x8000211D);
    static constexpr int32 COR_E_APPDOMAINUNLOADED = static_cast<int32>(0x80131014);
    static constexpr int32 COR_E_APPLICATION = static_cast<int32>(0x80131600);
    static constexpr int32 COR_E_ARGUMENT = static_cast<int32>(0x80070057);
    static constexpr int32 COR_E_ARGUMENTOUTOFRANGE = static_cast<int32>(0x80131502);
    static constexpr int32 COR_E_ARITHMETIC = static_cast<int32>(0x80070216);
    static constexpr int32 COR_E_ARRAYTYPEMISMATCH = static_cast<int32>(0x80131503);
    static constexpr int32 COR_E_BADIMAGEFORMAT = static_cast<int32>(0x8007000B);
    static constexpr int32 COR_E_TYPEUNLOADED = static_cast<int32>(0x80131013);
    static constexpr int32 COR_E_CANNOTUNLOADAPPDOMAIN = static_cast<int32>(0x80131015);
    static constexpr int32 COR_E_COMEMULATE = static_cast<int32>(0x80131535);
    static constexpr int32 COR_E_CONTEXTMARSHAL = static_cast<int32>(0x80131504);
    static constexpr int32 COR_E_DATAMISALIGNED = static_cast<int32>(0x80131541);
    static constexpr int32 COR_E_TIMEOUT = static_cast<int32>(0x80131505);
    static constexpr int32 COR_E_CUSTOMATTRIBUTEFORMAT = static_cast<int32>(0x80131605);
    static constexpr int32 COR_E_DIVIDEBYZERO = static_cast<int32>(0x80020012); // DISP_E_DIVBYZERO
    static constexpr int32 COR_E_DUPLICATEWAITOBJECT = static_cast<int32>(0x80131529);
    static constexpr int32 COR_E_EXCEPTION = static_cast<int32>(0x80131500);
    static constexpr int32 COR_E_EXECUTIONENGINE = static_cast<int32>(0x80131506);
    static constexpr int32 COR_E_FIELDACCESS = static_cast<int32>(0x80131507);
    static constexpr int32 COR_E_FORMAT = static_cast<int32>(0x80131537);
    static constexpr int32 COR_E_INDEXOUTOFRANGE = static_cast<int32>(0x80131508);
    static constexpr int32 COR_E_INSUFFICIENTMEMORY = static_cast<int32>(0x8013153D);
    static constexpr int32 COR_E_INSUFFICIENTEXECUTIONSTACK = static_cast<int32>(0x80131578);
    static constexpr int32 COR_E_INVALIDCAST = static_cast<int32>(0x80004002);
    static constexpr int32 COR_E_INVALIDCOMOBJECT = static_cast<int32>(0x80131527);
    static constexpr int32 COR_E_INVALIDFILTERCRITERIA = static_cast<int32>(0x80131601);
    static constexpr int32 COR_E_INVALIDOLEVARIANTTYPE = static_cast<int32>(0x80131531);
    static constexpr int32 COR_E_INVALIDOPERATION = static_cast<int32>(0x80131509);
    static constexpr int32 COR_E_INVALIDPROGRAM = static_cast<int32>(0x8013153A);
    static constexpr int32 COR_E_KEYNOTFOUND = static_cast<int32>(0x80131577);
    static constexpr int32 COR_E_MARSHALDIRECTIVE = static_cast<int32>(0x80131535);
    static constexpr int32 COR_E_MEMBERACCESS = static_cast<int32>(0x8013151A);
    static constexpr int32 COR_E_METHODACCESS = static_cast<int32>(0x80131510);
    static constexpr int32 COR_E_MISSINGFIELD = static_cast<int32>(0x80131511);
    static constexpr int32 COR_E_MISSINGMANIFESTRESOURCE = static_cast<int32>(0x80131532);
    static constexpr int32 COR_E_MISSINGMEMBER = static_cast<int32>(0x80131512);
    static constexpr int32 COR_E_MISSINGMETHOD = static_cast<int32>(0x80131513);
    static constexpr int32 COR_E_MISSINGSATELLITEASSEMBLY = static_cast<int32>(0x80131536);
    static constexpr int32 COR_E_MULTICASTNOTSUPPORTED = static_cast<int32>(0x80131514);
    static constexpr int32 COR_E_NOTFINITENUMBER = static_cast<int32>(0x80131528);
    static constexpr int32 COR_E_PLATFORMNOTSUPPORTED = static_cast<int32>(0x80131539);
    static constexpr int32 COR_E_NOTSUPPORTED = static_cast<int32>(0x80131515);
    static constexpr int32 COR_E_NULLREFERENCE = static_cast<int32>(0x80004003);
    static constexpr int32 COR_E_OBJECTDISPOSED = static_cast<int32>(0x80131622);
    static constexpr int32 COR_E_OPERATIONCANCELED = static_cast<int32>(0x8013153B);
    static constexpr int32 COR_E_OUTOFMEMORY = static_cast<int32>(0x8007000E);
    static constexpr int32 COR_E_OVERFLOW = static_cast<int32>(0x80131516);
    static constexpr int32 COR_E_RANK = static_cast<int32>(0x80131517);
    static constexpr int32 COR_E_REFLECTIONTYPELOAD    = static_cast<int32>(0x80131602);
    static constexpr int32 COR_E_RUNTIMEWRAPPED = static_cast<int32>(0x8013153E);
    static constexpr int32 COR_E_SAFEARRAYRANKMISMATCH = static_cast<int32>(0x80131538);
    static constexpr int32 COR_E_SAFEARRAYTYPEMISMATCH = static_cast<int32>(0x80131533);
    static constexpr int32 COR_E_SAFEHANDLEMISSINGATTRIBUTE = static_cast<int32>(0x80131623);
    static constexpr int32 COR_E_SECURITY = static_cast<int32>(0x8013150A);
    static constexpr int32 COR_E_SERIALIZATION = static_cast<int32>(0x8013150C);
    static constexpr int32 COR_E_SEMAPHOREFULL = static_cast<int32>(0x8013152B);
    static constexpr int32 COR_E_WAITHANDLECANNOTBEOPENED = static_cast<int32>(0x8013152C);
    static constexpr int32 COR_E_ABANDONEDMUTEX = static_cast<int32>(0x8013152D);
    static constexpr int32 COR_E_STACKOVERFLOW = static_cast<int32>(0x800703E9);
    static constexpr int32 COR_E_SYNCHRONIZATIONLOCK = static_cast<int32>(0x80131518);
    static constexpr int32 COR_E_SYSTEM = static_cast<int32>(0x80131501);
    static constexpr int32 COR_E_TARGET = static_cast<int32>(0x80131603);
    static constexpr int32 COR_E_TARGETINVOCATION = static_cast<int32>(0x80131604);
    static constexpr int32 COR_E_TARGETPARAMCOUNT = static_cast<int32>(0x8002000e);
    static constexpr int32 COR_E_THREADABORTED = static_cast<int32>(0x80131530);
    static constexpr int32 COR_E_THREADINTERRUPTED = static_cast<int32>(0x80131519);
    static constexpr int32 COR_E_THREADSTATE = static_cast<int32>(0x80131520);
    static constexpr int32 COR_E_THREADSTOP = static_cast<int32>(0x80131521);
    static constexpr int32 COR_E_THREADSTART = static_cast<int32>(0x80131525);
    static constexpr int32 COR_E_TYPEACCESS = static_cast<int32>(0x80131543);
    static constexpr int32 COR_E_TYPEINITIALIZATION = static_cast<int32>(0x80131534);
    static constexpr int32 COR_E_TYPELOAD = static_cast<int32>(0x80131522);
    static constexpr int32 COR_E_ENTRYPOINTNOTFOUND = static_cast<int32>(0x80131523);
    static constexpr int32 COR_E_DLLNOTFOUND = static_cast<int32>(0x80131524);
    static constexpr int32 COR_E_UNAUTHORIZEDACCESS = static_cast<int32>(0x80070005);
    static constexpr int32 COR_E_UNSUPPORTEDFORMAT = static_cast<int32>(0x80131523);
    static constexpr int32 COR_E_VERIFICATION = static_cast<int32>(0x8013150D);
    static constexpr int32 COR_E_HOSTPROTECTION = static_cast<int32>(0x80131640);
    static constexpr int32 CORSEC_E_MIN_GRANT_FAIL = static_cast<int32>(0x80131417);
    static constexpr int32 CORSEC_E_NO_EXEC_PERM = static_cast<int32>(0x80131418);
    static constexpr int32 CORSEC_E_POLICY_EXCEPTION = static_cast<int32>(0x80131416);
    static constexpr int32 CORSEC_E_XMLSYNTAX = static_cast<int32>(0x80131418);
    static constexpr int32 NTE_FAIL = static_cast<int32>(0x80090020);
    static constexpr int32 CORSEC_E_CRYPTO = static_cast<int32>(0x80131430);
    static constexpr int32 CORSEC_E_CRYPTO_UNEX_OPER = static_cast<int32>(0x80131431);
    static constexpr int32 DISP_E_OVERFLOW = static_cast<int32>(0x8002000a);
    static constexpr int32 FUSION_E_REF_DEF_MISMATCH = static_cast<int32>(0x80131040);
    static constexpr int32 FUSION_E_INVALID_NAME = static_cast<int32>(0x80131047);
    static constexpr int32 TYPE_E_TYPEMISMATCH = static_cast<int32>(0x80028ca0);
  };
}
