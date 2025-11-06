#include <xtd/xtd>

class program {
public:
  static auto main() -> void {
    auto boxes = box_collection {};
    
    boxes.add(program::box {10, 4, 6});
    boxes.add(program::box {4, 6, 10});
    boxes.add(program::box {6, 10, 4});
    boxes.add(program::box {12, 8, 10});
    
    // Same dimensions. Cannot be added:
    boxes.add(program::box {10, 4, 6});
    
    // Test the Remove method.
    display(boxes);
    console::write_line("Removing 6x10x4");
    boxes.remove(program::box {6, 10, 4});
    display(boxes);
    
    // Test the Contains method.
    auto box_check = program::box {8, 12, 10};
    console::write_line("Contains {}x{}x{} by dimensions: {}", box_check.height, box_check.length, box_check.width, boxes.contains(box_check));
    
    // Test the Contains method overload with a specified equality comparer.
    console::write_line("Contains {}x{}x{} by volume: {}", box_check.height, box_check.length, box_check.width, boxes.contains(box_check, box_same_volume {}));
  }
  
  struct box : public object, public iequatable<program::box> {
    // Public Constructors :
    box() = default;
    box(int h, int l, int w) : height {h}, length{l}, width {w} {}
    
    // Public Properties :
    int height = 0;
    int length = 0;
    int width = 0;
    
    // Public Methods :
    bool equals(const object& o) const noexcept override {return is<program::box>(o) && equals(as<program::box>(o));}
    bool equals(const program::box& o) const noexcept override {return box_same_dimensions {}.equals(*this, o);}
  };
  
  class box_collection : public ilist<program::box> {
  public:
    // Public Constructors :
    box_collection(const std::initializer_list<program::box>& boxes) : boxes_(boxes) {}
    
    // Public Properties :
    xtd::size count() const noexcept override {return boxes_.count();}
    
    bool is_fixed_size() const noexcept override {return false;}
    bool is_read_only() const noexcept override {return false;}
    bool is_synchronized() const noexcept override {return false;}
    
    const object& sync_root() const noexcept override {return sync_root_;}
    
    // Public Methods :
    void add(const program::box& item) override {
      if (!contains(item))
        boxes_.add(item);
      else
        console::write_line("A box with {}x{}x{} dimensions was already added to the collection.", item.height, item.length, item.width);
    }
    
    void clear() override {boxes_.clear();}
    
    bool contains(const program::box& item) const noexcept override {return index_of(item) != npos;}
    
    bool contains(const program::box& item, const iequality_comparer<program::box>& comparer) const noexcept {
      for (auto box : boxes_)
        if (comparer.equals(box, item)) return true;
      return false;
    }
    
    void copy_to(array<program::box>& array, xtd::size array_index) const override {boxes_.copy_to(array, array_index);}
    
    enumerator<program::box> get_enumerator() const override {return {new_ptr<box_enumerator>(boxes_)};}
    
    xtd::size index_of(const program::box& item) const noexcept override {
      for (auto index = 0_z; index  < count(); ++index)
        if (boxes_[index] == item) return index;
      return npos;
    }
    
    void insert(xtd::size index, const program::box& item) override {
      if (index >= count()) throw argument_out_of_range_exception {};
      boxes_.insert(index, item);
    }
    
    bool remove(const program::box& item) override {return boxes_.remove(item);}
    
    void remove_at(xtd::size index) override {
      if (index >= count()) throw argument_out_of_range_exception {};
      boxes_.remove_at(index);
    }
    
    // Public Operators :
    const program::box& operator [](xtd::size index) const override {
      if (index >= count()) throw argument_out_of_range_exception {};
      return boxes_[index];
    }
    
    program::box& operator [](xtd::size index) override {
      if (index >= count()) throw argument_out_of_range_exception {};
      return boxes_[index];
    }
    
  private:
    list<program::box> boxes_;
    object sync_root_;
  };
  
  class box_enumerator : public ienumerator<program::box> {
  public:
    // Public Constructors :
    explicit box_enumerator(const list<program::box>& items) : items_(items) {}
    
    // Public Properties :
    const program::box& current() const override {return items_[index_];}
    
    // Public Methods :
    bool move_next() override {return ++index_ < items_.count();}
    void reset() override {index_ = size_object::max_value;}
    
  protected:
    const list<program::box>& items_;
    size index_ = size_object::max_value;
  };
  
  // Defines two boxes as equal if they have the same dimensions.
  class box_same_dimensions : public iequality_comparer<program::box> {
  public:
    // Public Methods :
    bool equals(const program::box& b1, const program::box& b2) const noexcept override {return b1.height == b2.height && b1.length == b2.length && b1.width == b2.width;}
    
    size get_hash_code(const program::box& box) const noexcept override {return hash_code::combine(box.height, box.length, box.width);}
  };
  
  // Defines two boxes as equal if they have the same volume.
  class box_same_volume : public iequality_comparer<program::box> {
  public:
    // Public Methods :
    bool equals(const program::box& b1, const program::box& b2) const noexcept override {return b1.height * b1.length * b1.width == b2.height * b2.length * b2.width;}
    
    size get_hash_code(const program::box& box) const noexcept override {
      auto hash_code = hash_code::combine(box.height, box.length, box.width);
      console::write_line("HC: {}", hash_code);
      return hash_code;
    }
  };
  
  static void display(const box_collection& boxes) {
    console::write_line("\nheight  length  width   hash code");
    for (auto index = 0_z; index < boxes.count(); ++index)
      console::write_line("{,-6}  {,-6}  {,-6}  {}", boxes[index].height, boxes[index].length, boxes[index].width, boxes[index].get_hash_code());
    
    // Results by manipulating the iterator directly:
    
    //console::write_line("\nheight  length  width   hash code");
    //for (auto box : boxes)
    //  console::write_line("{,-6}  {,-6}  {,-6}  {}", box.height, box.length, box.width, box.get_hash_code());
    
    
    // Results by manipulating the enumerator directly:
    
    //auto enumerator = boxes.get_enumerator();
    //console::write_line("\nheight  length  width   hash code");
    //while (enumerator.move_next()) {
    //  auto b = enumerator.current();
    //  console::write_line("{,-6}  {,-6}  {,-6}  {}", b.height, b.length, b.width, b.get_hash_code());
    //}
    
    console::write_line();
  }
};

startup_(program::main);

// This code can produce the following output :
//
// A box with 10x4x6 dimensions was already added to the collection.
//
// height  length  width   hash code
// 10      4       6       215240349697
// 4       6       10      215240349697
// 6       10      4       215240349697
// 12      8       10      215240349697
//
// Removing 6x10x4
//
// height  length  width   hash code
// 10      4       6       215240349697
// 4       6       10      215240349697
// 12      8       10      215240349697
//
// Contains 8x12x10 by dimensions: false
// Contains 8x12x10 by volume: true
