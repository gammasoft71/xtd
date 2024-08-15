#include "../../../../include/xtd/speech/synthesis/prompt.h"
#include "../../../../include/xtd/speech/synthesis/speech_synthesizer.h"

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

bool prompt::is_completed() const noexcept {
  return !data_->synthesizer ? true : data_->synthesizer->state() == synthesizer_state::ready;
}

xtd::string& prompt::text_to_speak() noexcept {
  return data_->text_to_speak;
}

void prompt::synthesizer(const speech_synthesizer* synthesizer) noexcept {
  data_->synthesizer = synthesizer;
}
