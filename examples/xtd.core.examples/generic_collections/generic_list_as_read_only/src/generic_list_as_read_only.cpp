#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto dinosaurs = list<string> {};
    
    console::write_line("\ncapacity: {0}", dinosaurs.capacity());
    
    dinosaurs.add("Tyrannosaurus");
    dinosaurs.add("Amargasaurus");
    dinosaurs.add("Deinonychus");
    dinosaurs.add("Compsognathus");

    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);

    console::write_line("\nauto ro_dinosaurs = dinosaurs.as_read_only()");
    auto ro_dinosaurs = dinosaurs.as_read_only();
    
    console::write_line("\nElements in the read-only ilist:");
    for (auto dinosaur : ro_dinosaurs)
      console::write_line(dinosaur);

    console::write_line("\ndinosaurs[2] = \"Coelophysis\"");
    dinosaurs[2] = "Coelophysis";
    
    console::write_line("\nElements in the read-only ilist:");
    for (auto dinosaur : ro_dinosaurs)
      console::write_line(dinosaur);
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// capacity: 0
//
// Tyrannosaurus
// Amargasaurus
// Deinonychus
// Compsognathus
//
// auto ro_dinosaurs = dinosaurs.as_read_only()
//
// Elements in the read-only ilist:
// Tyrannosaurus
// Amargasaurus
// Deinonychus
// Compsognathus
//
// dinosaurs[2] = "Coelophysis"
//
// Elements in the read-only ilist:
// Tyrannosaurus
// Amargasaurus
// Coelophysis
// Compsognathus
