#include <xtd/forms/application>
#include <xtd/forms/button>
#include <xtd/forms/form>
#include <xtd/forms/label>

auto main() -> int {
  auto button1_clicked = 0, button2_clicked = 0;
  xtd::forms::button button1, button2;
  xtd::forms::label label1, label2;
  xtd::forms::form form1;
  
  button1.text("Button 1").location({50, 50});
  button2.auto_repeat(true).text("Button 2").location({50, 100}).size({200, 75});
  label1.text("Button 1 clicked 0 times").location({50, 200}).width(200);
  label2.text("Button 2 clicked 0 times").location({50, 230}).width(200);
  button1.click += delegate_ {label1.text(xtd::string::format("Button 1 clicked {} times", ++button1_clicked));};
  button2.click += delegate_ {label2.text(xtd::string::format("Button 2 clicked {} times", ++button2_clicked));};
  form1.text("Button 3 example");
  form1 << button1 << button2 << label1 << label2;
  
  xtd::forms::application::run(form1);
}
