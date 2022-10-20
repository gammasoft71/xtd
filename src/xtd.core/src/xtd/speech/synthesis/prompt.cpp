#include "../../../../include/xtd/speech/synthesis/prompt.h"
#include "../../../../include/xtd/speech/synthesis/speech_synthesizer.h"

using namespace xtd;
using namespace xtd::speech::synthesis;

prompt::prompt(const ustring& text_to_speak) {
  data_->text_to_speak = text_to_speak;
}

bool prompt::is_completed() const {
  return !data_->synthesizer ? true : data_->synthesizer->state() == synthesizer_state::ready;
}
