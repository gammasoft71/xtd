#include "sudoku.hpp"
#include <xtd/xtd>

auto print_grid(const sudoku::sudoku::grid_type& grid) -> void {
  for (auto y = 0_z; y < grid.get_length(0); ++y) {
    for (auto x = 0_z; x < grid.get_length(1); ++x)
      print("{} ", grid(y, x));
    println();
  }
}

auto main() -> int {
  //auto sudoku1 = sudoku::sudoku::parse(file::read_all_text("data.txt"));
  auto sudoku1 = sudoku::sudoku::make_puzzle(sudoku::sudoku::difficulty::easy);
  file::write_all_text("data.txt", string::join("\n", sudoku1.to_array().chunk(sudoku1.grid().get_length(0)).select<string>([](auto c){return string::join(" ", c);})));
  
  println(string('_', 25));
  println("{,25}", "Puzzle");
  print_grid(sudoku1.grid());
  println();
  
  sudoku1.solve();
  println(string('_', 25));
  println("{,25}", "Solved");
  print_grid(sudoku1.grid());
  println();
  
  application::run(form::create("Sudoku"));
}

// This code can produce the following output :
//
// _________________________
//                    Puzzle
// 1 0 5 0 2 9 6 0 0
// 0 0 0 0 8 4 0 0 5
// 4 0 0 6 0 0 0 0 1
// 0 2 0 5 0 0 0 4 0
// 5 1 0 0 0 0 0 6 9
// 6 8 7 0 0 1 5 3 0
// 2 0 1 8 0 6 9 7 0
// 0 5 0 4 9 7 0 1 8
// 0 7 9 0 1 3 4 5 6
//
// _________________________
//                    Solved
// 1 3 5 7 2 9 6 8 4
// 7 6 2 1 8 4 3 9 5
// 4 9 8 6 3 5 7 2 1
// 9 2 3 5 6 8 1 4 7
// 5 1 4 3 7 2 8 6 9
// 6 8 7 9 4 1 5 3 2
// 2 4 1 8 5 6 9 7 3
// 3 5 6 4 9 7 2 1 8
// 8 7 9 2 1 3 4 5 6
//
