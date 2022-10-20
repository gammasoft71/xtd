#include <xtd/xtd.core>
#include <xtd/xtd.forms.h>

using namespace std;
using namespace xtd;
using namespace xtd::speech::synthesis;

class xtd_core_manual_test {
public:
  static void main() {
    speech_synthesizer synthesizer;
    synthesizer.speak("Hello, World!");
  }
};

startup_(xtd_core_manual_test);
