#include <xtd/xtd.forms>

using namespace std;
using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Switch button example");

    switch_button1.parent(*this);
    switch_button1.location({10, 10});
    //switch_button1.width(100);
    switch_button1.rounded(true);
  }
  
private:
  switch_button switch_button1;
};

int main() {
  application::run(form1());
}
