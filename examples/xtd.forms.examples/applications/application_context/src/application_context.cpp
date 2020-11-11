#include <xtd/xtd.forms>

using namespace xtd::forms;

int main() {
  application_context context;
  
  form form1;
  form1.click += [&] {
    context.main_form(form1);
  };
  form1.text("Form 1 (Click the client area to set form as the main form)");
  form1.show();
  
  form form2;
  form2.click += [&] {
    context.main_form(form2);
  };
  form2.text("Form 2 (Click the client area to set form as the main form)");
  form2.show();

  form form3;
  form3.click += [&] {
    context.main_form(form3);
  };
  form3.text("Form 3 (Click the client area to set form as the main form)");
  form3.show();

  // if no client area form clicked, the application will not exit when you close the forms.
  application::run(context);
}
