#include <xtd/xtd>

struct coordinate : public istringable {
  int x = 0;
  int y = 0;
  
  coordinate() noexcept = default;
  coordinate(int x, int y) noexcept : x {x}, y {y} {}

  coordinate& translate(int x, int y) noexcept {
    self_.x += x;
    self_.y += y;
    return self_;
  }
  
  string to_string() const noexcept override {return string::format("{{x={}, y={}}}", x, y);}
};

auto main()->int {
  auto c = coordinate {200, 100};
  println("c => {}", c);

  println("translate");
  c.translate(50, 20);
  println("c => {}", c);
}

// This code can produce the following output :
//
// c => {x=200, y=100}
// translate
// c => {x=250, y=120}
