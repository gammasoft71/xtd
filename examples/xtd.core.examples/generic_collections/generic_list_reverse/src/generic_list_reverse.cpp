#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto dinosaurs = list<string> {};
    
    dinosaurs.add("Pachycephalosaurus");
    dinosaurs.add("Parasauralophus");
    dinosaurs.add("Mamenchisaurus");
    dinosaurs.add("Amargasaurus");
    dinosaurs.add("Coelophysis");
    dinosaurs.add("Oviraptor");
    
    console::write_line();
    for (const auto& dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    dinosaurs.reverse();
    
    console::write_line();
    for (const auto& dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    dinosaurs.reverse(1, 4);
    
    console::write_line();
    for (const auto& dinosaur : dinosaurs)
      console::write_line(dinosaur);
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// Pachycephalosaurus
// Parasauralophus
// Mamenchisaurus
// Amargasaurus
// Coelophysis
// Oviraptor
//
// Oviraptor
// Coelophysis
// Amargasaurus
// Mamenchisaurus
// Parasauralophus
// Pachycephalosaurus
//
// Oviraptor
// Parasauralophus
// Mamenchisaurus
// Amargasaurus
// Coelophysis
// Pachycephalosaurus
