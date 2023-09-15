#include <xtd/threading/thread_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/string_assert>
#include <xtd/tunit/test_class_attribute>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(thread_state_tests) {
  public:
    void test_method_(running) {
      assert::are_equal(0, enum_object<>::to_int32(thread_state::running), csf_);
      assert::are_equal("running", enum_object<>::to_string(thread_state::running), csf_);
      assert::are_equal(thread_state::running, enum_object<>::parse<thread_state>("running"), csf_);
    }
    
    void test_method_(stop_requested) {
      assert::are_equal(1, enum_object<>::to_int32(thread_state::stop_requested), csf_);
      assert::are_equal("stop_requested", enum_object<>::to_string(thread_state::stop_requested), csf_);
      assert::are_equal(thread_state::stop_requested, enum_object<>::parse<thread_state>("stop_requested"), csf_);
    }
    
    void test_method_(suspend_requested) {
      assert::are_equal(2, enum_object<>::to_int32(thread_state::suspend_requested), csf_);
      assert::are_equal("suspend_requested", enum_object<>::to_string(thread_state::suspend_requested), csf_);
      assert::are_equal(thread_state::suspend_requested, enum_object<>::parse<thread_state>("suspend_requested"), csf_);
    }
    
    void test_method_(background) {
      assert::are_equal(4, enum_object<>::to_int32(thread_state::background), csf_);
      assert::are_equal("background", enum_object<>::to_string(thread_state::background), csf_);
      assert::are_equal(thread_state::background, enum_object<>::parse<thread_state>("background"), csf_);
    }
    
    void test_method_(unstarted) {
      assert::are_equal(8, enum_object<>::to_int32(thread_state::unstarted), csf_);
      assert::are_equal("unstarted", enum_object<>::to_string(thread_state::unstarted), csf_);
      assert::are_equal(thread_state::unstarted, enum_object<>::parse<thread_state>("unstarted"), csf_);
    }
    
    void test_method_(stopped) {
      assert::are_equal(16, enum_object<>::to_int32(thread_state::stopped), csf_);
      assert::are_equal("stopped", enum_object<>::to_string(thread_state::stopped), csf_);
      assert::are_equal(thread_state::stopped, enum_object<>::parse<thread_state>("stopped"), csf_);
    }
    
    void test_method_(wait_sleep_join) {
      assert::are_equal(32, enum_object<>::to_int32(thread_state::wait_sleep_join), csf_);
      assert::are_equal("wait_sleep_join", enum_object<>::to_string(thread_state::wait_sleep_join), csf_);
      assert::are_equal(thread_state::wait_sleep_join, enum_object<>::parse<thread_state>("wait_sleep_join"), csf_);
    }
    
    void test_method_(suspended) {
      assert::are_equal(64, enum_object<>::to_int32(thread_state::suspended), csf_);
      assert::are_equal("suspended", enum_object<>::to_string(thread_state::suspended), csf_);
      assert::are_equal(thread_state::suspended, enum_object<>::parse<thread_state>("suspended"), csf_);
    }
    
    void test_method_(abort_requested) {
      assert::are_equal(128, enum_object<>::to_int32(thread_state::abort_requested), csf_);
      assert::are_equal("abort_requested", enum_object<>::to_string(thread_state::abort_requested), csf_);
      assert::are_equal(thread_state::abort_requested, enum_object<>::parse<thread_state>("abort_requested"), csf_);
    }
    
    void test_method_(aborted) {
      assert::are_equal(256, enum_object<>::to_int32(thread_state::aborted), csf_);
      assert::are_equal("aborted", enum_object<>::to_string(thread_state::aborted), csf_);
      assert::are_equal(thread_state::aborted, enum_object<>::parse<thread_state>("aborted"), csf_);
    }
  };
}

