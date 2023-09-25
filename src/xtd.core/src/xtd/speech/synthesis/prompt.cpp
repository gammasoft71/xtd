#include "../../../../include/xtd/speech/synthesis/prompt"
#include "../../../../include/xtd/speech/synthesis/speech_synthesizer"

using namespace std;
using namespace xtd;
using namespace xtd::speech::synthesis;

struct prompt::data {
  ustring text_to_speak;
  const speech_synthesizer* synthesizer = nullptr;
};

prompt::prompt() : prompt(ustring::empty_string) {
}

prompt::prompt(const ustring& text_to_speak) : data_(make_shared<data>()) {
  data_->text_to_speak = text_to_speak;
}

bool prompt::is_completed() const noexcept {
  return !data_->synthesizer ? true : data_->synthesizer->state() == synthesizer_state::ready;
}

xtd::ustring& prompt::text_to_speak() noexcept {
  return data_->text_to_speak;
}

void prompt::synthesizer(const speech_synthesizer* synthesizer) noexcept {
  data_->synthesizer = synthesizer;
}
