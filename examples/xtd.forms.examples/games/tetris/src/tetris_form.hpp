#include "board_control.hpp"

namespace tetris {
  class tetris_form final : public xtd::forms::form {
  public:
    tetris_form();

    static auto main();
    
  private:
    xtd::forms::status_bar status_bar_;
    board_control board_control_ {status_bar_};
  };
}
