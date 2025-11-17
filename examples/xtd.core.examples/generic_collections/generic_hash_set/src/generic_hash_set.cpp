#include <xtd/xtd>

namespace examples {
  class program {
  public:
    static void main() {
      auto even_numbers = hash_set<int> {};
      auto odd_numbers = hash_set<int> {};
      
      for (auto i = 0; i < 5; ++i) {
        // Populate even_numbers with just even numbers.
        even_numbers.add(i * 2);
        
        // Populate odd_numbers with just odd numbers.
        odd_numbers.add((i * 2) + 1);
      }
      
      console::write("even_numbers contains {} elements: ", even_numbers.count());
      display_set(even_numbers);
      console::write("odd_numbers contains {} elements: ", odd_numbers.count());
      display_set(odd_numbers);
      
      // Create a new hash_set populated with even numbers.
      auto numbers = even_numbers;
      console::write_line("numbers union_with odd_numbers...");
      numbers.union_with(odd_numbers);
      
      console::write("numbers contains {} elements: ", numbers.count());
      display_set(numbers);
    }

  private:
    static void display_set(const hash_set<int>& collection) {
      console::write("{");
      for (auto i : collection)
        console::write(" {}", i);
      console::write_line(" }");
    }
  };
}

startup_(examples::program::main);

// This code can produce the following output :
//
// even_numbers contains 5 elements: { 8 6 4 2 0 }
// odd_numbers contains 5 elements: { 9 7 5 3 1 }
// numbers union_with odd_numbers...
// numbers contains 10 elements: { 1 3 5 7 9 0 2 4 6 8 }
