#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto input = array<ustring> {"Brachiosaurus", "Amargasaurus", "Mamenchisaurus"};
    
    auto dinosaurs = list<ustring>(input);
    
    console::write_line("\ncapacity: {0}", dinosaurs.capacity());
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nadd_range(dinosaurs)");
    dinosaurs.add_range(dinosaurs);
    
    console::write_line();
    for(auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nremove_range(2, 2)");
    dinosaurs.remove_range(2, 2);
    
    console::write_line();
    for(auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    input = {"Tyrannosaurus", "Deinonychus", "Velociraptor"};
    console::write_line("\ninsert_range(3, input)");
    dinosaurs.insert_range(3, input);
    
    console::write_line();
    for(auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\noutput = dinosaurs.get_range(2, 3).to_array()");
    auto output = dinosaurs.get_range(2, 3).to_array();
    
    console::write_line();
    for (auto dinosaur : output)
      console::write_line(dinosaur);
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// capacity: 3
//
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
//
// add_range(dinosaurs)
//
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
// Brachiosaurus
// Amargasaurus
// Mamenchisaurus
//
// remove_range(2, 2)
//
// Brachiosaurus
// Amargasaurus
// Amargasaurus
// Mamenchisaurus
//
// insert_range(3, input)
//
// Brachiosaurus
// Amargasaurus
// Amargasaurus
// Tyrannosaurus
// Deinonychus
// Velociraptor
// Mamenchisaurus
//
// output = dinosaurs.get_range(2, 3).to_array()
//
// Amargasaurus
// Tyrannosaurus
// Deinonychus
