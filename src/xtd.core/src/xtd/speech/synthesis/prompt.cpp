#include "../../../../include/xtd/speech/synthesis/prompt.h"

using namespace xtd;
using namespace xtd::speech::synthesis;

prompt::prompt(const ustring& text_to_speak) {
  data_->text_to_speak = text_to_speak;
}
