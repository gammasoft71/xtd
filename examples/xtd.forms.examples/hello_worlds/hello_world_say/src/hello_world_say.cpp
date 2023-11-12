#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/speech/synthesis/speech_synthesizer>

using namespace xtd;
using namespace xtd::forms;
using namespace xtd::speech::synthesis;

class form1 : public form {
public:
  form1() {
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += [&] {
      speech_synthesizer1.speak_async("Hello, world!");
    };
  }
  
private:
  button button1;
  speech_synthesizer speech_synthesizer1;
};

auto main()->int {
  application::run(form1 {});
}
