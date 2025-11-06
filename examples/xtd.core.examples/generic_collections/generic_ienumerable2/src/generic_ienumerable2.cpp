#include <xtd/xtd>

class program {
public:
  static auto main() -> void {
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

  struct box : public iequatable<program::box> {
    box() = default;
    box(int l, int w, int h) : length{l}, width {w}, height {h} {}
    
    int length = 0;
    int width = 0;
    int height = 0;
    
    bool equals(const program::box& o) const noexcept override {return length == o.length && width == o.width && height == o.height;}
    string to_string() const noexcept {return string::format("box [length={}, width={}, height={}]", length, width, height);}
  };
  
  class box_collection : public ienumerable<program::box> {
  public:
    box_collection(const std::initializer_list<program::box>& boxes) : boxes_(boxes) {}
    
    enumerator<program::box> get_enumerator() const override {
      class box_enumerator : public ienumerator<program::box> {
      public:
        explicit box_enumerator(const list<program::box>& items) : items_(items) {}
        const program::box& current() const override {return items_[index_];}
        bool move_next() override {return ++index_ < items_.count();}
        void reset() override {index_ = size_object::max_value;}
        
      protected:
        const list<program::box>& items_;
        size index_ = size_object::max_value;
      };
      return {new_ptr<box_enumerator>(boxes_)};
    }
    
  private:
    list<program::box> boxes_;
  };
};

startup_(program::main);

// This code produces the following output :
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
