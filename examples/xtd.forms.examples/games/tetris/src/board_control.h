#include "shape.h"

namespace tetris {
  class board_control final : public xtd::forms::control {
  public:
    static constexpr int board_width = 10;
    static constexpr int board_height = 22;

    board_control(xtd::forms::status_bar& satus_bar);
    
    void start();
    void pause();

  private:
    void clear_board();
    void draw_square(xtd::drawing::graphics& graphics, int x, int y, tetrominoes tetrominoes);
    void drop_down();
    void new_piece();
    void one_line_down();
    void piece_dropped();
    void remove_full_lines();
    bool try_move(const shape& new_piece, int new_x, int new_y) noexcept;
    int square_width();
    int square_height();
    tetrominoes& tetrominoes_at(int x, int y);

    void on_paint(xtd::forms::paint_event_args& event) override;
    void on_key_down(xtd::forms::key_event_args& event) override;
    void on_tick(xtd::object& sender, const xtd::event_args& event);
    
    std::array<tetrominoes, board_width * board_height> board_;
    shape cur_piece_;
    int cur_x_ = 0;
    int cur_y_ = 0;
    bool falling_finished_ = false;
    int num_lines_removed_ = 0;
    bool paused_ = false;
    bool started_ = false;
    xtd::forms::status_bar& status_bar_;
    xtd::forms::timer timer_;
  };
}
