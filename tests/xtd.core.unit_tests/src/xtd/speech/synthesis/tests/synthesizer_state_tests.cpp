#include <xtd/speech/synthesis/synthesizer_state>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::speech::synthesis;
using namespace xtd::tunit;

namespace xtd::speech::synthesis::tests {
  class test_class_(synthesizer_state_tests) {
    auto test_method_(ready) {
      assert::are_equal(0, enum_object<>::to_int32(synthesizer_state::ready));
      assert::are_equal("ready", enum_object<>::to_string(synthesizer_state::ready));
      assert::are_equal(synthesizer_state::ready, enum_object<>::parse<synthesizer_state>("ready"));
    }
    
    auto test_method_(speaking) {
      assert::are_equal(1, enum_object<>::to_int32(synthesizer_state::speaking));
      assert::are_equal("speaking", enum_object<>::to_string(synthesizer_state::speaking));
      assert::are_equal(synthesizer_state::speaking, enum_object<>::parse<synthesizer_state>("speaking"));
    }
    
    auto test_method_(pause) {
      assert::are_equal(2, enum_object<>::to_int32(synthesizer_state::pause));
      assert::are_equal("pause", enum_object<>::to_string(synthesizer_state::pause));
      assert::are_equal(synthesizer_state::pause, enum_object<>::parse<synthesizer_state>("pause"));
    }
  };
}
