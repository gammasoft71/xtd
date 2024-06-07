#include "tetris_form.h"

using namespace tetris;
using namespace xtd;
using namespace xtd::forms;

tetris_form::tetris_form() {
  auto_size_mode(forms::auto_size_mode::grow_and_shrink);
  auto_size(true);
  center_to_screen();
  controls().push_back_range({board_control_, status_bar_});
  text("Tetris"_t);

  board_control_.dock(dock_style::fill);
  board_control_.start();
}
  
auto tetris_form::main() {
  application::run(tetris_form {});
}

startup_(tetris_form::main);
