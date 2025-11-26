#include "../../include/xtd/array.hpp"
#include "../../include/xtd/call_once.hpp"
#include "../../include/xtd/h_result.hpp"
#include "../../include/xtd/string.hpp"
#include "../../include/xtd/uint32.hpp"
#include "../../include/xtd/collections/generic/list.hpp"

using namespace xtd;
using namespace xtd::collections::generic;

bool h_result::failed(int32 h_result) noexcept {
  return h_result < 0;
}

int32 h_result::get_code(int32 h_result) noexcept {
  return h_result & static_cast<int32>(0xFFFF);
}

int32 h_result::get_facility(int32 h_result) noexcept {
  return (h_result >> 16) & static_cast<int32>(0x1FFF);
}

const xtd::array<int32>& h_result::get_h_results() noexcept {
  static auto h_results = array<int32> {};
  call_once_ {
    static auto tmp_h_results = list<int32> {};
    for (auto item : get_names())
      tmp_h_results.add(item.first);
    h_results = array<int32>(tmp_h_results);
  };
  return h_results;
}

string h_result::get_message(int32 h_result) noexcept {
  auto iterator = get_messages().find(h_result);
  if (iterator == get_messages().end()) return string::format("Unknown h_result 0x{:X8} ({})", static_cast<uint32>(h_result), h_result);
  return iterator->second;
}

const std::unordered_map<int32, string>& h_result::get_names() noexcept {
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
    {COR_E_ARITHMETIC, "COR_E_ARITHMETIC"},
    {COR_E_ARRAYTYPEMISMATCH, "COR_E_ARRAYTYPEMISMATCH"},
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
    {COR_E_DRIVENOTFOUND, "COR_E_DRIVENOTFOUND"},
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

string h_result::get_name(int32 h_result) noexcept {
  auto iterator = get_names().find(h_result);
  if (iterator == get_names().end()) return string::format("0x{:X8}", static_cast<uint32>(h_result));
  return iterator->second;
}

const std::unordered_map<int32, string>& h_result::get_messages() noexcept {
  static auto h_result_messages = std::unordered_map<int32, string> {
    {S_OK, "Operation successful."},
    {S_FALSE, "Operation successful but returned no results."},
    {COR_E_ABANDONEDMUTEX, "The wait completed due to an abandoned mutex."},
    {COR_E_AMBIGUOUSIMPLEMENTATION, "Ambiguous implementation found."},
    {COR_E_AMBIGUOUSMATCH, "Ambiguous match found."},
    {COR_E_APPDOMAINUNLOADED, "Attempted to access an unloaded AppDomain."},
    {COR_E_APPLICATION, "Error in the application."},
    {COR_E_ARGUMENT, "Value does not fall within the expected range."},
    {COR_E_ARGUMENTOUTOFRANGE, "Specified argument was out of the range of valid values."},
    {COR_E_ARITHMETIC, "Overflow or underflow in the arithmetic operation."},
    {COR_E_ARRAYTYPEMISMATCH, "Attempted to access an element as a type incompatible with the array."},
    {COR_E_BADEXEFORMAT, "Format of the executable (.exe) cannot be run."},
    {COR_E_BADIMAGEFORMAT, "Format of the executable (.exe) or library (.dll) is invalid."},
    {COR_E_CANNOTUNLOADAPPDOMAIN, "Attempt to unload the AppDomain failed."},
    {COR_E_CODECONTRACTFAILED, "A code contract (ie, precondition, postcondition, invariant, or assert) failed."},
    {COR_E_CONTEXTMARSHAL, "Attempted to marshal an object across a context boundary."},
    {COR_E_CUSTOMATTRIBUTEFORMAT, "Binary format of the specified custom attribute was invalid."},
    {COR_E_DATAMISALIGNED, "A datatype misalignment was detected in a load or store instruction."},
    {COR_E_DIRECTORYNOTFOUND, "Attempted to access a path that is not on the disk."},
    {COR_E_DIVIDEBYZERO, "Attempted to divide by zero."},
    {COR_E_DLLNOTFOUND, "Dll was not found."},
    {COR_E_DRIVENOTFOUND, "Could not find the drive. The drive might not be ready or might not be mapped."},
    {COR_E_DUPLICATEWAITOBJECT, "Duplicate objects in argument."},
    {COR_E_ENDOFSTREAM, "Attempted to read past the end of the stream."},
    {COR_E_ENTRYPOINTNOTFOUND, "Entry point was not found."},
    {COR_E_EXCEPTION, "Exception of type 'xtd::exception' was thrown."},
    {COR_E_EXECUTIONENGINE, "Internal error in the runtime."},
    {COR_E_FAILFAST, "Fail fast."},
    {COR_E_FIELDACCESS, "Attempted to access a field that is not accessible by the caller."},
    {COR_E_FILELOAD, "Could not load the specified file."},
    {COR_E_FILENOTFOUND, "Unable to find the specified file."},
    {COR_E_FORMAT, "One of the identified items was in an invalid format."},
    {COR_E_INDEXOUTOFRANGE, "Index was outside the bounds of the array."},
    {COR_E_INSUFFICIENTEXECUTIONSTACK, "Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space."},
    {COR_E_INSUFFICIENTMEMORY, "Insufficient memory to continue the execution of the program."},
    {COR_E_INVALIDCAST, "Specified cast is not valid."},
    {COR_E_INVALIDCOMOBJECT, "Attempt has been made to use a COM object that does not have a backing class factory."},
    {COR_E_INVALIDFILTERCRITERIA, "Specified filter criteria was invalid."},
    {COR_E_INVALIDOLEVARIANTTYPE, "Specified OLE variant was invalid."},
    {COR_E_INVALIDOPERATION, "Operation is not valid due to the current state of the object."},
    {COR_E_INVALIDPROGRAM, "xtd detected an invalid program."},
    {COR_E_IO, "I/O error occurred."},
    {COR_E_KEYNOTFOUND, "The given key was not present in the dictionary."},
    {COR_E_MARSHALDIRECTIVE, "Marshaling directives are invalid."},
    {COR_E_MEMBERACCESS, "Cannot access member."},
    {COR_E_METHODACCESS, "Attempt to access the method failed."},
    {COR_E_MISSINGFIELD, "Attempted to access a non-existing field."},
    {COR_E_MISSINGMANIFESTRESOURCE, "Attempted to access a missing manifest resource."},
    {COR_E_MISSINGMEMBER, "Attempted to access a missing member."},
    {COR_E_MISSINGMETHOD, "Attempted to access a missing method."},
    {COR_E_MISSINGSATELLITEASSEMBLY, "Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application."},
    {COR_E_MULTICASTNOTSUPPORTED, "Attempted to add multiple callbacks to a delegate that does not support multicast."},
    {COR_E_NOTFINITENUMBER, "Number encountered was not a finite quantity."},
    {COR_E_NOTSUPPORTED, "Specified method is not supported."},
    {COR_E_OBJECTCLOSED, "Cannot access a closed object."},
    {COR_E_OPERATIONCANCELED, "The operation was canceled."},
    {COR_E_OUTOFMEMORY, "Insufficient memory to continue the execution of the program."},
    {COR_E_OVERFLOW, "Arithmetic operation resulted in an overflow."},
    {COR_E_PATHTOOLONG, "The specified file name or path is too long, or a component of the specified path is too long."},
    {COR_E_PLATFORMNOTSUPPORTED, "Operation is not supported on this platform."},
    {COR_E_RANK, "Attempted to operate on an array with the incorrect number of dimensions."},
    {COR_E_REFLECTIONTYPELOAD, "Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown."},
    {COR_E_RUNTIMEWRAPPED, "An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception."},
    {COR_E_SAFEARRAYRANKMISMATCH, "Specified array was not of the expected rank."},
    {COR_E_SAFEARRAYTYPEMISMATCH, "Specified array was not of the expected type."},
    {COR_E_SECURITY, "Security error."},
    {COR_E_SERIALIZATION, "Serialization error."},
    {COR_E_STACKOVERFLOW, "Operation caused a stack overflow."},
    {COR_E_SYNCHRONIZATIONLOCK, "Object synchronization method was called from an unsynchronized block of code."},
    {COR_E_SYSTEM, "System error."},
    {COR_E_TARGET, "Exception of type 'xtd::reflection::target_exception' was thrown."},
    {COR_E_TARGETINVOCATION, "Exception has been thrown by the target of an invocation."},
    {COR_E_TARGETPARAMCOUNT, "Number of parameters specified does not match the expected number."},
    {COR_E_THREADABORTED, "Thread was aborted."},
    {COR_E_THREADINTERRUPTED, "Thread was interrupted from a waiting state."},
    {COR_E_THREADSTART, "Thread start failure."},
    {COR_E_THREADSTATE, "Thread was in an invalid state for the operation being executed."},
    {COR_E_TIMEOUT, "The operation has timed out."},
    {COR_E_TYPEACCESS, "Attempt to access the type failed."},
    {COR_E_TYPEINITIALIZATION, "The type initializer for 'value' threw an exception."},
    {COR_E_TYPELOAD, "Failure has occurred while loading a type."},
    {COR_E_TYPEUNLOADED, "Type had been unloaded."},
    {COR_E_UNAUTHORIZEDACCESS, "Attempted to perform an unauthorized operation."},
    {COR_E_VERIFICATION, "Operation could destabilize the runtime."},
    {COR_E_WAITHANDLECANNOTBEOPENED, "No handle of the given name exists."},
    {CO_E_NOTINITIALIZED, "Not initialized"},
    {DISP_E_PARAMNOTFOUND, "Could not find the parameter."},
    {DISP_E_TYPEMISMATCH, "Attempt to access a variable with an incompatible type."},
    {DISP_E_BADVARTYPE, "Invalid variable type."},
    {DISP_E_OVERFLOW, "Arithmetic operation resulted in an overflow."},
    {DISP_E_DIVBYZERO, "Attempted to divide by zero."},
    {E_ABORT, "Operation aborted."},
    {E_BOUNDS, "Bounds exception"},
    {E_CHANGED_STATE, "The state has been modified."},
    {E_FILENOTFOUND, "Unable to find the specified file."},
    {E_FAIL, "Unspecified failure."},
    {E_HANDLE, "The handle is invalid."},
    {E_INVALIDARG, "Value does not fall within the expected range."},
    {E_NOTIMPL, "The method or operation is not implemented."},
    {E_POINTER, "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."},
    {E_UNEXPECTED, "Unexpected failure."},
    {ERROR_MRM_MAP_NOT_FOUND, "Resource map not found."},
    {ERROR_TIMEOUT, "The operation has timed out."},
    {RO_E_CLOSED, "The object has been closed."},
    {RPC_E_CHANGED_MODE, "Cannot change the current thread mode."},
    {TYPE_E_TYPEMISMATCH, "Incompatible type."},
    {STG_E_PATHNOTFOUND, "Attempted to access a path that is not on the disk."},
    {CTL_E_PATHNOTFOUND, "Attempted to access a path that is not on the disk."},
    {CTL_E_FILENOTFOUND, "Unable to find the specified file."},
    {FUSION_E_INVALID_NAME, "Fusion invalid name exception."},
    {FUSION_E_REF_DEF_MISMATCH, "Fusion the reference definition is incompatible."},
    {ERROR_TOO_MANY_OPEN_FILES, "Too many open files."},
    {ERROR_SHARING_VIOLATION, "Sharing violation."},
    {ERROR_LOCK_VIOLATION, "Lock violations."},
    {ERROR_OPEN_FAILED, "Open failed."},
    {ERROR_DISK_CORRUPT, "Disk corrupt."},
    {ERROR_UNRECOGNIZED_VOLUME, "Unrecognized volume."},
    {ERROR_DLL_INIT_FAILED, "DLL init failed."},
    {MSEE_E_ASSEMBLYLOADINPROGRESS, "Assembly load in progress."},
    {ERROR_FILE_INVALID, "File invalid."},
  };
  return h_result_messages;
}

int32 h_result::get_severity(int32 h_result) noexcept {
  return (h_result >> 31) & static_cast<int32>(0x1);
}

const std::error_category& h_result::h_result_category() noexcept {
  struct h_result_category : public std::error_category {
    std::string message(int h_result) const override {return xtd::h_result::get_message(h_result);}
    const char* name() const noexcept override {return "h_result_category";}
  };
  
  static auto result = h_result_category {};
  return result;
}

bool h_result::is_error(int32 h_result) noexcept {
  return get_severity(h_result) == 1;
}

std::error_code h_result::make_error_code(int h_result) noexcept {
  return std::error_code {h_result, h_result_category()};
}

bool h_result::succeeded(int32 h_result) noexcept {
  return h_result >= 0;
}

string h_result::to_string(int32 h_result) noexcept {
  return get_name(h_result);
}
