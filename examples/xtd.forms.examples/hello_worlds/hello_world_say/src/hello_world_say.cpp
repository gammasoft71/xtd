#include <xtd/xtd>

using namespace xtd;
using namespace xtd::speech::synthesis;
using namespace xtd::forms;

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

int main() {
  application::run(form1 {});
}
