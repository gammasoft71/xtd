#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;

// Simple business object. A part_id is used to identify the type of part
// but the part name can change.
class part : public object, public iequatable<part> {
public:
  ustring part_name;
  int part_id = 0;

  part() = default;
  part(const ustring& name, int id) : part_name {name}, part_id {id} {}

  ustring to_string() const noexcept override {return ustring::format("ID: {}   Name: {}", part_id, part_name);}
  
  bool equals(const object& obj) const noexcept override {return is<part>(obj) && equals(as<part>(obj));}
  bool equals(const part& other) const noexcept override {return part_id == other.part_id;}

  size get_hash_code() const noexcept override {return part_id;}
};

class example {
public:
  static auto main() -> void {
    // Create a list of parts.
    auto parts = list<part>();
    
    // Add parts to the list.
    parts.add(part {"crank arm", 1234});
    parts.add(part {"chain ring", 1334});
    parts.add(part {"regular seat", 1434});
    parts.add(part {"banana seat", 1444});
    parts.add(part {"cassette", 1534});
    parts.add(part {"shift lever", 1634});

    // Write out the parts in the list. This will call the overridden ToString method
    // in the part class.
    console::write_line();
    for (auto part : parts)
      console::write_line(part);

    // Check the list for part #1734. This calls the iequatable::equals method of the part class, which checks the partId for equality.
    console::write_line("\ncontains(\"1734\"): {0}", parts.contains(part {"", 1734}));
    
    // Insert a new item at position 2.
    console::write_line("\nInsert(2, \"1834\")");
    parts.insert(2, part {"brake lever", 1834});
    
    //console::write_line();
    for (auto part : parts)
      console::write_line(part);

    console::write_line("\nparts[3]: {0}", parts[3]);
    
    console::write_line("\nremove(\"1534\")");
    
    // This will remove part 1534 even though the partName is different, because the equals method only checks part_id for equality.
    parts.remove(part {"cogs", 1534});
    
    console::write_line();
    for (auto part : parts)
      console::write_line(part);
    console::write_line("\nremove_at(3)");
    // This will remove the part at index 3.
    parts.remove_at(3);
    
    console::write_line();
    for (auto part : parts)
      console::write_line(part);
  }
};

startup_(example::main);

// This code produces the following output :
//
//
// ID: 1234   Name: crank arm
// ID: 1334   Name: chain ring
// ID: 1434   Name: regular seat
// ID: 1444   Name: banana seat
// ID: 1534   Name: cassette
// ID: 1634   Name: shift lever
//
// contains("1734"): false
//
// Insert(2, "1834")
// ID: 1234   Name: crank arm
// ID: 1334   Name: chain ring
// ID: 1834   Name: brake lever
// ID: 1434   Name: regular seat
// ID: 1444   Name: banana seat
// ID: 1534   Name: cassette
// ID: 1634   Name: shift lever
//
// parts[3]: ID: 1434   Name: regular seat
//
// remove("1534")
//
// ID: 1234   Name: crank arm
// ID: 1334   Name: chain ring
// ID: 1834   Name: brake lever
// ID: 1434   Name: regular seat
// ID: 1444   Name: banana seat
// ID: 1634   Name: shift lever
//
// remove_at(3)
//
// ID: 1234   Name: crank arm
// ID: 1334   Name: chain ring
// ID: 1834   Name: brake lever
// ID: 1444   Name: banana seat
// ID: 1634   Name: shift lever
