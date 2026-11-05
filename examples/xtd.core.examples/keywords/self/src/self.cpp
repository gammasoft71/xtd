#include <xtd/xtd>

struct point {
  int x = 0;
  int y = 0;
  
  auto offset(int x, int y) noexcept -> point& {
    self_.x += x;
    self_.y += y;
    return self_;
  }
  
  auto to_string() const noexcept -> string {return "point {x="_s + x + ", y=" + y + "}";}
};

auto main() -> int {
  auto c = point {.x = 200, .y = 100};
  println("c => " + c);
  println("offset");
  println("c => " + c.offset(50, 20));
}

// This code can produce the following output :
//
// c => point {x=200, y=100}
// offset
// c => point {x=250, y=120}
