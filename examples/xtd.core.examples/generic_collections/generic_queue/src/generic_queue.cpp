#include <xtd/xtd>

namespace examples {
  class program {
  public:
    static void main() {
      auto numbers = queue<string> {};
      numbers.enqueue("one");
      numbers.enqueue("two");
      numbers.enqueue("three");
      numbers.enqueue("four");
      numbers.enqueue("five");
      
      // A queue can be enumerated without disturbing its contents.
      for (auto number : numbers )
        console::write_line(number);
      
      console::write_line("\nDequeuing '{0}'", numbers.dequeue());
      console::write_line("Peek at next item to dequeue: {0}", numbers.peek());
      console::write_line("Dequeuing '{0}'", numbers.dequeue());
      
      // Create a copy of the queue, using the to_array method and the constructor that accepts an ienumerable<type_t>.
      auto queue_copy = queue<string>(numbers.to_array());
      
      console::write_line("\nContents of the first copy:");
      for(auto number : queue_copy )
        console::write_line(number);
      
      // Create an array twice the size of the queue and copy the elements of the queue, starting at the middle of the array.
      auto array2 = array<string>(numbers.count() * 2);
      numbers.copy_to(array2, numbers.count());
      
      // Create a second queue, using the constructor that accepts an ienumerable(Of type_t).
      auto queue_copy2 = queue<string>(array2);
      
      console::write_line("\nContents of the second copy, with duplicates and empty:");
      for(auto number : queue_copy2 )
        console::write_line(number);
      
      console::write_line("\nqueue_copy.contains(\"four\") = {}", queue_copy.contains("four"));
      
      console::write_line("\nqueue_copy.clear()");
      queue_copy.clear();
      console::write_line("\nqueue_copy.count() = {}", queue_copy.count());
    }
  };
}

startup_(examples::program::main);

// This code can produce the following output :
//
// one
// two
// three
// four
// five
//
// Dequeuing 'one'
// Peek at next item to dequeue: two
// Dequeuing 'two'
//
// Contents of the first copy:
// three
// four
// five
//
// Contents of the second copy, with duplicates and empty:
//
//
//
// three
// four
// five
// 
// queue_copy.contains("four") = true
//
// queue_copy.clear()
//
// queue_copy.count() = 0
