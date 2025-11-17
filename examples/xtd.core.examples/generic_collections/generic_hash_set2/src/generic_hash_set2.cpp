#include <xtd/xtd>

class example {
public:
  static void main() {
    auto all_vehicles = hash_set<string>(string_comparer::ordinal_ignore_case());
    auto some_vehicles = list<string> {};
    
    some_vehicles.add("Planes");
    some_vehicles.add("Trains");
    some_vehicles.add("Automobiles");
    
    // Add in the vehicles contained in the some_vehicles list.
    all_vehicles.union_with(some_vehicles);
    
    console::write_line("The current hash_set contains:\n");
    for (auto vehicle : all_vehicles)
      console::write_line(vehicle);
    
    all_vehicles.add("Ships");
    all_vehicles.add("Motorcycles");
    all_vehicles.add("Rockets");
    all_vehicles.add("Helicopters");
    all_vehicles.add("Submarines");
    
    console::write_line("\nThe updated hash_set contains:\n");
    for (auto vehicle : all_vehicles)
      console::write_line(vehicle);
    
    // Verify that the 'All Vehicles' set contains at least the vehicles in
    // the 'Some Vehicles' list.
    if (all_vehicles.is_superset_of(some_vehicles)) {
      console::write("\nThe 'All' vehicles set contains everything in ");
      console::write_line("'Some' vechicles list.");
    }
    
    // Check for Rockets. Here the OrdinalIgnoreCase comparer will compare
    // true for the mixed-case vehicle type.
    if (all_vehicles.contains("roCKeTs"))
      console::write_line("\nThe 'All' vehicles set contains 'roCKeTs'");
    
    all_vehicles.except_with(some_vehicles);
    console::write_line("\nThe excepted hash_set contains:\n");
    for (auto vehicle : all_vehicles)
      console::write_line(vehicle);
    
    // Remove all the vehicles that are not 'super cool'.
    all_vehicles.remove_where(is_not_super_cool);
    
    console::write_line("\nThe super cool vehicles are:\n");
    for (auto vehicle : all_vehicles)
      console::write_line(vehicle);
  }

  // Predicate to determine vehicle 'coolness'.
  static bool is_not_super_cool(const string& vehicle) {
    bool super_cool = (vehicle == "Helicopters") || (vehicle == "Motorcycles");
    return !super_cool;
  }
};

startup_(example::main);

// This code produces the following output :
//
// The current hash_set contains:
//
// Trains
// Automobiles
// Planes
//
// The updated hash_set contains:
//
// Submarines
// Helicopters
// Ships
// Rockets
// Motorcycles
// Trains
// Automobiles
// Planes
//
// The 'All' vehicles set contains everything in 'Some' vechicles list.
//
// The 'All' vehicles set contains 'roCKeTs'
//
// The excepted hash_set contains:
//
// Submarines
// Helicopters
// Ships
// Rockets
// Motorcycles
//
// The super cool vehicles are:
//
// Helicopters
// Motorcycles
