#include <xtd/distribution>
#include <xtd/tunit/assert>
#include <xtd/tunit/collection_assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(distribution_tests) {
    void test_method_(default_ctor) {
      auto d = distribution {};
      assert::are_equal(uri {}, d.bug_repport());
      assert::is_empty(d.code_name());
      assert::is_empty(d.description());
      assert::are_equal(uri {}, d.home());
      assert::is_empty(d.id());
      collection_assert::is_empty(d.like_ids());
      assert::is_empty(d.name());
      assert::are_equal(version {}, d.version());
      assert::is_empty(d.version_string());
      assert::is_empty(d.to_string());
    }
    
    void test_method_(ctor_with_params) {
      auto d = distribution {"macOS", version {12, 6, 5}, "Monterey", "Apple macOS 12.6.5 (Monterey)", "macos", {"macos", "osx"}, "12.6.5 (Monterey)", uri {"https://www.apple.com/macos"}, uri {"https://support.apple.com/macos"}};
      assert::are_equal(uri {"https://support.apple.com/macos"}, d.bug_repport());
      assert::are_equal("Monterey", d.code_name());
      assert::are_equal("Apple macOS 12.6.5 (Monterey)", d.description());
      assert::are_equal(uri {"https://www.apple.com/macos"}, d.home());
      assert::are_equal("macos", d.id());
      collection_assert::are_equal({"macos", "osx"}, d.like_ids());
      assert::are_equal("macOS", d.name());
      assert::are_equal(version {12, 6, 5}, d.version());
      assert::are_equal("12.6.5 (Monterey)", d.version_string());
      assert::are_equal("Apple macOS 12.6.5 (Monterey)", d.to_string());
    }
  };
}
