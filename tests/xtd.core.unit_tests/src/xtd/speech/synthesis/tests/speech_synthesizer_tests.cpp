#include <xtd/speech/synthesis/speech_synthesizer>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::speech::synthesis;
using namespace xtd::tunit;

namespace xtd::speech::synthesis::tests {
  class test_class_(speech_synthesizer_tests) {
    auto test_method_(create) {
      auto speech = speech_synthesizer {};
      assert::are_equal("xtd::speech::synthesis::speech_synthesizer", speech.to_string());
    }
    
    auto test_method_(state) {
      auto s = speech_synthesizer {};
      assert::are_equal(synthesizer_state::ready, s.state());
      s.speak("");
      assert::are_equal(synthesizer_state::ready, s.state());
    }
    
    auto test_method_(speak_with_prompt) {
      auto s = speech_synthesizer {};
      auto p = prompt("");
      assert::is_false(p.is_completed());
      s.speak(p);
      assert::is_true(p.is_completed());
    }
    
    auto test_method_(speak_with_string) {
      assert::does_not_throw([] {speech_synthesizer {}.speak("");});
    }
    
    auto test_method_(speak_async_with_prompt) {
      auto s = speech_synthesizer {};
      auto p = prompt("");
      s.speak_async(p);
      assert::is_true(p.is_completed());
    }
    
    auto test_method_(speak_async_with_string) {
      auto s = speech_synthesizer {};
      auto p = s.speak_async("");
      assert::is_true(p.is_completed());
    }
    
    auto test_method_(speak_completed) {
      auto has_completed_event = false;
      auto s = speech_synthesizer {};
      auto p = prompt("");
      
      s.speak_completed += [&](object & sender, const speak_completed_event_args & e) {
        assert::is_false(e.cancelled());
        assert::is_false(e.error().has_value());
        assert::are_same(p, e.prompt());
        assert::is_true(e.prompt().is_completed());
        assert::is_false(e.user_state().has_value());
        has_completed_event = true;
      };
      
      s.speak(p);
      assert::is_true(has_completed_event);
    }
    
    auto test_method_(speak_started) {
      auto has_started_event = false;
      auto s = speech_synthesizer {};
      auto p = prompt("");
      
      s.speak_started += [&](object & sender, const speak_started_event_args & e) {
        assert::is_false(e.cancelled());
        assert::is_false(e.error().has_value());
        assert::are_same(p, e.prompt());
        assert::is_false(e.prompt().is_completed());
        assert::is_false(e.user_state().has_value());
        has_started_event = true;
      };
      s.speak(p);
      assert::is_true(has_started_event);
    }
    
    auto test_method_(state_changed) {
      auto state_changed_event_value = 0;
      auto s = speech_synthesizer {};
      auto p = prompt("");
      
      s.state_changed += [&](object & sender, const state_changed_event_args & e) {
        if (state_changed_event_value == 0) {
          assert::are_equal(synthesizer_state::ready, e.previous_state());
          assert::are_equal(synthesizer_state::speaking, e.state());
        } else if (state_changed_event_value == 1) {
          assert::are_equal(synthesizer_state::speaking, e.previous_state());
          assert::are_equal(synthesizer_state::ready, e.state());
        }
        ++state_changed_event_value;
      };
      s.speak(p);
      assert::are_equal(2, state_changed_event_value);
    }
  };
}
