#include <xtd/xtd>

class program {
public:
  static auto main() -> void {
    auto test = simple_list();
    
    // Populate the List.
    console::write_line("Populate the List");
    test.add("one");
    test.add("two");
    test.add("three");
    test.add("four");
    test.add("five");
    test.add("six");
    test.add("seven");
    test.add("eight");
    test.print_contents();
    console::write_line();
    
    // Remove elements from the list.
    console::write_line("Remove elements from the list");
    test.remove("six");
    test.remove("eight");
    test.print_contents();
    console::write_line();
    
    // Add an element to the end of the list.
    console::write_line("Add an element to the end of the list");
    test.add("nine");
    test.print_contents();
    console::write_line();
    
    // Insert an element into the middle of the list.
    console::write_line("Insert an element into the middle of the list");
    test.insert(4, "number");
    test.print_contents();
    console::write_line();
    
    // Check for specific elements in the list.
    console::write_line("Check for specific elements in the list");
    console::write_line("List contains \"three\": {}", test.contains("three"));
    console::write_line("List contains \"ten\": {}", test.contains("ten"));
  }
  
  class simple_list : public object, public collections::ilist {
  private:
    array<any_object> contents_ = array<any_object>(8);
    xtd::size count_;
    
  public:
    inline static constexpr xtd::size npos = ilist::npos;

    simple_list() {count_ = 0;}
    
    auto print_contents() const noexcept -> void {
      console::write_line("List has a capacity of {} and currently has {} elements.", contents_.length(), count_);
      console::write("List contents:");
      for (auto i = 0_z; i < count(); ++i)
        console::write(" {}", contents_[i]);
      console::write_line();
    }

    // xtd::collections::iist Members
    
    auto is_fixed_size() const noexcept -> bool override {return true;}
    
    auto is_read_only() const noexcept -> bool override {return false;}

    auto add(const any_object& value) -> void override {
      if (count_ < contents_.length()) {
        contents_[count_] = value;
        count_++;
      }
    }
    
    auto clear() -> void override {
      count_ = 0;
    }
    
    auto contains(const any_object& value) const noexcept -> bool override {
      for (auto i = 0_z; i < count(); ++i)
        if (contents_[i] == value) return true;
      return false;
    }
    
    auto index_of(const any_object& value) const noexcept -> xtd::size override {
      for (auto i = 0_z; i < count(); ++i)
        if (contents_[i] == value) return i;
      return npos;
    }
    
    auto insert(xtd::size index, const any_object& value) -> void override {
      if (count_ + 1 <= contents_.length() && index < count()) {
        ++count_;
        
        for (xtd::size i = count() - 1; i > index; --i)
          contents_[i] = contents_[i - 1];
        
        contents_[index] = value;
      }
    }
    
    auto remove(const any_object& value) -> bool override {
      auto index = index_of(value);
      remove_at(index);
      return index != npos;
    }
    
    auto remove_at(xtd::size index) -> void override {
      if (index < count()) {
        for (xtd::size i = index; i < count() - 1; ++i)
          contents_[i] = contents_[i + 1];
        --count_;
      }
    }
    
    auto operator [] (xtd::size index) const -> const any_object& override {
      return contents_[index];
    }
    auto operator [] (xtd::size index) -> any_object& override {
      return contents_[index];
    }
    
    // xtd::collections::icollection members.
    
    auto count() const noexcept -> xtd::size override {return count_;}
    
    auto is_synchronized() const noexcept -> bool override {return false;}
    
    // Return the current instance since the underlying store is not
    // publicly available.
    auto sync_root() const noexcept -> const object& override {return *this;}
    
    auto copy_to(xtd::array<any_object>& array, xtd::size index) const noexcept -> void override {
      for (auto i = 0_z; i < count(); ++i)
        array[index + i] = contents_[i];
    }
    
    // xtd::collections::ienumerable Members
    
    auto get_enumerator() const -> collections::enumerator override {
      // Refer to the xtd::collection::ienumerator documentation for an example of
      // implementing an enumerator.
      throw not_implemented_exception {"The method or operation is not implemented."};
    }
  };
};

startup_(program::main);

// This code produces the following output :
//
// Populate the List
// List has a capacity of 8 and currently has 8 elements.
// List contents: one two three four five six seven eight
//
// Remove elements from the list
// List has a capacity of 8 and currently has 6 elements.
// List contents: one two three four five seven
//
// Add an element to the end of the list
// List has a capacity of 8 and currently has 7 elements.
// List contents: one two three four five seven nine
//
// Insert an element into the middle of the list
// List has a capacity of 8 and currently has 8 elements.
// List contents: one two three four number five seven nine
//
// Check for specific elements in the list
// List contains "three": true
// List contains "ten": false
