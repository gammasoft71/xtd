#include "shape.hpp"

namespace tetris {
  class board_control final : public control {
  public:
    static constexpr int board_width = 10;
    static constexpr int board_height = 22;

    board_control(status_bar& satus_bar);
    
    void start();
    void pause();

  private:
    void clear_board();
    void draw_square(graphics& graphics, int x, int y, tetrominoes tetrominoes);
    void drop_down();
    void new_piece();
    void one_line_down();
    void piece_dropped();
    void remove_full_lines();
    bool try_move(const shape& new_piece, int new_x, int new_y) noexcept;
    int square_width();
    int square_height();
    tetrominoes& tetrominoes_at(int x, int y);

    void on_paint(paint_event_args& event) override;
    void on_key_down(key_event_args& event) override;
    void on_tick(object& sender, const event_args& event);
    
    fixed_array<tetrominoes, board_width * board_height> board_;
    shape cur_piece_;
    int cur_x_ = 0;
    int cur_y_ = 0;
    bool falling_finished_ = false;
    int num_lines_removed_ = 0;
    bool paused_ = false;
    bool started_ = false;
    status_bar& status_bar_;
    forms::timer timer_;
  };
}
