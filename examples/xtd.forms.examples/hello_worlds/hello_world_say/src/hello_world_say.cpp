#include <xtd/xtd>

class form1 : public form {
public:
  form1() {
    text("Hello world (say)");
    
    button1.location({10, 10});
    button1.parent(*this);
    button1.text("Say...");
    button1.click += delegate_ {
      speech_synthesizer1.speak_async("Hello, World!");
    };
  }
  
private:
  button button1;
  speech::synthesis::speech_synthesizer speech_synthesizer1;
};

auto main() -> int {
  application::run(form1 {});
}
