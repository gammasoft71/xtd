#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto dinosaurs = list<string> {};
    
    dinosaurs.add("Pachycephalosaurus");
    dinosaurs.add("Amargasaurus");
    dinosaurs.add("Mamenchisaurus");
    dinosaurs.add("Deinonychus");
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nsort");
    dinosaurs.sort();
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nbinary_search and insert \"Coelophysis\":");
    auto index = dinosaurs.binary_search("Coelophysis");
    if (index > dinosaurs.count()) dinosaurs.insert(~index, "Coelophysis");
    
    console::write_line();
    for (string dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nbinary_search and insert \"Tyrannosaurus\":");
    index = dinosaurs.binary_search("Tyrannosaurus");
    if (index > dinosaurs.count()) dinosaurs.insert(~index, "Tyrannosaurus");
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// Pachycephalosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
//
// sort
//
// Amargasaurus
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
//
// binary_search and insert "Coelophysis":
//
// Amargasaurus
// Coelophysis
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
//
// binary_search and insert "Tyrannosaurus":
//
// Amargasaurus
// Coelophysis
// Deinonychus
// Mamenchisaurus
// Pachycephalosaurus
// Tyrannosaurus
