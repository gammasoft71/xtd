#include <xtd/xtd>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace xtd::io;

auto main()->int {
  console::write_line("application_resources = {}", xtd::environment::get_folder_path(xtd::environment::special_folder::application_resources));
  auto form1 = form::create("form1");
  auto button1 = button::create(form1, "Take a\nscreenshot", {10, 10});
  button1.auto_size(true);
  button1.click += [&] {
    form1.hide();
    application::do_events();
    auto b = bitmap {screen::primary_screen().bounds().width(), screen::primary_screen().bounds().height()};
    b.create_graphics().copy_from_screen({0, 0}, {0, 0}, screen::primary_screen().bounds().size());
    b.save(path::combine(environment::get_folder_path(environment::special_folder::desktop), "screenshot.png"));
    form1.show();
  };
  application::run(form1);
}
