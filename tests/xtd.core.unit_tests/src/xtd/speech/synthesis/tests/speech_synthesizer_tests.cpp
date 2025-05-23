#include <xtd/speech/synthesis/speech_synthesizer>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::speech::synthesis;
using namespace xtd::tunit;

namespace xtd::speech::synthesis::tests {
  class test_class_(speech_synthesizer_tests) {
    void test_method_(create) {
      auto speech = speech_synthesizer {};
      assert::are_equal("xtd::speech::synthesis::speech_synthesizer", speech.to_string());
    }

    void test_method_(state) {
      assert::are_equal(synthesizer_state::ready, speech_synthesizer {}.state());
    }

    void test_method_(speak_with_prompt) {
      auto p = prompt("");
      assert::does_not_throw([&p] {speech_synthesizer {}.speak(p);});
    }

    void test_method_(speak_with_string) {
      assert::does_not_throw([] {speech_synthesizer {}.speak("");});
    }
  };
}
