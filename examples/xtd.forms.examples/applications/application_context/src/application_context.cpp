#include <xtd/xtd>

auto main() -> int {
  auto context = application_context {};
  
  auto form1 = form::create("Form 1 (Click the client area to set form as the main form)");
  form1.click += delegate_ {context.main_form(form1);};
  form1.show();
  
  auto form2 = form::create("Form 2 (Click the client area to set form as the main form)");
  form2.click += delegate_ {context.main_form(form2);};
  form2.show();
  
  auto form3 = form::create("Form 3 (Click the client area to set form as the main form)");
  form3.click += delegate_ {context.main_form(form3);};
  form3.show();
  
  // if no client area form clicked, the application will not exit when you close the forms.
  application::run(context);
}
