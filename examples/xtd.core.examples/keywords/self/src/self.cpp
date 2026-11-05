#include <xtd/xtd>

struct coordinate {
  int x = 0;
  int y = 0;
  
  auto translate(int x, int y) noexcept -> coordinate& {
    self_.x += x;
    self_.y += y;
    return self_;
  }
  
  auto to_string() const noexcept -> string {return "coordinate {x="_s + x + ", y=" + y + "}";}
};

auto main() -> int {
  auto c = coordinate {.x = 200, .y = 100};
  println("c => {}", c);

  println("translate");
  c.translate(50, 20);
  println("c => {}", c);
}

// This code can produce the following output :
//
// c => coordinate {x=200, y=100}
// translate
// c => coordinate {x=250, y=120}
