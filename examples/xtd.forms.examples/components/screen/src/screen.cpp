#include <xtd/xtd>

using namespace xtd::forms;

int main() {
  xtd::drawing::rectangle area = screen::primary_screen().working_area();
  
  form form1;
  form1.start_position(form_start_position::manual);
  form1.location(area.location());
  form1.size({area.size().width() / 2, area.size().height() / 2});
  form1.text("screen 1/4");
  form1.visible(true);
  
  form form2;
  form2.start_position(form_start_position::manual);
  form2.location({area.location().x() + area.size().width() / 2, area.location().y()});
  form2.size({area.size().width() / 2, area.size().height() / 2});
  form2.text("screen 2/4");
  form2.visible(true);
  
  form form3;
  form3.start_position(form_start_position::manual);
  form3.location({area.location().x(), area.location().y() + area.size().height() / 2});
  form3.size({area.size().width() / 2, area.size().height() / 2});
  form3.text("screen 3/4");
  form3.visible(true);
  
  form form4;
  form4.start_position(form_start_position::manual);
  form4.location({area.location().x() + area.size().width() / 2, area.location().y() + area.size().height() / 2});
  form4.size({area.size().width() / 2, area.size().height() / 2});
  form4.text("screen 4/4");
  form4.visible(true);
  
  application::run(form1);
}
