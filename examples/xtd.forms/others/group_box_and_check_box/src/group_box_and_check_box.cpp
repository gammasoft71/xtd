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
    
    check_box1.location({20, 10});
    check_box1.parent(group_box1);
    check_box1.text("check 1");
    
    check_box2.checked(true);
    check_box2.location({20, 40});
    check_box2.parent(group_box1);
    check_box2.text("check 2");

    check_box3.location({20, 70});
    check_box3.parent(group_box1);
    check_box3.text("check 3");

    check_box4.location({20, 10});
    check_box4.parent(group_box2);
    check_box4.text("check 4");

    check_box5.location({20, 40});
    check_box5.parent(group_box2);
    check_box5.text("check 5");

    check_box6.checked(true);
    check_box6.location({20, 70});
    check_box6.parent(group_box2);
    check_box6.text("check 6");
  }
  
private:
  group_box group_box1;
  group_box group_box2;
  
  check_box check_box1;
  check_box check_box2;
  check_box check_box3;
  check_box check_box4;
  check_box check_box5;
  check_box check_box6;
};

int main() {
  application::run(form1());
}
