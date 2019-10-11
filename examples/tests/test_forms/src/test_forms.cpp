#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace std::literals;

int main() {
  form form_main;
  form_main.client_size({1280, 800});
  form_main.text("Demo forms");
  
  tab_control tab_control_main;
  tab_control_main.location({10, 10});
  tab_control_main.parent(form_main);
  tab_control_main.size(form_main.client_size() - size(20, 20));
  
  tab_page tab_page_controls;
  tab_page_controls.parent(tab_control_main);
  tab_page_controls.text("Controls");

  label label1;
  label1.location({10, 10});
  label1.parent(tab_page_controls);
  label1.text("label");
  
  tab_page tab_page_pickers;
  tab_page_pickers.parent(tab_control_main);
  tab_page_pickers.text("Pickers");
  
  tab_page tab_page_containers;
  tab_page_containers.parent(tab_control_main);
  tab_page_containers.text("Containers");
  
  group_box group_box1;
  group_box1.location({10, 10});
  group_box1.parent(tab_page_containers);
  group_box1.text("group_box");
  
  panel panel1;
  panel1.border_style(forms::border_style::fixed_single);
  panel1.location({220, 10});
  panel1.parent(tab_page_containers);
  panel1.text("panel");
  
  tab_control tab_control_top;
  tab_control_top.location({10, 120});
  tab_control_top.parent(tab_page_containers);
  tab_page tab_page_top1;
  tab_page_top1.parent(tab_control_top);
  tab_page_top1.text("1");
  tab_page tab_page_top2;
  tab_page_top2.parent(tab_control_top);
  tab_page_top2.text("2");
  tab_page tab_page_top3;
  tab_page_top3.parent(tab_control_top);
  tab_page_top3.text("3");
  
  tab_control tab_control_right;
  tab_control_right.alignment(tab_alignment::right);
  tab_control_right.location({220, 120});
  tab_control_right.parent(tab_page_containers);
  tab_page tab_page_right1;
  tab_page_right1.parent(tab_control_right);
  tab_page_right1.text("1");
  tab_page tab_page_right2;
  tab_page_right2.parent(tab_control_right);
  tab_page_right2.text("2");
  tab_page tab_page_right3;
  tab_page_right3.parent(tab_control_right);
  tab_page_right3.text("3");
  
  tab_control tab_control_bottom;
  tab_control_bottom.alignment(tab_alignment::bottom);
  tab_control_bottom.location({10, 230});
  tab_control_bottom.parent(tab_page_containers);
  tab_page tab_page_bottom1;
  tab_page_bottom1.parent(tab_control_bottom);
  tab_page_bottom1.text("1");
  tab_page tab_page_bottom2;
  tab_page_bottom2.parent(tab_control_bottom);
  tab_page_bottom2.text("2");
  tab_page tab_page_bottom3;
  tab_page_bottom3.parent(tab_control_bottom);
  tab_page_bottom3.text("3");
  
  tab_control tab_control_left;
  tab_control_left.alignment(tab_alignment::left);
  tab_control_left.location({220, 230});
  tab_control_left.parent(tab_page_containers);
  tab_page tab_page_left1;
  tab_page_left1.parent(tab_control_left);
  tab_page_left1.text("1");
  tab_page tab_page_left2;
  tab_page_left2.parent(tab_control_left);
  tab_page_left2.text("2");
  tab_page tab_page_left3;
  tab_page_left3.parent(tab_control_left);
  tab_page_left3.text("3");

  tab_page tab_page_dialogs;
  tab_page_dialogs.parent(tab_control_main);
  tab_page_dialogs.text("Dialogs");

  application::run(form_main);
}
