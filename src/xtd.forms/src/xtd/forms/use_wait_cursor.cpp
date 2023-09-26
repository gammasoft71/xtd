#include "../../../include/xtd/forms/application"
#include "../../../include/xtd/forms/use_wait_cursor"

using namespace xtd;
using namespace xtd::forms;

use_wait_cursor::use_wait_cursor() {
  application::use_wait_cursor(true);
}

use_wait_cursor::~use_wait_cursor() {
  application::use_wait_cursor(false);
}
