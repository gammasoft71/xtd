#include "../../../include/xtd/forms/application.h"
#include "../../../include/xtd/forms/use_wait_cursor.h"

using namespace xtd;
using namespace xtd::forms;

use_wait_cursor::use_wait_cursor() {
  application::use_wait_cursor(true);
}

use_wait_cursor::~use_wait_cursor() {
  application::use_wait_cursor(false);
}
