#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Group box and check box example");
    client_size({300, 160});
    
    group_box1.parent(*this);
    group_box1.bounds({10, 10, 135, 140});
    group_box1.text("Group 1");
    
    group_box2.parent(*this);
    group_box2.bounds({155, 10, 135, 140});
    group_box2.text("Group 2");
  }
  
private:
  group_box group_box1;
  group_box group_box2;
};

int main() {
  application::run(form1());
}
