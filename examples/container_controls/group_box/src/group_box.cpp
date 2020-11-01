#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

class form1 : public form {
public:
  form1() {
    text("Group box example");
    location({200, 200});
    client_size({640, 480});
    
    group_box1.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom);
    group_box1.parent(*this);
    group_box1.location({10, 10});
    group_box1.size({305, 460});
    group_box1.text("Group box 1");

    group_box2.anchor(anchor_styles::top | anchor_styles::left | anchor_styles::bottom | anchor_styles::right);
    group_box2.parent(*this);
    group_box2.location({325, 10});
    group_box2.size({305, 460});
  }
  
private:
  group_box group_box1;
  group_box group_box2;
};

int main() {
  application::run(form1());
}
