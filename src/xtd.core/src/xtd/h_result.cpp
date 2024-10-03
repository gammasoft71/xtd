#include "../../include/xtd/array.h"
#include "../../include/xtd/call_once.h"
#include "../../include/xtd/h_result.h"
#include "../../include/xtd/literals.h"
#include "../../include/xtd/string.h"
#include "../../include/xtd/uint32.h"

using namespace xtd;

const std::unordered_map<int32, string>& h_result::get_h_result_names() noexcept {
  static auto h_result_names = std::unordered_map<int32, string> {
    {S_OK, "S_OK"},
    {S_FALSE, "S_FALSE"},
    {COR_E_ABANDONEDMUTEX, "COR_E_ABANDONEDMUTEX"},
    {COR_E_AMBIGUOUSIMPLEMENTATION, "COR_E_AMBIGUOUSIMPLEMENTATION"},
    {COR_E_AMBIGUOUSMATCH, "COR_E_AMBIGUOUSMATCH"},
    {COR_E_APPDOMAINUNLOADED, "COR_E_APPDOMAINUNLOADED"},
    {COR_E_APPLICATION, "COR_E_APPLICATION"},
    {COR_E_ARGUMENT, "COR_E_ARGUMENT"},
    {COR_E_ARGUMENTOUTOFRANGE, "COR_E_ARGUMENTOUTOFRANGE"},
    {COR_E_ARITHMETIC , "COR_E_ARITHMETIC"},
    {COR_E_ARRAYTYPEMISMATCH , "COR_E_ARRAYTYPEMISMATCH"},
    {COR_E_BADEXEFORMAT, "COR_E_BADEXEFORMAT"},
    {COR_E_BADIMAGEFORMAT, "COR_E_BADIMAGEFORMAT"},
    {COR_E_CANNOTUNLOADAPPDOMAIN, "COR_E_CANNOTUNLOADAPPDOMAIN"},
    {COR_E_CODECONTRACTFAILED, "COR_E_CODECONTRACTFAILED"},
    {COR_E_CONTEXTMARSHAL, "COR_E_CONTEXTMARSHAL"},
    {COR_E_CUSTOMATTRIBUTEFORMAT, "COR_E_CUSTOMATTRIBUTEFORMAT"},
    {COR_E_DATAMISALIGNED, "COR_E_DATAMISALIGNED"},
    {COR_E_DIRECTORYNOTFOUND, "COR_E_DIRECTORYNOTFOUND"},
    {COR_E_DIVIDEBYZERO, "COR_E_DIVIDEBYZERO"},
    {COR_E_DLLNOTFOUND, "COR_E_DLLNOTFOUND"},
    {COR_E_DUPLICATEWAITOBJECT, "COR_E_DUPLICATEWAITOBJECT"},
    {COR_E_ENDOFSTREAM, "COR_E_ENDOFSTREAM"},
    {COR_E_ENTRYPOINTNOTFOUND, "COR_E_ENTRYPOINTNOTFOUND"},
    {COR_E_EXCEPTION, "COR_E_EXCEPTION"},
    {COR_E_EXECUTIONENGINE, "COR_E_EXECUTIONENGINE"},
    {COR_E_FAILFAST, "COR_E_FAILFAST"},
    {COR_E_FIELDACCESS, "COR_E_FIELDACCESS"},
    {COR_E_FILELOAD, "COR_E_FILELOAD"},
    {COR_E_FILENOTFOUND, "COR_E_FILENOTFOUND"},
    {COR_E_FORMAT, "COR_E_FORMAT"},
    {COR_E_INDEXOUTOFRANGE, "COR_E_INDEXOUTOFRANGE"},
    {COR_E_INSUFFICIENTEXECUTIONSTACK, "COR_E_INSUFFICIENTEXECUTIONSTACK"},
    {COR_E_INSUFFICIENTMEMORY, "COR_E_INSUFFICIENTMEMORY"},
    {COR_E_INVALIDCAST, "COR_E_INVALIDCAST"},
    {COR_E_INVALIDCOMOBJECT, "COR_E_INVALIDCOMOBJECT"},
    {COR_E_INVALIDFILTERCRITERIA, "COR_E_INVALIDFILTERCRITERIA"},
    {COR_E_INVALIDOLEVARIANTTYPE, "COR_E_INVALIDOLEVARIANTTYPE"},
    {COR_E_INVALIDOPERATION, "COR_E_INVALIDOPERATION"},
    {COR_E_INVALIDPROGRAM, "COR_E_INVALIDPROGRAM"},
    {COR_E_IO, "COR_E_IO"},
    {COR_E_KEYNOTFOUND, "COR_E_KEYNOTFOUND"},
    {COR_E_MARSHALDIRECTIVE, "COR_E_MARSHALDIRECTIVE"},
    {COR_E_MEMBERACCESS, "COR_E_MEMBERACCESS"},
    {COR_E_METHODACCESS, "COR_E_METHODACCESS"},
    {COR_E_MISSINGFIELD, "COR_E_MISSINGFIELD"},
    {COR_E_MISSINGMANIFESTRESOURCE, "COR_E_MISSINGMANIFESTRESOURCE"},
    {COR_E_MISSINGMEMBER, "COR_E_MISSINGMEMBER"},
    {COR_E_MISSINGMETHOD, "COR_E_MISSINGMETHOD"},
    {COR_E_MISSINGSATELLITEASSEMBLY, "COR_E_MISSINGSATELLITEASSEMBLY"},
    {COR_E_MULTICASTNOTSUPPORTED, "COR_E_MULTICASTNOTSUPPORTED"},
    {COR_E_NOTFINITENUMBER, "COR_E_NOTFINITENUMBER"},
    {COR_E_NOTSUPPORTED, "COR_E_NOTSUPPORTED"},
    {COR_E_OBJECTCLOSED, "COR_E_OBJECTCLOSED"},
    {COR_E_OPERATIONCANCELED, "COR_E_OPERATIONCANCELED"},
    {COR_E_OUTOFMEMORY, "COR_E_OUTOFMEMORY"},
    {COR_E_OVERFLOW, "COR_E_OVERFLOW"},
    {COR_E_PATHTOOLONG, "COR_E_PATHTOOLONG"},
    {COR_E_PLATFORMNOTSUPPORTED, "COR_E_PLATFORMNOTSUPPORTED"},
    {COR_E_RANK, "COR_E_RANK"},
    {COR_E_REFLECTIONTYPELOAD, "COR_E_REFLECTIONTYPELOAD"},
    {COR_E_RUNTIMEWRAPPED, "COR_E_RUNTIMEWRAPPED"},
    {COR_E_SAFEARRAYRANKMISMATCH, "COR_E_SAFEARRAYRANKMISMATCH"},
    {COR_E_SAFEARRAYTYPEMISMATCH, "COR_E_SAFEARRAYTYPEMISMATCH"},
    {COR_E_SECURITY, "COR_E_SECURITY"},
    {COR_E_SERIALIZATION, "COR_E_SERIALIZATION"},
    {COR_E_STACKOVERFLOW, "COR_E_STACKOVERFLOW"},
    {COR_E_SYNCHRONIZATIONLOCK, "COR_E_SYNCHRONIZATIONLOCK"},
    {COR_E_SYSTEM, "COR_E_SYSTEM"},
    {COR_E_TARGET, "COR_E_TARGET"},
    {COR_E_TARGETINVOCATION, "COR_E_TARGETINVOCATION"},
    {COR_E_TARGETPARAMCOUNT, "COR_E_TARGETPARAMCOUNT"},
    {COR_E_THREADABORTED, "COR_E_THREADABORTED"},
    {COR_E_THREADINTERRUPTED, "COR_E_THREADINTERRUPTED"},
    {COR_E_THREADSTART, "COR_E_THREADSTART"},
    {COR_E_THREADSTATE, "COR_E_THREADSTATE"},
    {COR_E_TIMEOUT, "COR_E_TIMEOUT"},
    {COR_E_TYPEACCESS, "COR_E_TYPEACCESS"},
    {COR_E_TYPEINITIALIZATION, "COR_E_TYPEINITIALIZATION"},
    {COR_E_TYPELOAD, "COR_E_TYPELOAD"},
    {COR_E_TYPEUNLOADED, "COR_E_TYPEUNLOADED"},
    {COR_E_UNAUTHORIZEDACCESS, "COR_E_UNAUTHORIZEDACCESS"},
    {COR_E_VERIFICATION, "COR_E_VERIFICATION"},
    {COR_E_WAITHANDLECANNOTBEOPENED, "COR_E_WAITHANDLECANNOTBEOPENED"},
    {CO_E_NOTINITIALIZED, "CO_E_NOTINITIALIZED"},
    {DISP_E_PARAMNOTFOUND, "DISP_E_PARAMNOTFOUND"},
    {DISP_E_TYPEMISMATCH, "DISP_E_TYPEMISMATCH"},
    {DISP_E_BADVARTYPE, "DISP_E_BADVARTYPE"},
    {DISP_E_OVERFLOW, "DISP_E_OVERFLOW"},
    {DISP_E_DIVBYZERO, "DISP_E_DIVBYZERO"},
    {E_ABORT, "E_ABORT"},
    {E_BOUNDS, "E_BOUNDS"},
    {E_CHANGED_STATE, "E_CHANGED_STATE"},
    {E_FILENOTFOUND, "E_FILENOTFOUND"},
    {E_FAIL, "E_FAIL"},
    {E_HANDLE, "E_HANDLE"},
    {E_INVALIDARG, "E_INVALIDARG"},
    {E_NOTIMPL, "E_NOTIMPL"},
    {E_POINTER, "E_POINTER"},
    {E_UNEXPECTED, "E_UNEXPECTED"},
    {ERROR_MRM_MAP_NOT_FOUND, "ERROR_MRM_MAP_NOT_FOUND"},
    {ERROR_TIMEOUT, "ERROR_TIMEOUT"},
    {RO_E_CLOSED, "RO_E_CLOSED"},
    {RPC_E_CHANGED_MODE, "RPC_E_CHANGED_MODE"},
    {TYPE_E_TYPEMISMATCH, "TYPE_E_TYPEMISMATCH"},
    {STG_E_PATHNOTFOUND, "STG_E_PATHNOTFOUND"},
    {CTL_E_PATHNOTFOUND, "CTL_E_PATHNOTFOUND"},
    {CTL_E_FILENOTFOUND, "CTL_E_FILENOTFOUND"},
    {FUSION_E_INVALID_NAME, "FUSION_E_INVALID_NAME"},
    {FUSION_E_REF_DEF_MISMATCH, "FUSION_E_REF_DEF_MISMATCH"},
    {ERROR_TOO_MANY_OPEN_FILES, "ERROR_TOO_MANY_OPEN_FILES"},
    {ERROR_SHARING_VIOLATION, "ERROR_SHARING_VIOLATION"},
    {ERROR_LOCK_VIOLATION, "ERROR_LOCK_VIOLATION"},
    {ERROR_OPEN_FAILED, "ERROR_OPEN_FAILED"},
    {ERROR_DISK_CORRUPT, "ERROR_DISK_CORRUPT"},
    {ERROR_UNRECOGNIZED_VOLUME, "ERROR_UNRECOGNIZED_VOLUME"},
    {ERROR_DLL_INIT_FAILED, "ERROR_DLL_INIT_FAILED"},
    {MSEE_E_ASSEMBLYLOADINPROGRESS, "MSEE_E_ASSEMBLYLOADINPROGRESS"},
    {ERROR_FILE_INVALID, "ERROR_FILE_INVALID"},
  };
  return h_result_names;
}
  
const std::unordered_map<int32, string>& h_result::get_h_result_messages() noexcept {
  static auto h_result_messages = std::unordered_map<int32, string> {
    {S_OK, "Operation successful."_t},
    {S_FALSE, "Operation successful but returned no results."_t},
    {COR_E_ABANDONEDMUTEX, "The wait completed due to an abandoned mutex."_t},
    {COR_E_AMBIGUOUSIMPLEMENTATION, "Ambiguous implementation found."_t},
    {COR_E_AMBIGUOUSMATCH, "Ambiguous match found."_t},
    {COR_E_APPDOMAINUNLOADED, "Attempted to access an unloaded AppDomain."_t},
    {COR_E_APPLICATION, "Error in the application."_t},
    {COR_E_ARGUMENT, "Value does not fall within the expected range."_t},
    {COR_E_ARGUMENTOUTOFRANGE, "Specified argument was out of the range of valid values."_t},
    {COR_E_ARITHMETIC , "Overflow or underflow in the arithmetic operation."},
    {COR_E_ARRAYTYPEMISMATCH , "Attempted to access an element as a type incompatible with the array."_t},
    {COR_E_BADEXEFORMAT, "Format of the executable (.exe) cannot be run."_t},
    {COR_E_BADIMAGEFORMAT, "Format of the executable (.exe) or library (.dll) is invalid."_t},
    {COR_E_CANNOTUNLOADAPPDOMAIN, "Attempt to unload the AppDomain failed."_t},
    {COR_E_CODECONTRACTFAILED, "A code contract (ie, precondition, postcondition, invariant, or assert) failed."_t},
    {COR_E_CONTEXTMARSHAL, "Attempted to marshal an object across a context boundary."_t},
    {COR_E_CUSTOMATTRIBUTEFORMAT, "Binary format of the specified custom attribute was invalid."_t},
    {COR_E_DATAMISALIGNED, "A datatype misalignment was detected in a load or store instruction."_t},
    {COR_E_DIRECTORYNOTFOUND, "Attempted to access a path that is not on the disk."_t},
    {COR_E_DIVIDEBYZERO, "Attempted to divide by zero."_t},
    {COR_E_DLLNOTFOUND, "Dll was not found."_t},
    {COR_E_DUPLICATEWAITOBJECT, ""_t},
    {COR_E_ENDOFSTREAM, ""_t},
    {COR_E_ENTRYPOINTNOTFOUND, ""_t},
    {COR_E_EXCEPTION, "Exception of type 'xtd::exception' was thrown."_t},
    {COR_E_EXECUTIONENGINE, ""_t},
    {COR_E_FAILFAST, ""_t},
    {COR_E_FIELDACCESS, ""_t},
    {COR_E_FILELOAD, ""_t},
    {COR_E_FILENOTFOUND, ""_t},
    {COR_E_FORMAT, ""_t},
    {COR_E_INDEXOUTOFRANGE, ""_t},
    {COR_E_INSUFFICIENTEXECUTIONSTACK, ""_t},
    {COR_E_INSUFFICIENTMEMORY, ""_t},
    {COR_E_INVALIDCAST, ""_t},
    {COR_E_INVALIDCOMOBJECT, ""_t},
    {COR_E_INVALIDFILTERCRITERIA, ""_t},
    {COR_E_INVALIDOLEVARIANTTYPE, ""_t},
    {COR_E_INVALIDOPERATION, ""_t},
    {COR_E_INVALIDPROGRAM, ""_t},
    {COR_E_IO, ""_t},
    {COR_E_KEYNOTFOUND, ""_t},
    {COR_E_MARSHALDIRECTIVE, ""_t},
    {COR_E_MEMBERACCESS, ""_t},
    {COR_E_METHODACCESS, ""_t},
    {COR_E_MISSINGFIELD, ""_t},
    {COR_E_MISSINGMANIFESTRESOURCE, ""_t},
    {COR_E_MISSINGMEMBER, ""_t},
    {COR_E_MISSINGMETHOD, ""_t},
    {COR_E_MISSINGSATELLITEASSEMBLY, ""_t},
    {COR_E_MULTICASTNOTSUPPORTED, ""_t},
    {COR_E_NOTFINITENUMBER, ""_t},
    {COR_E_NOTSUPPORTED, ""_t},
    {COR_E_OBJECTCLOSED, "Cannot access a closed object."_t},
    {COR_E_OPERATIONCANCELED, ""_t},
    {COR_E_OUTOFMEMORY, ""_t},
    {COR_E_OVERFLOW, ""_t},
    {COR_E_PATHTOOLONG, ""_t},
    {COR_E_PLATFORMNOTSUPPORTED, ""_t},
    {COR_E_RANK, "Attempted to operate on an array with the incorrect number of dimensions."_t},
    {COR_E_REFLECTIONTYPELOAD, ""_t},
    {COR_E_RUNTIMEWRAPPED, ""_t},
    {COR_E_SAFEARRAYRANKMISMATCH, ""_t},
    {COR_E_SAFEARRAYTYPEMISMATCH, ""_t},
    {COR_E_SECURITY, ""_t},
    {COR_E_SERIALIZATION, ""_t},
    {COR_E_STACKOVERFLOW, ""_t},
    {COR_E_SYNCHRONIZATIONLOCK, ""_t},
    {COR_E_SYSTEM, "System error."_t},
    {COR_E_TARGET, ""_t},
    {COR_E_TARGETINVOCATION, ""_t},
    {COR_E_TARGETPARAMCOUNT, ""_t},
    {COR_E_THREADABORTED, ""_t},
    {COR_E_THREADINTERRUPTED, ""_t},
    {COR_E_THREADSTART, ""_t},
    {COR_E_THREADSTATE, ""_t},
    {COR_E_TIMEOUT, ""_t},
    {COR_E_TYPEACCESS, ""_t},
    {COR_E_TYPEINITIALIZATION, ""_t},
    {COR_E_TYPELOAD, ""_t},
    {COR_E_TYPEUNLOADED, ""_t},
    {COR_E_UNAUTHORIZEDACCESS, ""_t},
    {COR_E_VERIFICATION, ""_t},
    {COR_E_WAITHANDLECANNOTBEOPENED, ""_t},
    {CO_E_NOTINITIALIZED, ""_t},
    {CO_E_NOTINITIALIZED, ""_t},
    {DISP_E_PARAMNOTFOUND, ""_t},
    {DISP_E_TYPEMISMATCH, ""_t},
    {DISP_E_BADVARTYPE, ""_t},
    {DISP_E_OVERFLOW, ""_t},
    {DISP_E_DIVBYZERO, ""_t},
    {E_ABORT, "Operation aborted."_t},
    {E_BOUNDS, ""_t},
    {E_CHANGED_STATE, ""_t},
    {E_FILENOTFOUND, ""_t},
    {E_FAIL, "Unspecified failure."_t},
    {E_HANDLE, ""_t},
    {E_INVALIDARG, ""_t},
    {E_NOTIMPL, "The method or operation is not implemented."_t},
    {E_POINTER, "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."_t},
    {E_UNEXPECTED, ""_t},
    {ERROR_MRM_MAP_NOT_FOUND, ""_t},
    {ERROR_TIMEOUT, ""_t},
    {RO_E_CLOSED, ""_t},
    {RPC_E_CHANGED_MODE, ""_t},
    {TYPE_E_TYPEMISMATCH, ""_t},
    {STG_E_PATHNOTFOUND, ""_t},
    {CTL_E_PATHNOTFOUND, ""_t},
    {CTL_E_FILENOTFOUND, ""_t},
    {FUSION_E_INVALID_NAME, ""_t},
    {FUSION_E_REF_DEF_MISMATCH, ""_t},
    {ERROR_TOO_MANY_OPEN_FILES, ""_t},
    {ERROR_SHARING_VIOLATION, ""_t},
    {ERROR_LOCK_VIOLATION, ""_t},
    {ERROR_OPEN_FAILED, ""_t},
    {ERROR_DISK_CORRUPT, ""_t},
    {ERROR_UNRECOGNIZED_VOLUME, ""_t},
    {ERROR_DLL_INIT_FAILED, ""_t},
    {MSEE_E_ASSEMBLYLOADINPROGRESS, ""_t},
    {ERROR_FILE_INVALID, ""_t},
  };
  return h_result_messages;
}

const xtd::array<int32>& h_result::get_h_results() noexcept {
  static auto h_results = xtd::array<int32> {};
  call_once_ {
    for (auto item : get_h_result_names())
      h_results.push_back(item.first);
  };
  return h_results;
}

string h_result::get_message(int32 h_result) noexcept {
  auto iterator = get_h_result_messages().find(h_result);
  if (iterator == get_h_result_messages().end()) return string::format("Unknown h_result 0x{0:X8} ({0})", static_cast<uint32>(h_result));
  return iterator->second;
}

string h_result::get_name(int32 h_result) noexcept {
  auto iterator = get_h_result_names().find(h_result);
  if (iterator == get_h_result_names().end()) return string::format("0x{:X8}", static_cast<uint32>(h_result));
  return iterator->second;
}

const std::error_category& h_result::h_result_category() noexcept {
  struct h_result_category : public std::error_category {
    std::string message(int h_result) const override {return  xtd::h_result::get_message(h_result);}
    const char* name() const noexcept override{return "h_result_category";}
  };

  static auto result = h_result_category {};
  return result;
}

std::error_code h_result::make_error_code(int h_result) noexcept {
  return std::error_code {h_result, h_result_category()};
}

string h_result::to_String(int32 h_result) noexcept {
  return get_name(h_result);
}
