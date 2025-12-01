#include <xtd/collections/generic/key_value_pair>
#include <xtd/as>
#include <xtd/interface>
#include <xtd/string>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(h_result_tests) {
    void test_method_(S_OK) {
      assert::are_equal(static_cast<int32>(0x00000000), h_result::S_OK);
    }
    
    void test_method_(S_FALSE) {
      assert::are_equal(static_cast<int32>(0x00000001), h_result::S_FALSE);
    }
    
    void test_method_(COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x8013152D), h_result::COR_E_ABANDONEDMUTEX);
      assert::are_equal(static_cast<int32>(0x152D), h_result::get_code(h_result::COR_E_ABANDONEDMUTEX));
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_ABANDONEDMUTEX));
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x8013106A), h_result::COR_E_AMBIGUOUSIMPLEMENTATION);
    }
    
    void test_method_(COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x8000211D), h_result::COR_E_AMBIGUOUSMATCH);
    }
    
    void test_method_(COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131014), h_result::COR_E_APPDOMAINUNLOADED);
    }
    
    void test_method_(COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x80131600), h_result::COR_E_APPLICATION);
    }
    
    void test_method_(COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x80070057), h_result::COR_E_ARGUMENT);
    }
    
    void test_method_(COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131502), h_result::COR_E_ARGUMENTOUTOFRANGE);
    }
    
    void test_method_(COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x80070216), h_result::COR_E_ARITHMETIC);
    }
    
    void test_method_(COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131503), h_result::COR_E_ARRAYTYPEMISMATCH);
    }
    
    void test_method_(COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x800700C1), h_result::COR_E_BADEXEFORMAT);
    }
    
    void test_method_(COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x8007000B), h_result::COR_E_BADIMAGEFORMAT);
    }
    
    void test_method_(COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x80131015), h_result::COR_E_CANNOTUNLOADAPPDOMAIN);
    }
    
    void test_method_(COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x80131542), h_result::COR_E_CODECONTRACTFAILED);
    }
    
    void test_method_(COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x80131504), h_result::COR_E_CONTEXTMARSHAL);
    }
    
    void test_method_(COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x80131605), h_result::COR_E_CUSTOMATTRIBUTEFORMAT);
    }
    
    void test_method_(COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x80131541), h_result::COR_E_DATAMISALIGNED);
    }
    
    void test_method_(COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070003), h_result::COR_E_DIRECTORYNOTFOUND);
    }
    
    void test_method_(COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_result::COR_E_DIVIDEBYZERO);
    }
    
    void test_method_(COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131524), h_result::COR_E_DLLNOTFOUND);
    }
    
    void test_method_(COR_E_DRIVENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070007), h_result::COR_E_DRIVENOTFOUND);
    }
    
    void test_method_(COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131529), h_result::COR_E_DUPLICATEWAITOBJECT);
    }
    
    void test_method_(COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x80070026), h_result::COR_E_ENDOFSTREAM);
    }
    
    void test_method_(COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131523), h_result::COR_E_ENTRYPOINTNOTFOUND);
    }
    
    void test_method_(COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x80131500), h_result::COR_E_EXCEPTION);
    }
    
    void test_method_(COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x80131506), h_result::COR_E_EXECUTIONENGINE);
    }
    
    void test_method_(COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x80131623), h_result::COR_E_FAILFAST);
    }
    
    void test_method_(COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x80131507), h_result::COR_E_FIELDACCESS);
    }
    
    void test_method_(COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x80131621), h_result::COR_E_FILELOAD);
    }
    
    void test_method_(COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_result::COR_E_FILENOTFOUND);
    }
    
    void test_method_(COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x80131537), h_result::COR_E_FORMAT);
    }
    
    void test_method_(COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131508), h_result::COR_E_INDEXOUTOFRANGE);
    }
    
    void test_method_(COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x80131578), h_result::COR_E_INSUFFICIENTEXECUTIONSTACK);
    }
    
    void test_method_(COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x8013153D), h_result::COR_E_INSUFFICIENTMEMORY);
    }
    
    void test_method_(COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x80004002), h_result::COR_E_INVALIDCAST);
    }
    
    void test_method_(COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131527), h_result::COR_E_INVALIDCOMOBJECT);
    }
    
    void test_method_(COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x80131601), h_result::COR_E_INVALIDFILTERCRITERIA);
    }
    
    void test_method_(COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x80131531), h_result::COR_E_INVALIDOLEVARIANTTYPE);
    }
    
    void test_method_(COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x80131509), h_result::COR_E_INVALIDOPERATION);
    }
    
    void test_method_(COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x8013153A), h_result::COR_E_INVALIDPROGRAM);
    }
    
    void test_method_(COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x80131620), h_result::COR_E_IO);
    }
    
    void test_method_(COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131577), h_result::COR_E_KEYNOTFOUND);
    }
    
    void test_method_(COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x80131535), h_result::COR_E_MARSHALDIRECTIVE);
    }
    
    void test_method_(COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x8013151A), h_result::COR_E_MEMBERACCESS);
    }
    
    void test_method_(COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x80131510), h_result::COR_E_METHODACCESS);
    }
    
    void test_method_(COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x80131511), h_result::COR_E_MISSINGFIELD);
    }
    
    void test_method_(COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x80131532), h_result::COR_E_MISSINGMANIFESTRESOURCE);
    }
    
    void test_method_(COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x80131512), h_result::COR_E_MISSINGMEMBER);
    }
    
    void test_method_(COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x80131513), h_result::COR_E_MISSINGMETHOD);
    }
    
    void test_method_(COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x80131536), h_result::COR_E_MISSINGSATELLITEASSEMBLY);
    }
    
    void test_method_(COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131514), h_result::COR_E_MULTICASTNOTSUPPORTED);
    }
    
    void test_method_(COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x80131528), h_result::COR_E_NOTFINITENUMBER);
    }
    
    void test_method_(COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131515), h_result::COR_E_NOTSUPPORTED);
    }
    
    void test_method_(COR_E_OBJECTCLOSED) {
      assert::are_equal(static_cast<int32>(0x80131622), h_result::COR_E_OBJECTCLOSED);
    }
    
    void test_method_(COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x8013153B), h_result::COR_E_OPERATIONCANCELED);
    }
    
    void test_method_(COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x8007000E), h_result::COR_E_OUTOFMEMORY);
    }
    
    void test_method_(COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x80131516), h_result::COR_E_OVERFLOW);
    }
    
    void test_method_(COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x800700CE), h_result::COR_E_PATHTOOLONG);
    }
    
    void test_method_(COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131539), h_result::COR_E_PLATFORMNOTSUPPORTED);
    }
    
    void test_method_(COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x80131517), h_result::COR_E_RANK);
    }
    
    void test_method_(COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131602), h_result::COR_E_REFLECTIONTYPELOAD);
    }
    
    void test_method_(COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x8013153E), h_result::COR_E_RUNTIMEWRAPPED);
    }
    
    void test_method_(COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131538), h_result::COR_E_SAFEARRAYRANKMISMATCH);
    }
    
    void test_method_(COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131533), h_result::COR_E_SAFEARRAYTYPEMISMATCH);
    }
    
    void test_method_(COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x8013150A), h_result::COR_E_SECURITY);
    }
    
    void test_method_(COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x8013150C), h_result::COR_E_SERIALIZATION);
    }
    
    void test_method_(COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x800703E9), h_result::COR_E_STACKOVERFLOW);
    }
    
    void test_method_(COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x80131518), h_result::COR_E_SYNCHRONIZATIONLOCK);
    }
    
    void test_method_(COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x80131501), h_result::COR_E_SYSTEM);
    }
    
    void test_method_(COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x80131603), h_result::COR_E_TARGET);
    }
    
    void test_method_(COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x80131604), h_result::COR_E_TARGETINVOCATION);
    }
    
    void test_method_(COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x8002000E), h_result::COR_E_TARGETPARAMCOUNT);
    }
    
    void test_method_(COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x80131530), h_result::COR_E_THREADABORTED);
    }
    
    void test_method_(COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x80131519), h_result::COR_E_THREADINTERRUPTED);
    }
    
    void test_method_(COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x80131525), h_result::COR_E_THREADSTART);
    }
    
    void test_method_(COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x80131520), h_result::COR_E_THREADSTATE);
    }
    
    void test_method_(COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x80131505), h_result::COR_E_TIMEOUT);
    }
    
    void test_method_(COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x80131543), h_result::COR_E_TYPEACCESS);
    }
    
    void test_method_(COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x80131534), h_result::COR_E_TYPEINITIALIZATION);
    }
    
    void test_method_(COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131522), h_result::COR_E_TYPELOAD);
    }
    
    void test_method_(COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131013), h_result::COR_E_TYPEUNLOADED);
    }
    
    void test_method_(COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x80070005), h_result::COR_E_UNAUTHORIZEDACCESS);
    }
    
    void test_method_(COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x8013150D), h_result::COR_E_VERIFICATION);
    }
    
    void test_method_(COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x8013152C), h_result::COR_E_WAITHANDLECANNOTBEOPENED);
    }
    
    void test_method_(CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x800401F0), h_result::CO_E_NOTINITIALIZED);
    }
    
    void test_method_(DISP_E_PARAMNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80020004), h_result::DISP_E_PARAMNOTFOUND);
    }
    
    void test_method_(DISP_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80020005), h_result::DISP_E_TYPEMISMATCH);
    }
    
    void test_method_(DISP_E_BADVARTYPE) {
      assert::are_equal(static_cast<int32>(0x80020008), h_result::DISP_E_BADVARTYPE);
    }
    
    void test_method_(DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x8002000A), h_result::DISP_E_OVERFLOW);
    }
    
    void test_method_(DISP_E_DIVBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_result::DISP_E_DIVBYZERO);
    }
    
    void test_method_(E_ABORT) {
      assert::are_equal(static_cast<int32>(0x80004004), h_result::E_ABORT);
    }
    
    void test_method_(E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x8000000B), h_result::E_BOUNDS);
    }
    
    void test_method_(E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x8000000C), h_result::E_CHANGED_STATE);
    }
    
    void test_method_(E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_result::E_FILENOTFOUND);
    }
    
    void test_method_(E_FAIL) {
      assert::are_equal(static_cast<int32>(0x80004005), h_result::E_FAIL);
    }
    
    void test_method_(E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x80070006), h_result::E_HANDLE);
    }
    
    void test_method_(E_INVALIDARG) {
      assert::are_equal(static_cast<int32>(0x80070057), h_result::E_INVALIDARG);
    }
    
    void test_method_(E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x80004001), h_result::E_NOTIMPL);
    }
    
    void test_method_(E_POINTER) {
      assert::are_equal(static_cast<int32>(0x80004003), h_result::E_POINTER);
    }
    
    void test_method_(E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0x8000FFFF), h_result::E_UNEXPECTED);
    }
    
    void test_method_(ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x80073B1F), h_result::ERROR_MRM_MAP_NOT_FOUND);
    }
    
    void test_method_(ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x800705B4), h_result::ERROR_TIMEOUT);
    }
    
    void test_method_(RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x80000013), h_result::RO_E_CLOSED);
    }
    
    void test_method_(RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x80010106), h_result::RPC_E_CHANGED_MODE);
    }
    
    void test_method_(TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80028CA0), h_result::TYPE_E_TYPEMISMATCH);
    }
    
    void test_method_(STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80030003), h_result::STG_E_PATHNOTFOUND);
    }
    
    void test_method_(CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A004C), h_result::CTL_E_PATHNOTFOUND);
    }
    
    void test_method_(CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A0035), h_result::CTL_E_FILENOTFOUND);
    }
    
    void test_method_(FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x80131047), h_result::FUSION_E_INVALID_NAME);
    }
    
    void test_method_(FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131040), h_result::FUSION_E_REF_DEF_MISMATCH);
    }
    
    void test_method_(ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x80070004), h_result::ERROR_TOO_MANY_OPEN_FILES);
    }
    
    void test_method_(ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070020), h_result::ERROR_SHARING_VIOLATION);
    }
    
    void test_method_(ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070021), h_result::ERROR_LOCK_VIOLATION);
    }
    
    void test_method_(ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007006E), h_result::ERROR_OPEN_FAILED);
    }
    
    void test_method_(ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x80070571), h_result::ERROR_DISK_CORRUPT);
    }
    
    void test_method_(ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x800703ED), h_result::ERROR_UNRECOGNIZED_VOLUME);
    }
    
    void test_method_(ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007045A), h_result::ERROR_DLL_INIT_FAILED);
    }
    
    void test_method_(MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x80131016), h_result::MSEE_E_ASSEMBLYLOADINPROGRESS);
    }
    
    void test_method_(ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x800703EE), h_result::ERROR_FILE_INVALID);
    }
    
    void test_method_(failed_with_ERROR_FILE_INVALID) {
      assert::is_true(h_result::failed(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(failed_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::is_true(h_result::failed(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(failed_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::is_true(h_result::failed(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(failed_with_ERROR_LOCK_VIOLATION) {
      assert::is_true(h_result::failed(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(failed_with_ERROR_SHARING_VIOLATION) {
      assert::is_true(h_result::failed(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(failed_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::is_true(h_result::failed(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(failed_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::is_true(h_result::failed(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(failed_with_CTL_E_FILENOTFOUND) {
      assert::is_true(h_result::failed(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(failed_with_RPC_E_CHANGED_MODE) {
      assert::is_true(h_result::failed(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(failed_with_RO_E_CLOSED) {
      assert::is_true(h_result::failed(h_result::RO_E_CLOSED));
    }
    
    void test_method_(failed_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::is_true(h_result::failed(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(failed_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::is_true(h_result::failed(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(failed_with_COR_E_INDEXOUTOFRANGE) {
      assert::is_true(h_result::failed(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(failed_with_E_CHANGED_STATE) {
      assert::is_true(h_result::failed(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(failed_with_COR_E_FIELDACCESS) {
      assert::is_true(h_result::failed(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(failed_with_E_BOUNDS) {
      assert::is_true(h_result::failed(h_result::E_BOUNDS));
    }
    
    void test_method_(failed_with_DISP_E_TYPEMISMATCH) {
      assert::is_true(h_result::failed(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(failed_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::is_true(h_result::failed(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(failed_with_CTL_E_PATHNOTFOUND) {
      assert::is_true(h_result::failed(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_VERIFICATION) {
      assert::is_true(h_result::failed(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(failed_with_E_POINTER) {
      assert::is_true(h_result::failed(h_result::E_POINTER));
    }
    
    void test_method_(failed_with_COR_E_THREADSTATE) {
      assert::is_true(h_result::failed(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(failed_with_COR_E_THREADSTART) {
      assert::is_true(h_result::failed(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(failed_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(failed_with_CO_E_NOTINITIALIZED) {
      assert::is_true(h_result::failed(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(failed_with_COR_E_THREADINTERRUPTED) {
      assert::is_true(h_result::failed(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(failed_with_COR_E_THREADABORTED) {
      assert::is_true(h_result::failed(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(failed_with_E_UNEXPECTED) {
      assert::is_true(h_result::failed(h_result::E_UNEXPECTED));
    }
    
    void test_method_(failed_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::is_true(h_result::failed(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(failed_with_E_FAIL) {
      assert::is_true(h_result::failed(h_result::E_FAIL));
    }
    
    void test_method_(failed_with_COR_E_TYPELOAD) {
      assert::is_true(h_result::failed(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(failed_with_COR_E_STACKOVERFLOW) {
      assert::is_true(h_result::failed(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(failed_with_TYPE_E_TYPEMISMATCH) {
      assert::is_true(h_result::failed(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(failed_with_COR_E_SERIALIZATION) {
      assert::is_true(h_result::failed(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(failed_with_COR_E_SECURITY) {
      assert::is_true(h_result::failed(h_result::COR_E_SECURITY));
    }
    
    void test_method_(failed_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::is_true(h_result::failed(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(failed_with_E_ABORT) {
      assert::is_true(h_result::failed(h_result::E_ABORT));
    }
    
    void test_method_(failed_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::is_true(h_result::failed(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(failed_with_COR_E_INSUFFICIENTMEMORY) {
      assert::is_true(h_result::failed(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(failed_with_COR_E_REFLECTIONTYPELOAD) {
      assert::is_true(h_result::failed(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(failed_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::is_true(h_result::failed(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(failed_with_COR_E_PATHTOOLONG) {
      assert::is_true(h_result::failed(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(failed_with_COR_E_APPLICATION) {
      assert::is_true(h_result::failed(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(failed_with_COR_E_OPERATIONCANCELED) {
      assert::is_true(h_result::failed(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(failed_with_DISP_E_OVERFLOW) {
      assert::is_true(h_result::failed(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(failed_with_COR_E_OBJECTCLOSED) {
      assert::is_true(h_result::failed(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(failed_with_COR_E_NOTSUPPORTED) {
      assert::is_true(h_result::failed(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(failed_with_COR_E_NOTFINITENUMBER) {
      assert::is_true(h_result::failed(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(failed_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::is_true(h_result::failed(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(failed_with_COR_E_MISSINGMETHOD) {
      assert::is_true(h_result::failed(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(failed_with_COR_E_MISSINGMEMBER) {
      assert::is_true(h_result::failed(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(failed_with_ERROR_DISK_CORRUPT) {
      assert::is_true(h_result::failed(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(failed_with_COR_E_OUTOFMEMORY) {
      assert::is_true(h_result::failed(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(failed_with_COR_E_MISSINGFIELD) {
      assert::is_true(h_result::failed(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(failed_with_ERROR_TIMEOUT) {
      assert::is_true(h_result::failed(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(failed_with_COR_E_METHODACCESS) {
      assert::is_true(h_result::failed(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(failed_with_COR_E_ARGUMENT) {
      assert::is_true(h_result::failed(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(failed_with_COR_E_OVERFLOW) {
      assert::is_true(h_result::failed(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(failed_with_COR_E_APPDOMAINUNLOADED) {
      assert::is_true(h_result::failed(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(failed_with_COR_E_KEYNOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_INVALIDPROGRAM) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(failed_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(failed_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::is_true(h_result::failed(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(failed_with_COR_E_INVALIDCAST) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(failed_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::is_true(h_result::failed(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(failed_with_COR_E_FORMAT) {
      assert::is_true(h_result::failed(h_result::COR_E_FORMAT));
    }
    
    void test_method_(failed_with_COR_E_FILELOAD) {
      assert::is_true(h_result::failed(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(failed_with_COR_E_DIVIDEBYZERO) {
      assert::is_true(h_result::failed(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(failed_with_COR_E_TYPEUNLOADED) {
      assert::is_true(h_result::failed(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(failed_with_COR_E_FAILFAST) {
      assert::is_true(h_result::failed(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(failed_with_COR_E_EXCEPTION) {
      assert::is_true(h_result::failed(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(failed_with_COR_E_DLLNOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_EXECUTIONENGINE) {
      assert::is_true(h_result::failed(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(failed_with_COR_E_DIRECTORYNOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_CONTEXTMARSHAL) {
      assert::is_true(h_result::failed(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(failed_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::is_true(h_result::failed(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(failed_with_COR_E_DRIVENOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_AMBIGUOUSMATCH) {
      assert::is_true(h_result::failed(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(failed_with_COR_E_BADEXEFORMAT) {
      assert::is_true(h_result::failed(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(failed_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::is_true(h_result::failed(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(failed_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::is_true(h_result::failed(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(failed_with_COR_E_TARGETINVOCATION) {
      assert::is_true(h_result::failed(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(failed_with_COR_E_CODECONTRACTFAILED) {
      assert::is_true(h_result::failed(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(failed_with_S_OK) {
      assert::is_false(h_result::failed(h_result::S_OK));
    }
    
    void test_method_(failed_with_COR_E_BADIMAGEFORMAT) {
      assert::is_true(h_result::failed(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(failed_with_COR_E_TYPEACCESS) {
      assert::is_true(h_result::failed(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(failed_with_DISP_E_PARAMNOTFOUND) {
      assert::is_true(h_result::failed(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(failed_with_FUSION_E_INVALID_NAME) {
      assert::is_true(h_result::failed(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(failed_with_COR_E_ENDOFSTREAM) {
      assert::is_true(h_result::failed(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(failed_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::is_true(h_result::failed(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(failed_with_COR_E_RUNTIMEWRAPPED) {
      assert::is_true(h_result::failed(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(failed_with_COR_E_TARGET) {
      assert::is_true(h_result::failed(h_result::COR_E_TARGET));
    }
    
    void test_method_(failed_with_COR_E_DATAMISALIGNED) {
      assert::is_true(h_result::failed(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(failed_with_COR_E_TYPEINITIALIZATION) {
      assert::is_true(h_result::failed(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(failed_with_COR_E_ARITHMETIC) {
      assert::is_true(h_result::failed(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(failed_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(failed_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::is_true(h_result::failed(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(failed_with_COR_E_TIMEOUT) {
      assert::is_true(h_result::failed(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(failed_with_COR_E_FILENOTFOUND) {
      assert::is_true(h_result::failed(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_TARGETPARAMCOUNT) {
      assert::is_true(h_result::failed(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(failed_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::is_true(h_result::failed(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(failed_with_E_NOTIMPL) {
      assert::is_true(h_result::failed(h_result::E_NOTIMPL));
    }
    
    void test_method_(failed_with_COR_E_MARSHALDIRECTIVE) {
      assert::is_true(h_result::failed(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(failed_with_DISP_E_BADVARTYPE) {
      assert::is_true(h_result::failed(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(failed_with_COR_E_IO) {
      assert::is_true(h_result::failed(h_result::COR_E_IO));
    }
    
    void test_method_(failed_with_ERROR_OPEN_FAILED) {
      assert::is_true(h_result::failed(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(failed_with_COR_E_ABANDONEDMUTEX) {
      assert::is_true(h_result::failed(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(failed_with_ERROR_DLL_INIT_FAILED) {
      assert::is_true(h_result::failed(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(failed_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::is_true(h_result::failed(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(failed_with_S_FALSE) {
      assert::is_false(h_result::failed(h_result::S_FALSE));
    }
    
    void test_method_(failed_with_COR_E_MEMBERACCESS) {
      assert::is_true(h_result::failed(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(failed_with_COR_E_RANK) {
      assert::is_true(h_result::failed(h_result::COR_E_RANK));
    }
    
    void test_method_(failed_with_COR_E_INVALIDCOMOBJECT) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(failed_with_E_HANDLE) {
      assert::is_true(h_result::failed(h_result::E_HANDLE));
    }
    
    void test_method_(failed_with_COR_E_INVALIDOPERATION) {
      assert::is_true(h_result::failed(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(failed_with_STG_E_PATHNOTFOUND) {
      assert::is_true(h_result::failed(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(failed_with_COR_E_SYSTEM) {
      assert::is_true(h_result::failed(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(get_code_with_ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x03EE), h_result::get_code(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(get_code_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x1016), h_result::get_code(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(get_code_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x03ED), h_result::get_code(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(get_code_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x0021), h_result::get_code(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(get_code_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x0020), h_result::get_code(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(get_code_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x0004), h_result::get_code(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(get_code_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x1040), h_result::get_code(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(get_code_with_CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0035), h_result::get_code(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(get_code_with_RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x0106), h_result::get_code(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(get_code_with_RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x0013), h_result::get_code(h_result::RO_E_CLOSED));
    }
    
    void test_method_(get_code_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x3B1F), h_result::get_code(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(get_code_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x106A), h_result::get_code(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(get_code_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x1508), h_result::get_code(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(get_code_with_E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x000C), h_result::get_code(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(get_code_with_COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x1507), h_result::get_code(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(get_code_with_E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x000B), h_result::get_code(h_result::E_BOUNDS));
    }
    
    void test_method_(get_code_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x0005), h_result::get_code(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(get_code_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x152C), h_result::get_code(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(get_code_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x004C), h_result::get_code(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x150D), h_result::get_code(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(get_code_with_E_POINTER) {
      assert::are_equal(static_cast<int32>(0x4003), h_result::get_code(h_result::E_POINTER));
    }
    
    void test_method_(get_code_with_COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x1520), h_result::get_code(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(get_code_with_COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x1525), h_result::get_code(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(get_code_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x1523), h_result::get_code(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(get_code_with_CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x01F0), h_result::get_code(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(get_code_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x1519), h_result::get_code(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(get_code_with_COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x1530), h_result::get_code(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(get_code_with_E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0xFFFF), h_result::get_code(h_result::E_UNEXPECTED));
    }
    
    void test_method_(get_code_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x1518), h_result::get_code(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(get_code_with_E_FAIL) {
      assert::are_equal(static_cast<int32>(0x4005), h_result::get_code(h_result::E_FAIL));
    }
    
    void test_method_(get_code_with_COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x1522), h_result::get_code(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(get_code_with_COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x03E9), h_result::get_code(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(get_code_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x8CA0), h_result::get_code(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(get_code_with_COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x150C), h_result::get_code(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(get_code_with_COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x150A), h_result::get_code(h_result::COR_E_SECURITY));
    }
    
    void test_method_(get_code_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x1533), h_result::get_code(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_code_with_E_ABORT) {
      assert::are_equal(static_cast<int32>(0x4004), h_result::get_code(h_result::E_ABORT));
    }
    
    void test_method_(get_code_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x1538), h_result::get_code(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(get_code_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x153D), h_result::get_code(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(get_code_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x1602), h_result::get_code(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(get_code_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x1539), h_result::get_code(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(get_code_with_COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x00CE), h_result::get_code(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(get_code_with_COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x1600), h_result::get_code(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(get_code_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x153B), h_result::get_code(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(get_code_with_DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x000A), h_result::get_code(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(get_code_with_COR_E_OBJECTCLOSED) {
      assert::are_equal(static_cast<int32>(0x1622), h_result::get_code(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(get_code_with_COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x1515), h_result::get_code(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(get_code_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x1528), h_result::get_code(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(get_code_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x1514), h_result::get_code(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(get_code_with_COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x1513), h_result::get_code(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(get_code_with_COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x1512), h_result::get_code(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(get_code_with_ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x0571), h_result::get_code(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(get_code_with_COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x000E), h_result::get_code(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(get_code_with_COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x1511), h_result::get_code(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(get_code_with_ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x05B4), h_result::get_code(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(get_code_with_COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x1510), h_result::get_code(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(get_code_with_COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x0057), h_result::get_code(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(get_code_with_COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x1516), h_result::get_code(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(get_code_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x1014), h_result::get_code(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(get_code_with_COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x1577), h_result::get_code(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x153A), h_result::get_code(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x1601), h_result::get_code(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(get_code_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x1536), h_result::get_code(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x4002), h_result::get_code(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(get_code_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x0005), h_result::get_code(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(get_code_with_COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x1537), h_result::get_code(h_result::COR_E_FORMAT));
    }
    
    void test_method_(get_code_with_COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x1621), h_result::get_code(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(get_code_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x0012), h_result::get_code(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(get_code_with_COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x1013), h_result::get_code(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(get_code_with_COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x1623), h_result::get_code(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(get_code_with_COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x1500), h_result::get_code(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(get_code_with_COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x1524), h_result::get_code(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x1506), h_result::get_code(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(get_code_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0003), h_result::get_code(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x1504), h_result::get_code(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(get_code_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x1502), h_result::get_code(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(get_code_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x211D), h_result::get_code(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(get_code_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0007), h_result::get_code(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x00C1), h_result::get_code(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(get_code_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x1578), h_result::get_code(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(get_code_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x1015), h_result::get_code(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(get_code_with_COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x1604), h_result::get_code(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(get_code_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x1542), h_result::get_code(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(get_code_with_S_OK) {
      assert::are_equal(static_cast<int32>(0x0000), h_result::get_code(h_result::S_OK));
    }
    
    void test_method_(get_code_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x000B), h_result::get_code(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(get_code_with_COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x1543), h_result::get_code(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(get_code_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0004), h_result::get_code(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(get_code_with_FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x1047), h_result::get_code(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(get_code_with_COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x0026), h_result::get_code(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(get_code_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x1529), h_result::get_code(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(get_code_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x153E), h_result::get_code(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(get_code_with_COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x1603), h_result::get_code(h_result::COR_E_TARGET));
    }
    
    void test_method_(get_code_with_COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x1541), h_result::get_code(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(get_code_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x1534), h_result::get_code(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(get_code_with_COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x0216), h_result::get_code(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x1531), h_result::get_code(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(get_code_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x1532), h_result::get_code(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(get_code_with_COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x1505), h_result::get_code(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(get_code_with_COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0002), h_result::get_code(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x000E), h_result::get_code(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(get_code_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x1503), h_result::get_code(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_code_with_E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x4001), h_result::get_code(h_result::E_NOTIMPL));
    }
    
    void test_method_(get_code_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x1535), h_result::get_code(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(get_code_with_DISP_E_BADVARTYPE) {
      assert::are_equal(static_cast<int32>(0x0008), h_result::get_code(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(get_code_with_COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x1620), h_result::get_code(h_result::COR_E_IO));
    }
    
    void test_method_(get_code_with_ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x006E), h_result::get_code(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(get_code_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x152D), h_result::get_code(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(get_code_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x045A), h_result::get_code(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(get_code_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x1605), h_result::get_code(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(get_code_with_S_FALSE) {
      assert::are_equal(static_cast<int32>(0x0001), h_result::get_code(h_result::S_FALSE));
    }
    
    void test_method_(get_code_with_COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x151A), h_result::get_code(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(get_code_with_COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x1517), h_result::get_code(h_result::COR_E_RANK));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x1527), h_result::get_code(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(get_code_with_E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x0006), h_result::get_code(h_result::E_HANDLE));
    }
    
    void test_method_(get_code_with_COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x1509), h_result::get_code(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(get_code_with_STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x0003), h_result::get_code(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(get_code_with_COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x1501), h_result::get_code(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(get_facility_with_ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(get_facility_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(get_facility_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(get_facility_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(get_facility_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(get_facility_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(get_facility_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(get_facility_with_CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0xA), h_result::get_facility(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(get_facility_with_RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x1), h_result::get_facility(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(get_facility_with_RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::RO_E_CLOSED));
    }
    
    void test_method_(get_facility_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(get_facility_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(get_facility_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(get_facility_with_E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(get_facility_with_COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(get_facility_with_E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_BOUNDS));
    }
    
    void test_method_(get_facility_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(get_facility_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(get_facility_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0xA), h_result::get_facility(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(get_facility_with_E_POINTER) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_POINTER));
    }
    
    void test_method_(get_facility_with_COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(get_facility_with_COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(get_facility_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(get_facility_with_CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x4), h_result::get_facility(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(get_facility_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(get_facility_with_COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(get_facility_with_E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_UNEXPECTED));
    }
    
    void test_method_(get_facility_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(get_facility_with_E_FAIL) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_FAIL));
    }
    
    void test_method_(get_facility_with_COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(get_facility_with_COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(get_facility_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(get_facility_with_COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(get_facility_with_COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SECURITY));
    }
    
    void test_method_(get_facility_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_facility_with_E_ABORT) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_ABORT));
    }
    
    void test_method_(get_facility_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(get_facility_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(get_facility_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(get_facility_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(get_facility_with_COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(get_facility_with_COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(get_facility_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(get_facility_with_DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(get_facility_with_COR_E_OBJECTCLOSED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(get_facility_with_COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(get_facility_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(get_facility_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(get_facility_with_COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(get_facility_with_COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(get_facility_with_ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(get_facility_with_COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(get_facility_with_COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(get_facility_with_ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(get_facility_with_COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(get_facility_with_COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(get_facility_with_COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(get_facility_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(get_facility_with_COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(get_facility_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(get_facility_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(get_facility_with_COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_FORMAT));
    }
    
    void test_method_(get_facility_with_COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(get_facility_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(get_facility_with_COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(get_facility_with_COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(get_facility_with_COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(get_facility_with_COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(get_facility_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(get_facility_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(get_facility_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(get_facility_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(get_facility_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(get_facility_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(get_facility_with_COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(get_facility_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(get_facility_with_S_OK) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::S_OK));
    }
    
    void test_method_(get_facility_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(get_facility_with_COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(get_facility_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(get_facility_with_FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(get_facility_with_COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(get_facility_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(get_facility_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(get_facility_with_COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TARGET));
    }
    
    void test_method_(get_facility_with_COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(get_facility_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(get_facility_with_COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(get_facility_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(get_facility_with_COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(get_facility_with_COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(get_facility_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_facility_with_E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::E_NOTIMPL));
    }
    
    void test_method_(get_facility_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(get_facility_with_DISP_E_BADVARTYPE) {
      assert::are_equal(static_cast<int32>(0x2), h_result::get_facility(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(get_facility_with_COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_IO));
    }
    
    void test_method_(get_facility_with_ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(get_facility_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(get_facility_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(get_facility_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(get_facility_with_S_FALSE) {
      assert::are_equal(static_cast<int32>(0x0), h_result::get_facility(h_result::S_FALSE));
    }
    
    void test_method_(get_facility_with_COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(get_facility_with_COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_RANK));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(get_facility_with_E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x7), h_result::get_facility(h_result::E_HANDLE));
    }
    
    void test_method_(get_facility_with_COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(get_facility_with_STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x3), h_result::get_facility(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(get_facility_with_COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x13), h_result::get_facility(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(get_h_results) {
      assert::are_equal(117_z, h_result::get_h_results().length());
      collection_assert::contains({h_result::ERROR_FILE_INVALID}, h_result::get_h_results());
      collection_assert::contains({h_result::MSEE_E_ASSEMBLYLOADINPROGRESS}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_UNRECOGNIZED_VOLUME}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_LOCK_VIOLATION}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_SHARING_VIOLATION}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_TOO_MANY_OPEN_FILES}, h_result::get_h_results());
      collection_assert::contains({h_result::FUSION_E_REF_DEF_MISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::CTL_E_FILENOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::RPC_E_CHANGED_MODE}, h_result::get_h_results());
      collection_assert::contains({h_result::RO_E_CLOSED}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_MRM_MAP_NOT_FOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_AMBIGUOUSIMPLEMENTATION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INDEXOUTOFRANGE}, h_result::get_h_results());
      collection_assert::contains({h_result::E_CHANGED_STATE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_FIELDACCESS}, h_result::get_h_results());
      collection_assert::contains({h_result::E_BOUNDS}, h_result::get_h_results());
      collection_assert::contains({h_result::DISP_E_TYPEMISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_WAITHANDLECANNOTBEOPENED}, h_result::get_h_results());
      collection_assert::contains({h_result::CTL_E_PATHNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_VERIFICATION}, h_result::get_h_results());
      collection_assert::contains({h_result::E_POINTER}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_THREADSTATE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_THREADSTART}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ENTRYPOINTNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::CO_E_NOTINITIALIZED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_THREADINTERRUPTED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_THREADABORTED}, h_result::get_h_results());
      collection_assert::contains({h_result::E_UNEXPECTED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SYNCHRONIZATIONLOCK}, h_result::get_h_results());
      collection_assert::contains({h_result::E_FAIL}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TYPELOAD}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_STACKOVERFLOW}, h_result::get_h_results());
      collection_assert::contains({h_result::TYPE_E_TYPEMISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SERIALIZATION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SECURITY}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SAFEARRAYTYPEMISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::E_ABORT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SAFEARRAYRANKMISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INSUFFICIENTMEMORY}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_REFLECTIONTYPELOAD}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_PLATFORMNOTSUPPORTED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_PATHTOOLONG}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_APPLICATION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_OPERATIONCANCELED}, h_result::get_h_results());
      collection_assert::contains({h_result::DISP_E_OVERFLOW}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_OBJECTCLOSED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_NOTSUPPORTED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_NOTFINITENUMBER}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MULTICASTNOTSUPPORTED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MISSINGMETHOD}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MISSINGMEMBER}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_DISK_CORRUPT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_OUTOFMEMORY}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MISSINGFIELD}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_TIMEOUT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_METHODACCESS}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ARGUMENT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_OVERFLOW}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_APPDOMAINUNLOADED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_KEYNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDPROGRAM}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDFILTERCRITERIA}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MISSINGSATELLITEASSEMBLY}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDCAST}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_UNAUTHORIZEDACCESS}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_FORMAT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_FILELOAD}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DIVIDEBYZERO}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TYPEUNLOADED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_FAILFAST}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_EXCEPTION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DLLNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_EXECUTIONENGINE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DIRECTORYNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_CONTEXTMARSHAL}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ARGUMENTOUTOFRANGE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_AMBIGUOUSMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DRIVENOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_BADEXEFORMAT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INSUFFICIENTEXECUTIONSTACK}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_CANNOTUNLOADAPPDOMAIN}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TARGETINVOCATION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_CODECONTRACTFAILED}, h_result::get_h_results());
      collection_assert::contains({h_result::S_OK}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_BADIMAGEFORMAT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TYPEACCESS}, h_result::get_h_results());
      collection_assert::contains({h_result::DISP_E_PARAMNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::FUSION_E_INVALID_NAME}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ENDOFSTREAM}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DUPLICATEWAITOBJECT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_RUNTIMEWRAPPED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TARGET}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_DATAMISALIGNED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TYPEINITIALIZATION}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ARITHMETIC}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDOLEVARIANTTYPE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MISSINGMANIFESTRESOURCE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TIMEOUT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_FILENOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_TARGETPARAMCOUNT}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ARRAYTYPEMISMATCH}, h_result::get_h_results());
      collection_assert::contains({h_result::E_NOTIMPL}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MARSHALDIRECTIVE}, h_result::get_h_results());
      collection_assert::contains({h_result::DISP_E_BADVARTYPE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_IO}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_OPEN_FAILED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_ABANDONEDMUTEX}, h_result::get_h_results());
      collection_assert::contains({h_result::ERROR_DLL_INIT_FAILED}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_CUSTOMATTRIBUTEFORMAT}, h_result::get_h_results());
      collection_assert::contains({h_result::S_FALSE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_MEMBERACCESS}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_RANK}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDCOMOBJECT}, h_result::get_h_results());
      collection_assert::contains({h_result::E_HANDLE}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_INVALIDOPERATION}, h_result::get_h_results());
      collection_assert::contains({h_result::STG_E_PATHNOTFOUND}, h_result::get_h_results());
      collection_assert::contains({h_result::COR_E_SYSTEM}, h_result::get_h_results());
    }
    
    void test_method_(get_message_with_S_OK) {
      assert::are_equal("Operation successful.", h_result::get_message(h_result::S_OK));
    }
    
    void test_method_(get_message_with_S_FALSE) {
      assert::are_equal("Operation successful but returned no results.", h_result::get_message(h_result::S_FALSE));
    }
    
    void test_method_(get_message_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal("The wait completed due to an abandoned mutex.", h_result::get_message(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(get_message_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal("Ambiguous implementation found.", h_result::get_message(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(get_message_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal("Ambiguous match found.", h_result::get_message(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(get_message_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal("Attempted to access an unloaded AppDomain.", h_result::get_message(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(get_message_with_COR_E_APPLICATION) {
      assert::are_equal("Error in the application.", h_result::get_message(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(get_message_with_COR_E_ARGUMENT) {
      assert::are_equal("Value does not fall within the expected range.", h_result::get_message(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(get_message_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal("Specified argument was out of the range of valid values.", h_result::get_message(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(get_message_with_COR_E_ARITHMETIC) {
      assert::are_equal("Overflow or underflow in the arithmetic operation.", h_result::get_message(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(get_message_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal("Attempted to access an element as a type incompatible with the array.", h_result::get_message(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_message_with_COR_E_BADEXEFORMAT) {
      assert::are_equal("Format of the executable (.exe) cannot be run.", h_result::get_message(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(get_message_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal("Format of the executable (.exe) or library (.dll) is invalid.", h_result::get_message(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(get_message_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal("Attempt to unload the AppDomain failed.", h_result::get_message(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(get_message_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal("A code contract (ie, precondition, postcondition, invariant, or assert) failed.", h_result::get_message(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(get_message_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal("Attempted to marshal an object across a context boundary.", h_result::get_message(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(get_message_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal("Binary format of the specified custom attribute was invalid.", h_result::get_message(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(get_message_with_COR_E_DATAMISALIGNED) {
      assert::are_equal("A datatype misalignment was detected in a load or store instruction.", h_result::get_message(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(get_message_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal("Attempted to divide by zero.", h_result::get_message(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(get_message_with_COR_E_DLLNOTFOUND) {
      assert::are_equal("Dll was not found.", h_result::get_message(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal("Duplicate objects in argument.", h_result::get_message(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(get_message_with_COR_E_DRIVEOTFOUND) {
      assert::are_equal("Could not find the drive. The drive might not be ready or might not be mapped.", h_result::get_message(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_ENDOFSTREAM) {
      assert::are_equal("Attempted to read past the end of the stream.", h_result::get_message(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(get_message_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal("Entry point was not found.", h_result::get_message(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_EXCEPTION) {
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", h_result::get_message(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(get_message_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal("Internal error in the runtime.", h_result::get_message(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(get_message_with_COR_E_FAILFAST) {
      assert::are_equal("Fail fast.", h_result::get_message(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(get_message_with_COR_E_FIELDACCESS) {
      assert::are_equal("Attempted to access a field that is not accessible by the caller.", h_result::get_message(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(get_message_with_COR_E_FILELOAD) {
      assert::are_equal("Could not load the specified file.", h_result::get_message(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(get_message_with_COR_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_FORMAT) {
      assert::are_equal("One of the identified items was in an invalid format.", h_result::get_message(h_result::COR_E_FORMAT));
    }
    
    void test_method_(get_message_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal("Index was outside the bounds of the array.", h_result::get_message(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(get_message_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal("Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space.", h_result::get_message(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(get_message_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::get_message(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDCAST) {
      assert::are_equal("Specified cast is not valid.", h_result::get_message(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal("Attempt has been made to use a COM object that does not have a backing class factory.", h_result::get_message(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal("Specified filter criteria was invalid.", h_result::get_message(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal("Specified OLE variant was invalid.", h_result::get_message(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDOPERATION) {
      assert::are_equal("Operation is not valid due to the current state of the object.", h_result::get_message(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(get_message_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal("xtd detected an invalid program.", h_result::get_message(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(get_message_with_COR_E_IO) {
      assert::are_equal("I/O error occurred.", h_result::get_message(h_result::COR_E_IO));
    }
    
    void test_method_(get_message_with_COR_E_KEYNOTFOUND) {
      assert::are_equal("The given key was not present in the dictionary.", h_result::get_message(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(get_message_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal("Marshaling directives are invalid.", h_result::get_message(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(get_message_with_COR_E_MEMBERACCESS) {
      assert::are_equal("Cannot access member.", h_result::get_message(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(get_message_with_COR_E_METHODACCESS) {
      assert::are_equal("Attempt to access the method failed.", h_result::get_message(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(get_message_with_COR_E_MISSINGFIELD) {
      assert::are_equal("Attempted to access a non-existing field.", h_result::get_message(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal("Attempted to access a missing manifest resource.", h_result::get_message(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMEMBER) {
      assert::are_equal("Attempted to access a missing member.", h_result::get_message(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(get_message_with_COR_E_MISSINGMETHOD) {
      assert::are_equal("Attempted to access a missing method.", h_result::get_message(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(get_message_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal("Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application.", h_result::get_message(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(get_message_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal("Attempted to add multiple callbacks to a delegate that does not support multicast.", h_result::get_message(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(get_message_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal("Number encountered was not a finite quantity.", h_result::get_message(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(get_message_with_COR_E_NOTSUPPORTED) {
      assert::are_equal("Specified method is not supported.", h_result::get_message(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(get_message_with_COR_E_OBJECTCLOSED) {
      assert::are_equal("Cannot access a closed object.", h_result::get_message(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(get_message_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal("The operation was canceled.", h_result::get_message(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(get_message_with_COR_E_OUTOFMEMORY) {
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::get_message(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(get_message_with_COR_E_OVERFLOW) {
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::get_message(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(get_message_with_COR_E_PATHTOOLONG) {
      assert::are_equal("The specified file name or path is too long, or a component of the specified path is too long.", h_result::get_message(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(get_message_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal("Operation is not supported on this platform.", h_result::get_message(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(get_message_with_COR_E_RANK) {
      assert::are_equal("Attempted to operate on an array with the incorrect number of dimensions.", h_result::get_message(h_result::COR_E_RANK));
    }
    
    void test_method_(get_message_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal("Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown.", h_result::get_message(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(get_message_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal("An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception.", h_result::get_message(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(get_message_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal("Specified array was not of the expected rank.", h_result::get_message(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(get_message_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal("Specified array was not of the expected type.", h_result::get_message(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_message_with_COR_E_SECURITY) {
      assert::are_equal("Security error.", h_result::get_message(h_result::COR_E_SECURITY));
    }
    
    void test_method_(get_message_with_COR_E_SERIALIZATION) {
      assert::are_equal("Serialization error.", h_result::get_message(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(get_message_with_COR_E_STACKOVERFLOW) {
      assert::are_equal("Operation caused a stack overflow.", h_result::get_message(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(get_message_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal("Object synchronization method was called from an unsynchronized block of code.", h_result::get_message(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(get_message_with_COR_E_SYSTEM) {
      assert::are_equal("System error.", h_result::get_message(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(get_message_with_COR_E_TARGET) {
      assert::are_equal("Exception of type 'xtd::reflection::target_exception' was thrown.", h_result::get_message(h_result::COR_E_TARGET));
    }
    
    void test_method_(get_message_with_COR_E_TARGETINVOCATION) {
      assert::are_equal("Exception has been thrown by the target of an invocation.", h_result::get_message(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(get_message_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal("Number of parameters specified does not match the expected number.", h_result::get_message(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(get_message_with_COR_E_THREADABORTED) {
      assert::are_equal("Thread was aborted.", h_result::get_message(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(get_message_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal("Thread was interrupted from a waiting state.", h_result::get_message(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(get_message_with_COR_E_THREADSTART) {
      assert::are_equal("Thread start failure.", h_result::get_message(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(get_message_with_COR_E_THREADSTATE) {
      assert::are_equal("Thread was in an invalid state for the operation being executed.", h_result::get_message(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(get_message_with_COR_E_TIMEOUT) {
      assert::are_equal("The operation has timed out.", h_result::get_message(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(get_message_with_COR_E_TYPEACCESS) {
      assert::are_equal("Attempt to access the type failed.", h_result::get_message(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(get_message_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal("The type initializer for 'value' threw an exception.", h_result::get_message(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(get_message_with_COR_E_TYPELOAD) {
      assert::are_equal("Failure has occurred while loading a type.", h_result::get_message(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(get_message_with_COR_E_TYPEUNLOADED) {
      assert::are_equal("Type had been unloaded.", h_result::get_message(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(get_message_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal("Attempted to perform an unauthorized operation.", h_result::get_message(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(get_message_with_COR_E_VERIFICATION) {
      assert::are_equal("Operation could destabilize the runtime.", h_result::get_message(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(get_message_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal("No handle of the given name exists.", h_result::get_message(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(get_message_with_CO_E_NOTINITIALIZED) {
      assert::are_equal("Not initialized", h_result::get_message(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(get_message_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal("Could not find the parameter.", h_result::get_message(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(get_message_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal("Attempt to access a variable with an incompatible type.", h_result::get_message(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(get_message_with_DISP_E_BADVARTYPE) {
      assert::are_equal("Invalid variable type.", h_result::get_message(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(get_message_with_DISP_E_OVERFLOW) {
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::get_message(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(get_message_with_DISP_E_DIVBYZERO) {
      assert::are_equal("Attempted to divide by zero.", h_result::get_message(h_result::DISP_E_DIVBYZERO));
    }
    
    void test_method_(get_message_with_E_ABORT) {
      assert::are_equal("Operation aborted.", h_result::get_message(h_result::E_ABORT));
    }
    
    void test_method_(get_message_with_E_BOUNDS) {
      assert::are_equal("Bounds exception", h_result::get_message(h_result::E_BOUNDS));
    }
    
    void test_method_(get_message_with_E_CHANGED_STATE) {
      assert::are_equal("The state has been modified.", h_result::get_message(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(get_message_with_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::E_FILENOTFOUND));
    }
    
    void test_method_(get_message_with_E_FAIL) {
      assert::are_equal("Unspecified failure.", h_result::get_message(h_result::E_FAIL));
    }
    
    void test_method_(get_message_with_E_HANDLE) {
      assert::are_equal("The handle is invalid.", h_result::get_message(h_result::E_HANDLE));
    }
    
    void test_method_(get_message_with_E_INVALIDARG) {
      assert::are_equal("Value does not fall within the expected range.", h_result::get_message(h_result::E_INVALIDARG));
    }
    
    void test_method_(get_message_with_E_NOTIMPL) {
      assert::are_equal("The method or operation is not implemented.", h_result::get_message(h_result::E_NOTIMPL));
    }
    
    void test_method_(get_message_with_E_POINTER) {
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", h_result::get_message(h_result::E_POINTER));
    }
    
    void test_method_(get_message_with_E_UNEXPECTED) {
      assert::are_equal("Unexpected failure.", h_result::get_message(h_result::E_UNEXPECTED));
    }
    
    void test_method_(get_message_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal("Resource map not found.", h_result::get_message(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(get_message_with_ERROR_TIMEOUT) {
      assert::are_equal("The operation has timed out.", h_result::get_message(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(get_message_with_RO_E_CLOSED) {
      assert::are_equal("The object has been closed.", h_result::get_message(h_result::RO_E_CLOSED));
    }
    
    void test_method_(get_message_with_RPC_E_CHANGED_MODE) {
      assert::are_equal("Cannot change the current thread mode.", h_result::get_message(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(get_message_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal("Incompatible type.", h_result::get_message(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(get_message_with_STG_E_PATHNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(get_message_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::get_message(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(get_message_with_CTL_E_FILENOTFOUND) {
      assert::are_equal("Unable to find the specified file.", h_result::get_message(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(get_message_with_FUSION_E_INVALID_NAME) {
      assert::are_equal("Fusion invalid name exception.", h_result::get_message(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(get_message_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal("Fusion the reference definition is incompatible.", h_result::get_message(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(get_message_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal("Too many open files.", h_result::get_message(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(get_message_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal("Sharing violation.", h_result::get_message(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(get_message_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal("Lock violations.", h_result::get_message(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(get_message_with_ERROR_OPEN_FAILED) {
      assert::are_equal("Open failed.", h_result::get_message(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(get_message_with_ERROR_DISK_CORRUPT) {
      assert::are_equal("Disk corrupt.", h_result::get_message(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(get_message_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal("Unrecognized volume.", h_result::get_message(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(get_message_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal("DLL init failed.", h_result::get_message(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(get_message_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal("Assembly load in progress.", h_result::get_message(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(get_message_with_ERROR_FILE_INVALID) {
      assert::are_equal("File invalid.", h_result::get_message(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(get_messages) {
      using h_result_message_pair = std::pair<int32, string>;
      assert::are_equal(117_z, h_result::get_messages().size());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_FILE_INVALID, "File invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::MSEE_E_ASSEMBLYLOADINPROGRESS, "Assembly load in progress."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_UNRECOGNIZED_VOLUME, "Unrecognized volume."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_LOCK_VIOLATION, "Lock violations."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_SHARING_VIOLATION, "Sharing violation."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_TOO_MANY_OPEN_FILES, "Too many open files."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::FUSION_E_REF_DEF_MISMATCH, "Fusion the reference definition is incompatible."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::CTL_E_FILENOTFOUND, "Unable to find the specified file."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::RPC_E_CHANGED_MODE, "Cannot change the current thread mode."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::RO_E_CLOSED, "The object has been closed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_MRM_MAP_NOT_FOUND, "Resource map not found."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_AMBIGUOUSIMPLEMENTATION, "Ambiguous implementation found."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INDEXOUTOFRANGE, "Index was outside the bounds of the array."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_CHANGED_STATE, "The state has been modified."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_FIELDACCESS, "Attempted to access a field that is not accessible by the caller."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_BOUNDS, "Bounds exception"}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::DISP_E_TYPEMISMATCH, "Attempt to access a variable with an incompatible type."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_WAITHANDLECANNOTBEOPENED, "No handle of the given name exists."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::CTL_E_PATHNOTFOUND, "Attempted to access a path that is not on the disk."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_VERIFICATION, "Operation could destabilize the runtime."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_POINTER, "Attempted to read or write protected memory. This is often an indication that other memory is corrupt."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_THREADSTATE, "Thread was in an invalid state for the operation being executed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_THREADSTART, "Thread start failure."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ENTRYPOINTNOTFOUND, "Entry point was not found."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::CO_E_NOTINITIALIZED, "Not initialized"}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_THREADINTERRUPTED, "Thread was interrupted from a waiting state."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_THREADABORTED, "Thread was aborted."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_UNEXPECTED, "Unexpected failure."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SYNCHRONIZATIONLOCK, "Object synchronization method was called from an unsynchronized block of code."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_FAIL, "Unspecified failure."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TYPELOAD, "Failure has occurred while loading a type."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_STACKOVERFLOW, "Operation caused a stack overflow."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::TYPE_E_TYPEMISMATCH, "Incompatible type."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SERIALIZATION, "Serialization error."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SECURITY, "Security error."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SAFEARRAYTYPEMISMATCH, "Specified array was not of the expected type."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_ABORT, "Operation aborted."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SAFEARRAYRANKMISMATCH, "Specified array was not of the expected rank."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INSUFFICIENTMEMORY, "Insufficient memory to continue the execution of the program."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_REFLECTIONTYPELOAD, "Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_PLATFORMNOTSUPPORTED, "Operation is not supported on this platform."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_PATHTOOLONG, "The specified file name or path is too long, or a component of the specified path is too long."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_APPLICATION, "Error in the application."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_OPERATIONCANCELED, "The operation was canceled."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::DISP_E_OVERFLOW, "Arithmetic operation resulted in an overflow."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_OBJECTCLOSED, "Cannot access a closed object."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_NOTSUPPORTED, "Specified method is not supported."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_NOTFINITENUMBER, "Number encountered was not a finite quantity."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MULTICASTNOTSUPPORTED, "Attempted to add multiple callbacks to a delegate that does not support multicast."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MISSINGMETHOD, "Attempted to access a missing method."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MISSINGMEMBER, "Attempted to access a missing member."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_DISK_CORRUPT, "Disk corrupt."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_OUTOFMEMORY, "Insufficient memory to continue the execution of the program."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MISSINGFIELD, "Attempted to access a non-existing field."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_TIMEOUT, "The operation has timed out."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_METHODACCESS, "Attempt to access the method failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ARGUMENT, "Value does not fall within the expected range."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_OVERFLOW, "Arithmetic operation resulted in an overflow."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_APPDOMAINUNLOADED, "Attempted to access an unloaded AppDomain."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_KEYNOTFOUND, "The given key was not present in the dictionary."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDPROGRAM, "xtd detected an invalid program."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDFILTERCRITERIA, "Specified filter criteria was invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MISSINGSATELLITEASSEMBLY, "Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDCAST, "Specified cast is not valid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_UNAUTHORIZEDACCESS, "Attempted to perform an unauthorized operation."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_FORMAT, "One of the identified items was in an invalid format."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_FILELOAD, "Could not load the specified file."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DIVIDEBYZERO, "Attempted to divide by zero."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TYPEUNLOADED, "Type had been unloaded."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_FAILFAST, "Fail fast."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_EXCEPTION, "Exception of type 'xtd::exception' was thrown."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DLLNOTFOUND, "Dll was not found."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_EXECUTIONENGINE, "Internal error in the runtime."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DIRECTORYNOTFOUND, "Attempted to access a path that is not on the disk."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_CONTEXTMARSHAL, "Attempted to marshal an object across a context boundary."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ARGUMENTOUTOFRANGE, "Specified argument was out of the range of valid values."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_AMBIGUOUSMATCH, "Ambiguous match found."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DRIVENOTFOUND, "Could not find the drive. The drive might not be ready or might not be mapped."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_BADEXEFORMAT, "Format of the executable (.exe) cannot be run."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INSUFFICIENTEXECUTIONSTACK, "Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_CANNOTUNLOADAPPDOMAIN, "Attempt to unload the AppDomain failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TARGETINVOCATION, "Exception has been thrown by the target of an invocation."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_CODECONTRACTFAILED, "A code contract (ie, precondition, postcondition, invariant, or assert) failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::S_OK, "Operation successful."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_BADIMAGEFORMAT, "Format of the executable (.exe) or library (.dll) is invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TYPEACCESS, "Attempt to access the type failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::DISP_E_PARAMNOTFOUND, "Could not find the parameter."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::FUSION_E_INVALID_NAME, "Fusion invalid name exception."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ENDOFSTREAM, "Attempted to read past the end of the stream."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DUPLICATEWAITOBJECT, "Duplicate objects in argument."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_RUNTIMEWRAPPED, "An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TARGET, "Exception of type 'xtd::reflection::target_exception' was thrown."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_DATAMISALIGNED, "A datatype misalignment was detected in a load or store instruction."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TYPEINITIALIZATION, "The type initializer for 'value' threw an exception."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ARITHMETIC, "Overflow or underflow in the arithmetic operation."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDOLEVARIANTTYPE, "Specified OLE variant was invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MISSINGMANIFESTRESOURCE, "Attempted to access a missing manifest resource."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TIMEOUT, "The operation has timed out."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_FILENOTFOUND, "Unable to find the specified file."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_TARGETPARAMCOUNT, "Number of parameters specified does not match the expected number."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ARRAYTYPEMISMATCH, "Attempted to access an element as a type incompatible with the array."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_NOTIMPL, "The method or operation is not implemented."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MARSHALDIRECTIVE, "Marshaling directives are invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::DISP_E_BADVARTYPE, "Invalid variable type."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_IO, "I/O error occurred."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_OPEN_FAILED, "Open failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_ABANDONEDMUTEX, "The wait completed due to an abandoned mutex."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::ERROR_DLL_INIT_FAILED, "DLL init failed."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_CUSTOMATTRIBUTEFORMAT, "Binary format of the specified custom attribute was invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::S_FALSE, "Operation successful but returned no results."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_MEMBERACCESS, "Cannot access member."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_RANK, "Attempted to operate on an array with the incorrect number of dimensions."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDCOMOBJECT, "Attempt has been made to use a COM object that does not have a backing class factory."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::E_HANDLE, "The handle is invalid."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_INVALIDOPERATION, "Operation is not valid due to the current state of the object."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::STG_E_PATHNOTFOUND, "Attempted to access a path that is not on the disk."}}, h_result::get_messages());
      collection_assert::contains({h_result_message_pair {h_result::COR_E_SYSTEM, "System error."}}, h_result::get_messages());
    }
    
    void test_method_(get_name_with_ERROR_FILE_INVALID) {
      assert::are_equal("ERROR_FILE_INVALID", h_result::get_name(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(get_name_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal("MSEE_E_ASSEMBLYLOADINPROGRESS", h_result::get_name(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(get_name_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal("ERROR_UNRECOGNIZED_VOLUME", h_result::get_name(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(get_name_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal("ERROR_LOCK_VIOLATION", h_result::get_name(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(get_name_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal("ERROR_SHARING_VIOLATION", h_result::get_name(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(get_name_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal("ERROR_TOO_MANY_OPEN_FILES", h_result::get_name(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(get_name_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal("FUSION_E_REF_DEF_MISMATCH", h_result::get_name(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(get_name_with_CTL_E_FILENOTFOUND) {
      assert::are_equal("CTL_E_FILENOTFOUND", h_result::get_name(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(get_name_with_RPC_E_CHANGED_MODE) {
      assert::are_equal("RPC_E_CHANGED_MODE", h_result::get_name(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(get_name_with_RO_E_CLOSED) {
      assert::are_equal("RO_E_CLOSED", h_result::get_name(h_result::RO_E_CLOSED));
    }
    
    void test_method_(get_name_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal("ERROR_MRM_MAP_NOT_FOUND", h_result::get_name(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(get_name_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal("COR_E_AMBIGUOUSIMPLEMENTATION", h_result::get_name(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(get_name_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal("COR_E_INDEXOUTOFRANGE", h_result::get_name(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(get_name_with_E_CHANGED_STATE) {
      assert::are_equal("E_CHANGED_STATE", h_result::get_name(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(get_name_with_COR_E_FIELDACCESS) {
      assert::are_equal("COR_E_FIELDACCESS", h_result::get_name(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(get_name_with_E_BOUNDS) {
      assert::are_equal("E_BOUNDS", h_result::get_name(h_result::E_BOUNDS));
    }
    
    void test_method_(get_name_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal("DISP_E_TYPEMISMATCH", h_result::get_name(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(get_name_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal("COR_E_WAITHANDLECANNOTBEOPENED", h_result::get_name(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(get_name_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal("CTL_E_PATHNOTFOUND", h_result::get_name(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_VERIFICATION) {
      assert::are_equal("COR_E_VERIFICATION", h_result::get_name(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(get_name_with_E_POINTER) {
      assert::are_equal("E_POINTER", h_result::get_name(h_result::E_POINTER));
    }
    
    void test_method_(get_name_with_COR_E_THREADSTATE) {
      assert::are_equal("COR_E_THREADSTATE", h_result::get_name(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(get_name_with_COR_E_THREADSTART) {
      assert::are_equal("COR_E_THREADSTART", h_result::get_name(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(get_name_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal("COR_E_ENTRYPOINTNOTFOUND", h_result::get_name(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(get_name_with_CO_E_NOTINITIALIZED) {
      assert::are_equal("CO_E_NOTINITIALIZED", h_result::get_name(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(get_name_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal("COR_E_THREADINTERRUPTED", h_result::get_name(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(get_name_with_COR_E_THREADABORTED) {
      assert::are_equal("COR_E_THREADABORTED", h_result::get_name(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(get_name_with_E_UNEXPECTED) {
      assert::are_equal("E_UNEXPECTED", h_result::get_name(h_result::E_UNEXPECTED));
    }
    
    void test_method_(get_name_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal("COR_E_SYNCHRONIZATIONLOCK", h_result::get_name(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(get_name_with_E_FAIL) {
      assert::are_equal("E_FAIL", h_result::get_name(h_result::E_FAIL));
    }
    
    void test_method_(get_name_with_COR_E_TYPELOAD) {
      assert::are_equal("COR_E_TYPELOAD", h_result::get_name(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(get_name_with_COR_E_STACKOVERFLOW) {
      assert::are_equal("COR_E_STACKOVERFLOW", h_result::get_name(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(get_name_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal("TYPE_E_TYPEMISMATCH", h_result::get_name(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(get_name_with_COR_E_SERIALIZATION) {
      assert::are_equal("COR_E_SERIALIZATION", h_result::get_name(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(get_name_with_COR_E_SECURITY) {
      assert::are_equal("COR_E_SECURITY", h_result::get_name(h_result::COR_E_SECURITY));
    }
    
    void test_method_(get_name_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal("COR_E_SAFEARRAYTYPEMISMATCH", h_result::get_name(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_name_with_E_ABORT) {
      assert::are_equal("E_ABORT", h_result::get_name(h_result::E_ABORT));
    }
    
    void test_method_(get_name_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal("COR_E_SAFEARRAYRANKMISMATCH", h_result::get_name(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(get_name_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal("COR_E_INSUFFICIENTMEMORY", h_result::get_name(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(get_name_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal("COR_E_REFLECTIONTYPELOAD", h_result::get_name(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(get_name_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal("COR_E_PLATFORMNOTSUPPORTED", h_result::get_name(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(get_name_with_COR_E_PATHTOOLONG) {
      assert::are_equal("COR_E_PATHTOOLONG", h_result::get_name(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(get_name_with_COR_E_APPLICATION) {
      assert::are_equal("COR_E_APPLICATION", h_result::get_name(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(get_name_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal("COR_E_OPERATIONCANCELED", h_result::get_name(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(get_name_with_DISP_E_OVERFLOW) {
      assert::are_equal("DISP_E_OVERFLOW", h_result::get_name(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(get_name_with_COR_E_OBJECTCLOSED) {
      assert::are_equal("COR_E_OBJECTCLOSED", h_result::get_name(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(get_name_with_COR_E_NOTSUPPORTED) {
      assert::are_equal("COR_E_NOTSUPPORTED", h_result::get_name(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(get_name_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal("COR_E_NOTFINITENUMBER", h_result::get_name(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(get_name_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal("COR_E_MULTICASTNOTSUPPORTED", h_result::get_name(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(get_name_with_COR_E_MISSINGMETHOD) {
      assert::are_equal("COR_E_MISSINGMETHOD", h_result::get_name(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(get_name_with_COR_E_MISSINGMEMBER) {
      assert::are_equal("COR_E_MISSINGMEMBER", h_result::get_name(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(get_name_with_ERROR_DISK_CORRUPT) {
      assert::are_equal("ERROR_DISK_CORRUPT", h_result::get_name(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(get_name_with_COR_E_OUTOFMEMORY) {
      assert::are_equal("COR_E_OUTOFMEMORY", h_result::get_name(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(get_name_with_COR_E_MISSINGFIELD) {
      assert::are_equal("COR_E_MISSINGFIELD", h_result::get_name(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(get_name_with_ERROR_TIMEOUT) {
      assert::are_equal("ERROR_TIMEOUT", h_result::get_name(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(get_name_with_COR_E_METHODACCESS) {
      assert::are_equal("COR_E_METHODACCESS", h_result::get_name(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(get_name_with_COR_E_ARGUMENT) {
      assert::are_equal("COR_E_ARGUMENT", h_result::get_name(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(get_name_with_COR_E_OVERFLOW) {
      assert::are_equal("COR_E_OVERFLOW", h_result::get_name(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(get_name_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal("COR_E_APPDOMAINUNLOADED", h_result::get_name(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(get_name_with_COR_E_KEYNOTFOUND) {
      assert::are_equal("COR_E_KEYNOTFOUND", h_result::get_name(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal("COR_E_INVALIDPROGRAM", h_result::get_name(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal("COR_E_INVALIDFILTERCRITERIA", h_result::get_name(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(get_name_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal("COR_E_MISSINGSATELLITEASSEMBLY", h_result::get_name(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDCAST) {
      assert::are_equal("COR_E_INVALIDCAST", h_result::get_name(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(get_name_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal("COR_E_UNAUTHORIZEDACCESS", h_result::get_name(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(get_name_with_COR_E_FORMAT) {
      assert::are_equal("COR_E_FORMAT", h_result::get_name(h_result::COR_E_FORMAT));
    }
    
    void test_method_(get_name_with_COR_E_FILELOAD) {
      assert::are_equal("COR_E_FILELOAD", h_result::get_name(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(get_name_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal("COR_E_DIVIDEBYZERO", h_result::get_name(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(get_name_with_COR_E_TYPEUNLOADED) {
      assert::are_equal("COR_E_TYPEUNLOADED", h_result::get_name(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(get_name_with_COR_E_FAILFAST) {
      assert::are_equal("COR_E_FAILFAST", h_result::get_name(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(get_name_with_COR_E_EXCEPTION) {
      assert::are_equal("COR_E_EXCEPTION", h_result::get_name(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(get_name_with_COR_E_DLLNOTFOUND) {
      assert::are_equal("COR_E_DLLNOTFOUND", h_result::get_name(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal("COR_E_EXECUTIONENGINE", h_result::get_name(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(get_name_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal("COR_E_DIRECTORYNOTFOUND", h_result::get_name(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal("COR_E_CONTEXTMARSHAL", h_result::get_name(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(get_name_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal("COR_E_ARGUMENTOUTOFRANGE", h_result::get_name(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(get_name_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal("COR_E_AMBIGUOUSMATCH", h_result::get_name(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(get_name_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal("COR_E_DRIVENOTFOUND", h_result::get_name(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_BADEXEFORMAT) {
      assert::are_equal("COR_E_BADEXEFORMAT", h_result::get_name(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(get_name_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal("COR_E_INSUFFICIENTEXECUTIONSTACK", h_result::get_name(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(get_name_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal("COR_E_CANNOTUNLOADAPPDOMAIN", h_result::get_name(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(get_name_with_COR_E_TARGETINVOCATION) {
      assert::are_equal("COR_E_TARGETINVOCATION", h_result::get_name(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(get_name_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal("COR_E_CODECONTRACTFAILED", h_result::get_name(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(get_name_with_S_OK) {
      assert::are_equal("S_OK", h_result::get_name(h_result::S_OK));
    }
    
    void test_method_(get_name_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal("COR_E_BADIMAGEFORMAT", h_result::get_name(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(get_name_with_COR_E_TYPEACCESS) {
      assert::are_equal("COR_E_TYPEACCESS", h_result::get_name(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(get_name_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal("DISP_E_PARAMNOTFOUND", h_result::get_name(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(get_name_with_FUSION_E_INVALID_NAME) {
      assert::are_equal("FUSION_E_INVALID_NAME", h_result::get_name(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(get_name_with_COR_E_ENDOFSTREAM) {
      assert::are_equal("COR_E_ENDOFSTREAM", h_result::get_name(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(get_name_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal("COR_E_DUPLICATEWAITOBJECT", h_result::get_name(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(get_name_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal("COR_E_RUNTIMEWRAPPED", h_result::get_name(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(get_name_with_COR_E_TARGET) {
      assert::are_equal("COR_E_TARGET", h_result::get_name(h_result::COR_E_TARGET));
    }
    
    void test_method_(get_name_with_COR_E_DATAMISALIGNED) {
      assert::are_equal("COR_E_DATAMISALIGNED", h_result::get_name(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(get_name_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal("COR_E_TYPEINITIALIZATION", h_result::get_name(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(get_name_with_COR_E_ARITHMETIC) {
      assert::are_equal("COR_E_ARITHMETIC", h_result::get_name(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal("COR_E_INVALIDOLEVARIANTTYPE", h_result::get_name(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(get_name_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal("COR_E_MISSINGMANIFESTRESOURCE", h_result::get_name(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(get_name_with_COR_E_TIMEOUT) {
      assert::are_equal("COR_E_TIMEOUT", h_result::get_name(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(get_name_with_COR_E_FILENOTFOUND) {
      assert::are_equal("COR_E_FILENOTFOUND", h_result::get_name(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal("COR_E_TARGETPARAMCOUNT", h_result::get_name(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(get_name_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal("COR_E_ARRAYTYPEMISMATCH", h_result::get_name(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_name_with_E_NOTIMPL) {
      assert::are_equal("E_NOTIMPL", h_result::get_name(h_result::E_NOTIMPL));
    }
    
    void test_method_(get_name_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal("COR_E_MARSHALDIRECTIVE", h_result::get_name(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(get_name_with_DISP_E_BADVARTYPE) {
      assert::are_equal("DISP_E_BADVARTYPE", h_result::get_name(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(get_name_with_COR_E_IO) {
      assert::are_equal("COR_E_IO", h_result::get_name(h_result::COR_E_IO));
    }
    
    void test_method_(get_name_with_ERROR_OPEN_FAILED) {
      assert::are_equal("ERROR_OPEN_FAILED", h_result::get_name(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(get_name_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal("COR_E_ABANDONEDMUTEX", h_result::get_name(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(get_name_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal("ERROR_DLL_INIT_FAILED", h_result::get_name(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(get_name_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal("COR_E_CUSTOMATTRIBUTEFORMAT", h_result::get_name(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(get_name_with_S_FALSE) {
      assert::are_equal("S_FALSE", h_result::get_name(h_result::S_FALSE));
    }
    
    void test_method_(get_name_with_COR_E_MEMBERACCESS) {
      assert::are_equal("COR_E_MEMBERACCESS", h_result::get_name(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(get_name_with_COR_E_RANK) {
      assert::are_equal("COR_E_RANK", h_result::get_name(h_result::COR_E_RANK));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal("COR_E_INVALIDCOMOBJECT", h_result::get_name(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(get_name_with_E_HANDLE) {
      assert::are_equal("E_HANDLE", h_result::get_name(h_result::E_HANDLE));
    }
    
    void test_method_(get_name_with_COR_E_INVALIDOPERATION) {
      assert::are_equal("COR_E_INVALIDOPERATION", h_result::get_name(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(get_name_with_STG_E_PATHNOTFOUND) {
      assert::are_equal("STG_E_PATHNOTFOUND", h_result::get_name(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(get_name_with_COR_E_SYSTEM) {
      assert::are_equal("COR_E_SYSTEM", h_result::get_name(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(get_names) {
      using h_result_name_pair = std::pair<int32, string>;
      assert::are_equal(117_z, h_result::get_names().size());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_FILE_INVALID, "ERROR_FILE_INVALID"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::MSEE_E_ASSEMBLYLOADINPROGRESS, "MSEE_E_ASSEMBLYLOADINPROGRESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_UNRECOGNIZED_VOLUME, "ERROR_UNRECOGNIZED_VOLUME"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_LOCK_VIOLATION, "ERROR_LOCK_VIOLATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_SHARING_VIOLATION, "ERROR_SHARING_VIOLATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_TOO_MANY_OPEN_FILES, "ERROR_TOO_MANY_OPEN_FILES"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::FUSION_E_REF_DEF_MISMATCH, "FUSION_E_REF_DEF_MISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::CTL_E_FILENOTFOUND, "CTL_E_FILENOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::RPC_E_CHANGED_MODE, "RPC_E_CHANGED_MODE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::RO_E_CLOSED, "RO_E_CLOSED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_MRM_MAP_NOT_FOUND, "ERROR_MRM_MAP_NOT_FOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_AMBIGUOUSIMPLEMENTATION, "COR_E_AMBIGUOUSIMPLEMENTATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INDEXOUTOFRANGE, "COR_E_INDEXOUTOFRANGE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_CHANGED_STATE, "E_CHANGED_STATE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_FIELDACCESS, "COR_E_FIELDACCESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_BOUNDS, "E_BOUNDS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::DISP_E_TYPEMISMATCH, "DISP_E_TYPEMISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_WAITHANDLECANNOTBEOPENED, "COR_E_WAITHANDLECANNOTBEOPENED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::CTL_E_PATHNOTFOUND, "CTL_E_PATHNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_VERIFICATION, "COR_E_VERIFICATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_POINTER, "E_POINTER"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_THREADSTATE, "COR_E_THREADSTATE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_THREADSTART, "COR_E_THREADSTART"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ENTRYPOINTNOTFOUND, "COR_E_ENTRYPOINTNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::CO_E_NOTINITIALIZED, "CO_E_NOTINITIALIZED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_THREADINTERRUPTED, "COR_E_THREADINTERRUPTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_THREADABORTED, "COR_E_THREADABORTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_UNEXPECTED, "E_UNEXPECTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SYNCHRONIZATIONLOCK, "COR_E_SYNCHRONIZATIONLOCK"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_FAIL, "E_FAIL"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TYPELOAD, "COR_E_TYPELOAD"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_STACKOVERFLOW, "COR_E_STACKOVERFLOW"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::TYPE_E_TYPEMISMATCH, "TYPE_E_TYPEMISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SERIALIZATION, "COR_E_SERIALIZATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SECURITY, "COR_E_SECURITY"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SAFEARRAYTYPEMISMATCH, "COR_E_SAFEARRAYTYPEMISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_ABORT, "E_ABORT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SAFEARRAYRANKMISMATCH, "COR_E_SAFEARRAYRANKMISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INSUFFICIENTMEMORY, "COR_E_INSUFFICIENTMEMORY"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_REFLECTIONTYPELOAD, "COR_E_REFLECTIONTYPELOAD"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_PLATFORMNOTSUPPORTED, "COR_E_PLATFORMNOTSUPPORTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_PATHTOOLONG, "COR_E_PATHTOOLONG"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_APPLICATION, "COR_E_APPLICATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_OPERATIONCANCELED, "COR_E_OPERATIONCANCELED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::DISP_E_OVERFLOW, "DISP_E_OVERFLOW"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_OBJECTCLOSED, "COR_E_OBJECTCLOSED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_NOTSUPPORTED, "COR_E_NOTSUPPORTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_NOTFINITENUMBER, "COR_E_NOTFINITENUMBER"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MULTICASTNOTSUPPORTED, "COR_E_MULTICASTNOTSUPPORTED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MISSINGMETHOD, "COR_E_MISSINGMETHOD"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MISSINGMEMBER, "COR_E_MISSINGMEMBER"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_DISK_CORRUPT, "ERROR_DISK_CORRUPT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_OUTOFMEMORY, "COR_E_OUTOFMEMORY"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MISSINGFIELD, "COR_E_MISSINGFIELD"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_TIMEOUT, "ERROR_TIMEOUT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_METHODACCESS, "COR_E_METHODACCESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ARGUMENT, "COR_E_ARGUMENT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_OVERFLOW, "COR_E_OVERFLOW"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_APPDOMAINUNLOADED, "COR_E_APPDOMAINUNLOADED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_KEYNOTFOUND, "COR_E_KEYNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDPROGRAM, "COR_E_INVALIDPROGRAM"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDFILTERCRITERIA, "COR_E_INVALIDFILTERCRITERIA"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MISSINGSATELLITEASSEMBLY, "COR_E_MISSINGSATELLITEASSEMBLY"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDCAST, "COR_E_INVALIDCAST"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_UNAUTHORIZEDACCESS, "COR_E_UNAUTHORIZEDACCESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_FORMAT, "COR_E_FORMAT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_FILELOAD, "COR_E_FILELOAD"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DIVIDEBYZERO, "COR_E_DIVIDEBYZERO"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TYPEUNLOADED, "COR_E_TYPEUNLOADED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_FAILFAST, "COR_E_FAILFAST"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_EXCEPTION, "COR_E_EXCEPTION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DLLNOTFOUND, "COR_E_DLLNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_EXECUTIONENGINE, "COR_E_EXECUTIONENGINE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DIRECTORYNOTFOUND, "COR_E_DIRECTORYNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_CONTEXTMARSHAL, "COR_E_CONTEXTMARSHAL"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ARGUMENTOUTOFRANGE, "COR_E_ARGUMENTOUTOFRANGE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_AMBIGUOUSMATCH, "COR_E_AMBIGUOUSMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DRIVENOTFOUND, "COR_E_DRIVENOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_BADEXEFORMAT, "COR_E_BADEXEFORMAT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INSUFFICIENTEXECUTIONSTACK, "COR_E_INSUFFICIENTEXECUTIONSTACK"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_CANNOTUNLOADAPPDOMAIN, "COR_E_CANNOTUNLOADAPPDOMAIN"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TARGETINVOCATION, "COR_E_TARGETINVOCATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_CODECONTRACTFAILED, "COR_E_CODECONTRACTFAILED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::S_OK, "S_OK"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_BADIMAGEFORMAT, "COR_E_BADIMAGEFORMAT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TYPEACCESS, "COR_E_TYPEACCESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::DISP_E_PARAMNOTFOUND, "DISP_E_PARAMNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::FUSION_E_INVALID_NAME, "FUSION_E_INVALID_NAME"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ENDOFSTREAM, "COR_E_ENDOFSTREAM"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DUPLICATEWAITOBJECT, "COR_E_DUPLICATEWAITOBJECT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_RUNTIMEWRAPPED, "COR_E_RUNTIMEWRAPPED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TARGET, "COR_E_TARGET"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_DATAMISALIGNED, "COR_E_DATAMISALIGNED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TYPEINITIALIZATION, "COR_E_TYPEINITIALIZATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ARITHMETIC, "COR_E_ARITHMETIC"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDOLEVARIANTTYPE, "COR_E_INVALIDOLEVARIANTTYPE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MISSINGMANIFESTRESOURCE, "COR_E_MISSINGMANIFESTRESOURCE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TIMEOUT, "COR_E_TIMEOUT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_FILENOTFOUND, "COR_E_FILENOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_TARGETPARAMCOUNT, "COR_E_TARGETPARAMCOUNT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ARRAYTYPEMISMATCH, "COR_E_ARRAYTYPEMISMATCH"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_NOTIMPL, "E_NOTIMPL"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MARSHALDIRECTIVE, "COR_E_MARSHALDIRECTIVE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::DISP_E_BADVARTYPE, "DISP_E_BADVARTYPE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_IO, "COR_E_IO"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_OPEN_FAILED, "ERROR_OPEN_FAILED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_ABANDONEDMUTEX, "COR_E_ABANDONEDMUTEX"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::ERROR_DLL_INIT_FAILED, "ERROR_DLL_INIT_FAILED"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_CUSTOMATTRIBUTEFORMAT, "COR_E_CUSTOMATTRIBUTEFORMAT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::S_FALSE, "S_FALSE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_MEMBERACCESS, "COR_E_MEMBERACCESS"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_RANK, "COR_E_RANK"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDCOMOBJECT, "COR_E_INVALIDCOMOBJECT"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::E_HANDLE, "E_HANDLE"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_INVALIDOPERATION, "COR_E_INVALIDOPERATION"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::STG_E_PATHNOTFOUND, "STG_E_PATHNOTFOUND"}}, h_result::get_names());
      collection_assert::contains({h_result_name_pair {h_result::COR_E_SYSTEM, "COR_E_SYSTEM"}}, h_result::get_names());
    }
    
    void test_method_(get_severity_with_ERROR_FILE_INVALID) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(get_severity_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(1, h_result::get_severity(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(get_severity_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(get_severity_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(get_severity_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(get_severity_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(get_severity_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(get_severity_with_CTL_E_FILENOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(get_severity_with_RPC_E_CHANGED_MODE) {
      assert::are_equal(1, h_result::get_severity(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(get_severity_with_RO_E_CLOSED) {
      assert::are_equal(1, h_result::get_severity(h_result::RO_E_CLOSED));
    }
    
    void test_method_(get_severity_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(get_severity_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(get_severity_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(get_severity_with_E_CHANGED_STATE) {
      assert::are_equal(1, h_result::get_severity(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(get_severity_with_COR_E_FIELDACCESS) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(get_severity_with_E_BOUNDS) {
      assert::are_equal(1, h_result::get_severity(h_result::E_BOUNDS));
    }
    
    void test_method_(get_severity_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(get_severity_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(get_severity_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_VERIFICATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(get_severity_with_E_POINTER) {
      assert::are_equal(1, h_result::get_severity(h_result::E_POINTER));
    }
    
    void test_method_(get_severity_with_COR_E_THREADSTATE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(get_severity_with_COR_E_THREADSTART) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(get_severity_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(get_severity_with_CO_E_NOTINITIALIZED) {
      assert::are_equal(1, h_result::get_severity(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(get_severity_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(get_severity_with_COR_E_THREADABORTED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(get_severity_with_E_UNEXPECTED) {
      assert::are_equal(1, h_result::get_severity(h_result::E_UNEXPECTED));
    }
    
    void test_method_(get_severity_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(get_severity_with_E_FAIL) {
      assert::are_equal(1, h_result::get_severity(h_result::E_FAIL));
    }
    
    void test_method_(get_severity_with_COR_E_TYPELOAD) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(get_severity_with_COR_E_STACKOVERFLOW) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(get_severity_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(get_severity_with_COR_E_SERIALIZATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(get_severity_with_COR_E_SECURITY) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SECURITY));
    }
    
    void test_method_(get_severity_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_severity_with_E_ABORT) {
      assert::are_equal(1, h_result::get_severity(h_result::E_ABORT));
    }
    
    void test_method_(get_severity_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(get_severity_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(get_severity_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(get_severity_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(get_severity_with_COR_E_PATHTOOLONG) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(get_severity_with_COR_E_APPLICATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(get_severity_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(get_severity_with_DISP_E_OVERFLOW) {
      assert::are_equal(1, h_result::get_severity(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(get_severity_with_COR_E_OBJECTCLOSED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(get_severity_with_COR_E_NOTSUPPORTED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(get_severity_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(get_severity_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(get_severity_with_COR_E_MISSINGMETHOD) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(get_severity_with_COR_E_MISSINGMEMBER) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(get_severity_with_ERROR_DISK_CORRUPT) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(get_severity_with_COR_E_OUTOFMEMORY) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(get_severity_with_COR_E_MISSINGFIELD) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(get_severity_with_ERROR_TIMEOUT) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(get_severity_with_COR_E_METHODACCESS) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(get_severity_with_COR_E_ARGUMENT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(get_severity_with_COR_E_OVERFLOW) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(get_severity_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(get_severity_with_COR_E_KEYNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(get_severity_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDCAST) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(get_severity_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(get_severity_with_COR_E_FORMAT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_FORMAT));
    }
    
    void test_method_(get_severity_with_COR_E_FILELOAD) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(get_severity_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(get_severity_with_COR_E_TYPEUNLOADED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(get_severity_with_COR_E_FAILFAST) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(get_severity_with_COR_E_EXCEPTION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(get_severity_with_COR_E_DLLNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(get_severity_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(get_severity_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(get_severity_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(get_severity_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_BADEXEFORMAT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(get_severity_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(get_severity_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(get_severity_with_COR_E_TARGETINVOCATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(get_severity_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(get_severity_with_S_OK) {
      assert::is_zero(h_result::get_severity(h_result::S_OK));
    }
    
    void test_method_(get_severity_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(get_severity_with_COR_E_TYPEACCESS) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(get_severity_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(get_severity_with_FUSION_E_INVALID_NAME) {
      assert::are_equal(1, h_result::get_severity(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(get_severity_with_COR_E_ENDOFSTREAM) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(get_severity_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(get_severity_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(get_severity_with_COR_E_TARGET) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TARGET));
    }
    
    void test_method_(get_severity_with_COR_E_DATAMISALIGNED) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(get_severity_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(get_severity_with_COR_E_ARITHMETIC) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(get_severity_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(get_severity_with_COR_E_TIMEOUT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(get_severity_with_COR_E_FILENOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(get_severity_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(get_severity_with_E_NOTIMPL) {
      assert::are_equal(1, h_result::get_severity(h_result::E_NOTIMPL));
    }
    
    void test_method_(get_severity_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(get_severity_with_DISP_E_BADVARTYPE) {
      assert::are_equal(1, h_result::get_severity(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(get_severity_with_COR_E_IO) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_IO));
    }
    
    void test_method_(get_severity_with_ERROR_OPEN_FAILED) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(get_severity_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(get_severity_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal(1, h_result::get_severity(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(get_severity_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(get_severity_with_S_FALSE) {
      assert::is_zero(h_result::get_severity(h_result::S_FALSE));
    }
    
    void test_method_(get_severity_with_COR_E_MEMBERACCESS) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(get_severity_with_COR_E_RANK) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_RANK));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(get_severity_with_E_HANDLE) {
      assert::are_equal(1, h_result::get_severity(h_result::E_HANDLE));
    }
    
    void test_method_(get_severity_with_COR_E_INVALIDOPERATION) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(get_severity_with_STG_E_PATHNOTFOUND) {
      assert::are_equal(1, h_result::get_severity(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(get_severity_with_COR_E_SYSTEM) {
      assert::are_equal(1, h_result::get_severity(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(h_result_category) {
      assert::are_equal("h_result_category", h_result::h_result_category().name());
      assert::are_equal("File invalid.", xtd::h_result::h_result_category().message(h_result::ERROR_FILE_INVALID));
      assert::are_equal("Assembly load in progress.", xtd::h_result::h_result_category().message(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
      assert::are_equal("Unrecognized volume.", xtd::h_result::h_result_category().message(h_result::ERROR_UNRECOGNIZED_VOLUME));
      assert::are_equal("Lock violations.", xtd::h_result::h_result_category().message(h_result::ERROR_LOCK_VIOLATION));
      assert::are_equal("Sharing violation.", xtd::h_result::h_result_category().message(h_result::ERROR_SHARING_VIOLATION));
      assert::are_equal("Too many open files.", xtd::h_result::h_result_category().message(h_result::ERROR_TOO_MANY_OPEN_FILES));
      assert::are_equal("Fusion the reference definition is incompatible.", xtd::h_result::h_result_category().message(h_result::FUSION_E_REF_DEF_MISMATCH));
      assert::are_equal("Unable to find the specified file.", xtd::h_result::h_result_category().message(h_result::CTL_E_FILENOTFOUND));
      assert::are_equal("Cannot change the current thread mode.", xtd::h_result::h_result_category().message(h_result::RPC_E_CHANGED_MODE));
      assert::are_equal("The object has been closed.", xtd::h_result::h_result_category().message(h_result::RO_E_CLOSED));
      assert::are_equal("Resource map not found.", xtd::h_result::h_result_category().message(h_result::ERROR_MRM_MAP_NOT_FOUND));
      assert::are_equal("Ambiguous implementation found.", xtd::h_result::h_result_category().message(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
      assert::are_equal("Index was outside the bounds of the array.", xtd::h_result::h_result_category().message(h_result::COR_E_INDEXOUTOFRANGE));
      assert::are_equal("The state has been modified.", xtd::h_result::h_result_category().message(h_result::E_CHANGED_STATE));
      assert::are_equal("Attempted to access a field that is not accessible by the caller.", xtd::h_result::h_result_category().message(h_result::COR_E_FIELDACCESS));
      assert::are_equal("Bounds exception", xtd::h_result::h_result_category().message(h_result::E_BOUNDS));
      assert::are_equal("Attempt to access a variable with an incompatible type.", xtd::h_result::h_result_category().message(h_result::DISP_E_TYPEMISMATCH));
      assert::are_equal("No handle of the given name exists.", xtd::h_result::h_result_category().message(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
      assert::are_equal("Attempted to access a path that is not on the disk.", xtd::h_result::h_result_category().message(h_result::CTL_E_PATHNOTFOUND));
      assert::are_equal("Operation could destabilize the runtime.", xtd::h_result::h_result_category().message(h_result::COR_E_VERIFICATION));
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", xtd::h_result::h_result_category().message(h_result::E_POINTER));
      assert::are_equal("Thread was in an invalid state for the operation being executed.", xtd::h_result::h_result_category().message(h_result::COR_E_THREADSTATE));
      assert::are_equal("Thread start failure.", xtd::h_result::h_result_category().message(h_result::COR_E_THREADSTART));
      assert::are_equal("Entry point was not found.", xtd::h_result::h_result_category().message(h_result::COR_E_ENTRYPOINTNOTFOUND));
      assert::are_equal("Not initialized", xtd::h_result::h_result_category().message(h_result::CO_E_NOTINITIALIZED));
      assert::are_equal("Thread was interrupted from a waiting state.", xtd::h_result::h_result_category().message(h_result::COR_E_THREADINTERRUPTED));
      assert::are_equal("Thread was aborted.", xtd::h_result::h_result_category().message(h_result::COR_E_THREADABORTED));
      assert::are_equal("Unexpected failure.", xtd::h_result::h_result_category().message(h_result::E_UNEXPECTED));
      assert::are_equal("Object synchronization method was called from an unsynchronized block of code.", xtd::h_result::h_result_category().message(h_result::COR_E_SYNCHRONIZATIONLOCK));
      assert::are_equal("Unspecified failure.", xtd::h_result::h_result_category().message(h_result::E_FAIL));
      assert::are_equal("Failure has occurred while loading a type.", xtd::h_result::h_result_category().message(h_result::COR_E_TYPELOAD));
      assert::are_equal("Operation caused a stack overflow.", xtd::h_result::h_result_category().message(h_result::COR_E_STACKOVERFLOW));
      assert::are_equal("Incompatible type.", xtd::h_result::h_result_category().message(h_result::TYPE_E_TYPEMISMATCH));
      assert::are_equal("Serialization error.", xtd::h_result::h_result_category().message(h_result::COR_E_SERIALIZATION));
      assert::are_equal("Security error.", xtd::h_result::h_result_category().message(h_result::COR_E_SECURITY));
      assert::are_equal("Specified array was not of the expected type.", xtd::h_result::h_result_category().message(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
      assert::are_equal("Operation aborted.", xtd::h_result::h_result_category().message(h_result::E_ABORT));
      assert::are_equal("Specified array was not of the expected rank.", xtd::h_result::h_result_category().message(h_result::COR_E_SAFEARRAYRANKMISMATCH));
      assert::are_equal("Insufficient memory to continue the execution of the program.", xtd::h_result::h_result_category().message(h_result::COR_E_INSUFFICIENTMEMORY));
      assert::are_equal("Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown.", xtd::h_result::h_result_category().message(h_result::COR_E_REFLECTIONTYPELOAD));
      assert::are_equal("Operation is not supported on this platform.", xtd::h_result::h_result_category().message(h_result::COR_E_PLATFORMNOTSUPPORTED));
      assert::are_equal("The specified file name or path is too long, or a component of the specified path is too long.", xtd::h_result::h_result_category().message(h_result::COR_E_PATHTOOLONG));
      assert::are_equal("Error in the application.", xtd::h_result::h_result_category().message(h_result::COR_E_APPLICATION));
      assert::are_equal("The operation was canceled.", xtd::h_result::h_result_category().message(h_result::COR_E_OPERATIONCANCELED));
      assert::are_equal("Arithmetic operation resulted in an overflow.", xtd::h_result::h_result_category().message(h_result::DISP_E_OVERFLOW));
      assert::are_equal("Cannot access a closed object.", xtd::h_result::h_result_category().message(h_result::COR_E_OBJECTCLOSED));
      assert::are_equal("Specified method is not supported.", xtd::h_result::h_result_category().message(h_result::COR_E_NOTSUPPORTED));
      assert::are_equal("Number encountered was not a finite quantity.", xtd::h_result::h_result_category().message(h_result::COR_E_NOTFINITENUMBER));
      assert::are_equal("Attempted to add multiple callbacks to a delegate that does not support multicast.", xtd::h_result::h_result_category().message(h_result::COR_E_MULTICASTNOTSUPPORTED));
      assert::are_equal("Attempted to access a missing method.", xtd::h_result::h_result_category().message(h_result::COR_E_MISSINGMETHOD));
      assert::are_equal("Attempted to access a missing member.", xtd::h_result::h_result_category().message(h_result::COR_E_MISSINGMEMBER));
      assert::are_equal("Disk corrupt.", xtd::h_result::h_result_category().message(h_result::ERROR_DISK_CORRUPT));
      assert::are_equal("Insufficient memory to continue the execution of the program.", xtd::h_result::h_result_category().message(h_result::COR_E_OUTOFMEMORY));
      assert::are_equal("Attempted to access a non-existing field.", xtd::h_result::h_result_category().message(h_result::COR_E_MISSINGFIELD));
      assert::are_equal("The operation has timed out.", xtd::h_result::h_result_category().message(h_result::ERROR_TIMEOUT));
      assert::are_equal("Attempt to access the method failed.", xtd::h_result::h_result_category().message(h_result::COR_E_METHODACCESS));
      assert::are_equal("Value does not fall within the expected range.", xtd::h_result::h_result_category().message(h_result::COR_E_ARGUMENT));
      assert::are_equal("Arithmetic operation resulted in an overflow.", xtd::h_result::h_result_category().message(h_result::COR_E_OVERFLOW));
      assert::are_equal("Attempted to access an unloaded AppDomain.", xtd::h_result::h_result_category().message(h_result::COR_E_APPDOMAINUNLOADED));
      assert::are_equal("The given key was not present in the dictionary.", xtd::h_result::h_result_category().message(h_result::COR_E_KEYNOTFOUND));
      assert::are_equal("xtd detected an invalid program.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDPROGRAM));
      assert::are_equal("Specified filter criteria was invalid.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDFILTERCRITERIA));
      assert::are_equal("Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application.", xtd::h_result::h_result_category().message(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
      assert::are_equal("Specified cast is not valid.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDCAST));
      assert::are_equal("Attempted to perform an unauthorized operation.", xtd::h_result::h_result_category().message(h_result::COR_E_UNAUTHORIZEDACCESS));
      assert::are_equal("One of the identified items was in an invalid format.", xtd::h_result::h_result_category().message(h_result::COR_E_FORMAT));
      assert::are_equal("Could not load the specified file.", xtd::h_result::h_result_category().message(h_result::COR_E_FILELOAD));
      assert::are_equal("Attempted to divide by zero.", xtd::h_result::h_result_category().message(h_result::COR_E_DIVIDEBYZERO));
      assert::are_equal("Type had been unloaded.", xtd::h_result::h_result_category().message(h_result::COR_E_TYPEUNLOADED));
      assert::are_equal("Fail fast.", xtd::h_result::h_result_category().message(h_result::COR_E_FAILFAST));
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", xtd::h_result::h_result_category().message(h_result::COR_E_EXCEPTION));
      assert::are_equal("Dll was not found.", xtd::h_result::h_result_category().message(h_result::COR_E_DLLNOTFOUND));
      assert::are_equal("Internal error in the runtime.", xtd::h_result::h_result_category().message(h_result::COR_E_EXECUTIONENGINE));
      assert::are_equal("Attempted to access a path that is not on the disk.", xtd::h_result::h_result_category().message(h_result::COR_E_DIRECTORYNOTFOUND));
      assert::are_equal("Attempted to marshal an object across a context boundary.", xtd::h_result::h_result_category().message(h_result::COR_E_CONTEXTMARSHAL));
      assert::are_equal("Specified argument was out of the range of valid values.", xtd::h_result::h_result_category().message(h_result::COR_E_ARGUMENTOUTOFRANGE));
      assert::are_equal("Ambiguous match found.", xtd::h_result::h_result_category().message(h_result::COR_E_AMBIGUOUSMATCH));
      assert::are_equal("Could not find the drive. The drive might not be ready or might not be mapped.", xtd::h_result::h_result_category().message(h_result::COR_E_DRIVENOTFOUND));
      assert::are_equal("Format of the executable (.exe) cannot be run.", xtd::h_result::h_result_category().message(h_result::COR_E_BADEXEFORMAT));
      assert::are_equal("Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space.", xtd::h_result::h_result_category().message(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
      assert::are_equal("Attempt to unload the AppDomain failed.", xtd::h_result::h_result_category().message(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
      assert::are_equal("Exception has been thrown by the target of an invocation.", xtd::h_result::h_result_category().message(h_result::COR_E_TARGETINVOCATION));
      assert::are_equal("A code contract (ie, precondition, postcondition, invariant, or assert) failed.", xtd::h_result::h_result_category().message(h_result::COR_E_CODECONTRACTFAILED));
      assert::are_equal("Operation successful.", xtd::h_result::h_result_category().message(h_result::S_OK));
      assert::are_equal("Format of the executable (.exe) or library (.dll) is invalid.", xtd::h_result::h_result_category().message(h_result::COR_E_BADIMAGEFORMAT));
      assert::are_equal("Attempt to access the type failed.", xtd::h_result::h_result_category().message(h_result::COR_E_TYPEACCESS));
      assert::are_equal("Could not find the parameter.", xtd::h_result::h_result_category().message(h_result::DISP_E_PARAMNOTFOUND));
      assert::are_equal("Fusion invalid name exception.", xtd::h_result::h_result_category().message(h_result::FUSION_E_INVALID_NAME));
      assert::are_equal("Attempted to read past the end of the stream.", xtd::h_result::h_result_category().message(h_result::COR_E_ENDOFSTREAM));
      assert::are_equal("Duplicate objects in argument.", xtd::h_result::h_result_category().message(h_result::COR_E_DUPLICATEWAITOBJECT));
      assert::are_equal("An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception.", xtd::h_result::h_result_category().message(h_result::COR_E_RUNTIMEWRAPPED));
      assert::are_equal("Exception of type 'xtd::reflection::target_exception' was thrown.", xtd::h_result::h_result_category().message(h_result::COR_E_TARGET));
      assert::are_equal("A datatype misalignment was detected in a load or store instruction.", xtd::h_result::h_result_category().message(h_result::COR_E_DATAMISALIGNED));
      assert::are_equal("The type initializer for 'value' threw an exception.", xtd::h_result::h_result_category().message(h_result::COR_E_TYPEINITIALIZATION));
      assert::are_equal("Overflow or underflow in the arithmetic operation.", xtd::h_result::h_result_category().message(h_result::COR_E_ARITHMETIC));
      assert::are_equal("Specified OLE variant was invalid.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDOLEVARIANTTYPE));
      assert::are_equal("Attempted to access a missing manifest resource.", xtd::h_result::h_result_category().message(h_result::COR_E_MISSINGMANIFESTRESOURCE));
      assert::are_equal("The operation has timed out.", xtd::h_result::h_result_category().message(h_result::COR_E_TIMEOUT));
      assert::are_equal("Unable to find the specified file.", xtd::h_result::h_result_category().message(h_result::COR_E_FILENOTFOUND));
      assert::are_equal("Number of parameters specified does not match the expected number.", xtd::h_result::h_result_category().message(h_result::COR_E_TARGETPARAMCOUNT));
      assert::are_equal("Attempted to access an element as a type incompatible with the array.", xtd::h_result::h_result_category().message(h_result::COR_E_ARRAYTYPEMISMATCH));
      assert::are_equal("The method or operation is not implemented.", xtd::h_result::h_result_category().message(h_result::E_NOTIMPL));
      assert::are_equal("Marshaling directives are invalid.", xtd::h_result::h_result_category().message(h_result::COR_E_MARSHALDIRECTIVE));
      assert::are_equal("Invalid variable type.", xtd::h_result::h_result_category().message(h_result::DISP_E_BADVARTYPE));
      assert::are_equal("I/O error occurred.", xtd::h_result::h_result_category().message(h_result::COR_E_IO));
      assert::are_equal("Open failed.", xtd::h_result::h_result_category().message(h_result::ERROR_OPEN_FAILED));
      assert::are_equal("The wait completed due to an abandoned mutex.", xtd::h_result::h_result_category().message(h_result::COR_E_ABANDONEDMUTEX));
      assert::are_equal("DLL init failed.", xtd::h_result::h_result_category().message(h_result::ERROR_DLL_INIT_FAILED));
      assert::are_equal("Binary format of the specified custom attribute was invalid.", xtd::h_result::h_result_category().message(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
      assert::are_equal("Operation successful but returned no results.", xtd::h_result::h_result_category().message(h_result::S_FALSE));
      assert::are_equal("Cannot access member.", xtd::h_result::h_result_category().message(h_result::COR_E_MEMBERACCESS));
      assert::are_equal("Attempted to operate on an array with the incorrect number of dimensions.", xtd::h_result::h_result_category().message(h_result::COR_E_RANK));
      assert::are_equal("Attempt has been made to use a COM object that does not have a backing class factory.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDCOMOBJECT));
      assert::are_equal("The handle is invalid.", xtd::h_result::h_result_category().message(h_result::E_HANDLE));
      assert::are_equal("Operation is not valid due to the current state of the object.", xtd::h_result::h_result_category().message(h_result::COR_E_INVALIDOPERATION));
      assert::are_equal("Attempted to access a path that is not on the disk.", xtd::h_result::h_result_category().message(h_result::STG_E_PATHNOTFOUND));
      assert::are_equal("System error.", xtd::h_result::h_result_category().message(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(is_error_with_ERROR_FILE_INVALID) {
      assert::is_true(h_result::is_error(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(is_error_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::is_true(h_result::is_error(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(is_error_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::is_true(h_result::is_error(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(is_error_with_ERROR_LOCK_VIOLATION) {
      assert::is_true(h_result::is_error(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(is_error_with_ERROR_SHARING_VIOLATION) {
      assert::is_true(h_result::is_error(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(is_error_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::is_true(h_result::is_error(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(is_error_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::is_true(h_result::is_error(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(is_error_with_CTL_E_FILENOTFOUND) {
      assert::is_true(h_result::is_error(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(is_error_with_RPC_E_CHANGED_MODE) {
      assert::is_true(h_result::is_error(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(is_error_with_RO_E_CLOSED) {
      assert::is_true(h_result::is_error(h_result::RO_E_CLOSED));
    }
    
    void test_method_(is_error_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::is_true(h_result::is_error(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(is_error_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(is_error_with_COR_E_INDEXOUTOFRANGE) {
      assert::is_true(h_result::is_error(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(is_error_with_E_CHANGED_STATE) {
      assert::is_true(h_result::is_error(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(is_error_with_COR_E_FIELDACCESS) {
      assert::is_true(h_result::is_error(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(is_error_with_E_BOUNDS) {
      assert::is_true(h_result::is_error(h_result::E_BOUNDS));
    }
    
    void test_method_(is_error_with_DISP_E_TYPEMISMATCH) {
      assert::is_true(h_result::is_error(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(is_error_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::is_true(h_result::is_error(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(is_error_with_CTL_E_PATHNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_VERIFICATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(is_error_with_E_POINTER) {
      assert::is_true(h_result::is_error(h_result::E_POINTER));
    }
    
    void test_method_(is_error_with_COR_E_THREADSTATE) {
      assert::is_true(h_result::is_error(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(is_error_with_COR_E_THREADSTART) {
      assert::is_true(h_result::is_error(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(is_error_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(is_error_with_CO_E_NOTINITIALIZED) {
      assert::is_true(h_result::is_error(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(is_error_with_COR_E_THREADINTERRUPTED) {
      assert::is_true(h_result::is_error(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(is_error_with_COR_E_THREADABORTED) {
      assert::is_true(h_result::is_error(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(is_error_with_E_UNEXPECTED) {
      assert::is_true(h_result::is_error(h_result::E_UNEXPECTED));
    }
    
    void test_method_(is_error_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::is_true(h_result::is_error(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(is_error_with_E_FAIL) {
      assert::is_true(h_result::is_error(h_result::E_FAIL));
    }
    
    void test_method_(is_error_with_COR_E_TYPELOAD) {
      assert::is_true(h_result::is_error(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(is_error_with_COR_E_STACKOVERFLOW) {
      assert::is_true(h_result::is_error(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(is_error_with_TYPE_E_TYPEMISMATCH) {
      assert::is_true(h_result::is_error(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(is_error_with_COR_E_SERIALIZATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(is_error_with_COR_E_SECURITY) {
      assert::is_true(h_result::is_error(h_result::COR_E_SECURITY));
    }
    
    void test_method_(is_error_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::is_true(h_result::is_error(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(is_error_with_E_ABORT) {
      assert::is_true(h_result::is_error(h_result::E_ABORT));
    }
    
    void test_method_(is_error_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::is_true(h_result::is_error(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(is_error_with_COR_E_INSUFFICIENTMEMORY) {
      assert::is_true(h_result::is_error(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(is_error_with_COR_E_REFLECTIONTYPELOAD) {
      assert::is_true(h_result::is_error(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(is_error_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::is_true(h_result::is_error(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(is_error_with_COR_E_PATHTOOLONG) {
      assert::is_true(h_result::is_error(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(is_error_with_COR_E_APPLICATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(is_error_with_COR_E_OPERATIONCANCELED) {
      assert::is_true(h_result::is_error(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(is_error_with_DISP_E_OVERFLOW) {
      assert::is_true(h_result::is_error(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(is_error_with_COR_E_OBJECTCLOSED) {
      assert::is_true(h_result::is_error(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(is_error_with_COR_E_NOTSUPPORTED) {
      assert::is_true(h_result::is_error(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(is_error_with_COR_E_NOTFINITENUMBER) {
      assert::is_true(h_result::is_error(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(is_error_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::is_true(h_result::is_error(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(is_error_with_COR_E_MISSINGMETHOD) {
      assert::is_true(h_result::is_error(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(is_error_with_COR_E_MISSINGMEMBER) {
      assert::is_true(h_result::is_error(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(is_error_with_ERROR_DISK_CORRUPT) {
      assert::is_true(h_result::is_error(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(is_error_with_COR_E_OUTOFMEMORY) {
      assert::is_true(h_result::is_error(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(is_error_with_COR_E_MISSINGFIELD) {
      assert::is_true(h_result::is_error(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(is_error_with_ERROR_TIMEOUT) {
      assert::is_true(h_result::is_error(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(is_error_with_COR_E_METHODACCESS) {
      assert::is_true(h_result::is_error(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(is_error_with_COR_E_ARGUMENT) {
      assert::is_true(h_result::is_error(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(is_error_with_COR_E_OVERFLOW) {
      assert::is_true(h_result::is_error(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(is_error_with_COR_E_APPDOMAINUNLOADED) {
      assert::is_true(h_result::is_error(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(is_error_with_COR_E_KEYNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDPROGRAM) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(is_error_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::is_true(h_result::is_error(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDCAST) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(is_error_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::is_true(h_result::is_error(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(is_error_with_COR_E_FORMAT) {
      assert::is_true(h_result::is_error(h_result::COR_E_FORMAT));
    }
    
    void test_method_(is_error_with_COR_E_FILELOAD) {
      assert::is_true(h_result::is_error(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(is_error_with_COR_E_DIVIDEBYZERO) {
      assert::is_true(h_result::is_error(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(is_error_with_COR_E_TYPEUNLOADED) {
      assert::is_true(h_result::is_error(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(is_error_with_COR_E_FAILFAST) {
      assert::is_true(h_result::is_error(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(is_error_with_COR_E_EXCEPTION) {
      assert::is_true(h_result::is_error(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(is_error_with_COR_E_DLLNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_EXECUTIONENGINE) {
      assert::is_true(h_result::is_error(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(is_error_with_COR_E_DIRECTORYNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_CONTEXTMARSHAL) {
      assert::is_true(h_result::is_error(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(is_error_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::is_true(h_result::is_error(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(is_error_with_COR_E_AMBIGUOUSMATCH) {
      assert::is_true(h_result::is_error(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(is_error_with_COR_E_DRIVENOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_BADEXEFORMAT) {
      assert::is_true(h_result::is_error(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(is_error_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::is_true(h_result::is_error(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(is_error_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::is_true(h_result::is_error(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(is_error_with_COR_E_TARGETINVOCATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(is_error_with_COR_E_CODECONTRACTFAILED) {
      assert::is_true(h_result::is_error(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(is_error_with_S_OK) {
      assert::is_false(h_result::is_error(h_result::S_OK));
    }
    
    void test_method_(is_error_with_COR_E_BADIMAGEFORMAT) {
      assert::is_true(h_result::is_error(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(is_error_with_COR_E_TYPEACCESS) {
      assert::is_true(h_result::is_error(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(is_error_with_DISP_E_PARAMNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(is_error_with_FUSION_E_INVALID_NAME) {
      assert::is_true(h_result::is_error(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(is_error_with_COR_E_ENDOFSTREAM) {
      assert::is_true(h_result::is_error(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(is_error_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::is_true(h_result::is_error(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(is_error_with_COR_E_RUNTIMEWRAPPED) {
      assert::is_true(h_result::is_error(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(is_error_with_COR_E_TARGET) {
      assert::is_true(h_result::is_error(h_result::COR_E_TARGET));
    }
    
    void test_method_(is_error_with_COR_E_DATAMISALIGNED) {
      assert::is_true(h_result::is_error(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(is_error_with_COR_E_TYPEINITIALIZATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(is_error_with_COR_E_ARITHMETIC) {
      assert::is_true(h_result::is_error(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(is_error_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::is_true(h_result::is_error(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(is_error_with_COR_E_TIMEOUT) {
      assert::is_true(h_result::is_error(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(is_error_with_COR_E_FILENOTFOUND) {
      assert::is_true(h_result::is_error(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_TARGETPARAMCOUNT) {
      assert::is_true(h_result::is_error(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(is_error_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::is_true(h_result::is_error(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(is_error_with_E_NOTIMPL) {
      assert::is_true(h_result::is_error(h_result::E_NOTIMPL));
    }
    
    void test_method_(is_error_with_COR_E_MARSHALDIRECTIVE) {
      assert::is_true(h_result::is_error(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(is_error_with_DISP_E_BADVARTYPE) {
      assert::is_true(h_result::is_error(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(is_error_with_COR_E_IO) {
      assert::is_true(h_result::is_error(h_result::COR_E_IO));
    }
    
    void test_method_(is_error_with_ERROR_OPEN_FAILED) {
      assert::is_true(h_result::is_error(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(is_error_with_COR_E_ABANDONEDMUTEX) {
      assert::is_true(h_result::is_error(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(is_error_with_ERROR_DLL_INIT_FAILED) {
      assert::is_true(h_result::is_error(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(is_error_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::is_true(h_result::is_error(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(is_error_with_S_FALSE) {
      assert::is_false(h_result::is_error(h_result::S_FALSE));
    }
    
    void test_method_(is_error_with_COR_E_MEMBERACCESS) {
      assert::is_true(h_result::is_error(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(is_error_with_COR_E_RANK) {
      assert::is_true(h_result::is_error(h_result::COR_E_RANK));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDCOMOBJECT) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(is_error_with_E_HANDLE) {
      assert::is_true(h_result::is_error(h_result::E_HANDLE));
    }
    
    void test_method_(is_error_with_COR_E_INVALIDOPERATION) {
      assert::is_true(h_result::is_error(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(is_error_with_STG_E_PATHNOTFOUND) {
      assert::is_true(h_result::is_error(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(is_error_with_COR_E_SYSTEM) {
      assert::is_true(h_result::is_error(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(make_error_code_with_ERROR_FILE_INVALID) {
      assert::are_equal(static_cast<int32>(0x800703EE), h_result::make_error_code(h_result::ERROR_FILE_INVALID).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_FILE_INVALID).category().name());
      assert::are_equal("File invalid.", h_result::make_error_code(h_result::ERROR_FILE_INVALID).message());
    }
    
    void test_method_(make_error_code_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal(static_cast<int32>(0x80131016), h_result::make_error_code(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS).category().name());
      assert::are_equal("Assembly load in progress.", h_result::make_error_code(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS).message());
    }
    
    void test_method_(make_error_code_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal(static_cast<int32>(0x800703ED), h_result::make_error_code(h_result::ERROR_UNRECOGNIZED_VOLUME).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_UNRECOGNIZED_VOLUME).category().name());
      assert::are_equal("Unrecognized volume.", h_result::make_error_code(h_result::ERROR_UNRECOGNIZED_VOLUME).message());
    }
    
    void test_method_(make_error_code_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070021), h_result::make_error_code(h_result::ERROR_LOCK_VIOLATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_LOCK_VIOLATION).category().name());
      assert::are_equal("Lock violations.", h_result::make_error_code(h_result::ERROR_LOCK_VIOLATION).message());
    }
    
    void test_method_(make_error_code_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal(static_cast<int32>(0x80070020), h_result::make_error_code(h_result::ERROR_SHARING_VIOLATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_SHARING_VIOLATION).category().name());
      assert::are_equal("Sharing violation.", h_result::make_error_code(h_result::ERROR_SHARING_VIOLATION).message());
    }
    
    void test_method_(make_error_code_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal(static_cast<int32>(0x80070004), h_result::make_error_code(h_result::ERROR_TOO_MANY_OPEN_FILES).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_TOO_MANY_OPEN_FILES).category().name());
      assert::are_equal("Too many open files.", h_result::make_error_code(h_result::ERROR_TOO_MANY_OPEN_FILES).message());
    }
    
    void test_method_(make_error_code_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131040), h_result::make_error_code(h_result::FUSION_E_REF_DEF_MISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::FUSION_E_REF_DEF_MISMATCH).category().name());
      assert::are_equal("Fusion the reference definition is incompatible.", h_result::make_error_code(h_result::FUSION_E_REF_DEF_MISMATCH).message());
    }
    
    void test_method_(make_error_code_with_CTL_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A0035), h_result::make_error_code(h_result::CTL_E_FILENOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::CTL_E_FILENOTFOUND).category().name());
      assert::are_equal("Unable to find the specified file.", h_result::make_error_code(h_result::CTL_E_FILENOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_RPC_E_CHANGED_MODE) {
      assert::are_equal(static_cast<int32>(0x80010106), h_result::make_error_code(h_result::RPC_E_CHANGED_MODE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::RPC_E_CHANGED_MODE).category().name());
      assert::are_equal("Cannot change the current thread mode.", h_result::make_error_code(h_result::RPC_E_CHANGED_MODE).message());
    }
    
    void test_method_(make_error_code_with_RO_E_CLOSED) {
      assert::are_equal(static_cast<int32>(0x80000013), h_result::make_error_code(h_result::RO_E_CLOSED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::RO_E_CLOSED).category().name());
      assert::are_equal("The object has been closed.", h_result::make_error_code(h_result::RO_E_CLOSED).message());
    }
    
    void test_method_(make_error_code_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal(static_cast<int32>(0x80073B1F), h_result::make_error_code(h_result::ERROR_MRM_MAP_NOT_FOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_MRM_MAP_NOT_FOUND).category().name());
      assert::are_equal("Resource map not found.", h_result::make_error_code(h_result::ERROR_MRM_MAP_NOT_FOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal(static_cast<int32>(0x8013106A), h_result::make_error_code(h_result::COR_E_AMBIGUOUSIMPLEMENTATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_AMBIGUOUSIMPLEMENTATION).category().name());
      assert::are_equal("Ambiguous implementation found.", h_result::make_error_code(h_result::COR_E_AMBIGUOUSIMPLEMENTATION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131508), h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE).category().name());
      assert::are_equal("Index was outside the bounds of the array.", h_result::make_error_code(h_result::COR_E_INDEXOUTOFRANGE).message());
    }
    
    void test_method_(make_error_code_with_E_CHANGED_STATE) {
      assert::are_equal(static_cast<int32>(0x8000000C), h_result::make_error_code(h_result::E_CHANGED_STATE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_CHANGED_STATE).category().name());
      assert::are_equal("The state has been modified.", h_result::make_error_code(h_result::E_CHANGED_STATE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_FIELDACCESS) {
      assert::are_equal(static_cast<int32>(0x80131507), h_result::make_error_code(h_result::COR_E_FIELDACCESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_FIELDACCESS).category().name());
      assert::are_equal("Attempted to access a field that is not accessible by the caller.", h_result::make_error_code(h_result::COR_E_FIELDACCESS).message());
    }
    
    void test_method_(make_error_code_with_E_BOUNDS) {
      assert::are_equal(static_cast<int32>(0x8000000B), h_result::make_error_code(h_result::E_BOUNDS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_BOUNDS).category().name());
      assert::are_equal("Bounds exception", h_result::make_error_code(h_result::E_BOUNDS).message());
    }
    
    void test_method_(make_error_code_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80020005), h_result::make_error_code(h_result::DISP_E_TYPEMISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::DISP_E_TYPEMISMATCH).category().name());
      assert::are_equal("Attempt to access a variable with an incompatible type.", h_result::make_error_code(h_result::DISP_E_TYPEMISMATCH).message());
    }
    
    void test_method_(make_error_code_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal(static_cast<int32>(0x8013152C), h_result::make_error_code(h_result::COR_E_WAITHANDLECANNOTBEOPENED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_WAITHANDLECANNOTBEOPENED).category().name());
      assert::are_equal("No handle of the given name exists.", h_result::make_error_code(h_result::COR_E_WAITHANDLECANNOTBEOPENED).message());
    }
    
    void test_method_(make_error_code_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x800A004C), h_result::make_error_code(h_result::CTL_E_PATHNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::CTL_E_PATHNOTFOUND).category().name());
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::make_error_code(h_result::CTL_E_PATHNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_VERIFICATION) {
      assert::are_equal(static_cast<int32>(0x8013150D), h_result::make_error_code(h_result::COR_E_VERIFICATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_VERIFICATION).category().name());
      assert::are_equal("Operation could destabilize the runtime.", h_result::make_error_code(h_result::COR_E_VERIFICATION).message());
    }
    
    void test_method_(make_error_code_with_E_POINTER) {
      assert::are_equal(static_cast<int32>(0x80004003), h_result::make_error_code(h_result::E_POINTER).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_POINTER).category().name());
      assert::are_equal("Attempted to read or write protected memory. This is often an indication that other memory is corrupt.", h_result::make_error_code(h_result::E_POINTER).message());
    }
    
    void test_method_(make_error_code_with_COR_E_THREADSTATE) {
      assert::are_equal(static_cast<int32>(0x80131520), h_result::make_error_code(h_result::COR_E_THREADSTATE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_THREADSTATE).category().name());
      assert::are_equal("Thread was in an invalid state for the operation being executed.", h_result::make_error_code(h_result::COR_E_THREADSTATE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_THREADSTART) {
      assert::are_equal(static_cast<int32>(0x80131525), h_result::make_error_code(h_result::COR_E_THREADSTART).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_THREADSTART).category().name());
      assert::are_equal("Thread start failure.", h_result::make_error_code(h_result::COR_E_THREADSTART).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131523), h_result::make_error_code(h_result::COR_E_ENTRYPOINTNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ENTRYPOINTNOTFOUND).category().name());
      assert::are_equal("Entry point was not found.", h_result::make_error_code(h_result::COR_E_ENTRYPOINTNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_CO_E_NOTINITIALIZED) {
      assert::are_equal(static_cast<int32>(0x800401F0), h_result::make_error_code(h_result::CO_E_NOTINITIALIZED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::CO_E_NOTINITIALIZED).category().name());
      assert::are_equal("Not initialized", h_result::make_error_code(h_result::CO_E_NOTINITIALIZED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal(static_cast<int32>(0x80131519), h_result::make_error_code(h_result::COR_E_THREADINTERRUPTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_THREADINTERRUPTED).category().name());
      assert::are_equal("Thread was interrupted from a waiting state.", h_result::make_error_code(h_result::COR_E_THREADINTERRUPTED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_THREADABORTED) {
      assert::are_equal(static_cast<int32>(0x80131530), h_result::make_error_code(h_result::COR_E_THREADABORTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_THREADABORTED).category().name());
      assert::are_equal("Thread was aborted.", h_result::make_error_code(h_result::COR_E_THREADABORTED).message());
    }
    
    void test_method_(make_error_code_with_E_UNEXPECTED) {
      assert::are_equal(static_cast<int32>(0x8000FFFF), h_result::make_error_code(h_result::E_UNEXPECTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_UNEXPECTED).category().name());
      assert::are_equal("Unexpected failure.", h_result::make_error_code(h_result::E_UNEXPECTED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal(static_cast<int32>(0x80131518), h_result::make_error_code(h_result::COR_E_SYNCHRONIZATIONLOCK).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SYNCHRONIZATIONLOCK).category().name());
      assert::are_equal("Object synchronization method was called from an unsynchronized block of code.", h_result::make_error_code(h_result::COR_E_SYNCHRONIZATIONLOCK).message());
    }
    
    void test_method_(make_error_code_with_E_FAIL) {
      assert::are_equal(static_cast<int32>(0x80004005), h_result::make_error_code(h_result::E_FAIL).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_FAIL).category().name());
      assert::are_equal("Unspecified failure.", h_result::make_error_code(h_result::E_FAIL).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131522), h_result::make_error_code(h_result::COR_E_TYPELOAD).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TYPELOAD).category().name());
      assert::are_equal("Failure has occurred while loading a type.", h_result::make_error_code(h_result::COR_E_TYPELOAD).message());
    }
    
    void test_method_(make_error_code_with_COR_E_STACKOVERFLOW) {
      assert::are_equal(static_cast<int32>(0x800703E9), h_result::make_error_code(h_result::COR_E_STACKOVERFLOW).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_STACKOVERFLOW).category().name());
      assert::are_equal("Operation caused a stack overflow.", h_result::make_error_code(h_result::COR_E_STACKOVERFLOW).message());
    }
    
    void test_method_(make_error_code_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80028CA0), h_result::make_error_code(h_result::TYPE_E_TYPEMISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::TYPE_E_TYPEMISMATCH).category().name());
      assert::are_equal("Incompatible type.", h_result::make_error_code(h_result::TYPE_E_TYPEMISMATCH).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SERIALIZATION) {
      assert::are_equal(static_cast<int32>(0x8013150C), h_result::make_error_code(h_result::COR_E_SERIALIZATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SERIALIZATION).category().name());
      assert::are_equal("Serialization error.", h_result::make_error_code(h_result::COR_E_SERIALIZATION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SECURITY) {
      assert::are_equal(static_cast<int32>(0x8013150A), h_result::make_error_code(h_result::COR_E_SECURITY).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SECURITY).category().name());
      assert::are_equal("Security error.", h_result::make_error_code(h_result::COR_E_SECURITY).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131533), h_result::make_error_code(h_result::COR_E_SAFEARRAYTYPEMISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SAFEARRAYTYPEMISMATCH).category().name());
      assert::are_equal("Specified array was not of the expected type.", h_result::make_error_code(h_result::COR_E_SAFEARRAYTYPEMISMATCH).message());
    }
    
    void test_method_(make_error_code_with_E_ABORT) {
      assert::are_equal(static_cast<int32>(0x80004004), h_result::make_error_code(h_result::E_ABORT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_ABORT).category().name());
      assert::are_equal("Operation aborted.", h_result::make_error_code(h_result::E_ABORT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131538), h_result::make_error_code(h_result::COR_E_SAFEARRAYRANKMISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SAFEARRAYRANKMISMATCH).category().name());
      assert::are_equal("Specified array was not of the expected rank.", h_result::make_error_code(h_result::COR_E_SAFEARRAYRANKMISMATCH).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal(static_cast<int32>(0x8013153D), h_result::make_error_code(h_result::COR_E_INSUFFICIENTMEMORY).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INSUFFICIENTMEMORY).category().name());
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::make_error_code(h_result::COR_E_INSUFFICIENTMEMORY).message());
    }
    
    void test_method_(make_error_code_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal(static_cast<int32>(0x80131602), h_result::make_error_code(h_result::COR_E_REFLECTIONTYPELOAD).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_REFLECTIONTYPELOAD).category().name());
      assert::are_equal("Exception of type 'xtd::reflection::reflection_type_load_exception' was thrown.", h_result::make_error_code(h_result::COR_E_REFLECTIONTYPELOAD).message());
    }
    
    void test_method_(make_error_code_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131539), h_result::make_error_code(h_result::COR_E_PLATFORMNOTSUPPORTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_PLATFORMNOTSUPPORTED).category().name());
      assert::are_equal("Operation is not supported on this platform.", h_result::make_error_code(h_result::COR_E_PLATFORMNOTSUPPORTED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_PATHTOOLONG) {
      assert::are_equal(static_cast<int32>(0x800700CE), h_result::make_error_code(h_result::COR_E_PATHTOOLONG).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_PATHTOOLONG).category().name());
      assert::are_equal("The specified file name or path is too long, or a component of the specified path is too long.", h_result::make_error_code(h_result::COR_E_PATHTOOLONG).message());
    }
    
    void test_method_(make_error_code_with_COR_E_APPLICATION) {
      assert::are_equal(static_cast<int32>(0x80131600), h_result::make_error_code(h_result::COR_E_APPLICATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_APPLICATION).category().name());
      assert::are_equal("Error in the application.", h_result::make_error_code(h_result::COR_E_APPLICATION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal(static_cast<int32>(0x8013153B), h_result::make_error_code(h_result::COR_E_OPERATIONCANCELED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_OPERATIONCANCELED).category().name());
      assert::are_equal("The operation was canceled.", h_result::make_error_code(h_result::COR_E_OPERATIONCANCELED).message());
    }
    
    void test_method_(make_error_code_with_DISP_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x8002000A), h_result::make_error_code(h_result::DISP_E_OVERFLOW).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::DISP_E_OVERFLOW).category().name());
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::make_error_code(h_result::DISP_E_OVERFLOW).message());
    }
    
    void test_method_(make_error_code_with_COR_E_OBJECTCLOSED) {
      assert::are_equal(static_cast<int32>(0x80131622), h_result::make_error_code(h_result::COR_E_OBJECTCLOSED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_OBJECTCLOSED).category().name());
      assert::are_equal("Cannot access a closed object.", h_result::make_error_code(h_result::COR_E_OBJECTCLOSED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_NOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131515), h_result::make_error_code(h_result::COR_E_NOTSUPPORTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_NOTSUPPORTED).category().name());
      assert::are_equal("Specified method is not supported.", h_result::make_error_code(h_result::COR_E_NOTSUPPORTED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal(static_cast<int32>(0x80131528), h_result::make_error_code(h_result::COR_E_NOTFINITENUMBER).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_NOTFINITENUMBER).category().name());
      assert::are_equal("Number encountered was not a finite quantity.", h_result::make_error_code(h_result::COR_E_NOTFINITENUMBER).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal(static_cast<int32>(0x80131514), h_result::make_error_code(h_result::COR_E_MULTICASTNOTSUPPORTED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MULTICASTNOTSUPPORTED).category().name());
      assert::are_equal("Attempted to add multiple callbacks to a delegate that does not support multicast.", h_result::make_error_code(h_result::COR_E_MULTICASTNOTSUPPORTED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MISSINGMETHOD) {
      assert::are_equal(static_cast<int32>(0x80131513), h_result::make_error_code(h_result::COR_E_MISSINGMETHOD).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MISSINGMETHOD).category().name());
      assert::are_equal("Attempted to access a missing method.", h_result::make_error_code(h_result::COR_E_MISSINGMETHOD).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MISSINGMEMBER) {
      assert::are_equal(static_cast<int32>(0x80131512), h_result::make_error_code(h_result::COR_E_MISSINGMEMBER).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MISSINGMEMBER).category().name());
      assert::are_equal("Attempted to access a missing member.", h_result::make_error_code(h_result::COR_E_MISSINGMEMBER).message());
    }
    
    void test_method_(make_error_code_with_ERROR_DISK_CORRUPT) {
      assert::are_equal(static_cast<int32>(0x80070571), h_result::make_error_code(h_result::ERROR_DISK_CORRUPT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_DISK_CORRUPT).category().name());
      assert::are_equal("Disk corrupt.", h_result::make_error_code(h_result::ERROR_DISK_CORRUPT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_OUTOFMEMORY) {
      assert::are_equal(static_cast<int32>(0x8007000E), h_result::make_error_code(h_result::COR_E_OUTOFMEMORY).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_OUTOFMEMORY).category().name());
      assert::are_equal("Insufficient memory to continue the execution of the program.", h_result::make_error_code(h_result::COR_E_OUTOFMEMORY).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MISSINGFIELD) {
      assert::are_equal(static_cast<int32>(0x80131511), h_result::make_error_code(h_result::COR_E_MISSINGFIELD).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MISSINGFIELD).category().name());
      assert::are_equal("Attempted to access a non-existing field.", h_result::make_error_code(h_result::COR_E_MISSINGFIELD).message());
    }
    
    void test_method_(make_error_code_with_ERROR_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x800705B4), h_result::make_error_code(h_result::ERROR_TIMEOUT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_TIMEOUT).category().name());
      assert::are_equal("The operation has timed out.", h_result::make_error_code(h_result::ERROR_TIMEOUT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_METHODACCESS) {
      assert::are_equal(static_cast<int32>(0x80131510), h_result::make_error_code(h_result::COR_E_METHODACCESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_METHODACCESS).category().name());
      assert::are_equal("Attempt to access the method failed.", h_result::make_error_code(h_result::COR_E_METHODACCESS).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ARGUMENT) {
      assert::are_equal(static_cast<int32>(0x80070057), h_result::make_error_code(h_result::COR_E_ARGUMENT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ARGUMENT).category().name());
      assert::are_equal("Value does not fall within the expected range.", h_result::make_error_code(h_result::COR_E_ARGUMENT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_OVERFLOW) {
      assert::are_equal(static_cast<int32>(0x80131516), h_result::make_error_code(h_result::COR_E_OVERFLOW).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_OVERFLOW).category().name());
      assert::are_equal("Arithmetic operation resulted in an overflow.", h_result::make_error_code(h_result::COR_E_OVERFLOW).message());
    }
    
    void test_method_(make_error_code_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131014), h_result::make_error_code(h_result::COR_E_APPDOMAINUNLOADED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_APPDOMAINUNLOADED).category().name());
      assert::are_equal("Attempted to access an unloaded AppDomain.", h_result::make_error_code(h_result::COR_E_APPDOMAINUNLOADED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_KEYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131577), h_result::make_error_code(h_result::COR_E_KEYNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_KEYNOTFOUND).category().name());
      assert::are_equal("The given key was not present in the dictionary.", h_result::make_error_code(h_result::COR_E_KEYNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal(static_cast<int32>(0x8013153A), h_result::make_error_code(h_result::COR_E_INVALIDPROGRAM).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDPROGRAM).category().name());
      assert::are_equal("xtd detected an invalid program.", h_result::make_error_code(h_result::COR_E_INVALIDPROGRAM).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal(static_cast<int32>(0x80131601), h_result::make_error_code(h_result::COR_E_INVALIDFILTERCRITERIA).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDFILTERCRITERIA).category().name());
      assert::are_equal("Specified filter criteria was invalid.", h_result::make_error_code(h_result::COR_E_INVALIDFILTERCRITERIA).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal(static_cast<int32>(0x80131536), h_result::make_error_code(h_result::COR_E_MISSINGSATELLITEASSEMBLY).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MISSINGSATELLITEASSEMBLY).category().name());
      assert::are_equal("Resource lookup fell back to the ultimate fallback resources in a satellite assembly, but that satellite either was not found or could not be loaded. Please consider reinstalling or repairing the application.", h_result::make_error_code(h_result::COR_E_MISSINGSATELLITEASSEMBLY).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDCAST) {
      assert::are_equal(static_cast<int32>(0x80004002), h_result::make_error_code(h_result::COR_E_INVALIDCAST).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDCAST).category().name());
      assert::are_equal("Specified cast is not valid.", h_result::make_error_code(h_result::COR_E_INVALIDCAST).message());
    }
    
    void test_method_(make_error_code_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal(static_cast<int32>(0x80070005), h_result::make_error_code(h_result::COR_E_UNAUTHORIZEDACCESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_UNAUTHORIZEDACCESS).category().name());
      assert::are_equal("Attempted to perform an unauthorized operation.", h_result::make_error_code(h_result::COR_E_UNAUTHORIZEDACCESS).message());
    }
    
    void test_method_(make_error_code_with_COR_E_FORMAT) {
      assert::are_equal(static_cast<int32>(0x80131537), h_result::make_error_code(h_result::COR_E_FORMAT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_FORMAT).category().name());
      assert::are_equal("One of the identified items was in an invalid format.", h_result::make_error_code(h_result::COR_E_FORMAT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_FILELOAD) {
      assert::are_equal(static_cast<int32>(0x80131621), h_result::make_error_code(h_result::COR_E_FILELOAD).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_FILELOAD).category().name());
      assert::are_equal("Could not load the specified file.", h_result::make_error_code(h_result::COR_E_FILELOAD).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal(static_cast<int32>(0x80020012), h_result::make_error_code(h_result::COR_E_DIVIDEBYZERO).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DIVIDEBYZERO).category().name());
      assert::are_equal("Attempted to divide by zero.", h_result::make_error_code(h_result::COR_E_DIVIDEBYZERO).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TYPEUNLOADED) {
      assert::are_equal(static_cast<int32>(0x80131013), h_result::make_error_code(h_result::COR_E_TYPEUNLOADED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TYPEUNLOADED).category().name());
      assert::are_equal("Type had been unloaded.", h_result::make_error_code(h_result::COR_E_TYPEUNLOADED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_FAILFAST) {
      assert::are_equal(static_cast<int32>(0x80131623), h_result::make_error_code(h_result::COR_E_FAILFAST).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_FAILFAST).category().name());
      assert::are_equal("Fail fast.", h_result::make_error_code(h_result::COR_E_FAILFAST).message());
    }
    
    void test_method_(make_error_code_with_COR_E_EXCEPTION) {
      assert::are_equal(static_cast<int32>(0x80131500), h_result::make_error_code(h_result::COR_E_EXCEPTION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_EXCEPTION).category().name());
      assert::are_equal("Exception of type 'xtd::exception' was thrown.", h_result::make_error_code(h_result::COR_E_EXCEPTION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DLLNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80131524), h_result::make_error_code(h_result::COR_E_DLLNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DLLNOTFOUND).category().name());
      assert::are_equal("Dll was not found.", h_result::make_error_code(h_result::COR_E_DLLNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal(static_cast<int32>(0x80131506), h_result::make_error_code(h_result::COR_E_EXECUTIONENGINE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_EXECUTIONENGINE).category().name());
      assert::are_equal("Internal error in the runtime.", h_result::make_error_code(h_result::COR_E_EXECUTIONENGINE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070003), h_result::make_error_code(h_result::COR_E_DIRECTORYNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DIRECTORYNOTFOUND).category().name());
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::make_error_code(h_result::COR_E_DIRECTORYNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal(static_cast<int32>(0x80131504), h_result::make_error_code(h_result::COR_E_CONTEXTMARSHAL).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_CONTEXTMARSHAL).category().name());
      assert::are_equal("Attempted to marshal an object across a context boundary.", h_result::make_error_code(h_result::COR_E_CONTEXTMARSHAL).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal(static_cast<int32>(0x80131502), h_result::make_error_code(h_result::COR_E_ARGUMENTOUTOFRANGE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ARGUMENTOUTOFRANGE).category().name());
      assert::are_equal("Specified argument was out of the range of valid values.", h_result::make_error_code(h_result::COR_E_ARGUMENTOUTOFRANGE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal(static_cast<int32>(0x8000211D), h_result::make_error_code(h_result::COR_E_AMBIGUOUSMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_AMBIGUOUSMATCH).category().name());
      assert::are_equal("Ambiguous match found.", h_result::make_error_code(h_result::COR_E_AMBIGUOUSMATCH).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070007), h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND).category().name());
      assert::are_equal("Could not find the drive. The drive might not be ready or might not be mapped.", h_result::make_error_code(h_result::COR_E_DRIVENOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_BADEXEFORMAT) {
      assert::are_equal(static_cast<int32>(0x800700C1), h_result::make_error_code(h_result::COR_E_BADEXEFORMAT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_BADEXEFORMAT).category().name());
      assert::are_equal("Format of the executable (.exe) cannot be run.", h_result::make_error_code(h_result::COR_E_BADEXEFORMAT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal(static_cast<int32>(0x80131578), h_result::make_error_code(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK).category().name());
      assert::are_equal("Insufficient stack to continue executing the program safely. This can happen from having too many functions on the call stack or function on the stack using too much stack space.", h_result::make_error_code(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK).message());
    }
    
    void test_method_(make_error_code_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal(static_cast<int32>(0x80131015), h_result::make_error_code(h_result::COR_E_CANNOTUNLOADAPPDOMAIN).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_CANNOTUNLOADAPPDOMAIN).category().name());
      assert::are_equal("Attempt to unload the AppDomain failed.", h_result::make_error_code(h_result::COR_E_CANNOTUNLOADAPPDOMAIN).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TARGETINVOCATION) {
      assert::are_equal(static_cast<int32>(0x80131604), h_result::make_error_code(h_result::COR_E_TARGETINVOCATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TARGETINVOCATION).category().name());
      assert::are_equal("Exception has been thrown by the target of an invocation.", h_result::make_error_code(h_result::COR_E_TARGETINVOCATION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal(static_cast<int32>(0x80131542), h_result::make_error_code(h_result::COR_E_CODECONTRACTFAILED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_CODECONTRACTFAILED).category().name());
      assert::are_equal("A code contract (ie, precondition, postcondition, invariant, or assert) failed.", h_result::make_error_code(h_result::COR_E_CODECONTRACTFAILED).message());
    }
    
    void test_method_(make_error_code_with_S_OK) {
      assert::are_equal(static_cast<int32>(0x00000000), h_result::make_error_code(h_result::S_OK).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::S_OK).category().name());
      assert::are_equal("Operation successful.", h_result::make_error_code(h_result::S_OK).message());
    }
    
    void test_method_(make_error_code_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal(static_cast<int32>(0x8007000B), h_result::make_error_code(h_result::COR_E_BADIMAGEFORMAT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_BADIMAGEFORMAT).category().name());
      assert::are_equal("Format of the executable (.exe) or library (.dll) is invalid.", h_result::make_error_code(h_result::COR_E_BADIMAGEFORMAT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TYPEACCESS) {
      assert::are_equal(static_cast<int32>(0x80131543), h_result::make_error_code(h_result::COR_E_TYPEACCESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TYPEACCESS).category().name());
      assert::are_equal("Attempt to access the type failed.", h_result::make_error_code(h_result::COR_E_TYPEACCESS).message());
    }
    
    void test_method_(make_error_code_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80020004), h_result::make_error_code(h_result::DISP_E_PARAMNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::DISP_E_PARAMNOTFOUND).category().name());
      assert::are_equal("Could not find the parameter.", h_result::make_error_code(h_result::DISP_E_PARAMNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_FUSION_E_INVALID_NAME) {
      assert::are_equal(static_cast<int32>(0x80131047), h_result::make_error_code(h_result::FUSION_E_INVALID_NAME).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::FUSION_E_INVALID_NAME).category().name());
      assert::are_equal("Fusion invalid name exception.", h_result::make_error_code(h_result::FUSION_E_INVALID_NAME).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ENDOFSTREAM) {
      assert::are_equal(static_cast<int32>(0x80070026), h_result::make_error_code(h_result::COR_E_ENDOFSTREAM).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ENDOFSTREAM).category().name());
      assert::are_equal("Attempted to read past the end of the stream.", h_result::make_error_code(h_result::COR_E_ENDOFSTREAM).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131529), h_result::make_error_code(h_result::COR_E_DUPLICATEWAITOBJECT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DUPLICATEWAITOBJECT).category().name());
      assert::are_equal("Duplicate objects in argument.", h_result::make_error_code(h_result::COR_E_DUPLICATEWAITOBJECT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal(static_cast<int32>(0x8013153E), h_result::make_error_code(h_result::COR_E_RUNTIMEWRAPPED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_RUNTIMEWRAPPED).category().name());
      assert::are_equal("An object that does not derive from xtd:oobject has been wrapped in a runtime_wrapped_exception.", h_result::make_error_code(h_result::COR_E_RUNTIMEWRAPPED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TARGET) {
      assert::are_equal(static_cast<int32>(0x80131603), h_result::make_error_code(h_result::COR_E_TARGET).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TARGET).category().name());
      assert::are_equal("Exception of type 'xtd::reflection::target_exception' was thrown.", h_result::make_error_code(h_result::COR_E_TARGET).message());
    }
    
    void test_method_(make_error_code_with_COR_E_DATAMISALIGNED) {
      assert::are_equal(static_cast<int32>(0x80131541), h_result::make_error_code(h_result::COR_E_DATAMISALIGNED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_DATAMISALIGNED).category().name());
      assert::are_equal("A datatype misalignment was detected in a load or store instruction.", h_result::make_error_code(h_result::COR_E_DATAMISALIGNED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal(static_cast<int32>(0x80131534), h_result::make_error_code(h_result::COR_E_TYPEINITIALIZATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TYPEINITIALIZATION).category().name());
      assert::are_equal("The type initializer for 'value' threw an exception.", h_result::make_error_code(h_result::COR_E_TYPEINITIALIZATION).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ARITHMETIC) {
      assert::are_equal(static_cast<int32>(0x80070216), h_result::make_error_code(h_result::COR_E_ARITHMETIC).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ARITHMETIC).category().name());
      assert::are_equal("Overflow or underflow in the arithmetic operation.", h_result::make_error_code(h_result::COR_E_ARITHMETIC).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal(static_cast<int32>(0x80131531), h_result::make_error_code(h_result::COR_E_INVALIDOLEVARIANTTYPE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDOLEVARIANTTYPE).category().name());
      assert::are_equal("Specified OLE variant was invalid.", h_result::make_error_code(h_result::COR_E_INVALIDOLEVARIANTTYPE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal(static_cast<int32>(0x80131532), h_result::make_error_code(h_result::COR_E_MISSINGMANIFESTRESOURCE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MISSINGMANIFESTRESOURCE).category().name());
      assert::are_equal("Attempted to access a missing manifest resource.", h_result::make_error_code(h_result::COR_E_MISSINGMANIFESTRESOURCE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TIMEOUT) {
      assert::are_equal(static_cast<int32>(0x80131505), h_result::make_error_code(h_result::COR_E_TIMEOUT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TIMEOUT).category().name());
      assert::are_equal("The operation has timed out.", h_result::make_error_code(h_result::COR_E_TIMEOUT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_FILENOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80070002), h_result::make_error_code(h_result::COR_E_FILENOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_FILENOTFOUND).category().name());
      assert::are_equal("Unable to find the specified file.", h_result::make_error_code(h_result::COR_E_FILENOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal(static_cast<int32>(0x8002000E), h_result::make_error_code(h_result::COR_E_TARGETPARAMCOUNT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_TARGETPARAMCOUNT).category().name());
      assert::are_equal("Number of parameters specified does not match the expected number.", h_result::make_error_code(h_result::COR_E_TARGETPARAMCOUNT).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal(static_cast<int32>(0x80131503), h_result::make_error_code(h_result::COR_E_ARRAYTYPEMISMATCH).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ARRAYTYPEMISMATCH).category().name());
      assert::are_equal("Attempted to access an element as a type incompatible with the array.", h_result::make_error_code(h_result::COR_E_ARRAYTYPEMISMATCH).message());
    }
    
    void test_method_(make_error_code_with_E_NOTIMPL) {
      assert::are_equal(static_cast<int32>(0x80004001), h_result::make_error_code(h_result::E_NOTIMPL).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_NOTIMPL).category().name());
      assert::are_equal("The method or operation is not implemented.", h_result::make_error_code(h_result::E_NOTIMPL).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal(static_cast<int32>(0x80131535), h_result::make_error_code(h_result::COR_E_MARSHALDIRECTIVE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MARSHALDIRECTIVE).category().name());
      assert::are_equal("Marshaling directives are invalid.", h_result::make_error_code(h_result::COR_E_MARSHALDIRECTIVE).message());
    }
    
    void test_method_(make_error_code_with_DISP_E_BADVARTYPE) {
      assert::are_equal(static_cast<int32>(0x80020008), h_result::make_error_code(h_result::DISP_E_BADVARTYPE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::DISP_E_BADVARTYPE).category().name());
      assert::are_equal("Invalid variable type.", h_result::make_error_code(h_result::DISP_E_BADVARTYPE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_IO) {
      assert::are_equal(static_cast<int32>(0x80131620), h_result::make_error_code(h_result::COR_E_IO).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_IO).category().name());
      assert::are_equal("I/O error occurred.", h_result::make_error_code(h_result::COR_E_IO).message());
    }
    
    void test_method_(make_error_code_with_ERROR_OPEN_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007006E), h_result::make_error_code(h_result::ERROR_OPEN_FAILED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_OPEN_FAILED).category().name());
      assert::are_equal("Open failed.", h_result::make_error_code(h_result::ERROR_OPEN_FAILED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal(static_cast<int32>(0x8013152D), h_result::make_error_code(h_result::COR_E_ABANDONEDMUTEX).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_ABANDONEDMUTEX).category().name());
      assert::are_equal("The wait completed due to an abandoned mutex.", h_result::make_error_code(h_result::COR_E_ABANDONEDMUTEX).message());
    }
    
    void test_method_(make_error_code_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal(static_cast<int32>(0x8007045A), h_result::make_error_code(h_result::ERROR_DLL_INIT_FAILED).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::ERROR_DLL_INIT_FAILED).category().name());
      assert::are_equal("DLL init failed.", h_result::make_error_code(h_result::ERROR_DLL_INIT_FAILED).message());
    }
    
    void test_method_(make_error_code_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal(static_cast<int32>(0x80131605), h_result::make_error_code(h_result::COR_E_CUSTOMATTRIBUTEFORMAT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_CUSTOMATTRIBUTEFORMAT).category().name());
      assert::are_equal("Binary format of the specified custom attribute was invalid.", h_result::make_error_code(h_result::COR_E_CUSTOMATTRIBUTEFORMAT).message());
    }
    
    void test_method_(make_error_code_with_S_FALSE) {
      assert::are_equal(static_cast<int32>(0x00000001), h_result::make_error_code(h_result::S_FALSE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::S_FALSE).category().name());
      assert::are_equal("Operation successful but returned no results.", h_result::make_error_code(h_result::S_FALSE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_MEMBERACCESS) {
      assert::are_equal(static_cast<int32>(0x8013151A), h_result::make_error_code(h_result::COR_E_MEMBERACCESS).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_MEMBERACCESS).category().name());
      assert::are_equal("Cannot access member.", h_result::make_error_code(h_result::COR_E_MEMBERACCESS).message());
    }
    
    void test_method_(make_error_code_with_COR_E_RANK) {
      assert::are_equal(static_cast<int32>(0x80131517), h_result::make_error_code(h_result::COR_E_RANK).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_RANK).category().name());
      assert::are_equal("Attempted to operate on an array with the incorrect number of dimensions.", h_result::make_error_code(h_result::COR_E_RANK).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal(static_cast<int32>(0x80131527), h_result::make_error_code(h_result::COR_E_INVALIDCOMOBJECT).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDCOMOBJECT).category().name());
      assert::are_equal("Attempt has been made to use a COM object that does not have a backing class factory.", h_result::make_error_code(h_result::COR_E_INVALIDCOMOBJECT).message());
    }
    
    void test_method_(make_error_code_with_E_HANDLE) {
      assert::are_equal(static_cast<int32>(0x80070006), h_result::make_error_code(h_result::E_HANDLE).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::E_HANDLE).category().name());
      assert::are_equal("The handle is invalid.", h_result::make_error_code(h_result::E_HANDLE).message());
    }
    
    void test_method_(make_error_code_with_COR_E_INVALIDOPERATION) {
      assert::are_equal(static_cast<int32>(0x80131509), h_result::make_error_code(h_result::COR_E_INVALIDOPERATION).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_INVALIDOPERATION).category().name());
      assert::are_equal("Operation is not valid due to the current state of the object.", h_result::make_error_code(h_result::COR_E_INVALIDOPERATION).message());
    }
    
    void test_method_(make_error_code_with_STG_E_PATHNOTFOUND) {
      assert::are_equal(static_cast<int32>(0x80030003), h_result::make_error_code(h_result::STG_E_PATHNOTFOUND).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::STG_E_PATHNOTFOUND).category().name());
      assert::are_equal("Attempted to access a path that is not on the disk.", h_result::make_error_code(h_result::STG_E_PATHNOTFOUND).message());
    }
    
    void test_method_(make_error_code_with_COR_E_SYSTEM) {
      assert::are_equal(static_cast<int32>(0x80131501), h_result::make_error_code(h_result::COR_E_SYSTEM).value());
      assert::are_equal("h_result_category", h_result::make_error_code(h_result::COR_E_SYSTEM).category().name());
      assert::are_equal("System error.", h_result::make_error_code(h_result::COR_E_SYSTEM).message());
    }
    
    void test_method_(make_error_code_with_unknown_value) {
      assert::are_equal(static_cast<int32>(0xFF00FF00), h_result::make_error_code(0xFF00FF00).value());
      assert::are_equal("h_result_category", h_result::make_error_code(0xFF00FF00).category().name());
      assert::are_equal("Unknown h_result 0xFF00FF00 (-16711936)", h_result::make_error_code(0xFF00FF00).message());
    }
    
    void test_method_(succeeded_with_ERROR_FILE_INVALID) {
      assert::is_false(h_result::succeeded(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(succeeded_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::is_false(h_result::succeeded(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(succeeded_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::is_false(h_result::succeeded(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(succeeded_with_ERROR_LOCK_VIOLATION) {
      assert::is_false(h_result::succeeded(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(succeeded_with_ERROR_SHARING_VIOLATION) {
      assert::is_false(h_result::succeeded(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(succeeded_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::is_false(h_result::succeeded(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(succeeded_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::is_false(h_result::succeeded(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(succeeded_with_CTL_E_FILENOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(succeeded_with_RPC_E_CHANGED_MODE) {
      assert::is_false(h_result::succeeded(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(succeeded_with_RO_E_CLOSED) {
      assert::is_false(h_result::succeeded(h_result::RO_E_CLOSED));
    }
    
    void test_method_(succeeded_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::is_false(h_result::succeeded(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(succeeded_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(succeeded_with_COR_E_INDEXOUTOFRANGE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(succeeded_with_E_CHANGED_STATE) {
      assert::is_false(h_result::succeeded(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(succeeded_with_COR_E_FIELDACCESS) {
      assert::is_false(h_result::succeeded(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(succeeded_with_E_BOUNDS) {
      assert::is_false(h_result::succeeded(h_result::E_BOUNDS));
    }
    
    void test_method_(succeeded_with_DISP_E_TYPEMISMATCH) {
      assert::is_false(h_result::succeeded(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(succeeded_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(succeeded_with_CTL_E_PATHNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_VERIFICATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(succeeded_with_E_POINTER) {
      assert::is_false(h_result::succeeded(h_result::E_POINTER));
    }
    
    void test_method_(succeeded_with_COR_E_THREADSTATE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(succeeded_with_COR_E_THREADSTART) {
      assert::is_false(h_result::succeeded(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(succeeded_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(succeeded_with_CO_E_NOTINITIALIZED) {
      assert::is_false(h_result::succeeded(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(succeeded_with_COR_E_THREADINTERRUPTED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(succeeded_with_COR_E_THREADABORTED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(succeeded_with_E_UNEXPECTED) {
      assert::is_false(h_result::succeeded(h_result::E_UNEXPECTED));
    }
    
    void test_method_(succeeded_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(succeeded_with_E_FAIL) {
      assert::is_false(h_result::succeeded(h_result::E_FAIL));
    }
    
    void test_method_(succeeded_with_COR_E_TYPELOAD) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(succeeded_with_COR_E_STACKOVERFLOW) {
      assert::is_false(h_result::succeeded(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(succeeded_with_TYPE_E_TYPEMISMATCH) {
      assert::is_false(h_result::succeeded(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(succeeded_with_COR_E_SERIALIZATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(succeeded_with_COR_E_SECURITY) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SECURITY));
    }
    
    void test_method_(succeeded_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(succeeded_with_E_ABORT) {
      assert::is_false(h_result::succeeded(h_result::E_ABORT));
    }
    
    void test_method_(succeeded_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(succeeded_with_COR_E_INSUFFICIENTMEMORY) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(succeeded_with_COR_E_REFLECTIONTYPELOAD) {
      assert::is_false(h_result::succeeded(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(succeeded_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(succeeded_with_COR_E_PATHTOOLONG) {
      assert::is_false(h_result::succeeded(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(succeeded_with_COR_E_APPLICATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(succeeded_with_COR_E_OPERATIONCANCELED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(succeeded_with_DISP_E_OVERFLOW) {
      assert::is_false(h_result::succeeded(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(succeeded_with_COR_E_OBJECTCLOSED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(succeeded_with_COR_E_NOTSUPPORTED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(succeeded_with_COR_E_NOTFINITENUMBER) {
      assert::is_false(h_result::succeeded(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(succeeded_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(succeeded_with_COR_E_MISSINGMETHOD) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(succeeded_with_COR_E_MISSINGMEMBER) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(succeeded_with_ERROR_DISK_CORRUPT) {
      assert::is_false(h_result::succeeded(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(succeeded_with_COR_E_OUTOFMEMORY) {
      assert::is_false(h_result::succeeded(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(succeeded_with_COR_E_MISSINGFIELD) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(succeeded_with_ERROR_TIMEOUT) {
      assert::is_false(h_result::succeeded(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(succeeded_with_COR_E_METHODACCESS) {
      assert::is_false(h_result::succeeded(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(succeeded_with_COR_E_ARGUMENT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(succeeded_with_COR_E_OVERFLOW) {
      assert::is_false(h_result::succeeded(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(succeeded_with_COR_E_APPDOMAINUNLOADED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(succeeded_with_COR_E_KEYNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDPROGRAM) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(succeeded_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDCAST) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(succeeded_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::is_false(h_result::succeeded(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(succeeded_with_COR_E_FORMAT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_FORMAT));
    }
    
    void test_method_(succeeded_with_COR_E_FILELOAD) {
      assert::is_false(h_result::succeeded(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(succeeded_with_COR_E_DIVIDEBYZERO) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(succeeded_with_COR_E_TYPEUNLOADED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(succeeded_with_COR_E_FAILFAST) {
      assert::is_false(h_result::succeeded(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(succeeded_with_COR_E_EXCEPTION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(succeeded_with_COR_E_DLLNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_EXECUTIONENGINE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(succeeded_with_COR_E_DIRECTORYNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_CONTEXTMARSHAL) {
      assert::is_false(h_result::succeeded(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(succeeded_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(succeeded_with_COR_E_AMBIGUOUSMATCH) {
      assert::is_false(h_result::succeeded(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(succeeded_with_COR_E_DRIVENOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_BADEXEFORMAT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(succeeded_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(succeeded_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::is_false(h_result::succeeded(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(succeeded_with_COR_E_TARGETINVOCATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(succeeded_with_COR_E_CODECONTRACTFAILED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(succeeded_with_S_OK) {
      assert::is_true(h_result::succeeded(h_result::S_OK));
    }
    
    void test_method_(succeeded_with_COR_E_BADIMAGEFORMAT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(succeeded_with_COR_E_TYPEACCESS) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(succeeded_with_DISP_E_PARAMNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(succeeded_with_FUSION_E_INVALID_NAME) {
      assert::is_false(h_result::succeeded(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(succeeded_with_COR_E_ENDOFSTREAM) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(succeeded_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(succeeded_with_COR_E_RUNTIMEWRAPPED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(succeeded_with_COR_E_TARGET) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TARGET));
    }
    
    void test_method_(succeeded_with_COR_E_DATAMISALIGNED) {
      assert::is_false(h_result::succeeded(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(succeeded_with_COR_E_TYPEINITIALIZATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(succeeded_with_COR_E_ARITHMETIC) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(succeeded_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(succeeded_with_COR_E_TIMEOUT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(succeeded_with_COR_E_FILENOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_TARGETPARAMCOUNT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(succeeded_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(succeeded_with_E_NOTIMPL) {
      assert::is_false(h_result::succeeded(h_result::E_NOTIMPL));
    }
    
    void test_method_(succeeded_with_COR_E_MARSHALDIRECTIVE) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(succeeded_with_DISP_E_BADVARTYPE) {
      assert::is_false(h_result::succeeded(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(succeeded_with_COR_E_IO) {
      assert::is_false(h_result::succeeded(h_result::COR_E_IO));
    }
    
    void test_method_(succeeded_with_ERROR_OPEN_FAILED) {
      assert::is_false(h_result::succeeded(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(succeeded_with_COR_E_ABANDONEDMUTEX) {
      assert::is_false(h_result::succeeded(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(succeeded_with_ERROR_DLL_INIT_FAILED) {
      assert::is_false(h_result::succeeded(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(succeeded_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(succeeded_with_S_FALSE) {
      assert::is_true(h_result::succeeded(h_result::S_FALSE));
    }
    
    void test_method_(succeeded_with_COR_E_MEMBERACCESS) {
      assert::is_false(h_result::succeeded(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(succeeded_with_COR_E_RANK) {
      assert::is_false(h_result::succeeded(h_result::COR_E_RANK));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDCOMOBJECT) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(succeeded_with_E_HANDLE) {
      assert::is_false(h_result::succeeded(h_result::E_HANDLE));
    }
    
    void test_method_(succeeded_with_COR_E_INVALIDOPERATION) {
      assert::is_false(h_result::succeeded(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(succeeded_with_STG_E_PATHNOTFOUND) {
      assert::is_false(h_result::succeeded(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(succeeded_with_COR_E_SYSTEM) {
      assert::is_false(h_result::succeeded(h_result::COR_E_SYSTEM));
    }
    
    void test_method_(to_string_with_ERROR_FILE_INVALID) {
      assert::are_equal("ERROR_FILE_INVALID", h_result::to_string(h_result::ERROR_FILE_INVALID));
    }
    
    void test_method_(to_string_with_MSEE_E_ASSEMBLYLOADINPROGRESS) {
      assert::are_equal("MSEE_E_ASSEMBLYLOADINPROGRESS", h_result::to_string(h_result::MSEE_E_ASSEMBLYLOADINPROGRESS));
    }
    
    void test_method_(to_string_with_ERROR_UNRECOGNIZED_VOLUME) {
      assert::are_equal("ERROR_UNRECOGNIZED_VOLUME", h_result::to_string(h_result::ERROR_UNRECOGNIZED_VOLUME));
    }
    
    void test_method_(to_string_with_ERROR_LOCK_VIOLATION) {
      assert::are_equal("ERROR_LOCK_VIOLATION", h_result::to_string(h_result::ERROR_LOCK_VIOLATION));
    }
    
    void test_method_(to_string_with_ERROR_SHARING_VIOLATION) {
      assert::are_equal("ERROR_SHARING_VIOLATION", h_result::to_string(h_result::ERROR_SHARING_VIOLATION));
    }
    
    void test_method_(to_string_with_ERROR_TOO_MANY_OPEN_FILES) {
      assert::are_equal("ERROR_TOO_MANY_OPEN_FILES", h_result::to_string(h_result::ERROR_TOO_MANY_OPEN_FILES));
    }
    
    void test_method_(to_string_with_FUSION_E_REF_DEF_MISMATCH) {
      assert::are_equal("FUSION_E_REF_DEF_MISMATCH", h_result::to_string(h_result::FUSION_E_REF_DEF_MISMATCH));
    }
    
    void test_method_(to_string_with_CTL_E_FILENOTFOUND) {
      assert::are_equal("CTL_E_FILENOTFOUND", h_result::to_string(h_result::CTL_E_FILENOTFOUND));
    }
    
    void test_method_(to_string_with_RPC_E_CHANGED_MODE) {
      assert::are_equal("RPC_E_CHANGED_MODE", h_result::to_string(h_result::RPC_E_CHANGED_MODE));
    }
    
    void test_method_(to_string_with_RO_E_CLOSED) {
      assert::are_equal("RO_E_CLOSED", h_result::to_string(h_result::RO_E_CLOSED));
    }
    
    void test_method_(to_string_with_ERROR_MRM_MAP_NOT_FOUND) {
      assert::are_equal("ERROR_MRM_MAP_NOT_FOUND", h_result::to_string(h_result::ERROR_MRM_MAP_NOT_FOUND));
    }
    
    void test_method_(to_string_with_COR_E_AMBIGUOUSIMPLEMENTATION) {
      assert::are_equal("COR_E_AMBIGUOUSIMPLEMENTATION", h_result::to_string(h_result::COR_E_AMBIGUOUSIMPLEMENTATION));
    }
    
    void test_method_(to_string_with_COR_E_INDEXOUTOFRANGE) {
      assert::are_equal("COR_E_INDEXOUTOFRANGE", h_result::to_string(h_result::COR_E_INDEXOUTOFRANGE));
    }
    
    void test_method_(to_string_with_E_CHANGED_STATE) {
      assert::are_equal("E_CHANGED_STATE", h_result::to_string(h_result::E_CHANGED_STATE));
    }
    
    void test_method_(to_string_with_COR_E_FIELDACCESS) {
      assert::are_equal("COR_E_FIELDACCESS", h_result::to_string(h_result::COR_E_FIELDACCESS));
    }
    
    void test_method_(to_string_with_E_BOUNDS) {
      assert::are_equal("E_BOUNDS", h_result::to_string(h_result::E_BOUNDS));
    }
    
    void test_method_(to_string_with_DISP_E_TYPEMISMATCH) {
      assert::are_equal("DISP_E_TYPEMISMATCH", h_result::to_string(h_result::DISP_E_TYPEMISMATCH));
    }
    
    void test_method_(to_string_with_COR_E_WAITHANDLECANNOTBEOPENED) {
      assert::are_equal("COR_E_WAITHANDLECANNOTBEOPENED", h_result::to_string(h_result::COR_E_WAITHANDLECANNOTBEOPENED));
    }
    
    void test_method_(to_string_with_CTL_E_PATHNOTFOUND) {
      assert::are_equal("CTL_E_PATHNOTFOUND", h_result::to_string(h_result::CTL_E_PATHNOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_VERIFICATION) {
      assert::are_equal("COR_E_VERIFICATION", h_result::to_string(h_result::COR_E_VERIFICATION));
    }
    
    void test_method_(to_string_with_E_POINTER) {
      assert::are_equal("E_POINTER", h_result::to_string(h_result::E_POINTER));
    }
    
    void test_method_(to_string_with_COR_E_THREADSTATE) {
      assert::are_equal("COR_E_THREADSTATE", h_result::to_string(h_result::COR_E_THREADSTATE));
    }
    
    void test_method_(to_string_with_COR_E_THREADSTART) {
      assert::are_equal("COR_E_THREADSTART", h_result::to_string(h_result::COR_E_THREADSTART));
    }
    
    void test_method_(to_string_with_COR_E_ENTRYPOINTNOTFOUND) {
      assert::are_equal("COR_E_ENTRYPOINTNOTFOUND", h_result::to_string(h_result::COR_E_ENTRYPOINTNOTFOUND));
    }
    
    void test_method_(to_string_with_CO_E_NOTINITIALIZED) {
      assert::are_equal("CO_E_NOTINITIALIZED", h_result::to_string(h_result::CO_E_NOTINITIALIZED));
    }
    
    void test_method_(to_string_with_COR_E_THREADINTERRUPTED) {
      assert::are_equal("COR_E_THREADINTERRUPTED", h_result::to_string(h_result::COR_E_THREADINTERRUPTED));
    }
    
    void test_method_(to_string_with_COR_E_THREADABORTED) {
      assert::are_equal("COR_E_THREADABORTED", h_result::to_string(h_result::COR_E_THREADABORTED));
    }
    
    void test_method_(to_string_with_E_UNEXPECTED) {
      assert::are_equal("E_UNEXPECTED", h_result::to_string(h_result::E_UNEXPECTED));
    }
    
    void test_method_(to_string_with_COR_E_SYNCHRONIZATIONLOCK) {
      assert::are_equal("COR_E_SYNCHRONIZATIONLOCK", h_result::to_string(h_result::COR_E_SYNCHRONIZATIONLOCK));
    }
    
    void test_method_(to_string_with_E_FAIL) {
      assert::are_equal("E_FAIL", h_result::to_string(h_result::E_FAIL));
    }
    
    void test_method_(to_string_with_COR_E_TYPELOAD) {
      assert::are_equal("COR_E_TYPELOAD", h_result::to_string(h_result::COR_E_TYPELOAD));
    }
    
    void test_method_(to_string_with_COR_E_STACKOVERFLOW) {
      assert::are_equal("COR_E_STACKOVERFLOW", h_result::to_string(h_result::COR_E_STACKOVERFLOW));
    }
    
    void test_method_(to_string_with_TYPE_E_TYPEMISMATCH) {
      assert::are_equal("TYPE_E_TYPEMISMATCH", h_result::to_string(h_result::TYPE_E_TYPEMISMATCH));
    }
    
    void test_method_(to_string_with_COR_E_SERIALIZATION) {
      assert::are_equal("COR_E_SERIALIZATION", h_result::to_string(h_result::COR_E_SERIALIZATION));
    }
    
    void test_method_(to_string_with_COR_E_SECURITY) {
      assert::are_equal("COR_E_SECURITY", h_result::to_string(h_result::COR_E_SECURITY));
    }
    
    void test_method_(to_string_with_COR_E_SAFEARRAYTYPEMISMATCH) {
      assert::are_equal("COR_E_SAFEARRAYTYPEMISMATCH", h_result::to_string(h_result::COR_E_SAFEARRAYTYPEMISMATCH));
    }
    
    void test_method_(to_string_with_E_ABORT) {
      assert::are_equal("E_ABORT", h_result::to_string(h_result::E_ABORT));
    }
    
    void test_method_(to_string_with_COR_E_SAFEARRAYRANKMISMATCH) {
      assert::are_equal("COR_E_SAFEARRAYRANKMISMATCH", h_result::to_string(h_result::COR_E_SAFEARRAYRANKMISMATCH));
    }
    
    void test_method_(to_string_with_COR_E_INSUFFICIENTMEMORY) {
      assert::are_equal("COR_E_INSUFFICIENTMEMORY", h_result::to_string(h_result::COR_E_INSUFFICIENTMEMORY));
    }
    
    void test_method_(to_string_with_COR_E_REFLECTIONTYPELOAD) {
      assert::are_equal("COR_E_REFLECTIONTYPELOAD", h_result::to_string(h_result::COR_E_REFLECTIONTYPELOAD));
    }
    
    void test_method_(to_string_with_COR_E_PLATFORMNOTSUPPORTED) {
      assert::are_equal("COR_E_PLATFORMNOTSUPPORTED", h_result::to_string(h_result::COR_E_PLATFORMNOTSUPPORTED));
    }
    
    void test_method_(to_string_with_COR_E_PATHTOOLONG) {
      assert::are_equal("COR_E_PATHTOOLONG", h_result::to_string(h_result::COR_E_PATHTOOLONG));
    }
    
    void test_method_(to_string_with_COR_E_APPLICATION) {
      assert::are_equal("COR_E_APPLICATION", h_result::to_string(h_result::COR_E_APPLICATION));
    }
    
    void test_method_(to_string_with_COR_E_OPERATIONCANCELED) {
      assert::are_equal("COR_E_OPERATIONCANCELED", h_result::to_string(h_result::COR_E_OPERATIONCANCELED));
    }
    
    void test_method_(to_string_with_DISP_E_OVERFLOW) {
      assert::are_equal("DISP_E_OVERFLOW", h_result::to_string(h_result::DISP_E_OVERFLOW));
    }
    
    void test_method_(to_string_with_COR_E_OBJECTCLOSED) {
      assert::are_equal("COR_E_OBJECTCLOSED", h_result::to_string(h_result::COR_E_OBJECTCLOSED));
    }
    
    void test_method_(to_string_with_COR_E_NOTSUPPORTED) {
      assert::are_equal("COR_E_NOTSUPPORTED", h_result::to_string(h_result::COR_E_NOTSUPPORTED));
    }
    
    void test_method_(to_string_with_COR_E_NOTFINITENUMBER) {
      assert::are_equal("COR_E_NOTFINITENUMBER", h_result::to_string(h_result::COR_E_NOTFINITENUMBER));
    }
    
    void test_method_(to_string_with_COR_E_MULTICASTNOTSUPPORTED) {
      assert::are_equal("COR_E_MULTICASTNOTSUPPORTED", h_result::to_string(h_result::COR_E_MULTICASTNOTSUPPORTED));
    }
    
    void test_method_(to_string_with_COR_E_MISSINGMETHOD) {
      assert::are_equal("COR_E_MISSINGMETHOD", h_result::to_string(h_result::COR_E_MISSINGMETHOD));
    }
    
    void test_method_(to_string_with_COR_E_MISSINGMEMBER) {
      assert::are_equal("COR_E_MISSINGMEMBER", h_result::to_string(h_result::COR_E_MISSINGMEMBER));
    }
    
    void test_method_(to_string_with_ERROR_DISK_CORRUPT) {
      assert::are_equal("ERROR_DISK_CORRUPT", h_result::to_string(h_result::ERROR_DISK_CORRUPT));
    }
    
    void test_method_(to_string_with_COR_E_OUTOFMEMORY) {
      assert::are_equal("COR_E_OUTOFMEMORY", h_result::to_string(h_result::COR_E_OUTOFMEMORY));
    }
    
    void test_method_(to_string_with_COR_E_MISSINGFIELD) {
      assert::are_equal("COR_E_MISSINGFIELD", h_result::to_string(h_result::COR_E_MISSINGFIELD));
    }
    
    void test_method_(to_string_with_ERROR_TIMEOUT) {
      assert::are_equal("ERROR_TIMEOUT", h_result::to_string(h_result::ERROR_TIMEOUT));
    }
    
    void test_method_(to_string_with_COR_E_METHODACCESS) {
      assert::are_equal("COR_E_METHODACCESS", h_result::to_string(h_result::COR_E_METHODACCESS));
    }
    
    void test_method_(to_string_with_COR_E_ARGUMENT) {
      assert::are_equal("COR_E_ARGUMENT", h_result::to_string(h_result::COR_E_ARGUMENT));
    }
    
    void test_method_(to_string_with_COR_E_OVERFLOW) {
      assert::are_equal("COR_E_OVERFLOW", h_result::to_string(h_result::COR_E_OVERFLOW));
    }
    
    void test_method_(to_string_with_COR_E_APPDOMAINUNLOADED) {
      assert::are_equal("COR_E_APPDOMAINUNLOADED", h_result::to_string(h_result::COR_E_APPDOMAINUNLOADED));
    }
    
    void test_method_(to_string_with_COR_E_KEYNOTFOUND) {
      assert::are_equal("COR_E_KEYNOTFOUND", h_result::to_string(h_result::COR_E_KEYNOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDPROGRAM) {
      assert::are_equal("COR_E_INVALIDPROGRAM", h_result::to_string(h_result::COR_E_INVALIDPROGRAM));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDFILTERCRITERIA) {
      assert::are_equal("COR_E_INVALIDFILTERCRITERIA", h_result::to_string(h_result::COR_E_INVALIDFILTERCRITERIA));
    }
    
    void test_method_(to_string_with_COR_E_MISSINGSATELLITEASSEMBLY) {
      assert::are_equal("COR_E_MISSINGSATELLITEASSEMBLY", h_result::to_string(h_result::COR_E_MISSINGSATELLITEASSEMBLY));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDCAST) {
      assert::are_equal("COR_E_INVALIDCAST", h_result::to_string(h_result::COR_E_INVALIDCAST));
    }
    
    void test_method_(to_string_with_COR_E_UNAUTHORIZEDACCESS) {
      assert::are_equal("COR_E_UNAUTHORIZEDACCESS", h_result::to_string(h_result::COR_E_UNAUTHORIZEDACCESS));
    }
    
    void test_method_(to_string_with_COR_E_FORMAT) {
      assert::are_equal("COR_E_FORMAT", h_result::to_string(h_result::COR_E_FORMAT));
    }
    
    void test_method_(to_string_with_COR_E_FILELOAD) {
      assert::are_equal("COR_E_FILELOAD", h_result::to_string(h_result::COR_E_FILELOAD));
    }
    
    void test_method_(to_string_with_COR_E_DIVIDEBYZERO) {
      assert::are_equal("COR_E_DIVIDEBYZERO", h_result::to_string(h_result::COR_E_DIVIDEBYZERO));
    }
    
    void test_method_(to_string_with_COR_E_TYPEUNLOADED) {
      assert::are_equal("COR_E_TYPEUNLOADED", h_result::to_string(h_result::COR_E_TYPEUNLOADED));
    }
    
    void test_method_(to_string_with_COR_E_FAILFAST) {
      assert::are_equal("COR_E_FAILFAST", h_result::to_string(h_result::COR_E_FAILFAST));
    }
    
    void test_method_(to_string_with_COR_E_EXCEPTION) {
      assert::are_equal("COR_E_EXCEPTION", h_result::to_string(h_result::COR_E_EXCEPTION));
    }
    
    void test_method_(to_string_with_COR_E_DLLNOTFOUND) {
      assert::are_equal("COR_E_DLLNOTFOUND", h_result::to_string(h_result::COR_E_DLLNOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_EXECUTIONENGINE) {
      assert::are_equal("COR_E_EXECUTIONENGINE", h_result::to_string(h_result::COR_E_EXECUTIONENGINE));
    }
    
    void test_method_(to_string_with_COR_E_DIRECTORYNOTFOUND) {
      assert::are_equal("COR_E_DIRECTORYNOTFOUND", h_result::to_string(h_result::COR_E_DIRECTORYNOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_CONTEXTMARSHAL) {
      assert::are_equal("COR_E_CONTEXTMARSHAL", h_result::to_string(h_result::COR_E_CONTEXTMARSHAL));
    }
    
    void test_method_(to_string_with_COR_E_ARGUMENTOUTOFRANGE) {
      assert::are_equal("COR_E_ARGUMENTOUTOFRANGE", h_result::to_string(h_result::COR_E_ARGUMENTOUTOFRANGE));
    }
    
    void test_method_(to_string_with_COR_E_AMBIGUOUSMATCH) {
      assert::are_equal("COR_E_AMBIGUOUSMATCH", h_result::to_string(h_result::COR_E_AMBIGUOUSMATCH));
    }
    
    void test_method_(to_string_with_COR_E_DRIVENOTFOUND) {
      assert::are_equal("COR_E_DRIVENOTFOUND", h_result::to_string(h_result::COR_E_DRIVENOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_BADEXEFORMAT) {
      assert::are_equal("COR_E_BADEXEFORMAT", h_result::to_string(h_result::COR_E_BADEXEFORMAT));
    }
    
    void test_method_(to_string_with_COR_E_INSUFFICIENTEXECUTIONSTACK) {
      assert::are_equal("COR_E_INSUFFICIENTEXECUTIONSTACK", h_result::to_string(h_result::COR_E_INSUFFICIENTEXECUTIONSTACK));
    }
    
    void test_method_(to_string_with_COR_E_CANNOTUNLOADAPPDOMAIN) {
      assert::are_equal("COR_E_CANNOTUNLOADAPPDOMAIN", h_result::to_string(h_result::COR_E_CANNOTUNLOADAPPDOMAIN));
    }
    
    void test_method_(to_string_with_COR_E_TARGETINVOCATION) {
      assert::are_equal("COR_E_TARGETINVOCATION", h_result::to_string(h_result::COR_E_TARGETINVOCATION));
    }
    
    void test_method_(to_string_with_COR_E_CODECONTRACTFAILED) {
      assert::are_equal("COR_E_CODECONTRACTFAILED", h_result::to_string(h_result::COR_E_CODECONTRACTFAILED));
    }
    
    void test_method_(to_string_with_S_OK) {
      assert::are_equal("S_OK", h_result::to_string(h_result::S_OK));
    }
    
    void test_method_(to_string_with_COR_E_BADIMAGEFORMAT) {
      assert::are_equal("COR_E_BADIMAGEFORMAT", h_result::to_string(h_result::COR_E_BADIMAGEFORMAT));
    }
    
    void test_method_(to_string_with_COR_E_TYPEACCESS) {
      assert::are_equal("COR_E_TYPEACCESS", h_result::to_string(h_result::COR_E_TYPEACCESS));
    }
    
    void test_method_(to_string_with_DISP_E_PARAMNOTFOUND) {
      assert::are_equal("DISP_E_PARAMNOTFOUND", h_result::to_string(h_result::DISP_E_PARAMNOTFOUND));
    }
    
    void test_method_(to_string_with_FUSION_E_INVALID_NAME) {
      assert::are_equal("FUSION_E_INVALID_NAME", h_result::to_string(h_result::FUSION_E_INVALID_NAME));
    }
    
    void test_method_(to_string_with_COR_E_ENDOFSTREAM) {
      assert::are_equal("COR_E_ENDOFSTREAM", h_result::to_string(h_result::COR_E_ENDOFSTREAM));
    }
    
    void test_method_(to_string_with_COR_E_DUPLICATEWAITOBJECT) {
      assert::are_equal("COR_E_DUPLICATEWAITOBJECT", h_result::to_string(h_result::COR_E_DUPLICATEWAITOBJECT));
    }
    
    void test_method_(to_string_with_COR_E_RUNTIMEWRAPPED) {
      assert::are_equal("COR_E_RUNTIMEWRAPPED", h_result::to_string(h_result::COR_E_RUNTIMEWRAPPED));
    }
    
    void test_method_(to_string_with_COR_E_TARGET) {
      assert::are_equal("COR_E_TARGET", h_result::to_string(h_result::COR_E_TARGET));
    }
    
    void test_method_(to_string_with_COR_E_DATAMISALIGNED) {
      assert::are_equal("COR_E_DATAMISALIGNED", h_result::to_string(h_result::COR_E_DATAMISALIGNED));
    }
    
    void test_method_(to_string_with_COR_E_TYPEINITIALIZATION) {
      assert::are_equal("COR_E_TYPEINITIALIZATION", h_result::to_string(h_result::COR_E_TYPEINITIALIZATION));
    }
    
    void test_method_(to_string_with_COR_E_ARITHMETIC) {
      assert::are_equal("COR_E_ARITHMETIC", h_result::to_string(h_result::COR_E_ARITHMETIC));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDOLEVARIANTTYPE) {
      assert::are_equal("COR_E_INVALIDOLEVARIANTTYPE", h_result::to_string(h_result::COR_E_INVALIDOLEVARIANTTYPE));
    }
    
    void test_method_(to_string_with_COR_E_MISSINGMANIFESTRESOURCE) {
      assert::are_equal("COR_E_MISSINGMANIFESTRESOURCE", h_result::to_string(h_result::COR_E_MISSINGMANIFESTRESOURCE));
    }
    
    void test_method_(to_string_with_COR_E_TIMEOUT) {
      assert::are_equal("COR_E_TIMEOUT", h_result::to_string(h_result::COR_E_TIMEOUT));
    }
    
    void test_method_(to_string_with_COR_E_FILENOTFOUND) {
      assert::are_equal("COR_E_FILENOTFOUND", h_result::to_string(h_result::COR_E_FILENOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_TARGETPARAMCOUNT) {
      assert::are_equal("COR_E_TARGETPARAMCOUNT", h_result::to_string(h_result::COR_E_TARGETPARAMCOUNT));
    }
    
    void test_method_(to_string_with_COR_E_ARRAYTYPEMISMATCH) {
      assert::are_equal("COR_E_ARRAYTYPEMISMATCH", h_result::to_string(h_result::COR_E_ARRAYTYPEMISMATCH));
    }
    
    void test_method_(to_string_with_E_NOTIMPL) {
      assert::are_equal("E_NOTIMPL", h_result::to_string(h_result::E_NOTIMPL));
    }
    
    void test_method_(to_string_with_COR_E_MARSHALDIRECTIVE) {
      assert::are_equal("COR_E_MARSHALDIRECTIVE", h_result::to_string(h_result::COR_E_MARSHALDIRECTIVE));
    }
    
    void test_method_(to_string_with_DISP_E_BADVARTYPE) {
      assert::are_equal("DISP_E_BADVARTYPE", h_result::to_string(h_result::DISP_E_BADVARTYPE));
    }
    
    void test_method_(to_string_with_COR_E_IO) {
      assert::are_equal("COR_E_IO", h_result::to_string(h_result::COR_E_IO));
    }
    
    void test_method_(to_string_with_ERROR_OPEN_FAILED) {
      assert::are_equal("ERROR_OPEN_FAILED", h_result::to_string(h_result::ERROR_OPEN_FAILED));
    }
    
    void test_method_(to_string_with_COR_E_ABANDONEDMUTEX) {
      assert::are_equal("COR_E_ABANDONEDMUTEX", h_result::to_string(h_result::COR_E_ABANDONEDMUTEX));
    }
    
    void test_method_(to_string_with_ERROR_DLL_INIT_FAILED) {
      assert::are_equal("ERROR_DLL_INIT_FAILED", h_result::to_string(h_result::ERROR_DLL_INIT_FAILED));
    }
    
    void test_method_(to_string_with_COR_E_CUSTOMATTRIBUTEFORMAT) {
      assert::are_equal("COR_E_CUSTOMATTRIBUTEFORMAT", h_result::to_string(h_result::COR_E_CUSTOMATTRIBUTEFORMAT));
    }
    
    void test_method_(to_string_with_S_FALSE) {
      assert::are_equal("S_FALSE", h_result::to_string(h_result::S_FALSE));
    }
    
    void test_method_(to_string_with_COR_E_MEMBERACCESS) {
      assert::are_equal("COR_E_MEMBERACCESS", h_result::to_string(h_result::COR_E_MEMBERACCESS));
    }
    
    void test_method_(to_string_with_COR_E_RANK) {
      assert::are_equal("COR_E_RANK", h_result::to_string(h_result::COR_E_RANK));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDCOMOBJECT) {
      assert::are_equal("COR_E_INVALIDCOMOBJECT", h_result::to_string(h_result::COR_E_INVALIDCOMOBJECT));
    }
    
    void test_method_(to_string_with_E_HANDLE) {
      assert::are_equal("E_HANDLE", h_result::to_string(h_result::E_HANDLE));
    }
    
    void test_method_(to_string_with_COR_E_INVALIDOPERATION) {
      assert::are_equal("COR_E_INVALIDOPERATION", h_result::to_string(h_result::COR_E_INVALIDOPERATION));
    }
    
    void test_method_(to_string_with_STG_E_PATHNOTFOUND) {
      assert::are_equal("STG_E_PATHNOTFOUND", h_result::to_string(h_result::STG_E_PATHNOTFOUND));
    }
    
    void test_method_(to_string_with_COR_E_SYSTEM) {
      assert::are_equal("COR_E_SYSTEM", h_result::to_string(h_result::COR_E_SYSTEM));
    }
  };
}
