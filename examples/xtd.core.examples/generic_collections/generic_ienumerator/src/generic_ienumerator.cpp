#include <xtd/collections/generic/enumerator>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;

struct box {
  int length = 0;
  int width = 0;
  int height = 0;
  
  ustring to_string() const noexcept {return ustring::format("box [length={}, width={}, height={}]", length, width, height);}
};

using box_collection = list<::box>;

class box_enumerator : public ienumerator<::box> {
public:
  explicit box_enumerator(const box_collection& boxes) : boxes {boxes} {}
  
  const ::box& current() const override {return boxes[cur_index];}
  bool move_next() override {return ++cur_index < boxes.size();}
  void reset() override {cur_index = box_integer<size>::max_value;}
  
private:
  const box_collection& boxes;
  size cur_index = box_integer<size>::max_value;
};

auto main() -> int {
  auto boxes = box_collection {{10, 20, 30}, {20, 5, 10}, {12, 3, 7}};
  auto enumerator = box_enumerator {boxes};
  while(enumerator.move_next())
    console::write_line(enumerator.current().to_string());
}

// This code can produces the following output :
//
// box [length=10, width=20, height=30]
// box [length=20, width=5, height=10]
// box [length=12, width=3, height=7]
