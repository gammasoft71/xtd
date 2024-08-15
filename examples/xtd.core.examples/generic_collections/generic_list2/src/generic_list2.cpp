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
    dinosaurs.add("Mamenchisaurus");
    dinosaurs.add("Deinonychus");
    dinosaurs.add("Compsognathus");
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\ncapacity: {0}", dinosaurs.capacity());
    console::write_line("count: {0}", dinosaurs.count());
    
    console::write_line("\ncontains(\"Deinonychus\"): {0}", dinosaurs.contains("Deinonychus"));
    
    console::write_line("\ninsert(2, \"Compsognathus\")");
    dinosaurs.insert(2, "Compsognathus");
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    // Shows accessing the list using the Item property.
    console::write_line("\ndinosaurs[3]: {0}", dinosaurs[3]);
    
    console::write_line("\nremove(\"Compsognathus\")");
    dinosaurs.remove("Compsognathus");
    
    console::write_line();
    for (auto dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    dinosaurs.trim_excess();
    console::write_line("\ntrim_excess()");
    console::write_line("capacity: {0}", dinosaurs.capacity());
    console::write_line("count: {0}", dinosaurs.count());
    
    dinosaurs.clear();
    console::write_line("\nclear()");
    console::write_line("capacity: {0}", dinosaurs.capacity());
    console::write_line("count: {0}", dinosaurs.count());
  }
};

startup_(example::main);

// This code produces the following output :
//
// capacity: 0
//
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
// Compsognathus
//
// capacity: 8
// count: 5
//
// contains("Deinonychus"): true
//
// insert(2, "Compsognathus")
//
// Tyrannosaurus
// Amargasaurus
// Compsognathus
// Mamenchisaurus
// Deinonychus
// Compsognathus
//
// dinosaurs[3]: Mamenchisaurus
//
// remove("Compsognathus")
//
// Tyrannosaurus
// Amargasaurus
// Mamenchisaurus
// Deinonychus
// Compsognathus
//
// trim_excess()
// capacity: 5
// count: 5

// clear()
// capacity: 5
// count: 0
