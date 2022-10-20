#include "../../../../include/xtd/speech/synthesis/speech_synthesizer.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::speech::synthesis;

speech_synthesizer::speech_synthesizer() {
  data_->handle = native::speech_synthesizer::create();
}

speech_synthesizer::~speech_synthesizer() {
  native::speech_synthesizer::destroy(data_->handle);
}

void speech_synthesizer::speak(const ustring& text_to_speak) const {
  native::speech_synthesizer::speak(data_->handle, text_to_speak);
}

void speech_synthesizer::speak(xtd::speech::synthesis::prompt& prompt) const {
  speak(prompt.data_->text_to_speak);
  prompt.data_->is_completed = true;
}

prompt speech_synthesizer::speak_async(const ustring& text_to_speak) const {
  native::speech_synthesizer::speak_async(data_->handle, text_to_speak);
  return prompt {text_to_speak};
}

void speech_synthesizer::speak_async(xtd::speech::synthesis::prompt& prompt) const {
  prompt = speak_async(prompt.data_->text_to_speak);
}
