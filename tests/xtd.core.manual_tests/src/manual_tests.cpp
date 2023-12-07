#include <xtd/as>
#include <xtd/is>
#include <xtd/console>
#include <xtd/date_time>
#include <xtd/day_of_week>
#include <xtd/convert_string>
#include <xtd/typeof>
#include <xtd/translator>

using namespace std;
using namespace xtd;

auto main()->int {
  console::write_line("locale = {}", translator::locale().name());
  translator::language("fr_CH");
  translator::locale("zh_CN");
  console::write_line("locale = {}", translator::locale().name());
  
  auto str = translator::translate("&Open...");
  console::write_line(str);
}
