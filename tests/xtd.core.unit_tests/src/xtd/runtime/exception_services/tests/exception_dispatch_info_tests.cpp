#include <xtd/runtime/exception_services/exception_dispatch_info>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::tunit;

namespace xtd::runtime::exception_services::tests {
  class test_class_(exception_dispatch_info_tests) {
    void test_method_(default_constructor) {
      assert::is_false(exception_dispatch_info {} ? true : false, csf_);
      assert::is_false(exception_dispatch_info {}.exception_captured(), csf_);
      assert::is_null(exception_dispatch_info {}.source_exception(), csf_);
    }
    
    void test_method_(exception_captured) {
      assert::is_false(exception_dispatch_info {}.exception_captured(), csf_);
      assert::is_true(exception_dispatch_info::capture(exception {csf_}).exception_captured(), csf_);
    }
    
    void test_method_(source_exception) {
      auto edi = exception_dispatch_info::capture(argument_out_of_range_exception {"The first index is out of range", csf_});
      assert::is_not_null(edi.source_exception(), csf_);
      assert::are_equal("The first index is out of range", edi.source_exception()->message(), csf_);
      assert::are_equal(typeof_<argument_out_of_range_exception>(), typeof_(*edi.source_exception()), csf_);
    }
    
    void test_method_(rethrow) {
      auto edi = exception_dispatch_info::capture(argument_out_of_range_exception {"The first index is out of range", csf_});
      try {
        edi.rethrow();
      } catch (const argument_out_of_range_exception& e) {
        assert::are_equal("The first index is out of range", e.message(), csf_);
      } catch (...) {
        assert::fail(csf_);
      }
    }
    
    void test_method_(rethrow_with_exception) {
      try {
        exception_dispatch_info::rethrow(argument_out_of_range_exception {"The first index is out of range", csf_});
      } catch (const argument_out_of_range_exception& e) {
        assert::are_equal("The first index is out of range", e.message(), csf_);
      } catch (...) {
        assert::fail(csf_);
      }
    }

    void test_method_(convert_to_bool_operator) {
      assert::is_false(exception_dispatch_info {} ? true : false, csf_);
      assert::is_true(exception_dispatch_info::capture(exception {csf_}) ? true : false, csf_);
    }
  };
}
