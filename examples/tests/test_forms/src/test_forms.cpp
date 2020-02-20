#include <xtd/xtd.forms>

using namespace xtd;
using namespace xtd::forms;

int main() {
  cdebug << format("install path = {}", __CMAKE_INSTALL_PREFIX__) << std::endl;
  cdebug << format("xtd include path = {}", __XTD_INCLUDE_PATH__) << std::endl;
  cdebug << format("xtd lib path = {}", __XTD_LIB_PATH__) << std::endl;
  auto main_form = control::create<form>("Test Gui");
  application::run(*main_form);
}
