#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto dinosaurs = list<ustring> {};
    
    console::write_line("\ncapacity: {0}", dinosaurs.capacity());
    
    dinosaurs.add("Tyrannosaurus");
    dinosaurs.add("Amargasaurus");
    dinosaurs.add("Deinonychus");
    dinosaurs.add("Compsognathus");

    auto read_only_dinosaurs = dinosaurs.as_read_only();

    console::write_line();
    for (auto dinosaur : read_only_dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("count: {0}", read_only_dinosaurs.count());
    
    console::write_line("\ncontains(\"Deinonychus\"): {0}", dinosaurs.contains("Deinonychus"));
    
    console::write_line("\nread_only_dinosaurs[3]: {0}", dinosaurs[3]);
    
    console::write_line("\index_of(\"Compsognathus\"): {0}", read_only_dinosaurs.index_of("Compsognathus"));
    
    console::write_line("\nInsert into the wrapped List:");
    console::write_line("insert(2, \"Oviraptor\")");
    dinosaurs.insert(2, "Oviraptor");
    
    console::write_line();
    for (auto dinosaur : read_only_dinosaurs)
      console::write_line(dinosaur);

    auto dino_array = array<ustring>(read_only_dinosaurs.count() + 2);
    read_only_dinosaurs.copy_to(dinoArray, 1);
    
    console::write_line("\nCopied array has {0} elements:", dino_array.size());
    for (auto dinosaur : dino_array )
      console::write_line("\"{0}\"", dinosaur);
  }
};

startup_(example::main);

// This code can produces the following output :
//
