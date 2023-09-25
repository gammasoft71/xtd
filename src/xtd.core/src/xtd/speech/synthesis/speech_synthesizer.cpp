#include "../../../../include/xtd/speech/synthesis/speech_synthesizer"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/speech_synthesizer>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <functional>

using namespace std;
using namespace xtd;
using namespace xtd::speech::synthesis;

struct speech_synthesizer::data {
  intptr handle = 0;
  int32 rate = 0;
  synthesizer_state state = synthesizer_state::ready;
  int32 volume = 100;
  xtd::speech::synthesis::prompt prompt;
  xtd::speech::synthesis::prompt* used_prompt = &prompt;
};

speech_synthesizer::speech_synthesizer() : data_(std::make_shared<data>()) {
  data_->handle = native::speech_synthesizer::create();
}

speech_synthesizer::~speech_synthesizer() {
  native::speech_synthesizer::destroy(data_->handle);
}

synthesizer_state speech_synthesizer::state() const noexcept {
  return data_->state;
}

void speech_synthesizer::speak(const ustring& text_to_speak) {
  data_->used_prompt = &data_->prompt;
  data_->used_prompt->text_to_speak() = text_to_speak;
  speak(*data_->used_prompt);
}

void speech_synthesizer::speak(xtd::speech::synthesis::prompt& prompt) {
  data_->used_prompt = &prompt;
  on_speak_started();
  native::speech_synthesizer::speak(data_->handle, data_->used_prompt->text_to_speak());
  data_->used_prompt->synthesizer(this);
  on_speak_completed();
}

xtd::speech::synthesis::prompt& speech_synthesizer::speak_async(const ustring& text_to_speak) {
  data_->used_prompt = &data_->prompt;
  data_->used_prompt->text_to_speak() = text_to_speak;
  speak_async(*data_->used_prompt);
  return *data_->used_prompt;
}

void speech_synthesizer::speak_async(xtd::speech::synthesis::prompt& prompt) {
  data_->used_prompt = &prompt;
  on_speak_started();
  native::speech_synthesizer::speak_async(data_->handle, data_->used_prompt->text_to_speak(), bind(&speech_synthesizer::on_speak_completed, this));
  data_->used_prompt->synthesizer(this);
}

void speech_synthesizer::on_speak_completed() {
  set_state(synthesizer_state::ready);
  speak_completed(*this, {false, nullptr, data_->used_prompt});
}

void speech_synthesizer::on_speak_started() {
  set_state(synthesizer_state::speaking);
  speak_started(*this, {false, nullptr, data_->used_prompt});
}

void speech_synthesizer::set_state(synthesizer_state value) {
  if (data_->state != value) {
    auto previous_state = data_->state;
    data_->state = value;
    state_changed(*this, {previous_state, data_->state});
  }
}
