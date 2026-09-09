#include <xtd/xtd>

class example {
public:
  static auto main() {
    auto dinosaurs = array<string> {
      "Pachycephalosaurus",
      "Amargasaurus",
      "Tyrannosaurus",
      "Mamenchisaurus",
      "Deinonychus",
      "Edmontosaurus"
    };
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nsort");
    dinosaurs.sort();
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nbinary_search for \"Coelophysis\":");
    auto index = array<>::binary_search(dinosaurs, "Coelophysis");
    show_where(dinosaurs, index);
    
    console::write_line("\nbinary_search for \"Tyrannosaurus\":");
    index = array<>::binary_search(dinosaurs, "Tyrannosaurus");
    show_where(dinosaurs, index);
  }
  
  template<typename type_t>
  static auto show_where(const array<type_t>& array, usize index) -> void {
    if (index < array.length())
      console::write_line("Found at index {}.", index);
    else {
      // If the index is greater or equal then array length, it represents the bitwise complement of the next larger element in the array.
      //
      index = ~index;
      
      console::write("Not found. Sorts between: ");
      
      if (index == 0) console::write("beginning of array and ");
      else console::write("{} and ", array[index-1]);
      
      if (index == array.length()) console::write_line("end of array.");
      else console::write_line("{}.", array[index]);
    }
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// Pachycephalosaurus
// Amargasaurus
// Tyrannosaurus
// Mamenchisaurus
// Deinonychus
// Edmontosaurus
//
// sort
//
// Amargasaurus
// Deinonychus
// Edmontosaurus
// Mamenchisaurus
// Pachycephalosaurus
// Tyrannosaurus
//
// binary_search for "Coelophysis":
// Not found. Sorts between: Amargasaurus and Deinonychus.
//
// binary_search for "Tyrannosaurus":
// Found at index 5.
