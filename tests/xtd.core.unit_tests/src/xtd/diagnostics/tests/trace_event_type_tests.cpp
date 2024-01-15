#include <xtd/diagnostics/trace_event_type>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(trace_event_type_tests) {
    void test_method_(critical) {
      assert::are_equal(1, enum_object<>::to_int32(trace_event_type::critical), csf_);
      assert::are_equal("critical", enum_object<>::to_string(trace_event_type::critical), csf_);
      assert::are_equal(trace_event_type::critical, enum_object<>::parse<trace_event_type>("critical"), csf_);
    }
    
    void test_method_(error) {
      assert::are_equal(2, enum_object<>::to_int32(trace_event_type::error), csf_);
      assert::are_equal("error", enum_object<>::to_string(trace_event_type::error), csf_);
      assert::are_equal(trace_event_type::error, enum_object<>::parse<trace_event_type>("error"), csf_);
    }
    
    void test_method_(information) {
      assert::are_equal(8, enum_object<>::to_int32(trace_event_type::information), csf_);
      assert::are_equal("information", enum_object<>::to_string(trace_event_type::information), csf_);
      assert::are_equal(trace_event_type::information, enum_object<>::parse<trace_event_type>("information"), csf_);
    }
    
    void test_method_(resume) {
      assert::are_equal(2048, enum_object<>::to_int32(trace_event_type::resume), csf_);
      assert::are_equal("resume", enum_object<>::to_string(trace_event_type::resume), csf_);
      assert::are_equal(trace_event_type::resume, enum_object<>::parse<trace_event_type>("resume"), csf_);
    }
    
    void test_method_(start) {
      assert::are_equal(256, enum_object<>::to_int32(trace_event_type::start), csf_);
      assert::are_equal("start", enum_object<>::to_string(trace_event_type::start), csf_);
      assert::are_equal(trace_event_type::start, enum_object<>::parse<trace_event_type>("start"), csf_);
    }
    
    void test_method_(stop) {
      assert::are_equal(512, enum_object<>::to_int32(trace_event_type::stop), csf_);
      assert::are_equal("stop", enum_object<>::to_string(trace_event_type::stop), csf_);
      assert::are_equal(trace_event_type::stop, enum_object<>::parse<trace_event_type>("stop"), csf_);
    }
    
    void test_method_(suspend) {
      assert::are_equal(1024, enum_object<>::to_int32(trace_event_type::suspend), csf_);
      assert::are_equal("suspend", enum_object<>::to_string(trace_event_type::suspend), csf_);
      assert::are_equal(trace_event_type::suspend, enum_object<>::parse<trace_event_type>("suspend"), csf_);
    }
    
    void test_method_(transfer) {
      assert::are_equal(4096, enum_object<>::to_int32(trace_event_type::transfer), csf_);
      assert::are_equal("transfer", enum_object<>::to_string(trace_event_type::transfer), csf_);
      assert::are_equal(trace_event_type::transfer, enum_object<>::parse<trace_event_type>("transfer"), csf_);
    }
    
    void test_method_(verbose) {
      assert::are_equal(16, enum_object<>::to_int32(trace_event_type::verbose), csf_);
      assert::are_equal("verbose", enum_object<>::to_string(trace_event_type::verbose), csf_);
      assert::are_equal(trace_event_type::verbose, enum_object<>::parse<trace_event_type>("verbose"), csf_);
    }
    
    void test_method_(warning) {
      assert::are_equal(4, enum_object<>::to_int32(trace_event_type::warning), csf_);
      assert::are_equal("warning", enum_object<>::to_string(trace_event_type::warning), csf_);
      assert::are_equal(trace_event_type::warning, enum_object<>::parse<trace_event_type>("warning"), csf_);
    }
  };
}
