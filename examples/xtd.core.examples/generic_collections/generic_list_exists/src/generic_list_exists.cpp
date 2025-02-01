#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

class example {
public:
  static auto main() -> void {
    auto dinosaurs = list<string> {};
    
    dinosaurs.add("Compsognathus");
    dinosaurs.add("Amargasaurus");
    dinosaurs.add("Oviraptor");
    dinosaurs.add("Velociraptor");
    dinosaurs.add("Deinonychus");
    dinosaurs.add("Dilophosaurus");
    dinosaurs.add("Gallimimus");
    dinosaurs.add("Triceratops");
    
    console::write_line();
    for (const auto& dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\ntrue_for_all(ends_with_saurus): {0}", dinosaurs.true_for_all(predicate<const string&> {ends_with_saurus}));
    
    console::write_line("\nfind(ends_with_saurus): {0}", dinosaurs.find(predicate<const string&> {ends_with_saurus}));
    
    console::write_line("\nfindLast(ends_with_saurus): {0}", dinosaurs.find_last(predicate<const string&> {ends_with_saurus}));
    
    console::write_line("\nfind_all(ends_with_saurus):");
    auto sublist = dinosaurs.find_all(predicate<const string&> {ends_with_saurus});
    
    for (const auto& dinosaur : sublist)
      console::write_line(dinosaur);
    
    console::write_line("\n{0} elements removed by remove_all(ends_with_saurus).", dinosaurs.remove_all(predicate<const string&> {ends_with_saurus}));
    
    console::write_line("\nlist now contains:");
    for (const auto& dinosaur : dinosaurs)
      console::write_line(dinosaur);
    
    console::write_line("\nexists(ends_with_saurus): {0}", dinosaurs.exists(predicate<const string&> {ends_with_saurus}));
  }
  
private:
  // Search predicate returns true if a string ends in "saurus".
  static bool ends_with_saurus(const string& s) {
    return s.to_lower().ends_with("saurus");
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// Compsognathus
// Amargasaurus
// Oviraptor
// Velociraptor
// Deinonychus
// Dilophosaurus
// Gallimimus
// Triceratops
//
// true_for_all(ends_with_saurus): false
//
// find(ends_with_saurus): Amargasaurus
//
// findLast(ends_with_saurus): Dilophosaurus
//
// find_all(ends_with_saurus):
// Amargasaurus
// Dilophosaurus
//
// 2 elements removed by remove_all(ends_with_saurus).
//
// list now contains:
// Compsognathus
// Oviraptor
// Velociraptor
// Deinonychus
// Gallimimus
// Triceratops
//
// exists(ends_with_saurus): false
