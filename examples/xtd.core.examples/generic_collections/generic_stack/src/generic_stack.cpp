#include <xtd/xtd>

namespace examples {
  class program {
  public:
    static auto main() -> void {
      auto numbers = stack<string> {};
      numbers.push("one");
      numbers.push("two");
      numbers.push("three");
      numbers.push("four");
      numbers.push("five");
      
      // A stack can be enumerated without disturbing its contents.
      for (auto number : numbers)
        console::write_line(number);
      
      console::write_line("\nPopping '{}'", numbers.pop());
      console::write_line("Peek at next item to destack: {}", numbers.peek());
      console::write_line("Popping '{}'", numbers.pop());
      
      // Create a copy of the stack, using the to_array method and the constructor that accepts an ienumerable<type_t>.
      auto stack2 = stack<string>(numbers.to_array());
      
      console::write_line("\nContents of the first copy:");
      for (auto number : stack2 )
        console::write_line(number);
      
      // Create an array twice the size of the stack and copy the elements of the stack, starting at the middle of the array.
      auto array2 = array<string>(numbers.count() * 2);
      numbers.copy_to(array2, numbers.count());
      
      // Create a second stack, using the constructor that accepts an ienumerable<type_t>.
      auto stack3 = stack<string>(array2);
      
      console::write_line("\nContents of the second copy, with duplicates and nulls:");
      for (auto number : stack3 )
        console::write_line(number);
      
      console::write_line("\nstack2.contains(\"four\") = {0}", stack2.contains("four"));
      
      console::write_line("\nstack2.clear()");
      stack2.clear();
      console::write_line("\nstack2.count() = {0}", stack2.count());
    }
  };
}

startup_(examples::program::main);

// This code can produce the following output :
//
// five
// four
// three
// two
// one
//
// Popping 'five'
// Peek at next item to destack: four
// Popping 'four'
//
// Contents of the first copy:
// one
// two
// three
//
// Contents of the second copy, with duplicates and nulls:
// one
// two
// three
//
//
//
//
// stack2.contains("four") = false
//
// stack2.clear()
//
// stack2.count() = 0
