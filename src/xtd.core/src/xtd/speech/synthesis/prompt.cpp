#include "../../../../include/xtd/speech/synthesis/prompt.hpp"
#include "../../../../include/xtd/speech/synthesis/speech_synthesizer.hpp"

using namespace xtd;
using namespace xtd::speech::synthesis;

struct prompt::data {
  string text_to_speak;
  const speech_synthesizer* synthesizer = nullptr;
};

prompt::prompt() : prompt(string::empty_string) {
}

prompt::prompt(const string& text_to_speak) : data_(xtd::new_sptr<data>()) {
  data_->text_to_speak = text_to_speak;
}

auto prompt::is_completed() const noexcept -> bool {
  return !data_->synthesizer ? false : data_->synthesizer->state() == synthesizer_state::ready;
}

auto prompt::text_to_speak() noexcept -> string& {
  return data_->text_to_speak;
}

auto prompt::synthesizer(const speech_synthesizer* synthesizer) noexcept -> void {
  data_->synthesizer = synthesizer;
}
