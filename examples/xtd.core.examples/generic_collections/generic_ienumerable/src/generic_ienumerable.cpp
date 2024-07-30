#include <xtd/collections/generic/ienumerable>
#include <xtd/console>

using namespace xtd;
using namespace xtd::collections::generic;

struct box {
  int length = 0;
  int width = 0;
  int height = 0;
  
  ustring to_string() const noexcept {return ustring::format("box [length={}, width={}, height={}]", length, width, height);};
};

class box_collection : public ienumerable<::box> {
public:
  box_collection(const std::initializer_list<::box>& boxes) : boxes_(boxes) {}
  
  enumerator<::box> get_enumerator() const override {
    class box_enumerator : public ienumerator<::box> {
    public:
      explicit box_enumerator(const list<::box>& items) : items_(items) {}
      const ::box& current() const override {return items_[index_];}
      bool move_next() override {return ++index_ < items_.size();}
      void reset() override {index_ = xtd::box_integer<xtd::size>::max_value;}
      
    protected:
      const list<::box>& items_;
      size index_ = xtd::box_integer<xtd::size>::max_value;
    };
    return {new_ptr<box_enumerator>(boxes_)};
  }
  
private:
  list<::box> boxes_;
};

auto main() -> int {
  auto boxes = box_collection {{10, 20, 30}, {20, 5, 10}, {12, 3, 7}};
  
  auto enumerator = boxes.get_enumerator();
  while (enumerator.move_next())
    console::write_line(enumerator.current().to_string());
  
  console::write_line();
  for (auto box : boxes)
    console::write_line(box.to_string());
  
  console::write_line();
  for (auto iterator = boxes.begin(); iterator != boxes.end(); ++iterator)
    console::write_line(iterator->to_string());
}

// This code can produces the following output :
//
// box [length=10, width=20, height=30]
// box [length=20, width=5, height=10]
// box [length=12, width=3, height=7]
//
// box [length=10, width=20, height=30]
// box [length=20, width=5, height=10]
// box [length=12, width=3, height=7]
//
// box [length=10, width=20, height=30]
// box [length=20, width=5, height=10]
// box [length=12, width=3, height=7]
