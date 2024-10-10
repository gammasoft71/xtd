#include <xtd/as>
#include <xtd/interface>
#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(h_result_tests) {
    void test_method_(S_OK) {
      assert::are_equal(static_cast<int32>(0x00000000), h_result::S_OK, csf_);
    }

    void test_method_(S_FALSE) {
      assert::are_equal(static_cast<int32>(0x00000001), h_result::S_FALSE, csf_);
    }

    void test_method_(COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x8013152D), h_result::COR_E_ABANDONEDMUTEX, csf_);
    }

    void test_method_(COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x8013106A), h_result::COR_E_AMBIGUOUSIMPLEMENTATION, csf_);
    }

    void test_method_(COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x8000211D), h_result::COR_E_AMBIGUOUSMATCH, csf_);
    }

    void test_method_(COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131014), h_result::COR_E_APPDOMAINUNLOADED, csf_);
    }

    void test_method_(COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x80131600), h_result::COR_E_APPLICATION, csf_);
    }

    void test_method_(COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x80070057), h_result::COR_E_ARGUMENT, csf_);
    }

    void test_method_(COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131502), h_result::COR_E_ARGUMENTOUTOFRANGE, csf_);
    }

    void test_method_(COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x80070216), h_result::COR_E_ARITHMETIC, csf_);
    }

    void test_method_(COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131503), h_result::COR_E_ARRAYTYPEMISMATCH, csf_);
    }

    void test_method_(COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x800700C1), h_result::COR_E_BADEXEFORMAT, csf_);
    }

    void test_method_(COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x8007000B), h_result::COR_E_BADIMAGEFORMAT, csf_);
    }

    void test_method_(COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x80131015), h_result::COR_E_CANNOTUNLOADAPPDOMAIN, csf_);
    }

    void test_method_(COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x80131542), h_result::COR_E_CODECONTRACTFAILED, csf_);
    }

    void test_method_(COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x80131504), h_result::COR_E_CONTEXTMARSHAL, csf_);
    }

    void test_method_(COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x80131605), h_result::COR_E_CUSTOMATTRIBUTEFORMAT, csf_);
    }

    void test_method_(COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x80131541), h_result::COR_E_DATAMISALIGNED, csf_);
    }

    void test_method_(COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070003), h_result::COR_E_DIRECTORYNOTFOUND, csf_);
    }

    void test_method_(COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_result::COR_E_DIVIDEBYZERO, csf_);
    }

    void test_method_(COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131524), h_result::COR_E_DLLNOTFOUND, csf_);
    }

    void test_method_(COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131529), h_result::COR_E_DUPLICATEWAITOBJECT, csf_);
    }

    void test_method_(COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x80070026), h_result::COR_E_ENDOFSTREAM, csf_);
    }

    void test_method_(COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131523), h_result::COR_E_ENTRYPOINTNOTFOUND, csf_);
    }

    void test_method_(COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x80131500), h_result::COR_E_EXCEPTION, csf_);
    }

    void test_method_(COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x80131506), h_result::COR_E_EXECUTIONENGINE, csf_);
    }

    void test_method_(COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x80131623), h_result::COR_E_FAILFAST, csf_);
    }

    void test_method_(COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x80131507), h_result::COR_E_FIELDACCESS, csf_);
    }

    void test_method_(COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x80131621), h_result::COR_E_FILELOAD, csf_);
    }

    void test_method_(COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_result::COR_E_FILENOTFOUND, csf_);
    }

    void test_method_(COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x80131537), h_result::COR_E_FORMAT, csf_);
    }

    void test_method_(COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131508), h_result::COR_E_INDEXOUTOFRANGE, csf_);
    }

    void test_method_(COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x80131578), h_result::COR_E_INSUFFICIENTEXECUTIONSTACK, csf_);
    }

    void test_method_(COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x8013153D), h_result::COR_E_INSUFFICIENTMEMORY, csf_);
    }

    void test_method_(COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x80004002), h_result::COR_E_INVALIDCAST, csf_);
    }

    void test_method_(COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131527), h_result::COR_E_INVALIDCOMOBJECT, csf_);
    }

    void test_method_(COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x80131601), h_result::COR_E_INVALIDFILTERCRITERIA, csf_);
    }

    void test_method_(COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x80131531), h_result::COR_E_INVALIDOLEVARIANTTYPE, csf_);
    }

    void test_method_(COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x80131509), h_result::COR_E_INVALIDOPERATION, csf_);
    }

    void test_method_(COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x8013153A), h_result::COR_E_INVALIDPROGRAM, csf_);
    }

    void test_method_(COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x80131620), h_result::COR_E_IO, csf_);
    }

    void test_method_(COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131577), h_result::COR_E_KEYNOTFOUND, csf_);
    }

    void test_method_(COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x80131535), h_result::COR_E_MARSHALDIRECTIVE, csf_);
    }

    void test_method_(COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x8013151A), h_result::COR_E_MEMBERACCESS, csf_);
    }

    void test_method_(COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x80131510), h_result::COR_E_METHODACCESS, csf_);
    }

    void test_method_(COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x80131511), h_result::COR_E_MISSINGFIELD, csf_);
    }

    void test_method_(COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x80131532), h_result::COR_E_MISSINGMANIFESTRESOURCE, csf_);
    }

    void test_method_(COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x80131512), h_result::COR_E_MISSINGMEMBER, csf_);
    }

    void test_method_(COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x80131513), h_result::COR_E_MISSINGMETHOD, csf_);
    }

    void test_method_(COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x80131536), h_result::COR_E_MISSINGSATELLITEASSEMBLY, csf_);
    }

    void test_method_(COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131514), h_result::COR_E_MULTICASTNOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x80131528), h_result::COR_E_NOTFINITENUMBER, csf_);
    }

    void test_method_(COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131515), h_result::COR_E_NOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_OBJECTCLOSED) {
      assert::are_equal(static_cast<int32>(0x80131622), h_result::COR_E_OBJECTCLOSED, csf_);
    }

    void test_method_(COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x8013153B), h_result::COR_E_OPERATIONCANCELED, csf_);
    }

    void test_method_(COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x8007000E), h_result::COR_E_OUTOFMEMORY, csf_);
    }

    void test_method_(COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x80131516), h_result::COR_E_OVERFLOW, csf_);
    }

    void test_method_(COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x800700CE), h_result::COR_E_PATHTOOLONG, csf_);
    }

    void test_method_(COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131539), h_result::COR_E_PLATFORMNOTSUPPORTED, csf_);
    }

    void test_method_(COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x80131517), h_result::COR_E_RANK, csf_);
    }

    void test_method_(COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131602), h_result::COR_E_REFLECTIONTYPELOAD, csf_);
    }

    void test_method_(COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x8013153E), h_result::COR_E_RUNTIMEWRAPPED, csf_);
    }

    void test_method_(COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131538), h_result::COR_E_SAFEARRAYRANKMISMATCH, csf_);
    }

    void test_method_(COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131533), h_result::COR_E_SAFEARRAYTYPEMISMATCH, csf_);
    }

    void test_method_(COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x8013150A), h_result::COR_E_SECURITY, csf_);
    }

    void test_method_(COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x8013150C), h_result::COR_E_SERIALIZATION, csf_);
    }

    void test_method_(COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x800703E9), h_result::COR_E_STACKOVERFLOW, csf_);
    }

    void test_method_(COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x80131518), h_result::COR_E_SYNCHRONIZATIONLOCK, csf_);
    }

    void test_method_(COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x80131501), h_result::COR_E_SYSTEM, csf_);
    }

    void test_method_(COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x80131603), h_result::COR_E_TARGET, csf_);
    }

    void test_method_(COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x80131604), h_result::COR_E_TARGETINVOCATION, csf_);
    }

    void test_method_(COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x8002000E), h_result::COR_E_TARGETPARAMCOUNT, csf_);
    }

    void test_method_(COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x80131530), h_result::COR_E_THREADABORTED, csf_);
    }

    void test_method_(COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x80131519), h_result::COR_E_THREADINTERRUPTED, csf_);
    }

    void test_method_(COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x80131525), h_result::COR_E_THREADSTART, csf_);
    }

    void test_method_(COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x80131520), h_result::COR_E_THREADSTATE, csf_);
    }

    void test_method_(COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x80131505), h_result::COR_E_TIMEOUT, csf_);
    }

    void test_method_(COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x80131543), h_result::COR_E_TYPEACCESS, csf_);
    }

    void test_method_(COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x80131534), h_result::COR_E_TYPEINITIALIZATION, csf_);
    }

    void test_method_(COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131522), h_result::COR_E_TYPELOAD, csf_);
    }

    void test_method_(COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131013), h_result::COR_E_TYPEUNLOADED, csf_);
    }

    void test_method_(COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x80070005), h_result::COR_E_UNAUTHORIZEDACCESS, csf_);
    }

    void test_method_(COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x8013150D), h_result::COR_E_VERIFICATION, csf_);
    }

    void test_method_(COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x8013152C), h_result::COR_E_WAITHANDLECANNOTBEOPENED, csf_);
    }

    void test_method_(CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x800401F0), h_result::CO_E_NOTINITIALIZED, csf_);
    }

    void test_method_(DISP_E_PARAMNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80020004), h_result::DISP_E_PARAMNOTFOUND, csf_);
    }

    void test_method_(DISP_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80020005), h_result::DISP_E_TYPEMISMATCH, csf_);
    }

    void test_method_(DISP_E_BADVARTYPE) {
      assert::are_equal(static_cast<int32>(0x80020008), h_result::DISP_E_BADVARTYPE, csf_);
    }

    void test_method_(DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x8002000A), h_result::DISP_E_OVERFLOW, csf_);
    }

    void test_method_(DISP_E_DIVBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_result::DISP_E_DIVBYZERO, csf_);
    }

    void test_method_(E_ABORT) {
      assert::are_equal(static_cast<int32>(0x80004004), h_result::E_ABORT, csf_);
    }

    void test_method_(E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x8000000B), h_result::E_BOUNDS, csf_);
    }

    void test_method_(E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x8000000C), h_result::E_CHANGED_STATE, csf_);
    }

    void test_method_(E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_result::E_FILENOTFOUND, csf_);
    }

    void test_method_(E_FAIL) {
      assert::are_equal(static_cast<int32>(0x80004005), h_result::E_FAIL, csf_);
    }

    void test_method_(E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x80070006), h_result::E_HANDLE, csf_);
    }

    void test_method_(E_INVALIDARG) {
      assert::are_equal(static_cast<int32>(0x80070057), h_result::E_INVALIDARG, csf_);
    }

    void test_method_(E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x80004001), h_result::E_NOTIMPL, csf_);
    }

    void test_method_(E_POINTER) {
      assert::are_equal(static_cast<int32>(0x80004003), h_result::E_POINTER, csf_);
    }

    void test_method_(E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0x8000FFFF), h_result::E_UNEXPECTED, csf_);
    }

    void test_method_(ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x80073B1F), h_result::ERROR_MRM_MAP_NOT_FOUND, csf_);
    }

    void test_method_(ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x800705B4), h_result::ERROR_TIMEOUT, csf_);
    }

    void test_method_(RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x80000013), h_result::RO_E_CLOSED, csf_);
    }

    void test_method_(RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x80010106), h_result::RPC_E_CHANGED_MODE, csf_);
    }

    void test_method_(TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80028CA0), h_result::TYPE_E_TYPEMISMATCH, csf_);
    }

    void test_method_(STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80030003), h_result::STG_E_PATHNOTFOUND, csf_);
    }

    void test_method_(CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A004C), h_result::CTL_E_PATHNOTFOUND, csf_);
    }

    void test_method_(CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A0035), h_result::CTL_E_FILENOTFOUND, csf_);
    }

    void test_method_(FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x80131047), h_result::FUSION_E_INVALID_NAME, csf_);
    }

    void test_method_(FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131040), h_result::FUSION_E_REF_DEF_MISMATCH, csf_);
    }

    void test_method_(ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x80070004), h_result::ERROR_TOO_MANY_OPEN_FILES, csf_);
    }

    void test_method_(ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070020), h_result::ERROR_SHARING_VIOLATION, csf_);
    }

    void test_method_(ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070021), h_result::ERROR_LOCK_VIOLATION, csf_);
    }

    void test_method_(ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007006E), h_result::ERROR_OPEN_FAILED, csf_);
    }

    void test_method_(ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x80070571), h_result::ERROR_DISK_CORRUPT, csf_);
    }

    void test_method_(ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x800703ED), h_result::ERROR_UNRECOGNIZED_VOLUME, csf_);
    }

    void test_method_(ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007045A), h_result::ERROR_DLL_INIT_FAILED, csf_);
    }

    void test_method_(MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x80131016), h_result::MSEE_E_ASSEMBLYLOADINPROGRESS, csf_);
    }

    void test_method_(ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x800703EE), h_result::ERROR_FILE_INVALID, csf_);
    }
    
    void test_method_(get_h_results) {
      assert::are_equal(116_z, h_result::get_messages().size(), csf_);
      assert::are_equal(116_z, h_result::get_names().size(), csf_);
      assert::are_equal(116_z, h_result::get_h_results().size(), csf_);
    }
    
    void test_method_(get_message_with_S_OK) {
      assert::are_equal("Operation successful.", h_result::get_message(h_result::S_OK), csf_);
    }

    void test_method_(get_message_with_S_FALSE) {
      assert::are_equal("Operation successful but returned no results.", h_result::get_message(h_result::S_FALSE), csf_);
    }

    void test_method_(get_message_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal("The wait completed due to an abandoned mutex.", h_result::get_message(h_result::COR_E_ABANDONEDMUTEX), csf_);
    }

    void test_method_(get_message_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal("Ambiguous implementation found.", h_result::get_message(h_result::COR_E_AMBIGUOUSIMPLEMENTATION), csf_);
    }

    void test_method_(get_message_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal("Ambiguous match found.", h_result::get_message(h_result::COR_E_AMBIGUOUSMATCH), csf_);
    }

    void test_method_(get_message_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal("Attempted to access an unloaded AppDomain.", h_result::get_message(h_result::COR_E_APPDOMAINUNLOADED), csf_);
    }

    void test_method_(get_message_with_COR_E_APPLICATION) {
      assert::are_equal("Error in the application.", h_result::get_message(h_result::COR_E_APPLICATION), csf_);
    }

    void test_method_(get_message_with_COR_E_ARGUMENT) {
      assert::are_equal("Value does not fall within the expected range.", h_result::get_message(h_result::COR_E_ARGUMENT), csf_);
    }

    void test_method_(get_message_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal("Specified argument was out of the range of valid values.", h_result::get_message(h_result::COR_E_ARGUMENTOUTOFRANGE), csf_);
    }

    void test_method_(get_message_with_COR_E_ARITHMETIC) {
      assert::are_equal("Overflow or underflow in the arithmetic operation.", h_result::get_message(h_result::COR_E_ARITHMETIC), csf_);
    }

    void test_method_(get_message_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal("Attempted to access an element as a type incompatible with the array.", h_result::get_message(h_result::COR_E_ARRAYTYPEMISMATCH), csf_);
    }

    void test_method_(get_message_with_COR_E_BADEXEFORMAT) {
      assert::are_equal("Format of the executable (.exe) cannot be run.", h_result::get_message(h_result::COR_E_BADEXEFORMAT), csf_);
    }

    void test_method_(get_message_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal("Format of the executable (.exe) or library (.dll) is invalid.", h_result::get_message(h_result::COR_E_BADIMAGEFORMAT), csf_);
    }

    void test_method_(get_message_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal("Attempt to unload the AppDomain failed.", h_result::get_message(h_result::COR_E_CANNOTUNLOADAPPDOMAIN), csf_);
    }
    
    void test_method_(get_message_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal("A code contract (ie, precondition, postcondition, invariant, or assert) failed.", h_result::get_message(h_result::COR_E_CODECONTRACTFAILED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal("Attempted to marshal an object across a context boundary.", h_result::get_message(h_result::COR_E_CONTEXTMARSHAL), csf_);
    }
    
    void test_method_(get_message_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal("Binary format of the specified custom attribute was invalid.", h_result::get_message(h_result::COR_E_CUSTOMATTRIBUTEFORMAT), csf_);
    }
    
    void test_method_(get_message_with_COR_E_DATAMISALIGNED) {
      assert::are_equal("A datatype misalignment was detected in a load or store instruction.", h_result::get_message(h_result::COR_E_DATAMISALIGNED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::COR_E_DIRECTORYNOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal("Attempted to divide by zero.", h_result::get_message(h_result::COR_E_DIVIDEBYZERO), csf_);
    }
    
    void test_method_(get_message_with_COR_E_DLLNOTFOUND) {
      assert::are_equal("Dll was not found.", h_result::get_message(h_result::COR_E_DLLNOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal("Duplicate objects in argument.", h_result::get_message(h_result::COR_E_DUPLICATEWAITOBJECT), csf_);
    }
    
    void test_method_(get_message_with_COR_E_ENDOFSTREAM) {
      assert::are_equal("Attempted to read past the end of the stream.", h_result::get_message(h_result::COR_E_ENDOFSTREAM), csf_);
    }
    
    void test_method_(get_message_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal("Entry point was not found.", h_result::get_message(h_result::COR_E_ENTRYPOINTNOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_COR_E_EXCEPTION) {
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", h_result::get_message(h_result::COR_E_EXCEPTION), csf_);
    }
    
    void test_method_(get_message_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal("Internal error in the runtime.", h_result::get_message(h_result::COR_E_EXECUTIONENGINE), csf_);
    }
    
    void test_method_(get_message_with_COR_E_FAILFAST) {
      assert::are_equal("Fail fast.", h_result::get_message(h_result::COR_E_FAILFAST), csf_);
    }
    
    void test_method_(get_message_with_COR_E_FIELDACCESS) {
      assert::are_equal("Attempted to access a field that is not accessible by the caller.", h_result::get_message(h_result::COR_E_FIELDACCESS), csf_);
    }
    
    void test_method_(get_message_with_COR_E_FILELOAD) {
      assert::are_equal("Could not load the specified file.", h_result::get_message(h_result::COR_E_FILELOAD), csf_);
    }
    
    void test_method_(get_message_with_COR_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::COR_E_FILENOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_COR_E_FORMAT) {
      assert::are_equal("One of the identified items was in an invalid format.", h_result::get_message(h_result::COR_E_FORMAT), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal("Index was outside the bounds of the array.", h_result::get_message(h_result::COR_E_INDEXOUTOFRANGE), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal("Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space.", h_result::get_message(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::get_message(h_result::COR_E_INSUFFICIENTMEMORY), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDCAST) {
      assert::are_equal("Specified cast is not valid.", h_result::get_message(h_result::COR_E_INVALIDCAST), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal("Attempt has been made to use a COM object that does not have a backing class factory.", h_result::get_message(h_result::COR_E_INVALIDCOMOBJECT), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal("Specified filter criteria was invalid.", h_result::get_message(h_result::COR_E_INVALIDFILTERCRITERIA), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal("Specified OLE variant was invalid.", h_result::get_message(h_result::COR_E_INVALIDOLEVARIANTTYPE), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDOPERATION) {
      assert::are_equal("Operation is not valid due to the current state of the object.", h_result::get_message(h_result::COR_E_INVALIDOPERATION), csf_);
    }
    
    void test_method_(get_message_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal("xtd detected an invalid program.", h_result::get_message(h_result::COR_E_INVALIDPROGRAM), csf_);
    }
    
    void test_method_(get_message_with_COR_E_IO) {
      assert::are_equal("I/O error occurred.", h_result::get_message(h_result::COR_E_IO), csf_);
    }
    
    void test_method_(get_message_with_COR_E_KEYNOTFOUND) {
      assert::are_equal("The given key was not present in the dictionary.", h_result::get_message(h_result::COR_E_KEYNOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal("Marshaling directives are invalid.", h_result::get_message(h_result::COR_E_MARSHALDIRECTIVE), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MEMBERACCESS) {
      assert::are_equal("Cannot access member.", h_result::get_message(h_result::COR_E_MEMBERACCESS), csf_);
    }
    
    void test_method_(get_message_with_COR_E_METHODACCESS) {
      assert::are_equal("Attempt to access the method failed.", h_result::get_message(h_result::COR_E_METHODACCESS), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MISSINGFIELD) {
      assert::are_equal("Attempted to access a non-existing field.", h_result::get_message(h_result::COR_E_MISSINGFIELD), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal("Attempted to access a missing manifest resource.", h_result::get_message(h_result::COR_E_MISSINGMANIFESTRESOURCE), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMEMBER) {
      assert::are_equal("Attempted to access a missing member.", h_result::get_message(h_result::COR_E_MISSINGMEMBER), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMETHOD) {
      assert::are_equal("Attempted to access a missing method.", h_result::get_message(h_result::COR_E_MISSINGMETHOD), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal("Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application.", h_result::get_message(h_result::COR_E_MISSINGSATELLITEASSEMBLY), csf_);
    }
    
    void test_method_(get_message_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal("Attempted to add multiple callbacks to a delegate that does not support multicast.", h_result::get_message(h_result::COR_E_MULTICASTNOTSUPPORTED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal("Number encountered was not a finite quantity.", h_result::get_message(h_result::COR_E_NOTFINITENUMBER), csf_);
    }
    
    void test_method_(get_message_with_COR_E_NOTSUPPORTED) {
      assert::are_equal("Specified method is not supported.", h_result::get_message(h_result::COR_E_NOTSUPPORTED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_OBJECTCLOSED) {
      assert::are_equal("Cannot access a closed object.", h_result::get_message(h_result::COR_E_OBJECTCLOSED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal("The operation was canceled.", h_result::get_message(h_result::COR_E_OPERATIONCANCELED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_OUTOFMEMORY) {
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::get_message(h_result::COR_E_OUTOFMEMORY), csf_);
    }
    
    void test_method_(get_message_with_COR_E_OVERFLOW) {
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::get_message(h_result::COR_E_OVERFLOW), csf_);
    }
    
    void test_method_(get_message_with_COR_E_PATHTOOLONG) {
      assert::are_equal("The specified file name or path is too long, or a component of the specified path is too long.", h_result::get_message(h_result::COR_E_PATHTOOLONG), csf_);
    }
    
    void test_method_(get_message_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal("Operation is not supported on this platform.", h_result::get_message(h_result::COR_E_PLATFORMNOTSUPPORTED), csf_);
    }

    void test_method_(get_message_with_COR_E_RANK) {
      assert::are_equal("Attempted to operate on an array with the incorrect number of dimensions.", h_result::get_message(h_result::COR_E_RANK), csf_);
    }
    
    void test_method_(get_message_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal("Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown.", h_result::get_message(h_result::COR_E_REFLECTIONTYPELOAD), csf_);
    }
    
    void test_method_(get_message_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal("An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception.", h_result::get_message(h_result::COR_E_RUNTIMEWRAPPED), csf_);
    }
    
    void test_method_(get_message_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal("Specified array was not of the expected rank.", h_result::get_message(h_result::COR_E_SAFEARRAYRANKMISMATCH), csf_);
    }
    
    void test_method_(get_message_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal("Specified array was not of the expected type.", h_result::get_message(h_result::COR_E_SAFEARRAYTYPEMISMATCH), csf_);
    }
    
    void test_method_(get_message_with_COR_E_SECURITY) {
      assert::are_equal("Security error.", h_result::get_message(h_result::COR_E_SECURITY), csf_);
    }
    
    void test_method_(get_message_with_COR_E_SERIALIZATION) {
      assert::are_equal("Serialization error.", h_result::get_message(h_result::COR_E_SERIALIZATION), csf_);
    }
    
    void test_method_(get_message_with_COR_E_STACKOVERFLOW) {
      assert::are_equal("Operation caused a stack overflow.", h_result::get_message(h_result::COR_E_STACKOVERFLOW), csf_);
    }
    
    void test_method_(get_message_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal("Object synchronization method was called from an unsynchronized block of code.", h_result::get_message(h_result::COR_E_SYNCHRONIZATIONLOCK), csf_);
    }

    void test_method_(get_message_with_COR_E_SYSTEM) {
      assert::are_equal("System error.", h_result::get_message(h_result::COR_E_SYSTEM), csf_);
    }

    void test_method_(get_message_with_COR_E_TARGET) {
      assert::are_equal("Exception of type 'xtd::reflection::target_exception' was thrown.", h_result::get_message(h_result::COR_E_TARGET), csf_);
    }

    void test_method_(get_message_with_COR_E_TARGETINVOCATION) {
      assert::are_equal("Exception has been thrown by the target of an invocation.", h_result::get_message(h_result::COR_E_TARGETINVOCATION), csf_);
    }

    void test_method_(get_message_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal("Number of parameters specified does not match the expected number.", h_result::get_message(h_result::COR_E_TARGETPARAMCOUNT), csf_);
    }

    void test_method_(get_message_with_COR_E_THREADABORTED) {
      assert::are_equal("Thread was aborted.", h_result::get_message(h_result::COR_E_THREADABORTED), csf_);
    }

    void test_method_(get_message_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal("Thread was interrupted from a waiting state.", h_result::get_message(h_result::COR_E_THREADINTERRUPTED), csf_);
    }

    void test_method_(get_message_with_COR_E_THREADSTART) {
      assert::are_equal("Thread start failure.", h_result::get_message(h_result::COR_E_THREADSTART), csf_);
    }

    void test_method_(get_message_with_COR_E_THREADSTATE) {
      assert::are_equal("Thread was in an invalid state for the operation being executed.", h_result::get_message(h_result::COR_E_THREADSTATE), csf_);
    }

    void test_method_(get_message_with_COR_E_TIMEOUT) {
      assert::are_equal("The operation has timed out.", h_result::get_message(h_result::COR_E_TIMEOUT), csf_);
    }

    void test_method_(get_message_with_COR_E_TYPEACCESS) {
      assert::are_equal("Attempt to access the type failed.", h_result::get_message(h_result::COR_E_TYPEACCESS), csf_);
    }

    void test_method_(get_message_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal("The type initializer for 'value' threw an exception.", h_result::get_message(h_result::COR_E_TYPEINITIALIZATION), csf_);
    }

    void test_method_(get_message_with_COR_E_TYPELOAD) {
      assert::are_equal("Failure has occurred while loading a type.", h_result::get_message(h_result::COR_E_TYPELOAD), csf_);
    }

    void test_method_(get_message_with_COR_E_TYPEUNLOADED) {
      assert::are_equal("Type had been unloaded.", h_result::get_message(h_result::COR_E_TYPEUNLOADED), csf_);
    }

    void test_method_(get_message_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal("Attempted to perform an unauthorized operation.", h_result::get_message(h_result::COR_E_UNAUTHORIZEDACCESS), csf_);
    }

    void test_method_(get_message_with_COR_E_VERIFICATION) {
      assert::are_equal("Operation could destabilize the runtime.", h_result::get_message(h_result::COR_E_VERIFICATION), csf_);
    }

    void test_method_(get_message_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal("No handle of the given name exists.", h_result::get_message(h_result::COR_E_WAITHANDLECANNOTBEOPENED), csf_);
    }

    void test_method_(get_message_with_CO_E_NOTINITIALIZED) {
      assert::are_equal("Not initialized", h_result::get_message(h_result::CO_E_NOTINITIALIZED), csf_);
    }

    void test_method_(get_message_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal("Could not find the parameter.", h_result::get_message(h_result::DISP_E_PARAMNOTFOUND), csf_);
    }

    void test_method_(get_message_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal("Attempt to access a variable with an incompatible type.", h_result::get_message(h_result::DISP_E_TYPEMISMATCH), csf_);
    }

    void test_method_(get_message_with_DISP_E_BADVARTYPE) {
      assert::are_equal("Invalid variable type.", h_result::get_message(h_result::DISP_E_BADVARTYPE), csf_);
    }

    void test_method_(get_message_with_DISP_E_OVERFLOW) {
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::get_message(h_result::DISP_E_OVERFLOW), csf_);
    }

    void test_method_(get_message_with_DISP_E_DIVBYZERO) {
      assert::are_equal("Attempted to divide by zero.", h_result::get_message(h_result::DISP_E_DIVBYZERO), csf_);
    }

    void test_method_(get_message_with_E_ABORT) {
      assert::are_equal("Operation aborted.", h_result::get_message(h_result::E_ABORT), csf_);
    }
    
    void test_method_(get_message_with_E_BOUNDS) {
      assert::are_equal("Bounds exception", h_result::get_message(h_result::E_BOUNDS), csf_);
    }
    
    void test_method_(get_message_with_E_CHANGED_STATE) {
      assert::are_equal("The state has been modified.", h_result::get_message(h_result::E_CHANGED_STATE), csf_);
    }
    
    void test_method_(get_message_with_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::E_FILENOTFOUND), csf_);
    }
    
    void test_method_(get_message_with_E_FAIL) {
      assert::are_equal("Unspecified failure.", h_result::get_message(h_result::E_FAIL), csf_);
    }
    
    void test_method_(get_message_with_E_HANDLE) {
      assert::are_equal("The handle is invalid.", h_result::get_message(h_result::E_HANDLE), csf_);
    }
    
    void test_method_(get_message_with_E_INVALIDARG) {
      assert::are_equal("Value does not fall within the expected range.", h_result::get_message(h_result::E_INVALIDARG), csf_);
    }
    
    void test_method_(get_message_with_E_NOTIMPL) {
      assert::are_equal("The method or operation is not implemented.", h_result::get_message(h_result::E_NOTIMPL), csf_);
    }

    void test_method_(get_message_with_E_POINTER) {
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", h_result::get_message(h_result::E_POINTER), csf_);
    }
    
    void test_method_(get_message_with_E_UNEXPECTED) {
      assert::are_equal("Unexpected failure.", h_result::get_message(h_result::E_UNEXPECTED), csf_);
    }

    void test_method_(get_message_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal("Resource map not found.", h_result::get_message(h_result::ERROR_MRM_MAP_NOT_FOUND), csf_);
    }

    void test_method_(get_message_with_ERROR_TIMEOUT) {
      assert::are_equal("The operation has timed out.", h_result::get_message(h_result::ERROR_TIMEOUT), csf_);
    }

    void test_method_(get_message_with_RO_E_CLOSED) {
      assert::are_equal("The object has been closed.", h_result::get_message(h_result::RO_E_CLOSED), csf_);
    }

    void test_method_(get_message_with_RPC_E_CHANGED_MODE) {
      assert::are_equal("Cannot change the current thread mode.", h_result::get_message(h_result::RPC_E_CHANGED_MODE), csf_);
    }

    void test_method_(get_message_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal("Incompatible type.", h_result::get_message(h_result::TYPE_E_TYPEMISMATCH), csf_);
    }

    void test_method_(get_message_with_STG_E_PATHNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::STG_E_PATHNOTFOUND), csf_);
    }

    void test_method_(get_message_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::CTL_E_PATHNOTFOUND), csf_);
    }

    void test_method_(get_message_with_CTL_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::CTL_E_FILENOTFOUND), csf_);
    }

    void test_method_(get_message_with_FUSION_E_INVALID_NAME) {
      assert::are_equal("Fusion invalid name exception.", h_result::get_message(h_result::FUSION_E_INVALID_NAME), csf_);
    }

    void test_method_(get_message_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal("Fusion the reference definition is incompatible.", h_result::get_message(h_result::FUSION_E_REF_DEF_MISMATCH), csf_);
    }

    void test_method_(get_message_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal("Too many open files.", h_result::get_message(h_result::ERROR_TOO_MANY_OPEN_FILES), csf_);
    }

    void test_method_(get_message_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal("Sharing violation.", h_result::get_message(h_result::ERROR_SHARING_VIOLATION), csf_);
    }

    void test_method_(get_message_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal("Lock violations.", h_result::get_message(h_result::ERROR_LOCK_VIOLATION), csf_);
    }

    void test_method_(get_message_with_ERROR_OPEN_FAILED) {
      assert::are_equal("Open failed.", h_result::get_message(h_result::ERROR_OPEN_FAILED), csf_);
    }

    void test_method_(get_message_with_ERROR_DISK_CORRUPT) {
      assert::are_equal("Disk corrupt.", h_result::get_message(h_result::ERROR_DISK_CORRUPT), csf_);
    }

    void test_method_(get_message_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal("Unrecognized volume.", h_result::get_message(h_result::ERROR_UNRECOGNIZED_VOLUME), csf_);
    }

    void test_method_(get_message_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal("DLL init failed.", h_result::get_message(h_result::ERROR_DLL_INIT_FAILED), csf_);
    }

    void test_method_(get_message_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal("Assembly load in progress.", h_result::get_message(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS), csf_);
    }

    void test_method_(get_message_with_ERROR_FILE_INVALID) {
      assert::are_equal("File invalid.", h_result::get_message(h_result::ERROR_FILE_INVALID), csf_);
    }

    void test_method_(make_error_code_with_S_OK) {
      assert::are_equal(static_cast<int32>(0x00000000), h_result::make_error_code(h_result::S_OK).value(), csf_);
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::S_OK).category().name(), csf_);
      assert::are_equal("Operation successful.", h_result::make_error_code(h_result::S_OK).message(), csf_);
    }
    
    void test_method_(make_error_code_with_COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x80131517), h_result::make_error_code(h_result::COR_E_RANK).value(), csf_);
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_RANK).category().name(), csf_);
      assert::are_equal("Attempted to operate on an array with the incorrect number of dimensions.", h_result::make_error_code(h_result::COR_E_RANK).message(), csf_);
    }
    
    void test_method_(make_error_code_with_unknown_value) {
      assert::are_equal(static_cast<int32>(0xFF00FF00), h_result::make_error_code(0xFF00FF00).value(), csf_);
      assert::are_equal("h_result_category", h_result::make_error_code(0xFF00FF00).category().name(), csf_);
      assert::are_equal("Unknown h_result 0xFF00FF00 (-16711936)", h_result::make_error_code(0xFF00FF00).message(), csf_);
    }
  };
}
